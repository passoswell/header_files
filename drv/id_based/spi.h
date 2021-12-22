/**
 * @file  spi.h
 * @date  18-December-2020
 * @brief Configuration and access of Serial Peripheral Interfaces.
 *
 * @author
 * @author
 */


#ifndef SPI_H
#define SPI_H


#include <stdint.h>
#include "stdstatus.h"
#include "setup.h"


/**
 * @brief Maximum number of SPI IDs, which limits the maximum number of 
 * SPI devices that can be configured by this driver. SPI_MAX_ID can be changed
 * by defining it on setup.h file.
 */
#ifndef SPI_MAX_ID
#define SPI_MAX_ID                                                             3
#endif


/**
 * @brief List of SPI ports and routed pins.
 * COPI = Controller Out Peripheral In
 * CIPO = Controller In Peripheral Out
 */
typedef enum
{
  SPI1_SCL_PA5_CIPO_PA6_COPI_PA7 = 0,
  SPI2_SCL_PB10_CIPO_C2_COPI_C3,
  SPI2_SCL_PB13_CIPO_PC2_COPI_PC3,
  SPI3_SCL_PC10_CIPO_PC11_COPI_PC12,
  SPI3_SCL_PC10_CIPO_PC11_COPI_PB5,
  SPI_NUMBER_OF_PORTS,
} SPI_Port_t;

/**
 * @brief List of GPIO ports.
 */
typedef enum
{
  SPI_GPIO_PORT_A = 0,
  SPI_GPIO_PORT_B,
  SPI_GPIO_PORT_C,
  SPI_GPIO_PORT_D,
  SPI_GPIO_PORT_E,
  SPI_GPIO_PORT_F,
  SPI_GPIO_PORT_G,
  SPI_GPIO_PORT_H,
  SPI_NUMBER_OF_GPIO_PORTS,
} SPI_ChipSelectPort_t;

/**
 * @brief List of GPIO pins.
 */
typedef enum
{
  SPI_GPIO_PIN_0 = 0,
  SPI_GPIO_PIN_1,
  SPI_GPIO_PIN_2,
  SPI_GPIO_PIN_3,
  SPI_GPIO_PIN_4,
  SPI_GPIO_PIN_5,
  SPI_GPIO_PIN_6,
  SPI_GPIO_PIN_7,
  SPI_GPIO_PIN_8,
  SPI_GPIO_PIN_9,
  SPI_GPIO_PIN_10,
  SPI_GPIO_PIN_11,
  SPI_GPIO_PIN_12,
  SPI_GPIO_PIN_13,
  SPI_GPIO_PIN_14,
  SPI_GPIO_PIN_15,
  SPI_NUMBER_OF_PINS,
}SPI_ChipSelectPin_t;

/**
 * @brief List of polarities.
 */
typedef enum
{
  SPI_ACTIVE_LOW  = 0,
  SPI_ACTIVE_HIGH,
  SPI_NUMBER_OF_POLARITIES,
} SPI_Polarity_t;

/**
 * @brief List of clock phases.
 */
typedef enum
{
  SPI_PHA_LEADING_EDGE   = ((uint32_t)0x00000000U),
  SPI_PHA_TRAILING_EDGE  = (0x1UL << (0U))
} SPI_Pha_Opt;

/**
 * @brief List of SPI modes.
 * @note
 *        CPOL = 0 : SCL idles at 0 (low level)
 *        CPOL = 1 : SCL idles at 1 (high level)
 *        CPHA = 0 : The "out" side changes  data on the trailing edge of SCL,
 *                   the "in" side captures  data on the leading edge of SCL.
 *        CPHA = 1 : The "out" side changes  data on the leading edge of SCL,
 *                   the "in" side captures  data on the trailing edge of SCL.
 */
typedef enum
{
  SPI_MODE_0 = 0, /*!< CPOL = 0, CPHA = 0 */
  SPI_MODE_1,     /*!< CPOL = 0,,CPHA = 1 */
  SPI_MODE_2,     /*!< CPOL = 1, CPHA = 0 */
  SPI_MODE_3,     /*!< CPOL = 1, CPHA = 1 */
  SPI_NUMBER_OF_MODES,
}SPI_Mode_t;

/**
 * @brief List of prescalers.
 */
typedef enum
{
  SPI_PRESCALLER_2 = 0,
  SPI_PRESCALLER_4,
  SPI_PRESCALLER_8,
  SPI_PRESCALLER_16,
  SPI_PRESCALLER_32,
  SPI_PRESCALLER_64,
  SPI_PRESCALLER_128,
  SPI_PRESCALLER_256,
  SPI_NUMBER_OF_PRESCALERS,
} SPI_Prescaler_t;

/**
 * @brief SPI configuration structure.
 */
typedef struct
{
  SPI_Port_t           Port;
  SPI_Mode_t           Mode;

  SPI_ChipSelectPort_t ChipSelectPort;
  SPI_ChipSelectPin_t  ChipSelectPin;
  SPI_Polarity_t       ChipSelectPolarity;

  SPI_Prescaler_t      Prescaler;
  uint8_t              MosiValueOnReads; /*!<Value sent during read operations*/
} SPI_Parameters_t;



/**
 * @brief  SPI configuration routine.
 * @param  ID : ID that should be allocated and configured.
 * @param  Parameter : The desired SPI parameters.
 * @retval EStatus_t
 */
EStatus_t SPI_Init(uint8_t ID, SPI_Parameters_t Parameter);


/**
 * @brief  Basic routine to send data to SPI.
 * @param  ID : SPI ID number.
 * @param  SendBuffer : Pointer to where the data is.
 * @param  SendLength : How many bytes to send.
 * @retval EStatus_t
 */
EStatus_t SPI_Send(uint8_t ID, uint8_t *SendBuffer, uint16_t SendLength);


/**
 * @brief  Basic routine to read data from SPI.
 * @param  ID : SPI ID number.
 * @param  RecBuffer : Pointer to store the received data.
 * @param  RecLength : Maximum amount of data to receive.
 * @retval EStatus_t
 * @note
 *         The MosiValueOnReads configured during the SPI_Init call will be
 *         sent through MOSI pin.
 */
EStatus_t SPI_Read(uint8_t ID, uint8_t *RecBuffer, uint16_t RecLength);


/**
 * @brief  Routine to send and read data from SPI.
 * @param  ID : SPI ID number.
 * @param  SendBuffer : Pointer to where the data is.
 * @param  RecBuffer : Pointer to store the received data.
 * @param  Length : Maximum amount of data to receive.
 * @retval EStatus_t
 */
EStatus_t SPI_Transfer(uint8_t ID, uint8_t *SendBuffer, uint8_t *RecBuffer,
    uint16_t Length);


/**
 * @brief  Routine to  take control over CS line state.
 * @param  ID : SPI ID number.
 * @param  Lock : Locks state of CS pin if equals to one.
 * @param  Value : Value at which CS pin will lock, either 0 or 1.
 * @retval EStatus_t
 * @note   If Lock is zero, CS pin goes to unselected state.
 *         If Lock is not zero, CS goes to zero if Value is zero.
 *         If Lock is not zero, CS goes to one if Value is not zero.
 */
EStatus_t SPI_CsControl(uint8_t ID, uint8_t Lock, uint8_t Value);

#endif /* SPI_H */
