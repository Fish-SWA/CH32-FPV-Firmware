#include "debug.h"
#include "pwm.h"
#include "../apps/inc/Crsf.h"
#include "../apps/inc/control.h"

int Motor_pos[4] = {2, 3, 1, 4}; //电机的ID映射

void TIM9_PWMOut_Init( u16 arr, u16 psc, u16 ccp )
{
    GPIO_InitTypeDef GPIO_InitStructure={0};
    TIM_OCInitTypeDef TIM_OCInitStructure={0};
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure={0};

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOD | RCC_APB2Periph_TIM9 | RCC_APB2Periph_AFIO, ENABLE );
    GPIO_PinRemapConfig(GPIO_FullRemap_TIM9, ENABLE);                  //TIM9完全映射

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_11 | GPIO_Pin_13 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init( GPIOD, &GPIO_InitStructure );

    TIM_TimeBaseInitStructure.TIM_Period = arr;
    TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit( TIM9, &TIM_TimeBaseInitStructure);

#if (PWM_MODE == PWM_MODE1)
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;

#elif (PWM_MODE == PWM_MODE2)
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;

#endif

    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = ccp;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

    // 初始化各个通道
    TIM_OC1Init( TIM9, &TIM_OCInitStructure );
    TIM_OC2Init( TIM9, &TIM_OCInitStructure );
    TIM_OC3Init( TIM9, &TIM_OCInitStructure );
    TIM_OC4Init( TIM9, &TIM_OCInitStructure );
    TIM_CtrlPWMOutputs(TIM9, ENABLE );
    TIM_OC1PreloadConfig( TIM9, TIM_OCPreload_Disable );
    TIM_OC2PreloadConfig( TIM9, TIM_OCPreload_Disable );
    TIM_OC3PreloadConfig( TIM9, TIM_OCPreload_Disable );
    TIM_OC4PreloadConfig( TIM9, TIM_OCPreload_Disable );
    TIM_ARRPreloadConfig( TIM9, ENABLE );
    TIM_Cmd( TIM9, ENABLE );
}


void PWM_Init()
{
    TIM9_PWMOut_Init(Max_duty, PWM_Prescaler-1, 1000);
    TIM_SetCompare1(TIM9,PWM_THROTTLE_MIN);    //初始最低油门
    TIM_SetCompare2(TIM9,PWM_THROTTLE_MIN);
    TIM_SetCompare3(TIM9,PWM_THROTTLE_MIN);
    TIM_SetCompare4(TIM9,PWM_THROTTLE_MIN);
}

void Motor_ctr(u16 pwm, u8 n)
{
    int motor_id_fix = 0;
    if(pwm<=PWM_THROTTLE_MIN){  //限制输入幅度
     pwm=PWM_THROTTLE_MIN;
    }else if(pwm>=PWM_THROTTLE_MAX){  //限制输入幅度
     pwm=PWM_THROTTLE_MAX;
    }else if(pwm<=PWM_THROTTLE_MIN_ROTATE){     //不让电机处于不能流畅转动的区间
     pwm=PWM_THROTTLE_MIN;
    }

    /*当解锁电机的时候，强制电机转速处于怠速以上*/
    if(is_locked == Unlocked && pwm<PWM_THROTTLE_MIN_ROTATE){
        pwm=PWM_THROTTLE_MIN_ROTATE;
    }

    /*!Debug 验证电机ID*/
    //if(n != 3) pwm=PWM_THROTTLE_MIN;
    /*修正电机ID*/
    motor_id_fix = Motor_pos[n-1];

    /*缓启动时禁用*/
    if(MOTOR_MODE == MOTOR_SOFT_STARTING){
        return;
    }


    switch (motor_id_fix)
    {
        case 1:
            TIM_SetCompare1(TIM9,pwm);  //1号电机
            break;
        case 2:
            TIM_SetCompare2(TIM9,pwm);  //2号电机
            break;
        case 3:
            TIM_SetCompare3(TIM9,pwm);  //3号电机
            break;
        case 4:
            TIM_SetCompare4(TIM9,pwm);  //3号电机
            break;
        default:
            break;
    }
}

/*仅在缓启动模式使用*/
void Motor_ctr_SOFT_START(u16 pwm, u8 n)
{
    int motor_id_fix;
    if(pwm<=PWM_THROTTLE_MIN){  //限制输入幅度
     pwm=PWM_THROTTLE_MIN;
    }else if(pwm>=PWM_THROTTLE_MAX){  //限制输入幅度
     pwm=PWM_THROTTLE_MAX;
    }
    motor_id_fix = Motor_pos[n-1];
    switch (motor_id_fix)
    {
        case 1:
            TIM_SetCompare1(TIM9,pwm);  //1号电机
            break;
        case 2:
            TIM_SetCompare2(TIM9,pwm);  //2号电机
            break;
        case 3:
            TIM_SetCompare3(TIM9,pwm);  //3号电机
            break;
        case 4:
            TIM_SetCompare4(TIM9,pwm);  //3号电机
            break;
        default:
            break;
    }
}





