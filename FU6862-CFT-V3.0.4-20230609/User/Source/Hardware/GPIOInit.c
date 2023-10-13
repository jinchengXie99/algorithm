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
 * @brief       GPIO初始化配置,可将I/O口配置成输入或输出模式，上拉还是不上拉，模拟输出还是数字输出
 * @data        2022/08/12
 */	
void GPIO_Init(void)
{
//    P0_OE = P01 | P05 | P06 | P07;  //使能LED报警IO口
//    P0_PU = P01 | P05 | P06 | P07; // 需确认这些端口能接受上拉

//	ClrBit(P0_OE, P02);            // SW2  温度
//    SetBit(P0_PU, P02);            // 
//	
//	
//	ClrBit(P0_OE, P03);            // 中档
//    SetBit(P0_PU, P03);            // 
//	
//	ClrBit(P0_OE, P07);            // 高档
//    SetBit(P0_PU, P07);            // 
//	
//	
//	
// 	SetBit(P0_OE, P04);            // LED3
//    SetBit(P0_PU, P04);            //      
//	
//	SetBit(P0_OE, P05);            // LED2
//    SetBit(P0_PU, P05);            // 
//    
//	SetBit(P0_OE, P06);            // LED1
//    SetBit(P0_PU, P06);            //

//	SetBit(P1_OE, P11);            // 
//	SetBit(P1_PU, P11);            // 发热丝输出位
//	GP11 = 1;   

//	SetBit(P1_OE, P12);            // 
//	SetBit(P1_PU, P12);            // 发热丝输出位
//	GP12 = 0; 
	
    ClrBit(P1_PU, P13);             // 总开关   关上拉
    ClrBit(P1_OE, P13);                         // 关输出
    
  SetBit(P0_OE, P07);           //发热丝控制端口
  GP07 = !HEAT_ON_LEVEL;
  
  SetBit(P1_PU, P14);           // 温度档位按键
    
  SetBit(P1_OE, P15 | P16 | P17);           
  ClrBit(P1_PU, P15 | P16 | P17);           //P15、P16、P17三个口控制6个灯
    
  GP15 = 0;         // 100 橙色D1+红色D3 010 2*蓝色D25 001 橙色D6+红色D4  
  GP16 = 0;         // 110 红色D3+蓝色D5 101 2*橙色D16 011 蓝色D2+红色D4
  GP17 = 0;
}