#ifndef  IMU_H
#define IMU_H

#include "FreeRTOS.h"
#include "task.h"
#include "MPU6050.h"
#include "bsp_filter.h"

#define IMU_READ_DELAY 1    //IMU轮询周期 ms

extern void IMU_task(void *pvParameters);
extern FilterBuf_STRUCT gyro_filter[6];    //IMU平均值滤波结构体
extern MPU6050_para_t MPU6050_para_filted; //滤波之后的IMU数据

#endif