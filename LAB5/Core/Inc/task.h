/*
 * task.h
 *
 *  Created on: 26 Nov 2025
 *      Author: dell pro
 */

#ifndef INC_TASK_H_
#define INC_TASK_H_

#include "main.h"
#include "scheduler.h"
#include "fsm_communication.h"
#include "fsm_parser.h"
#include "software_timer.h"
#include"global.h"

void TASK_Init(void);
void Task_Blink(void);    // chớp tắt PA5 mỗi 1s
void Task_TimerRun(void);    // gọi timer_run()
void Task_FSM_Community(void);
void Task_FSM_Parser(void);
void Task_check(void);
#endif /* INC_TASK_H_ */
