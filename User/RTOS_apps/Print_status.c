/****************************Print_status.c***************************************
从调试串口输出无人机的信�?


*******************************************************************************/
#include "Print_status.h"

void Print_status_task(void *pvParameters);
void Graph_print();
void String_print();
extern MICOLINK_PAYLOAD_RANGE_SENSOR_t payload_filtered;
extern MICOLINK_PAYLOAD_RANGE_SENSOR_t payload;
extern float compensate_factor;
void Print_status_task(void *pvParameters)
{
    while(1)
    {
    
    // Graph_print();
    String_print();

    vTaskDelay(PRINT_DELAY_TIME);

    }
}

void Graph_print()
{


    printf("d: %d, %d, %d, %d, %f, %f, %f\r\n", TIM_GetCapture2(TIM9),
            TIM_GetCapture3(TIM9),
            TIM_GetCapture1(TIM9),
            TIM_GetCapture4(TIM9),
            MPU6050_para_filted.yaw,
            MPU6050_para_filted.pitch,
            MPU6050_para_filted.roll);
}

void String_print()
{

//    return;
    printf("MTF01_roll_agnle:%f\r\n",control.MTF01_roll_agnle);
    printf("MTF01_pitch_agnle:%f\r\n",control.MTF01_pitch_agnle);
    printf("statues:%d\r\n",payload.tof_status);

    printf("compensate_factor=%f\r\n",compensate_factor);
    printf("xPortGetMinimumEverFreeHeapSize = %d\r\n",xPortGetMinimumEverFreeHeapSize());   //剩余堆空�?

    printf("yaw_filted=%f\r\n",MPU6050_para_filted.yaw);
    printf("pitch_filted=%f\r\n",MPU6050_para_filted.pitch);
    printf("roll_filted=%f\r\n",MPU6050_para_filted.roll);

    printf("av_yaw_filted=%d\r\n",MPU6050_para_filted.av_yaw);
    printf("av_pitch_filted=%d\r\n",MPU6050_para_filted.av_pitch);
    printf("av_roll_filted=%d\r\n",MPU6050_para_filted.av_roll);

    printf("yaw_outer_loop=%f\r\n",control.PID_yaw_outerloop.out);
    printf("roll_outer_loop=%f\r\n",control.PID_roll_outerloop.out);
    printf("pitch_outer_loop=%f\r\n",control.PID_pitch_outerloop.out);

    printf("yaw_out=%f\r\n",control.PID_yaw_innerloop.out);
    printf("roll_out=%f\r\n",control.PID_roll_innerloop.out);
    printf("pitch_out=%f\r\n",control.PID_pitch_innerloop.out);


    printf("PWM1:%d\r\n",TIM_GetCapture2(TIM9));    //对应实际�?2号电�?
    printf("PWM2:%d\r\n",TIM_GetCapture3(TIM9));    //3
    printf("PWM3:%d\r\n",TIM_GetCapture4(TIM9));    //4
    printf("PWM4:%d\r\n",TIM_GetCapture1(TIM9));    //1
    if(control.flight_mode==GPS){
        printf("flight_mode:GPS\r\n");
    }
    else if(control.flight_mode==Stable){
        printf("flight_mode:Stable\r\n");
    }
    else{
        printf("flight_mode:Free\r\n");
    }

    if(control.is_locked == Unlocked){
        printf("Throttle Unlocked\r\n");
    }
    else{
        printf("Throttle Locked\r\n");
    }

    printf("distance:%d\r\n",payload_filtered.distance);
    printf("Px:%f\r\n",payload_filtered.Px);
    printf("Py:%f\r\n",payload_filtered.Py);
    printf("Vx:%f\r\n",payload_filtered.Vx);
    printf("Vy:%f\r\n",payload_filtered.Vy);

    if(control.CONTROL_MODE == PID_CONTROL_MODE){
        printf("Control_mode:PID\r\n\n");
    }else if(control.CONTROL_MODE == RAW_CONTROL_MODE){
        printf("Control_mode:RAW\r\n\n");
    }else if(control.CONTROL_MODE == STABLE_CONTROL_MODE){
        printf("Control_mode:Stable\r\n\n");
    }
}

//    printf("d: %d, %d, %d, %d, %f, %f, %f\r\n", TIM_GetCapture2(TIM9),
//            TIM_GetCapture3(TIM9),
//            TIM_GetCapture1(TIM9),
//            TIM_GetCapture4(TIM9),
//            MPU6050_para_filted.yaw,
//            MPU6050_para_filted.pitch,
//            MPU6050_para_filted.roll);


//    printf("ch1:%d\r\n",CrsfChannels[0]);
//    printf("ch2:%d\r\n",CrsfChannels[1]);
//    printf("ch3:%d\r\n",CrsfChannels[2]);
//    printf("ch4:%d\r\n",CrsfChannels[3]);
//    printf("ch5:%d\r\n",CrsfChannels[4]);
//    printf("ch6:%d\r\n",CrsfChannels[5]);
//    printf("ch7:%d\r\n",CrsfChannels[6]);
//    printf("ch8:%d\r\n",CrsfChannels[7]);
//    printf("ch9:%d\r\n",CrsfChannels[8]);
//    printf("ch10:%d\r\n",CrsfChannels[9]);
//    printf("ch11:%d\r\n",CrsfChannels[10]);
//    printf("ch12:%d\r\n\n",CrsfChannels[11]);

// printf("yaw=%f\r\n",MPU6050_para.yaw);
// printf("pitch=%f\r\n",MPU6050_para.pitch);
// printf("roll=%f\r\n",MPU6050_para.roll);
// printf("av_yaw=%d\r\n",MPU6050_para.av_yaw);
// printf("av_pitch=%d\r\n",MPU6050_para.av_pitch);
// printf("av_roll=%d\r\n",MPU6050_para.av_roll);



