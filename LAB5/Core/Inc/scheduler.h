/*
 * scheduler.h
 *
 *  Created on: 26 Nov 2025
 *      Author: dell pro
 */


#include <stdint.h>

#define SCH_MAX_TASKS   40
#define WHEEL_SIZE      256

extern int TIME_CYCLE;

typedef struct sTask {
    void (*pTask)(void);
    uint32_t Delay;
    uint32_t Period;
    uint8_t  RunMe;
    uint32_t TaskID;

    struct sTask* next;
} sTasks;

void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint32_t SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
uint8_t SCH_Delete_Task(uint32_t taskID);
