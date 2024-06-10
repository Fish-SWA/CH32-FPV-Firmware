#ifndef  __CONTROL_H_
#define __CONTROL_H_

#include "../apps/inc/pid.h"
#include "../apps/inc/Crsf.h"


#define single_Fly_Pitch_Zero  10.0f;
#define single_Fly_Roll_Zero   3.0f;
#define single_Fly_Yaw_Zero    0.0f;



#define ELRS_Throttle       CrsfChannels[2]
#define ELRS_Pitch          CrsfChannels[1]
#define ELRS_Yaw            CrsfChannels[3]
#define ELRS_Roll           CrsfChannels[0]

#define ELRS_mode           CrsfChannels[6]
#define ELRS_Throttle_lock  CrsfChannels[4]
//#define ELRS_XXX            CrsfChannels[5]
//#define ELRX_XXX            CrsfChannels[7]

//控制模式
enum
{
    PID_CONTROL_MODE = 1,   //电机转速为PID输出
    RAW_CONTROL_MODE        //电机转速直接为油门输入（debug模式）
};

//电机模式
enum
{
    MOTOR_NORMAL = 1,       //正常模式
    MOTOR_SOFT_STARTING     //正在缓启动中
};

//电机缓启动相关
#define SOFT_START_TIME 1000 //缓启动时间，ms

#define IMU_SAMPLE_SIZE 2 //IMU平均值滤波器大小

// 积分
#define Angle_I_Limit 5000
#define Gyro_I_Limit  3000

// ELRS数据转换到角度数据：ELRS_data*ELRS2angle=angle，30/(1811-1000)=0.037
#define ELRS2angle    0.037
// ELRS数据转换到油门数据：ELRS_data*ELRS2throttle=throttle，1440/1711=0.8416
#define ELRS2throttle 0.5  // 不是0.8419是因为留一点油门给飞机调整姿态
//#define ELRS2throttle 0.92  // 不是0.8419是因为留一点油门给飞机调整姿态


// 最大倾斜角度，还未换算
#define MAX_ROLL_ANGLE  30
#define MAX_PITCH_ANGLE 30

// 机械零点，需要调
#define Mech_zero_pitch  0
#define Mech_zero_roll   0


// 需要给飞机姿态调整预留PWM，所以油门为100时不能达到7200占空比
// 油门达到100时，PWM为 100*PWM_OIL
#define PWM_OIL 45

// 处于Locked状态时，油门和pid被禁用
#define Locked    1
#define Unlocked  0

// 飞行模式，无控制，自稳，GPS模式
#define Free    0
#define Stable  1
#define GPS     2

// 机动，降落
#define landing      1
#define not_landing  0


void PIDSTRUCT_Init();
float ELRS_Convert_angle(int ELRS_data);
u16 ELRS_Convert_throttle(unsigned ELRS_data);
void ELRS_Convert_flight_mode();
void ELRS_Convert_lock();
void Update_ELRS();
void Roll_outerloop_ctr();
void Roll_innerloop_ctr();
void Yaw_outerloop_ctr();
void Yaw_innerloop_ctr();
void Pitch_outerloop_ctr();
void Pitch_innerloop_ctr();
void Flight_control();
void Stop_motor();
void Check_control_mode();

extern int CONTROL_MODE;
extern u8 is_locked;
extern int MOTOR_MODE;

extern PID_STRUCT PID_yaw_outerloop;
extern PID_STRUCT PID_yaw_innerloop;
extern PID_STRUCT PID_pitch_outerloop;
extern PID_STRUCT PID_pitch_innerloop;
extern PID_STRUCT PID_roll_outerloop;
extern PID_STRUCT PID_roll_innerloop;

extern u8 is_locked;           // 电机锁
extern u8 flight_mode;         //飞行模式
extern u8 is_landing;          //自动降落
extern uint16_t Throttle;

#endif









