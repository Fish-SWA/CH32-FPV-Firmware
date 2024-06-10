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

//����ģʽ
enum
{
    PID_CONTROL_MODE = 1,   //���ת��ΪPID���
    RAW_CONTROL_MODE        //���ת��ֱ��Ϊ�������루debugģʽ��
};

//���ģʽ
enum
{
    MOTOR_NORMAL = 1,       //����ģʽ
    MOTOR_SOFT_STARTING     //���ڻ�������
};

//������������
#define SOFT_START_TIME 1000 //������ʱ�䣬ms

#define IMU_SAMPLE_SIZE 2 //IMUƽ��ֵ�˲�����С

// ����
#define Angle_I_Limit 5000
#define Gyro_I_Limit  3000

// ELRS����ת�����Ƕ����ݣ�ELRS_data*ELRS2angle=angle��30/(1811-1000)=0.037
#define ELRS2angle    0.037
// ELRS����ת�����������ݣ�ELRS_data*ELRS2throttle=throttle��1440/1711=0.8416
#define ELRS2throttle 0.5  // ����0.8419����Ϊ��һ�����Ÿ��ɻ�������̬
//#define ELRS2throttle 0.92  // ����0.8419����Ϊ��һ�����Ÿ��ɻ�������̬


// �����б�Ƕȣ���δ����
#define MAX_ROLL_ANGLE  30
#define MAX_PITCH_ANGLE 30

// ��е��㣬��Ҫ��
#define Mech_zero_pitch  0
#define Mech_zero_roll   0


// ��Ҫ���ɻ���̬����Ԥ��PWM����������Ϊ100ʱ���ܴﵽ7200ռ�ձ�
// ���Ŵﵽ100ʱ��PWMΪ 100*PWM_OIL
#define PWM_OIL 45

// ����Locked״̬ʱ�����ź�pid������
#define Locked    1
#define Unlocked  0

// ����ģʽ���޿��ƣ����ȣ�GPSģʽ
#define Free    0
#define Stable  1
#define GPS     2

// ����������
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

extern u8 is_locked;           // �����
extern u8 flight_mode;         //����ģʽ
extern u8 is_landing;          //�Զ�����
extern uint16_t Throttle;

#endif









