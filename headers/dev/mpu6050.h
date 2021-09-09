/**
 * @file  mpu6050.h
 * @date  25-December-2020
 * @brief MPU6050 accelerometer and gyroscope configuration and access.
 *
 * @author
 * @author
 */


#ifndef MPU6050_H
#define MPU6050_H


#include "setup.h"
#include "iic.h"
#include "custom_types.h"


/**
 * @brief Maximum number of devices allowed.
 */
#ifndef MPU6050_MAX_ID
#define MPU6050_MAX_ID                                                         1
#endif


/**
 * @brief Useful characteristics.
 */


/**
 * @brief List of possible IIC addresses (see datasheet).
 */
enum MPU6050_IICAddress{
  MPU6050_0x68 = 0x68,
  MPU6050_0x69 = 0x69,
};


/**
 * @brief  Basic configuration structure.
 */
typedef struct{
  IIC_Port_t   Port;         /*!< IIC pins for physical connection*/
  uint16_t     Address;      /*!< 7 bits IIC address */
  IIC_PullUp_t PullUpOption;
}MPU6050_Parameters_t;


extern IMU_Functions_t MPU6050_Functions;


/**
 * @brief  MPU6050 IIC  peripheral initialization routine.
 * @param  ID : ID for device used.
 * @param  Parameter : Pointer to the desired configuration parameters
 * @retval EStatus_t
 * @note This routine only initializes the internal hardware and is not enough
 *       for full device usage; the MPU6050_ExtHwConfig has to be called as
 *       well.
 */
EStatus_t MPU6050_IntHwInit( uint8_t ID, MPU6050_Parameters_t Parameter );


/**
 * @brief  MPU6050 device initialization routine.
 * @param  ID : ID for device used.
 * @retval EStatus_t
 *@note  This routine only configures the device hardware and is not enough
 *       for full device usage; the MPU6050_IntHwInit must be called first.
 */
EStatus_t MPU6050_ExtHwConfig( uint8_t ID );


/**
 * @brief  This routine reads sensor data.
 * @param  ID : ID for device used.
 * @param  Data: Variable where data read will be stored.
 * @retval EStatus_t
 * @note   Not all fields will be filled, it depends on the sensor type.
 */
EStatus_t MPU6050_Read( uint8_t ID, IMU_Data_t *Data );


/**
 * @brief  This routine returns the specifications for the device.
 * @param  ID : ID for device used.
 * @param  Pixel: byte to send.
 * @retval EStatus_t
 */
EStatus_t MPU6050_ReadSpecs(IMU_specs_t *Specs);

#endif  /* MPU6050_H */
