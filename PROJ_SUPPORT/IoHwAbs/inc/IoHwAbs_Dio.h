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
* @file   IoHwAbs_Dio.h                                                       *
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

#ifndef IOHWABS_DIO_H
#define IOHWABS_DIO_H

/******************************* Includes ************************************/
#include "IO_Mapping.h"

/************************** Global Macro Definitions *************************/

#define DIO_CHANNEL_CONDRV_HSD_PRECHARGE    (DIO_CHANNEL_HSD_O_00_EN)
#define DIO_CHANNEL_CONDRV_HSD_HEAT_FILM    (DIO_CHANNEL_HSD_O_01_EN)
#define DIO_CHANNEL_CONDRV_HSD_MAIN_POS     (DIO_CHANNEL_HSD_O_02_EN)
#define DIO_CHANNEL_CONDRV_HSD_MAIN_NEG     (DIO_CHANNEL_HSD_O_03_EN)
#define DIO_CHANNEL_CONDRV_HSD_UNUSED_1     (DIO_CHANNEL_HSD_O_04_EN)
#define DIO_CHANNEL_CONDRV_HSD_CAB500       (DIO_CHANNEL_HSD_O_05_EN)
#define DIO_CHANNEL_CONDRV_HSD_UNUSED_2     (DIO_CHANNEL_HSD_O_06_EN)
#define DIO_CHANNEL_CONDRV_HSD_UNUSED_3     (DIO_CHANNEL_HSD_O_07_EN)


/*************************** Global Typedefs *********************************/


/********************** Global Constant Declarations *************************/


/*********************** Global Variable Declarations ************************/


/*********************** Global Function Declarations ************************/

void GPIO_Outputs_Init(void);
void GPIO_Outputs_Shutdown(void);

#endif
