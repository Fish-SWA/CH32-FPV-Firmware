#ifndef  IMU_H
#define IMU_H

#include "FreeRTOS.h"
#include "task.h"
#include "MPU6050.h"
#include "bsp_filter.h"

#define IMU_READ_DELAY 1    //IMU��ѯ���� ms

extern void IMU_task(void *pvParameters);
extern FilterBuf_STRUCT gyro_filter[6];    //IMUƽ��ֵ�˲��ṹ��
extern MPU6050_para_t MPU6050_para_filted; //�˲�֮���IMU����

#endif