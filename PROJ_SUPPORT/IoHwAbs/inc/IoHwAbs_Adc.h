/******************************************************************************
* Gotion, Inc. CONFIDENTIAL                                                   *
* Copyright (c) 2017 Gotion, Inc, All Rights Reserved.                        *
*                                                                             *
* This document contains proprietary information belonging to Gotion, Inc.    *
* Transmittal, reproduction, dissemination and/or editing of this document    *
* as well as utilization of its contents and communication there of to        *
* others without express authorization are prohibited. Offenders will         *
* be held liable for payment of damages. All rights created by patent         *
* grant or registration of a utility model or design patent are reserved.     *
*******************************************************************************
* @file   IoHwAbs_Adc.h                                                       *
*                                                                             *
* @Version 1.0                                                                *
*                                                                             *
* @date   2018.09.25                                                          *
*                                                                             *
* @brief  Interface through AUTOSAR Rte.                                      *
*                                                                             *
* Changeable by user:  YES                                                    *
*                                                                             *
* App / Low level interface.                                                  *
*                                                                             *
* Change history:                                                             *
* - V1.0: 2018.09.25 - Alberto Garrido - Initial revision                     *
*                                                                             *
******************************************************************************/

#ifndef IOHWABS_ADC_H
#define IOHWABS_ADC_H

/******************************* Includes ************************************/

#include "Platform_Types.h"
#include "Adc.h"
#include "Dio.h"
#include "NTC.h"
#include "powermode.h"        //for wake enumeration
#include "XofYDiagnostic.h"
#include "Rte_CanCommDiag_Type.h"


/************************** Global Macro Definitions *************************/

#define HSD_ISNS_PRECHARGE      HSD_O_00_ISNS
#define HSD_ISNS_HEAT_FILM      HSD_O_01_ISNS
#define HSD_ISNS_MAIN_POS       HSD_O_02_ISNS
#define HSD_ISNS_MAIN_NEG       HSD_O_03_ISNS
#define HSD_ISNS_CAB500         HSD_O_05_ISNS

#define HSD_USNS_PRECHARGE      HSD_O_00_USNS
#define HSD_USNS_HEAT_FILM      HSD_O_01_USNS
#define HSD_USNS_MAIN_POS       HSD_O_02_USNS
#define HSD_USNS_MAIN_NEG       HSD_O_03_USNS
#define HSD_USNS_CAB500         HSD_O_05_USNS

#define WAKE_MASK_NO_WAKE       ((uint8) 0b00000000)
#define WAKE_MASK_KL15          ((uint8) 0b00000001)
#define WAKE_MASK_CAN           ((uint8) 0b00000010)
#define WAKE_MASK_UNUSED_1      ((uint8) 0b00000100)
#define WAKE_MASK_AUX           ((uint8) 0b00001000)
#define WAKE_MASK_RTC           ((uint8) 0b00010000)
#define WAKE_MASK_UNUSED_2      ((uint8) 0b00100000)
#define WAKE_MASK_CAN_RTC       ((uint8) (WAKE_MASK_CAN | WAKE_MASK_RTC))

#define ADC_GROUP0_MAX_CHANNELS     0x10
#define ADC_GROUP1_MAX_CHANNELS     0x10
#define ADC_GROUP2_MAX_CHANNELS     0x10

#define NO_OF_TESTS     2u
#define SHORT_TO_VBATT  0u
#define SHORT_TO_GND    1u

#define ADC_STARTUP_SAMPLE_COUNT  3u

#define RESISTOR_WAKE_1         (33000.0f)
#define RESISTOR_WAKE_2          (7500.0f)

#define RESISTOR_CHRG_1        (100000.0f)
#define RESISTOR_CHRG_2         (33000.0f)

#define RESISTOR_V_SENSE_1      (33000.0f)
#define RESISTOR_V_SENSE_2       (7500.0f)

#define RESISTOR_I_SENSE_KL30   (10000.0f)
#define RESISTOR_I_SENSE_HSD     (5100.0f)
#define RESISTOR_I_SENSE            (0.047f)

#define ISNS_CHIP_FACTOR            (0.004f)

#define ADC_RAW_TO_VOLTS                (0.001221001f)
#define RES_DIV_EXT_WAKE                ((RESISTOR_WAKE_1 + RESISTOR_WAKE_2) / RESISTOR_WAKE_2)
#define RES_DIV_CHRG_CC2                ((RESISTOR_CHRG_1 + RESISTOR_CHRG_2) / RESISTOR_CHRG_2)
#define RES_DIV_V_SENSE                 ((RESISTOR_V_SENSE_1 + RESISTOR_V_SENSE_2) / RESISTOR_V_SENSE_2)
#define RES_DIV_KL30_I_SENSE            (1.0f / (RESISTOR_I_SENSE_KL30 * ISNS_CHIP_FACTOR * RESISTOR_I_SENSE))
#define RES_DIV_HSD_I_SENSE             (1.0f / (RESISTOR_I_SENSE_HSD * ISNS_CHIP_FACTOR * RESISTOR_I_SENSE))

#define ADC_FACTOR_HW_REV               (ADC_RAW_TO_VOLTS)
#define ADC_FACTOR_INT_WAKE             (ADC_RAW_TO_VOLTS)
#define ADC_FACTOR_EXT_WAKE             (ADC_RAW_TO_VOLTS * RES_DIV_EXT_WAKE)
#define ADC_FACTOR_NTCF                 (ADC_RAW_TO_VOLTS)
#define ADC_FACTOR_CHRG_CC2             (ADC_RAW_TO_VOLTS * RES_DIV_CHRG_CC2)
#define ADC_FACTOR_KL30_I_SENSE         (ADC_RAW_TO_VOLTS * RES_DIV_KL30_I_SENSE)
#define ADC_FACTOR_KL30_V_SENSE         (ADC_RAW_TO_VOLTS * RES_DIV_V_SENSE)
#define ADC_FACTOR_HSD_I_SENSE          (ADC_RAW_TO_VOLTS * RES_DIV_HSD_I_SENSE)
#define ADC_FACTOR_HSD_V_SENSE          (ADC_RAW_TO_VOLTS * RES_DIV_V_SENSE)
#define ADC_FACTOR_HVIL_V_SENSE         (ADC_RAW_TO_VOLTS * RES_DIV_V_SENSE)


#define ADC_MAPPING_TABLE    \
    /*ADC Channel ID          ADC Buffer Group    ADC MCAL Channel ID                    VBatt    Ground    Offset   Factor                     XofYWindow  XofYCount  Diagnostics   Call Rate*/ \
    ENTRY(HWREV_A2D,          ADC_Buffer_Group0,  AdcConf_AdcChannel_HWREV_A2D,          4.7f,    0.01f,    0.0f,    ADC_FACTOR_HW_REV,         10u,        6u,        NO_TEST,      TEN_MS) \
    ENTRY(WKD_INT1_INT2_A2D,  ADC_Buffer_Group0,  AdcConf_AdcChannel_WKD_INT1_INT2_A2D,  4.7f,    0.01f,    0.0f,    ADC_FACTOR_INT_WAKE,       10u,        6u,        NO_TEST,      TEN_MS) \
    ENTRY(WKD_EXT4_I_USNS,    ADC_Buffer_Group0,  AdcConf_AdcChannel_WKD_EXT4_I_USNS,    4.7f,    0.01f,    0.0f,    ADC_FACTOR_EXT_WAKE,       10u,        6u,        NO_TEST,      TEN_MS) \
    ENTRY(WKD_EXT3_I_USNS,    ADC_Buffer_Group0,  AdcConf_AdcChannel_WKD_EXT3_I_USNS,    4.7f,    0.01f,    0.0f,    ADC_FACTOR_EXT_WAKE,       10u,        6u,        NO_TEST,      TEN_MS) \
    ENTRY(WKD_EXT2_I_USNS,    ADC_Buffer_Group0,  AdcConf_AdcChannel_WKD_EXT2_I_USNS,    4.7f,    0.01f,    0.0f,    ADC_FACTOR_EXT_WAKE,       10u,        6u,        NO_TEST,      TEN_MS) \
    ENTRY(WKD_EXT1_I_USNS,    ADC_Buffer_Group0,  AdcConf_AdcChannel_WKD_EXT1_I_USNS,    4.7f,    0.01f,    0.0f,    ADC_FACTOR_EXT_WAKE,       10u,        6u,        NO_TEST,      TEN_MS) \
    ENTRY(NTCF_I_00,          ADC_Buffer_Group0,  AdcConf_AdcChannel_NTCF_I_00,          4.7f,    0.01f,    0.0f,    ADC_FACTOR_NTCF,           10u,        6u,        NO_TEST,      TEN_MS) \
    ENTRY(NTCF_I_01,          ADC_Buffer_Group0,  AdcConf_AdcChannel_NTCF_I_01,          4.7f,    0.01f,    0.0f,    ADC_FACTOR_NTCF,           10u,        6u,        NO_TEST,      TEN_MS) \
    ENTRY(FANFB_I_00,         ADC_Buffer_Group0,  AdcConf_AdcChannel_FANFB_I_00,         4.7f,    0.01f,    0.0f,    ADC_RAW_TO_VOLTS,          10u,        6u,        NO_TEST,      TEN_MS) \
    ENTRY(FANFB_I_01,         ADC_Buffer_Group0,  AdcConf_AdcChannel_FANFB_I_01,         4.7f,    0.01f,    0.0f,    ADC_RAW_TO_VOLTS,          10u,        6u,        NO_TEST,      TEN_MS) \
    ENTRY(CHRG_GBCC2_A2D,     ADC_Buffer_Group0,  AdcConf_AdcChannel_CHRG_GBCC2_A2D,     4.7f,    0.01f,    0.0f,    ADC_FACTOR_CHRG_CC2,       10u,        6u,        NO_TEST,      TEN_MS) \
    ENTRY(KL30_I_ISNS,        ADC_Buffer_Group0,  AdcConf_AdcChannel_KL30_I_ISNS,        4.7f,    0.01f,    0.0f,    ADC_FACTOR_KL30_I_SENSE,   10u,        6u,        NO_TEST,      TEN_MS) \
    ENTRY(KL30MR_I_USNS,      ADC_Buffer_Group0,  AdcConf_AdcChannel_KL30MR_I_USNS,      4.7f,    0.01f,    0.0f,    ADC_FACTOR_KL30_V_SENSE,   10u,        6u,        NO_TEST,      TEN_MS) \
    ENTRY(HSD_O_01_ISNS,      ADC_Buffer_Group1,  AdcConf_AdcChannel_HSD_O_01_ISNS,      4.7f,    0.01f,    0.0f,    ADC_FACTOR_HSD_I_SENSE,     3u,        2u,        VBATT,        ONE_MS) \
    ENTRY(HSD_O_00_USNS,      ADC_Buffer_Group1,  AdcConf_AdcChannel_HSD_O_00_USNS,      4.7f,    0.01f,    0.0f,    ADC_FACTOR_HSD_V_SENSE,    10u,        6u,        NO_TEST,      ONE_MS) \
    ENTRY(HSD_O_00_ISNS,      ADC_Buffer_Group1,  AdcConf_AdcChannel_HSD_O_00_ISNS,      4.7f,    0.01f,    0.0f,    ADC_FACTOR_HSD_I_SENSE,     3u,        2u,        VBATT,        ONE_MS) \
    ENTRY(HSD_O_01_USNS,      ADC_Buffer_Group1,  AdcConf_AdcChannel_HSD_O_01_USNS,      4.7f,    0.01f,    0.0f,    ADC_FACTOR_HSD_V_SENSE,    10u,        6u,        NO_TEST,      ONE_MS) \
    ENTRY(HSD_O_02_USNS,      ADC_Buffer_Group1,  AdcConf_AdcChannel_HSD_O_02_USNS,      4.7f,    0.01f,    0.0f,    ADC_FACTOR_HSD_V_SENSE,    10u,        6u,        NO_TEST,      ONE_MS) \
    ENTRY(HSD_O_02_ISNS,      ADC_Buffer_Group1,  AdcConf_AdcChannel_HSD_O_02_ISNS,      4.7f,    0.01f,    0.0f,    ADC_FACTOR_HSD_I_SENSE,     3u,        2u,        VBATT,        ONE_MS) \
    ENTRY(HSD_O_05_USNS,      ADC_Buffer_Group2,  AdcConf_AdcChannel_HSD_O_05_USNS,      4.7f,    0.01f,    0.0f,    ADC_FACTOR_HSD_V_SENSE,    10u,        6u,        NO_TEST,      ONE_MS) \
    ENTRY(HSD_O_05_ISNS,      ADC_Buffer_Group2,  AdcConf_AdcChannel_HSD_O_05_ISNS,      4.7f,    0.01f,    0.0f,    ADC_FACTOR_HSD_I_SENSE,     3u,        2u,        VBATT,        ONE_MS) \
    ENTRY(HSD_O_04_USNS,      ADC_Buffer_Group2,  AdcConf_AdcChannel_HSD_O_04_USNS,      4.7f,    0.01f,    0.0f,    ADC_FACTOR_HSD_V_SENSE,    10u,        6u,        NO_TEST,      ONE_MS) \
    ENTRY(HSD_O_04_ISNS,      ADC_Buffer_Group2,  AdcConf_AdcChannel_HSD_O_04_ISNS,      4.7f,    0.01f,    0.0f,    ADC_FACTOR_HSD_I_SENSE,     3u,        2u,        VBATT,        ONE_MS) \
    ENTRY(HSD_O_03_USNS,      ADC_Buffer_Group2,  AdcConf_AdcChannel_HSD_O_03_USNS,      4.7f,    0.01f,    0.0f,    ADC_FACTOR_HSD_V_SENSE,    10u,        6u,        NO_TEST,      ONE_MS) \
    ENTRY(HSD_O_03_ISNS,      ADC_Buffer_Group2,  AdcConf_AdcChannel_HSD_O_03_ISNS,      4.7f,    0.01f,    0.0f,    ADC_FACTOR_HSD_I_SENSE,     3u,        2u,        VBATT,        ONE_MS) \
    ENTRY(VND7040_SNS,        ADC_Buffer_Group2,  AdcConf_AdcChannel_VND7040_SNS,        4.7f,    0.01f,    0.0f,    ADC_RAW_TO_VOLTS,          10u,        6u,        NO_TEST,      ONE_MS) \
    ENTRY(HVIL_O_00_USNS,     ADC_Buffer_Group2,  AdcConf_AdcChannel_HVIL_O_00_USNS,     4.7f,    0.01f,    0.0f,    ADC_FACTOR_HVIL_V_SENSE,   10u,        6u,        NO_TEST,      ONE_MS) \
    ENTRY(HVIL_I_00_USNS,     ADC_Buffer_Group2,  AdcConf_AdcChannel_HVIL_I_00_USNS,     4.7f,    0.01f,    0.0f,    ADC_FACTOR_HVIL_V_SENSE,   10u,        6u,        NO_TEST,      ONE_MS) \
    ENTRY(HVIL_O_01_USNS,     ADC_Buffer_Group2,  AdcConf_AdcChannel_HVIL_O_01_USNS,     4.7f,    0.01f,    0.0f,    ADC_FACTOR_HVIL_V_SENSE,   10u,        6u,        NO_TEST,      ONE_MS) \
    ENTRY(HVIL_I_01_USNS,     ADC_Buffer_Group2,  AdcConf_AdcChannel_HVIL_I_01_USNS,     4.7f,    0.01f,    0.0f,    ADC_FACTOR_HVIL_V_SENSE,   10u,        6u,        NO_TEST,      ONE_MS)


/*************************** Global Typedefs *********************************/

typedef enum
{
    ONE_MS,
    TEN_MS
}TeLLSR_e_ADC_Diagnostic_CallRate;


typedef enum
{
    HW_REV_UNINIT = 0,
    HW_REV_P01    = 1,
} TeLLSR_Board_Version;


typedef enum
{
    #define ENTRY(ChId, GrPtr, MCALChn, VBatThrshld, GndThrshld, Offset, Formula, XWinSize, YFailCnt, Test, CallRate) ChId,
        ADC_MAPPING_TABLE
    #undef ENTRY
    
    NUMBER_OF_ADC_CHANNELS
} TeLLSR_Adc_Channel;


typedef enum
{
    NO_TEST     = 0b00000000,
    VBATT       = 0b00000001,
    GND         = 0b00000010,
    VBATT_N_GND = 0b00000011
}TeLLSR_Type_Of_Diagnostic;


typedef struct
{
    uint8 Adc_Status_GND;
    uint8 Adc_Status_VBatt;
    float ADC_Voltage;
    float RTE_Voltage;
    boolean RTE_Fault;
} TeLLSR_Adc_Diagnostic_Results;


typedef struct
{  
    Adc_ValueGroupType *adcGroupPtr;
    Adc_ChannelType adcChannelPort;
    float Short_to_VBat_Threshold;
    float Short_to_Gnd_Threshold;
    float OffsetNeeded;
    float ConversionFormula;
    TeLLSR_Type_Of_Diagnostic DiagTest;
    TeLLSR_e_ADC_Diagnostic_CallRate FnCallRate;    
} TeLLSR_Adc_Mapping_Table;


/********************** Global Constant Declarations *************************/



/*********************** Global Variable Declarations ************************/

extern Adc_ValueGroupType ADC_Buffer_Group0[ADC_GROUP0_MAX_CHANNELS];
extern Adc_ValueGroupType ADC_Buffer_Group1[ADC_GROUP1_MAX_CHANNELS];
extern Adc_ValueGroupType ADC_Buffer_Group2[ADC_GROUP2_MAX_CHANNELS];
extern TeLLSR_Adc_Diagnostic_Results VaLLSR_Adc_Diag_Status[NUMBER_OF_ADC_CHANNELS];


/*********************** Global Function Declarations ************************/

uint8 Adc_Determine_WakeReason(void);
Adc_ValueGroupType Adc_Read_Buffer(TeLLSR_Adc_Channel adcChannel);
float Adc_Read_Float(TeLLSR_Adc_Channel adcChannel);
uint8 Adc_Read_FirstWakeReason(void);
uint8 Adc_Read_WakeReason(void);
TeLLSR_Board_Version Adc_Read_BoardVersion(void);


#endif
