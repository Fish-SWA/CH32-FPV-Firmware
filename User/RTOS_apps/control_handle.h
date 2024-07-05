#ifndef  CONTROL_HANDLE_H
#define CONTROL_HANDLE_H

#include "FreeRTOS.h"
#include "task.h"
#include "control_handle.h"
#include "pwm.h"
#include "pid.h"
#include "Crsf.h"
#include "IMU_handle.h"
#include "../General_Files/drivers/MTF01.h"

/*调度参数*/
#define CONRTOL_PERIOD  10  //控制周期，单位ms

extern void control_handle_task(void *pvParameters);


/*控制参数*/

#define single_Fly_Pitch_Zero  0.0f
#define single_Fly_Roll_Zero   0.0f
#define single_Fly_Yaw_Zero    0.0f



#define ELRS_Throttle       CrsfChannels[2]
#define ELRS_Pitch          CrsfChannels[1]
#define ELRS_Yaw            CrsfChannels[3]
#define ELRS_Roll           CrsfChannels[0]

#define ELRS_mode           CrsfChannels[6]
#define ELRS_Control_mode   CrsfChannels[5]
#define ELRS_Throttle_lock  CrsfChannels[4]
//#define ELRS_XXX            CrsfChannels[5]
//#define ELRX_XXX            CrsfChannels[7]

//控制模式
enum
{
    PID_CONTROL_MODE = 1,   //电机�?速为PID输出
    RAW_CONTROL_MODE,       //电机�?速直接为油门输入（debug模式�?
    STABLE_CONTROL_MODE     //不可控，�?稳模�?
};

//电机模式
enum
{
    MOTOR_NORMAL = 1,       //正常模式
    MOTOR_SOFT_STARTING     //正在缓启动中
};

//全局变量
typedef struct
{
    float Mech_zero_yaw;    // yaw轴机械零点，因为需要更新所以是变量
    u8 is_locked;           // 电机�?
    u8 flight_mode;         //飞�?�模�?
    u8 is_landing;          //�?动降�?

    PID_STRUCT PID_yaw_outerloop;
    PID_STRUCT PID_yaw_innerloop;
    PID_STRUCT PID_pitch_outerloop;
    PID_STRUCT PID_pitch_innerloop;
    PID_STRUCT PID_roll_outerloop;
    PID_STRUCT PID_roll_innerloop;
    PID_STRUCT MTF01_roll_outerloop;
    PID_STRUCT MTF01_roll_innerloop;
    PID_STRUCT MTF01_pitch_outerloop;
    PID_STRUCT MTF01_pitch_innerloop;
    PID_STRUCT MTF01_height_positionloop;

    uint16_t PWM_Out1;         // 最终作用到电机1的PWM
    uint16_t PWM_Out2;         // 最终作用到电机2的PWM
    uint16_t PWM_Out3;         // 最终作用到电机3的PWM
    uint16_t PWM_Out4;         // 最终作用到电机4的PWM

    float Yaw;
    float Pitch;
    float Roll;
    float MTF01_roll_agnle;
    float MTF01_pitch_agnle;
    uint16_t Throttle;
    int CONTROL_MODE;    //控制模式设定
    int MOTOR_MODE;      //电机模式设定
}Control_TypeDef;


//电机缓启动相�?
#define SOFT_START_TIME 300 //缓启动时间，ms

#define IMU_SAMPLE_SIZE 4 //IMU平均值滤波器大小

// �?�?
#define Angle_I_Limit 200
#define Gyro_I_Limit  200

// ELRS数据�?换到角度数据：ELRS_data*ELRS2angle=angle�?30/(1811-1000)=0.037
#define ELRS2angle    0.06
// ELRS数据�?换到油门数据：ELRS_data*ELRS2throttle=throttle�?1440/1711=0.8416
#define ELRS2throttle 0.55  // 不是0.8419�?因为留一点油门给飞机调整姿�?
//#define ELRS2throttle 0.92  // 不是0.8419�?因为留一点油门给飞机调整姿�?


// 最大倾斜角度，还�?换算
#define MAX_ROLL_ANGLE  20
#define MAX_PITCH_ANGLE 20

// 机�?�零点，需要调
#define Mech_zero_pitch  0
#define Mech_zero_roll   0


// 需要给飞机姿态调整�?�留PWM，所以油门为100时不能达�?7200占空�?
// 油门达到100时，PWM�? 100*PWM_OIL
#define PWM_OIL 45

// 处于Locked状态时，油门和pid�?禁用
#define Locked    1
#define Unlocked  0

// 飞�?�模式，无控制，�?稳，GPS模式
#define Free    0
#define Stable  1
#define GPS     2

//调试架子有阻尼，调试架测出来的参数需要给一�?衰减
#define damp_rate   0.55

// 机动，降�?
#define landing      1
#define not_landing  0

//定高（mm�?
#define stable_height 700

extern Control_TypeDef control;

extern void Stop_motor();


void control_handle_task(void *pvParameters);
void PIDSTRUCT_Init();
float ELRS_Convert_angle(int ELRS_data);
u16 ELRS_Convert_throttle(unsigned ELRS_data);
void ELRS_Convert_flight_mode();
void ELRS_Convert_lock();
void Update_ELRS();
void Roll_outerloop_ctr(float angle_num);
void Roll_innerloop_ctr();
void Yaw_outerloop_ctr(float angle_num);
void Yaw_innerloop_ctr();
void Pitch_outerloop_ctr(float angle_num);
void Pitch_innerloop_ctr();
void Flight_control();
void Stop_motor();
void Check_control_mode();
void control_para_init();
float angle2rad(float angle);



#endif
