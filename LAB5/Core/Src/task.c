/*
 * task.c
 *
 *  Created on: 26 Nov 2025
 *      Author: dell pro
 */


#include "task.h"


void Task_Blink(void)
{
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}


void Task_TimerRun(void)
{
    timerRun();
}

void Task_FSM_Community(void)
{
    uart_communiation_fsm();
}

void Task_FSM_Parser(void)
{
	  if (buffer_flag) {
	        command_parser_fsm();
	        buffer_flag = 0;
	    }
}

