/*
 * task.c
 *
 *  Created on: 26 Nov 2025
 *      Author: dell pro
 */


#include "task.h"

void TASK_Init(void) {
    SCH_Add_Task(Task_Blink, 0, 2000);
    SCH_Add_Task(Task_TimerRun, 0, 10);
    SCH_Add_Task(Task_FSM_Community, 0, 500);
    SCH_Add_Task(Task_FSM_Parser, 1, 100);
}
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

