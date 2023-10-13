/* --------------------------- (C) COPYRIGHT 2020 Fortiortech ShenZhen -----------------------------
    File Name      : AddFunction.h
    Author         : Fortiortech  Appliction Team / Leo.li Edit
    Version        : V1.0
    Date           : 2020-12-21
    Description    : This file contains all the common data types used for Motor Control.
----------------------------------------------------------------------------------------------------
                                       All Rights Reserved
------------------------------------------------------------------------------------------------- */
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __LOWSPEEDCONCTROL_H_
#define __LOWSPEEDCONCTROL_H_

/******************************************************************************/
#include <FU68xx_2_Type.h>
#include <Customer.h>
#include <Parameter.h> 
/******************************************************************************/
//#define LowSpeedValueTemp               (float)(((360 *Pole_Pairs)/(65535 * TPWM_VALUE * 5 *60))*(32767 / MOTOR_SPEED_BASE)) //10个载波周期计算速度常量 
#define LowSpeedValueTemp               (float)(((SAMP_FREQ *60*Pole_Pairs)/(65535*1))*(32767 / MOTOR_SPEED_BASE)) //10个载波周期计算速度常量

typedef struct
{
  uint8  LowSpeedFlag;
  uint8  ForceThetaFlag;  
  uint8  ThetaSpeedFlag;  
  uint16 Low_SpeedState_Count;
  uint16 Low_Swicth_Time;  
  uint16 Motor_Open_ACC;
  uint16 Motor_Open_Speed_Min;
  uint16 Motor_Open_CNT;  
  int16  LowSpeed; 
  int16  VS;  
  int16  Theta;
  int16  Theta_Voltage;
  int16 Theta_LSB;   
}LOWSPEEDCONCTROL;

extern LOWSPEEDCONCTROL  LowSpeedCtrl;

extern void   LowSpeedTheta(void);
extern void   LowSpeedCal(void);
extern void   EstimateSwitch(void);
extern void   Open_Low_Start_Init(void);
#endif