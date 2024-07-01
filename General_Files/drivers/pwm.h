#ifndef  __PWM_H_
#define __PWM_H_


#define PWM_MODE1   0
#define PWM_MODE2   1

#define PWM_THROTTLE_MAX 2880           //���PWMռ�ձ�
#define PWM_THROTTLE_MIN 1440           //��СPWMռ�ձ� 
#define PWM_THROTTLE_MIN_ROTATE 1650    //�õ��ת������С����
#define PWM_CLOSE_LOOP_CONTROL_ENABLE   1750 //����pid���Ƶ�����

// define mode1���������¼�����mode2�����ϼ���
#define PWM_MODE PWM_MODE1
//#define PWM_MODE PWM_MODE2

// �������궨�壬��֤50Hz��ռ�ձȴ�0���ŵ������ţ���Ӧ1~2ms
#define Max_duty           7200       // PWM�������������ռ�ձ�
#define PWM_Prescaler      50           // TIM9��Ƶϵ��
#define PWM_CCR            1440       // TIM9�Ƚϲ���Ĵ���

void TIM9_PWMOut_Init( u16 arr, u16 psc, u16 ccp );
void PWM_Init(void);
void Motor_ctr(u16 pwm, u8 n);
void Motor_ctr_SOFT_START(u16 pwm, u8 n);

extern int Motor_pos[4];

#endif
