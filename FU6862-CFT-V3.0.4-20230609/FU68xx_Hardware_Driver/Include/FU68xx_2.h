/**
  ******************************************************************************
  * @file    FU68xx_2.h
  * @author  Fortiortech MCU Team
  * @version V1.0
  * @date    10-Apr-2017
  ******************************************************************************
  * @attention
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT FU6812,FU6861.
  ******************************************************************************
  */

/* Define to prevent recu、

/* Includes -------------------------------------------------------------------------------------*/
#include <absacc.h>						//absacc.h包含直接访问8051不同区域存储器的宏
#include <intrins.h>					//intrins.h包含空操作，左右位移等内嵌代码
#include <math.h>						//math.h包含算术运算的数学函数
#include <stdlib.h>						//stdlib.h包含数据类型装换、产生随机数和存储器定位函数
#include <string.h>						//string.h包含字符串和缓存操作函数

/*常用宏定义-------------------------------------------------------------------------------------*/
#define Q12(n)		(uint32)(n*4095.0)
#define Q15(n)		(uint32)(n*32767.0)
#define Q16(n)		(uint32)(n*65535.0)
#define Enable		1
#define Disable		0
#define True		1
#define False		0

/*FTC6802设备寄存器------------------------------------------------------------------------------*/
#include <FU68xx_2_MCU.h>
#include <FU68xx_2_DMA.h>

