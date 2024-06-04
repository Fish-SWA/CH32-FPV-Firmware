/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : Main program body.
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* SPDX-License-Identifier: Apache-2.0
*******************************************************************************/


#include "debug.h"
#include "system.h"
#include "apps/inc/Crsf.h"
#include "apps/inc/control.h"
#include "drivers/pwm.h"

int last_RC_lock_state = Locked;	//上一次锁定状态
float Motor_speed_set = PWM_THROTTLE_MIN; //油门值设定

/* Global typedef */

/* Global define */

/* Global Variable */



/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */

void Motor_sort_start()		//电机缓启动
{
	if(is_locked == Unlocked && last_RC_lock_state == Locked){	//当解锁电机时候
		printf("MOTOR UNLOCKED!!!!\n");
		last_RC_lock_state = Unlocked;
		MOTOR_MODE = MOTOR_SOFT_STARTING;	//切换到缓启动模式

		for(int i=0; i<SOFT_START_TIME; i++){	//缓启动逻辑
			Motor_speed_set = ((((float)PWM_THROTTLE_MIN_ROTATE-(float)PWM_THROTTLE_MIN)/(float)SOFT_START_TIME))*i + PWM_THROTTLE_MIN;
			//printf("Motor_set=%d\n", (int)Motor_speed_set);
				Motor_ctr_SOFT_START(Motor_speed_set, 1);
				Motor_ctr_SOFT_START(Motor_speed_set, 2);
				Motor_ctr_SOFT_START(Motor_speed_set, 3);
				Motor_ctr_SOFT_START(Motor_speed_set, 4);
			Delay_Ms(1);
		}

		printf("MOTOR OK!!!!\n");
		MOTOR_MODE = MOTOR_NORMAL; //切换回正常模式
	}

	if(is_locked == Locked){
		last_RC_lock_state = Locked;
		MOTOR_MODE = MOTOR_NORMAL;
		Stop_motor();
	}


}

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Delay_Init();
	Crc_init(0xD5);
	USART_Printf_Init(115200);
	printf("SystemClk:%d\r\n",SystemCoreClock);

	printf("This is printf example\r\n");

	System_Init();
# git test

	while(1)
    {
	    System_Loop();
		Motor_sort_start();
	}
}


