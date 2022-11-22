/*
 * SCH.h
 *
 *  Created on: Nov 9, 2022
 *      Author: Luong
 */

#ifndef INC_SCH_H_
#define INC_SCH_H_
#include "main.h"
typedef struct {
	void (*pTask) (void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
}sTask;

#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0;
sTask SCH_tasks_G[SCH_MAX_TASKS];

extern int current_index_task;

void SCH_Init(void);

void SCH_Add_Task ( void (*pFunction)() ,
					uint32_t DELAY,
					uint32_t PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Tasks(void);

uint8_t SCH_Delete_Task(uint32_t taskID);

#endif /* INC_SCH_H_ */
