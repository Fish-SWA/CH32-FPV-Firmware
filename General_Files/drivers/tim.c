

#include "debug.h"
#include "tim.h"
#include "../General_Files/drivers/MPU6050.h"
#include "../General_Files/drivers/pwm.h"
#include "../apps/inc/control.h"

extern u8 is_locked;           //电机锁
extern u8 flight_mode;         //飞行模式
extern u8 is_landing;          //自动降落
extern float Yaw;
extern float Pitch;
extern float Roll;
extern uint16_t Throttle;

void TIM3_Interrupt_Init(void)
{
   NVIC_InitTypeDef NVIC_InitStructure={0};
   NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn ;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1; //抢占优先级
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        //子优先级
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);
}


void TIM3_Init( u16 arr, u16 psc)
{
   TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;

   RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM3, ENABLE );

   TIM_TimeBaseInitStructure.TIM_Period = arr;
   TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
   TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
   TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Down;
   TIM_TimeBaseInit( TIM3, &TIM_TimeBaseInitStructure);

   TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
   TIM_ARRPreloadConfig( TIM3, ENABLE );
   TIM_Cmd( TIM3, ENABLE );

   TIM3_Interrupt_Init();
}


void TIM3_IRQHandler(void)   __attribute__((interrupt("WCH-Interrupt-fast")));
//volatile uint16_t LED_Status = 0;
void TIM3_IRQHandler(void)
{
    TIM_ClearFlag(TIM3, TIM_FLAG_Update);  //清除标志位
    Update_ELRS();
    if(MPU6050_MPU_DMP_GetData() == RESET)
    {
        if(is_locked==Unlocked){
            if(Throttle>=1600){
                Flight_control();
            }
            else if(Throttle<1600){
                Motor_ctr(Throttle,1);
                Motor_ctr(Throttle,2);
                Motor_ctr(Throttle,3);
                Motor_ctr(Throttle,4);
            }

        }
        else{
            Stop_motor();
        }
        print_status();
    }

}


void TIM4_Interrupt_Init(void)
{
   NVIC_InitTypeDef NVIC_InitStructure={0};
   NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn ;
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //抢占优先级
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        //子优先级
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);
}


void TIM4_Init( u16 arr, u16 psc)
{
   TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;

   RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM4, ENABLE );

   TIM_TimeBaseInitStructure.TIM_Period = arr;
   TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
   TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
   TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Down;
   TIM_TimeBaseInit( TIM4, &TIM_TimeBaseInitStructure);

   TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);
   TIM_ARRPreloadConfig( TIM4, ENABLE );
   TIM_Cmd( TIM4, ENABLE );

   TIM4_Interrupt_Init();
}


void TIM4_IRQHandler(void)   __attribute__((interrupt("WCH-Interrupt-fast")));
//volatile uint16_t LED_Status = 0;
void TIM4_IRQHandler(void)
{
    TIM_ClearFlag(TIM4, TIM_FLAG_Update);//清除标志位
    GPIO_TogglePin(GPIOA, GPIO_Pin_8);
}





















