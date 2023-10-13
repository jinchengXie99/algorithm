/*  -------------------------- (C) COPYRIGHT 2022 Fortiortech ShenZhen ---------------------------*/
/**
 * @copyright (C) COPYRIGHT 2022 Fortiortech Shenzhen
 * @file      
 * @author    Fortiortech  Appliction Team
 * @since     Create:2022-07-14
 * @date      Last modify:2022-07-14
 * @note      Last modify author is Leo.li
 * @brief      
 */

/* Includes -------------------------------------------------------------------------------------*/
#include <FU68xx_2.h>
#include <Myproject.h>


/** 
 * @brief       PI初始化
 * @data        2022/08/12
 */		
void PI_Init(void)
{
    PI1_KP = SKP;                      //速度调节
    PI1_KI = SKI;
    PI1_UKMAX = SOUTMAX;
    PI1_UKMIN = SOUTMIN;
	
    PI2_KP = _Q12(0.1);                //限制功率调节
    PI2_KI = _Q15(0.001);
//    PI2_UKMAX = SOUTMAX;
//    PI2_UKMIN = SOUTMAX >>1;
	PI2_UKMAX = QOUTMAX;
    PI2_UKMIN = _Q15(0.6);
	
    PI3_KP = DQKP;
    PI3_KI = DQKI;
    PI3_UKMAX = QOUTMAX;
    PI3_UKMIN = QOUTMIN;
    PI2_UKH = SOUTMAX;
    PI3_UKH = 0;
}