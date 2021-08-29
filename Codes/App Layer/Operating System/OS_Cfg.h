/*
 * OS_Cfg.h
 *
 * Created: 8/28/2021 1:41:56 PM
 *  Author: Ahmed Nabil
 */ 


#ifndef OS_CFG_H_
#define OS_CFG_H_

#include "MCAL/Gpt Module/Gpt.h"

/********* OS CONFIGURATIONS **********/
/*- Max Priority can be assigned to a task (Priority 1 -> OS_MAX_PRIORITY)
 *- Knowing that 1 is the least priority -*/
#define OS_MAX_PRIORITY				10U

/*- The number of ticks in second
 *- @example: 1000 -> 1000 ticks in a second -> 1 tick = 1ms -*/
#define OS_TICKS_PER_SECOND			1000U

/*- Max Number of Tasks uses the OS -*/
#define OS_MAX_TASKS_NUM			3U

/*- Interval to calculate the CPU Load through it -*/
#define OS_CPU_LOAD_TIME_FRAME		500U

/*- MACRO to enable the exe time calculation -*/
#define OS_CALC_TASK_EXE_TIME		FALSE

/********* TIMER CONFIGURATIONS **********/
/*- Timer channel used by the OS for timing -*/
#define OS_TIMER_CHANNEL_ID				TIMER_CHANNEL_0_ID

/*- Timer counter max value -*/
#define OS_TIMER_COUNTER_MAX_VALUE		256U

#endif /* OS_CFG_H_ */