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
#include <FU68xx_2_System.h>


/** 
 * @brief       ADC硬件设备初始化配置，使能ADC，通道配置，采样时间配置，中断配置
 * @data        2022/08/12
 */	
void ADC_Init(void)
{
    /*  -------------------------------------------------------------------------------------------------
        ADC基本配置
        -------------------------------------------------------------------------------------------------*/
    /*  -------------------------------------------------------------------------------------------------
        ADC通道配置
        1、使能相应Pin为模拟Pin，禁止数字功能
        2、使能通道MASK，连接Pin到ADC模块
        ADC_CH0--P20_AN--IU--固定                 ADC_CH5--P32_AN
        ADC_CH1--P23_AN--IV--固定                 ADC_CH6--P33_AN
        ADC_CH2--P24_AN--DCBUS--固定              ADC_CH7--P34_AN
        ADC_CH3--P25_AN--VSP                      ADC_CH8--P21_AN
        ADC_CH4--P27_AN--IBUS/IW--固定            ADC_CH9--P16_AN
                                                  ADC_CH10--P14_AN
                                                  ADC_CH11--P26_AN
        -------------------------------------------------------------------------------------------------*/
    SetBit(P2_AN, P27 | P26 | P24);
	  SetBit(P3_AN, P34 | P33);	
//    SetBit(P1_AN, P14);	
    
    SetBit(ADC_MASK_SYSC, CH11EN | CH7EN | CH6EN | CH4EN | CH2EN);       //Config P2.7 as ADC4 IBUS/IW
    
    /*ADC通道采样时钟周期设置*/
    SetBit(ADC_MASK_SYSC, 0x3000);
    
    ADC_SYSC  = 0x31;
    
    SetReg(ADC_CR, ADCIF | ADCIE, 0x00);                                          // 清标志位和关中断
	
    SetBit(ADC_CR, ADCEN);                                 // 使能ADC   

}



