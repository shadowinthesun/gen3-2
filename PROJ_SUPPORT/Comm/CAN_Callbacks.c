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
* @file   CAN_Callbacks.c                                                     *
*                                                                             *
* @Version 1.0                                                                *
*                                                                             *
* @date   May 30, 2019                                                        *
*                                                                             *
* @brief  Brief description of file.                                          *
*                                                                             *
* Changeable by user:  NO                                                     *
*                                                                             *
* Detailed description of file.                                               *
*                                                                             *
* Change history:                                                             *
* - V1.0: 2019.05.30 - s.mukhtar - Initial Revision                           *
* - V1.1: 2019.07.08 - K. Patel  - GWM NM updates                             *
*                                                                             *
******************************************************************************/

/******************************* Includes ************************************/
#include "Platform_Types.h"
#include "ComStack_Cfg.h"
#include "Compiler.h"
#include "Crc_Checksum.h"
#include "Can_Comm_Diagnostics.h"
#include "CAN_NM.h"
#include "Software_Version.h"
#include "DID_Component.h"
#include "Com.h"
#include "Com_Cfg_Internal.h"
#include "Com_Prv_Types.h"
#include "Com_Prv.h"
#include "Rte_PMDR.h"
#include "powermode.h"

/**************************** Prebuild checks ********************************/

/************************* Private Macro Definitions ************************/

/*************************** Private Typedefs ********************************/

/*********************** Private Function Prototypes *************************/
uint8 Update_Message_ARC_CRC(uint8 * msg);
bool CAN_Transmission_Check(void);

/*********************** Global Constant Definitions *************************/

/*********************** Global Variable Definitions *************************/

/*********************** Private Constant Definitions ************************/

#define SW_VERSION_STRING   F195_CONST_VALUE
#define HW_VERSION_STRING   F191_CONST_VALUE

#define SW_VERSION_SIZE     8u
#define HW_VERSION_SIZE     5u

/*********************** Private Variable Definitions ************************/

static uint8 SW_Version_Index = 0;
static uint8 HW_Version_Index = 0;


extern uint8 RAM_Mirror_Variant[1];
/*********************** Global Function Definitions *************************/

void CANNM_Config_Change_Chery_T1D_20ms(void)
{
	Com_TxIpduRamPtrType TxIpduRamPtr;
	TxIpduRamPtr = &Com_TxIpduRam_s[ComConf_ComIPdu_NMm_BMS_CANNODE_1];
	TxIpduRamPtr->Com_Tick_Tx=2;//change send time to 20ms 	Com_SendSignal(250, &data);
}

void CANNM_Config_Change_Chery_T1D_1000ms(void)
{
	Com_TxIpduRamPtrType TxIpduRamPtr;
	TxIpduRamPtr = &Com_TxIpduRam_s[ComConf_ComIPdu_NMm_BMS_CANNODE_1];
	TxIpduRamPtr->Com_Tick_Tx=100;//change send time to 1000ms 	Com_SendSignal(250, &data);
}

uint8 ABM_1_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Perform_Can_ARC_CRC_Diagnostics(CanRxMsg_ABM1, ptr);
    Declare_Message_Receipt(CanRxMsg_ABM1);
    return TRUE;
}

uint8 CLM_2_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Declare_Message_Receipt(CanRxMsg_CLM2);
    return TRUE;
}

uint8 DCDC_1_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Declare_Message_Receipt(CanRxMsg_DCDC1);
    return TRUE;
}

uint8 HCU_7_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Declare_Message_Receipt(CanRxMsg_HCU7);
    return TRUE;
}

uint8 ICM_1_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Declare_Message_Receipt(CanRxMsg_ICM1);
    return TRUE;
}

uint8 ISGF_1_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Declare_Message_Receipt(CanRxMsg_ISGF1);
    return TRUE;
}

uint8 ISGF_3_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Declare_Message_Receipt(CanRxMsg_ISGF3);
    return TRUE;
}

uint8 OBC_1_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Declare_Message_Receipt(CanRxMsg_OBC1);
    return TRUE;
}

uint8 OBC_2_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Declare_Message_Receipt(CanRxMsg_OBC2);
    return TRUE;
}

uint8 OBC_3_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Declare_Message_Receipt(CanRxMsg_OBC3);
    return TRUE;
}

uint8 OBC_4_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Declare_Message_Receipt(CanRxMsg_OBC4);
    return TRUE;
}

uint8 TMF_1_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Declare_Message_Receipt(CanRxMsg_TMF1);
    return TRUE;
}

uint8 TMF_3_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Declare_Message_Receipt(CanRxMsg_TMF3);
    return TRUE;
}

uint8 TMR_1_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Declare_Message_Receipt(CanRxMsg_TMR1);
    return TRUE;
}

uint8 TMR_3_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    Declare_Message_Receipt(CanRxMsg_TMR3);
    return TRUE;
}

uint8 TestReqMsg_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}


uint8 BMS_1_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;
    static uint8 live_counter=0;
	static uint8 crc_checksum=0;
	live_counter=live_counter+1;
	live_counter %= 16;
    crc_checksum=Update_Message_ARC_CRC(Com_IpduBuf_BMS_1_CANNODE_1);
	Com_InternalSendSignal(((VAR(Com_SignalIdType, AUTOMATIC))1), &live_counter);
    Com_InternalSendSignal(((VAR(Com_SignalIdType, AUTOMATIC))0), &crc_checksum);
	ReturnValue = CAN_Transmission_Check();
    return ReturnValue;
}

uint8 BMS_2_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
	boolean ReturnValue = TRUE;
    static uint8 live_counter=0;
	static uint8 crc_checksum=0XC2;
	live_counter=live_counter+1;
	live_counter %= 16;
    crc_checksum=Update_Message_ARC_CRC(Com_IpduBuf_BMS_2_CANNODE_1);
	Com_InternalSendSignal(((VAR(Com_SignalIdType, AUTOMATIC))8), &live_counter);
    Com_InternalSendSignal(((VAR(Com_SignalIdType, AUTOMATIC))7), &crc_checksum);
    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_3_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_4_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}


uint8 BMS_5_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
	boolean ReturnValue = TRUE;
    static uint8 live_counter=0;
	static uint8 crc_checksum=0;
	live_counter=live_counter+1;
	live_counter %= 16;
    crc_checksum=Update_Message_ARC_CRC(Com_IpduBuf_BMS_5_CANNODE_1);
	Com_InternalSendSignal(((VAR(Com_SignalIdType, AUTOMATIC))66), &live_counter);
    Com_InternalSendSignal(((VAR(Com_SignalIdType, AUTOMATIC))65), &crc_checksum);
    ReturnValue = CAN_Transmission_Check();
    return ReturnValue;
}

uint8 BMS_6_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;
    static uint8 live_counter=0;
	static uint8 crc_checksum=0;
	live_counter=live_counter+1;
	live_counter %= 16;
    crc_checksum=Update_Message_ARC_CRC(Com_IpduBuf_BMS_6_CANNODE_1);
	Com_InternalSendSignal(((VAR(Com_SignalIdType, AUTOMATIC))78), &live_counter);
    Com_InternalSendSignal(((VAR(Com_SignalIdType, AUTOMATIC))77), &crc_checksum);
    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_7_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
	boolean ReturnValue = TRUE;
    static uint8 live_counter=0;
	static uint8 crc_checksum=0;
	live_counter=live_counter+1;
	live_counter %= 16;
    crc_checksum=Update_Message_ARC_CRC(Com_IpduBuf_BMS_7_CANNODE_1);
	Com_InternalSendSignal(((VAR(Com_SignalIdType, AUTOMATIC))91), &live_counter);
    Com_InternalSendSignal(((VAR(Com_SignalIdType, AUTOMATIC))90), &crc_checksum);
    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_8_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;
    static uint8 live_counter=0;
	static uint8 crc_checksum=0xE2;
	live_counter=live_counter+1;
	live_counter %= 16;
    crc_checksum=Update_Message_ARC_CRC(Com_IpduBuf_BMS_8_CANNODE_1);
	Com_InternalSendSignal(((VAR(Com_SignalIdType, AUTOMATIC))103), &live_counter);
    Com_InternalSendSignal(((VAR(Com_SignalIdType, AUTOMATIC))102), &crc_checksum);
    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_9_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_10_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_11_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_12_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

/*zhuzx20201118
uint8 BMS_13_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_14_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_15_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_16_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue;

    Update_Message_ARC_CRC(ptr);
    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}
*/
uint8 BMS_17_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_18_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_19_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_20_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_21_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_22_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = CAN_Transmission_Check();
	uint8 variant = 0;

    if (ReturnValue)
    {
        uint8 Byte_Index = 1;

        if ( SW_Version_Index >= SW_VERSION_SIZE )
        {
            SW_Version_Index = 0;
        }

        while (Byte_Index < 8u)
        {
            if ( SW_Version_Index < SW_VERSION_SIZE )
            {
                ptr[ Byte_Index ] = (uint8) SW_VERSION_STRING[ SW_Version_Index++ ];
            }
            else
            {
				if((SW_Version_Index == SW_VERSION_SIZE) && (variant == 0))
				{
				   
		           ptr[Byte_Index] = (RAM_Mirror_Variant[0]);
				   variant = 1;
				}
				else
				{
					ptr[ Byte_Index ] = 0u;
				}
                
            }

            Byte_Index += 1;
        }

        ptr[0] = (uint8) ((SW_VERSION_SIZE << 4u) & 0xF0);

        if (SW_Version_Index > 0)
        {
            ptr[0] |= (uint8) ((((SW_Version_Index - 1u) / 7u) + 1u) & 0x0F);
        }
		
    }

    return ReturnValue;
}

uint8 BMS_23_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = CAN_Transmission_Check();

    if (ReturnValue)
    {
        uint8 Byte_Index = 1;

        if ( HW_Version_Index >= HW_VERSION_SIZE )
        {
            HW_Version_Index = 0;
        }

        while (Byte_Index < 8u)
        {
            if ( HW_Version_Index < HW_VERSION_SIZE )
            {
                ptr[ Byte_Index ] = (uint8) HW_VERSION_STRING[ HW_Version_Index++ ];
            }
            else
            {
                ptr[ Byte_Index ] = 0u;
            }

            Byte_Index += 1;
        }

        ptr[0] = (uint8) ((HW_VERSION_SIZE << 4u) & 0xF0);

        if (HW_Version_Index > 0)
        {
            ptr[0] |= (uint8) ((((HW_Version_Index - 1u) / 7u) + 1u) & 0x0F);
        }
    }

    return ReturnValue;
}

uint8 BMS_24_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_25_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Tem_1_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Tem_2_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Tem_3_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Tem_4_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Tem_5_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Tem_6_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_1_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_2_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_3_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_4_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_5_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_6_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_7_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_8_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_9_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_12_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_10_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_11_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_13_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_14_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_15_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_16_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_17_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_18_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_19_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_20_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_21_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_22_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_23_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 BMS_Vol_24_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    boolean ReturnValue = TRUE;

    ReturnValue = CAN_Transmission_Check();

    return ReturnValue;
}

uint8 CTS_Time_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 CEM_Errors_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 CSD_Statistic_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 CST_ChStop_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 CHM_Handshake_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 CRO_Ready_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 CML_Limits_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 CCS_Act_Values_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 CRM_Ident_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 Return_Current_IP_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 BHM_Handshake_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 BST_Stop_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 BEM_Errors_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 BSD_Statistic_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 BSM_State_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 BRO_Ready_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 BCL_Sv_Req_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 TP_BCS_ActValues_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 TP_BCP_Limits_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 TP_BMT_Temp_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 TP_BSP_Reserved_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 TP_BRM_Ident_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 TP_BMV_CellVoltage_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 NMm_BMS_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
	boolean ReturnValue = TRUE;
	static uint8 send_times=0;
    //ReturnValue = CAN_Transmission_Check();
	if((VePMDR_e_AppPowerModeState==12)||(VePMDR_e_AppPowerModeState==18))// if is slow charge ,it will send Can nm MESSAGE to wake up
	{
	    ReturnValue=true;
	}
	else
	{
	    ReturnValue=false;
	}
    if(send_times>11)
	{
		CANNM_Config_Change_Chery_T1D_1000ms();
	}
	else
	{
		CANNM_Config_Change_Chery_T1D_20ms();
	    send_times++;
	}	
    return ReturnValue;
}

uint8 NMm_CDU_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
	Declare_Message_Receipt(CanRxMsg_NMM_CDU);
    return TRUE;
}

uint8 NMm_HCU_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
	Declare_Message_Receipt(CanRxMsg_NMM_HCU);
    return TRUE;
}

uint8 NMm_MCUR_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
	Declare_Message_Receipt(CanRxMsg_NMM_MCUR);
    return TRUE;
}

uint8 NMm_HCU__Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}

uint8 NMm_ISG_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
	Declare_Message_Receipt(CanRxMsg_NMM_ISG);
    return TRUE;
}

uint8 NMm_TMF_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
	Declare_Message_Receipt(CanRxMsg_NMM_TMF);
    return TRUE;
}

uint8 NMm_CGW_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
	Declare_Message_Receipt(CanRxMsg_NMM_CGW);
    return TRUE;
}

uint8 TBOX_1_Cbk(VAR(PduIdType, AUTOMATIC) id, P2VAR(uint8, AUTOMATIC, COM_APPL_DATA) ptr)
{
    return TRUE;
}



/*********************** Private Function Definitions ************************/

uint8 Update_Message_ARC_CRC(uint8 * msg)
{
	uint8 data=0;
    typedef struct
    {
        uint8   arc  : 4u;
        uint8   data : 4u;
    }ARC_Byte;
    /* First update the alive rolling counter as a read, modify, write*/
    /* Read */
    ARC_Byte * Le_ARCByte = (ARC_Byte *) &msg[ ARC_LOCATION ];
    /* Modify */
    Le_ARCByte->arc += 1;
    Le_ARCByte->arc %= 16;
    /* Write */
    msg[ ARC_LOCATION ] = *((uint8 *) Le_ARCByte);

    /* Then update the checksum */
    msg[ CHECKSUM_LOCATION ] = Calculate_CRC8((const uint8 *) &msg[ 0 ], SIZEOF_PROTECTION_AREA);
	data = msg[ CHECKSUM_LOCATION ];
	return data;
}
