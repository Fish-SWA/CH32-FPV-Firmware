#ifndef  IMU_H
#define IMU_H

#include "FreeRTOS.h"
#include "task.h"
#include "MPU6050.h"
#include "bsp_filter.h"

#define IMU_READ_DELAY 5   //IMU��ѯ���� ms

enum{
    IMU_IO_BUSY = 0,
    IMU_IO_IDLE
};

extern void IMU_task(void *pvParameters);
extern MPU6050_para_t MPU6050_para;        //��IMU��ȡ����ԭʼ����
extern MPU6050_para_t MPU6050_para_filted; //�˲�֮���IMU����
extern int IMU_IO_STATUS;

#endif
