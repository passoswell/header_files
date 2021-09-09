/**
 * @file  sdcard.h
 * @date  30-December-2020
 * @brief SDCard configuration and access.
 *
 * @author
 * @author
 */


#ifndef SDCARD_H
#define SDCARD_H


#include "setup.h"
#include "spi.h"
#include "custom_types.h"


/**
 * @brief Useful characteristics.
 */


/**
 * @brief  Basic configuration structure.
 */
//typedef struct{
//  //IIC_Port_t   Port;         /*!< IIC pins for physical connection*/
//  uint16_t     Address;      /*!< 7 bits IIC address */
//  //IIC_PullUp_t PullUpOption;
//}SDCARD_Parameters_t;


//extern LOGGER_Functions_t SDCARD_Functions;


/**
 * @brief  Initializes internal peripherals.
 * @retval EStatus_t
 * @note This routine only initializes the internal hardware and is not enough
 *       for full device usage; the SDCARD_ExtHwConfig has to be called as
 *       well.
 */
EStatus_t SDCARD_IntHwInit( void );


/**
 * @brief  Initializes external peripheral.
 * @retval EStatus_t
 *@note  This routine only configures the device hardware and is not enough
 *       for full device usage; the SDCARD_IntHwInit must be called first.
 */
EStatus_t SDCARD_ExtHwConfig( void );


/**
 * @brief  This routine reads data from memory.
 * @param  DataBuffer : Variable where data read will be stored.
 * @param  Sector : Sector within the memory.
 * @param  NumberOfSectors : Number of sectors to read.
 * @retval EStatus_t
 */
EStatus_t SDCARD_Read(uint8_t *DataBuffer, uint32_t Sector,
    uint32_t NumberOfSectors);


/**
 * @brief  This routine writes data to memory.
 * @param  DataBuffer : Variable where data to write is stored.
 * @param  Sector : Sector within the memory.
 * @param  NumberOfSectors : Number of sectors to read.
 * @retval EStatus_t
 */
EStatus_t SDCARD_Write(uint8_t *DataBuffer, uint32_t Sector,
    uint32_t NumberOfSectors);


/**
 * @brief  This routine returns the specifications for the device.
 * @param  Pixel: byte to send.
 * @retval EStatus_t
 */
EStatus_t SDCARD_ReadSpecs( /* MEM_specs_t *Specs */ void);

#endif  /* SDCARD_H */
