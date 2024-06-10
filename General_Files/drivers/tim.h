#ifndef  __TIM_H_
#define __TIM_H_

#include "../apps/inc/control.h"
#include "uart.h"
#include "../General_Files/drivers/MPU6050.h"

void TIM3_Interrupt_Init(void);
void TIM3_Init( u16 arr, u16 psc);
void TIM3_IRQHandler(void);
void TIM4_Interrupt_Init(void);
void TIM4_Init( u16 arr, u16 psc);
void TIM4_IRQHandler(void);


extern MPU6050_para_t MPU6050_para_filted;
extern int Motor_pos[4];



#endif



