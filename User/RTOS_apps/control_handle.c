/****************************control_handle.c***************************************
�������˻��Ŀ���

�ɻ������Ӧͼ
       1��    2��
 ��ͷ��   \  /
        /  \
       3��    4��
pwm: ���pwm
n:   ������
*******************************************************************************/

#include "control_handle.h"

/*ȫ�ֱ���*/
#define rate 0.6  //���Լ��������ᣬ���Լܲ�����Ĳ�����Ҫ��һ��˥��

Control_TypeDef control;

void control_handle_task(void *pvParameters); 

void control_handle_task(void *pvParameters)
{
    control_para_init();    //��ʼ��ȫ�ֱ���

    while(1)
    {
        if(control.MOTOR_MODE != MOTOR_SOFT_STARTING){      //���������ڻ������������ִ�п���
            Update_ELRS();
            if(control.is_locked==Unlocked){
                if(control.Throttle>=PWM_CLOSE_LOOP_CONTROL_ENABLE){
                    Flight_control();
                }
            else if(control.Throttle<PWM_CLOSE_LOOP_CONTROL_ENABLE){
                    Motor_ctr(control.Throttle,1);
                    Motor_ctr(control.Throttle,2);
                    Motor_ctr(control.Throttle,3);
                    Motor_ctr(control.Throttle,4);
                }
            }
            else{
                Stop_motor();
                pid_func.clc(&control.PID_roll_outerloop);
                pid_func.clc(&control.PID_roll_innerloop);
                pid_func.clc(&control.PID_pitch_outerloop);
                pid_func.clc(&control.PID_pitch_innerloop);
                pid_func.clc(&control.PID_yaw_outerloop);
                pid_func.clc(&control.PID_yaw_innerloop);
            }
        }
        vTaskDelay(CONRTOL_PERIOD);
    }
}

void PIDSTRUCT_Init()
{
    /*
     * �����ǵĽ��ٶ��ǽ��ٶ�Խ�󣬼Ĵ���ֵԽС�������ڻ���PID�����Ǹ���
     * ������������ֶ���ͨ��ȡ��������PID�����Ǹ�
     */
    //////////////////////////////////////////yaw////////////////////////////////////////
    // ������⻷��ʼ�����ǶȻ���
    pid_func.reset(&control.PID_yaw_outerloop);
    control.PID_yaw_outerloop.Kp=5.0f;
    control.PID_yaw_outerloop.Ki=0.0f;
    control.PID_yaw_outerloop.Kd=0.0f;
    control.PID_yaw_outerloop.max_iout=Angle_I_Limit;
    control.PID_yaw_outerloop.min_iout=-Angle_I_Limit;
    control.PID_yaw_outerloop.max_out=65535;
    control.PID_yaw_outerloop.min_out=-65535;
    control.PID_yaw_outerloop.DeadBand = 0.01;    //PID����
    pid_func.init(&control.PID_yaw_outerloop);      // ��ջ���

    // ������ڻ���ʼ�������ٶȻ���
    pid_func.reset(&control.PID_yaw_innerloop);
    control.PID_yaw_innerloop.Kp=3.4f;
    control.PID_yaw_innerloop.Ki=0.0f;
    control.PID_yaw_innerloop.Kd=0.0f;
    control.PID_yaw_innerloop.max_iout=Gyro_I_Limit;
    control.PID_yaw_innerloop.min_iout=-Gyro_I_Limit;
    control.PID_yaw_innerloop.max_out=65535;
    control.PID_yaw_innerloop.min_out=-65535;
    control.PID_yaw_innerloop.DeadBand=0.01;
    pid_func.init(&control.PID_yaw_innerloop);      // ��ջ���

    ////////////////////////////////////////pitch////////////////////////////////////////
    // �������⻷��ʼ�����ǶȻ���
    pid_func.reset(&control.PID_pitch_outerloop);
    control.PID_pitch_outerloop.Kp=2.7*rate;
    control.PID_pitch_outerloop.Ki=0.05*rate; //-0.12
    control.PID_pitch_outerloop.Kd=5.0*rate;  //-5.3
    control.PID_pitch_outerloop.max_iout=Angle_I_Limit;
    control.PID_pitch_outerloop.min_iout=-Angle_I_Limit;
    control.PID_pitch_outerloop.max_out=65535;
    control.PID_pitch_outerloop.min_out=-65535;
    control.PID_pitch_outerloop.DeadBand = 0.1;    //PID����
    pid_func.init(&control.PID_pitch_outerloop);    // ��ջ���

    // �������ڻ���ʼ�������ٶȻ���
    pid_func.reset(&control.PID_pitch_innerloop);
    control.PID_pitch_innerloop.Kp=4.8*rate;    //2.2
    control.PID_pitch_innerloop.Ki=0.0*rate;    //0.0
    control.PID_pitch_innerloop.Kd=5.9*rate;    //5.7
    control.PID_pitch_innerloop.max_iout=Gyro_I_Limit;
    control.PID_pitch_innerloop.min_iout=-Gyro_I_Limit;
    control.PID_pitch_innerloop.max_out=65535;
    control.PID_pitch_innerloop.min_out=-65535;
    control.PID_pitch_innerloop.DeadBand=1;
    pid_func.init(&control.PID_pitch_innerloop);    // ��ջ���

    //////////////////////////////////////////roll////////////////////////////////////////
    // ������⻷��ʼ�����ǶȻ���
    pid_func.reset(&control.PID_roll_outerloop);
    control.PID_roll_outerloop.Kp=2.7*rate;
    control.PID_roll_outerloop.Ki=0.1*rate;
    control.PID_roll_outerloop.Kd=5.3*rate;
    control.PID_roll_outerloop.max_iout=Angle_I_Limit;
    control.PID_roll_outerloop.min_iout=-Angle_I_Limit;
    control.PID_roll_outerloop.max_out=65535;
    control.PID_roll_outerloop.min_out=-65535;
    control.PID_roll_outerloop.DeadBand=0.01;
    pid_func.init(&control.PID_roll_outerloop);     // ��ջ���

    // ������ڻ���ʼ�������ٶȻ���
    pid_func.reset(&control.PID_roll_innerloop);
    control.PID_roll_innerloop.Kp=4.9*rate;
    control.PID_roll_innerloop.Ki=0.0f;
    control.PID_roll_innerloop.Kd=5.7*rate;
    control.PID_roll_innerloop.max_iout=Gyro_I_Limit;
    control.PID_roll_innerloop.min_iout=-Gyro_I_Limit;
    control.PID_roll_innerloop.max_out=65535;
    control.PID_roll_innerloop.min_out=-65535;
    control.PID_roll_innerloop.DeadBand=1;
    pid_func.init(&control.PID_roll_innerloop);     // ��ջ���
}
//***********************************************************************
// ��ҡ��ֵת��Ϊ�Ƕȣ�ӳ��Ϊ��30��
float ELRS_Convert_angle(int ELRS_data)
{
    float angle;
    if(ELRS_data>1000){
        angle=(ELRS_data-1000)*ELRS2angle;
    }
    else if(ELRS_data<985){
        angle=(ELRS_data-985)*ELRS2angle;
    }
    else {
        angle=0;
    }
    return angle;
}

// ��ҡ��ֵת��Ϊ���ţ�ӳ��Ϊ0~100
u16 ELRS_Convert_throttle(unsigned ELRS_data)
{
    u16 throttle;
    if(ELRS_data<=200){
        throttle=1350;
    }
    else {
        throttle=1350+(u16)(ELRS_data-200)*ELRS2throttle;
    }
    return throttle;
}

// ��ҡ��ֵת��Ϊ�����
void ELRS_Convert_lock()
{
    if (ELRS_Throttle_lock>=1785 && ELRS_Throttle_lock<=1800){
        control.is_locked = Unlocked;
    }
    else {
        control.is_locked = Locked;
    }
}

// ��ҡ��ֵת��Ϊ����ģʽ
void ELRS_Convert_flight_mode()
{
    if (ELRS_mode>=1785 && ELRS_mode<=1800){
        control.flight_mode = GPS;
    }
    else if(ELRS_mode>=990 && ELRS_mode<=1010){
        control.flight_mode = Stable;
    }
    else{
        control.flight_mode = Free;
    }
}

// ���¸���ELRSֵ
void Update_ELRS()
{
    control.Yaw=ELRS_Convert_angle(ELRS_Yaw);
    control.Roll=ELRS_Convert_angle(ELRS_Roll);
    control.Pitch=ELRS_Convert_angle(ELRS_Pitch);
    control.Throttle = ELRS_Convert_throttle(ELRS_Throttle);
    ELRS_Convert_lock();
    ELRS_Convert_flight_mode();
    Check_control_mode(); //ͬ������ģʽ
}

//***********************************************************************
// ��ȡ�ɻ���ǰ״̬���Խ��и��ֶ���



//***********************************************************************
// Roll����
void Roll_outerloop_ctr()
{
    float angle_num=control.Roll + Mech_zero_roll;
    pid_func.calc(&control.PID_roll_outerloop, angle_num, MPU6050_para_filted.roll);
}

void Roll_innerloop_ctr()
{
    pid_func.calc(&control.PID_roll_innerloop, control.PID_roll_outerloop.out, MPU6050_para_filted.av_roll/50.0f);//Debug������50.0f���������٣���������20ms���⻷��λ�Ƕ�ÿ��
//    printf("d: %f, %f", PID_roll_outerloop.out, MPU6050_para_filted.av_roll/1000.0f);
}

// Yaw����
void Yaw_outerloop_ctr()
{
    float angle_num=control.Yaw + control.Mech_zero_yaw;
//    printf("yaw_desired=%f\r\n",angle_num);
    pid_func.calc(&control.PID_yaw_outerloop, angle_num, MPU6050_para_filted.yaw);
}

void Yaw_innerloop_ctr()
{
    pid_func.calc(&control.PID_yaw_innerloop, control.PID_yaw_outerloop.out, -MPU6050_para_filted.av_yaw/50.0f);
}

// Pitch����
void Pitch_outerloop_ctr()
{
    float angle_num=control.Pitch + Mech_zero_pitch;
    pid_func.calc(&control.PID_pitch_outerloop, angle_num, MPU6050_para_filted.pitch);
}

void Pitch_innerloop_ctr()
{
    pid_func.calc(&control.PID_pitch_innerloop, control.PID_pitch_outerloop.out, MPU6050_para_filted.av_pitch/50.0f);
}

// ��ң����ͬ������ģʽ
void Check_control_mode()
{
    if(CrsfChannels[7] == 191){     //��������
        control.CONTROL_MODE = PID_CONTROL_MODE;
    }else if(CrsfChannels[7] == 1792){  //��������
        control.CONTROL_MODE = RAW_CONTROL_MODE;
    }
    
}

void Flight_control()
{
    Roll_outerloop_ctr();
    Roll_innerloop_ctr();

    Pitch_outerloop_ctr();
    Pitch_innerloop_ctr();

    Yaw_outerloop_ctr();
    Yaw_innerloop_ctr();

    control.Mech_zero_yaw = MPU6050_para_filted.yaw;     // ��ֹת����ͷ��0

    control.PWM_Out1=control.Throttle+control.PID_pitch_innerloop.out+control.PID_roll_innerloop.out+control.PID_yaw_innerloop.out;
    control.PWM_Out2=control.Throttle+control.PID_pitch_innerloop.out-control.PID_roll_innerloop.out-control.PID_yaw_innerloop.out;
    control.PWM_Out3=control.Throttle-control.PID_pitch_innerloop.out+control.PID_roll_innerloop.out+control.PID_yaw_innerloop.out;
    control.PWM_Out4=control.Throttle-control.PID_pitch_innerloop.out-control.PID_roll_innerloop.out-control.PID_yaw_innerloop.out;
//    PWM_Out1=Throttle+PID_yaw_innerloop.out;
//    PWM_Out2=Throttle-PID_yaw_innerloop.out;
//    PWM_Out3=Throttle-PID_yaw_innerloop.out;
//    PWM_Out4=Throttle+PID_yaw_innerloop.out;

    Limit(control.PWM_Out1, PWM_THROTTLE_MAX, PWM_THROTTLE_MIN);
    Limit(control.PWM_Out2, PWM_THROTTLE_MAX, PWM_THROTTLE_MIN);
    Limit(control.PWM_Out3, PWM_THROTTLE_MAX, PWM_THROTTLE_MIN);
    Limit(control.PWM_Out4, PWM_THROTTLE_MAX, PWM_THROTTLE_MIN);
    if(control.CONTROL_MODE == PID_CONTROL_MODE)
    {
        Motor_ctr(control.PWM_Out1,1);
        Motor_ctr(control.PWM_Out2,2);
        Motor_ctr(control.PWM_Out3,3);
        Motor_ctr(control.PWM_Out4,4);
//          Motor_ctr(PWM_THROTTLE_MIN,3);
//          Motor_ctr(PWM_THROTTLE_MIN,4);
    }
    else if(control.CONTROL_MODE == RAW_CONTROL_MODE)
    {
        Motor_ctr(control.Throttle,1);
        Motor_ctr(control.Throttle,2);
        Motor_ctr(control.Throttle,3);
        Motor_ctr(control.Throttle,4);
    }

}

//��ʼ��ȫ�ֱ���
void control_para_init()
{
    control.Mech_zero_yaw = 0;  // yaw���е��㣬��Ϊ��Ҫ���������Ǳ���
    control.is_locked = 1;      // �����
    control.flight_mode = 1;    //����ģʽ
    control.is_landing = 0;     //�Զ�����

    control.PWM_Out1=0;     // �������õ����1��PWM
    control.PWM_Out2=0;     // �������õ����2��PWM
    control.PWM_Out3=0;     // �������õ����3��PWM
    control.PWM_Out4=0;     // �������õ����4��PWM

    control.Yaw   = 0;
    control.Pitch = 0;
    control.Roll  = 0;
    control.Throttle = 0;
    control.CONTROL_MODE = PID_CONTROL_MODE;    //����ģʽ�趨
    control.MOTOR_MODE = MOTOR_NORMAL;          //���ģʽ�趨
}

void Stop_motor()
{
    Motor_ctr(PWM_THROTTLE_MIN,1);
    Motor_ctr(PWM_THROTTLE_MIN,2);
    Motor_ctr(PWM_THROTTLE_MIN,3);
    Motor_ctr(PWM_THROTTLE_MIN,4);
}