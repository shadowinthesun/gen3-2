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
* @file   IoHwAbs_Dio.c                                                       *
*                                                                             *
* @Version 1.1                                                                *
*                                                                             *
* @date   2018.09.25                                                          *
*                                                                             *
* @brief  Interface through AUTOSAR Rte.                                      *
*                                                                             *
* Changeable by user:  NO                                                     *
*                                                                             *
* App / Low level interface.                                                  *
*                                                                             *
* Change history:                                                             *
* - V1.0: 2018.09.25 - Alberto Garrido - Initial revision                     *
* - V2.0: 2019.09.17 - Niharika Jha - Revised as per the new HaSI             *                                                                            *
******************************************************************************/


/******************************* Includes ************************************/

#include "Rte_IoHwAbstraction.h"
#include "IoHwAbs_Adc.h"
#include "IoHwAbs_Dio.h"
#include "Dio.h"
#include "TestMode.h"
#include "ASW_Types.h"

/**************************** Prebuild checks ********************************/


/************************* Private Macro Definitions *************************/

/*************************** Private Typedefs ********************************/


/*********************** Private Function Prototypes *************************/

static void Dio_Signals_fromApp_25ms(void);
static void Dio_WritePort_25ms(void);

/*********************** Global Constant Definitions *************************/


/*********************** Global Variable Definitions *************************/
extern uint32 BSWOvrd;
extern uint8 ConCmd;

extern bool VeLLSR_b_ShuntCurrPreFault;
extern bool VeLLSR_b_ShuntCurrPosFault;
extern bool VeLLSR_b_ShuntCurrHeatFault;
extern bool VeLLSR_b_ShuntCurrFSPFault;
extern bool VeLLSR_b_ShuntCurrNegFault;
extern uint16 VeLLIR_dc_MainCntctr_Neg_LSEN;

extern TeLLSR_Board_Version VeLLIR_k_BoardVer;

extern uint8 RAM_Mirror_Variant[1];

/*********************** Private Constant Definitions ************************/


/*********************** Private Variable Definitions ************************/

boolean VeLLIR_b_MainCntctr_Pre_HSEN = FALSE;
boolean VeLLIR_b_MainCntctr_Pos_HSEN = FALSE;
boolean VeLLIR_b_MainCntctr_Neg_HSEN = FALSE;
boolean VeLLIR_b_FastChargeCntctr_HSEN = FALSE;
boolean VeLLIR_b_HeatCntctr_HSEN = FALSE;


/*********************** Global Function Definitions *************************/

FUNC(void, IoHwAbstraction_CODE) RE_IoHwAbs_DIO_10ms(void)
{

}


FUNC(void, IoHwAbstraction_CODE) RE_IoHwAbs_DIO_25ms(void)
{
    Dio_Signals_fromApp_25ms();
    Dio_WritePort_25ms();
}


/******************************************************************************
* @name   GPIO_Outputs_Init                                                   *
* @brief  Initialises GPIO outputs to their default states                    *
******************************************************************************/
void GPIO_Outputs_Init(void)
{
    Dio_WriteChannel(DIO_CHANNEL_CAN2_STB,             STD_HIGH);
    Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_PRECHARGE, STD_LOW);

    // For Chery T1D - Sample B - Variant B - we do not have a Heat Film 
    if (RAM_Mirror_Variant[0] != SAMPLE_B_NO_HF_VARIANT)
    {  
        Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_HEAT_FILM, STD_LOW);
    } 

    Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_MAIN_POS,  STD_LOW);
    Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_MAIN_NEG,  STD_LOW);

    // For Chery T1D - Sample B - Variant C - we use a SHUNT instead of CAB500 or CSNV500
    if (RAM_Mirror_Variant[0] != SAMPLE_B_SHUNT_VARIANT)
    {
        Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_CAB500,    STD_HIGH);
    }

    Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_UNUSED_1,  STD_LOW);
    Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_UNUSED_2,  STD_LOW);
    Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_UNUSED_3,  STD_LOW);
    Dio_WriteChannel(DIO_CHANNEL_HV_EN,                STD_HIGH);
    Dio_WriteChannel(DIO_CHANNEL_HVIL_EN,              STD_LOW);
    Dio_WriteChannel(DIO_CHANNEL_SBC_ERROR,            STD_LOW);
    Dio_WriteChannel(DIO_CHANNEL_SBC_WDI,              STD_LOW);
    Dio_WriteChannel(DIO_CHANNEL_SPI_FRAM_CSB,         STD_HIGH);
    Dio_WriteChannel(DIO_CHANNEL_SPI_LSD_CSB,          STD_HIGH);
    Dio_WriteChannel(DIO_CHANNEL_SPI_SBC_CSB,          STD_HIGH);
    Dio_WriteChannel(DIO_CHANNEL_SPI_TPL1TX_CSB,       STD_HIGH);
    Dio_WriteChannel(DIO_CHANNEL_SPI_TPL2TX_CSB,       STD_HIGH);
    Dio_WriteChannel(DIO_CHANNEL_COOLDRV_FLTRST,       STD_LOW);
    Dio_WriteChannel(DIO_CHANNEL_COOLDRV_SEL0,         STD_LOW);
    Dio_WriteChannel(DIO_CHANNEL_COOLDRV_SEL1,         STD_LOW);
}


/******************************************************************************
* @name    GPIO_Outputs_Shutdown                                              *
* @brief   Turns off GPIOs during shutdown sequence                           *
*                                                                             *
* @return                                                                     *
*                                                                             *
******************************************************************************/
void GPIO_Outputs_Shutdown(void)
{
    Dio_WriteChannel(DIO_CHANNEL_HV_EN, STD_LOW);

    // For Chery T1D - Sample B - Variant C - we use a SHUNT instead of CAB500 or CSNV500
    if (RAM_Mirror_Variant[0] != SAMPLE_B_SHUNT_VARIANT)
    {
        Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_CAB500, STD_LOW);
    }
}


/*********************** Private Function Definitions ************************/

static void Dio_Signals_fromApp_25ms(void)
{
    VeLLIR_b_MainCntctr_Pre_HSEN = (boolean)Rte_IRead_RE_IoHwAbs_DIO_25ms_VeCFLR_b_EnblGPIOPre_drv_VeCFLR_b_EnblGPIOPre_drv();
    VeLLIR_b_MainCntctr_Pos_HSEN = (boolean)Rte_IRead_RE_IoHwAbs_DIO_25ms_VeCFLR_b_EnblGPIOPos_drv_VeCFLR_b_EnblGPIOPos_drv();
    VeLLIR_b_MainCntctr_Neg_HSEN = (boolean)Rte_IRead_RE_IoHwAbs_DIO_25ms_VeCFLR_b_EnblGPIONeg_drv_VeCFLR_b_EnblGPIONeg_drv();
    VeLLIR_b_HeatCntctr_HSEN     = (boolean)Rte_IRead_RE_IoHwAbs_DIO_25ms_VeCFLR_b_EnblGPIOHeat_drv_VeCFLR_b_EnblGPIOHeat_drv();
}


static void Dio_WritePort_25ms(void)
{
    if ( TestMode_IsSpecificTestModeActive( TEST_MODE_FULL ) != U16_SAFE_TRUE )
    {
        if(VeLLSR_b_ShuntCurrPosFault == FALSE)
	    {
            Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_MAIN_POS, VeLLIR_b_MainCntctr_Pos_HSEN);
        }
        
        if(VeLLSR_b_ShuntCurrNegFault == FALSE)
        {
            Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_MAIN_NEG, VeLLIR_b_MainCntctr_Neg_HSEN);
        }
		
		if(VeLLSR_b_ShuntCurrPreFault == FALSE)
		{
			Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_PRECHARGE, VeLLIR_b_MainCntctr_Pre_HSEN);
		}
        // For Chery T1D - Sample B - Variant B - we do not have a Heat Film
		if((VeLLSR_b_ShuntCurrHeatFault == FALSE) && (RAM_Mirror_Variant[0] != SAMPLE_B_NO_HF_VARIANT))
		{
			Dio_WriteChannel(DIO_CHANNEL_CONDRV_HSD_HEAT_FILM, VeLLIR_b_HeatCntctr_HSEN);
		}
	}
}
