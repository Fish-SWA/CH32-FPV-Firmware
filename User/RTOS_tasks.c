#include "RTOS_tasks.h"
#include "uart.h"

TaskHandle_t TESTTask_Handler;
TaskHandle_t PrintTask_Handler;


void RTOS_init();
void test_task(void *pvParameters);

void RTOS_init()
{
    //测试线程
    // xTaskCreate((TaskFunction_t )test_task,
    //                 (const char*    )"test",
    //                 (uint16_t       )TEST_STK_SIZE,
    //                 (void*          )NULL,
    //                 (UBaseType_t    )TEST_TASK_PRIO,
    //                 (TaskHandle_t*  )&TESTTask_Handler);

    //串口调试线程
    xTaskCreate((TaskFunction_t )print_status,
                    (const char*    )"test",
                    (uint16_t       )PRINT_STK_SIZE,
                    (void*          )NULL,
                    (UBaseType_t    )PRINT_TASK_PRIO,
                    (TaskHandle_t*  )&PrintTask_Handler);
    
    vTaskStartScheduler();
}

void test_task(void *pvParameters)
{
    while(1)
    {
        printf("task1 entry\r\n");
        GPIO_SetBits(GPIOA, GPIO_Pin_8);
        vTaskDelay(100);
        GPIO_ResetBits(GPIOA, GPIO_Pin_8);
        vTaskDelay(100);
    }
}