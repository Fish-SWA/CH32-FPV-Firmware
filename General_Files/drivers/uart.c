
#include "debug.h"
#include "uart.h"
#include "stdio.h"
#include "../apps/inc/Crsf.h"
#include "../General_Files/drivers/uart.h"
#include "MPU6050.h"
#include "../apps/inc/control.h"

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
    HandleByteReceived();
    USART_ClearFlag(USARTx, USART_IT_RXNE);
//    USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE);
}

void print_status()
{
    printf("yaw=%f\r\n",MPU6050_para.yaw);
    printf("pitch=%f\r\n",MPU6050_para.pitch);
    printf("roll=%f\r\n",MPU6050_para.roll);
    printf("av_yaw=%d\r\n",MPU6050_para.av_yaw);
    printf("av_pitch=%d\r\n",MPU6050_para.av_pitch);
    printf("av_roll=%d\r\n",MPU6050_para.av_roll);
//    printf("temp=%f\r\n\n",MPU6050_Get_Temp());
    printf("PWM1:%d\r\n",TIM_GetCapture1(TIM9));
    printf("PWM2:%d\r\n",TIM_GetCapture2(TIM9));
    printf("PWM3:%d\r\n",TIM_GetCapture3(TIM9));
    printf("PWM4:%d\r\n\n",TIM_GetCapture4(TIM9));
    if(flight_mode==GPS){
        printf("flight_mode:GPS\r\n");
    }
    else if(flight_mode==Stable){
        printf("flight_mode:Stable\r");
    }
    else{
        printf("flight_mode:Free\r\n");
    }
    if(is_locked == Unlocked){
        printf("Throttle Unlocked\r\n");
    }
    else{
        printf("Throttle Locked\r\n");
    }
//        Delay_Ms(100);
//        printf("ch1:%d\r\n",CrsfChannels[0]);
//        printf("ch2:%d\r\n",CrsfChannels[1]);
//        printf("ch3:%d\r\n",CrsfChannels[2]);
//        printf("ch4:%d\r\n",CrsfChannels[3]);
//        printf("ch5:%d\r\n",CrsfChannels[4]);
//        printf("ch6:%d\r\n",CrsfChannels[5]);
//        printf("ch7:%d\r\n",CrsfChannels[6]);
//        printf("ch8:%d\r\n",CrsfChannels[7]);
//        printf("ch9:%d\r\n",CrsfChannels[8]);
//        printf("ch10:%d\r\n",CrsfChannels[9]);
//        printf("ch11:%d\r\n",CrsfChannels[10]);
//        printf("ch12:%d\r\n\n",CrsfChannels[11]);


}



