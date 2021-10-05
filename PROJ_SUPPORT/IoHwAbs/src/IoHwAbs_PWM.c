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
* @file   IoHwAbs_PWM.c                                                       *
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
*                                                                             *
******************************************************************************/


/******************************* Includes ************************************/

#include "timing.h"
#include "Rte_IoHwAbstraction.h"
#include "IoHwAbs_Adc.h"
#include "IoHwAbs_PWM.h"
#include "Pwm_17_Gtm.h"
#include "Mcu.h"
#include "TestMode.h"

/**************************** Prebuild checks ********************************/


/************************* Private Macro Definitions *************************/

#define DEFAULT_FREQUENCY 10000
#define CONDRV_FREQUENCY  1600

#define CONVERT_DCYCLE_UINT16 327.68f
#define MAX_DUTYCYCLE 0x8000
#define HALF_DUTYCYCLE 0x4000

#define Set_Floor_And_Ceiling_Float(fpv, floor, ceiling)    ((fpv > ceiling) ? ceiling : (fpv < floor) ? floor : fpv)

/*************************** Private Typedefs ********************************/


/*********************** Private Function Prototypes *************************/

static void PWM_Signals_fromApp_25ms(void);
static void Calculate_DutyCycle (void);
static uint16 Convert_DutyCycle(float percent);
static void Write_PWM_DutyCycle(void);

#if (HARDWARE_PLATFORM == PLATFORM_SCU)
    static void PWM_PSISO_Sweeping(void);
#endif

/*********************** Global Constant Definitions *************************/


/*********************** Global Variable Definitions *************************/
#if (HARDWARE_PLATFORM == PLATFORM_SCU)
float VeLLIR_pct_MainCntctr_Pos_LSEN = 0.0f;
float VeLLIR_pct_MainCntctr_Neg_LSEN = 0.0f;
float VeLLIR_pct_MainCntctr_Pre_LSEN = 0.0f;
float VeLLIR_pct_HeatCntctr_LSEN = 0.0f;
float VeLLIR_pct_FspCntctr_LSEN = 0.0f;
uint16 VeLLIR_dc_MainCntctr_Pos_LSEN = 0;
uint16 VeLLIR_dc_MainCntctr_Neg_LSEN = 0;
uint16 VeLLIR_dc_MainCntctr_Pre_LSEN = 0;
uint16 VeLLIR_dc_HeatCntctr_LSEN = 0;
uint16 VeLLIR_dc_Heat1Cntctr_LSEN = 0;
uint16 VeLLIR_dc_FspCntctr_LSEN = 0;
#endif
uint16 VeLLIR_dc_HVILEN0 = 0;
uint16 VeLLIR_dc_HVILEN1 = 0;
uint16 VeLLIR_dc_FANSPD0 = 0;
uint16 VeLLIR_dc_FANSPD1 = 0;

/*********************** Private Constant Definitions ************************/


/*********************** Private Variable Definitions ************************/

#if (HARDWARE_PLATFORM == PLATFORM_SCU)
static uint16 VeLLIR_dc_HVMPS_CLK1 = HALF_DUTYCYCLE;
static uint32 VeLLIR_f_HVMPS_CLK1;
static bool VeLLIR_b_SweepingState = TRUE;    // used to store the state increasing/decreasing of the frequency sweeping
static uint32 VeLLIR_f_MinFrequency;
static uint32 VeLLIR_f_MaxFrequency;
static uint32 VeLLIR_n_FrequencyStep;
static uint8 VeLLIR_n_SweepIterations;
#endif

/*********************** Global Function Definitions *************************/
/******************************************************************************
* @name                                                                       *
* @brief                                                                      *
*                                                                             *
* @param [in]                                                                 *
*                                                                             *
* Brief Description                                                           *
******************************************************************************/

FUNC(void, IoHwAbstraction_CODE) RE_IoHwAbs_PWM_1ms(void)
{
#if (HARDWARE_PLATFORM == PLATFORM_SCU)
    PWM_PSISO_Sweeping();
#endif
}

/******************************************************************************
* @name                                                                       *
* @brief                                                                      *
*                                                                             *
* @param [in]                                                                 *
*                                                                             *
* Brief Description                                                           *
******************************************************************************/

FUNC(void, IoHwAbstraction_CODE) RE_IoHwAbs_PWM_25ms(void)
{
    PWM_Signals_fromApp_25ms();
    Calculate_DutyCycle();
    Write_PWM_DutyCycle();
}

/******************************************************************************
* @name                                                                       *
* @brief                                                                      *
*                                                                             *
* @param [in]                                                                 *
*                                                                             *
* Brief Description                                                           *
******************************************************************************/

void PWM_Init(void)
{
    /* initialize MCAL PWM driver */
    Pwm_17_Gtm_Init(&Pwm_ConfigRoot[0]);
    Pwm_17_Gtm_SetPeriodAndDuty(PWM_CHANNEL_CONDRV_CLK, GTM_CLK / CONDRV_FREQUENCY, HALF_DUTYCYCLE);
}

/******************************************************************************
* @name                                                                       *
* @brief                                                                      *
*                                                                             *
* @param [in]                                                                 *
*                                                                             *
* Brief Description                                                           *
******************************************************************************/

void PWM_Update_Freq_Sweeping(void)
{
#if (HARDWARE_PLATFORM == PLATFORM_SCU)
    VeLLIR_f_MinFrequency = 200;    // 200KHz
    VeLLIR_f_MaxFrequency = 550;    // 500KHz
    VeLLIR_n_SweepIterations = 20;

    VeLLIR_n_FrequencyStep = (uint32)((VeLLIR_f_MaxFrequency - VeLLIR_f_MinFrequency) / VeLLIR_n_SweepIterations);
    VeLLIR_f_HVMPS_CLK1 = VeLLIR_f_MinFrequency;
#endif
}

/*********************** Private Function Definitions ************************/

static void PWM_Signals_fromApp_25ms(void)
{
#if (HARDWARE_PLATFORM == PLATFORM_SCU)
    VeLLIR_pct_MainCntctr_Pos_LSEN = Set_Floor_And_Ceiling_Float(Rte_IRead_RE_IoHwAbs_PWM_25ms_VeCFLR_Pct_ContctrPWM_Pos_drv_VeCFLR_Pct_ContctrPWM_Pos_drv(), 0.0f, 100.0f);
    VeLLIR_pct_MainCntctr_Neg_LSEN = Set_Floor_And_Ceiling_Float(Rte_IRead_RE_IoHwAbs_PWM_25ms_VeCFLR_Pct_ContctrPWM_Neg_drv_VeCFLR_Pct_ContctrPWM_Neg_drv(), 0.0f, 100.0f);
    VeLLIR_pct_MainCntctr_Pre_LSEN = Set_Floor_And_Ceiling_Float(Rte_IRead_RE_IoHwAbs_PWM_25ms_VeCFLR_Pct_ContctrPWM_Pre_drv_VeCFLR_Pct_ContctrPWM_Pre_drv(), 0.0f, 100.0f);
    VeLLIR_pct_HeatCntctr_LSEN = Set_Floor_And_Ceiling_Float(Rte_IRead_RE_IoHwAbs_PWM_25ms_VeCFLR_Pct_ContctrPWM_Heat_drv_VeCFLR_Pct_ContctrPWM_Heat_drv(), 0.0f, 100.0f);
    VeLLIR_pct_FspCntctr_LSEN = Set_Floor_And_Ceiling_Float(Rte_IRead_RE_IoHwAbs_PWM_25ms_VeCFLR_Pct_ContctrPWM_Fsp_drv_VeCFLR_Pct_ContctrPWM_Fsp_drv(), 0.0f, 100.0f);
#endif
}

static void Calculate_DutyCycle (void)
{
#if (HARDWARE_PLATFORM == PLATFORM_SCU)
    VeLLIR_dc_MainCntctr_Pos_LSEN = Convert_DutyCycle(VeLLIR_pct_MainCntctr_Pos_LSEN);
    VeLLIR_dc_MainCntctr_Neg_LSEN = Convert_DutyCycle(VeLLIR_pct_MainCntctr_Neg_LSEN);
    VeLLIR_dc_MainCntctr_Pre_LSEN = Convert_DutyCycle(VeLLIR_pct_MainCntctr_Pre_LSEN);
    VeLLIR_dc_HeatCntctr_LSEN = Convert_DutyCycle(VeLLIR_pct_HeatCntctr_LSEN);
    VeLLIR_dc_FspCntctr_LSEN = Convert_DutyCycle(VeLLIR_pct_FspCntctr_LSEN);
#endif

    VeLLIR_dc_HVILEN0 = Convert_DutyCycle(0);
    VeLLIR_dc_HVILEN1 = Convert_DutyCycle(0);

    VeLLIR_dc_FANSPD0 = Convert_DutyCycle(0);
    VeLLIR_dc_FANSPD1 = Convert_DutyCycle(0);
}

static uint16 Convert_DutyCycle(float percent)
{
    uint16 result;

    result = (uint16)((100.0f - percent) * CONVERT_DCYCLE_UINT16);
    if(result > MAX_DUTYCYCLE)
    {
        result = MAX_DUTYCYCLE;
    }
    return result;
}

static void Write_PWM_DutyCycle(void)
{
    if ( TestMode_IsSpecificTestModeActive( TEST_MODE_FULL ) != U16_SAFE_TRUE )
    {
#if (HARDWARE_PLATFORM == PLATFORM_SCU)
        Pwm_17_Gtm_SetPeriodAndDuty(PWM_CHANNEL_CONDRV_LSD_MAIN_POS, GTM_CLK / DEFAULT_FREQUENCY, VeLLIR_dc_MainCntctr_Pos_LSEN);
        Pwm_17_Gtm_SetPeriodAndDuty(PWM_CHANNEL_CONDRV_LSD_MAIN_NEG, GTM_CLK / DEFAULT_FREQUENCY, VeLLIR_dc_MainCntctr_Neg_LSEN);
        Pwm_17_Gtm_SetPeriodAndDuty(PWM_CHANNEL_CONDRV_LSD_PRECHARGE, GTM_CLK / DEFAULT_FREQUENCY, VeLLIR_dc_MainCntctr_Pre_LSEN);    // 10KHz, 100%   // 10KHz, 100%
        Pwm_17_Gtm_SetPeriodAndDuty(PWM_CHANNEL_CONDRV_LSD_HEAT_FILM, GTM_CLK / DEFAULT_FREQUENCY, VeLLIR_dc_HeatCntctr_LSEN);    // 10KHz, 100%   // 10KHz, 100%
        Pwm_17_Gtm_SetPeriodAndDuty(PWM_CHANNEL_CONDRV_LSD_FAST_CHRG, GTM_CLK / DEFAULT_FREQUENCY, VeLLIR_dc_FspCntctr_LSEN);    // 10KHz, 100%   // 10KHz, 100%
#endif
        Pwm_17_Gtm_SetPeriodAndDuty(PWM_CHANNEL_HVIL_EN_0, GTM_CLK / DEFAULT_FREQUENCY, VeLLIR_dc_HVILEN0);
        Pwm_17_Gtm_SetPeriodAndDuty(PWM_CHANNEL_HVIL_EN_1, GTM_CLK / DEFAULT_FREQUENCY, VeLLIR_dc_HVILEN1);
        Pwm_17_Gtm_SetPeriodAndDuty(PWM_CHANNEL_SETSPD_0, GTM_CLK / DEFAULT_FREQUENCY, VeLLIR_dc_FANSPD0);
#if (HARDWARE_PLATFORM == PLATFORM_BMC)
        Pwm_17_Gtm_SetPeriodAndDuty(PWM_CHANNEL_SETSPD_1, GTM_CLK / DEFAULT_FREQUENCY, VeLLIR_dc_FANSPD1);
#endif
    }
}

#if (HARDWARE_PLATFORM == PLATFORM_SCU)
static void PWM_PSISO_Sweeping(void)
{
    if(VeLLIR_f_HVMPS_CLK1 != 0)
    {
        Pwm_17_Gtm_SetPeriodAndDuty(Pwm_17_GtmConf_PwmChannel_HVMPS_CLK1, (Pwm_17_Gtm_PeriodType)(100000/VeLLIR_f_HVMPS_CLK1), VeLLIR_dc_HVMPS_CLK1); // 100MHz clock
    }

    if(VeLLIR_b_SweepingState)
    {
        VeLLIR_f_HVMPS_CLK1 += VeLLIR_n_FrequencyStep;
        if(VeLLIR_f_HVMPS_CLK1 >= VeLLIR_f_MaxFrequency)
        {
            VeLLIR_b_SweepingState = FALSE;
            VeLLIR_f_HVMPS_CLK1 = VeLLIR_f_MaxFrequency;
        }
    }
    else
    {
        if(VeLLIR_f_HVMPS_CLK1 > VeLLIR_n_FrequencyStep)
        {
            VeLLIR_f_HVMPS_CLK1 -= VeLLIR_n_FrequencyStep;
        }
        else
        {
            VeLLIR_f_HVMPS_CLK1 = VeLLIR_f_MinFrequency;
        }
        if(VeLLIR_f_HVMPS_CLK1 <= VeLLIR_f_MinFrequency)
        {
            VeLLIR_b_SweepingState = TRUE;
            VeLLIR_f_HVMPS_CLK1 = VeLLIR_f_MinFrequency;
        }
    }
}
#endif
