
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

extern u8 is_locked;           // 电机锁
extern u8 flight_mode;         //飞行模式
extern u8 is_landing;          //自动降落

void USART2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));


void USARTx_CFG(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    NVIC_InitTypeDef  NVIC_InitStructure = {0};

    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2 , ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 串口2
    /* USART2 TX-->A.2   RX-->A.3 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

//    // 串口3
//    /* USART3 TX-->B.10  RX-->B.11 */
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//    GPIO_Init(GPIOB, &GPIO_InitStructure);
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//    GPIO_Init(GPIOB, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 420000;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;



//    USART_Init(USART3, &USART_InitStructure);
//    USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);

    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

//    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);

    USART_Cmd(USART2, ENABLE);
    USART_Init(USART2, &USART_InitStructure);
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
}


//void USART2_IRQHandler(void)
//{
//
//    if(USART_GetITStatus(USART2,USART_IT_RXNE) != RESET && USART_GetFlagStatus(USART2, USART_FLAG_RXNE) != RESET)
//    {
//        RxBuffer[0]=USART_ReceiveData(USART2);
//        RxBuf[RxBuf_Index++] = RxBuffer[0];
//        HandleByteReceived();
//        if (RxBuf_Index == (sizeof(RxBuf)/sizeof(RxBuf[0])))
//        {
//            RxBuf_Index = 0;
//        }
//
//        USART_ClearFlag(USART2, USART_IT_RXNE);
//
////        USART_ITConfig(USART2, USART_IT_RXNE, DISABLE);
////        USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
//
//    }
////    else if(USART_GetITStatus(USART2,USART_IT_IDLE) != RESET)
////    {
////        USART_ReceiveData(USART2);
////        isUsart2RxFlag = true;
////    }
//
//}




void USART2_IRQHandler(void)
{

    if(USART_GetITStatus(USART2,USART_IT_RXNE) != RESET && USART_GetFlagStatus(USART2, USART_FLAG_RXNE) != RESET)
    {
        UART_RxCpltCallback(USART2);
    }
}

void UART_RxCpltCallback(USART_TypeDef *USARTx)
{
    RxBuf[RxBuf_Index++] =USART_ReceiveData(USARTx);

    if (RxBuf_Index == (sizeof(RxBuf)/sizeof(RxBuf[0])))
    {
        RxBuf_Index = 0;
    }
    if(IMU_IO_STATUS == IMU_IO_IDLE) HandleByteReceived();  //仅在IMU不读写时解包
    USART_ClearFlag(USARTx, USART_IT_RXNE);
//    USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);
}



