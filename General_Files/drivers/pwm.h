#ifndef  __PWM_H_
#define __PWM_H_


#define PWM_MODE1   0
#define PWM_MODE2   1

#define PWM_THROTTLE_MAX 2880           //最大PWM占空比
#define PWM_THROTTLE_MIN 1440           //最小PWM占空比 
#define PWM_THROTTLE_MIN_ROTATE 1650    //让电机转动的最小油门
#define PWM_CLOSE_LOOP_CONTROL_ENABLE   1750 //启用pid控制的油门

// define mode1，就是向下计数，mode2是向上计数
#define PWM_MODE PWM_MODE1
//#define PWM_MODE PWM_MODE2

// 计数器宏定义，保证50Hz，占空比从0油门到满油门，对应1~2ms
#define Max_duty           7200       // PWM计数器，即最大占空比
#define PWM_Prescaler      50           // TIM9分频系数
#define PWM_CCR            1440       // TIM9比较捕获寄存器

void TIM9_PWMOut_Init( u16 arr, u16 psc, u16 ccp );
void PWM_Init(void);
void Motor_ctr(u16 pwm, u8 n);
void Motor_ctr_SOFT_START(u16 pwm, u8 n);

extern int Motor_pos[4];

#endif
