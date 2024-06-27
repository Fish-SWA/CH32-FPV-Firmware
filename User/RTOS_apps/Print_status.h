#ifndef  PRINT_STATUS
#define PRINT_STATUS
#include "debug.h"
#include "uart.h"
#include "stdio.h"
#include "../apps/inc/Crsf.h"
#include "MPU6050.h"
#include "control_handle.h"
#include "tim.h"
#include "FreeRTOS.h"
#include "task.h"
#include "IMU_handle.h"
#include "MTF01.h"

#define PRINT_DELAY_TIME 10 //两次输出的间隔

extern void Print_status_task(void *pvParameters);
extern MICOLINK_PAYLOAD_RANGE_SENSOR_t payload;
#endif
