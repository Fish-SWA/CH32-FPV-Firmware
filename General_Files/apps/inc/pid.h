#ifndef __PID_H_
#define __PID_H_
#define Limit(input, max, min) \
    do {                         \
        if ((input) > (max))     \
        {                        \
            (input) = (max);     \
        }                        \
        else if ((input) < (min))\
        {                        \
            (input) = (min);     \
        }                        \
    } while(0)

#define LimitMin(input,min) {if (input < min){ input = min;}}


typedef struct  _PID{
    float Kp;
    float Ki;
    float Kd;

    float max_out;      //������
    float min_out;      //��С���
    float max_iout;     //���������
    float min_iout;     //���������

    float set;          //Ŀ��ֵ
    float fdb;          //��ǰֵ

    float out;          //pid���
    float Pout;         //����������
    float Iout;         //���ֿ�����
    float Dout;         //΢�ֿ�����
    float Dbuf[3];      //΢���� 0���� 1��һ�� 2���ϴ�
    float error[3];     //����� 0���� 1��һ�� 2���ϴ�
}PID_STRUCT;

// pid�����ṹ��
typedef struct _PID_FUNC{

    void (*reset) ( PID_STRUCT *pid);
    void (*init ) ( PID_STRUCT *pid);
    void (*clc  ) ( PID_STRUCT *pid);
    void (*calc ) ( PID_STRUCT *pid, float set, float fdb);
}PID_FUNC;


extern PID_FUNC pid_func;

#endif

