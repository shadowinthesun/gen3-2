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
* @file   IoHwAbs_Icu.h                                                       *
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
#ifndef IOHWABS_ICU_H
#define IOHWABS_ICU_H

/******************************* Includes ************************************/


/************************** Global Macro Definitions *************************/


/*************************** Global Typedefs *********************************/


/********************** Global Constant Declarations *************************/


/*********************** Global Variable Declarations ************************/


/*********************** Global Function Declarations ************************/
extern void Icu_Init(void);
extern void RE_IoHwAbs_Icu_1ms(void);

#endif  /* IOHWABS_ICU_H */
