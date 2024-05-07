#ifndef  __PWM_H_
#define __PWM_H_


#define PWM_MODE1   0
#define PWM_MODE2   1

// define mode1，就是向下计数，mode2是向上计数
#define PWM_MODE PWM_MODE1
//#define PWM_MODE PWM_MODE2

// 计数器宏定义，保证50Hz，占空比从0油门到满油门，对应1~2ms
#define Max_duty           28800       // PWM计数器，即最大占空比
#define PWM_Prescaler      50           // TIM9分频系数
#define PWM_CCR            1440       // TIM9比较捕获寄存器

void TIM9_PWMOut_Init( u16 arr, u16 psc, u16 ccp );
void PWM_Init(void);
void Motor_ctr(u16 pwm, u8 n);

#endif
