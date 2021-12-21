/**
 * @file  pit.h
 * @date  01-November-2020
 * @brief Configuration and access to Periodic Interruption Timers.
 *
 * This header file contains the prototypes for configuration and access
 * of software timers.
 *
 * @author
 * @author
 */


#ifndef PIT_H
#define PIT_H

#include <stdint.h>
#include "stdstatus.h"
#include "setup.h"


/**
 * @brief Maximum number of PIT IDs, which limits the maximum number of 
 * software timers that can be configured by this driver. PIT_MAX_ID can be
 * changed by defining it on setup.h file.
 */
#ifndef PIT_MAX_ID
#define PIT_MAX_ID                                                            10
#endif


/**
 * @brief Timer units enumeration
 */
typedef enum
{
  PIT_MILLISECONDS, /*!< Specifies the unit of milliseconds to the counter. */
} PIT_TimeUnit_t;


/**
 * @brief  Start time counting routine.
 * @param  ID : Requester's ID
 * @param  CountsToPerform : How many ticks to count
 * @param  Unit : Tick's time base.
 *         This parameter can be one of the following values:
 *             @arg PIT_Millisec: Counter is set to milliseconds base.
 * @retval void.
 * @note   This routine will start a time counting operation. If it was already
 *       counting time for this ID the previous operation will be aborted.
 *       Use the Get_Timer routine to check if the given period has passed.
 */
EStatus_t PIT_Set(uint8_t ID, uint32_t CountsToPerform, PIT_TimeUnit_t Unit);

/**
 * @brief  Routine that checks if the requested time has passed.
 * @param  ID : Requester's ID
 * @retval Result : Result of Operation.
 *         This parameter can be one of the following values:
 *         @arg ANSWERED_REQUEST: All ok, time is being counted
 *         @arg OPERATION_RUNNING: Time has not passed yet, keep waiting.
 *         @arg Else: Some error happened.
 *
 */
EStatus_t PIT_Get(uint8_t ID);

/**
 * @brief  Stop driver's operation.
 * @retval Result : Result of Operation.
 *         This parameter can be one of the following values:
 *         @arg ANSWERED_REQUEST: All ok, time is being counted
 *         @arg Else: Some error happened.
 * @note   This routine will stop the PIT driver, making it not count the time
 * periods anymore. This is usually called before entering stop mode so
 * that the driver's interrupts doesn't wake up the device.
 */
EStatus_t PIT_Halt(void);

/**
 * @brief  Resume driver's operation.
 * @retval Result : Result of Operation.
 *         This parameter can be one of the following values:
 *         @arg ANSWERED_REQUEST: All ok, time is being counted
 *         @arg Else: Some error happened.
 * @note   This routine will resume the PIT driver, making it able to do its
 * operations again. It is usually called after a wake up event.
 */
EStatus_t PIT_Resume(void);

#endif  /* __PIT_H */
