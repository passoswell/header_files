/**
 * @file  iic.h
 * @date  14-December-2020
 * @brief Configuration and access to Inter-Integrated Circuit interfaces.
 *
 * @author
 * @author
 */


#ifndef IIC_H
#define IIC_H


#include <stdint.h>
#include "stdstatus.h"
#include "setup.h"


/**
 * @brief Maximum number of IIC IDs, which limits the maximum number of 
 * IIC devices that can be configured by this driver. IIC_MAX_ID can be changed
 * by defining it on setup.h file.
 */
#ifndef IIC_MAX_ID
#define IIC_MAX_ID                                                             3
#endif


/**
 * @brief List of IIC ports and routed pins.
 */
typedef enum
{
  IIC1_SDA_PB7_SCL_PB6,
  IIC2_SDA_PB11_SCL_PB10,
  IIC3_SDA_PC9_SCL_PA8,
  IIC_NUMBER_OF_PORTS,
}IIC_Port_t;

/**
 * @brief List of options the device's IIC protocol address.
 */
typedef enum
{
  IIC_7_BITS,
  IIC_10_BITS,
  IIC_NUMBER_OF_DEVADDR_SIZES,
} IIC_DevAddrSize_t;

/**
 * @brief List of options for register size in bits on the device.
 */
typedef enum
{
  IIC_NO_REGADDR = 0,
  IIC_8_BITS,
  IIC_16_BITS,
  IIC_24_BITS,
  IIC_32_BITS,
  IIC_NUMBER_OF_REGADDR_SIZES,
} IIC_RegAddrSize_t;

/**
 * @brief List of available baud rates.
 */
typedef enum
{
  IIC_100_kBPS = 0,
  IIC_400_kBPS,
  IIC_NUMBER_OF_BAUDRATES,
} IIC_BaudRate_t;

/**
 * @brief List of pull resistor options.
 */
typedef enum
{
  IIC_PULLUP_DISABLED = 0,
  IIC_PULLUP_ENABLED,
  IIC_NUMBER_OF_PULL_OPTIONS,
} IIC_PullUp_t;


/**
 * @brief IIC configuration structure.
 */
typedef struct
{
  IIC_Port_t        Port;
  IIC_DevAddrSize_t DevAddrSize;  /*!< IIC protocol address size */
  uint16_t          DevAddress;   /*!< IIC protocol address of the device */
  IIC_BaudRate_t    BaudRate;
  IIC_PullUp_t      PullUpOption;
  IIC_RegAddrSize_t RegAddrSize;  /*!< Size of the address inside the device */
}IIC_Parameters_t;


/**
 * @brief  Routine to configure an IIC port.
 * @param  ID : ID that should be allocated and configured.
 * @param  Parameter : The desired IIC parameters (@ref IIC_Parameters_t).
 * @param  SendLength : How many bytes to send.
 * @retval EStatus_t
 */
EStatus_t IIC_Init(uint8_t ID, IIC_Parameters_t Parameter);


/**
 * @brief  Basic routine to send data.
 * @param  ID : IIC ID number.
 * @param  Register : Adrress of a register position in the IIC device.
 * @param  SendBuffer : Pointer to where the data is.
 * @param  SendLength : How many bytes to send.
 * @retval EStatus_t
 */
EStatus_t IIC_Send(uint8_t ID, uint32_t Register, uint8_t *SendBuffer,
    uint32_t SendLength);


/**
 * @brief  Basic routine to receive data.
 * @param  ID : IIC ID number.
 * @param  Register : Adrress of a register position in the IIC device.
 * @param  RecBuffer : Pointer to store the received data.
 * @param  RecLength : Maximum amount of data to receive.
 * @retval EStatus_t
 */
EStatus_t IIC_Read(uint8_t ID, uint32_t Register, uint8_t *RecBuffer,
    uint16_t RecLength);


/**
 * @brief Reconfigure IIC hardware with the specified parameters.
 * @param  ID : IIC ID number.
 * @param  Parameter : The desired IIC parameters (@ref IIC_Parameters_t).
 * @retval EStatus_t
 */
EStatus_t IIC_Reconfigure(uint8_t ID, IIC_Parameters_t Parameter);

#endif /* IIC_H */
