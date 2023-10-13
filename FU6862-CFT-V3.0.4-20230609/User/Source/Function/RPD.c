/*  -------------------------- (C) COPYRIGHT 2022 Fortiortech ShenZhen ---------------------------*/
/**
 * @copyright (C) COPYRIGHT 2022 Fortiortech Shenzhen
 * @file      xxx.c
 * @author    Fortiortech  Appliction Team
 * @since     Create:2021-07-14
 * @date      Last modify:2022-07-30
 * @note      Last modify author is Leo.li
 * @brief      
 */
 
#include <FU68xx_2.h>
#include <Myproject.h>

/* Private define -------------------------------------------------------------------------------*/
#if(PosCheckEnable)
RPD_TypeDef RPD_Status;
RPD_Param_TypeDef RPDPara;

/** 
 * @brief      RPD初始化
 * @date       2022-07-14
 */
void RPD_Init(void)
{
    RPD_Status = RPD_0;
    RPDPara.DetectCount[0] = 0;
    RPDPara.DetectCount[1] = 0;
    RPDPara.DetectCount[2] = 0;
    RPDPara.DetectCount[3] = 0;
    RPDPara.DetectCount[4] = 0;
    RPDPara.DetectCount[5] = 0;
    RPDPara.DetectCount[6] = 0;
    RPDPara.DetectCount[7] = 0;
    RPDPara.InsetCount[0] = 0;
    RPDPara.InsetCount[1] = 0;
    RPDPara.InsetCount[2] = 0;
    RPDPara.InsetCount[3] = 0;
    RPDPara.InsetCount[4] = 0;
    RPDPara.InsetCount[5] = 0;
    RPDPara.InsetCount[6] = 0;
    RPDPara.InsetCount[7] = 0;
    RPDPara.U_Offset   = (mcCurOffset.IuOffset - 16383) >> 6;
    RPDPara.V_Offset   = (mcCurOffset.IvOffset - 16383) >> 6;
    RPDPara.W_Offset   = (mcCurOffset.Iw_busOffset - 16383) >> 6;
    RPDPara.injectmin = 0;
    RPDPara.injectmid = 0;
    RPDPara.ThetaGet = 0xFF;
    RPDPara.injecttimes = 0;
}


/** 
 * @brief      RPD对应Time2的初始化
 * @date       2022-07-14
 */
void Time2_RPD_Init(void)
{
    /*  -------------------------------------------------------------------------------------------------
        先停止计数，配置完寄存器后，最后启动计数
        -------------------------------------------------------------------------------------------------*/
    ClrBit(TIM2_CR1, T2EN);                                    // 0，停止计数；1,使能计数
    /*  -------------------------------------------------------------------------------------------------
        时钟分频设置(TIM2_PSC)
        000:cpuclk(24MHz)         001:cpuclk/2^1(12MHz)   010:cpuclk/2^2(6MHz)    011:cpuclk/2^3(3MHz)
        100:cpuclk/2^4(1.5MHz)    101:cpuclk/2^5(750KHz)  110:cpuclk/2^6(375KHz)  111:cpuclk/2^7(187.5KHz)
        -------------------------------------------------------------------------------------------------*/
    #if (InjectTime == Short_Inject)
    {
        SetReg(TIM2_CR0, T2PSC0 | T2PSC1 | T2PSC2, 0x00);
    }
    #elif (InjectTime == Long_Inject)
    {
        SetReg(TIM2_CR0, T2PSC0 | T2PSC1 | T2PSC2, T2PSC0);
    }
    #endif
    /*  -------------------------------------------------------------------------------------------------
        /模式选择
        TIM2_MOD1，TIM2_MOD0
        00--输入Timer模式；01--输出模式
        10--输入Count模式；11--QEP或者RSD模式
        -------------------------------------------------------------------------------------------------*/
    SetReg(TIM2_CR0, T2MOD0 | T2MOD1, T2MOD0);
    SetBit(TIM2_CR1, T2FE);                                    // 滤波使能
    /*  -------------------------------------------------------------------------------------------------
        清除中断标志位
        不配置中断
        -------------------------------------------------------------------------------------------------*/
    ClrBit(TIM2_CR1, T2IR | T2IP | T2IF);
    ClrBit(TIM2_CR0, T2IRE | T2CES);                          // QEP&RSD方向改变事件
    ClrBit(TIM2_CR1, T2IPE | T2IFE);                          // 清零上升沿检测中断
    /*  -------------------------------------------------------------------------------------------------
        配置周期值、比较值、计数值
        禁止PWM周期检测中断使能
        使能计数器上溢中断使能
        -------------------------------------------------------------------------------------------------*/
    TIM2__CNTR = 0;
    TIM2__ARR = 0xFFFF;
}

/** 
 * @brief      RPD
 * @date       2022-07-14
 */
void RPD(void)
{
    if (McStaSet.SetFlag.PosiCheckSetFlag  == 0)       // 初始化RPD配置
    {
        McStaSet.SetFlag.PosiCheckSetFlag = 1;
        RPD_Init();                                   // RPD变量初始化
        Time2_RPD_Init();                             // RPD的Time2初始化
        SetBit(PI_LPF_CR, T2RPD);                     // 使能RPD,即当比较器3产生中断，对应的Time2的计数器的数据会保存，关闭MOE，停止TIM2计数
        MOE = 0;                                      // 关闭MOE
        DRV_DR = DRV_ARR + 1;
        ClrBit(DRV_CR, OCS);                          // 计数器比较值来源，0-方波；1-FOC,SVPWM,SPWM
        SetBit(DAC_CR, DACEN);                        // 使能DAC
                       
        if (mcCurOffset.Iw_busOffset > 10922)
        {
            SetBit(DAC_CR, DACMOD);                       // 0: 正常模式，DAC输出电压范围为0到VREF。1: 半电压转换模式，DAC输出电压范围为VHALF到VREF。
        }
        else
        {
            ClrBit(DAC_CR, DACMOD);
        } 
		DAC_DR = DAC_RPDCurValue;                 //设置检测电流
    }
}
#endif
