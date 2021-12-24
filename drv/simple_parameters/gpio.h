/**
 * @file  gpio.h
 * @date  11-October-2020
 * @brief Configuration and access General Purpose I/O.
 *
 * This header file contains the prototypes for GPIO
 * configuration and access.
 *
 * @author
 * @author
 */

#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>
#include "stdstatus.h"
#include "setup.h"


/**
 * @brief Maximum number of GPIO IDs, which limits the maximum number of 
 * GPIO pins that can be configured by this driver. GPIO_MAX_ID can be changed
 * by defining it on setup.h file.
 */
#ifndef GPIO_MAX_ID
#define GPIO_MAX_ID                                                           50
#endif


/**
 * @brief List of GPIO pins.
 */
typedef enum
{
  GPIO_PIN_0 = 0,
  GPIO_PIN_1,
  GPIO_PIN_2,
  GPIO_PIN_3,
  GPIO_PIN_4,
  GPIO_PIN_5,
  GPIO_PIN_6,
  GPIO_PIN_7,
  GPIO_PIN_8,
  GPIO_PIN_9,
  GPIO_PIN_10,
  GPIO_PIN_11,
  GPIO_PIN_12,
  GPIO_PIN_13,
  GPIO_PIN_14,
  GPIO_PIN_15,
  GPIO_NUMBER_OF_PINS,
} GPIO_PinList_t;

/**
 * @brief List of GPIO ports.
 */
typedef enum
{
  GPIO_PORT_A = 0,
  GPIO_PORT_B,
  GPIO_PORT_C,
  GPIO_PORT_D,
  GPIO_PORT_E,
  GPIO_PORT_F,
  GPIO_PORT_G,
  GPIO_PORT_H,
  GPIO_PORT_I,
  GPIO_NUMBER_OF_PORTS,        /*!< For Sizing Only */
} GPIO_PortList_t;

/**
 * @brief GPIO direction enumeration.
 */
typedef enum
{
  GPIO_INPUT = 0,
  GPIO_OUTPUT,
} GPIO_Direction_t;

/**
 * @brief GPIO driver type list.
 */
typedef enum
{
  GPIO_PULL_DISABLED = 0,  /*!< No pull resistor */
  GPIO_PULL_UP          ,  /*!< Open drain with internal pull-up */
  GPIO_PULL_DOWN        ,  /*!< Open drain with internal pull-down */
  GPIO_OPEN_DRAIN       ,  /*!< Open drain with no pull */
  GPIO_PUSH_PULL        ,  /*!< Push-pull driver, output only */
  GPIO_NUMBER_OF_DRIVERS,  /*!< For Sizing Only */
} GPIO_PullCfg_t;

/**
 * @brief GPIO level list.
 */
typedef enum
{
  GPIO_LOW_LEVEL  = 0,    /*!< Low level logic  */
  GPIO_HIGH_LEVEL = 1,    /*!< High level logic */
}GPIO_DataOutput_t;

/**
 * @brief GPIO configuration structure.
 */
typedef struct
{
  GPIO_PinList_t    Pin;
  GPIO_PortList_t   Port;
  GPIO_Direction_t  Direction;
  GPIO_PullCfg_t    PullConfig;
  GPIO_DataOutput_t OutputValue;
} GPIO_Parameters_t;


/**
 * @brief  Routine to configure a GPIO pin.
 * @param  ID : Requester's ID
 * @param  Parameter : Pointer to the desired parameters (@ref GPIO_Parameters)
 * @retval EStatus_t
 */
EStatus_t GPIO_Init(uint8_t ID, GPIO_Parameters_t Parameter);


/**
 * @brief  Routine to set GPIO high.
 * @param  ID : Pin to set
 * @retval EStatus_t
 * @note   Pin must be an output pin.
 */
EStatus_t GPIO_Set(uint8_t ID);


/**
 * @brief  Routine to set GPIO low.
 * @param  ID : Pin to clear
 * @retval EStatus_t
 * @note   Pin must be an output pin.
 */
EStatus_t GPIO_Clear(uint8_t ID);


/**
 * @brief  Routine to switch the state of a GPIO between low and high.
 * @param  ID : Whose pin should have its state changed
 * @retval EStatus_t
 * @note   Pin must be an output.
 *         If low, GPIO goes high.
 *         If high, GPIO goes low.
 */
EStatus_t  GPIO_Toggle(uint8_t ID);


/**
 * @brief  Routine to change the state of a GPIO.
 * @param  ID : Whose pin should have its state changed
 * @param  Value : One of @ref GPIO_DataOutput_t values
 * @retval EStatus_t
 * @note   Pin must be an output.
 *         If 0, GPIO goes low.
 *         If 1, GPIO goes high.
 */
EStatus_t  GPIO_Write(uint8_t ID, uint8_t Value);


/**
 * @brief  Routine to read a GPIO input.
 * @param  ID : ID of pin to read.
 * @param  InputValue : Pin's value is one of GPIO_DataOutput_t values
 * @retval EStatus_t
 * @note   Pin must be an input.
 */
EStatus_t GPIO_Read(uint8_t ID, uint8_t * InputValue);

#endif  /* GPIO_H */
