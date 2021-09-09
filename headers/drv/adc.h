/**
 * @file  adc.h
 * @date  18-December-2020
 * @brief ADC configuration and access.
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
 * @brief Max number of ADC IDs.
 */
#ifndef ADC_MAX_ID
#define ADC_MAX_ID                                                             3
#endif

/**
 * @brief List of hardware ADC ports.
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
 * @brief  ADC Clock Prescaler enumeration.
 */
typedef enum
{
  ADC_CLOCK_DIV2      = (0x00000000U),
  ADC_CLOCK_DIV4      = (0x1U << 16U),
  ADC_CLOCK_DIV6      = (0x2U << 16U),
  ADC_CLOCK_DIV8      = (0x3U << 16U)
}ADC_Prescaler_t;

/**
 * @brief  ADC Channel Sampling Time enumeration.
 */
typedef enum
{
  ADC_SAMPLE_TIME_3CYCLES      = (0x00000000U),
  ADC_SAMPLE_TIME_15CYCLES     = (0x1U),
  ADC_SAMPLE_TIME_28CYCLES     = (0x2U),
  ADC_SAMPLE_TIME_56CYCLES     = (0x3U),
  ADC_SAMPLE_TIME_84CYCLES     = (0x4U),
  ADC_SAMPLE_TIME_112CYCLES    = (0x5U),
  ADC_SAMPLE_TIME_144CYCLES    = (0x6U),
  ADC_SAMPLE_TIME_480CYCLES    = (0x7U),
}ADC_Channel_Sampling_Time_t;

/**
 * @brief  ADC Resolution enumeration.
 */
typedef enum
{
  ADC_12_BITS     = (0x00000000U),
  ADC_10_BITS     = (0x1U << 24U),
  ADC_8_BITS      = (0x2U << 24U),
  ADC_6_BITS      = (0x3U << 24U),
}ADC_Resolution_t;

/**
 * @brief  ADC Configuration structure.
 */
typedef struct
{
  ADC_Port_t                  Port;
  ADC_Channel_t               Channel;
  ADC_Resolution_t            Resolution;

  ADC_Prescaler_t             ClockPrescaler;
  ADC_Channel_Sampling_Time_t ChannelSamplingTime;
}ADC_Parameters_t;


/**
 * @brief  Initialize the internal ADC.
 * @param  ID : ID of the ADC.
 * @param  Parameter : The desired ADC's parameters.
 * @retval EStatus_t
 * @note   This routine will configure the ADC to perform reading on ADC
 *         channels using Interruption.
 */
EStatus_t ADC_Init(uint8_t ID, ADC_Parameters_t Parameter);

/**
 * @brief  Initialize an specified channel of ADC.
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
 * @param  Number_Of_Samples : Number of Samples.
 * @retval EStatus_t
 */
EStatus_t ADC_Read(uint8_t ID, uint32_t *SampleBuffer, uint32_t SampleSize);

#endif /* ADC_H */
