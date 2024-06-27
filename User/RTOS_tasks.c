/****************************RTOS_tasks.c***************************************
���ڴ����͹���RTOS�߳�

������̵߳ķ�����
1.��RTOS_apps����Ӷ�Ӧ��.c��.h�ļ�������д���߳�������
2.��RTOS_tasks.c������һ��TaskHandle_t�ṹ�壬������RTOS_tasks.h�й涨���̵߳����ȼ���ջ�ռ�
3.��RTOS_tasks.c��include�̶߳�Ӧ��.h�ļ�
4.��RTOS_init()������̵߳ĳ�ʼ������

*******************************************************************************/

#include "RTOS_tasks.h"
/*�߳��ļ�*/
#include "RTOS_apps/soft_start.h"
#include "RTOS_apps/Print_status.h"
#include "RTOS_apps/control_handle.h"
#include "RTOS_apps/IMU_handle.h"


TaskHandle_t PrintTask_Handler;
TaskHandle_t Motor_SoftStart_Handler;
TaskHandle_t Control_task_Handler;
TaskHandle_t IMU_Task_Handler;


void RTOS_init();
void test_task(void *pvParameters);

void RTOS_init()
{
    //�����߳�
    // xTaskCreate((TaskFunction_t )test_task,
    //                 (const char*    )"test",
    //                 (uint16_t       )TEST_STK_SIZE,
    //                 (void*          )NULL,
    //                 (UBaseType_t    )TEST_TASK_PRIO,
    //                 (TaskHandle_t*  )&TESTTask_Handler);

    //���ڵ����߳�
    xTaskCreate((TaskFunction_t )Print_status_task,
                (const char*    )"uart",
                (uint16_t       )PRINT_STK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )PRINT_TASK_PRIO,
                (TaskHandle_t*  )&PrintTask_Handler);
    
    // ����������߳�
    xTaskCreate((TaskFunction_t )Motor_sort_start,
                (const char*    )"Soft",
                (uint16_t       )SoftStart_SIZE,
                (void*          )NULL,
                (UBaseType_t    )SoftStart_PRIO,
                (TaskHandle_t*  )&Motor_SoftStart_Handler);

    //�ɻ������߳�
    xTaskCreate((TaskFunction_t )control_handle_task,
                (const char*    )"control",
                (uint16_t       )ControlHandle_SIZE,
                (void*          )NULL,
                (UBaseType_t    )ControlHandle_PRIO,
                (TaskHandle_t*  )&Control_task_Handler);

    //IMU�߳�
    xTaskCreate((TaskFunction_t )IMU_task,
                (const char*    )"imu",
                (uint16_t       )IMU_SIZE,
                (void*          )NULL,
                (UBaseType_t    )IMU_PRIO,
                (TaskHandle_t*  )&IMU_Task_Handler);
    vTaskStartScheduler();
}

/*���Ժ���*/
void test_task(void *pvParameters)
{
    while(1)
    {
        printf("TEST_Called\n");
        vTaskDelay(5);
    }
}

