#include "control_handle.h"



void control_handle_task(void *pvParameters);


void control_handle_task(void *pvParameters)
{
    while(1)
    {
        if(MOTOR_MODE == MOTOR_SOFT_STARTING){
            return;       //如果电机正在缓启动，电机不执行控制
        }

        if(is_locked==Unlocked){
            if(Throttle>=PWM_CLOSE_LOOP_CONTROL_ENABLE){
                Flight_control();
            }
        else if(Throttle<PWM_CLOSE_LOOP_CONTROL_ENABLE){
                Motor_ctr(Throttle,1);
                Motor_ctr(Throttle,2);
                Motor_ctr(Throttle,3);
                Motor_ctr(Throttle,4);
            }
        }
        else{
            Stop_motor();
            pid_func.clc(&PID_roll_outerloop);
            pid_func.clc(&PID_roll_innerloop);
            pid_func.clc(&PID_pitch_outerloop);
            pid_func.clc(&PID_pitch_innerloop);
            pid_func.clc(&PID_yaw_outerloop);
            pid_func.clc(&PID_yaw_innerloop);
        }
        printf("control_handle_called!\n");     //!Debug
        vTaskDelay(CONRTOL_PERIOD);
    }
}

