/*
 * OS.h
 *
 * Created: 8/28/2021 1:41:39 PM
 *  Author: Ahmed Nabil
 */ 


#ifndef OS_H_
#define OS_H_

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- INCLUDES *-*-*-*-*-*/
#include "OS_Cfg.h"
#include "Microcontroller/Interrupt Handler/Interrupt_Interface.h"
#include "Microcontroller/Std_types.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- CONSTANTS *-*-*-*-*-*/
/*- Constants for the state of the OS -*/
#define OS_STATE_NOT_INITIALIZED				0U
#define OS_STATE_INITIALIZED					1U
#define OS_STATE_RUNNING						2U



/*- Primitive Types
-------------------------------*/
/*- Typedef for the State of the OS -*/
typedef uint8_t OS_State_t;

/*- Typedef to the Tick of the system -*/
typedef uint32_t OS_Tick_t;

/*- Typedef to the Unique ID of the task -*/
typedef uint8_t OS_TaskID_t;

/*- Typedef to the Priority of the task -*/
typedef uint8_t OS_TaskPriority_t;

/*- Typedef to the Periodicity of the task -*/
typedef uint16_t OS_TaskPeriodicity_t;

/*- Typedef to the Function Pointer of the task -*/
typedef Std_ReturnType (*OS_TaskFunctionPtr_t)(void);

/*- Typedef to the State of the task -*/
typedef uint8_t OS_TaskState_t;

typedef float32_t OS_CPU_Load_t;
/*- STRUCTS AND UNIONS Typedef -------------------------------------*/

/*- Typedef to the runtime information of the task -*/
typedef struct
{
	OS_TaskID_t Task_ID;
	OS_TaskPriority_t Task_Priority;
	OS_TaskPeriodicity_t Task_Period;
	OS_TaskFunctionPtr_t Task_mainFunction;
	OS_TaskState_t Task_State;
	OS_Tick_t Task_nextStartTick;
	OS_TaskID_t Ready_Index;
	#if OS_CALC_TASK_EXE_TIME == TRUE
	OS_Tick_t Task_ExecutionTime;
	OS_CPU_Load_t Task_Utilization;
	#endif
}OS_TaskInfo_t;



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/*- Function used to start the OS -*/
Std_ReturnType OS_Start(void);

/*- Function used to create task to join the OS Scheduler -*/
Std_ReturnType OS_createTask(OS_TaskID_t *createdTask_ID, OS_TaskFunctionPtr_t createdTask_Function,
							OS_TaskPeriodicity_t createdTask_Period, OS_TaskPriority_t createdTask_Priority);

/*- Function used to assign a new priority to a given task -*/
Std_ReturnType OS_setTaskPriority(OS_TaskID_t givenTask_ID, OS_TaskPriority_t givenTask_Priority);

/*- Function used to assign a new periodicity to a given task -*/
Std_ReturnType OS_setTaskPeriodicity(OS_TaskID_t givenTask_ID, OS_TaskPeriodicity_t givenTask_Period);

/*- Function used to suspend a task from the scheduler -*/
Std_ReturnType OS_SuspendTask(OS_TaskID_t givenTask_ID);

/*- Function used to resume a suspended task to join the scheduler -*/
Std_ReturnType OS_ResumeTask(OS_TaskID_t givenTask_ID);

/*- Function used to get the current tick count of the OS -*/
Std_ReturnType OS_getTickCount(OS_Tick_t *Tick_Count);





/* Configuration Extern Variable */

#endif /* OS_H_ */