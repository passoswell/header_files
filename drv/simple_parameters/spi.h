/**
 * @file  spi.h
 * @date  18-December-2020
 * @brief Configuration and access of Serial Peripheral Interfaces as master.
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
 * @brief Options for configuration of CS pin
 */
typedef enum
{
  SPI_HARDWARE_CS = 0, /*!< The CS is controled by hardware, if available */
  SPI_SOFTWARE_CS,     /*!< The CS must be configured and manibulated 
                            by the caller */
}SPI_CS_Options;

/**
 * @brief SPI configuration structure.
 */
typedef struct
{
  SPI_Port_t     Port;
  SPI_Mode_t     Mode;

  SPI_CS_Options CsMode;              

  float          ClockFrequency;
  uint8_t        MosiValueOnReads; /*!<Value sent during read operations*/
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
 * @note   The data received is ignored and discarded.
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

#endif /* SPI_H */
