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

#if ((FRDetectMethod == BEMFMethod) && (TailWind_Mode == TailWind))

BEMFDetect_TypeDef xdata BEMFDetect;

/** 
 * @brief      BEMF的初始化，包括变量初始化，使能比较器
 * @date       2022-07-14
 */	
void BEMFDetectInit(void)
{
    //BEMF检测前关闭mos输出
    BEMFDetect.BEMFSpeed = 0;
    BEMFDetect.BEMFSpeedBase = 0;
    BEMFDetect.BEMFStatus = 0;
    BEMFDetect.FRStatus      = MCCtrl.FR_Status;
    BEMFDetect.BEMFTimeCount = BEMF_START_DETECT_TIME;//初始反电动势检测时间
    BEMFDetect.BEMFSpeedInitStatus = 0;
    BEMFDetect.FlagSpeedCal = 0;
    BEMFDetect.BEMFStartStatus = 0;
	

    //使能定时器2用于检测时间
    Time2_BMEF_Init();
    //使能比较器
    CMP_BMEF_Init();
}

/** 
 * @brief      BMF对应Time2的初始化
 * @date       2022-07-14
 */
void CMP_BMEF_Init(void)
{
    /*  -------------------------------------------------------------------------------------------------
        CMP Input Pin Mode
        0: GPIO Mode, P1.4--CMP0_IN+, P1.6--CMP1_IN+, P2.1--CMP2_IN+
                  P1.5--CMP0_IN-, P1.7--CMP1_IN-, P2.2--CMP2_IN-
        1: BEMF Mode, 比较器正端连接到内部星型连接电阻U、V、W的BMEF采样点，
                  比较器负端连接到内部星型连接电阻的虚拟中性点
                  比较器负端与P1.5/P1.7/P2.2断开，这三个GPIO可做其他用途
        -------------------------------------------------------------------------------------------------*/
    SetBit(P1_AN, P14 | P16);                                   // CMP0、CMP1
    SetBit(P2_AN, P21);                                         // CMP2
    /*  -------------------------------------------------------------------------------------------------
        CMP0_MOD：
        00：    无内置虚拟中心点电阻的BEMF模式
        01：  内置虚拟中心点电阻的BEMF模式
        10：  3差分比较器模式
        11：  2比较器模式
        -------------------------------------------------------------------------------------------------*/
    SetReg(CMP_CR2, CMP0MOD0 | CMP0MOD1, CMP0MOD0);
    /*  -------------------------------------------------------------------------------------------------
        比较器输出选择配置，与CMP0_MOD配合使用
        CMP0_SEL[1:0]=00，比较器0工作在3比较器轮询模式，正端在CMP0P、CMP1P、CMP2P之间自动轮流选择，
                      负端固定接内置BEMF电阻的中心点，其输出结果分别送至CMP0_OUT、CMP1_OUT、CMP2_OUT
        CMP0_SEL[1:0]=01，比较器0选择CMP0对应的端口组合，正端接CMP0P，负端接内置BEMF电阻的中心点，输出接CMP0_OUT
        CMP0_SEL[1:0]=10，比较器0选择CMP1对应的端口组合，正端接CMP1P，负端接内置BEMF电阻的中心点，输出接CMP1_OUT
        CMP0_SEL[1:0]=11，比较器0选择CMP2对应的端口组合，正端接CMP2P，负端接内置BEMF电阻的中心点，输出接CMP2_OUT
    
        -----------------------------------------------------------------------------*/
    SetReg(CMP_CR2, CMP0SEL0 | CMP0SEL1, 0x00);
    /*  -------------------------------------------------------------------------------------------------
        比较器迟滞电压选择
        000: 无迟滞   001: ±2.5mV   010: -5mV   011: +5mV
        100: +-5mV   101: -10mV   110: +10mV   111: +-10mV
        -------------------------------------------------------------------------------------------------*/
    SetReg(CMP_CR1, CMP0HYS0 | CMP0HYS1 | CMP0HYS2, CMP0HYS2  );
    /*  -------------------------------------------------------------------------------------------------
        CMP0的轮询时间设置
        -------------------------------------------------------------------------------------------------*/
    SetReg(CMP_CR2, CMP0CSEL1 | CMP0CSEL0, 0x00);
    /*  -------------------------------------------------------------------------------------------------
        比较器中断模式配置
        00: 不产生中断  01: 上升沿产生中断  10: 下降沿产生中断  11: 上升/下降沿产生中断
        -------------------------------------------------------------------------------------------------*/
    SetReg(CMP_CR0, CMP2IM0 | CMP2IM1, CMP2IM0 | CMP2IM1);
    SetReg(CMP_CR0, CMP1IM0 | CMP1IM1, CMP1IM0 | CMP1IM1);
    SetReg(CMP_CR0, CMP0IM0 | CMP0IM1, CMP0IM0 | CMP0IM1);
    SetBit(CMP_CR2, CMP0EN);                              //开三个比较器
}

/** 
 * @brief      BMF对应Time2的初始化
 * @date       2022-07-14
 */
void Time2_BMEF_Init(void)
{
    /*  -------------------------------------------------------------------------------------------------
        先停止计数，配置完寄存器后，最后启动计数
        -------------------------------------------------------------------------------------------------*/
    ClrBit(TIM2_CR1, T2EN);                                    // 0，停止计数；1,使能计数
    /*  -------------------------------------------------------------------------------------------------
        时钟分频设置(T2PSC)
        000:cpuclk(24MHz)         001:cpuclk/2^1(12MHz)   010:cpuclk/2^2(6MHz)    011:cpuclk/2^3(3MHz)
        100:cpuclk/2^4(1.5MHz)    101:cpuclk/2^5(750KHz)  110:cpuclk/2^6(375KHz)  111:cpuclk/2^7(187.5KHz)
        -------------------------------------------------------------------------------------------------*/
    SetReg(TIM2_CR0, T2PSC0 | T2PSC1 | T2PSC2, T2PSC0 | T2PSC2);
    /*  -------------------------------------------------------------------------------------------------
        /模式选择
        T2MODE1，T2MODE0
        00--输入Timer模式；01--输出模式
        10--输入Count模式；11--QEP或者RSD模式
        -------------------------------------------------------------------------------------------------*/
    SetReg(TIM2_CR0, T2MOD0 | T2MOD1, T2MOD0);
    /*  -------------------------------------------------------------------------------------------------
        清除中断标志位
        禁止PWM周期检测中断使能
        -------------------------------------------------------------------------------------------------*/
    ClrBit(TIM2_CR0, T2CES);                                       // 清零脉冲计数器不使能
    ClrBit(TIM2_CR1, T2IR | T2IF | T2IP);                  // 清零中断标志位
    /*  -------------------------------------------------------------------------------------------------
        配置周期值、比较值、计数值
        禁止PWM周期检测中断使能
        使能计数器上溢中断使能
        -------------------------------------------------------------------------------------------------*/
    TIM2__ARR = 60000;                                                       // TIM2 Period = 0.32s
    TIM2__DR = TIM2__ARR;
    TIM2__CNTR = 0;
    /*-----------启动计数------------------------------------------------*/
    SetBit(TIM2_CR1, T2EN);                                    //启动计数
}

/** 
 * @brief      读反电动势状态
 * @date       2022-07-14
 */
uint8   GetBEMFStatus(void)
{
    uint8 BEMFStatus = 0;
    
    if (ReadBit(CMP_SR, CMP2OUT))
    {
        BEMFStatus += 4;
    }
    
    if (ReadBit(CMP_SR, CMP1OUT))
    {
        BEMFStatus += 2;
    }
    
    if (ReadBit(CMP_SR, CMP0OUT))
    {
        BEMFStatus += 1;
    }
    
    return BEMFStatus;
}

/** 
 * @brief      功能函数，检测电机转向，根据相邻两个Hall状态顺序来判断电机转向
 * @exception  MC_FR--电机转向，取值为CW或CCW LastHallStatus
 * @date       2022-07-14
 */
uint8 CWCCWDetect(uint8 HallStatus)
{
    static uint8 MC_FR = 0;
    static uint8 MC_HallStatus = 0;
    
    if (MC_HallStatus == 0) //第一次进入中断
    {
        MC_HallStatus = HallStatus;
        MC_FR = BEMFDetect.FRStatus;
        return MC_FR;
    }
    
    if (MC_HallStatus != HallStatus)
    {
        switch (MC_HallStatus)
        {
            case 1:
                if (HallStatus == 5)
                {
                    MC_FR = CCW;
                }
                
                if (HallStatus == 3)
                {
                    MC_FR = CW;
                }
                
                break;
                
            case 2:
                if (HallStatus == 3)
                {
                    MC_FR = CCW;
                }
                
                if (HallStatus == 6)
                {
                    MC_FR = CW;
                }
                
                break;
                
            case 3:
                if (HallStatus == 1)
                {
                    MC_FR = CCW;
                }
                
                if (HallStatus == 2)
                {
                    MC_FR = CW;
                }
                
                break;
                
            case 4:
                if (HallStatus == 6)
                {
                    MC_FR = CCW;
                }
                
                if (HallStatus == 5)
                {
                    MC_FR = CW;
                }
                
                break;
                
            case 5:
                if (HallStatus == 4)
                {
                    MC_FR = CCW;
                }
                
                if (HallStatus == 1)
                {
                    MC_FR = CW;
                }
                
                break;
                
            case 6:
                if (HallStatus == 2)
                {
                    MC_FR = CCW;
                }
                
                if (HallStatus == 4)
                {
                    MC_FR = CW;
                }
                
                break;
                
            default:
                break;
        }
        
        MC_HallStatus = HallStatus;
    }
    
    return MC_FR;
}


/** 
 * @brief      检测速度的计时
 * @date       2022-07-14
 */
void BEMFSpeedDetect(void)
{
    if (BEMFDetect.BEMFSpeedInitStatus == 0)
    {
        BEMFDetect.BEMFSpeedInitStatus = 1;
        BEMFDetect.PeriodTime = 0;
        BEMFDetect.MC_StepTime[0] = 0;
        BEMFDetect.MC_StepTime[1] = 0;
        BEMFDetect.MC_StepTime[2] = 0;
        BEMFDetect.MC_StepTime[3] = 0;
        BEMFDetect.MC_StepTime[4] = 0;
        BEMFDetect.MC_StepTime[5] = 0;
        BEMFDetect.BEMFStep = 0;
        BEMFDetect.StepTime = 0;
        BEMFDetect.FirstCycle = 0;
    }
    else
    {
        BEMFDetect.StepTime = TIM2__CNTR;
        TIM2__CNTR = 0;
        BEMFDetect.MC_StepTime[BEMFDetect.BEMFStep] = BEMFDetect.StepTime;
        BEMFDetect.PeriodTime = (BEMFDetect.MC_StepTime[0] + BEMFDetect.MC_StepTime[1] + BEMFDetect.MC_StepTime[2] +
                BEMFDetect.MC_StepTime[3] + BEMFDetect.MC_StepTime[4] + BEMFDetect.MC_StepTime[5]) >> 3;
        BEMFDetect.BEMFStep++;
        
        if (BEMFDetect.FirstCycle) //360度，第一圈是360计算一次速度，第二圈是60度计算一次速度
        {
            BEMFDetect.FlagSpeedCal = 1;
            BEMFDetect.BEMFSpeedBase = TempBEMFSpeedBase;
        }
        else//60度
        {
            BEMFDetect.FlagSpeedCal = 1;
            BEMFDetect.BEMFSpeedBase = TempBEMFSpeedBase1;
            BEMFDetect.PeriodTime = BEMFDetect.StepTime;
        }
        
        if (BEMFDetect.BEMFStep == 6)
        {
            BEMFDetect.FirstCycle = 1;
            BEMFDetect.BEMFStep = 0;
        }
    }
}

/** 
 * @brief      速度计算，得到的是Q格式的数
 * @date       2022-07-14
 */
void BEMFSpeedCal(void)
{
    if (BEMFDetect.FlagSpeedCal) //此处注意XDATA和除数只能是16位的问题
    {
        BEMFDetect.BEMFSpeed    = DivQ_L_MDU(BEMFDetect.BEMFSpeedBase >>16, BEMFDetect.BEMFSpeedBase, BEMFDetect.PeriodTime);
        //得到的是Q格式的速度,此处除法器与过调值不冲突
        BEMFDetect.FlagSpeedCal = 0;
    }
}


/** 
 * @brief      BEMF检测，判断方向，速度，以及顺风切闭环
 * @date       2022-07-14
 */
void BEMFDetectFunc(void)
{
    if (ReadBit(CMP_SR, CMP0IF) || ReadBit(CMP_SR, CMP1IF) || ReadBit(CMP_SR, CMP2IF)) //当检测到比较器中断时
    {
        //检测当前BEMF状态
        BEMFDetect.BEMFStatus = GetBEMFStatus();
        //根据BEMF状态判断FR状态
        BEMFDetect.FRStatus = CWCCWDetect(BEMFDetect.BEMFStatus);
        //速度检测
        BEMFSpeedDetect();
        //速度计算
        BEMFSpeedCal();
        
        //强制启动标志使能时
        if (BEMFDetect.BEMFStartStatus)
        {
            //CW时U相BEMF上升沿启动，CCW时V相BEMF上升沿启动
            if (((MCCtrl.FR_Status == CW) && (BEMFDetect.BEMFStatus == 5)) || ((MCCtrl.FR_Status == CCW) && (BEMFDetect.BEMFStatus == 3)))
            {
                //执行直接闭环启动程序
                BEMFFOCCloseLoopStart();
                ClrBit(CMP_CR0, CMP2IM1 | CMP2IM0 | CMP1IM1 | CMP1IM0 | CMP0IM1 | CMP0IM0);
                ClrBit(CMP_CR2, CMP0EN);
                BEMFDetect.BEMFStartStatus = 0;
            }
        }
        
        ClrBit(CMP_SR, CMP0IF | CMP1IF | CMP2IF);           //清除中断标志位 
    }
}

/** 
 * @brief      BEMF处理方式
 * @date       2022-07-14
 */
void BEMFDealwith(void)
{
    if ((BEMFDetect.BEMFTimeCount < (BEMF_START_DETECT_TIME - BEMF_START_DELAY_TIME)))
    {
        if (BEMFDetect.FRStatus == MCCtrl.FR_Status)
        {
            //超过设定转速时直接启动
            if ((BEMFDetect.BEMFSpeed > BEMFMotorStartSpeed) && (BEMFDetect.BEMFSpeed < BEMFMotorStartSpeedHigh))
            {
                BEMFDetect.BEMFStartStatus = 1;
            }
        }
        else//反转，刹车
        {
            McStaSet.SetFlag.TailWindSetFlag = 0;
            MOE = 0;
            DRV_DR = DRV_ARR + 1;
            DRV_CMR &= 0xFFC0;
            DRV_CMR |= 0x015;                         // 三相下桥臂通，刹车
            ClrBit(DRV_CR, OCS); //OCS = 0, DRV_COMR;OCS = 1, FOC/SVPWM/SPWM
            //            SetBit(DRV_CR, DRVEN);
            MOE = 1;
            ClrBit(CMP_CR0, CMP2IM1 | CMP2IM0 | CMP1IM1 | CMP1IM0 | CMP0IM1 | CMP0IM0);
            ClrBit(CMP_CR2, CMP0EN);
            
            if (BEMFDetect.BEMFSpeed > _Q15(300.0 / MOTOR_SPEED_BASE))
            {
                mcFocCtrl.State_Count = 200;
                BEMFDetect.BEMFCCWFlag = 1;
            }
            else
            {
                mcFocCtrl.State_Count = 100;
                
                if (BEMFDetect.BEMFCCWFlag == 0)
                { BEMFDetect.BEMFCCWFlag = 2; }
            }
        }
    }
    
    if (BEMFDetect.BEMFTimeCount == 0)// && (BEMFDetect.BEMFSpeed <= BEMFMotorStartSpeed)) //静止或低速
    {
        ClrBit(CMP_CR0, CMP2IM1 | CMP2IM0 | CMP1IM1 | CMP1IM0 | CMP0IM1 | CMP0IM0);
        ClrBit(CMP_CR2, CMP0EN);
        mcState = mcPosiCheck;
        McStaSet.SetFlag.PosiCheckSetFlag = 0;
        mcFocCtrl.mcPosCheckAngle           = 0xffff;         // 角度赋初值
    }
}


/** 
 * @brief      对FOC的相关寄存器进行配置,先清理寄存器，后配置，最后使能
 * @exception  闭环启动
 * @date       2022-07-14
 */
void BEMFFOCCloseLoopStart(void)
{
    /*FOC初始化*/
    FOC_Init();
    /*启动电流、KP、KI*/
    FOC_IDREF = ID_Start_CURRENT;                         // D轴启动电流
    mcFocCtrl.mcIqref = IQ_RUN_CURRENT;                     // Q轴启动电流
    FOC_IQREF = mcFocCtrl.mcIqref;                          // Q轴启动电流
    FOC_DQKP = DQKP;
    FOC_DQKI = DQKI;
    FOC_EFREQACC    = Motor_Omega_Ramp_ACC;
    FOC_EFREQMIN    = Motor_Omega_Ramp_Min;
    FOC_EFREQHOLD = Motor_Omega_Ramp_End;
    SetBit(FOC_CR1, EFAE);                                                          // 估算器强制输出
    ClrBit(FOC_CR1, RFAE);                                                          // 禁止强拉
    SetBit(FOC_CR1, ANGM);                                                          // 估算模式
    FOC__EOME = BEMFDetect.BEMFSpeed;
    
    #if (EstimateAlgorithm == PLL)
    {
        FOC_EKP                           = OBSW_KP_GAIN_RUN2;
        FOC_EKI                           = OBSW_KI_GAIN_RUN2;
        mcFocCtrl.mcIqref                 = IQ_RUN_CURRENT;
    }
	#else
    {
        //根据不同转速确启动的ATO_BW值
        FOC_EKP                       = OBSW_KP_GAIN_RUN2;
        FOC_EKI                       = OBSW_KI_GAIN_RUN2;
        mcFocCtrl.mcIqref             = IQ_RUN_CURRENT;
        mcFocCtrl.State_Count         = 10;
    }
    #endif //end    EstimateAlgorithm
    FOC_OMEKLPF                           = SPEED_KLPF;
    mcState                               = mcRun;
    mcFocCtrl.CtrlMode                    = 0;
    /*使能输出*/
    DRV_CMR |= 0x3F;                         // U、V、W相输出
    MOE = 1;
    EA = 1;
}
#endif