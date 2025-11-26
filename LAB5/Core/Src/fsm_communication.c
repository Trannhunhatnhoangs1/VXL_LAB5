/*
 * fsm_comunication.c
 *
 *  Created on: 25 Nov 2025
 *      Author: dell pro
 */
#include "fsm_communication.h"


extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;

void uart_communiation_fsm() {
    static char str[50];

    switch (message_status) {
    case INIT:
        break;
    case SEND:
        {
            int ADC_value = HAL_ADC_GetValue(&hadc1);
            int len = sprintf(str, "!ADC=%d\r\n", ADC_value);
            HAL_UART_Transmit(&huart2, (void *)str, len, 1000);
            setTimer1(3000);
            message_status = WAIT;
        }
        break;
    case WAIT:
        if (timer1_flag) message_status = SEND;
        break;
    default:
        break;
    }
}
