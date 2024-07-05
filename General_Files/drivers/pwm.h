#ifndef  __PWM_H_
#define __PWM_H_


#define PWM_MODE1   0
#define PWM_MODE2   1

#define PWM_THROTTLE_MAX 2880           //最大PWM占空比
#define PWM_THROTTLE_MIN 1440           //最小PWM占空比 
#define PWM_THROTTLE_MIN_ROTATE 1650    //让电机转动的最小油门
#define PWM_CLOSE_LOOP_CONTROL_ENABLE   1650 //启用pid控制的油门

// define mode1锛屽氨鏄?鍚戜笅璁℃暟锛宮ode2鏄?鍚戜笂璁℃暟
#define PWM_MODE PWM_MODE1
//#define PWM_MODE PWM_MODE2

// 璁℃暟鍣ㄥ畯瀹氫箟锛屼繚璇?50Hz锛屽崰绌烘瘮浠?0娌归棬鍒版弧娌归棬锛屽?瑰簲1~2ms
#define Max_duty           7200       // PWM璁℃暟鍣?锛屽嵆鏈�澶у崰绌烘瘮
#define PWM_Prescaler      50           // TIM9鍒嗛?戠郴鏁?
#define PWM_CCR            1440       // TIM9姣旇緝鎹曡幏瀵勫瓨鍣?

void TIM9_PWMOut_Init( u16 arr, u16 psc, u16 ccp );
void PWM_Init(void);
void Motor_ctr(u16 pwm, u8 n);
void Motor_ctr_SOFT_START(u16 pwm, u8 n);

extern int Motor_pos[4];

#endif
