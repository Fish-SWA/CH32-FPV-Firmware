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

/*���Ȳ���*/
#define CONRTOL_PERIOD  20  //�������ڣ���λms

extern void control_handle_task(void *pvParameters);


/*���Ʋ���*/

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

//����ģʽ
enum
{
    PID_CONTROL_MODE = 1,   //���ת��ΪPID���
    RAW_CONTROL_MODE,       //���ת��ֱ��Ϊ�������루debugģʽ��
    STABLE_CONTROL_MODE     //���ɿأ�����ģʽ
};

//���ģʽ
enum
{
    MOTOR_NORMAL = 1,       //����ģʽ
    MOTOR_SOFT_STARTING     //���ڻ�������
};

//ȫ�ֱ���
typedef struct
{
    float Mech_zero_yaw;    // yaw���е��㣬��Ϊ��Ҫ���������Ǳ���
    u8 is_locked;           // �����
    u8 flight_mode;         //����ģʽ
    u8 is_landing;          //�Զ�����

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

    uint16_t PWM_Out1;         // �������õ����1��PWM
    uint16_t PWM_Out2;         // �������õ����2��PWM
    uint16_t PWM_Out3;         // �������õ����3��PWM
    uint16_t PWM_Out4;         // �������õ����4��PWM

    float Yaw;
    float Pitch;
    float Roll;
    float MTF01_roll_agnle;
    float MTF01_pitch_agnle;
    uint16_t Throttle;
    int CONTROL_MODE;    //����ģʽ�趨
    int MOTOR_MODE;      //���ģʽ�趨
}Control_TypeDef;


//������������
#define SOFT_START_TIME 600 //������ʱ�䣬ms

#define IMU_SAMPLE_SIZE 5 //IMUƽ��ֵ�˲�����С

// ����
#define Angle_I_Limit 200
#define Gyro_I_Limit  200

// ELRS����ת�����Ƕ����ݣ�ELRS_data*ELRS2angle=angle��30/(1811-1000)=0.037
#define ELRS2angle    0.037
// ELRS����ת�����������ݣ�ELRS_data*ELRS2throttle=throttle��1440/1711=0.8416
#define ELRS2throttle 0.55  // ����0.8419����Ϊ��һ�����Ÿ��ɻ�������̬
//#define ELRS2throttle 0.92  // ����0.8419����Ϊ��һ�����Ÿ��ɻ�������̬


// �����б�Ƕȣ���δ����
#define MAX_ROLL_ANGLE  40
#define MAX_PITCH_ANGLE 40

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

//���Լ��������ᣬ���Լܲ�����Ĳ�����Ҫ��һ��˥��
#define damp_rate   0.60

// ����������
#define landing      1
#define not_landing  0

//���ߣ�mm��
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
