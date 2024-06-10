#ifndef  PRINT_STATUS>H
#define PRINT_STATUS
#include "debug.h"
#include "uart.h"
#include "stdio.h"
#include "../apps/inc/Crsf.h"
#include "MPU6050.h"
#include "../apps/inc/control.h"
#include "tim.h"
#include "FreeRTOS.h"
#include "task.h"

#define PRINT_DELAY_TIME 50 //��������ļ��

extern void Print_status_task(void *pvParameters);

#endif