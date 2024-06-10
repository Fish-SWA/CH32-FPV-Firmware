#ifndef  CONTROL_HANDLE_H
#define CONTROL_HANDLE_H

#include "FreeRTOS.h"
#include "task.h"
#include "control.h"
#include "pwm.h"


#define CONRTOL_PERIOD  10  //控制周期，单位ms

extern void control_handle_task(void *pvParameters);

#endif