/**
 * @file  sys_cfg_stm32f407.h
 * @date  09-December-2020
 * @brief System Clock and System Tick configuration.
 *
 * This header file contains the prototypes for clock and tick
 * timer configuration.
 *
 * @author
 * @author
 */

#ifndef SYS_CFG_STM32F407_H
#define SYS_CFG_STM32F407_H

#include <stdint.h>


/**
 * @brief Enable various clock interfaces.
 * @param  None
 * @retval None
 */
void SYS_EnablePeripheralsClock(void);

/**
 * @brief Configure the system clock to 168MHz
 * @param  None
 * @retval None
 */
void SYS_ConfigureClock168MHzExt(void);

/**
 * @brief Configure the system clock to 168MHz by HSI
 * @param  None
 * @retval None
 */
void SYS_ConfigureClock168MHzInt(void);

/**
 * @brief Set the system clock to reset default values
 * @param  None
 * @retval None
 */
void SYS_DeInitClock(void);

/**
 * @brief Enable the External Low Speed oscillator 32.678KHz
 * @param  None
 * @retval None
 */
void SYS_EnableLSE(void);

/**
 * @brief Return the system tick counter (milliseconds counter)
 * @param  None
 * @retval System millisecond tick value
 */
uint32_t SYS_GetTick(void);

#endif /* SYS_CFG_STM32F407_H */
