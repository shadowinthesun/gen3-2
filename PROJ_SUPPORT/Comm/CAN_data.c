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
* @file   CAN_data.c                                                          *
*                                                                             *
* @Version 1.0                                                                *
*                                                                             *
* @date   2018.10.10                                                          *
*                                                                             *
* @brief  Brief description of file.                                          *
*                                                                             *
* Changeable by user:  NO                                                     *
*                                                                             *
* Detailed description of file.                                               *
*                                                                             *
* Change history:                                                             *
* - V1.0: 2018.10.10 - s.mukhtar - Initial Revision                           *
* - V1.1: 2019.07.08 - K. Patel  - GWM NM updates                             *
*                                                                             *
******************************************************************************/

/**************************** Prebuild checks ********************************/

/******************************* Includes ************************************/
#include "TestMode.h"
#include "CanIf.h"
#include "Configuration_Interface_System.h"
#include "Rte_MemMap.h"
#include "Ifx_reg.h"
#include "ASW_Rte_Type.h"
#include "ComStack_Cfg.h"
#include "Com_Cfg.h"
#include "CanIf_Cfg.h"
#include "Nvm_Cfg.h"
#include "CAN_data.h"
#include "Crc_8h2f.h"
#include "Math.h"
#include "powermode.h"
#include "IoHwAbs_Adc.h"
#include "CAN_Comm_Diagnostics.h"

#include "Rte_HallSensorComponent.h"
#include "Com.h"


/************************* Private Macro Definitions ************************/

/*Helper Macros for transmitting cell voltages*/

/*Helper macros for transmitting cell temperatures*/


/*************************** Private Typedefs ********************************/
#define DEFAULT_VALUE_ZERO 0u
// will be removed once i have an app signal
#define APP_VALUE          1024u
#define TEN_MS_RUNNABLE_RATE            (10u)

/*********************** Private Function Prototypes *************************/

bool CAN_Transmission_Check(void);

/*********************** Global Constant Definitions *************************/

/*********************** Global Variable Definitions *************************/
//extern SOCR_Code_B SOCR_Code_B_n;

//TODO: Remove this hack when new GWM DBC is imported in ISOLAR
extern uint8 VeLLSR_b_CanComNotAllowed;
extern TeLLSR_Board_Version VeLLIR_k_BoardVer;
extern const Dcm_DataArrayTypeUint8_DspData_F195Type F195_DID_Value;

/*********************** Private Constant Definitions ************************/
/*********************** Private Variable Definitions ************************/
/*********************** Global Function Definitions *************************/
/******************************************************************************
* @name    RE_CAN_Signals_100ms                                               *
* @brief   100ms runnable for outgoing CAN traffic                            *
*                                                                             *
*                                                                             *
* Function to receive app variables from upper layers and transmit CAN        *
* messages for signals that correspond to the 100ms rate                      *
******************************************************************************/
FUNC(void, CAN_Signals_CODE) RE_CAN_Signals_100ms(void)
{
  
}

void RE_toAppl_100ms_Processing_func(void){}
void RE_fromAppl_25ms_Processing_func(void){}
void RE_toAppl_10ms_Processing_func(void){}
/******************************************************************************
* @name    RE_CAN_Signals_1000msfunc                                          *
* @brief   1000ms runnable for outgoing CAN traffic                           *
*                                                                             *
*                                                                             *
* Function to receive app variables from upper layers and transmit CAN        *
* messages for signals that correspond to the 1000ms rate                     *
******************************************************************************/
FUNC(void, CAN_Signals_CODE) RE_CAN_Signals_1000msfunc(void)
{
  

    /*Transmit Hardware version*/
   // Rte_IWrite_RE_CAN_Signals_1000ms_PPort_BMS_HWVersion_uint16((uint16)VeLLIR_k_BoardVer);

    /*Transmit Software versions*/
    {
        uint8 * versionPtr = (uint8 *)F195_DID_Value;
        uint8 swVersion = ((versionPtr[3] & 0x0F) * 10) + (versionPtr[4] & 0x0F);
        uint8 calVersion = ((versionPtr[7] & 0x0F) * 10) + (versionPtr[8] & 0x0F);

       // Rte_IWrite_RE_CAN_Signals_1000ms_PPort_BMS_SWVersion_uint16((uint16)calVersion);
    }


}

/******************************************************************************
* @name    RE_CAN_Signals_10ms                                                *
* @brief   10ms runnable for outgoing CAN traffic                             *
*                                                                             *
*                                                                             *
* Function to receive app variables from upper layers and transmit CAN        *
* messages for signals that correspond to the 10ms rate                       *
******************************************************************************/
FUNC(void, CAN_Signals_CODE) RE_CAN_Signals_10ms(void)
{
    

    if(VeCAN_BusOff_Counter >= Ke_CanBusOff_Threshold)
    {
        if(VeCAN_BusOffSlowTimer < Ke_CanBusOffSlowTime)
        {
            VeCAN_BusOffSlowTimer += TEN_MS_RUNNABLE_RATE;
        }
        else
        {
            /* Do nothing */
        }
    }
    else
    {
        /* Do nothing */
    }

#if (VEHICLE_TYPE == VEHICLE_GWM_EC01)
    /* This is for J1939 CAN bus off diagnostics to workaround ETAS stack problem */
    /* ETAS stack does not detect J1939 bus off properly */
    RE_CAN_BusOffJ1939_10ms();
#endif

}

/******************************************************************************
* @name    RE_CAN_Signals_500ms                                               *
* @brief   500ms runnable for outgoing CAN traffic                            *
*                                                                             *
*                                                                             *
* Function to receive app variables from upper layers and transmit CAN        *
* messages for signals that correspond to the 500ms rate                      *
******************************************************************************/
FUNC(void, CAN_Signals_CODE) RE_CAN_Signals_500ms(void)
{

}


/******************************************************************************
* @name    CAN_Transmission_Check                                             *
* @brief   Function the allow or disallow the transmission of CAN messages    *
*                                                                             *
* @retvalue    TRUE -  CAN traffic is allowed to transmit normally            *
* @retvalue FALSE - CAN traffic must be forcefully stopped from transmitting  *
*                                                                             *
* ECU entering test mode, RTC being the only wake to have been active, or     *
* application commanding a shutdown of the ECU are the three reasons that     *
* CAN traffic must be forcefully stopped                                      *
******************************************************************************/
bool CAN_Transmission_Check(void)
{
    bool Flag = TRUE;
    if( TestMode_IsSpecificTestModeActive( TEST_MODE_FULL ) == U16_SAFE_TRUE )
    {
        Flag = FALSE;
    }
    else if (VeLLSR_b_CanComNotAllowed == TRUE)
    {
        Flag = FALSE;
    }
#if((GWM_CAN_NM == FEATURE_ON)||(CHERY_CAN_NM == FEATURE_ON))
    else if (Powermode_CAN_Traffic_Allowed() == FALSE)
    {
        Flag = FALSE;
    }
#endif
    else if((VeCAN_BusOff_Counter >= Ke_CanBusOff_Threshold) && (VeCAN_BusOffSlowTimer >= Ke_CanBusOffSlowTime))
    {
        Flag = FALSE;
    }
    return Flag;
}

uint8 DTC_Signal_Transmission_Enabled(void)
{
    uint8 Le_DTC_Transmission_Enabled = FALSE;
    if (0 == VePMDR_b_DiagDisabled)
    {
        Le_DTC_Transmission_Enabled = TRUE;
    }
    return Le_DTC_Transmission_Enabled;
}


/*********************** Callback Function Definitions *************************/

FUNC(boolean,COM_CODE) TestRespMsg_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    // leave this as returning true or false for the time being until this is made
    // to be spontaneous instead of cyclic
    
    if (TestMode_IsTestRespMsgActive() == U16_SAFE_TRUE && TestRespMsg_TxBufferEntries > 0)
    {
        #if (TEST_MODE_TIMING == CYCLIC)
        ptr[0] = TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][0];
        ptr[1] = TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][1];
        ptr[2] = TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][2];
        ptr[3] = TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][3];
        ptr[4] = TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][4];
        ptr[5] = TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][5];
        ptr[6] = TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][6];
        ptr[7] = TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][7];
      
        TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][0] = 0;
        TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][1] = 0;
        TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][2] = 0;
        TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][3] = 0;
        TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][4] = 0;
        TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][5] = 0;
        TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][6] = 0;
        TestRespMsg_TxBuffer[TestRespMsg_TxBufferTransmittedIndex][7] = 0;
        #endif
        TestRespMsg_TxBufferEntries -= 1;

        TestRespMsg_TxBufferTransmittedIndex += 1;
        TestRespMsg_TxBufferTransmittedIndex %= TEST_RESP_MSG_TX_BUFFER_SIZE;

        return(TRUE);
    }
    else
    {
        return(FALSE);
    }
}


FUNC(void,COM_CODE) Rte_COMCbkTOut_Return_Current_IP_CSM_Fail(void){}
void Rte_COMCbkTOut_TestReq7(void){}
void Rte_COMCbkTOut_TestReq6(void){}
void Rte_COMCbkTOut_TestReq5(void){}
void Rte_COMCbkTOut_TestReq4(void){}
void Rte_COMCbkTOut_TestReq3(void){}
void Rte_COMCbkTOut_TestReq2(void){}
void Rte_COMCbkTOut_TestReq1(void){}
void Rte_COMCbkTOut_TestReq0(void){}
void Rte_COMCbk_TMR_CurrentHV(void){} 
void Rte_COMCbk_usrData5_CDU(void){}
void Rte_COMCbk_usrData4_CDU(void){}
void Rte_COMCbk_usrData3_CDU(void){}
void Rte_COMCbk_usrData2_CDU(void){}
void Rte_COMCbk_ECUSPEC_AWAKE_CDU(void){}
void Rte_COMCbk_DIAGNOSTIC_AWAKE_CDU(void){}
void Rte_COMCbk_IGNITION_AWAKE_CDU(void){}
void Rte_COMCbk_NETWORK_AWAKE_CDU(void){}
void Rte_COMCbk_ECUSPEC_WAKEUP_CDU(void){}
void Rte_COMCbk_NETWORK_WAKEUP_CDU(void){}
void Rte_COMCbk_RESET_WAKEUP_CDU(void){}
void Rte_COMCbk_IGNITION_WAKEUP_CDU(void){}
void Rte_COMCbk_usrData0_CDU(void){}
void Rte_COMCbk_NMm_CDU_Reserved1(void){}
void Rte_COMCbk_RMR_CDU(void){}
void Rte_COMCbk_srcNodeID_CDU(void){}
void Rte_COMCbk_usrData5_HCU(void){}
void Rte_COMCbk_usrData4_HCU(void){}
void Rte_COMCbk_usrData3_HCU(void){}
void Rte_COMCbk_usrData2_HCU(void){}
void Rte_COMCbk_ECUSPEC_AWAKE_HCU(void){}
void Rte_COMCbk_ABM_1_CheckSum(void){}
void Rte_COMCbk_ABM_1_MessageCounter(void){}
void Rte_COMCbk_BatteryVoltage(void){}
void Rte_COMCbk_CrashOutputSts(void){}
void Rte_COMCbk_DCDC_OutputCurr(void){}
void Rte_COMCbk_DCDC_OutputVolt(void){}
void Rte_COMCbk_DIAGNOSTIC_AWAKE_HCU(void){}
void Rte_COMCbk_DIAGNOSTIC_AWAKE_MCUF(void){}
void Rte_COMCbk_DIAGNOSTIC_AWAKE_MCUR(void){}
void Rte_COMCbk_ECUSPEC_AWAKE_MCUF(void){}
void Rte_COMCbk_ECUSPEC_AWAKE_MCUR(void){}
void Rte_COMCbk_ECUSPEC_WAKEUP_HCU(void){}
void Rte_COMCbk_ECUSPEC_WAKEUP_MCUF(void){}
void Rte_COMCbk_ECUSPEC_WAKEUP_MCUR(void){}
void Rte_COMCbk_ExternalTemperatureFailSts_GS(void){}
void Rte_COMCbk_ExternalTemperatureRaw_C(void){}

void Rte_COMCbk_IGNITION_AWAKE_HCU(void){}
void Rte_COMCbk_IGNITION_AWAKE_MCUF(void){}
void Rte_COMCbk_IGNITION_AWAKE_MCUR(void){}
void Rte_COMCbk_IGNITION_WAKEUP_HCU(void){}
void Rte_COMCbk_IGNITION_WAKEUP_MCUF(void){}
void Rte_COMCbk_IGNITION_WAKEUP_MCUR(void){}
void Rte_COMCbk_ISGF_IdcAct(void){}
void Rte_COMCbk_ISGF_ModeSt(void){}
void Rte_COMCbk_NETWORK_AWAKE_HCU(void){}
void Rte_COMCbk_NETWORK_AWAKE_MCUF(void){}
void Rte_COMCbk_NETWORK_AWAKE_MCUR(void){}
void Rte_COMCbk_NETWORK_WAKEUP_HCU(void){}
void Rte_COMCbk_NETWORK_WAKEUP_MCUF(void){}
void Rte_COMCbk_NETWORK_WAKEUP_MCUR(void){}
void Rte_COMCbk_NMm_HCU_Reserved1(void){}
void Rte_COMCbk_NMm_MCUF_Reserved1(void){}
void Rte_COMCbk_NMm_MCUR_Reserved1(void){}
//void Rte_COMCbk_OBC_ChgCurr(void){}
//void Rte_COMCbk_OBC_CP_DutyCycleFault(void){}
//void Rte_COMCbk_OBC_CP_DutyCycleValue(void){}
void Rte_COMCbk_OBC_InputCurr(void){}
void Rte_COMCbk_OBC_InputVolt(void){}
void Rte_COMCbk_OBC_KL30_UnderVolt(void){}
void Rte_COMCbk_OBC_MaxOutputVoltage(void){}
void Rte_COMCbk_OBC_FaultLevelSts(void){}
void Rte_COMCbk_OBC_ChgVolt(void){}
void Rte_COMCbk_OBC_StateHVIL(void){}
void Rte_COMCbk_RESET_WAKEUP_HCU(void){}
void Rte_COMCbk_RESET_WAKEUP_MCUF(void){}
void Rte_COMCbk_RESET_WAKEUP_MCUR(void){}
void Rte_COMCbk_Return_Current_IP_CSM_Fail(void){}
void Rte_COMCbk_Return_Current_IP_Sensor_Name(void){}
void Rte_COMCbk_RMR_HCU(void){}
void Rte_COMCbk_RMR_MCUF(void){}
void Rte_COMCbk_RMR_MCUR(void){}
void Rte_COMCbk_srcNodeID_HCU(void){}
void Rte_COMCbk_srcNodeID_MCUF(void){}
void Rte_COMCbk_srcNodeID_MCUR(void){}
void Rte_COMCbk_TMF_IdcAct(void){}
void Rte_COMCbk_TMF_ModeSt(void){}
void Rte_COMCbk_TMR_State(void){}
void Rte_COMCbk_usrData0_HCU(void){}
void Rte_COMCbk_usrData0_MCUF(void){}
void Rte_COMCbk_usrData0_MCUR(void){}
void Rte_COMCbk_usrData2_MCUF(void){}
void Rte_COMCbk_usrData2_MCUR(void){}
void Rte_COMCbk_usrData3_MCUF(void){}
void Rte_COMCbk_usrData3_MCUR(void){}
void Rte_COMCbk_usrData4_MCUF(void){}
void Rte_COMCbk_usrData4_MCUR(void){}
void Rte_COMCbk_usrData5_MCUF(void){}
void Rte_COMCbk_usrData5_MCUR(void){}
void Rte_COMCbk_OBC_ChargeSourceMode(void){}
void Rte_COMCbk_OBC_FaultCode(void){}
//void Rte_COMCbk_HCU_BattHeatAllow(void){}
void Rte_COMCbk_HCU_BattHVHAllow(void){}
void Rte_COMCbk_DCDC_LvSideCurr(void){}
void Rte_COMCbk_DCDC_LvSideVolt(void){}
void Rte_COMCbk_usrData5_ISG(void){}
void Rte_COMCbk_usrData4_ISG(void){}
void Rte_COMCbk_usrData3_ISG(void){}
void Rte_COMCbk_usrData2_ISG(void){}
void Rte_COMCbk_ECUSPEC_AWAKE_ISG(void){}
void Rte_COMCbk_DIAGNOSTIC_AWAKE_ISG(void){}
void Rte_COMCbk_IGNITION_AWAKE_ISG(void){}
void Rte_COMCbk_NETWORK_AWAKE_ISG(void){}
void Rte_COMCbk_ECUSPEC_WAKEUP_ISG(void){}
void Rte_COMCbk_NETWORK_WAKEUP_ISG(void){}
void Rte_COMCbk_RESET_WAKEUP_ISG(void){}
void Rte_COMCbk_IGNITION_WAKEUP_ISG(void){}
void Rte_COMCbk_usrData0_ISG(void){}
void Rte_COMCbk_NMm_ISGReserved1(void){}
void Rte_COMCbk_RMR_ISG(void){}
void Rte_COMCbk_srcNodeID_ISG(void){}
void Rte_COMCbk_usrData4_TMF(void){}
void Rte_COMCbk_usrData3_TMF(void){}
void Rte_COMCbk_usrData2_TMF(void){}
void Rte_COMCbk_usrData5_TMF(void){}
void Rte_COMCbk_DIAGNOSTIC_AWAKE_TMF(void){}
void Rte_COMCbk_IGNITION_AWAKE_TMF(void){}
void Rte_COMCbk_NETWORK_AWAKE_TMF(void){}
void Rte_COMCbk_ECUSPEC_WAKEUP_TMF(void){}
void Rte_COMCbk_NETWORK_WAKEUP_TMF(void){}
void Rte_COMCbk_RESET_WAKEUP_TMF(void){}
void Rte_COMCbk_IGNITION_WAKEUP_TMF(void){}
void Rte_COMCbk_usrData0_TMF(void){}
void Rte_COMCbk_NMm_TMF_Reserved1(void){}
void Rte_COMCbk_RMR_TMF(void){}
void Rte_COMCbk_srcNodeID_TMF(void){}
void Rte_COMCbk_ECUSPEC_AWAKE_TMF(void){}


FUNC(void,COM_CODE) Rte_COMCbk_CTS_dateActDay(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CTS_dateActHour(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CTS_dateActMin(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CTS_dateActMonth(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CTS_dateActSec(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CTS_dateActYear(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CEM_stToErrBatStatusMsg(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CEM_stToErrBatStatisticMsg(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CEM_stToErrBatParaMsg(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CEM_stToErrBatChStopMsg(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CEM_stToErrBatChRequestMsg(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CEM_stToErrBatChReadyMsg(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CEM_stToErrBatCarIdentMsg(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CSD_tiChAct(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CSD_nrChargerNr(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CSD_eOutEnergyAct(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CST_stStopSuspensionFault(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CST_stErrStopOther(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CST_stStopNormal(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CST_stStopManual(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CST_stStopErr(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CST_stErrStopMatchCurr(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CST_stErrStopChTempIntern(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CST_stErrStopChTemp(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CST_stErrStopChShutdown(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CST_stErrStopChEnergy(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CST_stErrStopChConnector(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CST_stErrStopAbnormalVolt(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CHM_nrProtocolVersion(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CRO_stChargerReady(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CML_iOutMin(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CML_iOutMax(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CML_uOutMax(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CML_uOutMin(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CCS_PermittingFlag(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CCS_uOutAct(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CCS_tiChAct(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CCS_iOutAct(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CRM_ascLocation(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CRM_nrChargerNr(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_CRM_stBmsIdentStatus(void) {}
FUNC(void,COM_CODE) Rte_COMCbk_OBC_CCLineConnectSts(void){}
FUNC(void,COM_CODE) Rte_COMCbk_OBC_CPLineSts(void){}
FUNC(void,COM_CODE) Rte_COMCbkTOut_Return_Current_IP_Value(void){}
FUNC(void,COM_CODE) Rte_COMCbkTOut_Return_Current_IP_Error_Info(void){}


#define RE_CAN_Signals_STOP_SEC_CODE
#include "CAN_Signals_MemMap.h"
