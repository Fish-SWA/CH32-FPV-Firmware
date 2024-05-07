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
#include "../apps/inc/Crsf.h"



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
int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Delay_Init();
	Crc_init(0xD5);
	USART_Printf_Init(115200);
	printf("SystemClk:%d\r\n",SystemCoreClock);

	printf("This is printf example\r\n");

	System_Init();

	while(1)
    {
	    System_Loop();

	}
}


