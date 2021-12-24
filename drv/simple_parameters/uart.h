/**
 * @file  uart.h
 * @date  10-December-2020
 * @brief Configuration and access of UART interfaces.
 *
 * @author
 * @author
 */


#ifndef UART_H
#define UART_H


#include <stdint.h>
#include "stdstatus.h"
#include "setup.h"


/**
 * @brief Maximum number of UART IDs, which limits the maximum number of 
 * UART channels that can be configured by this driver. UART_MAX_ID
 * can be changed by defining it on setup.h file.
 */
#ifndef UART_MAX_ID
#define UART_MAX_ID                                                            3
#endif


/**
 * @brief Command to stop reception when used with UART_Read function.
 */
#define UART_ABORT_RECEPTION                                                0x00


/**
 * @brief List of UART ports and routed pins.
 */
typedef enum
{
  UART1_RX_PA10_TX_PA9,
  UART2_RX_PD6_TX_PD5,
  UART2_RX_PA3_TX_PA2,
  UART3_RX_PD9_TX_PD8,
  UART6_RX_PC7_TX_PC6,
  UART_NUMBER_OF_PORTS,
} UART_Port_t;

/**
 * @brief List of available baud rates.
 */
typedef enum
{
  UART_9600_BPS,
  UART_19200_BPS,
  UART_57600_BPS,
  UART_115200_BPS,
  UART_230400_BPS,
  UART_460800_BPS,
  UART_921600_BPS,
  UART_NUMBER_OF_BAUDRATES,
}UART_BaudRate_t;

/**
 * @brief UART configuration structure.
 */
typedef struct
{
  UART_Port_t     Port;
  UART_BaudRate_t BaudRate;
  uint32_t        ReceptionTimeOut_ms;
}UART_Parameters_t;

/**
 * @brief  UART configuration routine.
 * @param  ID : ID that should be allocated and configured.
 * @param  Parameter : the desired UART's parameters.
 * @retval EStatus_t
 */
EStatus_t UART_Init(uint8_t ID, UART_Parameters_t Parameter);


/**
 * @brief  Basic routine to send data.
 * @param  ID : UART ID number.
 * @param  SendBuffer : Pointer to where the data is.
 * @param  SendLength : How many bytes to send.
 * @retval EStatus_t
 */
EStatus_t UART_Send(uint8_t ID, uint8_t *SendBuffer, uint32_t SendLength);


/**
 * @brief  Basic routine to receive data.
 * @param  ID : UART ID number.
 * @param  RecBuffer : Pointer to store the received data.
 * @param  RecLength : Maximum amount of data to receive.
 * @retval EStatus_t
 * @note
 *         UART_ABORT_RECEPTION can be sent as RecLength to abort reception
 *         The first 2 bytes of the buffer correspond to the number of bytes
 *         received, MSB first.
 */
EStatus_t UART_Read(uint8_t ID, uint8_t *RecBuffer, uint32_t RecLength);


/**
 * @brief Reconfigure UART hardware with the specified parameters.
 * @param  ID : UART ID number.
 * @param  Parameter : Pointer to the desired UART's parameters.
 * @retval EStatus_t
 */
EStatus_t UART_Reconfigure(uint8_t ID, UART_Parameters_t Parameter);

#endif /* UART_H */
