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
#ifndef __LED_H_
#define __LED_H_
//#define PID_CONTROL_TEM

/* Exported types -------------------------------------------------------------------------------*/
typedef struct
{
	uint8 LEDCnt;
	uint8 FlagLED;
	uint8 FlagStepTime;
	uint16 LEDTimeCnt;	
} LEDCtl_TypeDef;

typedef struct
{
    uint16 OnOffCount;
    uint16 OnOffTimes;
    uint16 CycleCount;
    uint16 WaitTime;
    uint16 LED_Step;
}MCLedDisplay;

#define LED1              GP06
#define LED2              GP05
#define LED3              GP04

extern uint8 xdata LED1_EN, LED2_EN, LED3_EN, LED4_EN, LED5_EN, LED6_EN;

/* Exported variables ---------------------------------------------------------------------------*/
extern MCLedDisplay     xdata   mcLedDisplay;
extern LEDCtl_TypeDef LEDCtl;

/* Exported functions ---------------------------------------------------------------------------*/
extern void LEDControl(void);
extern void Temperature_Control(void);
extern void LED_1MS_CYCLE(void);
extern void LED_ONOFF_SET(uint8 ShineTimes, uint8 ShineMode);
extern void KEY_LED_Display(void);

#endif
