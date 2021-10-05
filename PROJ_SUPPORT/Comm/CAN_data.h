

#ifndef __CAN_DATA_H_
#define __CAN_DATA_H_

// /* @brief CAN message buffer length (used for rollback counter and CRC calculation */
#define CAN_MSG_BUFFER_LENGTH              (8U)

// /* @brief CRC status bit status definition for RE_RollbackCnt */
#define CAN_MSG_CRC_STATUS_BIT_MASK        (0x01U)

// /* @brief Rolling counter status bit definition for RE_RollbackCnt */
#define CAN_MSG_ROLLCNT_STATUS_BIT_MASK_OK (0x02U)

// /* @brief Rolling counter location in the CAN message: bitmask and byte location */
#define CAN_MSG_ROLLCNT_MASK               (0x0FU)  /* lower nibble */
#define CAN_MSG_ROLLCNT_LOCATION           (6U)

// /* @brief CRC8 location in the CAN message: byte location*/
#define CAN_MSG_CRC_LOCATION               (7U)

#define CRC8_H2F_START_VALUE    0xFFU
#define CRC8_H2F_XOR            0xFFU

#define CRC8_XOR_TYPE           (0x00u)
#define CRC8_POLY_TYPE          (0x01u)

void CAN_CheckCANMsg(uint8 *u8msg, uint8 u8cnt, uint8 *u8status);
void CAN_ProtCANMsg(uint8 *u8msg, uint8 u8cnt, uint8 u8CRCType);
bool CAN_Transmission_Check(void);

#endif