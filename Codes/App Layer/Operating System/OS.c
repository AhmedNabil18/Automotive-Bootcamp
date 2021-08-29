/*
 * OS.c
 *
 * Created: 8/28/2021 1:41:24 PM
 *  Author: Ahmed Nabil
 */ 

/*- INCLUDES
----------------------------------------------*/
#include "OS.h"


/*- CONSTANTS
----------------------------------------------*/

/*- Constants for the Task states -*/
#define OS_TASK_STATE_READY					0x0AU
#define OS_TASK_STATE_RUNING				0x0BU
#define OS_TASK_STATE_BLOCKED				0x0CU
#define OS_TASK_STATE_CLOSED				0x0DU
#define OS_TASK_STATE_SUSPENDED				0x0EU

/*- Factor of changing Second to Microsecond -*/
#define OS_SECOND_TO_MICRO_SEC				1000000UL


/*- GLOBAL EXTERN VARIABLES -------------------------------------*/
/*- Global static Variable for the Tick counter of the OS -*/
volatile OS_Tick_t OS_TickCount = 0;

/*- Global Static Variable for the State of the OS -*/
OS_State_t OS_CurrentState = OS_STATE_NOT_INITIALIZED;

/*- Global Static Variable for the Tasks counter -*/
OS_TaskID_t OS_TasksCounter = 0;

/*- Global Static Variable for the Ready Tasks counter -*/
OS_TaskID_t OS_ReadyTasksCounter = 0;

/*- Global static variable for the current task index -*/
OS_TaskID_t OS_currentTaskIndex = 0;

/*- Global static array for the subscribed tasks -*/
OS_TaskInfo_t OS_Tasks[OS_MAX_TASKS_NUM];

/*- Global static variable for the number of OVF Counts -*/
uint8_t OS_GptOVFCount = 0;

/*- Global static variable for the initial counter value -*/
uint32_t OS_GptInitialCounterValue = 0;

/*- Global static variable used to count the OVF events from the timer -*/
uint8_t OVF_Counter = 0;

/*- Flag used to Enable and Disable the Idle Task -*/
volatile uint8_t Idle_Flag = FALSE;

/*- Global Static variable used to save the duration of the Idle task -*/
volatile OS_Tick_t OS_IdleTask_Duration = 0;

/*- Global Static flag used to indicate a tick increment -*/
uint8_t tickChange = TRUE;

OS_Tick_t OS_CPU_Load_Frame = OS_CPU_LOAD_TIME_FRAME;

OS_CPU_Load_t OS_CPU_Load = 0;

/*- Static Functions -------------------------------------*/
void OS_IdleTask(void);

#if 0
void OS_IdleTask(void)
{
	OS_IdleTask_Duration++;
	Idle_Flag = TRUE;
	while (Idle_Flag == TRUE)
	{
	}
}
#else
void OS_IdleTask(void)
{
	OS_Tick_t firstTick=0, lastTick=0;
	OS_getTickCount(&firstTick);
	Idle_Flag = TRUE;
	while (Idle_Flag == TRUE)
	{
	}
	OS_getTickCount(&lastTick);
	OS_IdleTask_Duration += (lastTick - firstTick);
}
#endif

/************************************************************************************
* Parameters (in): None
* Parameters (out): Error Status
* Return value: Std_ReturnType
* Description: Function to be passed as callback to the timer to count the ticks.
************************************************************************************/
static void OS_tickCounter(uint8_t Int_Vect_Num)
{
	if(OS_GptOVFCount == 0)
	{
		/* Increase the OS Tick counter */
		OS_TickCount++;
		OS_CPU_Load_Frame--;
		tickChange = TRUE;
		/* Reset the counter with the initial value to start counting */
		Gpt_setCounterValue(OS_TIMER_CHANNEL_ID, OS_GptInitialCounterValue);
		
		/* Check if any of the blocked tasks will be ready */
		uint8_t taskCounter = 0;
		for (taskCounter=0; taskCounter<OS_TasksCounter; taskCounter++)
		{
			/* Check if the blocked task next start tick is the current tick count */
			if((OS_Tasks[taskCounter].Task_State == OS_TASK_STATE_BLOCKED)
				&& (OS_Tasks[taskCounter].Task_nextStartTick == OS_TickCount))
			{
				/* Assign the new next ready tick of the task */
				OS_Tasks[taskCounter].Task_nextStartTick = OS_TickCount + OS_Tasks[taskCounter].Task_Period;
				/* Make the task ready */
				OS_Tasks[taskCounter].Task_State = OS_TASK_STATE_READY;
				/* Increment the counter of the ready tasks */
				OS_ReadyTasksCounter++;
				/* Assign the turn of this task in the ready queue */
				OS_Tasks[taskCounter].Ready_Index = OS_ReadyTasksCounter;
				
				Idle_Flag = FALSE;
			}
			else
			{
				
			}
		}
	}
	else
	{
		if (OVF_Counter == 0)
		{
			OS_TickCount++;
			OS_CPU_Load_Frame--;
			tickChange = TRUE;
			OVF_Counter = OS_GptOVFCount;
			Gpt_setCounterValue(OS_TIMER_CHANNEL_ID, OS_GptInitialCounterValue);
			
			/* Check if any of the blocked tasks will be ready */
			uint8_t taskCounter = 0;
			for (taskCounter=0; taskCounter<OS_TasksCounter; taskCounter++)
			{
				/* Check if the blocked task next start tick is the current tick count */
				if((OS_Tasks[taskCounter].Task_State == OS_TASK_STATE_BLOCKED)
				&& (OS_Tasks[taskCounter].Task_nextStartTick == OS_TickCount))
				{
					/* Assign the new next ready tick of the task */
					OS_Tasks[taskCounter].Task_nextStartTick = OS_TickCount + OS_Tasks[taskCounter].Task_Period;
					/* Make the task ready */
					OS_Tasks[taskCounter].Task_State = OS_TASK_STATE_READY;
					/* Increment the counter of the ready tasks */
					OS_ReadyTasksCounter++;
					/* Assign the turn of this task in the ready queue */
					OS_Tasks[taskCounter].Ready_Index = OS_ReadyTasksCounter;
				}
				else
				{
					
				}
			}
		} 
		else
		{
			OVF_Counter--;
		}
	}
}

/************************************************************************************
* Parameters (in): None
* Parameters (out): Error Status
* Return value: Std_ReturnType
* Description: Implement the OS Initialization.
************************************************************************************/
static Std_ReturnType OS_Init(void)
{
	/*- Initialize the Gpt Module -*/
	GptInit();
	/*- Calculate the initial counter value to achieve the required tick timer -*/
	OS_GptInitialCounterValue = ((SYS_CLOCK_FREQUENCY/(strGpt_Channels[OS_TIMER_CHANNEL_ID].u8_Prescaler))/OS_TICKS_PER_SECOND);
	/*- Check if the Counter value is smaller than the max value of the timer counter register -*/
	if (OS_GptInitialCounterValue < OS_TIMER_COUNTER_MAX_VALUE)
	{
		OS_GptInitialCounterValue = OS_TIMER_COUNTER_MAX_VALUE - OS_GptInitialCounterValue;
	} 
	else
	{
		float32_t f32_TempValue = (float32_t)OS_GptInitialCounterValue/OS_TIMER_COUNTER_MAX_VALUE;
		OS_GptOVFCount = f32_TempValue;
		f32_TempValue -= OS_GptOVFCount;
		OS_GptInitialCounterValue = OS_TIMER_COUNTER_MAX_VALUE - (uint32_t)(f32_TempValue * OS_TIMER_COUNTER_MAX_VALUE);
		OVF_Counter = OS_GptOVFCount;
	}
	
	/* Enable the Global Interrupt */
	EnableGlobalInterrupts();
	/* Enable the interrupt notification of the overflow of the timer */
	Gpt_EnableNotification_OVF(OS_TIMER_CHANNEL_ID, OS_tickCounter);
	/* Start timer */
	Gpt_Start(OS_TIMER_CHANNEL_ID, OS_GptInitialCounterValue);
	
	
	/* Change the state of the OS to initialized */
	OS_CurrentState = OS_STATE_INITIALIZED;
	return E_OK;
}

/************************************************************************************
* Parameters (in): None
* Parameters (out): Error Status
* Return value: Std_ReturnType
* Description: The main function of the OS.
************************************************************************************/
static Std_ReturnType OS_mainFunction(void)
{
	uint8_t taskCounter = 0;
	uint8_t firstEntry = FALSE;
	while (1)
	{
		if(tickChange == TRUE)
		{
			tickChange = FALSE;
			firstEntry = TRUE;
			if(OS_ReadyTasksCounter > 0)
			{
				for(taskCounter=0; taskCounter<OS_TasksCounter; taskCounter++)
				{
					/* Check for the ready tasks */
					if(OS_Tasks[taskCounter].Task_State == OS_TASK_STATE_READY)
					{
						if(firstEntry == TRUE)
						{
							firstEntry = FALSE;
							OS_currentTaskIndex = taskCounter;
						}
						/* Check the highest priority */
						if(OS_Tasks[taskCounter].Task_Priority > OS_Tasks[OS_currentTaskIndex].Task_Priority)
						{   /* In case of the priority of the counter task greater than the current Task */
							OS_currentTaskIndex = taskCounter;
						}
						else if (OS_Tasks[taskCounter].Task_Priority < OS_Tasks[OS_currentTaskIndex].Task_Priority)
						{
							
						}
						else
						{	/* In case the 2 tasks have the same priority */
							if(OS_Tasks[taskCounter].Ready_Index < OS_Tasks[OS_currentTaskIndex].Ready_Index)
							{	/* Check if the counter task was ready before the current Task*/
								OS_currentTaskIndex = taskCounter;
							}
							else
							{
								
							}
						}
					}
					else
					{
						
					}
				}
				/* Change the state of the task to running */
				OS_Tasks[OS_currentTaskIndex].Task_State = OS_TASK_STATE_RUNING;
				
				#if OS_CALC_TASK_EXE_TIME == TRUE
				/* Get the current tick count */
				OS_Tick_t Task_ExeTime = OS_TickCount;
				#endif
				
				/* Run the chosen task */
				OS_Tasks[OS_currentTaskIndex].Task_mainFunction();
				
				#if OS_CALC_TASK_EXE_TIME == TRUE
				/* Get the execution time of the task */
				Task_ExeTime = OS_TickCount - Task_ExeTime;
				if (Task_ExeTime == 0)
				{
					Task_ExeTime = 1;
				}
				/* Save the worst case execution time of the task */
				if(Task_ExeTime > OS_Tasks[OS_currentTaskIndex].Task_ExecutionTime)
				{
					OS_Tasks[OS_currentTaskIndex].Task_ExecutionTime = Task_ExeTime;
				}
				/* Calculate the utilization of the task */
				OS_Tasks[OS_currentTaskIndex].Task_Utilization = ((float32_t)100*Task_ExeTime)/OS_Tasks[OS_currentTaskIndex].Task_Period;
				#endif
				
				/* Change the state of the task to blocked */
				OS_Tasks[OS_currentTaskIndex].Task_State = OS_TASK_STATE_BLOCKED;
				OS_ReadyTasksCounter--;
			}
			else
			{
				/* Sleep */
				OS_IdleTask();
			}
			if(OS_CPU_Load_Frame == 0)
			{
				OS_CPU_Load_Frame = OS_CPU_LOAD_TIME_FRAME;
				OS_CPU_Load = ((float32_t)(OS_CPU_LOAD_TIME_FRAME - OS_IdleTask_Duration)/OS_CPU_LOAD_TIME_FRAME)*100;
				OS_IdleTask_Duration = 0;
			}
		}
		else
		{
			
		}
	}
	return E_OK;
}




/*- LOCAL FUNCTIONS IMPLEMENTATION ------------------------*/
/************************************************************************************
* Parameters (in): None
* Parameters (out): Error Status
* Return value: Std_ReturnType
* Description: Start the operating system Initialization and main function.
************************************************************************************/
Std_ReturnType OS_Start(void)
{
	/* Initialize the System */
	if(E_NOT_OK == OS_Init())
	{
		return E_NOT_OK;
	}
	else
	{
		/* Run the scheduler of the OS */
		OS_mainFunction();
	}
	return E_NOT_OK;
}


/************************************************************************************
* Parameters (in): None
* Parameters (out): Error Status
* Return value: Std_ReturnType
* Description: Create a new Task to join the scheduler algorithm.
************************************************************************************/
Std_ReturnType OS_createTask(OS_TaskID_t *createdTask_ID, OS_TaskFunctionPtr_t createdTask_Function,
							 OS_TaskPeriodicity_t createdTask_Period, OS_TaskPriority_t createdTask_Priority)
{
	if(OS_TasksCounter < OS_MAX_TASKS_NUM)
	{	
		/* 
		 * Fill the new task's data inside the tasks array 
		 */
		OS_Tasks[OS_TasksCounter].Task_mainFunction = createdTask_Function;
		OS_Tasks[OS_TasksCounter].Task_Period = createdTask_Period;
		OS_Tasks[OS_TasksCounter].Task_Priority = createdTask_Priority;
		/* Make the task Ready to be run */
		OS_Tasks[OS_TasksCounter].Task_State = OS_TASK_STATE_READY;
		/* Assign the next Ready tick for the task */
		OS_Tasks[OS_TasksCounter].Task_nextStartTick = createdTask_Period;
		/* Assign a new ID to the task */
		*createdTask_ID = OS_TasksCounter;
		/* Assign the ID of the task */
		OS_Tasks[OS_TasksCounter].Task_ID = *createdTask_ID;
		/* Increase the Ready Task counter */
		OS_ReadyTasksCounter++;
		/* Increase the tasks counter */
		OS_TasksCounter = OS_ReadyTasksCounter;
	}
	else
	{
		/* No empty space for a new task*/
		return E_NOT_OK;
	}
	
	return E_OK;
}


/************************************************************************************
* Parameters (in): givenTask_ID - The ID of the task.
*				   givenTask_Priority - The new priority of the task
* Parameters (out): Error Status
* Return value: Std_ReturnType
* Description: Change the priority of a task with the given ID.
************************************************************************************/
Std_ReturnType OS_setTaskPriority(OS_TaskID_t givenTask_ID, OS_TaskPriority_t givenTask_Priority)
{
	/* Check if the task is not closed/deleted */
	if (OS_Tasks[givenTask_ID].Task_State != OS_TASK_STATE_CLOSED)
	{	/* Change the task's priority with the new given one */
		OS_Tasks[givenTask_ID].Task_Priority = givenTask_Priority;
	} 
	else
	{
		return E_NOT_OK;
	}
	return E_OK;	
}


/************************************************************************************
* Parameters (in): givenTask_ID - The ID of the task.
*				   givenTask_Period - The new period of the task
* Parameters (out): Error Status
* Return value: Std_ReturnType
* Description: Change the periodicity of a task with the given ID.
************************************************************************************/
Std_ReturnType OS_setTaskPeriodicity(OS_TaskID_t givenTask_ID, OS_TaskPeriodicity_t givenTask_Period)
{
	/* Check if the task is not closed/deleted */
	if (OS_Tasks[givenTask_ID].Task_State != OS_TASK_STATE_CLOSED)
	{	/* Change the task's periodicity with the new given one */
		OS_Tasks[givenTask_ID].Task_Period = givenTask_Period;
	}
	else
	{
		return E_NOT_OK;
	}
	return E_OK;
}


/************************************************************************************
* Parameters (in): givenTask_ID - The ID of the task to be suspended
* Parameters (out): Error Status
* Return value: Std_ReturnType
* Description: Function used to suspend a task from running.
************************************************************************************/
Std_ReturnType OS_SuspendTask(OS_TaskID_t givenTask_ID)
{
	/* Check if the task is not closed/deleted */
	if ((OS_Tasks[givenTask_ID].Task_State != OS_TASK_STATE_CLOSED)
		&& (OS_Tasks[givenTask_ID].Task_State != OS_TASK_STATE_SUSPENDED))
	{	/* Force Change the task's state to Blocked */
		OS_Tasks[givenTask_ID].Task_State = OS_TASK_STATE_SUSPENDED;
		OS_ReadyTasksCounter--;
	}
	else
	{
		return E_NOT_OK;
	}
	return E_OK;
}

/************************************************************************************
* Parameters (in): givenTask_ID - The ID of the task to be resumed
* Parameters (out): Error Status
* Return value: Std_ReturnType
* Description: Resume a Suspended Task.
************************************************************************************/
Std_ReturnType OS_ResumeTask(OS_TaskID_t givenTask_ID)
{
	/* Check if the task is already SUSPENDED */
	if (OS_Tasks[givenTask_ID].Task_State == OS_TASK_STATE_SUSPENDED)
	{	/* Force Change the task's state to Ready */
		OS_Tasks[givenTask_ID].Task_State = OS_TASK_STATE_READY;
		/* Assign the next start tick for the task */
		OS_Tasks[givenTask_ID].Task_nextStartTick = OS_TickCount + OS_Tasks[givenTask_ID].Task_Period;
		OS_ReadyTasksCounter++;
	}
	else
	{
		return E_NOT_OK;
	}
	return E_OK;
}



/************************************************************************************
* Parameters (in): None
* Parameters (out): Tick_Count - The current tick count
* Return value: Std_ReturnType
* Description: Function used to get the current tick count of the OS.
************************************************************************************/
Std_ReturnType OS_getTickCount(OS_Tick_t *Tick_Count)
{
	if(OS_CurrentState != OS_STATE_NOT_INITIALIZED)
	{
		/* Return the current tickCount of the OS */
		*Tick_Count = OS_TickCount;
	}
	else
	{
		return E_NOT_OK;
	}
	return E_OK;
}