/*
 * rtos_config.h
 *
 *  Created on: 16 sep. 2020
 *      Author: alberto
 */

#ifndef RTOS_CONFIG_H_
#define RTOS_CONFIG_H_

/*! @brief Tick period */
#define RTOS_TIC_PERIOD_IN_US 		(1000)

/*! @brief Stack size for each task */
#define RTOS_STACK_SIZE				(500)

/*! @brief Max number of tasks for runtime */
#define RTOS_MAX_NUMBER_OF_TASKS	(10)

/*! @brief Is alive configuration */
#define RTOS_ENABLE_IS_ALIVE
#ifdef RTOS_ENABLE_IS_ALIVE
/*! @brief Is alive signal port */
#define RTOS_IS_ALIVE_PORT			E
/*! @brief Is alive signal pin */
#define RTOS_IS_ALIVE_PIN			6
/*! @brief Is alive signal period */
#define RTOS_IS_ALIVE_PERIOD_IN_US  (1000000)
#endif

#endif /* RTOS_CONFIG_H_ */
