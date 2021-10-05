// This file contains #defines, typedefs, etc used by Application Rings

#ifndef ASW_RTE_TYPE_H
#define ASW_RTE_TYPE_H

#  ifndef false
#   define false                       (0U)
#  endif

#  ifndef true
#   define true                        (1U)
#  endif

#ifndef MAX_uint8_T
#define MAX_uint8_T                     (255)
#endif

// typedef enum TeVSDR_e_HVCurrentSense {
// CeVSDR_e_Shunt = 0,
// CeVSDR_e_Hall = 1,
// CeVSDR_e_ShuntAndHall = 2
// } TeVSDR_e_HVCurrentSense;

// typedef enum TeHVSR_e_SCU_SystemSts {
// CeHVSR_e_SCU_Default = 0,
// CeHVSR_e_SCU_EnableHV_System = 1,
// CeHVSR_e_SCU_FaultChecks1 = 2,
// CeHVSR_e_SCU_FaultChecks2 = 3,
// CeHVSR_e_SCU_ContactorCheck = 4,
// CeHVSR_e_SCU_ContactorClosure = 5,
// CeHVSR_e_SCU_EvaluateContactorClosure = 6,
// CeHVSR_e_SCU_TempState1 = 7,
// CeHVSR_e_SCU_ReversePowerFlow = 8,
// CeHVSR_e_SCU_TempsState2 = 9,
// CeHVSR_e_SCU_Balancing = 10,
// CeHVSR_e_SCU_Charging = 11,
// CeHVSR_e_SCU_Propulsion = 12,
// CeHVSR_e_SCU_DisableHV_System = 13,
// CeHVSR_e_SCU_ContactorBasicCheck = 14,
// CeHVSR_e_SCU_ContactorOpen = 15,
// CeHVSR_e_SCU_EvaluateContactorOpen = 16,
// CeHVSR_e_SCU_PowerDownComplete = 17,
// CeHVSR_e_SCU_EmergencyStop = 18,
// CeHVSR_e_SCU_PeriodicWakeUP = 19,
// CeHVSR_e_SCU_EndOfLine = 20,
// CeHVSR_e_SCU_LimpHome = 21,
// CeHVSR_e_SCU_CheckHV_System = 22
// } TeHVSR_e_SCU_SystemSts;

#define CeHVSR_e_SCU_Default                        0
#define CeHVSR_e_SCU_EnableHV_System                1
#define CeHVSR_e_SCU_FaultChecks1                   2
#define CeHVSR_e_SCU_FaultChecks2                   3
#define CeHVSR_e_SCU_ContactorCheck                 4
#define CeHVSR_e_SCU_ContactorClosure               5
#define CeHVSR_e_SCU_EvaluateContactorClosure       6
#define CeHVSR_e_SCU_TempState1                     7
#define CeHVSR_e_SCU_ReversePowerFlow               8
#define CeHVSR_e_SCU_TempsState2                    9
#define CeHVSR_e_SCU_Balancing                      10
#define CeHVSR_e_SCU_Charging                       11
#define CeHVSR_e_SCU_Propulsion                     12
#define CeHVSR_e_SCU_DisableHV_System               13
#define CeHVSR_e_SCU_ContactorBasicCheck            14
#define CeHVSR_e_SCU_ContactorOpen                  15
#define CeHVSR_e_SCU_EvaluateContactorOpen          16
#define CeHVSR_e_SCU_PowerDownComplete              17
#define CeHVSR_e_SCU_EmergencyStop                  18
#define CeHVSR_e_SCU_PeriodicWakeUP                 19
#define CeHVSR_e_SCU_EndOfLine                      20
#define CeHVSR_e_SCU_LimpHome                       21
#define CeHVSR_e_SCU_CheckHV_System                 22

#endif
