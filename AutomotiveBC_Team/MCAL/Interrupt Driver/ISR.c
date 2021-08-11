/*****************************************************************************
* Module: Interrupt Module
* File Name: ISR.h
* Description: Source file for Interrupt Module
* Author: Mohamed Magdy
* Date: 14-July-2021
******************************************************************************/
#include "ISR.h"

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
static volatile uint32_t gu32_OvfCounts = Initial_Value;

static pfINT0_CallBack_t ExtInt0Callback;


/*- Function Definitions
-------------------------------*/
void EnableGlobalInterrupts(void)
{
	SET_BIT(SREG_R, GLOBAL_INT);
}

void DisableGlobalInterrupts(void)
{
	CLEAR_BIT(SREG_R, GLOBAL_INT);
}

void EnableExternalInterrupts_INT0(uint8_t senseControl)
{
	SET_BIT(GICR_R, INT0_B);
	switch(senseControl)
	{
		case(LOW_LEVEL):
		{
			CLEAR_BIT(MCUCR_R, ISC00_B);
			CLEAR_BIT(MCUCR_R, ISC00_B);
			break;
		}
		case(LOGIC_CHANGE):
		{
			SET_BIT(MCUCR_R, ISC00_B);
			CLEAR_BIT(MCUCR_R, ISC00_B);
			break;
		}
		case(FALLING_EDGE):
		{
			CLEAR_BIT(MCUCR_R, ISC00_B);
			SET_BIT(MCUCR_R, ISC00_B);
			break;
		}
		case(RISING_EDGE):
		{
			SET_BIT(MCUCR_R, ISC00_B);
			SET_BIT(MCUCR_R, ISC00_B);
			break;
		}					
	}
	EnableGlobalInterrupts();
}

void DisableExternalInterrupts_INT0()
{
	CLEAR_BIT(GICR_R, INT0_B);
}


/*****************************************************************************************
* Parameters (in): pointer to function to be called from ISR
* Parameters (out): None
* Return value: None
* Description: sets the function to be called by external interrupt 0 ISR
******************************************************************************************/
void setExtINT0Callback(pfINT0_CallBack_t FunToBeCalledInISR)
{
	ExtInt0Callback = FunToBeCalledInISR;
	
}

/*****************************************************************************************
* Parameters (in): None
* Parameters (out):None
* Return value: None
* Description: interrupt service routine for external interrupt 0 ISR
******************************************************************************************/
ISR(INT0)
{
	
	ExtInt0Callback();
}
