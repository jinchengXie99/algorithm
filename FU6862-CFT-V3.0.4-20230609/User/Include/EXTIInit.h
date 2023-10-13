/*  -------------------------- (C) COPYRIGHT 2022 Fortiortech ShenZhen ---------------------------*/
/**
 * @copyright (C) COPYRIGHT 2022 Fortiortech Shenzhen
 * @file      LED.c
 * @author    Fortiortech  Appliction Team
 * @since     Create:2022-07-14
 * @date      Last modify:2022-07-14
 * @note      Last modify author is Leo.li
 * @brief      
 */

/* Define to prevent recursive inclusion --------------------------------------------------------*/
#ifndef __EXTIINIT_H_
#define __EXTIINIT_H_


typedef struct
{
    uint8 ScrOnAngleTimeDatum;         //期望给定 导通延迟时间  单位为  1/载波频率
    uint8 ScrOnAngleTime;              //实际给定 导通延迟时间  单位为  1/载波频率
    uint8 ScrOnPeriod;                 //控制周期
	
    uint16 Temperature;                //温度值
    uint16 TemperatureDatum[3];        //温度期望值
    
	uint16 TPCtrlDealy;                // 发热丝导通延时计数
    
} USER_TYPEDEF;

/* Exported variables ---------------------------------------------------------------------------*/
extern USER_TYPEDEF  User;


/* Exported functions ---------------------------------------------------------------------------*/
extern void EXTI_Init(void);
extern void Sleepmode_Init(void);
extern void ZeroCrossing_Init(void);

#endif


