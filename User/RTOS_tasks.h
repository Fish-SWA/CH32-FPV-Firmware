#include "FreeRTOS.h"
#include "task.h"

/* �̲߳��� */
#define TEST_TASK_PRIO       4
#define TEST_TASK_SIZE       256
#define PRINT_TASK_PRIO      3
#define PRINT_STK_SIZE       256
#define SoftStart_PRIO       4
#define SoftStart_SIZE       256
#define ControlHandle_PRIO   0
#define ControlHandle_SIZE   1536
#define IMU_PRIO             2
#define IMU_SIZE             1024

extern void RTOS_init();
