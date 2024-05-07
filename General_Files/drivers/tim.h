#ifndef  __TIM_H_
#define __TIM_H_

#include "../apps/inc/control.h"
#include "uart.h"

void TIM3_Interrupt_Init(void);
void TIM3_Init( u16 arr, u16 psc);
void TIM3_IRQHandler(void);
void TIM4_Interrupt_Init(void);
void TIM4_Init( u16 arr, u16 psc);
void TIM4_IRQHandler(void);


#endif



