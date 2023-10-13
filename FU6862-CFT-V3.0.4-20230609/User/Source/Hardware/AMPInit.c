/*  -------------------------- (C) COPYRIGHT 2022 Fortiortech ShenZhen ---------------------------*/
/**
 * @copyright (C) COPYRIGHT 2022 Fortiortech Shenzhen
 * @file      xxx.c
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
 * @brief       AMP初始化配置,使能运放电压VHALF，配置运放的电流采样正向输入，反向输入和输出，包括I_BUS,I_U,I_V
                并使能对应的运放
 * @data        2022/08/12
 */	
void AMP_Init(void)
{

    /*运放使能*/
    #if (Shunt_Resistor_Mode == Single_Resistor)
    {
        /* ----AMP 端口模拟功能设置---- */
        #if (HW_AMP_MODE == AMP_NOMAL) //外部放大
        {
            SetBit(P3_AN, P31);             //AMP0 Pin设置为模拟模式  +
            SetBit(P3_AN, P30);             //AMP0 Pin设置为模拟模式  -
            SetBit(P2_AN, P27);             //AMP0 Pin设置为模拟模式  O
            SetBit(AMP_CR, AMP0EN);        //AMP0 Enable
            
            ClrBit(CMP_AMP, AMP0_GAIN2);
            ClrBit(CMP_AMP, AMP0_GAIN1);
            ClrBit(CMP_AMP, AMP0_GAIN0);
        }
        #else       // 内部PGA双端差分输入
        {
            SetBit(P3_AN, P31);             //AMP0 Pin设置为模拟模式  +
            SetBit(P3_AN, P30);             //AMP0 Pin设置为模拟模式  -
            SetBit(P2_AN, P27);             //AMP0 Pin设置为模拟模式  O
            
            ClrBit(TSD_ADJ, AMP0M_GND);     // 禁止运放反向输入端内部接地
            SetBit(AMP_CR, AMP0EN);         //AMP0 Enable
            
            #if (HW_AMPGAIN == AMP2x)
            {
                ClrBit(CMP_AMP, AMP0_GAIN2);
                ClrBit(CMP_AMP, AMP0_GAIN1);
                SetBit(CMP_AMP, AMP0_GAIN0);
            }
            #elif (HW_AMPGAIN == AMP4x)
            {
                ClrBit(CMP_AMP, AMP0_GAIN2);
                SetBit(CMP_AMP, AMP0_GAIN1);
                ClrBit(CMP_AMP, AMP0_GAIN0);
            }
            #elif (HW_AMPGAIN == AMP8x)
            {
                ClrBit(CMP_AMP, AMP0_GAIN2);
                SetBit(CMP_AMP, AMP0_GAIN1);
                SetBit(CMP_AMP, AMP0_GAIN0);
            }
            #elif (HW_AMPGAIN == AMP16x)
            {
                SetBit(CMP_AMP, AMP0_GAIN2);
                ClrBit(CMP_AMP, AMP0_GAIN1);
                ClrBit(CMP_AMP, AMP0_GAIN0);
            }
            #endif
        }
        #endif
    }
    #else   // 双 三电阻采样
    {
        SetBit(P1_AN, P16);             //AMP1 Pin设置为模拟模式  +
        SetBit(P1_AN, P17);             //AMP1 Pin设置为模拟模式  -
        SetBit(P2_AN, P20);             //AMP1 Pin设置为模拟模式  O

        SetBit(P2_AN, P21);             //AMP2 Pin设置为模拟模式  +
        SetBit(P2_AN, P22);             //AMP2 Pin设置为模拟模式  -
        SetBit(P2_AN, P23);             //AMP2 Pin设置为模拟模式  O
        ClrBit(P2_OE, P23);             //P23_OE需要强制为0，禁止DA1输出至PAD

        SetBit(P3_AN, P31);             //AMP0 Pin设置为模拟模式  +
        SetBit(P3_AN, P30);             //AMP0 Pin设置为模拟模式  -
        SetBit(P2_AN, P27);             //AMP0 Pin设置为模拟模式  O
		
		ClrBit(TSD_ADJ, AMP0M_GND);     // 禁止运放反向输入端内部接地
		ClrBit(TSD_ADJ, AMP12M_GND);    // 禁止运放反向输入端内部接地
		
        SetBit(AMP_CR, AMP0EN);         //AMP0 Enable
        SetBit(AMP_CR, AMP1EN);         //AMP1 Enable
        SetBit(AMP_CR, AMP2EN);         //AMP2 Enable
        
        #if (HW_AMP_MODE == AMP_NOMAL)      //外部放大
        {
            ClrBit(CMP_AMP, AMP0_GAIN2);
            ClrBit(CMP_AMP, AMP0_GAIN1);
            ClrBit(CMP_AMP, AMP0_GAIN0);
    
            ClrBit(CMP_AMP, AMP_PH_GAIN2);
            ClrBit(CMP_AMP, AMP_PH_GAIN1);
            ClrBit(CMP_AMP, AMP_PH_GAIN0);
        }
        #else
        {
            #if (HW_AMPGAIN == AMP2x)
            {
                ClrBit(CMP_AMP, AMP0_GAIN2);
                ClrBit(CMP_AMP, AMP0_GAIN1);
                SetBit(CMP_AMP, AMP0_GAIN0);
    
                ClrBit(CMP_AMP, AMP_PH_GAIN2);
                ClrBit(CMP_AMP, AMP_PH_GAIN1);
                SetBit(CMP_AMP, AMP_PH_GAIN0);
            }
            #elif (HW_AMPGAIN == AMP4x)
            {
                ClrBit(CMP_AMP, AMP0_GAIN2);
                SetBit(CMP_AMP, AMP0_GAIN1);
                ClrBit(CMP_AMP, AMP0_GAIN0);
    
                ClrBit(CMP_AMP, AMP_PH_GAIN2);
                SetBit(CMP_AMP, AMP_PH_GAIN1);
                ClrBit(CMP_AMP, AMP_PH_GAIN0);
            }
            #elif (HW_AMPGAIN == AMP8x)
            {
                ClrBit(CMP_AMP, AMP0_GAIN2);
                SetBit(CMP_AMP, AMP0_GAIN1);
                SetBit(CMP_AMP, AMP0_GAIN0);
    
                ClrBit(CMP_AMP, AMP_PH_GAIN2);
                SetBit(CMP_AMP, AMP_PH_GAIN1);
                SetBit(CMP_AMP, AMP_PH_GAIN0);
            }
            #elif (HW_AMPGAIN == AMP16x)
            {
                SetBit(CMP_AMP, AMP0_GAIN2);
                ClrBit(CMP_AMP, AMP0_GAIN1);
                ClrBit(CMP_AMP, AMP0_GAIN0);
    
                SetBit(CMP_AMP, AMP_PH_GAIN2);
                ClrBit(CMP_AMP, AMP_PH_GAIN1);
                ClrBit(CMP_AMP, AMP_PH_GAIN0);
            }
            #endif
        }
        #endif
    }
    #endif
	
}