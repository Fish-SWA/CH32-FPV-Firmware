/****************************Print_status.c***************************************
�������Ļ����У���ֹ�����������ҵ�

����⵽�������ʱ������ռ����Ŀ���Ȩ���ѵ����ת�ٻ������������ٺ����ͷſ���Ȩ


*******************************************************************************/

#include "soft_start.h"
#include "FreeRTOS.h"
#include "task.h"
#include "drivers/pwm.h"
#include "control.h"

int last_RC_lock_state = Locked;	//��һ������״̬
float Motor_speed_set = PWM_THROTTLE_MIN; //����ֵ�趨

void Motor_sort_start(void *pvParameters);

/*�������߳�*/
void Motor_sort_start(void *pvParameters)
{
    while(1)
    {
        if(is_locked == Unlocked && last_RC_lock_state == Locked){	//���������ʱ��
            printf("MOTOR UNLOCKED!!!!\n");
            last_RC_lock_state = Unlocked;
            MOTOR_MODE = MOTOR_SOFT_STARTING;	//�л���������ģʽ

            for(int i=0; i<SOFT_START_TIME; i++){	//�������߼�
                Motor_speed_set = ((((float)PWM_THROTTLE_MIN_ROTATE-(float)PWM_THROTTLE_MIN)/(float)SOFT_START_TIME))*i + PWM_THROTTLE_MIN;
                    Motor_ctr_SOFT_START(Motor_speed_set, 1);
                    Motor_ctr_SOFT_START(Motor_speed_set, 2);
                    Motor_ctr_SOFT_START(Motor_speed_set, 3);
                    Motor_ctr_SOFT_START(Motor_speed_set, 4);
                vTaskDelay(1);
            }

            printf("MOTOR OK!!!!\n");
            MOTOR_MODE = MOTOR_NORMAL; //�л�������ģʽ
        }

        if(is_locked == Locked){
            last_RC_lock_state = Locked;
            MOTOR_MODE = MOTOR_NORMAL;
            Stop_motor();
        }

        vTaskDelay(10);    //10ms����һ��
    }

}
