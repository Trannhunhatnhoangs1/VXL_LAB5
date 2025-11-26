/*
 * global.h
 *
 *  Created on: 26 Nov 2025
 *      Author: dell pro
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <stdio.h>
#include "main.h"
#include "software_timer.h"

// global initial state
#define INIT		0
// FOR PARSER FSM
#define _			1
#define _R			2
#define _RS			3
#define _RST		4
#define _RST_		5

#define END			10
#define O			11
#define OK			12

// FOR COMMUNICATION FSM
#define SEND		21
#define WAIT		22

// FOR UART
#define MAX_BUFFER_SIZE 30

extern uint8_t temp;
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern uint8_t buffer[MAX_BUFFER_SIZE];

extern int parser_status;
extern int message_status;



#endif /* INC_GLOBAL_H_ */
