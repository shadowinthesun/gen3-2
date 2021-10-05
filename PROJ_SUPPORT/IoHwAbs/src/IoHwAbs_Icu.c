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
* @file   IoHwAbs_Icu.c                                                       *
*                                                                             *
* @Version 1.0                                                                *
*                                                                             *
* @date   2019.06.07                                                          *
*                                                                             *
* @brief  Interface through AUTOSAR Rte.                                      *
*                                                                             *
* Changeable by user:  NO                                                     *
*                                                                             *
* App / Low level interface.                                                  *
*                                                                             *
* Change history:                                                             *
* - V1.0: 2019.06.07 - K. Patel - Initial revision                            *
*                                                                             *
******************************************************************************/


/******************************* Includes ************************************/
#include "Rte_IoHwAbstraction.h"
#include "Icu_17_GtmCcu6.h"
#include "Crash_PWM_Measurement.h"

/**************************** Prebuild checks ********************************/


/************************* Private Macro Definitions *************************/


/*************************** Private Typedefs ********************************/


/*********************** Private Function Prototypes *************************/


/*********************** Global Constant Definitions *************************/


/*********************** Global Variable Definitions *************************/


/*********************** Private Constant Definitions ************************/


/*********************** Private Variable Definitions ************************/


/*********************** Global Function Definitions *************************/

/******************************************************************************
* @name                                                                       *
* @brief                                                                      *
*                                                                             *
* @param [in]                                                                 *
*                                                                             *
* Brief Description                                                           *
******************************************************************************/
void Icu_Init(void)
{
    /* Initialize MCAL ICU driver */
    Icu_17_GtmCcu6_Init(&Icu_ConfigRoot[0]);
}


/******************************************************************************
* @name                                                                       *
* @brief                                                                      *
*                                                                             *
* @param [in]                                                                 *
*                                                                             *
* Brief Description                                                           *
******************************************************************************/
FUNC(void, IoHwAbstraction_CODE) RE_IoHwAbs_Icu_1ms(void)
{
}
