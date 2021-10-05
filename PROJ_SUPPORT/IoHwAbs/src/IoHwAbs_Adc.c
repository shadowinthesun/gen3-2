/******************************************************************************
* Gotion, Inc. CONFIDENTIAL                                                   *
* Copyright (c) 2017 Gotion, Inc, All Rights Reserved.                        *
*                                                                             *
* This document contains proprietary information belonging to Gotion Inc.     *
* Transmittal, reproduction, dissemination and/or editing of this document    *
* as well as utilization of its contents and communication there of to        *
* others without express authorization are prohibited. Offenders will         *
* be held liable for payment of damages. All rights created by patent         *
* grant or registration of a utility model or design patent are reserved.     *
*******************************************************************************
* @file   IoHwAbs_Adc.c                                                       *
*                                                                             *
* @Version 1.2                                                                *
*                                                                             *
* @date   Aug 6, 2018                                                         *
*                                                                             *
* @brief  Brief description of file.                                          *
*                                                                             *
* Changeable by user:  NO                                                     *
*                                                                             *
* Detailed description of file.                                               *
*                                                                             *
* Change history:                                                             *
* - V1.0: Jan 23, 2018 - n.jha - Initial revision                             *
* - V1.1: Aug 6, 2018 - s.mukhtar - changed variable names and layout         *
* - V1.2: Oct 5, 2018 - a.garrido - introduced ADC diagnostics                *
* - V1.3  Feb 20, 2019 - n.jha   - Changed the architecture to make better use*
*                             of the XMACRO Table to avoid repetition of the  *
*                             code                                            *
******************************************************************************/


/******************************* Includes ************************************/

#include "Platform_Types.h"
#include "IoHwAbs_Adc.h"
#include "IoHwAbs_PWM.h"
#include "IoHwAbs_Dio.h"
#include "XofYDiagnostic.h"
#include "ADC_Diagnostic.h"
#include "Rte_IoHwAbstraction.h"
#include "Rte_CanCommDiag_Type.h"
#include "NTC.h"
#include "Rte_IoHwAbstraction_Type.h"      //for wake enumeration
#include "TestMode.h"
#include "stm.h"
#include "Hall_Sensor_Drvr.h"
#include "Reset_Handling.h"
#include "User_Diag_Types.h"
#include "ASW_Types.h"


/**************************** Prebuild checks ********************************/


/************************* Private Macro Definitions *************************/

#define SHORT_COOLDOWN_TIME    5000 // counter is increased on 1ms runnable so 5s

#define Absolute_Value(value1, value2)          ((value1 > value2) ? (value1 - value2) : (value2 - value1))
#define CC2_CONN_VOLTAGE_LO_THD    (0.7f)
#define CC2_CONN_VOLTAGE_HI_THD    (2.4f)                                                        

#define ADC_StartGroupConversion_Asynchronous(X) Adc_StartGroupConversion((X))


/*************************** Private Typedefs ********************************/


/*********************** Private Function Prototypes *************************/

static void ADC_StartGroupConversion_Synchronous(Adc_GroupType ADCGroup);
static void ADC_HighSideDriveOvercurrentDetection(void);
static void Set_Value_And_Result_For_RTE(TeLLSR_Adc_Channel ADCChannel);
static void ADC_UpdateWakeReason(float Voltage, uint8 WakeSource);
static void ADC_ChannelConversions(Adc_GroupType ADCGroup);
static void ADC_UpdateRteSignals(Adc_GroupType ADCGroup);
static void ADC_UpdateCommEnableStatus(void);
static void ADC_StartupVoltageMeasurement(void);
static void ADC_UpdateHardwareRevision(void);
static void ADC_UpdateWakeDetection(void);
static TeLLSR_Board_Version ADC_DecodeHardwareRevision(float HardwareRevVoltage);
static Adc_ValueGroupType * ADC_GroupToBufferPtr(Adc_GroupType ADCGroup);


/*********************** Global Variable Definitions *************************/

extern uint32 BSWOvrd;
extern uint8 ConCmd;
extern uint8 ReOpenConState;
extern uint16 ReOpenConTimer;

extern uint8 RAM_Mirror_Variant[1];

bool VeLLSR_b_ShuntCurrPreFault = FALSE;
bool VeLLSR_b_ShuntCurrPosFault = FALSE;
bool VeLLSR_b_ShuntCAB500Fault = FALSE;
bool VeLLSR_b_ShuntCurrHeatFault = FALSE;
bool VeLLSR_b_ShuntCurrNegFault = FALSE;
bool VeLLSR_b_ShuntCurrFSPFault = FALSE;
bool VeLLSR_b_CanComNotAllowed = TRUE;
bool VeLLSR_b_CC2 = FALSE;

Adc_ValueGroupType ADC_Buffer_Group0[ADC_GROUP0_MAX_CHANNELS];
Adc_ValueGroupType ADC_Buffer_Group1[ADC_GROUP1_MAX_CHANNELS];
Adc_ValueGroupType ADC_Buffer_Group2[ADC_GROUP2_MAX_CHANNELS];

TeLLSR_Board_Version VeLLIR_k_BoardVer = HW_REV_UNINIT;

uint8 VeLLSR_k_HVILCircuit_flt = DTC_TEST_PASS;
uint8 VeLLSR_k_IsoCircuit_flt = DTC_NOT_TESTED;

float32 VaLLSR_T_WaterTempArray[ 2 ] = { 0.0f };
uint8   VaLLSR_b_WaterTemp_Inv[ 2 ]  = { 0u };


/*********************** Global Constant Definitions *************************/


/*********************** Private Constant Definitions ************************/

const TeLLSR_Adc_Mapping_Table Adc_Mapping_Table[NUMBER_OF_ADC_CHANNELS] =
{
    #define ENTRY(ChId, GrPtr, MCALChn, VBatThrshld, GndThrshld, Offset, Formula, XWinSize, YFailCnt, Test, CallRate) \
        { \
            .adcGroupPtr             = GrPtr,       \
            .adcChannelPort          = MCALChn,     \
            .Short_to_VBat_Threshold = VBatThrshld, \
            .Short_to_Gnd_Threshold  = GndThrshld,  \
            .OffsetNeeded            = Offset,      \
            .ConversionFormula       = Formula,     \
            .DiagTest                = Test,        \
            .FnCallRate              = CallRate     \
        },

        ADC_MAPPING_TABLE

    #undef ENTRY
};


TeLLSR_Adc_Diagnostic_Results VaLLSR_Adc_Diag_Status[NUMBER_OF_ADC_CHANNELS] =
{
    #define ENTRY(ChId, GrPtr, MCALChn, VBatThrshld, GndThrshld, Offset, Formula, XWinSize, YFailCnt, Test, CallRate) \
        { \
            .Adc_Status_GND = X_OF_Y_PASS,      \
            .Adc_Status_VBatt = X_OF_Y_PASS,    \
            .ADC_Voltage = 0.0f,                \
            .RTE_Voltage = 0.0f,                \
            .RTE_Fault =FALSE                   \
        },

      ADC_MAPPING_TABLE

    #undef ENTRY 
};

        
/*********************** Private Variable Definitions ************************/

static float VeLLSR_U_HwRevVoltage = 0.0f;
static uint8 VeLLSR_n_WakeDetectIter = 0;
static boolean VeLLSR_b_CANWake = FALSE;
static boolean VeLLSR_b_RTCWake = FALSE;
static boolean VeLLSR_b_KL15Wake = FALSE;
static boolean VeLLSR_b_KL15DetectedThisDriveCycle = FALSE;
static uint8 VeLLSR_n_WakeUpReason = WAKE_MASK_NO_WAKE;
static uint8 VeLLSR_n_FirstWakeUpReason = WAKE_MASK_NO_WAKE;

static uint16 VeLLSR_t_ShuntCurrPreTime = 0;
static uint16 VeLLSR_t_ShuntCurrPosTime = 0;
static uint16 VeLLSR_t_ShuntCAB500Time = 0;
static uint16 VeLLSR_t_ShuntCurrHeatTime = 0;
static uint16 VeLLSR_t_ShuntCurrNegTime = 0;
static uint16 VeLLSR_t_ShuntCurrFSPTime = 0;


/*********************** Global Function Definitions *************************/

/******************************************************************************
* @name                                                                       *
* @brief                                                                      *
*                                                                             *
* @param [in]                                                                 *
*                                                                             *
* Brief Description                                                           *
******************************************************************************/
FUNC(void, IoHwAbstraction_CODE) RE_IoHwAbs_Init(void)
{
    Rte_IWrite_RE_IoHwAbs_Init_VeLLSR_e_WakeUpReason_VeLLSR_e_WakeUpReason(VeLLSR_n_FirstWakeUpReason);
    Rte_IWrite_RE_IoHwAbs_Init_VeLLSR_n_FirstWakeUpReason_VeLLSR_n_FirstWakeUpReason(VeLLSR_n_FirstWakeUpReason);
    
    // Start Group Conversions
    ADC_StartGroupConversion_Asynchronous(AdcConf_AdcGroup_AdcGroup_0);
    ADC_StartGroupConversion_Asynchronous(AdcConf_AdcGroup_AdcGroup_1);
    ADC_StartGroupConversion_Asynchronous(AdcConf_AdcGroup_AdcGroup_2);
}


/******************************************************************************
* @name                                                                       *
* @brief                                                                      *
*                                                                             *
* @param [in]                                                                 *
*                                                                             *
* Brief Description                                                           *
******************************************************************************/
FUNC(void, IoHwAbstraction_CODE) RE_IoHwAbs_ADC_1ms(void)
{
    // Does this add safety, or potentially halt the ADC?
    if
    (
        Adc_GetGroupStatus(AdcConf_AdcGroup_AdcGroup_1) == ADC_STREAM_COMPLETED
        &&
        Adc_GetGroupStatus(AdcConf_AdcGroup_AdcGroup_2) == ADC_STREAM_COMPLETED
    )
    {
        ADC_ChannelConversions(AdcConf_AdcGroup_AdcGroup_1);
        ADC_ChannelConversions(AdcConf_AdcGroup_AdcGroup_2);

        ADC_UpdateRteSignals(AdcConf_AdcGroup_AdcGroup_1);
        ADC_UpdateRteSignals(AdcConf_AdcGroup_AdcGroup_2);

        ADC_HighSideDriveOvercurrentDetection();
    }
    else
    {
        // Halt conversions to try again
        Adc_StopGroupConversion(AdcConf_AdcGroup_AdcGroup_1);
        Adc_StopGroupConversion(AdcConf_AdcGroup_AdcGroup_2);
    }

    // Start group conversions
    ADC_StartGroupConversion_Asynchronous(AdcConf_AdcGroup_AdcGroup_1);
    ADC_StartGroupConversion_Asynchronous(AdcConf_AdcGroup_AdcGroup_2);
}


/******************************************************************************
* @name                                                                       *
* @brief                                                                      *
*                                                                             *
* @param [in]                                                                 *
*                                                                             *
* Brief Description                                                           *
******************************************************************************/
FUNC(void, IoHwAbstraction_CODE) RE_IoHwAbs_ADC_10ms(void)
{
    // Does this add safety, or potentially halt the ADC?
    if ( Adc_GetGroupStatus(AdcConf_AdcGroup_AdcGroup_0) == ADC_STREAM_COMPLETED )
    {
        ADC_ChannelConversions(AdcConf_AdcGroup_AdcGroup_0);
        ADC_UpdateRteSignals(AdcConf_AdcGroup_AdcGroup_0);
        
        // ADC group 0 contains all wake measurements
        ADC_UpdateWakeDetection();
        ADC_UpdateCommEnableStatus();
    }
    else
    {
        // Halt conversions to try again
        Adc_StopGroupConversion(AdcConf_AdcGroup_AdcGroup_0);
    }

    // Start group conversion
    ADC_StartGroupConversion_Asynchronous(AdcConf_AdcGroup_AdcGroup_0);
}


/******************************************************************************
* @name                                                                       *
* @brief                                                                      *
*                                                                             *
* @param [in]                                                                 *
*                                                                             *
* Brief Description                                                           *
******************************************************************************/
FUNC(void, IoHwAbstraction_CODE) RE_IoHwAbs_ADC_100ms(void)
{
    float NTC_0_VoltageRatio = VaLLSR_Adc_Diag_Status[ NTCF_I_00 ].RTE_Voltage / 5.0f;
    float NTC_1_VoltageRatio = VaLLSR_Adc_Diag_Status[ NTCF_I_01 ].RTE_Voltage / 5.0f;

    VaLLSR_b_WaterTemp_Inv[ 0 ] = \
        CalculateTemperature(NTC_0_VoltageRatio, &WaterTemp_NTC_Table, &(VaLLSR_T_WaterTempArray[ 0 ]));

    VaLLSR_b_WaterTemp_Inv[ 1 ] = \
        CalculateTemperature(NTC_1_VoltageRatio, &WaterTemp_NTC_Table, &(VaLLSR_T_WaterTempArray[ 1 ]));
	
	Rte_Write_VaLLSR_T_WaterTempArray_VaLLSR_T_WaterTempArray(VaLLSR_T_WaterTempArray);
	Rte_Write_VaLLSR_b_WaterTemp_Inv_VaLLSR_b_WaterTemp_Inv(VaLLSR_b_WaterTemp_Inv);
}


void IoHwAbs_Adc_Notification_Group0(void)
{
    
}


void IoHwAbs_Adc_Notification_Group1(void)
{

}


void IoHwAbs_Adc_Notification_Group2(void)
{
    
}


FUNC(void, IoHwAbstraction_CODE) RE_IoHwAbs_ADC_Cbk(void)
{

}


/******************************************************************************
* @name          Adc_Read_FirstWakeReason                                     *
* @brief         Will return the value of the first detected wake up reason   *
* @param [in]                                                                 *
*                                                                             *
******************************************************************************/
uint8 Adc_Read_FirstWakeReason(void)
{
    return VeLLSR_n_FirstWakeUpReason;
}


/******************************************************************************
* @name          Adc_Read_WakeReason                                          *
* @brief         Will return the value of the current wake up reason          *
* @param [in]                                                                 *
*                                                                             *
******************************************************************************/
uint8 Adc_Read_WakeReason(void)
{
    return VeLLSR_n_WakeUpReason;
}


/******************************************************************************
* @name          Adc_Read_BoardVersion                                        *
* @brief         Will return the value of the detected HW Board Version       *
* @param [in]                                                                 *
*                                                                             *
******************************************************************************/
TeLLSR_Board_Version Adc_Read_BoardVersion(void)
{
    return VeLLIR_k_BoardVer;
}


/******************************************************************************
* @name          Adc_Read_Buffer                                              *
* @brief         Will return the value of the corresponding ADC channel       *
*                abstracting from the hardware mapping by looking into        *
*                the Adc_Mapping_Table structure                              *
* @param [in]    VeLLSR_Adc_Channel adcChannel to read                        *
*                                                                             *
******************************************************************************/
Adc_ValueGroupType Adc_Read_Buffer(TeLLSR_Adc_Channel ADCChannel)
{
    Adc_ValueGroupType returnValue = 0xFFFF;

    if ( ADCChannel < NUMBER_OF_ADC_CHANNELS )
    {
        if ( Adc_Mapping_Table[ ADCChannel ].adcGroupPtr != NULL_PTR )
        {
            returnValue = Adc_Mapping_Table[ ADCChannel ].adcGroupPtr[ Adc_Mapping_Table[ ADCChannel ].adcChannelPort ];
        }
    }

    return returnValue;
}


/******************************************************************************
* @name          Adc_Read_Buffer                                              *
* @brief         Will return the value of the corresponding ADC channel       *
*                abstracting from the hardware mapping by looking into        *
*                the Adc_Mapping_Table structure                              *
* @param [in]    VeLLSR_Adc_Channel adcChannel to read                        *
*                                                                             *
******************************************************************************/
float Adc_Read_Float(TeLLSR_Adc_Channel ADCChannel)
{
    float returnValue = 0.0f;
    uint16 ADCValue = Adc_Read_Buffer(ADCChannel);

    if (ADCValue != 0xFFFF)
    {
        returnValue = (float) ((ADCValue * Adc_Mapping_Table[ ADCChannel ].ConversionFormula) + Adc_Mapping_Table[ ADCChannel ].OffsetNeeded);
    }
    else
    {
        returnValue = 0.0f;
    }
    
    return returnValue;
}


/******************************************************************************
* @name    Adc_Determine_WakeReason                                           *
* @brief   Determines the BMS wake reasons when the function is called. If    *
*          the HW_REV has not been determined yet it will retrieve it's value *
*          to determine whether to use independent ADC channels for the wake  *
*          reasons (SCU_P12_C_Sample onwards) or if it must scroll through    *
*          the different Wake Mux select lines to detect the different wake   *
*          reasons (SCU_P11_B_Sample backwards). Once the HW_REV has been     *
*          identified, the function will trigger ADC conversion on AdcGroup_1 *
*          and update each wake up reason bit on the retunr value.            *
*                                                                             *
* @retval  uint8    bitwise variable holding each independent wake reason     *
*                                                                             *
******************************************************************************/
uint8 Adc_Determine_WakeReason(void)
{
    ADC_StartupVoltageMeasurement();
    ADC_UpdateHardwareRevision();
    ADC_UpdateWakeDetection();

    // Update First Wake up Reason
    VeLLSR_n_FirstWakeUpReason = VeLLSR_n_WakeUpReason;

    // Find out if it we woke up from RTC
    ADC_UpdateCommEnableStatus();

    return VeLLSR_n_WakeUpReason;
}


/*********************** Private Function Definitions ************************/

/******************************************************************************
* @name    ADC_StartGroupConversion_Synchronous                               *
* @brief   This function will trigger a reading in the group passed as a      *
*          parameter and will wait until completion of the ADC reading        *
*                                                                             *
* @param [in]  Adc_GroupType    ADC Group to perform conversions on           *
******************************************************************************/
static void ADC_StartGroupConversion_Synchronous(Adc_GroupType ADCGroup)
{
    uint32 TimeoutCounter = 0x000FFFFF;

    if
    (
        ADCGroup == AdcConf_AdcGroup_AdcGroup_0
        ||
        ADCGroup == AdcConf_AdcGroup_AdcGroup_1
        ||
        ADCGroup == AdcConf_AdcGroup_AdcGroup_2
    )
    {
        // Start Group Conversions
        ADC_StartGroupConversion_Asynchronous(ADCGroup);

        // Wait for new ADC data acquisition to be complete
        while((Adc_GetGroupStatus(ADCGroup) != ADC_STREAM_COMPLETED) && (TimeoutCounter-- > 0));
    }
}


/******************************************************************************
* @name    ADC_HighSideDriveOvercurrentDetection                              *
* @brief   Perform overcurrent detction on all project enabled high side      *
*          drives, and take protective action if any faults are detected.     *
******************************************************************************/
static void ADC_HighSideDriveOvercurrentDetection(void)
{
    if (VaLLSR_Adc_Diag_Status[ HSD_ISNS_PRECHARGE ].RTE_Fault == TRUE)
    {
        VeLLSR_b_ShuntCurrPreFault = TRUE;
        VeLLSR_t_ShuntCurrPreTime = SHORT_COOLDOWN_TIME;
        Dio_WriteChannel( DIO_CHANNEL_CONDRV_HSD_PRECHARGE, STD_LOW );
    }
    else
    {
        if (VeLLSR_b_ShuntCurrPreFault == TRUE)
        {
            if (--VeLLSR_t_ShuntCurrPreTime == 0)
            {
                VeLLSR_b_ShuntCurrPreFault = FALSE;
            }
        }
    }

    if (VaLLSR_Adc_Diag_Status[ HSD_ISNS_MAIN_POS ].RTE_Fault == TRUE)
    {
        VeLLSR_b_ShuntCurrPosFault = TRUE;
        VeLLSR_t_ShuntCurrPosTime = SHORT_COOLDOWN_TIME;
        Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_MAIN_POS, STD_LOW);
    }
    else
    {
        if (VeLLSR_b_ShuntCurrPosFault == TRUE)
        {
            if (--VeLLSR_t_ShuntCurrPosTime == 0)
            {
                VeLLSR_b_ShuntCurrPosFault = FALSE;
            }
        }
    }

    if (VaLLSR_Adc_Diag_Status[ HSD_ISNS_MAIN_NEG ].RTE_Fault == TRUE)
    {
        VeLLSR_b_ShuntCurrNegFault = TRUE;
        VeLLSR_t_ShuntCurrNegTime = SHORT_COOLDOWN_TIME;
        Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_MAIN_NEG, STD_LOW);
    }
    else
    {
        if (VeLLSR_b_ShuntCurrNegFault == TRUE)
        {
            if (--VeLLSR_t_ShuntCurrNegTime == 0)
            {
                VeLLSR_b_ShuntCurrNegFault = FALSE;
            }
        }
    }
    
    // For Chery T1D - Sample B - Variant B - we do not have a Heat Film 
    if (RAM_Mirror_Variant[0] != SAMPLE_B_NO_HF_VARIANT)
    {
        if (VaLLSR_Adc_Diag_Status[ HSD_ISNS_HEAT_FILM ].RTE_Fault == TRUE)
        {
            VeLLSR_b_ShuntCurrHeatFault = TRUE;
            VeLLSR_t_ShuntCurrHeatTime = SHORT_COOLDOWN_TIME;
            Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_HEAT_FILM, STD_LOW);
        }
        else
        {
            if (VeLLSR_b_ShuntCurrHeatFault == TRUE)
            {
                if (--VeLLSR_t_ShuntCurrHeatTime == 0)
                {
                    VeLLSR_b_ShuntCurrHeatFault = FALSE;
                }
            }
        }
    }

    // For Chery T1D - Sample B - Variant C - we use a SHUNT instead of CAB500 or CSNV500
    if (RAM_Mirror_Variant[0] != SAMPLE_B_SHUNT_VARIANT)
    {
        if (VaLLSR_Adc_Diag_Status[ HSD_ISNS_CAB500 ].RTE_Fault == TRUE)
        {
            VeLLSR_b_ShuntCAB500Fault = TRUE;
            VeLLSR_t_ShuntCAB500Time = SHORT_COOLDOWN_TIME;
            Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_CAB500, STD_LOW);
        }
        else
        {
            if (VeLLSR_b_ShuntCAB500Fault == TRUE)
            {
                if (--VeLLSR_t_ShuntCAB500Time == 0)
                {
                    VeLLSR_b_ShuntCAB500Fault = FALSE;
                    Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_CAB500, STD_HIGH);
                }
            }
        }

    }
   
}


/******************************************************************************
* @name    ADC_StartupVoltageMeasurement                                      *
* @brief   Synchronously measure the voltages, 
******************************************************************************/
static void ADC_StartupVoltageMeasurement(void)
{
    uint8 SampleIndex;
    uint8 ChannelIndex;

     // Esnure no conversions are currently active
    Adc_StopGroupConversion(AdcConf_AdcGroup_AdcGroup_0);

    for (SampleIndex = 0; SampleIndex < ADC_STARTUP_SAMPLE_COUNT; SampleIndex += 1)
    {
        // average all group 0  measurements DEF number of times
        ADC_StartGroupConversion_Synchronous(AdcConf_AdcGroup_AdcGroup_0);

        // Add each channels voltage to its voltage sum
        for (ChannelIndex = 0; ChannelIndex < NUMBER_OF_ADC_CHANNELS; ChannelIndex += 1)
        {
            if ( Adc_Mapping_Table[ ChannelIndex ].adcGroupPtr == ADC_GroupToBufferPtr(AdcConf_AdcGroup_AdcGroup_0) )
            {
                VaLLSR_Adc_Diag_Status[ ChannelIndex ].ADC_Voltage += Adc_Read_Float(ChannelIndex);
            }
        }
    }

    // divide all group 0 measurements by ADC_STARTUP_SAMPLE_COUNT to get an average voltage in ADC_Voltage
    for (ChannelIndex = 0; ChannelIndex < NUMBER_OF_ADC_CHANNELS; ChannelIndex += 1)
    {
        if ( Adc_Mapping_Table[ ChannelIndex ].adcGroupPtr == ADC_GroupToBufferPtr(AdcConf_AdcGroup_AdcGroup_0) )
        {
            VaLLSR_Adc_Diag_Status[ ChannelIndex ].ADC_Voltage /= ADC_STARTUP_SAMPLE_COUNT;
        }
    }
}


/******************************************************************************
* @name    ADC_UpdateHardwareRevision                                         *
* @brief   Synchronously measure the voltages, 
******************************************************************************/
static void ADC_UpdateHardwareRevision(void)
{
    if ( VeLLIR_k_BoardVer == HW_REV_UNINIT )
    {
        VeLLSR_U_HwRevVoltage = VaLLSR_Adc_Diag_Status[ HWREV_A2D ].ADC_Voltage;

        // Find board version based on voltage
        VeLLIR_k_BoardVer = ADC_DecodeHardwareRevision(VeLLSR_U_HwRevVoltage);
    }
}


/******************************************************************************
* @name    ADC_DecodeHardwareRevision                                         *
* @brief   Return the HW revision given the HW revision voltage.              *
******************************************************************************/
static TeLLSR_Board_Version ADC_DecodeHardwareRevision(float HardwareRevVoltage)
{
    return HW_REV_P01;
}


/******************************************************************************
* @name    ADC_UpdateWakeDetection                                            *
* @brief   Given the voltages for each of the wake inputs, update the current *
*          wake reasons.                                                      *
******************************************************************************/
static void ADC_UpdateWakeDetection(void)
{
    float LeLLSR_U_WakeVoltage_Int  = VaLLSR_Adc_Diag_Status[ WKD_INT1_INT2_A2D ].ADC_Voltage;
    float LeLLSR_U_WakeVoltage_Ext1 = VaLLSR_Adc_Diag_Status[ WKD_EXT1_I_USNS ].ADC_Voltage;
    float LeLLSR_U_WakeVoltage_Ext2 = VaLLSR_Adc_Diag_Status[ WKD_EXT2_I_USNS ].ADC_Voltage;
    float LeLLSR_U_WakeVoltage_Ext3 = VaLLSR_Adc_Diag_Status[ WKD_EXT3_I_USNS ].ADC_Voltage;
    float LeLLSR_U_WakeVoltage_Ext4 = VaLLSR_Adc_Diag_Status[ WKD_EXT4_I_USNS ].ADC_Voltage;

    // Determine wake up reasons for all 3 ADC channels
    ADC_UpdateWakeReason(LeLLSR_U_WakeVoltage_Int,  WAKE_MASK_CAN_RTC);
    ADC_UpdateWakeReason(LeLLSR_U_WakeVoltage_Ext1, WAKE_MASK_KL15);
    // ADC_UpdateWakeReason(LeLLSR_U_WakeVoltage_Ext2, WAKE_MASK_UNUSED_1);
    // ADC_UpdateWakeReason(LeLLSR_U_WakeVoltage_Ext3, WAKE_MASK_UNUSED_2);
    // ADC_UpdateWakeReason(LeLLSR_U_WakeVoltage_Ext4, WAKE_MASK_UNUSED_3);

    // Update independent wake signals
    VeLLSR_b_KL15Wake = (VeLLSR_n_WakeUpReason & WAKE_MASK_KL15) ? TRUE : FALSE;
    VeLLSR_b_CANWake  = (VeLLSR_n_WakeUpReason & WAKE_MASK_CAN)  ? TRUE : FALSE;
    VeLLSR_b_RTCWake  = (VeLLSR_n_WakeUpReason & WAKE_MASK_RTC)  ? TRUE : FALSE;
}


/******************************************************************************
* @name    ADC_UpdateWakeReason                                               *
* @brief   Function to update the Wake Reason state variable                  *
******************************************************************************/
static void ADC_UpdateWakeReason(float Voltage, uint8 WakeSource)
{
    // Set a local wake var so wake reasons are always correctly populated in VeLLSR_n_WakeUpReason
    uint8 LeLLSR_n_WakeUpReason = VeLLSR_n_WakeUpReason;

    switch ( WakeSource )
    {
        case WAKE_MASK_CAN_RTC:
        {
            // Wake             Value    Range
            // Failed Circuit   0.0      [ 0.00 - 1.00 )    // Treated as no wake
            // RTC + CAN        2.0      [ 1.00 - 2.25 )
            // RTC              2.5      [ 2.25 - 2.90 )
            // CAN              3.33     [ 2.90 - 4.00 )
            // No Wake          5.0      [ 4.00 - 5.00 ]

            // Clear CAN + RTC Wake
            LeLLSR_n_WakeUpReason &= (uint8)(~WAKE_MASK_CAN_RTC);

            if ( 1.0f <= Voltage && Voltage < 2.25f )
            {
                // RTC + CAN Wake
                LeLLSR_n_WakeUpReason |= WAKE_MASK_CAN_RTC;
            }
            else
            if ( Voltage <= 2.25f && Voltage < 2.9f )
            {
                // RTC Wake
                LeLLSR_n_WakeUpReason |= WAKE_MASK_RTC;
            }
            else
            if ( 2.9f <= Voltage && Voltage < 4.0f )
            {
                // CAN Wake
                LeLLSR_n_WakeUpReason |= WAKE_MASK_CAN;
            }

            break;
        }

        case WAKE_MASK_KL15:
        {
            if ( 5.5f <= Voltage )
            {
                // set KL15 wake bit
                LeLLSR_n_WakeUpReason |= WAKE_MASK_KL15;
            }
            else
            if ( Voltage < 3.0f )
            {
                // clear kl15 wake bit
                LeLLSR_n_WakeUpReason &= (uint8)(~WAKE_MASK_KL15);
            }
        }

        default:
        {
            break;
        }
    }

    // Set global wake reason to the update local value
    VeLLSR_n_WakeUpReason = LeLLSR_n_WakeUpReason;
}


/******************************************************************************
* @name    ADC_UpdateCommEnableStatus                                         *
* @brief   Determines if the wake history supports enabling or disabling CAN  *
*          communication for the current drive cycle.                         *
******************************************************************************/
static void ADC_UpdateCommEnableStatus(void)
{   
    uint8 LeLLSR_b_CanComNotAllowed = FALSE;
    uint8 StartupCurrentWakeHistory = (VeLLSR_n_WakeUpReason | VeLLSR_n_FirstWakeUpReason);

    if ( StartupCurrentWakeHistory & WAKE_MASK_KL15 )
    {
        VeLLSR_b_KL15DetectedThisDriveCycle = TRUE;
    }

    // If KL15 has never been enabled during the current drive cycle
    // AND
    // The only current + startup wake is the RTC
    if
    (
        VeLLSR_b_KL15DetectedThisDriveCycle == FALSE
        &&
        StartupCurrentWakeHistory == WAKE_MASK_RTC
    )
    {
        LeLLSR_b_CanComNotAllowed = TRUE;
    }
    
    VeLLSR_b_CanComNotAllowed = LeLLSR_b_CanComNotAllowed;    
}


/******************************************************************************
* @name          Set_Value_And_Result_For_RTE                                 *
* @brief                                                                      *
******************************************************************************/
static void Set_Value_And_Result_For_RTE(TeLLSR_Adc_Channel ADCChannel)
{
    if
    (
        VaLLSR_Adc_Diag_Status[ ADCChannel ].Adc_Status_GND == X_OF_Y_FAIL
        ||
        VaLLSR_Adc_Diag_Status[ ADCChannel ].Adc_Status_VBatt == X_OF_Y_FAIL
    )
    {
        VaLLSR_Adc_Diag_Status[ ADCChannel ].RTE_Fault = TRUE;
    }
    else
    {
        VaLLSR_Adc_Diag_Status[ ADCChannel ].RTE_Voltage = VaLLSR_Adc_Diag_Status[ ADCChannel ].ADC_Voltage;
        VaLLSR_Adc_Diag_Status[ ADCChannel ].RTE_Fault = FALSE;
    }
}


/******************************************************************************
* @name    ADC_ChannelConversions                                             *
* @brief   Function to perform ADC data conversions on all channels and to    *
*          be called once the ADC groups data acquisition are complete        *
******************************************************************************/
static void ADC_ChannelConversions(Adc_GroupType ADCGroup)
{
    uint8 ChannelIndex = 0;

    for (ChannelIndex = 0; ChannelIndex < NUMBER_OF_ADC_CHANNELS; ChannelIndex += 1)
    {
        if ( Adc_Mapping_Table[ ChannelIndex ].adcGroupPtr == ADC_GroupToBufferPtr(ADCGroup) )
        {
            VaLLSR_Adc_Diag_Status[ ChannelIndex ].ADC_Voltage = Adc_Read_Float(ChannelIndex);
            Perform_Adc_Diagnostics(ChannelIndex);
            Set_Value_And_Result_For_RTE(ChannelIndex);
        }
    }
}


/******************************************************************************
* @name    ADC_GroupToBufferPtr                                               *
* @brief   Given a group ID, return its result buffer ptr.                    *
******************************************************************************/
static Adc_ValueGroupType * ADC_GroupToBufferPtr(Adc_GroupType ADCGroup)
{
    Adc_ValueGroupType * GroupPtr = NULL_PTR;

    if ( ADCGroup == AdcConf_AdcGroup_AdcGroup_0 )
    {
        GroupPtr = ADC_Buffer_Group0;
    }
    else
    if ( ADCGroup == AdcConf_AdcGroup_AdcGroup_1 )
    {
        GroupPtr = ADC_Buffer_Group1;
    }
    else
    if ( ADCGroup == AdcConf_AdcGroup_AdcGroup_2 )
    {
        GroupPtr = ADC_Buffer_Group2;
    }

    return GroupPtr;
}


/******************************************************************************
* @name    ADC_UpdateRteSignals                                             *
* @brief   Function to update RTE variables to application and to be called   *
*          once the ADC channel conversions are complete                      *
* @return                                                                     *
******************************************************************************/
static void ADC_UpdateRteSignals(Adc_GroupType ADCGroup)
{
    if ( ADCGroup == AdcConf_AdcGroup_AdcGroup_0 )
    {
        if
        (
            VaLLSR_Adc_Diag_Status[ CHRG_GBCC2_A2D ].RTE_Voltage <= CC2_CONN_VOLTAGE_HI_THD
            &&
            VaLLSR_Adc_Diag_Status[ CHRG_GBCC2_A2D ].RTE_Voltage >= CC2_CONN_VOLTAGE_LO_THD
        )
        {
            VeLLSR_b_CC2 = TRUE;
        }
        else
        {
            VeLLSR_b_CC2 = FALSE;
        }

        if ( TestMode_IsSpecificTestModeActive(TEST_MODE_APP_ENABLED) == U16_SAFE_TRUE )
        {
            Rte_Write_VeLLSR_b_ActivateBSWOvrd_VeLLSR_b_ActivateBSWOvrd(BSWOvrd);
            Rte_Write_VeLLSR_b_CloseContactors_VeLLSR_b_CloseContactors(ConCmd);
        }

        Rte_Write_VeLLSR_U_KL30Volt_VeLLSR_U_KL30Volt(VaLLSR_Adc_Diag_Status[ KL30MR_I_USNS ].RTE_Voltage);
        Rte_Write_VeLLSR_b_VCU_Wake_VeLLSR_b_VCU_Wake(VeLLSR_b_KL15Wake);
        Rte_Write_VeLLSR_b_CC2_VeLLSR_b_CC2(VeLLSR_b_CC2);
    }
    else
    if ( ADCGroup == AdcConf_AdcGroup_AdcGroup_1 )
    {
        Rte_Write_VeLLSR_U_HS_OSMPre_VeLLSR_U_HS_OSMPre(VaLLSR_Adc_Diag_Status[ HSD_USNS_PRECHARGE ].RTE_Voltage);
        Rte_Write_VeLLSR_U_HS_OSMHeat_VeLLSR_U_HS_OSMHeat(VaLLSR_Adc_Diag_Status[ HSD_USNS_HEAT_FILM ].RTE_Voltage);
        Rte_Write_VeLLSR_U_HS_OSMPos_VeLLSR_U_HS_OSMPos(VaLLSR_Adc_Diag_Status[ HSD_USNS_MAIN_POS ].RTE_Voltage);

        Rte_Write_VeLLSR_b_HS_OSMPre_Inv_VeLLSR_b_HS_OSMPre_Inv(VaLLSR_Adc_Diag_Status[ HSD_USNS_PRECHARGE ].RTE_Fault);
        Rte_Write_VeLLSR_b_HS_OSMPos_Inv_VeLLSR_b_HS_OSMPos_Inv(VaLLSR_Adc_Diag_Status[ HSD_USNS_MAIN_POS ].RTE_Fault);

        Rte_Write_VeLLSR_I_ShuntCurrPre_VeLLSR_I_ShuntCurrPre(VaLLSR_Adc_Diag_Status[ HSD_ISNS_PRECHARGE ].RTE_Voltage);
        Rte_Write_VeLLSR_b_ConDrvPreCircuit_flt_VeLLSR_b_ConDrvPreCircuit_flt(VeLLSR_b_ShuntCurrPreFault);

        Rte_Write_VeLLSR_I_ShuntCurrPos_VeLLSR_I_ShuntCurrPos(VaLLSR_Adc_Diag_Status[ HSD_ISNS_MAIN_POS ].RTE_Voltage);
        Rte_Write_VeLLSR_b_ConDrvPosCircuit_flt_VeLLSR_b_ConDrvPosCircuit_flt(VeLLSR_b_ShuntCurrPosFault);

        Rte_Write_VeLLSR_I_ShuntCurrHeat_VeLLSR_I_ShuntCurrHeat(VaLLSR_Adc_Diag_Status[ HSD_ISNS_HEAT_FILM ].RTE_Voltage);
        Rte_Write_VeLLSR_b_ConDrvHeatCircuit_flt_VeLLSR_b_ConDrvHeatCircuit_flt(VeLLSR_b_ShuntCurrHeatFault);
    }
    else
    if ( ADCGroup == AdcConf_AdcGroup_AdcGroup_2 )
    {

        if ( Rte_CData_KeLLSR_b_HVILCircuit_flt_En() )
        {
            VeLLSR_k_HVILCircuit_flt = Rte_CData_KeLLSR_k_HVILCircuit_flt_Val();
        }
        else
        {
            VeLLSR_k_HVILCircuit_flt = (
                                            VaLLSR_Adc_Diag_Status[ HVIL_O_00_USNS ].RTE_Fault
                                            ||
                                            VaLLSR_Adc_Diag_Status[ HVIL_I_00_USNS ].RTE_Fault
                                        ) ? DTC_TEST_FAIL : DTC_TEST_PASS;
        }

        if ( Rte_CData_KeLLSR_b_IsoCircuit_flt_En() )
        {
            VeLLSR_k_IsoCircuit_flt = Rte_CData_KeLLSR_k_IsoCircuit_flt_Val();
        }
        else
        {
            VeLLSR_k_IsoCircuit_flt = DTC_TEST_PASS;
        }

        Rte_Write_VeLLSR_U_HS_OSMNeg_VeLLSR_U_HS_OSMNeg(VaLLSR_Adc_Diag_Status[ HSD_USNS_MAIN_NEG ].RTE_Voltage);
        Rte_Write_VeLLSR_b_HS_OSMNeg_Inv_VeLLSR_b_HS_OSMNeg_Inv(VaLLSR_Adc_Diag_Status[ HSD_USNS_MAIN_NEG ].RTE_Fault);

        Rte_Write_VeLLSR_I_ShuntCurrNeg_VeLLSR_I_ShuntCurrNeg(VaLLSR_Adc_Diag_Status[ HSD_ISNS_MAIN_NEG ].RTE_Voltage);

        Rte_Write_VeLLSR_U_HS_HVIL_VeLLSR_U_HS_HVIL(VaLLSR_Adc_Diag_Status[ HVIL_O_00_USNS ].RTE_Voltage);
        Rte_Write_VeLLSR_U_LS_HVIL_VeLLSR_U_LS_HVIL(VaLLSR_Adc_Diag_Status[ HVIL_I_00_USNS ].RTE_Voltage);
        Rte_Write_VeLLSR_b_HS_HVIL_Inv_VeLLSR_b_HS_HVIL_Inv(VaLLSR_Adc_Diag_Status[ HVIL_O_00_USNS ].RTE_Fault);
        Rte_Write_VeLLSR_b_LS_HVIL_Inv_VeLLSR_b_LS_HVIL_Inv(VaLLSR_Adc_Diag_Status[ HVIL_I_00_USNS ].RTE_Fault);

        Rte_Write_VeLLSR_U_HS_FCHVIL_VeLLSR_U_HS_FCHVIL(VaLLSR_Adc_Diag_Status[ HVIL_O_01_USNS ].RTE_Voltage);
        Rte_Write_VeLLSR_U_LS_FCHVIL_VeLLSR_U_LS_FCHVIL(VaLLSR_Adc_Diag_Status[ HVIL_I_01_USNS ].RTE_Voltage);
        Rte_Write_VeLLSR_b_LS_FCHVIL_Inv_VeLLSR_b_LS_FCHVIL_Inv(VaLLSR_Adc_Diag_Status[ HVIL_O_01_USNS ].RTE_Fault);
        Rte_Write_VeLLSR_b_HS_FCHVIL_Inv_VeLLSR_b_HS_FCHVIL_Inv(VaLLSR_Adc_Diag_Status[ HVIL_I_01_USNS ].RTE_Fault);
    }
}
