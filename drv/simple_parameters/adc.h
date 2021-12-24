/**
 * @file  adc.h
 * @date  18-December-2020
 * @brief Configuration and access to Analog to Digital Converters.
 *
 * @author
 * @author
 */


#ifndef ADC_H
#define ADC_H


#include <stdint.h>
#include "stdstatus.h"
#include "setup.h"


/**
 * @brief Maximum number of ADC IDs, which limits the maximum number of 
 * ADC channels that can be configured by this driver. ADC_MAX_ID can be changed
 * by defining it on setup.h file.
 */
#ifndef ADC_MAX_ID
#define ADC_MAX_ID                                                             3
#endif

/**
 * @brief List of hardware ADCs.
 */
typedef enum
{
  ADC01 = 0,
  ADC02,
  ADC03,
  ADC_NUMBER_OF_PORTS,
}ADC_Port_t;

/**
 * @brief List of ADC channels.
 */
typedef enum
{
  ADC123_CH0_PA0 = 0,
  ADC123_CH1_PA1,
  ADC123_CH2_PA2,
  ADC123_CH3_PA3,
  ADC12_CH4_PA4,
  ADC12_CH5_PA5,
  ADC12_CH6_PA6,
  ADC12_CH7_PA7,
  ADC12_CH8_PB0,
  ADC12_CH9_PB1,
  ADC123_CH10_PC0,
  ADC123_CH11_PC1,
  ADC123_CH12_PC2,
  ADC123_CH13_PC3,
  ADC12_CH14_PC4,
  ADC12_CH15_PC5,
  ADC_NUMBER_OF_CHANNELS,
}ADC_Channel_t;

/**
 * @brief  ADC Resolution enumeration.
 */
typedef enum
{
  ADC_6_BITS = 0,
  ADC_8_BITS,
  ADC_10_BITS,
  ADC_12_BITS,
}ADC_Resolution_t;

/**
 * @brief  ADC Configuration structure.
 */
typedef struct
{
  ADC_Port_t        Port;
  ADC_Channel_t     Channel;
  ADC_Resolution_t  Resolution;
  float             Convertionfrequency;
}ADC_Parameters_t;


/**
 * @brief  Initialize the internal ADC peripheral.
 * @param  ID : ID of the ADC.
 * @param  Parameter : The desired ADC parameters (@ref ADC_Parameters_t).
 * @retval EStatus_t
 * @note   This routine will configure the ADC to perform reading on ADC
 *         channels.
 */
EStatus_t ADC_Init(uint8_t ID, ADC_Parameters_t Parameter);

/**
 * @brief  Configure an specified channel of ADC.
 * @param  ID : ID of the ADC.
 * @param  Channel : Desired channel to enable.
 * @retval EStatus_t
 * @note   This routine will configure the ADC channel, and associates to an ID.
 */
EStatus_t ADC_Setup_Channel(uint8_t ID, ADC_Channel_t Channel);

/**
 * @brief  Read a number of samples from an ADC to a buffer.
 * @param  ID : ID of the channel
 * @param  Buffer : Pointer to the location of storage.
 * @param  BufferSize : Number of Samples.
 * @retval EStatus_t
 */
EStatus_t ADC_Read(uint8_t ID, uint32_t *SampleBuffer, uint32_t BufferSize);

#endif /* ADC_H */
