/**
  ******************************************************************************
  * @author  何。小P
  * @version V1.0
  * @date    2018-08-22
  * @brief   桂林安合科技有限公司 版权所有（C）All rights reserved.
  ******************************************************************************
	* 
	*	文件名：dp_filter.c
	*	功  能：数字滤波算法
    *
  ******************************************************************************
**/ 

#include "bsp_filter.h"


/**
  ******************************************************************************
 * @函数： void FilterSample( FilterBuf_STRUCT* p, float32 NewValue)
 * @描述：数据采样，样本保存
 * @输入：NewValue:新的采样采样值
 * @返回：无
 * @作者：何。小P
 * @版本：V1.0,2018-08-22
  ******************************************************************************
 */
void FilterSample( FilterBuf_STRUCT* p, float NewValue)
{
	if(p->Head == 0 && p->Rear == 0 && p->Base[0] == 0)
	{
		p->Base[p->Rear]  = NewValue;
	}
	else
	{
		p->Rear = (p->Rear+1)%FilterBuf_MaxLen;
		
		p->Base[p->Rear] = NewValue;
		
		if(p->Head == p->Rear)p->Head = (p->Head+1)%FilterBuf_MaxLen;
	}
}
/**
  ******************************************************************************
 * @函数：float32 FilterAverage( FilterBuf_STRUCT* p)
 * @描述：计算平均数
 * @输入：数据样本
 * @返回：样本的平均值
 * @作者：何。小P
 * @版本：V1.0,2018-08-22
  ******************************************************************************
 */
float FilterAverage( FilterBuf_STRUCT* p)
{
	float sum	= 0.0f;
	uint16_t  i;
	for( i = 0; i<FilterBuf_MaxLen; i++)
	{
		sum += p->Base[i];
	}
	return (float)(sum/FilterBuf_MaxLen);
}

/*			 [] END OF FILE					*/

