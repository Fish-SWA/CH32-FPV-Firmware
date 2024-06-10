/**
  ******************************************************************************
  * @author  �Ρ�СP
  * @version V1.0
  * @date    2018-08-22
  * @brief   ���ְ��ϿƼ����޹�˾ ��Ȩ���У�C��All rights reserved.
  ******************************************************************************
	* 
	*	�ļ�����dp_filter_lib.h
	*	��  �ܣ������˲��㷨
    *
  ******************************************************************************
**/ 


#ifndef _DP_FILTER_H
#define _DP_FILTER_H
#include "debug.h"
#include "../apps/inc/control.h"

#define FilterBuf_MaxLen 3

typedef struct{

	float Base[FilterBuf_MaxLen];
	int16_t   Head;
	int16_t   Rear;

}FilterBuf_STRUCT;


void    FilterSample( FilterBuf_STRUCT* p, float NewValue);
float   FilterAverage( FilterBuf_STRUCT* p);

#endif










