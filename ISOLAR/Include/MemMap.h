/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : MemMap.h $                                                 **
**                                                                           **
**  $CC VERSION : \main\61 $                                                 **
**                                                                           **
**  $DATE       : 2013-07-08 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION :                                                            **
**                                                                           **
**             This file allows to map variables, constants and code         **
**             of modules to individual memory sections. The user can        **
**             adapt the memory mapping to their ECU specific needs.         **
**                                                                           **
**             Important note 1: if specific variables and constants are     **
**             mapped to banked/paged memory, the related compiler           **
**             abstraction symbols must fit to these locations!              **
**                                                                           **
**             Important note 2: The section names passed via #pragmas must  **
**             be defined in the linker control and section map files!       **
**  SPECIFICATION(S) : AUTOSAR_SWS_MemoryMapping.pdf,Release 1.0.0           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: yes                                     **
**                                                                           **
******************************************************************************/

/******************************************************************************
**                      Module section mapping                               **
******************************************************************************/
/*
 * The symbol 'START_WITH_IF' is undefined.
 *
 * Thus, the preprocessor continues searching for defined symbols
 * This first #ifdef makes integration of delivered parts of MemMap.h
 * easier because every supplier starts with #elif
 */
/*
 * MemMap 019 published information
 */

#ifndef MEMMAP_H
#define MEMMAP_H


/* Mem Vendor ID */
#define MEM_VENDOR_ID         ((uint16)17)

/* MEM SW Major Version */
#define MEM_SW_MAJOR_VERSION  (1U)
/* MEM SW Minor Version */
#define MEM_SW_MINOR_VERSION  (0)
/* MEM SW Patch Version */
#define MEM_SW_PATCH_VERSION  (0)

/* MEM AR Major Version */
#define MEM_AR_MAJOR_VERSION  (1U)
/* MEM AR Minor Version */
#define MEM_AR_MINOR_VERSION  (0)
/* MEM AR Patch Version */
#define MEM_AR_PATCH_VERSION  (13U)

#endif
/*
  Identifier clash , upto 60 characters allowed
  MISRA Rule 92 violation : #undef should not be used.
  MemMap works with undefine and redefine principle.
*/
/*lint -idlen(60) -esym(961,92) */


/*lint -esym(960,19.6)   */  /* Allow usage of #undef */
#if defined (START_WITH_IF)

/*****************************************************************************
**                                 MCU                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (MCU_START_SEC_CODE)

   #undef      MCU_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (MCU_STOP_SEC_CODE)
   #undef      MCU_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (MCU_START_SEC_SAFETY_CODE)
   #undef      MCU_START_SEC_SAFETY_CODE
   #define   DEFAULT_START_SEC_SAFETY_CODE_SHARED
#elif defined (MCU_STOP_SEC_SAFETY_CODE)
   #undef      MCU_STOP_SEC_SAFETY_CODE
   #define DEFAULT_STOP_SEC_SAFETY_CODE_SHARED


#elif defined (MCU_START_SEC_QM_CODE)
   #undef      MCU_START_SEC_QM_CODE
   #define   DEFAULT_START_SEC_QM_CODE_SHARED
#elif defined (MCU_STOP_SEC_QM_CODE)
   #undef      MCU_STOP_SEC_QM_CODE
   #define DEFAULT_STOP_SEC_QM_CODE_SHARED


#elif defined (MCU_START_SEC_VAR_NOINIT_8BIT)
   #undef      MCU_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      MCU_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (MCU_START_SEC_VAR_NOINIT_16BIT)
   #undef      MCU_START_SEC_VAR_NOINIT_16BIT
   #define   MCU_START_SEC_USER_VAR_16BIT
#elif defined (MCU_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      MCU_STOP_SEC_VAR_NOINIT_16BIT
   #define MCU_STOP_SEC_USER_VAR_16BIT


#elif defined (MCU_START_SEC_VAR_NOINIT_32BIT)
   #undef      MCU_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      MCU_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (MCU_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      MCU_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (MCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      MCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (MCU_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      MCU_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      MCU_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (MCU_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      MCU_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      MCU_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (MCU_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      MCU_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      MCU_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (MCU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      MCU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (MCU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      MCU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (MCU_START_SEC_VAR_FAST_8BIT)
   #undef      MCU_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_FAST_8BIT)
   #undef      MCU_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (MCU_START_SEC_VAR_FAST_16BIT)
   #undef      MCU_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_FAST_16BIT)
   #undef      MCU_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (MCU_START_SEC_VAR_FAST_32BIT)
   #undef      MCU_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_FAST_32BIT)
   #undef      MCU_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (MCU_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      MCU_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (MCU_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      MCU_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (MCU_START_SEC_VAR_8BIT)
   #undef      MCU_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_8BIT)
   #undef      MCU_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (MCU_START_SEC_VAR_16BIT)
   #undef      MCU_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_16BIT)
   #undef      MCU_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (MCU_START_SEC_VAR_32BIT)
   #undef      MCU_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (MCU_STOP_SEC_VAR_32BIT)
   #undef      MCU_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (MCU_START_SEC_VAR_UNSPECIFIED)
   #undef      MCU_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (MCU_STOP_SEC_VAR_UNSPECIFIED)
   #undef      MCU_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (MCU_START_SEC_CONST_8BIT)
   #undef      MCU_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (MCU_STOP_SEC_CONST_8BIT)
   #undef      MCU_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (MCU_START_SEC_CONST_16BIT)
   #undef      MCU_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (MCU_STOP_SEC_CONST_16BIT)
   #undef      MCU_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (MCU_START_SEC_CONST_32BIT)
   #undef      MCU_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (MCU_STOP_SEC_CONST_32BIT)
   #undef      MCU_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (MCU_START_SEC_CONST_UNSPECIFIED)
   #undef      MCU_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (MCU_STOP_SEC_CONST_UNSPECIFIED)
   #undef      MCU_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (MCU_START_SEC_POSTBUILDCFG)
   #undef      MCU_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (MCU_STOP_SEC_POSTBUILDCFG)
   #undef      MCU_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 BFX                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (BFX_START_SEC_CODE)
   #undef      BFX_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (BFX_STOP_SEC_CODE)
   #undef      BFX_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED

/*****************************************************************************
**                                 DIO                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (DIO_START_SEC_CODE)
   #undef      DIO_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (DIO_STOP_SEC_CODE)
   #undef      DIO_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (DIO_START_SEC_VAR_NOINIT_8BIT)
   #undef      DIO_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      DIO_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (DIO_START_SEC_VAR_NOINIT_16BIT)
   #undef      DIO_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      DIO_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (DIO_START_SEC_VAR_NOINIT_32BIT)
   #undef      DIO_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      DIO_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (DIO_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DIO_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (DIO_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DIO_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (DIO_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      DIO_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      DIO_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (DIO_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      DIO_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      DIO_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (DIO_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      DIO_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      DIO_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (DIO_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      DIO_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (DIO_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      DIO_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (DIO_START_SEC_VAR_FAST_8BIT)
   #undef      DIO_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_FAST_8BIT)
   #undef      DIO_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (DIO_START_SEC_VAR_FAST_16BIT)
   #undef      DIO_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_FAST_16BIT)
   #undef      DIO_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (DIO_START_SEC_VAR_FAST_32BIT)
   #undef      DIO_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_FAST_32BIT)
   #undef      DIO_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (DIO_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DIO_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (DIO_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DIO_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (DIO_START_SEC_VAR_8BIT)
   #undef      DIO_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_8BIT)
   #undef      DIO_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (DIO_START_SEC_VAR_16BIT)
   #undef      DIO_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_16BIT)
   #undef      DIO_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (DIO_START_SEC_VAR_32BIT)
   #undef      DIO_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (DIO_STOP_SEC_VAR_32BIT)
   #undef      DIO_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (DIO_START_SEC_VAR_UNSPECIFIED)
   #undef      DIO_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (DIO_STOP_SEC_VAR_UNSPECIFIED)
   #undef      DIO_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (DIO_START_SEC_CONST_8BIT)
   #undef      DIO_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (DIO_STOP_SEC_CONST_8BIT)
   #undef      DIO_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (DIO_START_SEC_CONST_16BIT)
   #undef      DIO_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (DIO_STOP_SEC_CONST_16BIT)
   #undef      DIO_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (DIO_START_SEC_CONST_32BIT)
   #undef      DIO_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (DIO_STOP_SEC_CONST_32BIT)
   #undef      DIO_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (DIO_START_SEC_CONST_UNSPECIFIED)
   #undef      DIO_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (DIO_STOP_SEC_CONST_UNSPECIFIED)
   #undef      DIO_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (DIO_START_SEC_POSTBUILDCFG)
   #undef      DIO_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (DIO_STOP_SEC_POSTBUILDCFG)
   #undef      DIO_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 GPT                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (GPT_START_SEC_CODE)
   #undef      GPT_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_CODE)
   #undef      GPT_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_NOINIT_8BIT)
   #undef      GPT_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      GPT_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_NOINIT_16BIT)
   #undef      GPT_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      GPT_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_NOINIT_32BIT)
   #undef      GPT_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      GPT_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      GPT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      GPT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      GPT_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      GPT_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      GPT_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      GPT_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      GPT_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      GPT_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      GPT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      GPT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_FAST_8BIT)
   #undef      GPT_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_FAST_8BIT)
   #undef      GPT_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_FAST_16BIT)
   #undef      GPT_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_FAST_16BIT)
   #undef      GPT_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_FAST_32BIT)
   #undef      GPT_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_FAST_32BIT)
   #undef      GPT_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      GPT_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      GPT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_8BIT)
   #undef      GPT_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_8BIT)
   #undef      GPT_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_16BIT)
   #undef      GPT_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_16BIT)
   #undef      GPT_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_32BIT)
   #undef      GPT_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_32BIT)
   #undef      GPT_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_VAR_UNSPECIFIED)
   #undef      GPT_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_VAR_UNSPECIFIED)
   #undef      GPT_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE


#elif defined (GPT_START_SEC_CONST_8BIT)
   #undef      GPT_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_CONST_8BIT)
   #undef      GPT_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_CONST_16BIT)
   #undef      GPT_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_CONST_16BIT)
   #undef      GPT_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_CONST_32BIT)
   #undef      GPT_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_CONST_32BIT)
   #undef      GPT_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_CORE1_PRIVATE


#elif defined (GPT_START_SEC_CONST_UNSPECIFIED)
   #undef      GPT_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_CONST_UNSPECIFIED)
   #undef      GPT_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE


#elif defined (GPT_START_SEC_POSTBUILDCFG)
   #undef      GPT_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_CORE1_PRIVATE
#elif defined (GPT_STOP_SEC_POSTBUILDCFG)
   #undef      GPT_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE

/*****************************************************************************
**                                 ICU_17_GTMCCU6                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (ICU_17_GTMCCU6_START_SEC_CODE)
   #undef      ICU_17_GTMCCU6_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_CODE)
   #undef      ICU_17_GTMCCU6_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_8BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_16BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_32BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_FAST_8BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_8BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_FAST_16BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_16BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_FAST_32BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_32BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_8BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_8BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_16BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_16BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_32BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_32BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_VAR_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_VAR_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_CONST_8BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_CONST_8BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_CONST_16BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_CONST_16BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_CONST_32BIT)
   #undef      ICU_17_GTMCCU6_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_CONST_32BIT)
   #undef      ICU_17_GTMCCU6_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_CONST_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_CONST_UNSPECIFIED)
   #undef      ICU_17_GTMCCU6_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (ICU_17_GTMCCU6_START_SEC_POSTBUILDCFG)
   #undef      ICU_17_GTMCCU6_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (ICU_17_GTMCCU6_STOP_SEC_POSTBUILDCFG)
   #undef      ICU_17_GTMCCU6_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 PWM_17_GTM                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (PWM_17_GTM_START_SEC_CODE)
   #undef      PWM_17_GTM_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_CODE)
   #undef      PWM_17_GTM_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_NOINIT_8BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_NOINIT_16BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_NOINIT_32BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      PWM_17_GTM_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      PWM_17_GTM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      PWM_17_GTM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      PWM_17_GTM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_FAST_8BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_FAST_8BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_FAST_16BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_FAST_16BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_FAST_32BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_FAST_32BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      PWM_17_GTM_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      PWM_17_GTM_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_8BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_8BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_16BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_16BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_32BIT)
   #undef      PWM_17_GTM_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_32BIT)
   #undef      PWM_17_GTM_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_VAR_UNSPECIFIED)
   #undef      PWM_17_GTM_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_VAR_UNSPECIFIED)
   #undef      PWM_17_GTM_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (PWM_17_GTM_START_SEC_CONST_8BIT)
   #undef      PWM_17_GTM_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_CONST_8BIT)
   #undef      PWM_17_GTM_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_CONST_16BIT)
   #undef      PWM_17_GTM_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_CONST_16BIT)
   #undef      PWM_17_GTM_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_CONST_32BIT)
   #undef      PWM_17_GTM_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_CONST_32BIT)
   #undef      PWM_17_GTM_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (PWM_17_GTM_START_SEC_CONST_UNSPECIFIED)
   #undef      PWM_17_GTM_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_CONST_UNSPECIFIED)
   #undef      PWM_17_GTM_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (PWM_17_GTM_START_SEC_POSTBUILDCFG)
   #undef      PWM_17_GTM_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (PWM_17_GTM_STOP_SEC_POSTBUILDCFG)
   #undef      PWM_17_GTM_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 GTM                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (GTM_START_SEC_CODE)
   #undef      GTM_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (GTM_STOP_SEC_CODE)
   #undef      GTM_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (GTM_START_SEC_VAR_NOINIT_8BIT)
   #undef      GTM_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      GTM_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (GTM_START_SEC_VAR_NOINIT_16BIT)
   #undef      GTM_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      GTM_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (GTM_START_SEC_VAR_NOINIT_32BIT)
   #undef      GTM_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      GTM_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (GTM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      GTM_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (GTM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      GTM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (GTM_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      GTM_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      GTM_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (GTM_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      GTM_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      GTM_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (GTM_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      GTM_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      GTM_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (GTM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      GTM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (GTM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      GTM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (GTM_START_SEC_VAR_FAST_8BIT)
   #undef      GTM_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_FAST_8BIT)
   #undef      GTM_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (GTM_START_SEC_VAR_FAST_16BIT)
   #undef      GTM_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_FAST_16BIT)
   #undef      GTM_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (GTM_START_SEC_VAR_FAST_32BIT)
   #undef      GTM_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_FAST_32BIT)
   #undef      GTM_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (GTM_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      GTM_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (GTM_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      GTM_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (GTM_START_SEC_VAR_8BIT)
   #undef      GTM_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_8BIT)
   #undef      GTM_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (GTM_START_SEC_VAR_16BIT)
   #undef      GTM_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_16BIT)
   #undef      GTM_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (GTM_START_SEC_VAR_32BIT)
   #undef      GTM_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (GTM_STOP_SEC_VAR_32BIT)
   #undef      GTM_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (GTM_START_SEC_VAR_UNSPECIFIED)
   #undef      GTM_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (GTM_STOP_SEC_VAR_UNSPECIFIED)
   #undef      GTM_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (GTM_START_SEC_CONST_8BIT)
   #undef      GTM_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (GTM_STOP_SEC_CONST_8BIT)
   #undef      GTM_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (GTM_START_SEC_CONST_16BIT)
   #undef      GTM_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (GTM_STOP_SEC_CONST_16BIT)
   #undef      GTM_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (GTM_START_SEC_CONST_32BIT)
   #undef      GTM_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (GTM_STOP_SEC_CONST_32BIT)
   #undef      GTM_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (GTM_START_SEC_CONST_UNSPECIFIED)
   #undef      GTM_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (GTM_STOP_SEC_CONST_UNSPECIFIED)
   #undef      GTM_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (GTM_START_SEC_POSTBUILDCFG)
   #undef      GTM_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (GTM_STOP_SEC_POSTBUILDCFG)
   #undef      GTM_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 PORT                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (PORT_START_SEC_CODE)
   #undef      PORT_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (PORT_STOP_SEC_CODE)
   #undef      PORT_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (PORT_START_SEC_VAR_NOINIT_8BIT)
   #undef      PORT_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      PORT_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (PORT_START_SEC_VAR_NOINIT_16BIT)
   #undef      PORT_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      PORT_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (PORT_START_SEC_VAR_NOINIT_32BIT)
   #undef      PORT_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      PORT_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (PORT_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      PORT_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (PORT_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      PORT_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (PORT_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      PORT_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      PORT_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (PORT_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      PORT_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      PORT_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (PORT_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      PORT_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      PORT_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (PORT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      PORT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (PORT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      PORT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (PORT_START_SEC_VAR_FAST_8BIT)
   #undef      PORT_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_FAST_8BIT)
   #undef      PORT_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (PORT_START_SEC_VAR_FAST_16BIT)
   #undef      PORT_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_FAST_16BIT)
   #undef      PORT_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (PORT_START_SEC_VAR_FAST_32BIT)
   #undef      PORT_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_FAST_32BIT)
   #undef      PORT_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (PORT_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      PORT_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (PORT_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      PORT_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (PORT_START_SEC_VAR_8BIT)
   #undef      PORT_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_8BIT)
   #undef      PORT_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (PORT_START_SEC_VAR_16BIT)
   #undef      PORT_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_16BIT)
   #undef      PORT_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (PORT_START_SEC_VAR_32BIT)
   #undef      PORT_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (PORT_STOP_SEC_VAR_32BIT)
   #undef      PORT_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (PORT_START_SEC_VAR_UNSPECIFIED)
   #undef      PORT_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (PORT_STOP_SEC_VAR_UNSPECIFIED)
   #undef      PORT_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (PORT_START_SEC_CONST_8BIT)
   #undef      PORT_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (PORT_STOP_SEC_CONST_8BIT)
   #undef      PORT_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (PORT_START_SEC_CONST_16BIT)
   #undef      PORT_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (PORT_STOP_SEC_CONST_16BIT)
   #undef      PORT_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (PORT_START_SEC_CONST_32BIT)
   #undef      PORT_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (PORT_STOP_SEC_CONST_32BIT)
   #undef      PORT_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (PORT_START_SEC_CONST_UNSPECIFIED)
   #undef      PORT_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (PORT_STOP_SEC_CONST_UNSPECIFIED)
   #undef      PORT_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (PORT_START_SEC_POSTBUILDCFG)
   #undef      PORT_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (PORT_STOP_SEC_POSTBUILDCFG)
   #undef      PORT_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 CAN_17_MCANP                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (CAN_17_MCANP_START_SEC_CODE)
   #undef      CAN_17_MCANP_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_CODE)
   #undef      CAN_17_MCANP_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_NOINIT_8BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_NOINIT_16BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_NOINIT_32BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CAN_17_MCANP_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CAN_17_MCANP_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_FAST_8BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_FAST_8BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_FAST_16BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_FAST_16BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_FAST_32BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_FAST_32BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CAN_17_MCANP_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_8BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_8BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_16BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_16BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_32BIT)
   #undef      CAN_17_MCANP_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_32BIT)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_VAR_UNSPECIFIED)
   #undef      CAN_17_MCANP_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_VAR_UNSPECIFIED)
   #undef      CAN_17_MCANP_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (CAN_17_MCANP_START_SEC_CONST_8BIT)
   #undef      CAN_17_MCANP_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_CONST_8BIT)
   #undef      CAN_17_MCANP_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_CONST_16BIT)
   #undef      CAN_17_MCANP_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_CONST_16BIT)
   #undef      CAN_17_MCANP_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_CONST_32BIT)
   #undef      CAN_17_MCANP_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_CONST_32BIT)
   #undef      CAN_17_MCANP_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (CAN_17_MCANP_START_SEC_CONST_UNSPECIFIED)
   #undef      CAN_17_MCANP_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_CONST_UNSPECIFIED)
   #undef      CAN_17_MCANP_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (CAN_17_MCANP_START_SEC_POSTBUILDCFG)
   #undef      CAN_17_MCANP_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (CAN_17_MCANP_STOP_SEC_POSTBUILDCFG)
   #undef      CAN_17_MCANP_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 SPI                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (SPI_START_SEC_CODE)
   #undef      SPI_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (SPI_STOP_SEC_CODE)
   #undef      SPI_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (SPI_START_SEC_VAR_NOINIT_8BIT)
   #undef      SPI_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      SPI_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (SPI_START_SEC_VAR_NOINIT_16BIT)
   #undef      SPI_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      SPI_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (SPI_START_SEC_VAR_NOINIT_32BIT)
   #undef      SPI_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      SPI_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (SPI_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      SPI_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      SPI_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (SPI_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      SPI_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      SPI_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (SPI_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      SPI_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      SPI_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (SPI_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      SPI_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      SPI_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (SPI_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      SPI_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (SPI_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      SPI_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (SPI_START_SEC_VAR_FAST_8BIT)
   #undef      SPI_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_FAST_8BIT)
   #undef      SPI_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (SPI_START_SEC_VAR_FAST_16BIT)
   #undef      SPI_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_FAST_16BIT)
   #undef      SPI_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (SPI_START_SEC_VAR_FAST_32BIT)
   #undef      SPI_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_FAST_32BIT)
   #undef      SPI_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (SPI_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      SPI_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (SPI_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      SPI_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (SPI_START_SEC_VAR_8BIT)
   #undef      SPI_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_8BIT)
   #undef      SPI_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (SPI_START_SEC_VAR_16BIT)
   #undef      SPI_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_16BIT)
   #undef      SPI_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (SPI_START_SEC_VAR_32BIT)
   #undef      SPI_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (SPI_STOP_SEC_VAR_32BIT)
   #undef      SPI_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (SPI_START_SEC_VAR_UNSPECIFIED)
   #undef      SPI_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (SPI_STOP_SEC_VAR_UNSPECIFIED)
   #undef      SPI_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (SPI_START_SEC_CONST_8BIT)
   #undef      SPI_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (SPI_STOP_SEC_CONST_8BIT)
   #undef      SPI_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (SPI_START_SEC_CONST_16BIT)
   #undef      SPI_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (SPI_STOP_SEC_CONST_16BIT)
   #undef      SPI_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (SPI_START_SEC_CONST_32BIT)
   #undef      SPI_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (SPI_STOP_SEC_CONST_32BIT)
   #undef      SPI_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (SPI_START_SEC_CONST_UNSPECIFIED)
   #undef      SPI_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (SPI_STOP_SEC_CONST_UNSPECIFIED)
   #undef      SPI_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (SPI_START_SEC_POSTBUILDCFG)
   #undef      SPI_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (SPI_STOP_SEC_POSTBUILDCFG)
   #undef      SPI_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 ADC                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (ADC_START_SEC_CODE)
   #undef      ADC_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (ADC_STOP_SEC_CODE)
   #undef      ADC_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (ADC_START_SEC_VAR_NOINIT_8BIT)
   #undef      ADC_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      ADC_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (ADC_START_SEC_VAR_NOINIT_16BIT)
   #undef      ADC_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      ADC_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (ADC_START_SEC_VAR_NOINIT_32BIT)
   #undef      ADC_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      ADC_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (ADC_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ADC_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ADC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (ADC_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ADC_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ADC_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (ADC_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ADC_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ADC_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (ADC_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ADC_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ADC_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (ADC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ADC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (ADC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ADC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (ADC_START_SEC_VAR_FAST_8BIT)
   #undef      ADC_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_FAST_8BIT)
   #undef      ADC_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (ADC_START_SEC_VAR_FAST_16BIT)
   #undef      ADC_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_FAST_16BIT)
   #undef      ADC_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (ADC_START_SEC_VAR_FAST_32BIT)
   #undef      ADC_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_FAST_32BIT)
   #undef      ADC_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (ADC_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ADC_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (ADC_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ADC_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (ADC_START_SEC_VAR_8BIT)
   #undef      ADC_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_8BIT)
   #undef      ADC_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (ADC_START_SEC_VAR_16BIT)
   #undef      ADC_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_16BIT)
   #undef      ADC_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (ADC_START_SEC_VAR_32BIT)
   #undef      ADC_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (ADC_STOP_SEC_VAR_32BIT)
   #undef      ADC_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (ADC_START_SEC_VAR_UNSPECIFIED)
   #undef      ADC_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (ADC_STOP_SEC_VAR_UNSPECIFIED)
   #undef      ADC_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (ADC_START_SEC_CONST_8BIT)
   #undef      ADC_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (ADC_STOP_SEC_CONST_8BIT)
   #undef      ADC_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (ADC_START_SEC_CONST_16BIT)
   #undef      ADC_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (ADC_STOP_SEC_CONST_16BIT)
   #undef      ADC_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (ADC_START_SEC_CONST_32BIT)
   #undef      ADC_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (ADC_STOP_SEC_CONST_32BIT)
   #undef      ADC_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (ADC_START_SEC_CONST_UNSPECIFIED)
   #undef      ADC_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (ADC_STOP_SEC_CONST_UNSPECIFIED)
   #undef      ADC_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (ADC_START_SEC_POSTBUILDCFG)
   #undef      ADC_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (ADC_STOP_SEC_POSTBUILDCFG)
   #undef      ADC_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 WDG_17_SCU                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (WDG_17_SCU_START_SEC_CODE)
   #undef      WDG_17_SCU_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_CODE)
   #undef      WDG_17_SCU_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_NOINIT_8BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_NOINIT_16BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_NOINIT_32BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      WDG_17_SCU_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      WDG_17_SCU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      WDG_17_SCU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      WDG_17_SCU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_FAST_8BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_FAST_8BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_FAST_16BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_FAST_16BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_FAST_32BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_FAST_32BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      WDG_17_SCU_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      WDG_17_SCU_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_8BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_8BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_16BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_16BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_32BIT)
   #undef      WDG_17_SCU_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_32BIT)
   #undef      WDG_17_SCU_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_VAR_UNSPECIFIED)
   #undef      WDG_17_SCU_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_VAR_UNSPECIFIED)
   #undef      WDG_17_SCU_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (WDG_17_SCU_START_SEC_CONST_8BIT)
   #undef      WDG_17_SCU_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_CONST_8BIT)
   #undef      WDG_17_SCU_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_CONST_16BIT)
   #undef      WDG_17_SCU_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_CONST_16BIT)
   #undef      WDG_17_SCU_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_CONST_32BIT)
   #undef      WDG_17_SCU_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_CONST_32BIT)
   #undef      WDG_17_SCU_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (WDG_17_SCU_START_SEC_CONST_UNSPECIFIED)
   #undef      WDG_17_SCU_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_CONST_UNSPECIFIED)
   #undef      WDG_17_SCU_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (WDG_17_SCU_START_SEC_POSTBUILDCFG)
   #undef      WDG_17_SCU_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (WDG_17_SCU_STOP_SEC_POSTBUILDCFG)
   #undef      WDG_17_SCU_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 CANTRCV_17_6250GV33                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (CANTRCV_17_6250GV33_START_SEC_CODE)
   #undef      CANTRCV_17_6250GV33_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_CODE)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_8BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_16BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_32BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_FAST_8BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_8BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_FAST_16BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_16BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_FAST_32BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_32BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_8BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_8BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_16BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_16BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_32BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_32BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_VAR_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_VAR_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_CONST_8BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_CONST_8BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_CONST_16BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_CONST_16BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_CONST_32BIT)
   #undef      CANTRCV_17_6250GV33_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_CONST_32BIT)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (CANTRCV_17_6250GV33_START_SEC_CONST_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6250GV33_STOP_SEC_CONST_UNSPECIFIED)
   #undef      CANTRCV_17_6250GV33_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 CANTRCV_17_6251G                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (CANTRCV_17_6251G_START_SEC_CODE)
   #undef      CANTRCV_17_6251G_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_CODE)
   #undef      CANTRCV_17_6251G_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_NOINIT_8BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_NOINIT_16BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_NOINIT_32BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_FAST_8BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_FAST_8BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_FAST_16BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_FAST_16BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_FAST_32BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_FAST_32BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_8BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_8BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_16BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_16BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_32BIT)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_32BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_VAR_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_VAR_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_CONST_8BIT)
   #undef      CANTRCV_17_6251G_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_CONST_8BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_CONST_16BIT)
   #undef      CANTRCV_17_6251G_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_CONST_16BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_CONST_32BIT)
   #undef      CANTRCV_17_6251G_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_CONST_32BIT)
   #undef      CANTRCV_17_6251G_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (CANTRCV_17_6251G_START_SEC_CONST_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (CANTRCV_17_6251G_STOP_SEC_CONST_UNSPECIFIED)
   #undef      CANTRCV_17_6251G_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 DMA                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (DMA_START_SEC_CODE)
   #undef      DMA_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (DMA_STOP_SEC_CODE)
   #undef      DMA_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (DMA_START_SEC_VAR_NOINIT_8BIT)
   #undef      DMA_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      DMA_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (DMA_START_SEC_VAR_NOINIT_16BIT)
   #undef      DMA_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      DMA_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (DMA_START_SEC_VAR_NOINIT_32BIT)
   #undef      DMA_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      DMA_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (DMA_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DMA_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (DMA_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      DMA_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (DMA_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      DMA_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      DMA_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (DMA_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      DMA_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      DMA_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (DMA_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      DMA_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      DMA_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (DMA_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      DMA_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (DMA_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      DMA_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (DMA_START_SEC_VAR_FAST_8BIT)
   #undef      DMA_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_FAST_8BIT)
   #undef      DMA_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (DMA_START_SEC_VAR_FAST_16BIT)
   #undef      DMA_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_FAST_16BIT)
   #undef      DMA_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (DMA_START_SEC_VAR_FAST_32BIT)
   #undef      DMA_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_FAST_32BIT)
   #undef      DMA_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (DMA_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DMA_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (DMA_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      DMA_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (DMA_START_SEC_VAR_8BIT)
   #undef      DMA_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_8BIT)
   #undef      DMA_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (DMA_START_SEC_VAR_16BIT)
   #undef      DMA_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_16BIT)
   #undef      DMA_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (DMA_START_SEC_VAR_32BIT)
   #undef      DMA_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (DMA_STOP_SEC_VAR_32BIT)
   #undef      DMA_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (DMA_START_SEC_VAR_UNSPECIFIED)
   #undef      DMA_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (DMA_STOP_SEC_VAR_UNSPECIFIED)
   #undef      DMA_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (DMA_START_SEC_CONST_8BIT)
   #undef      DMA_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (DMA_STOP_SEC_CONST_8BIT)
   #undef      DMA_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (DMA_START_SEC_CONST_16BIT)
   #undef      DMA_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (DMA_STOP_SEC_CONST_16BIT)
   #undef      DMA_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (DMA_START_SEC_CONST_32BIT)
   #undef      DMA_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (DMA_STOP_SEC_CONST_32BIT)
   #undef      DMA_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (DMA_START_SEC_CONST_UNSPECIFIED)
   #undef      DMA_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (DMA_STOP_SEC_CONST_UNSPECIFIED)
   #undef      DMA_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 FLSLOADER                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (FLSLOADER_START_SEC_CODE)
   #undef      FLSLOADER_START_SEC_CODE
#ifdef _TASKING_C_TRICORE_
      #pragma section code "FLSLOADER_SOURCE"
      #pragma optimize R
   #elif _GNU_C_TRICORE_
      #pragma section ".text.FLSLOADER_SOURCE" ax
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".FLSLOADER_SOURCE" far-absolute RX
   #endif
#elif defined (FLSLOADER_STOP_SEC_CODE)
   #undef      FLSLOADER_STOP_SEC_CODE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
      #pragma endoptimize
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif


#elif defined (FLSLOADER_START_SEC_WRITE_CODE)
   #undef      FLSLOADER_START_SEC_WRITE_CODE
   #define   DEFAULT_START_SEC_WRITE_CODE_SHARED
#elif defined (FLSLOADER_STOP_SEC_WRITE_CODE)
   #undef      FLSLOADER_STOP_SEC_WRITE_CODE
   #define DEFAULT_STOP_SEC_WRITE_CODE_SHARED


#elif defined (FLSLOADER_START_SEC_ERASE_CODE)
   #undef      FLSLOADER_START_SEC_ERASE_CODE
   #define   DEFAULT_START_SEC_ERASE_CODE_SHARED
#elif defined (FLSLOADER_STOP_SEC_ERASE_CODE)
   #undef      FLSLOADER_STOP_SEC_ERASE_CODE
   #define DEFAULT_STOP_SEC_ERASE_CODE_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_NOINIT_8BIT)
   #undef      FLSLOADER_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_NOINIT_16BIT)
   #undef      FLSLOADER_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_NOINIT_32BIT)
   #undef      FLSLOADER_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FLSLOADER_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FLSLOADER_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FLSLOADER_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FLSLOADER_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FLSLOADER_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FLSLOADER_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FLSLOADER_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_FAST_8BIT)
   #undef      FLSLOADER_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_FAST_8BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_FAST_16BIT)
   #undef      FLSLOADER_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_FAST_16BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_FAST_32BIT)
   #undef      FLSLOADER_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_FAST_32BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FLSLOADER_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FLSLOADER_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_8BIT)
   #undef      FLSLOADER_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_8BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_16BIT)
   #undef      FLSLOADER_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_16BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_32BIT)
   #undef      FLSLOADER_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_32BIT)
   #undef      FLSLOADER_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (FLSLOADER_START_SEC_VAR_UNSPECIFIED)
   #undef      FLSLOADER_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (FLSLOADER_STOP_SEC_VAR_UNSPECIFIED)
   #undef      FLSLOADER_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (FLSLOADER_START_SEC_CONST_8BIT)
   #undef      FLSLOADER_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_CONST_8BIT)
   #undef      FLSLOADER_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (FLSLOADER_START_SEC_CONST_16BIT)
   #undef      FLSLOADER_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_CONST_16BIT)
   #undef      FLSLOADER_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (FLSLOADER_START_SEC_CONST_32BIT)
   #undef      FLSLOADER_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (FLSLOADER_STOP_SEC_CONST_32BIT)
   #undef      FLSLOADER_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (FLSLOADER_START_SEC_CONST_UNSPECIFIED)
   #undef      FLSLOADER_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (FLSLOADER_STOP_SEC_CONST_UNSPECIFIED)
   #undef      FLSLOADER_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 IRQ                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (IRQ_START_SEC_CODE)
   #undef      IRQ_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (IRQ_STOP_SEC_CODE)
   #undef      IRQ_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (IRQ_START_SEC_VAR_NOINIT_8BIT)
   #undef      IRQ_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      IRQ_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_NOINIT_16BIT)
   #undef      IRQ_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      IRQ_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_NOINIT_32BIT)
   #undef      IRQ_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      IRQ_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      IRQ_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (IRQ_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      IRQ_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (IRQ_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      IRQ_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      IRQ_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      IRQ_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      IRQ_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      IRQ_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      IRQ_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      IRQ_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (IRQ_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      IRQ_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (IRQ_START_SEC_VAR_FAST_8BIT)
   #undef      IRQ_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_FAST_8BIT)
   #undef      IRQ_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_FAST_16BIT)
   #undef      IRQ_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_FAST_16BIT)
   #undef      IRQ_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_FAST_32BIT)
   #undef      IRQ_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_FAST_32BIT)
   #undef      IRQ_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      IRQ_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (IRQ_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      IRQ_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (IRQ_START_SEC_VAR_8BIT)
   #undef      IRQ_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_8BIT)
   #undef      IRQ_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_16BIT)
   #undef      IRQ_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_16BIT)
   #undef      IRQ_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_32BIT)
   #undef      IRQ_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (IRQ_STOP_SEC_VAR_32BIT)
   #undef      IRQ_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (IRQ_START_SEC_VAR_UNSPECIFIED)
   #undef      IRQ_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (IRQ_STOP_SEC_VAR_UNSPECIFIED)
   #undef      IRQ_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (IRQ_START_SEC_CONST_8BIT)
   #undef      IRQ_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (IRQ_STOP_SEC_CONST_8BIT)
   #undef      IRQ_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (IRQ_START_SEC_CONST_16BIT)
   #undef      IRQ_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (IRQ_STOP_SEC_CONST_16BIT)
   #undef      IRQ_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (IRQ_START_SEC_CONST_32BIT)
   #undef      IRQ_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (IRQ_STOP_SEC_CONST_32BIT)
   #undef      IRQ_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (IRQ_START_SEC_CONST_UNSPECIFIED)
   #undef      IRQ_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (IRQ_STOP_SEC_CONST_UNSPECIFIED)
   #undef      IRQ_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 FEE                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (FEE_START_SEC_CODE)
   #undef      FEE_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (FEE_STOP_SEC_CODE)
   #undef      FEE_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (FEE_START_SEC_VAR_NOINIT_8BIT)
   #undef      FEE_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      FEE_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (FEE_START_SEC_VAR_NOINIT_16BIT)
   #undef      FEE_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      FEE_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (FEE_START_SEC_VAR_NOINIT_32BIT)
   #undef      FEE_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      FEE_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (FEE_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FEE_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FEE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (FEE_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FEE_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FEE_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (FEE_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FEE_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FEE_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (FEE_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FEE_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FEE_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (FEE_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FEE_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (FEE_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FEE_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (FEE_START_SEC_VAR_FAST_8BIT)
   #undef      FEE_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_FAST_8BIT)
   #undef      FEE_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (FEE_START_SEC_VAR_FAST_16BIT)
   #undef      FEE_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_FAST_16BIT)
   #undef      FEE_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (FEE_START_SEC_VAR_FAST_32BIT)
   #undef      FEE_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_FAST_32BIT)
   #undef      FEE_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (FEE_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FEE_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (FEE_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FEE_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (FEE_START_SEC_VAR_8BIT)
   #undef      FEE_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_8BIT)
   #undef      FEE_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (FEE_START_SEC_VAR_16BIT)
   #undef      FEE_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_16BIT)
   #undef      FEE_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (FEE_START_SEC_VAR_32BIT)
   #undef      FEE_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (FEE_STOP_SEC_VAR_32BIT)
   #undef      FEE_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (FEE_START_SEC_SPL_VAR_32BIT)
   #undef      FEE_START_SEC_SPL_VAR_32BIT
   #define   DEFAULT_START_SEC_SPL_VAR_32BIT_SHARED
#elif defined (FEE_STOP_SEC_SPL_VAR_32BIT)
   #undef      FEE_STOP_SEC_SPL_VAR_32BIT
   #define DEFAULT_STOP_SEC_SPL_VAR_32BIT_SHARED


#elif defined (FEE_START_SEC_VAR_UNSPECIFIED)
   #undef      FEE_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (FEE_STOP_SEC_VAR_UNSPECIFIED)
   #undef      FEE_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (FEE_START_SEC_CONST_8BIT)
   #undef      FEE_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (FEE_STOP_SEC_CONST_8BIT)
   #undef      FEE_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (FEE_START_SEC_CONST_16BIT)
   #undef      FEE_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (FEE_STOP_SEC_CONST_16BIT)
   #undef      FEE_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (FEE_START_SEC_CONST_32BIT)
   #undef      FEE_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (FEE_STOP_SEC_CONST_32BIT)
   #undef      FEE_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (FEE_START_SEC_CONST_UNSPECIFIED)
   #undef      FEE_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (FEE_STOP_SEC_CONST_UNSPECIFIED)
   #undef      FEE_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 SENT                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (SENT_START_SEC_POSTBUILDCFG)
   #undef      SENT_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (SENT_STOP_SEC_POSTBUILDCFG)
   #undef      SENT_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED


#elif defined (SENT_START_SEC_VAR_32BIT)
   #undef      SENT_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (SENT_STOP_SEC_VAR_32BIT)
   #undef      SENT_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (SENT_START_SEC_VAR_8BIT)
   #undef      SENT_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (SENT_STOP_SEC_VAR_8BIT)
   #undef      SENT_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (SENT_START_SEC_CODE)
   #undef      SENT_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (SENT_STOP_SEC_CODE)
   #undef      SENT_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED

/*****************************************************************************
**                                 IOM                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (IOM_START_SEC_POSTBUILDCFG)
   #undef      IOM_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (IOM_STOP_SEC_POSTBUILDCFG)
   #undef      IOM_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED


#elif defined (IOM_START_SEC_CODE)
   #undef      IOM_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (IOM_STOP_SEC_CODE)
   #undef      IOM_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (IOM_START_SEC_VAR_8BIT)
   #undef      IOM_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (IOM_STOP_SEC_VAR_8BIT)
   #undef      IOM_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (IOM_START_SEC_VAR_32BIT)
   #undef      IOM_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (IOM_STOP_SEC_VAR_32BIT)
   #undef      IOM_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED

/*****************************************************************************
**                                 FLS_17_PMU                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (FLS_17_PMU_START_SEC_CODE)
   #undef      FLS_17_PMU_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_CODE)
   #undef      FLS_17_PMU_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_NOINIT_8BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_NOINIT_16BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_NOINIT_32BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FLS_17_PMU_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FLS_17_PMU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FLS_17_PMU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FLS_17_PMU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_FAST_8BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_FAST_8BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_FAST_16BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_FAST_16BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_FAST_32BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_FAST_32BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FLS_17_PMU_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FLS_17_PMU_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_8BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_8BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_16BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_16BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_32BIT)
   #undef      FLS_17_PMU_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_32BIT)
   #undef      FLS_17_PMU_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_SPL_VAR_32BIT)
   #undef      FLS_17_PMU_START_SEC_SPL_VAR_32BIT
   #define   DEFAULT_START_SEC_SPL_VAR_32BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_SPL_VAR_32BIT)
   #undef      FLS_17_PMU_STOP_SEC_SPL_VAR_32BIT
   #define DEFAULT_STOP_SEC_SPL_VAR_32BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_VAR_UNSPECIFIED)
   #undef      FLS_17_PMU_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_VAR_UNSPECIFIED)
   #undef      FLS_17_PMU_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (FLS_17_PMU_START_SEC_CONST_8BIT)
   #undef      FLS_17_PMU_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_CONST_8BIT)
   #undef      FLS_17_PMU_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_CONST_16BIT)
   #undef      FLS_17_PMU_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_CONST_16BIT)
   #undef      FLS_17_PMU_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_CONST_32BIT)
   #undef      FLS_17_PMU_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_CONST_32BIT)
   #undef      FLS_17_PMU_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (FLS_17_PMU_START_SEC_CONST_UNSPECIFIED)
   #undef      FLS_17_PMU_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_CONST_UNSPECIFIED)
   #undef      FLS_17_PMU_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (FLS_17_PMU_START_SEC_POSTBUILDCFG)
   #undef      FLS_17_PMU_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (FLS_17_PMU_STOP_SEC_POSTBUILDCFG)
   #undef      FLS_17_PMU_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 ERU                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (ERU_START_SEC_CODE)
   #undef      ERU_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (ERU_STOP_SEC_CODE)
   #undef      ERU_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (ERU_START_SEC_VAR_NOINIT_8BIT)
   #undef      ERU_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      ERU_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (ERU_START_SEC_VAR_NOINIT_16BIT)
   #undef      ERU_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      ERU_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (ERU_START_SEC_VAR_NOINIT_32BIT)
   #undef      ERU_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      ERU_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (ERU_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ERU_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (ERU_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ERU_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (ERU_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ERU_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ERU_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (ERU_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ERU_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ERU_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (ERU_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ERU_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ERU_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (ERU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ERU_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (ERU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ERU_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (ERU_START_SEC_VAR_FAST_8BIT)
   #undef      ERU_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_FAST_8BIT)
   #undef      ERU_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (ERU_START_SEC_VAR_FAST_16BIT)
   #undef      ERU_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_FAST_16BIT)
   #undef      ERU_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (ERU_START_SEC_VAR_FAST_32BIT)
   #undef      ERU_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_FAST_32BIT)
   #undef      ERU_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (ERU_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ERU_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (ERU_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ERU_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (ERU_START_SEC_VAR_8BIT)
   #undef      ERU_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_8BIT)
   #undef      ERU_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (ERU_START_SEC_VAR_16BIT)
   #undef      ERU_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_16BIT)
   #undef      ERU_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (ERU_START_SEC_VAR_32BIT)
   #undef      ERU_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (ERU_STOP_SEC_VAR_32BIT)
   #undef      ERU_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (ERU_START_SEC_VAR_UNSPECIFIED)
   #undef      ERU_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (ERU_STOP_SEC_VAR_UNSPECIFIED)
   #undef      ERU_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (ERU_START_SEC_CONST_8BIT)
   #undef      ERU_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (ERU_STOP_SEC_CONST_8BIT)
   #undef      ERU_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (ERU_START_SEC_CONST_16BIT)
   #undef      ERU_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (ERU_STOP_SEC_CONST_16BIT)
   #undef      ERU_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (ERU_START_SEC_CONST_32BIT)
   #undef      ERU_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (ERU_STOP_SEC_CONST_32BIT)
   #undef      ERU_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (ERU_START_SEC_CONST_UNSPECIFIED)
   #undef      ERU_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (ERU_STOP_SEC_CONST_UNSPECIFIED)
   #undef      ERU_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 MSC                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (MSC_START_SEC_CODE)
   #undef      MSC_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (MSC_STOP_SEC_CODE)
   #undef      MSC_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (MSC_START_SEC_VAR_NOINIT_8BIT)
   #undef      MSC_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      MSC_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (MSC_START_SEC_VAR_NOINIT_16BIT)
   #undef      MSC_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      MSC_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (MSC_START_SEC_VAR_NOINIT_32BIT)
   #undef      MSC_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      MSC_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (MSC_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      MSC_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (MSC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      MSC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (MSC_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      MSC_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      MSC_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (MSC_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      MSC_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      MSC_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (MSC_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      MSC_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      MSC_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (MSC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      MSC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (MSC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      MSC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (MSC_START_SEC_VAR_FAST_8BIT)
   #undef      MSC_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_FAST_8BIT)
   #undef      MSC_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (MSC_START_SEC_VAR_FAST_16BIT)
   #undef      MSC_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_FAST_16BIT)
   #undef      MSC_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (MSC_START_SEC_VAR_FAST_32BIT)
   #undef      MSC_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_FAST_32BIT)
   #undef      MSC_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (MSC_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      MSC_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (MSC_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      MSC_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (MSC_START_SEC_VAR_8BIT)
   #undef      MSC_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_8BIT)
   #undef      MSC_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (MSC_START_SEC_VAR_16BIT)
   #undef      MSC_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_16BIT)
   #undef      MSC_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (MSC_START_SEC_VAR_32BIT)
   #undef      MSC_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (MSC_STOP_SEC_VAR_32BIT)
   #undef      MSC_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (MSC_START_SEC_VAR_UNSPECIFIED)
   #undef      MSC_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (MSC_STOP_SEC_VAR_UNSPECIFIED)
   #undef      MSC_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (MSC_START_SEC_CONST_8BIT)
   #undef      MSC_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (MSC_STOP_SEC_CONST_8BIT)
   #undef      MSC_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (MSC_START_SEC_CONST_16BIT)
   #undef      MSC_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (MSC_STOP_SEC_CONST_16BIT)
   #undef      MSC_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (MSC_START_SEC_CONST_32BIT)
   #undef      MSC_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (MSC_STOP_SEC_CONST_32BIT)
   #undef      MSC_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (MSC_START_SEC_CONST_UNSPECIFIED)
   #undef      MSC_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (MSC_STOP_SEC_CONST_UNSPECIFIED)
   #undef      MSC_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (MSC_START_SEC_POSTBUILDCFG)
   #undef      MSC_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (MSC_STOP_SEC_POSTBUILDCFG)
   #undef      MSC_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 LIN_17_ASCLIN                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (LIN_17_ASCLIN_START_SEC_CODE)
   #undef      LIN_17_ASCLIN_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_CODE)
   #undef      LIN_17_ASCLIN_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_NOINIT_8BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_NOINIT_16BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_NOINIT_32BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_FAST_8BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_FAST_8BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_FAST_16BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_FAST_16BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_FAST_32BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_FAST_32BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_8BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_8BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_16BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_16BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_32BIT)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_32BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_VAR_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_VAR_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_CONST_8BIT)
   #undef      LIN_17_ASCLIN_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_CONST_8BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_CONST_16BIT)
   #undef      LIN_17_ASCLIN_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_CONST_16BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_CONST_32BIT)
   #undef      LIN_17_ASCLIN_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_CONST_32BIT)
   #undef      LIN_17_ASCLIN_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_CONST_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_CONST_UNSPECIFIED)
   #undef      LIN_17_ASCLIN_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (LIN_17_ASCLIN_START_SEC_POSTBUILDCFG)
   #undef      LIN_17_ASCLIN_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (LIN_17_ASCLIN_STOP_SEC_POSTBUILDCFG)
   #undef      LIN_17_ASCLIN_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 UART                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (UART_START_SEC_CODE)
   #undef      UART_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (UART_STOP_SEC_CODE)
   #undef      UART_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (UART_START_SEC_VAR_NOINIT_8BIT)
   #undef      UART_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      UART_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (UART_START_SEC_VAR_NOINIT_16BIT)
   #undef      UART_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      UART_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (UART_START_SEC_VAR_NOINIT_32BIT)
   #undef      UART_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      UART_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (UART_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      UART_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (UART_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      UART_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (UART_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      UART_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      UART_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (UART_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      UART_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      UART_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (UART_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      UART_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      UART_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (UART_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      UART_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (UART_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      UART_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (UART_START_SEC_VAR_FAST_8BIT)
   #undef      UART_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_FAST_8BIT)
   #undef      UART_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (UART_START_SEC_VAR_FAST_16BIT)
   #undef      UART_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_FAST_16BIT)
   #undef      UART_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (UART_START_SEC_VAR_FAST_32BIT)
   #undef      UART_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_FAST_32BIT)
   #undef      UART_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (UART_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      UART_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (UART_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      UART_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (UART_START_SEC_VAR_8BIT)
   #undef      UART_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_8BIT)
   #undef      UART_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (UART_START_SEC_VAR_16BIT)
   #undef      UART_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_16BIT)
   #undef      UART_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (UART_START_SEC_VAR_32BIT)
   #undef      UART_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (UART_STOP_SEC_VAR_32BIT)
   #undef      UART_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (UART_START_SEC_VAR_UNSPECIFIED)
   #undef      UART_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (UART_STOP_SEC_VAR_UNSPECIFIED)
   #undef      UART_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (UART_START_SEC_CONST_8BIT)
   #undef      UART_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (UART_STOP_SEC_CONST_8BIT)
   #undef      UART_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (UART_START_SEC_CONST_16BIT)
   #undef      UART_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (UART_STOP_SEC_CONST_16BIT)
   #undef      UART_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (UART_START_SEC_CONST_32BIT)
   #undef      UART_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (UART_STOP_SEC_CONST_32BIT)
   #undef      UART_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (UART_START_SEC_CONST_UNSPECIFIED)
   #undef      UART_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (UART_STOP_SEC_CONST_UNSPECIFIED)
   #undef      UART_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (UART_START_SEC_POSTBUILDCFG)
   #undef      UART_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (UART_STOP_SEC_POSTBUILDCFG)
   #undef      UART_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 CANTRCV6251G                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (CANTRCV6251G_START_SEC_CODE)
   #undef      CANTRCV6251G_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_CODE)
   #undef      CANTRCV6251G_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_NOINIT_8BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_NOINIT_16BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_NOINIT_32BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CANTRCV6251G_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CANTRCV6251G_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CANTRCV6251G_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CANTRCV6251G_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_FAST_8BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_FAST_8BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_FAST_16BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_FAST_16BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_FAST_32BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_FAST_32BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CANTRCV6251G_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CANTRCV6251G_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_8BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_8BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_16BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_16BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_32BIT)
   #undef      CANTRCV6251G_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_32BIT)
   #undef      CANTRCV6251G_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_VAR_UNSPECIFIED)
   #undef      CANTRCV6251G_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_VAR_UNSPECIFIED)
   #undef      CANTRCV6251G_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (CANTRCV6251G_START_SEC_CONST_8BIT)
   #undef      CANTRCV6251G_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_CONST_8BIT)
   #undef      CANTRCV6251G_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_CONST_16BIT)
   #undef      CANTRCV6251G_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_CONST_16BIT)
   #undef      CANTRCV6251G_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_CONST_32BIT)
   #undef      CANTRCV6251G_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_CONST_32BIT)
   #undef      CANTRCV6251G_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (CANTRCV6251G_START_SEC_CONST_UNSPECIFIED)
   #undef      CANTRCV6251G_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (CANTRCV6251G_STOP_SEC_CONST_UNSPECIFIED)
   #undef      CANTRCV6251G_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 ETH_17_ETHMAC                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (ETH_17_ETHMAC_START_SEC_CODE)
   #undef      ETH_17_ETHMAC_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_CODE)
   #undef      ETH_17_ETHMAC_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_NOINIT_8BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_NOINIT_16BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_NOINIT_32BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_FAST_16BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_FAST_16BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_FAST_32BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_FAST_32BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_8BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_8BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_16BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_16BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_32BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_32BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_VAR_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_CONST_8BIT)
   #undef      ETH_17_ETHMAC_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_CONST_8BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_CONST_16BIT)
   #undef      ETH_17_ETHMAC_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_CONST_16BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_CONST_32BIT)
   #undef      ETH_17_ETHMAC_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_CONST_32BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_CONST_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_CONST_UNSPECIFIED)
   #undef      ETH_17_ETHMAC_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (ETH_17_ETHMAC_START_SEC_POSTBUILDCFG)
   #undef      ETH_17_ETHMAC_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (ETH_17_ETHMAC_STOP_SEC_POSTBUILDCFG)
   #undef      ETH_17_ETHMAC_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 CRC                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (CRC_START_SEC_POSTBUILDCFG)
   #undef      CRC_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (CRC_STOP_SEC_POSTBUILDCFG)
   #undef      CRC_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED


#elif defined (CRC_START_SEC_CODE)
   #undef      CRC_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (CRC_STOP_SEC_CODE)
   #undef      CRC_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (CRC_START_SEC_VAR_NOINIT_8BIT)
   #undef      CRC_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      CRC_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (CRC_START_SEC_VAR_NOINIT_16BIT)
   #undef      CRC_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      CRC_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (CRC_START_SEC_VAR_NOINIT_32BIT)
   #undef      CRC_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      CRC_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (CRC_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CRC_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (CRC_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      CRC_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (CRC_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CRC_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      CRC_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (CRC_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CRC_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      CRC_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (CRC_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CRC_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      CRC_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (CRC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CRC_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (CRC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      CRC_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (CRC_START_SEC_VAR_FAST_16BIT)
   #undef      CRC_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_FAST_16BIT)
   #undef      CRC_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (CRC_START_SEC_VAR_FAST1_32BIT)
   #undef      CRC_START_SEC_VAR_FAST1_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST1_32BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_FAST1_32BIT)
   #undef      CRC_STOP_SEC_VAR_FAST1_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST1_32BIT_SHARED


#elif defined (CRC_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CRC_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (CRC_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      CRC_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (CRC_START_SEC_VAR_8BIT)
   #undef      CRC_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_8BIT)
   #undef      CRC_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (CRC_START_SEC_VAR_16BIT)
   #undef      CRC_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_16BIT)
   #undef      CRC_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (CRC_START_SEC_VAR_32BIT)
   #undef      CRC_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (CRC_STOP_SEC_VAR_32BIT)
   #undef      CRC_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (CRC_START_SEC_VAR_UNSPECIFIED)
   #undef      CRC_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (CRC_STOP_SEC_VAR_UNSPECIFIED)
   #undef      CRC_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (CRC_START_SEC_CONST_8BIT)
   #undef      CRC_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (CRC_STOP_SEC_CONST_8BIT)
   #undef      CRC_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (CRC_START_SEC_CONST_16BIT)
   #undef      CRC_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (CRC_STOP_SEC_CONST_16BIT)
   #undef      CRC_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (CRC_START_SEC_CONST_32BIT)
   #undef      CRC_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (CRC_STOP_SEC_CONST_32BIT)
   #undef      CRC_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (CRC_START_SEC_CONST_UNSPECIFIED)
   #undef      CRC_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (CRC_STOP_SEC_CONST_UNSPECIFIED)
   #undef      CRC_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED

/*****************************************************************************
**                                 FR_17_ERAY                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (FR_17_ERAY_START_SEC_CODE)
   #undef      FR_17_ERAY_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_CODE)
   #undef      FR_17_ERAY_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_NOINIT_8BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_NOINIT_16BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_NOINIT_32BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FR_17_ERAY_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      FR_17_ERAY_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FR_17_ERAY_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      FR_17_ERAY_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_FAST_8BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_FAST_8BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_FAST_16BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_FAST_16BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_FAST_32BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_FAST_32BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FR_17_ERAY_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      FR_17_ERAY_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_8BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_8BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_16BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_16BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_32BIT)
   #undef      FR_17_ERAY_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_32BIT)
   #undef      FR_17_ERAY_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_VAR_UNSPECIFIED)
   #undef      FR_17_ERAY_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_VAR_UNSPECIFIED)
   #undef      FR_17_ERAY_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (FR_17_ERAY_START_SEC_CONST_8BIT)
   #undef      FR_17_ERAY_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_CONST_8BIT)
   #undef      FR_17_ERAY_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_CONST_16BIT)
   #undef      FR_17_ERAY_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_CONST_16BIT)
   #undef      FR_17_ERAY_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_CONST_32BIT)
   #undef      FR_17_ERAY_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_CONST_32BIT)
   #undef      FR_17_ERAY_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (FR_17_ERAY_START_SEC_CONST_UNSPECIFIED)
   #undef      FR_17_ERAY_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_CONST_UNSPECIFIED)
   #undef      FR_17_ERAY_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (FR_17_ERAY_START_SEC_POSTBUILDCFG)
   #undef      FR_17_ERAY_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (FR_17_ERAY_STOP_SEC_POSTBUILDCFG)
   #undef      FR_17_ERAY_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 STM                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (STM_START_SEC_CODE)
   #undef      STM_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (STM_STOP_SEC_CODE)
   #undef      STM_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (STM_START_SEC_VAR_NOINIT_8BIT)
   #undef      STM_START_SEC_VAR_NOINIT_8BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_NOINIT_8BIT)
   #undef      STM_STOP_SEC_VAR_NOINIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED


#elif defined (STM_START_SEC_VAR_NOINIT_16BIT)
   #undef      STM_START_SEC_VAR_NOINIT_16BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_NOINIT_16BIT)
   #undef      STM_STOP_SEC_VAR_NOINIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED


#elif defined (STM_START_SEC_VAR_NOINIT_32BIT)
   #undef      STM_START_SEC_VAR_NOINIT_32BIT
   #define   DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_NOINIT_32BIT)
   #undef      STM_STOP_SEC_VAR_NOINIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED


#elif defined (STM_START_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      STM_START_SEC_VAR_NOINIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
#elif defined (STM_STOP_SEC_VAR_NOINIT_UNSPECIFIED)
   #undef      STM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED


#elif defined (STM_START_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      STM_START_SEC_VAR_POWER_ON_INIT_8BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_POWER_ON_INIT_8BIT)
   #undef      STM_STOP_SEC_VAR_POWER_ON_INIT_8BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED


#elif defined (STM_START_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      STM_START_SEC_VAR_POWER_ON_INIT_16BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_POWER_ON_INIT_16BIT)
   #undef      STM_STOP_SEC_VAR_POWER_ON_INIT_16BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED


#elif defined (STM_START_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      STM_START_SEC_VAR_POWER_ON_INIT_32BIT
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_POWER_ON_INIT_32BIT)
   #undef      STM_STOP_SEC_VAR_POWER_ON_INIT_32BIT
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED


#elif defined (STM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      STM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
#elif defined (STM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
   #undef      STM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED


#elif defined (STM_START_SEC_VAR_FAST_8BIT)
   #undef      STM_START_SEC_VAR_FAST_8BIT
   #define   DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_FAST_8BIT)
   #undef      STM_STOP_SEC_VAR_FAST_8BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED


#elif defined (STM_START_SEC_VAR_FAST_16BIT)
   #undef      STM_START_SEC_VAR_FAST_16BIT
   #define   DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_FAST_16BIT)
   #undef      STM_STOP_SEC_VAR_FAST_16BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED


#elif defined (STM_START_SEC_VAR_FAST_32BIT)
   #undef      STM_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_FAST_32BIT)
   #undef      STM_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED


#elif defined (STM_START_SEC_VAR_FAST_UNSPECIFIED)
   #undef      STM_START_SEC_VAR_FAST_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
#elif defined (STM_STOP_SEC_VAR_FAST_UNSPECIFIED)
   #undef      STM_STOP_SEC_VAR_FAST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED


#elif defined (STM_START_SEC_VAR_8BIT)
   #undef      STM_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_8BIT)
   #undef      STM_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (STM_START_SEC_VAR_16BIT)
   #undef      STM_START_SEC_VAR_16BIT
   #define   DEFAULT_START_SEC_VAR_16BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_16BIT)
   #undef      STM_STOP_SEC_VAR_16BIT
   #define DEFAULT_STOP_SEC_VAR_16BIT_SHARED


#elif defined (STM_START_SEC_VAR_32BIT)
   #undef      STM_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (STM_STOP_SEC_VAR_32BIT)
   #undef      STM_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (STM_START_SEC_VAR_UNSPECIFIED)
   #undef      STM_START_SEC_VAR_UNSPECIFIED
   #define   DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
#elif defined (STM_STOP_SEC_VAR_UNSPECIFIED)
   #undef      STM_STOP_SEC_VAR_UNSPECIFIED
   #define DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED


#elif defined (STM_START_SEC_CONST_8BIT)
   #undef      STM_START_SEC_CONST_8BIT
   #define   DEFAULT_START_SEC_CONST_8BIT_SHARED
#elif defined (STM_STOP_SEC_CONST_8BIT)
   #undef      STM_STOP_SEC_CONST_8BIT
   #define DEFAULT_STOP_SEC_CONST_8BIT_SHARED


#elif defined (STM_START_SEC_CONST_16BIT)
   #undef      STM_START_SEC_CONST_16BIT
   #define   DEFAULT_START_SEC_CONST_16BIT_SHARED
#elif defined (STM_STOP_SEC_CONST_16BIT)
   #undef      STM_STOP_SEC_CONST_16BIT
   #define DEFAULT_STOP_SEC_CONST_16BIT_SHARED


#elif defined (STM_START_SEC_CONST_32BIT)
   #undef      STM_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (STM_STOP_SEC_CONST_32BIT)
   #undef      STM_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (STM_START_SEC_CONST_UNSPECIFIED)
   #undef      STM_START_SEC_CONST_UNSPECIFIED
   #define   DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
#elif defined (STM_STOP_SEC_CONST_UNSPECIFIED)
   #undef      STM_STOP_SEC_CONST_UNSPECIFIED
   #define DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED


#elif defined (STM_START_SEC_POSTBUILDCFG)
   #undef      STM_START_SEC_POSTBUILDCFG
   #define   DEFAULT_START_SEC_POSTBUILDCFG_SHARED
#elif defined (STM_STOP_SEC_POSTBUILDCFG)
   #undef      STM_STOP_SEC_POSTBUILDCFG
   #define DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 ECUM                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */

#elif defined (ECUM_START_SEC_CODE)
   #undef      ECUM_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (ECUM_STOP_SEC_CODE)
   #undef      ECUM_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED

#elif defined (ECUM_START_SEC_CONST_32BIT)
   #undef      ECUM_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (ECUM_STOP_SEC_CONST_32BIT)
   #undef      ECUM_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (ECUM_START_SEC_VAR_32BIT)
   #undef      ECUM_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (ECUM_STOP_SEC_VAR_32BIT)
   #undef      ECUM_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


#elif defined (ECUM_START_SEC_POSTBUILDCFG)
   #undef      ECUM_START_SEC_POSTBUILDCFG
   #define   ECUM_START_SEC_POSTBUILDCFG_SHARED
#elif defined (ECUM_STOP_SEC_POSTBUILDCFG)
   #undef      ECUM_STOP_SEC_POSTBUILDCFG
   #define ECUM_STOP_SEC_POSTBUILDCFG_SHARED

/*****************************************************************************
**                                 MCAL                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (MCAL_START_SEC_VAR_FAST_32BIT)
   #undef      MCAL_START_SEC_VAR_FAST_32BIT
   #define   DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#elif defined (MCAL_STOP_SEC_VAR_FAST_32BIT)
   #undef      MCAL_STOP_SEC_VAR_FAST_32BIT
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED

/*****************************************************************************
**                                 MCAL_TCLIB                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (MCAL_TCLIB_START_SEC_CODE)
   #undef      MCAL_TCLIB_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (MCAL_TCLIB_STOP_SEC_CODE)
   #undef      MCAL_TCLIB_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (MCAL_TCLIB_START_SEC_CONST_32BIT)
   #undef      MCAL_TCLIB_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (MCAL_TCLIB_STOP_SEC_CONST_32BIT)
   #undef      MCAL_TCLIB_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (MCAL_TCLIB_START_SEC_VAR_8BIT)
   #undef      MCAL_TCLIB_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (MCAL_TCLIB_STOP_SEC_VAR_8BIT)
   #undef      MCAL_TCLIB_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED

/*****************************************************************************
**                                 MCAL_WDGLIB                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (MCAL_WDGLIB_START_SEC_CODE)
   #undef      MCAL_WDGLIB_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (MCAL_WDGLIB_STOP_SEC_CODE)
   #undef      MCAL_WDGLIB_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (MCAL_WDGLIB_START_SEC_CONST_32BIT)
   #undef      MCAL_WDGLIB_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (MCAL_WDGLIB_STOP_SEC_CONST_32BIT)
   #undef      MCAL_WDGLIB_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (MCAL_WDGLIB_START_SEC_VAR_8BIT)
   #undef      MCAL_WDGLIB_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (MCAL_WDGLIB_STOP_SEC_VAR_8BIT)
   #undef      MCAL_WDGLIB_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (MCAL_WDGLIB_START_SEC_VAR_32BIT)
   #undef      MCAL_WDGLIB_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (MCAL_WDGLIB_STOP_SEC_VAR_32BIT)
   #undef      MCAL_WDGLIB_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED

/*****************************************************************************
**                                 MCAL_DMALIB                                      **
******************************************************************************/

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (MCAL_DMALIB_START_SEC_CODE)
   #undef      MCAL_DMALIB_START_SEC_CODE
   #define   DEFAULT_START_SEC_CODE_SHARED
#elif defined (MCAL_DMALIB_STOP_SEC_CODE)
   #undef      MCAL_DMALIB_STOP_SEC_CODE
   #define DEFAULT_STOP_SEC_CODE_SHARED


#elif defined (MCAL_DMALIB_START_SEC_CONST_32BIT)
   #undef      MCAL_DMALIB_START_SEC_CONST_32BIT
   #define   DEFAULT_START_SEC_CONST_32BIT_SHARED
#elif defined (MCAL_DMALIB_STOP_SEC_CONST_32BIT)
   #undef      MCAL_DMALIB_STOP_SEC_CONST_32BIT
   #define DEFAULT_STOP_SEC_CONST_32BIT_SHARED


#elif defined (MCAL_DMALIB_START_SEC_VAR_8BIT)
   #undef      MCAL_DMALIB_START_SEC_VAR_8BIT
   #define   DEFAULT_START_SEC_VAR_8BIT_SHARED
#elif defined (MCAL_DMALIB_STOP_SEC_VAR_8BIT)
   #undef      MCAL_DMALIB_STOP_SEC_VAR_8BIT
   #define DEFAULT_STOP_SEC_VAR_8BIT_SHARED


#elif defined (MCAL_DMALIB_START_SEC_VAR_32BIT)
   #undef      MCAL_DMALIB_START_SEC_VAR_32BIT
   #define   DEFAULT_START_SEC_VAR_32BIT_SHARED
#elif defined (MCAL_DMALIB_STOP_SEC_VAR_32BIT)
   #undef      MCAL_DMALIB_STOP_SEC_VAR_32BIT
   #define DEFAULT_STOP_SEC_VAR_32BIT_SHARED


/* -------------------------------------------------------------------------- */
/* End of module section mapping                                              */
/* -------------------------------------------------------------------------- */
#elif defined (IRQ_START_SEC_IVT_CODE)
   #undef      IRQ_START_SEC_IVT_CODE
   #define   DEFAULT_START_SEC_IVT_CODE
#elif defined (IRQ_STOP_SEC_IVT_CODE)
   #undef      IRQ_STOP_SEC_IVT_CODE
   #define DEFAULT_STOP_SEC_IVT_CODE

#elif defined (ADC_START_SEC_VAR_DMABUFFER)
   #undef      ADC_START_SEC_VAR_DMABUFFER
   #define ADC_DMA_START_SEC_EMUXSCAN_BUFFER
#elif defined (ADC_STOP_SEC_VAR_DMABUFFER)
   #undef      ADC_STOP_SEC_VAR_DMABUFFER
   #define ADC_DMA_STOP_SEC_EMUXSCAN_BUFFER

#elif defined (FEE_START_SEC_JOBENDNOTIF_CODE)
   #undef   FEE_START_SEC_JOBENDNOTIF_CODE
   #define FEE_START_JOBENDNOTIF
#elif defined (FEE_STOP_SEC_JOBENDNOTIF_CODE)
   #undef   FEE_STOP_SEC_JOBENDNOTIF_CODE
   #define FEE_STOP_JOBENDNOTIF

#elif defined (FEE_START_SEC_JOBERRNOTIF_CODE)
   #undef   FEE_START_SEC_JOBERRNOTIF_CODE
   #define FEE_START_JOBERRNOTIF
#elif defined (FEE_STOP_SEC_JOBERRNOTIF_CODE)
   #undef   FEE_STOP_SEC_JOBERRNOTIF_CODE
   #define FEE_STOP_JOBERRNOTIF

/* 
 * To be used for mapping FLS Write and Erase API's to user defined address 
 * external flash etc 
 */
#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN)
   #undef      FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN
   #define   FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN_API
#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN)
   #undef      FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN
   #define   FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN_API

#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_END)
   #undef      FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_END
   #define   FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_END_API
#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_END)
   #undef      FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_END
   #define   FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_END_API

#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN)
   #undef      FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN
   #define   FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN_API
#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN)
   #undef      FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN
   #define   FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN_API

#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_END)
   #undef      FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_END
   #define   FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_END_API
#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_END)
   #undef      FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_END
   #define   FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_END_API

#elif defined (FLS_17_PMU_START_SEC_SPL_VAR_32BIT)
   #undef      FLS_17_PMU_START_SEC_SPL_VAR_32BIT
   #define FLS_17_PMU_START_CONFIG
#elif defined (FLS_17_PMU_STOP_SEC_SPL_VAR_32BIT)
   #undef      FLS_17_PMU_STOP_SEC_SPL_VAR_32BIT
   #define FLS_17_PMU_STOP_CONFIG


/*
 * To be used for all global or static variables (8 bits )
 * that have atleast one of  the following properties
 * 1. accessed bitwise  2. frequently used
 * 3. high number of accesses in source code
 */ 
#elif defined (ETH_17_ETHMAC_START_SEC_VAR_FAST_8BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_FAST_8BIT
   #define ETH_17_ETHMAC_RES_START_SEC_VAR_FAST_8BIT
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_FAST_8BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_FAST_8BIT
   #define ETH_17_ETHMAC_RES_STOP_SEC_VAR_FAST_8BIT

/*
 * To be used for all global or static variables (32 bits )
 * that have atleast one of  the following properties
 * 1. accessed bitwise  2. frequently used
 * 3. high number of accesses in source code
 */ 
#elif defined (ETH_17_ETHMAC_START_SEC_VAR_FAST_32BIT)
   #undef      ETH_17_ETHMAC_START_SEC_VAR_FAST_32BIT
   #define ETH_17_ETHMAC_RES_START_SEC_VAR_FAST_32BIT
#elif defined (ETH_17_ETHMAC_STOP_SEC_VAR_FAST_32BIT)
   #undef      ETH_17_ETHMAC_STOP_SEC_VAR_FAST_32BIT
   #define ETH_17_ETHMAC_RES_STOP_SEC_VAR_FAST_32BIT

/*
 * To be used for all global or static variables (32 bits )
 * that have atleast one of  the following properties
 * 1. accessed bitwise  2. frequently used
 * 3. high number of accesses in source code
 */ 
#elif defined (CRC_START_SEC_VAR_FAST_32BIT)
   #undef      CRC_START_SEC_VAR_FAST_32BIT
   #define CRC_RES_START_SEC_VAR_FAST_32BIT
#elif defined (CRC_STOP_SEC_VAR_FAST_32BIT)
   #undef      CRC_STOP_SEC_VAR_FAST_32BIT
   #define CRC_RES_STOP_SEC_VAR_FAST_32BIT

/*
Fls_Write API : Section
*/
#elif defined (FLSLOADER_START_SEC_WRITE_CODE)
   #undef      FLSLOADER_START_SEC_WRITE_CODE
   #define     FLSLOADER_START_WRITE_API
#elif defined (FLSLOADER_STOP_SEC_WRITE_CODE)
   #undef      FLSLOADER_STOP_SEC_WRITE_CODE
   #define     FLSLOADER_STOP_WRITE_API
/*
Fls Erase API : Section
*/
#elif defined (FLSLOADER_START_SEC_ERASE_CODE)
   #undef      FLSLOADER_START_SEC_ERASE_CODE
   #define     FLSLOADER_START_ERASE_API
#elif defined (FLSLOADER_STOP_SEC_ERASE_CODE)
   #undef      FLSLOADER_STOP_SEC_ERASE_CODE
   #define     FLSLOADER_STOP_ERASE_API


/* -------------------------------------------------------------------------- */
/* End of module section mapping                                              */
/* -------------------------------------------------------------------------- */

   #elif defined (PWM_17_GTM_START_SEC_CALLOUT_CODE)
      #undef      PWM_17_GTM_START_SEC_CALLOUT_CODE
      #define PWM_17_GTM_START_SEC_NOTIFICATION
   #elif defined (PWM_17_GTM_STOP_SEC_CALLOUT_CODE)
      #undef      PWM_17_GTM_STOP_SEC_CALLOUT_CODE
      #define   PWM_17_GTM_STOP_SEC_NOTIFICATION   

   #elif defined (ICU_17_GTMCCU6_START_SEC_CALLOUT_CODE)
      #undef      ICU_17_GTMCCU6_START_SEC_CALLOUT_CODE
      #define ICU_17_GTMCCU6_START_SEC_NOTIFICATION
   #elif defined (ICU_17_GTMCCU6_STOP_SEC_CALLOUT_CODE)
      #undef      ICU_17_GTMCCU6_STOP_SEC_CALLOUT_CODE
      #define   ICU_17_GTMCCU6_STOP_SEC_NOTIFICATION  
   
   #elif defined (WDG_17_SCU_START_SEC_CALLOUT_CODE)
      #undef      WDG_17_SCU_START_SEC_CALLOUT_CODE
      #define WDG_17_SCU_START_SEC_NOTIFICATION
   #elif defined (WDG_17_SCU_STOP_SEC_CALLOUT_CODE)
      #undef      WDG_17_SCU_STOP_SEC_CALLOUT_CODE
      #define   WDG_17_SCU_STOP_SEC_NOTIFICATION  
   
   #elif defined (STM_START_SEC_CALLOUT_CODE)
      #undef      STM_START_SEC_CALLOUT_CODE
      #define STM_START_SEC_NOTIFICATION
   #elif defined (STM_STOP_SEC_CALLOUT_CODE)
      #undef      STM_STOP_SEC_CALLOUT_CODE
      #define   STM_STOP_SEC_NOTIFICATION    
   
   #elif defined (GPT_START_SEC_CALLOUT_CODE)
      #undef      GPT_START_SEC_CALLOUT_CODE
      #define GPT_START_SEC_NOTIFICATION
   #elif defined (GPT_STOP_SEC_CALLOUT_CODE)
      #undef      GPT_STOP_SEC_CALLOUT_CODE
      #define   GPT_STOP_SEC_NOTIFICATION   


   #elif defined (LIN_17_ASCLIN_START_CHCFG)
      #undef      LIN_17_ASCLIN_START_CHCFG
      #define LIN_17_ASCLIN_START_LOADABLECFG
   #elif defined (LIN_17_ASCLIN_STOP_CHCFG)
      #undef      LIN_17_ASCLIN_STOP_CHCFG
   #define   LIN_17_ASCLIN_STOP_LOADABLECFG        



/* -------------------------------------------------------------------------- */
/* End of module Notification function section mapping                        */
/* -------------------------------------------------------------------------- */
/* The Source and Destination pointers passed to the SPI are 
   handled by the DMA in the asynchronous mode. It is necesarry 
   that these variables fullfill the following addressing constarints.
   1. In case of transfer width > 8, the data type is 16bits. Therefore
      it is necesarry to have the source and destination pointers
      word aligned. (On a Even Boundary). Use of #pragma align 2 will
      ensure word alignment.
   2. DMA implements a Circular Buffer with a maximum width of 32KB.
      So the Src/Des Ptrs (Starting Address + Length Of data) should not 
      span the 32KB Boundary if Sequential data are to be transferred.
      The start address of this section must be selected so that the 
      variables donot exceed the 32KB boundary.
      [(DMA_Address & 0x00007FFFU) + Length <= 0x00008000U] 
      
   So it has to be ensured that the section "SPI_START_SEC_VAR_DMA_ACCESS" 
   fullfills the above stated criteria*/
#elif defined (SPI_START_SEC_VAR_DMA_ACCESS)
   #undef      SPI_START_SEC_VAR_DMA_ACCESS
#ifdef _DIABDATA_C_TRICORE_
   #define SPI_START_SEC_VAR_FAST_32BIT
#else
/* In the Demo App supplied with AUTOSAR_MCAL2,
   the section:DEFAULT_START_SEC_VAR_FAST_32BIT is sufficient to satisfy the
   memory requirements for DMA. This may not be true for other applications and 
   the user should ensure this. */ 
   #define DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
#endif   
#elif defined (SPI_STOP_SEC_VAR_DMA_ACCESS)
   #undef      SPI_STOP_SEC_VAR_DMA_ACCESS
#ifdef _DIABDATA_C_TRICORE_
   #define SPI_STOP_SEC_VAR_FAST_32BIT
#else
/* In the Demo App supplied with AUTOSAR_MCAL2,
   the section:DEFAULT_START_SEC_VAR_FAST_32BIT is sufficient to satisfy the
   memory requirements for DMA. This may not be true for other applications and 
   the user should ensure this. */ 
   #define DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED
#endif 


/* The Source and Destination pointers passed to the SPI are 
   handled by the DMA in the asynchronous mode. It is necesarry 
   that these variables fullfill the following addressing constarints.
   1. In case of transfer width > 8, the data type is 16bits. Therefore
      it is necesarry to have the source and destination pointers
      word aligned. (On a Even Boundary). Use of #pragma align 2 will
      ensure word alignment.
   2. DMA implements a Circular Buffer with a maximum width of 32KB.
      So the Src/Des Ptrs (Starting Address + Length Of data) should not 
      span the 32KB Boundary if Sequential data are to be transferred.
      The start address of this section must be selected so that the 
      variables donot exceed the 32KB boundary.
      [(DMA_Address & 0x00007FFFU) + Length <= 0x00008000U] 
      
   So it has to be ensured that the section "DMA_START_SEC_VAR_DMA_ACCESS" 
   fullfills the above stated criteria*/
#elif defined (DMA_START_SEC_VAR_DMA_ACCESS)
   #undef      DMA_START_SEC_VAR_DMA_ACCESS
/* In the Demo App supplied with AUTOSAR_MCAL2,
   the section:DEFAULT_START_SEC_VAR_FAST_16BIT is sufficient to satisfy the
   memory requirements for DMA. This may not be true for other applications and 
   the user should ensure this. */ 
   #define DEFAULT_START_SEC_VAR_FAST_16BIT
#elif defined (DMA_STOP_SEC_VAR_DMA_ACCESS)
   #undef      DMA_STOP_SEC_VAR_DMA_ACCESS
   #define DEFAULT_STOP_SEC_VAR_FAST_16BIT

/* 
 * To be used for mapping code to application block, boot block, 
 * external flash etc 
 */
#elif defined (FLS_17_PMU_START_SPL_SEC_CODE_CMDWRITE)
   #undef      FLS_17_PMU_START_SPL_SEC_CODE_CMDWRITE
   #define   DEFAULT_START_SEC_CODE 
#elif defined (FLS_17_PMU_STOP_SPL_SEC_CODE_CMDWRITE)
   #undef      FLS_17_PMU_STOP_SPL_SEC_CODE_CMDWRITE
   #define DEFAULT_STOP_SEC_CODE

/*
 * To be used for global or static vars alignnment to 16 bit boundary
 *
 */
#elif defined (FLS_17_PMU_START_VAR_ALIGN_16_BIT)
   #undef      FLS_17_PMU_START_VAR_ALIGN_16_BIT
   #define DEFAULT_START_VAR_ALIGN_16_BIT
#elif defined (FLS_17_PMU_STOP_VAR_ALIGN_16_BIT)
   #undef      FLS_17_PMU_STOP_VAR_ALIGN_16_BIT
   #define DEFAULT_STOP_VAR_ALIGN_16_BIT

/*
 * To be used for global or static vars alignnment to 16 bit boundary
 *
 */
#elif defined (FEE_START_VAR_ALIGN_16_BIT)
   #undef      FEE_START_VAR_ALIGN_16_BIT
   #define DEFAULT_START_VAR_ALIGN_16_BIT
#elif defined (FEE_STOP_VAR_ALIGN_16_BIT)
   #undef      FEE_STOP_VAR_ALIGN_16_BIT
   #define DEFAULT_STOP_VAR_ALIGN_16_BIT

/*
 * To be used for global or static vars packing 
 *
 */
#elif defined (FEE_START_VAR_PACK_2)
   #undef      FEE_START_VAR_PACK_2
   #define DEFAULT_START_VAR_PACK_2
#elif defined (FEE_STOP_VAR_PACK_2)
   #undef      FEE_STOP_VAR_PACK_2
   #define DEFAULT_STOP_VAR_PACK_2



   #elif defined (BMD_HDR_START_SEC_CONST_UNSPECIFIED)
   #undef      BMD_HDR_START_SEC_CONST_UNSPECIFIED
   #define BMD_HDR_START_SEC_BMI_HEADER
   #elif defined (BMD_HDR_STOP_SEC_CONST_UNSPECIFIED)
   #undef      BMD_HDR_STOP_SEC_CONST_UNSPECIFIED
   #define   BMD_HDR_STOP_SEC_BMI_HEADER        
#else
  //#error "MemMap.h: No valid section define found"
#endif  /* START_WITH_IF */
/*******************************************************************************
**                      Default section mapping                               **
*******************************************************************************/
/* general start of #elif chain whith #if                                     */
#if defined (START_WITH_IF)

/*****************************************************************************
**                                 ROM CONFIG DATA                          **
******************************************************************************/
/* 
Memory Section of Post Build Configuration 
*/

#elif defined (DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU0.Private.CONFIGURATION_PB"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU0.Private.CONFIGURATION_PB" a 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU0.Private.CONFIGURATION_PB" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_POSTBUILDCFG_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_POSTBUILDCFG_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU1.Private.CONFIGURATION_PB"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU1.Private.CONFIGURATION_PB" a 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU1.Private.CONFIGURATION_PB" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_POSTBUILDCFG_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_POSTBUILDCFG_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU2.Private.CONFIGURATION_PB"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU2.Private.CONFIGURATION_PB" a 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU2.Private.CONFIGURATION_PB" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_POSTBUILDCFG_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_POSTBUILDCFG_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_POSTBUILDCFG_SHARED)
   #undef      DEFAULT_START_SEC_POSTBUILDCFG_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="Shared.CONFIGURATION_PB"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.Shared.CONFIGURATION_PB" a 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.Shared.CONFIGURATION_PB" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED)
   #undef      DEFAULT_STOP_SEC_POSTBUILDCFG_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (ECUM_START_SEC_POSTBUILDCFG_CORE0_PRIVATE)
   #undef      ECUM_START_SEC_POSTBUILDCFG_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU0.Private.CONFIGURATION_ECUM_PB"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU0.Private.CONFIGURATION_ECUM_PB" a 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU0.Private.CONFIGURATION_ECUM_PB" far-absolute R
   #endif
#elif defined (ECUM_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE)
   #undef      ECUM_STOP_SEC_POSTBUILDCFG_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (ECUM_START_SEC_POSTBUILDCFG_CORE1_PRIVATE)
   #undef      ECUM_START_SEC_POSTBUILDCFG_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU1.Private.CONFIGURATION_ECUM_PB"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU1.Private.CONFIGURATION_ECUM_PB" a 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU1.Private.CONFIGURATION_ECUM_PB" far-absolute R
   #endif
#elif defined (ECUM_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE)
   #undef      ECUM_STOP_SEC_POSTBUILDCFG_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (ECUM_START_SEC_POSTBUILDCFG_CORE2_PRIVATE)
   #undef      ECUM_START_SEC_POSTBUILDCFG_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU2.Private.CONFIGURATION_ECUM_PB"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU2.Private.CONFIGURATION_ECUM_PB" a 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU2.Private.CONFIGURATION_ECUM_PB" far-absolute R
   #endif
#elif defined (ECUM_STOP_SEC_POSTBUILDCFG_CORE2_PRIVATE)
   #undef      ECUM_STOP_SEC_POSTBUILDCFG_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (ECUM_START_SEC_POSTBUILDCFG_SHARED)
   #undef      ECUM_START_SEC_POSTBUILDCFG_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="Shared.CONFIGURATION_ECUM_PB"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.Shared.CONFIGURATION_ECUM_PB" a 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.Shared.CONFIGURATION_ECUM_PB" far-absolute R
   #endif
#elif defined (ECUM_STOP_SEC_POSTBUILDCFG_SHARED)
   #undef      ECUM_STOP_SEC_POSTBUILDCFG_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code="CPU0.Private.DEFAULT_CODE_ROM"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.CPU0.Private.DEFAULT_CODE_ROM" ax 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.CPU0.Private.DEFAULT_CODE_ROM" RX
   #endif
#elif defined (DEFAULT_STOP_SEC_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif


#elif defined (DEFAULT_START_SEC_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code="CPU1.Private.DEFAULT_CODE_ROM"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.CPU1.Private.DEFAULT_CODE_ROM" ax 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.CPU1.Private.DEFAULT_CODE_ROM" RX
   #endif
#elif defined (DEFAULT_STOP_SEC_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif


#elif defined (DEFAULT_START_SEC_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code="CPU2.Private.DEFAULT_CODE_ROM"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.CPU2.Private.DEFAULT_CODE_ROM" ax 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.CPU2.Private.DEFAULT_CODE_ROM" RX
   #endif
#elif defined (DEFAULT_STOP_SEC_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif


#elif defined (DEFAULT_START_SEC_CODE_SHARED)
   #undef      DEFAULT_START_SEC_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section code="Shared.DEFAULT_CODE_ROM"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.Shared.DEFAULT_CODE_ROM" ax 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.Shared.DEFAULT_CODE_ROM" RX
   #endif
#elif defined (DEFAULT_STOP_SEC_CODE_SHARED)
   #undef      DEFAULT_STOP_SEC_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif

#elif defined (DEFAULT_START_SEC_SAFETY_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_SAFETY_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code="CPU0.Private.DEFAULT_SAFETY_CODE_ROM"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.CPU0.Private.DEFAULT_SAFETY_CODE_ROM" ax 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.CPU0.Private.DEFAULT_SAFETY_CODE_ROM" RX
   #endif
#elif defined (DEFAULT_STOP_SEC_SAFETY_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SAFETY_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif


#elif defined (DEFAULT_START_SEC_SAFETY_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_SAFETY_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code="CPU1.Private.DEFAULT_SAFETY_CODE_ROM"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.CPU1.Private.DEFAULT_SAFETY_CODE_ROM" ax 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.CPU1.Private.DEFAULT_SAFETY_CODE_ROM" RX
   #endif
#elif defined (DEFAULT_STOP_SEC_SAFETY_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SAFETY_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif


#elif defined (DEFAULT_START_SEC_SAFETY_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_SAFETY_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code="CPU2.Private.DEFAULT_SAFETY_CODE_ROM"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.CPU2.Private.DEFAULT_SAFETY_CODE_ROM" ax 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.CPU2.Private.DEFAULT_SAFETY_CODE_ROM" RX
   #endif
#elif defined (DEFAULT_STOP_SEC_SAFETY_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_SAFETY_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif


#elif defined (DEFAULT_START_SEC_SAFETY_CODE_SHARED)
   #undef      DEFAULT_START_SEC_SAFETY_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section code="Shared.DEFAULT_SAFETY_CODE_ROM"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.Shared.DEFAULT_SAFETY_CODE_ROM" ax 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.Shared.DEFAULT_SAFETY_CODE_ROM" RX
   #endif
#elif defined (DEFAULT_STOP_SEC_SAFETY_CODE_SHARED)
   #undef      DEFAULT_STOP_SEC_SAFETY_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif


#elif defined (DEFAULT_START_SEC_QM_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_QM_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code="CPU0.Private.DEFAULT_QM_CODE_ROM"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.CPU0.Private.DEFAULT_QM_CODE_ROM" ax 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.CPU0.Private.DEFAULT_QM_CODE_ROM" RX
   #endif
#elif defined (DEFAULT_STOP_SEC_QM_CODE_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_QM_CODE_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif


#elif defined (DEFAULT_START_SEC_QM_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_QM_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code="CPU1.Private.DEFAULT_QM_CODE_ROM"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.CPU1.Private.DEFAULT_QM_CODE_ROM" ax 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.CPU1.Private.DEFAULT_QM_CODE_ROM" RX
   #endif
#elif defined (DEFAULT_STOP_SEC_QM_CODE_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_QM_CODE_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif


#elif defined (DEFAULT_START_SEC_QM_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_QM_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code="CPU2.Private.DEFAULT_QM_CODE_ROM"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.CPU2.Private.DEFAULT_QM_CODE_ROM" ax 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.CPU2.Private.DEFAULT_QM_CODE_ROM" RX
   #endif
#elif defined (DEFAULT_STOP_SEC_QM_CODE_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_QM_CODE_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif


#elif defined (DEFAULT_START_SEC_QM_CODE_SHARED)
   #undef      DEFAULT_START_SEC_QM_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section code="Shared.DEFAULT_QM_CODE_ROM"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.Shared.DEFAULT_QM_CODE_ROM" ax 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.Shared.DEFAULT_QM_CODE_ROM" RX
   #endif
#elif defined (DEFAULT_STOP_SEC_QM_CODE_SHARED)
   #undef      DEFAULT_STOP_SEC_QM_CODE_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_8BIT"
      #pragma noclear
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_8BIT" aw 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_8BIT" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="CPU1.Private.DEFAULT_RAM_NOINIT_8BIT"
      #pragma noclear
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_8BIT" aw 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_NOINIT_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_8BIT" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="CPU2.Private.DEFAULT_RAM_NOINIT_8BIT"
      #pragma noclear
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_8BIT" aw 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_NOINIT_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_8BIT" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="Shared.DEFAULT_RAM_NOINIT_8BIT"
      #pragma noclear
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.Shared.DEFAULT_RAM_NOINIT_8BIT" aw 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.Shared.DEFAULT_RAM_NOINIT_8BIT" ".bss.Shared.DEFAULT_RAM_NOINIT_8BIT" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_16BIT"
      #pragma noclear
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_16BIT" aw 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_16BIT" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_16BIT" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="CPU1.Private.DEFAULT_RAM_NOINIT_16BIT"
      #pragma noclear
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_16BIT" aw 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_NOINIT_16BIT" ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_16BIT" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="CPU2.Private.DEFAULT_RAM_NOINIT_16BIT"
      #pragma noclear
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_16BIT" aw 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_NOINIT_16BIT" ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_16BIT" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="Shared.DEFAULT_RAM_NOINIT_16BIT"
      #pragma noclear
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.Shared.DEFAULT_RAM_NOINIT_16BIT" aw 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.Shared.DEFAULT_RAM_NOINIT_16BIT" ".bss.Shared.DEFAULT_RAM_NOINIT_16BIT" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_32BIT"
      #pragma noclear
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_32BIT" aw 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_32BIT" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="CPU1.Private.DEFAULT_RAM_NOINIT_32BIT"
      #pragma noclear
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_32BIT" aw 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_NOINIT_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_32BIT" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="CPU2.Private.DEFAULT_RAM_NOINIT_32BIT"
      #pragma noclear
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_32BIT" aw 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_NOINIT_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_32BIT" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="Shared.DEFAULT_RAM_NOINIT_32BIT"
      #pragma noclear
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.Shared.DEFAULT_RAM_NOINIT_32BIT" aw 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.Shared.DEFAULT_RAM_NOINIT_32BIT" ".bss.Shared.DEFAULT_RAM_NOINIT_32BIT" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED"
      #pragma noclear
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" aw 
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="CPU1.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED"
      #pragma noclear
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" aw 
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" ".bss.CPU1.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="CPU2.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED"
      #pragma noclear
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" aw 
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" ".bss.CPU2.Private.DEFAULT_RAM_NOINIT_UNSPECIFIED" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farnoclear="Shared.DEFAULT_RAM_NOINIT_UNSPECIFIED"
      #pragma noclear
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.Shared.DEFAULT_RAM_NOINIT_UNSPECIFIED" aw 
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.Shared.DEFAULT_RAM_NOINIT_UNSPECIFIED" ".bss.Shared.DEFAULT_RAM_NOINIT_UNSPECIFIED" RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_NOINIT_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma clear
      #pragma section farnoclear restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU0.Private.DEFAULT_RAM_8BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU0.Private.DEFAULT_RAM_8BIT" aw 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU1.Private.DEFAULT_RAM_8BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU1.Private.DEFAULT_RAM_8BIT" aw 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU2.Private.DEFAULT_RAM_8BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU2.Private.DEFAULT_RAM_8BIT" aw 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="Shared.DEFAULT_RAM_8BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.Shared.DEFAULT_RAM_8BIT" aw 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.Shared.DEFAULT_RAM_8BIT" ".bss.Shared.DEFAULT_RAM_8BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU0.Private.DEFAULT_RAM_16BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU0.Private.DEFAULT_RAM_16BIT" aw 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_16BIT" ".bss.CPU0.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU1.Private.DEFAULT_RAM_16BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU1.Private.DEFAULT_RAM_16BIT" aw 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_16BIT" ".bss.CPU1.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU2.Private.DEFAULT_RAM_16BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU2.Private.DEFAULT_RAM_16BIT" aw 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_16BIT" ".bss.CPU2.Private.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="Shared.DEFAULT_RAM_16BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".data.Shared.DEFAULT_RAM_16BIT" aw 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.Shared.DEFAULT_RAM_16BIT" ".bss.Shared.DEFAULT_RAM_16BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU0.Private.DEFAULT_RAM_32BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU0.Private.DEFAULT_RAM_32BIT" aw 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU1.Private.DEFAULT_RAM_32BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU1.Private.DEFAULT_RAM_32BIT" aw 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU2.Private.DEFAULT_RAM_32BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU2.Private.DEFAULT_RAM_32BIT" aw 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="Shared.DEFAULT_RAM_32BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".data.Shared.DEFAULT_RAM_32BIT" aw 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.Shared.DEFAULT_RAM_32BIT" ".bss.Shared.DEFAULT_RAM_32BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU0.Private.DEFAULT_RAM_UNSPECIFIED"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" aw 
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU1.Private.DEFAULT_RAM_UNSPECIFIED"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU1.Private.DEFAULT_RAM_UNSPECIFIED" aw 
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_UNSPECIFIED" ".bss.CPU1.Private.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU2.Private.DEFAULT_RAM_UNSPECIFIED"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU2.Private.DEFAULT_RAM_UNSPECIFIED" aw 
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_UNSPECIFIED" ".bss.CPU2.Private.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_VAR_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="Shared.DEFAULT_RAM_UNSPECIFIED"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.Shared.DEFAULT_RAM_UNSPECIFIED" aw 
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.Shared.DEFAULT_RAM_UNSPECIFIED" ".bss.Shared.DEFAULT_RAM_UNSPECIFIED" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_8BIT"
      #pragma for_uninitialized_data_use_memory near
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_8BIT" awB 1
   #else
      #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_8BIT" awBz 1
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_8BIT" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_8BIT" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="CPU1.Private.DEFAULT_RAM_FAST_8BIT"
      #pragma for_uninitialized_data_use_memory near
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_8BIT" awB 1
   #else
      #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_8BIT" awBz 1
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.CPU1.Private.DEFAULT_RAM_FAST_8BIT" ".zbss.CPU1.Private.DEFAULT_RAM_FAST_8BIT" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="CPU2.Private.DEFAULT_RAM_FAST_8BIT"
      #pragma for_uninitialized_data_use_memory near
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_8BIT" awB 1
   #else
      #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_8BIT" awBz 1
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.CPU2.Private.DEFAULT_RAM_FAST_8BIT" ".zbss.CPU2.Private.DEFAULT_RAM_FAST_8BIT" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_FAST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="Shared.DEFAULT_RAM_FAST_8BIT"
      #pragma for_uninitialized_data_use_memory near
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_8BIT" awB 1
   #else
      #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_8BIT" awBz 1
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.Shared.DEFAULT_RAM_FAST_8BIT" ".zbss.Shared.DEFAULT_RAM_FAST_8BIT" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_16BIT"
      #pragma for_uninitialized_data_use_memory near
      #pragma align 4
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_16BIT" awB 2
   #else
      #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_16BIT" awBz 2
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_16BIT" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_16BIT" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="CPU1.Private.DEFAULT_RAM_FAST_16BIT"
      #pragma for_uninitialized_data_use_memory near
      #pragma align 4
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_16BIT" awB 2
   #else
      #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_16BIT" awBz 2
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.CPU1.Private.DEFAULT_RAM_FAST_16BIT" ".zbss.CPU1.Private.DEFAULT_RAM_FAST_16BIT" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="CPU2.Private.DEFAULT_RAM_FAST_16BIT"
      #pragma for_uninitialized_data_use_memory near
      #pragma align 4
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_16BIT" awB 2
   #else
      #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_16BIT" awBz 2
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.CPU2.Private.DEFAULT_RAM_FAST_16BIT" ".zbss.CPU2.Private.DEFAULT_RAM_FAST_16BIT" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_FAST_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="Shared.DEFAULT_RAM_FAST_16BIT"
      #pragma for_uninitialized_data_use_memory near
      #pragma align 4
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_16BIT" awB 2
   #else
      #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_16BIT" awBz 2
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.Shared.DEFAULT_RAM_FAST_16BIT" ".zbss.Shared.DEFAULT_RAM_FAST_16BIT" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_32BIT"
      #pragma for_uninitialized_data_use_memory near
      #pragma align 4
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_32BIT" awB 4
   #else
      #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_32BIT" awBz 4
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_32BIT" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_32BIT" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="CPU1.Private.DEFAULT_RAM_FAST_32BIT"
      #pragma for_uninitialized_data_use_memory near
      #pragma align 4
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_32BIT" awB 4
   #else
      #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_32BIT" awBz 4
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.CPU1.Private.DEFAULT_RAM_FAST_32BIT" ".zbss.CPU1.Private.DEFAULT_RAM_FAST_32BIT" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="CPU2.Private.DEFAULT_RAM_FAST_32BIT"
      #pragma for_uninitialized_data_use_memory near
      #pragma align 4
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_32BIT" awB 4
   #else
      #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_32BIT" awBz 4
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.CPU2.Private.DEFAULT_RAM_FAST_32BIT" ".zbss.CPU2.Private.DEFAULT_RAM_FAST_32BIT" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_FAST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="Shared.DEFAULT_RAM_FAST_32BIT"
      #pragma for_uninitialized_data_use_memory near
      #pragma align 4
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_32BIT" awB 4
   #else
      #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_32BIT" awB 4 /* 2014.06.16 MARTELLA: I had to remove the 'z' attribute, otherwise the compilation failed */
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.Shared.DEFAULT_RAM_FAST_32BIT" ".zbss.Shared.DEFAULT_RAM_FAST_32BIT" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED"
      #pragma for_uninitialized_data_use_memory near
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED" awB 
   #else
      #pragma section ".zbss.CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED" awBz 
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED" ".zbss.CPU0.Private.DEFAULT_RAM_FAST_UNSPECIFIED" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="CPU1.Private.DEFAULT_RAM_FAST_UNSPECIFIED"
      #pragma for_uninitialized_data_use_memory near
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_UNSPECIFIED" awB 
   #else
      #pragma section ".zbss.CPU1.Private.DEFAULT_RAM_FAST_UNSPECIFIED" awBz 
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.CPU1.Private.DEFAULT_RAM_FAST_UNSPECIFIED" ".zbss.CPU1.Private.DEFAULT_RAM_FAST_UNSPECIFIED" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="CPU2.Private.DEFAULT_RAM_FAST_UNSPECIFIED"
      #pragma for_uninitialized_data_use_memory near
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_UNSPECIFIED" awB 
   #else
      #pragma section ".zbss.CPU2.Private.DEFAULT_RAM_FAST_UNSPECIFIED" awBz 
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.CPU2.Private.DEFAULT_RAM_FAST_UNSPECIFIED" ".zbss.CPU2.Private.DEFAULT_RAM_FAST_UNSPECIFIED" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_VAR_FAST_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="Shared.DEFAULT_RAM_FAST_UNSPECIFIED"
      #pragma for_uninitialized_data_use_memory near
   #elif _GNU_C_TRICORE_
   #ifdef _NO_OPT_
      #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_UNSPECIFIED" awB 
   #else
      #pragma section ".zbss.Shared.DEFAULT_RAM_FAST_UNSPECIFIED" awBz 
   #endif
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".zdata.Shared.DEFAULT_RAM_FAST_UNSPECIFIED" ".zbss.Shared.DEFAULT_RAM_FAST_UNSPECIFIED" near-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_FAST_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" aw 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" aw 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" ".bss.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" aw 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" ".bss.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_8BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="Shared.DEFAULT_RAM_POWER_ON_INIT_8BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_8BIT" aw 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_8BIT" ".bss.Shared.DEFAULT_RAM_POWER_ON_INIT_8BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" aw 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" aw 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" ".bss.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" aw 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" ".bss.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_16BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="Shared.DEFAULT_RAM_POWER_ON_INIT_16BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_16BIT" aw 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_16BIT" ".bss.Shared.DEFAULT_RAM_POWER_ON_INIT_16BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" aw 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" aw 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" ".bss.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" aw 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" ".bss.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_32BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="Shared.DEFAULT_RAM_POWER_ON_INIT_32BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_32BIT" aw 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_32BIT" ".bss.Shared.DEFAULT_RAM_POWER_ON_INIT_32BIT" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" aw 
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" ".bss.CPU0.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" aw 
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" ".bss.CPU1.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" aw 
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" ".bss.CPU2.Private.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="Shared.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED"
   #elif _GNU_C_TRICORE_
      #pragma section ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" aw 
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".data.Shared.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" ".bss.Shared.DEFAULT_RAM_POWER_ON_INIT_UNSPECIFIED" far-absolute RW
   #endif
#elif defined (DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif


#elif defined (DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU0.Private.DEFAULT_CONST_8BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_8BIT" a 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_8BIT" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU1.Private.DEFAULT_CONST_8BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU1.Private.DEFAULT_CONST_8BIT" a 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU1.Private.DEFAULT_CONST_8BIT" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU2.Private.DEFAULT_CONST_8BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU2.Private.DEFAULT_CONST_8BIT" a 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU2.Private.DEFAULT_CONST_8BIT" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_8BIT_SHARED)
   #undef      DEFAULT_START_SEC_CONST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="Shared.DEFAULT_CONST_8BIT"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.Shared.DEFAULT_CONST_8BIT" a 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.Shared.DEFAULT_CONST_8BIT" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_8BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_CONST_8BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU0.Private.DEFAULT_CONST_16BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_16BIT" a 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_16BIT" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU1.Private.DEFAULT_CONST_16BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU1.Private.DEFAULT_CONST_16BIT" a 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU1.Private.DEFAULT_CONST_16BIT" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU2.Private.DEFAULT_CONST_16BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU2.Private.DEFAULT_CONST_16BIT" a 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU2.Private.DEFAULT_CONST_16BIT" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_16BIT_SHARED)
   #undef      DEFAULT_START_SEC_CONST_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="Shared.DEFAULT_CONST_16BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.Shared.DEFAULT_CONST_16BIT" a 2
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.Shared.DEFAULT_CONST_16BIT" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_16BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_CONST_16BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU0.Private.DEFAULT_CONST_32BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_32BIT" a 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_32BIT" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU1.Private.DEFAULT_CONST_32BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU1.Private.DEFAULT_CONST_32BIT" a 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU1.Private.DEFAULT_CONST_32BIT" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU2.Private.DEFAULT_CONST_32BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU2.Private.DEFAULT_CONST_32BIT" a 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU2.Private.DEFAULT_CONST_32BIT" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_32BIT_SHARED)
   #undef      DEFAULT_START_SEC_CONST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="Shared.DEFAULT_CONST_32BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.Shared.DEFAULT_CONST_32BIT" a 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.Shared.DEFAULT_CONST_32BIT" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_32BIT_SHARED)
   #undef      DEFAULT_STOP_SEC_CONST_32BIT_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU0.Private.DEFAULT_CONST_FAR_UNSPECIFIED"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU0.Private.DEFAULT_CONST_FAR_UNSPECIFIED" a 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU0.Private.DEFAULT_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE0_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU1.Private.DEFAULT_CONST_FAR_UNSPECIFIED"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU1.Private.DEFAULT_CONST_FAR_UNSPECIFIED" a 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU1.Private.DEFAULT_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE1_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="CPU2.Private.DEFAULT_CONST_FAR_UNSPECIFIED"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.CPU2.Private.DEFAULT_CONST_FAR_UNSPECIFIED" a 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.CPU2.Private.DEFAULT_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE2_PRIVATE)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_CORE2_PRIVATE
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif


#elif defined (DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED)
   #undef      DEFAULT_START_SEC_CONST_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="Shared.DEFAULT_CONST_FAR_UNSPECIFIED"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.Shared.DEFAULT_CONST_FAR_UNSPECIFIED" a 
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.Shared.DEFAULT_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
#elif defined (DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED)
   #undef      DEFAULT_STOP_SEC_CONST_UNSPECIFIED_SHARED
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif

#elif defined (CPU0_GUARDED_RAM_START)
	#undef CPU0_GUARDED_RAM_START
	#pragma section ".guardram"

#elif defined (CPU0_GUARDED_RAM_END)
	#undef CPU0_GUARDED_RAM_END
	#pragma section

#elif defined (CPU0_GUARDED_RAM_CRC_START)
	#undef CPU0_GUARDED_RAM_CRC_START
	#pragma section ".guardram_crc"

#elif defined (CPU0_GUARDED_RAM_CRC_END)
	#undef CPU0_GUARDED_RAM_CRC_END
	#pragma section
/*****************************************************************************
**                                 EXTRAS                                   **
******************************************************************************/

#elif defined (LIN_17_ASCLIN_START_LOADABLECFG)
   #undef   LIN_17_ASCLIN_START_LOADABLECFG
   #ifdef _TASKING_C_TRICORE_   
      #pragma section farrom="Shared.LIN_LOADABLE_CHANCFG"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.Shared.LIN_LOADABLE_CHANCFG" a
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".rodata.Shared.LIN_LOADABLE_CHANCFG" far-absolute R
   #endif
#elif defined (LIN_17_ASCLIN_STOP_LOADABLECFG)
   #undef   LIN_17_ASCLIN_STOP_LOADABLECFG
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif

#elif defined (DEFAULT_START_SEC_IVT_CODE)
   #undef      DEFAULT_START_SEC_IVT_CODE
   #ifdef _TASKING_C_TRICORE_
      #pragma section code "inttab"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".inttab" ax 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".inttab" X
   #endif
#elif defined (DEFAULT_STOP_SEC_IVT_CODE)
   #undef      DEFAULT_STOP_SEC_IVT_CODE
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE X
   #endif

#elif defined (PWM_17_GTM_START_SEC_NOTIFICATION)
   #undef      PWM_17_GTM_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
      #pragma section code "PWM_NOTIFICATION"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.PWM_NOTIFICATION" ax
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.PWM_NOTIFICATION" RX
   #endif
#elif defined (PWM_17_GTM_STOP_SEC_NOTIFICATION)
   #undef      PWM_17_GTM_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif

#elif defined (ICU_17_GTMCCU6_START_SEC_NOTIFICATION)
   #undef      ICU_17_GTMCCU6_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
      #pragma section code "ICU_NOTIFICATION"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.ICU_NOTIFICATION" ax
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.ICU_NOTIFICATION" RX
   #endif
#elif defined (ICU_17_GTMCCU6_STOP_SEC_NOTIFICATION)
   #undef      ICU_17_GTMCCU6_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif
   
#elif defined (WDG_17_SCU_START_SEC_NOTIFICATION)
   #undef      WDG_17_SCU_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
      #pragma section code "WDG_NOTIFICATION"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.WDG_NOTIFICATION" ax
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.WDG_NOTIFICATION" RX
   #endif
#elif defined (WDG_17_SCU_STOP_SEC_NOTIFICATION)
   #undef      WDG_17_SCU_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif
   
#elif defined (STM_START_SEC_NOTIFICATION)
   #undef      STM_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
      #pragma section code "STM_NOTIFICATION"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.STM_NOTIFICATION" ax
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.STM_NOTIFICATION" RX
   #endif
#elif defined (STM_STOP_SEC_NOTIFICATION)
   #undef      STM_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif
   
#elif defined (GPT_START_SEC_NOTIFICATION)
   #undef      GPT_START_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
      #pragma section code "GPT_NOTIFICATION"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.GPT_NOTIFICATION" ax
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".text.GPT_NOTIFICATION" RX
   #endif
#elif defined (GPT_STOP_SEC_NOTIFICATION)
   #undef      GPT_STOP_SEC_NOTIFICATION
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif

/* WR Section: Fls Loader Write API placed here */
#elif defined (FLSLOADER_START_WRITE_API)
   #undef     FLSLOADER_START_WRITE_API
   #ifdef _TASKING_C_TRICORE_
      #pragma section code "FLSLOADER_WRITE_SOURCE"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.FLSLOADER_WRITE_SOURCE" ax
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".FLSLOADER_WRITE_SOURCE" RX
   #endif
#elif defined (FLSLOADER_STOP_WRITE_API)
   #undef     FLSLOADER_STOP_WRITE_API
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif
/* ER Section: Fls Loader Erase API placed here */
#elif defined (FLSLOADER_START_ERASE_API)
   #undef     FLSLOADER_START_ERASE_API
   #ifdef _TASKING_C_TRICORE_
      #pragma section code "FLSLOADER_ERASE_SOURCE"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.FLSLOADER_ERASE_SOURCE" ax
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".FLSLOADER_ERASE_SOURCE" RX
   #endif
#elif defined (FLSLOADER_STOP_ERASE_API)
   #undef     FLSLOADER_STOP_ERASE_API
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif

/* ---The following sections attempt to locate FLS Write and Erase command-----
   ---Cycles in an order. It is essential to enforce the correct sequence------
   ---so that the FLS driver can perform as requird.-------------------------*/
#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN_API)
   #undef     FLS_17_PMU_START_SEC_SPL_CODE_WRITECMD_BEGIN_API
   #ifdef _TASKING_C_TRICORE_
      #pragma section code "FLS_AC_WRITE_SOURCE"
      #pragma optimize R
   #elif _GNU_C_TRICORE_
      #pragma section ".text.FLS_AC_WRITE_SOURCE" ax
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".FLS_AC_WRITE_SOURCE" far-absolute RX
   #endif
   
#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN_API)
   #undef     FLS_17_PMU_STOP_SEC_SPL_CODE_WRITECMD_BEGIN_API
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
      #pragma endoptimize
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif   

#elif defined (FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN_API)
   #undef     FLS_17_PMU_START_SEC_SPL_CODE_ERASECMD_BEGIN_API
   #ifdef _TASKING_C_TRICORE_
      #pragma section code "FLS_AC_ERASE_SOURCE"
      #pragma optimize R
   #elif _GNU_C_TRICORE_
      #pragma section ".text.FLS_AC_ERASE_SOURCE" ax
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".FLS_AC_ERASE_SOURCE" far-absolute RX
   #endif
   
#elif defined (FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN_API)
   #undef     FLS_17_PMU_STOP_SEC_SPL_CODE_ERASECMD_BEGIN_API
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
      #pragma endoptimize
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif   

#elif defined (FEE_START_JOBENDNOTIF)
   #undef   FEE_START_JOBENDNOTIF
   #ifdef _TASKING_C_TRICORE_
      #pragma section code "FEE_JOBENDNOTIF_CODE"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.FEE_JOBENDNOTIF_CODE" ax
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".FEE_JOBENDNOTIF_CODE" RX
   #endif
#elif defined (FEE_STOP_JOBENDNOTIF)
   #undef   FEE_STOP_JOBENDNOTIF
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif

#elif defined (FEE_START_JOBERRNOTIF)
   #undef   FEE_START_JOBERRNOTIF
   #ifdef _TASKING_C_TRICORE_
      #pragma section code "FEE_JOBERRNOTIF_CODE"
   #elif _GNU_C_TRICORE_
      #pragma section ".text.FEE_JOBERRNOTIF_CODE" ax
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE ".FEE_JOBERRNOTIF_CODE" RX
   #endif
#elif defined (FEE_STOP_JOBERRNOTIF)
   #undef   FEE_STOP_JOBERRNOTIF
   #ifdef _TASKING_C_TRICORE_
      #pragma section code restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CODE RX
   #endif
   
   
#elif defined (FLS_17_PMU_START_CONFIG)
   #undef      FLS_17_PMU_START_CONFIG
   #ifdef _TASKING_C_TRICORE_
      #pragma section fardata="FLS_RESERVED"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".data.FLS_RESERVED" aw 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".FLS_RESERVED" far-absolute RW
   #endif
#elif defined (FLS_17_PMU_STOP_CONFIG)
   #undef      FLS_17_PMU_STOP_CONFIG
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section fardata restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif
   
#elif defined (ETH_17_ETHMAC_RES_START_SEC_VAR_FAST_8BIT)
   #undef      ETH_17_ETHMAC_RES_START_SEC_VAR_FAST_8BIT
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="ETH_RAM_FAST_8BIT"
      #pragma for_uninitialized_data_use_memory near
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.ETH_RAM_FAST_8BIT" awB 1
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".error" ".ETH_RAM_FAST_8BIT" RW
   #endif
#elif defined (ETH_17_ETHMAC_RES_STOP_SEC_VAR_FAST_8BIT)
   #undef      ETH_17_ETHMAC_RES_STOP_SEC_VAR_FAST_8BIT
   #ifdef _TASKING_C_TRICORE_
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif

#elif defined (ETH_17_ETHMAC_RES_START_SEC_VAR_FAST_32BIT)
   #undef      ETH_17_ETHMAC_RES_START_SEC_VAR_FAST_32BIT
   #ifdef _TASKING_C_TRICORE_
      #pragma section nearbss="ETH_RAM_FAST_32BIT"
      #pragma for_uninitialized_data_use_memory near
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".bss.ETH_RAM_FAST_32BIT" awB 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".error" ".ETH_RAM_FAST_32BIT" RW
   #endif
#elif defined (ETH_17_ETHMAC_RES_STOP_SEC_VAR_FAST_32BIT)
   #undef      ETH_17_ETHMAC_RES_STOP_SEC_VAR_FAST_32BIT
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma for_uninitialized_data_use_memory restore
      #pragma section nearbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif
   
 #elif defined (ADC_DMA_START_SEC_EMUXSCAN_BUFFER)
   #undef      ADC_DMA_START_SEC_EMUXSCAN_BUFFER
   #ifdef _TASKING_C_TRICORE_
      #pragma section farbss="ADC_DMA_EMUXSCAN_RAM_16BIT"
      #pragma align 4
   #elif _GNU_C_TRICORE_
      #pragma section ".data.ADC_DMA_EMUXSCAN_RAM_16BIT" aw 4
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA ".ADC_DMA_EMUXSCAN_RAM_16BIT" far-absolute RW
   #endif
#elif defined (ADC_DMA_STOP_SEC_EMUXSCAN_BUFFER)
   #undef      ADC_DMA_STOP_SEC_EMUXSCAN_BUFFER
   #ifdef _TASKING_C_TRICORE_
      #pragma align restore
      #pragma section farbss restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section DATA RW
   #endif
   
   
#elif defined (BMD_HDR_START_SEC_BMI_HEADER)
   #undef      BMD_HDR_START_SEC_BMI_HEADER
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom="BMD_HDR_CONST_FAR_UNSPECIFIED"
   #elif _GNU_C_TRICORE_
      #pragma section ".rodata.BMD_HDR_CONST_FAR_UNSPECIFIED" a
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST ".BMD_HDR_CONST_FAR_UNSPECIFIED" far-absolute R
   #endif
#elif defined (BMD_HDR_STOP_SEC_BMI_HEADER)
   #undef      BMD_HDR_STOP_SEC_BMI_HEADER
   #ifdef _TASKING_C_TRICORE_
      #pragma section farrom restore
   #elif _GNU_C_TRICORE_
      #pragma section
   #elif _DIABDATA_C_TRICORE_
      #pragma section CONST R
   #endif
   
#elif defined (SPI_START_SEC_VAR_FAST_32BIT)
   #undef      SPI_START_SEC_VAR_FAST_32BIT
   #pragma section DATA ".error" ".SPI_RAM_FAST_32BIT" RW
#elif defined (SPI_STOP_SEC_VAR_FAST_32BIT)
   #undef      SPI_STOP_SEC_VAR_FAST_32BIT
   #pragma section DATA RW   
   
/* -------------------------------------------------------------------------- */
/* End of default section mapping                                             */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* Begin alignment mapping                                                    */
/* -------------------------------------------------------------------------- */

#elif defined (DEFAULT_START_VAR_ALIGN_16_BIT)
   #undef      DEFAULT_START_VAR_ALIGN_16_BIT
   #pragma align 4
#elif defined (DEFAULT_STOP_VAR_ALIGN_16_BIT)
   #undef      DEFAULT_STOP_VAR_ALIGN_16_BIT
   #pragma align restore
/* -------------------------------------------------------------------------- */
/* End of alignment mapping                                                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* Begin Packing                                                              */
/* -------------------------------------------------------------------------- */

#elif defined (DEFAULT_START_VAR_PACK_2)
   #undef      DEFAULT_START_VAR_PACK_2
   #pragma pack 2
#elif defined (DEFAULT_STOP_VAR_PACK_2)
   #undef      DEFAULT_STOP_VAR_PACK_2
   #pragma pack 0
/* -------------------------------------------------------------------------- */
/* End of Packing                                                             */
/* -------------------------------------------------------------------------- */

/*lint +idlen(60) +esym(961,92) */
/*lint +esym(960,19.6)   */  /* Allow usage of #undef */


#elif defined (CALIB_HEADER_START_SEC)
   #undef      CALIB_HEADER_START_SEC
   #pragma section ".calib_ram_header" a
#elif defined (CALIB_HEADER_STOP_SEC)
   #undef      CALIB_HEADER_STOP_SEC
   #pragma section
         
#elif defined (CALIB_START_SEC)
   #undef      CALIB_START_SEC
   #pragma section ".calib_ram_32" a
#elif defined (CALIB_STOP_SEC)
   #undef      CALIB_STOP_SEC
   #pragma section

#elif defined (CALIB_RAM_START_SEC)
   #undef      CALIB_RAM_START_SEC
   #pragma section ".calib_ram_32" az
#elif defined (CALIB_RAM_STOP_SEC)
   #undef      CALIB_RAM_STOP_SEC
   #pragma section


#elif defined (RTE_START_SEC_CALPRM_32)
   #undef      RTE_START_SEC_CALPRM_32
   #pragma section ".calib_ram_32" a 4
#elif defined (RTE_STOP_SEC_CALPRM_32)
   #undef      RTE_STOP_SEC_CALPRM_32
   #pragma section

#elif defined (RTE_START_SEC_CALPRM_16)
   #undef      RTE_START_SEC_CALPRM_16
   #pragma section ".calib_ram_16" a 2
#elif defined (RTE_STOP_SEC_CALPRM_16)
   #undef      RTE_STOP_SEC_CALPRM_16
   #pragma section

#elif defined (RTE_START_SEC_CALPRM_8)
   #undef      RTE_START_SEC_CALPRM_8
   #pragma section ".calib_ram_8" a 1
#elif defined (RTE_STOP_SEC_CALPRM_8)
   #undef      RTE_STOP_SEC_CALPRM_8
   #pragma section

#elif defined (RTE_START_SEC_CALPRM_BOOLEAN)
   #undef      RTE_START_SEC_CALPRM_BOOLEAN
   #pragma section ".calib_ram_8" a 1
#elif defined (RTE_STOP_SEC_CALPRM_BOOLEAN)
   #undef      RTE_STOP_SEC_CALPRM_BOOLEAN
   #pragma section

#endif  /* START_WITH_IF */
