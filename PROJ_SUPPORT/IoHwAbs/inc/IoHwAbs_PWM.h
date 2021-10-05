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
* @file   IoHwAbs_Pwm.h                                                       *
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

#ifndef IOHWABS_PWM_H
#define IOHWABS_PWM_H

/******************************* Includes ************************************/
#include "IO_Mapping.h"

/************************** Global Macro Definitions *************************/

#define PWMChannel_CONDRV_LSD_PRECHARGE     PWM_CHANNEL_CONDRV_0_LSEN
#define PWMChannel_CONDRV_LSD_MAIN_POS      PWM_CHANNEL_CONDRV_1_LSEN
#define PWMChannel_CONDRV_LSD_MAIN_NEG      PWM_CHANNEL_CONDRV_2_LSEN
#define PWMChannel_CONDRV_LSD_HEAT_FILM     PWM_CHANNEL_CONDRV_3_LSEN
#define PWMChannel_CONDRV_LSD_FAST_CHRG     PWM_CHANNEL_CONDRV_4_LSEN

/*************************** Global Typedefs *********************************/


/********************** Global Constant Declarations *************************/


/*********************** Global Variable Declarations ************************/


/*********************** Global Function Declarations ************************/

void PWM_Init(void);
void PWM_Update_Freq_Sweeping(void);

#endif
