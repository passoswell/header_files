/**
 * @file  ssd1306.h
 * @date  02-May-2016
 * @brief SSD1306 display configuration and access, character display only.
 *
 * @author Iago Pattas
 * @author Wellington Passos
 * @author
 */


#ifndef SSD1306_H
#define SSD1306_H


#include "setup.h"
#include "iic.h"
#include "custom_types.h"


/**
 * @brief Maximum number of SSD1306 display devices allowed.
 */
#ifndef SSD1306_MAX_ID
#define SSD1306_MAX_ID                                                         1
#endif


/**
 * @brief Useful characteristics.
 */
#define SSD1306_H_CHAR_SIZE                                                   16
#define SSD1306_V_CHAR_SIZE                                                    4
#define SSD1306_MAX_CHAR_SIZE        (SSD1306_H_CHAR_SIZE * SSD1306_V_CHAR_SIZE)
#define SSD1306_H_PIXELS                                                     128
#define SSD1306_V_PIXELS                                                      64
#define SSD1306_H_BITS_PER_WRITE                                               1
#define SSD1306_V_BITS_PER_WRITE                                               8
#define SSD1306_H_BYTE_PER_COL       (SSD1306_H_PIXELS/SSD1306_H_BITS_PER_WRITE)
#define SSD1306_V_BYTE_PER_ROW       (SSD1306_V_PIXELS/SSD1306_V_BITS_PER_WRITE)


/**
 * @brief List of possible IIC addresses (see datasheet).
 */
enum SSD1306_IICAddress{
  SSD1306_0x3C = 0x3C,
  SSD1306_0x3D = 0x3D,
};


/**
 * @brief  Basic configuration structure.
 */
typedef struct{
  IIC_Port_t   Port;         /*!< IIC pins for physical connection*/
  uint16_t     Address;      /*!< 7 bits IIC address */
  IIC_PullUp_t PullUpOption;
}SSD1306_Parameters_t;


extern Display_Functions_t SSD1306_Functions;


/**
 * @brief  SSD1306 IIC  peripheral initialization routine.
 * @param  ID : ID for device used.
 * @param  Parameter : Pointer to the desired configuration parameters
 * @retval EStatus_t
 * @note This routine only initializes the internal hardware and is not enough
 *       for full device usage; the SSD1306_ExtHwConfig has to be called as
 *       well.
 */
EStatus_t SSD1306_IntHwInit( uint8_t ID, SSD1306_Parameters_t Parameter );


/**
 * @brief  SSD1306 device initialization routine.
 * @param  ID : ID for device used.
 * @retval EStatus_t
 *@note  This routine only configures the device hardware and is not enough
 *       for full device usage; the SSD1306_IntHwInit must be called first.
 */
EStatus_t SSD1306_ExtHwConfig( uint8_t ID );


/**
 * @brief  This routine sets the cursor on the desired position.
 * @param  ID : ID for device used.
 * @param  StartRow: The desired row.
 * @param  StartCol: The desired column.
 * @retval EStatus_t
 */
EStatus_t SSD1306_SetCursor( uint8_t ID, uint8_t Row, uint8_t Col );


/**
 * @brief  This routine sends a character to the desired position.
 * @param  ID : ID for device used.
 * @param  Row: The desired row.
 * @param  Col: The desired column.
 * @param  Char2Send: The character to send.
 * @param  Color: The desired color, a number between 0 and 1.
 * @retval EStatus_t
 */
EStatus_t SSD1306_SendChar( uint8_t ID, uint8_t Row, uint8_t Col,
    uint8_t Char2Send, uint8_t Color );


/**
 * @brief  This routine sends a text to the display.
 * @param  ID : ID for device used.
 * @param  SendBuffer: Pointer to the text location.
 * @param  Sendlength: Text size in bytes.
 * @param  StartRow: The desired row.
 * @param  StartCol: The desired column.
 * @param  Char2Send: The character to send.
 * @param  Color: The desired color, a number between 0 and 1.
 * @retval EStatus_t
 */
EStatus_t SSD1306_SendString( uint8_t ID, uint8_t *SendBuffer,
    uint32_t SendLength, uint8_t Row, uint8_t Col, uint8_t Color );


/**
 * @brief  This routine clears the display.
 * @param  ID : ID for device used.
 * @param  Color : The desired color, a number between 0 and 1.
 * @retval EStatus_t
 */
EStatus_t SSD1306_ClearScreen( uint8_t ID, uint8_t Color );


/**
 * @brief  This routine draws a pixel on the display.
 * @param  ID : ID for device used.
 * @param  Pixel: byte to send.
 * @retval EStatus_t
 */
EStatus_t SSD1306_DrawPixels(uint8_t ID, uint8_t *SendBuffer,
    uint32_t SendLength, uint8_t Row, uint8_t Col);


/**
 * @brief  This routine returns the specifications for the display.
 * @param  ID : ID for device used.
 * @param  Pixel: byte to send.
 * @retval EStatus_t
 */
EStatus_t SSD1306_ReadSpecs(Display_specs_t *Specs);

#endif  /* SSD1306_H */
