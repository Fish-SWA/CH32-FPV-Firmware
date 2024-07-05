#ifndef  __PWM_H_
#define __PWM_H_


#define PWM_MODE1   0
#define PWM_MODE2   1

#define PWM_THROTTLE_MAX 2880           //���PWMռ�ձ�
#define PWM_THROTTLE_MIN 1440           //��СPWMռ�ձ� 
#define PWM_THROTTLE_MIN_ROTATE 1650    //�õ��ת������С����
#define PWM_CLOSE_LOOP_CONTROL_ENABLE   1650 //����pid���Ƶ�����

// define mode1，就�?向下计数，mode2�?向上计数
#define PWM_MODE PWM_MODE1
//#define PWM_MODE PWM_MODE2

// 计数器宏定义，保�?50Hz，占空比�?0油门到满油门，�?�应1~2ms
#define Max_duty           7200       // PWM计数�?，即最大占空比
#define PWM_Prescaler      50           // TIM9分�?�系�?
#define PWM_CCR            1440       // TIM9比较捕获寄存�?

void TIM9_PWMOut_Init( u16 arr, u16 psc, u16 ccp );
void PWM_Init(void);
void Motor_ctr(u16 pwm, u8 n);
void Motor_ctr_SOFT_START(u16 pwm, u8 n);

extern int Motor_pos[4];

#endif
