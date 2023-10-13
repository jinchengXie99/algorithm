/*  -------------------------- (C) COPYRIGHT 2022 Fortiortech ShenZhen ---------------------------*/
/**
 * @copyright (C) COPYRIGHT 2022 Fortiortech Shenzhen
 * @file      xxx.c
 * @author    Fortiortech  Appliction Team
 * @since     Create:2022-07-14
 * @date      Last modify:2022-08-07
 * @note      Last modify author is Leo.li
 * @brief      
 */

/* Includes -------------------------------------------------------------------------------------*/
#include <FU68xx_2.h>
#include <Myproject.h>
#include <math.h>

extern uint8 data g_1mTick;                   ///< 1ms滴答信号，每隔1ms在SYSTICK定时器被置1，需在大循环使用处清零

uint16 xdata spidebug[4] = { 0 };
uint8 PWM_Count = 0;
uint8 Getzero_flag = 0;

uint8 VoltDetecExternCnt = 0;

/** 
 * @brief        FO_INT interrupt，硬件FO过流保护，关断输出，中断优先级最高
 * @date         2022-08-07  
 */
void FO_INT(void) interrupt 1                                                   // 硬件FO过流中断，关闭输出
{
    MOE     = 0;                                                                // 关闭输出
    mcFaultSource = FaultHardOVCurrent;                                         // 硬件过流保护
    IF0           = 0;                                                          // clear P00 interrupt flag
}


/** 
 * @brief        外部中断：用于过零检测和发热控制
 * @date         2022-08-07  
 */
void EXTERN_INT(void) interrupt 2
{
//    static uint16 ScrOnTime = 0;
    
    VoltDetecExternCnt = 60;                // 进中断赋初值
//	               //发热开启时间	
//	    /* 电机运行超过200ms、电机运行中、电机转速超过12000RPM */
//    if ((User.TPCtrlDealy < 4800) && (mcState == mcRun) && (mcFocCtrl.SpeedFlt > 12000))
//    {
//        ScrOnTime ++;                     // 过零点计数，国内电网50Hz，一般10ms进一次
//        if (ScrOnTime <= User.ScrOnPeriod)    // 过零周期内
//        {     /* -----非冷风档以及开启周期内----- */
//            if ((ScrOnTime < User.ScrOnAngleTimeDatum) && (User.ScrOnAngleTime != Temperature_Off))
//            {
//                GP01 = 0;                                  //打开发热丝
//            }
//            else      // 超过开启周期或冷风档则关闭发热丝
//            {
//                GP01 = 1;                                  //关闭发热丝
//            }
//        }
//        else              //一个周期完成后
//        {
//            ScrOnTime = 0;

//			Temperature_Control();                         //发热功率控制
//        }       
//    }   
//	else
//	{
//		GP01 = 1;                                         //关闭发热丝
//	}
                
                
//    if((mcState == mcRun) && (Heat_on_delay >= 1200) && (Cool_Lv == 0) && (Overtmp_flag == 0))    // 交流电过零点，检测到过零点才会进入   实际20ms进一次，和硬件设计有关
//    {
//        /* -----过零点个数计数----- */
//        Heat_on_cnt++;          // 变量自加，不能放在前面
//        
//    /* -该值此时为8可进入判断，即第8个过零点可进入下述判断，实际时间为160ms，即一段周期完成- */
//        if(Heat_on_cnt >= HEAT_TIMECNT_MAX) // 第8次过零信号更新周期，即单段周期结束 160ms
//        {
//            Heat_on_cnt = 0;
//            Heatdutycnt++;
//            if(Heatdutycnt > 2)
//            {
//                Heatdutycnt = 0;
//            }
//            Heat_duty_cycle = Heatduty[Heatdutycnt];    // 发热丝输出周期三段赋值
//        }
//        else
//        {
//            if(Heat_on_cnt <= Heat_duty_cycle) 
//            {
//                GP07 = HEAT_ON_LEVEL;     
//            }
//            else
//            {
//                GP07 = !HEAT_ON_LEVEL;
//            }
//        }
//    }
//    else
//    {
//        GP07 = !HEAT_ON_LEVEL;
//    }
    
    Getzero_flag = 1;           // 过零点标记
    
    if((Heat_on_flag) && (Cool_Lv == 0) && (Overtmp_flag == 0) && (OverVoltageflag == 0))
    {
        GP07 = HEAT_ON_LEVEL;
    }
    else
    {
        GP07 = !HEAT_ON_LEVEL;
    }
    ClrBit(P2_IF, P21);                                   // 清零中断标志位
}

/** 
 * @brief        Time2-BEMF顺逆风检测
 * @date         2022-08-07  
 */
void TIM2_INT(void) interrupt 4
{
    if (ReadBit(TIM2_CR1, T2IR))
    { 
        ClrBit(TIM2_CR1, T2IR);
    }
    
    if (ReadBit(TIM2_CR1, T2IP))
    {
        ClrBit(TIM2_CR1, T2IP);
    }
    
    if (ReadBit(TIM2_CR1, T2IF))
    {
        ClrBit(TIM2_CR1, T2EN);                  //关闭计数器
        ClrBit(TIM2_CR1, T2IF);
    }
}

/** 
 * @brief        CMP3：硬件比较器过流保护，关断输出，中断优先级最高
 * @brief        CMP0/1/2：顺逆风判断
 * @date         2022-07-14  
 */
void CMP_ISR(void) interrupt 7
{
    if (ReadBit(CMP_SR, CMP3IF))
    {
        if (mcState != mcPosiCheck)
        {
            MOE     = 0;                                                        // 关闭输出
            mcFaultSource = FaultHardOVCurrent;                                 // 硬件过流保护
        }
        else
        {
			MOE     = 0; 
			#if(PosCheckEnable)                                                                                 // 关闭MOE
            RPDPara.InsetCount[RPDPara.injecttimes]  = TIM2__CNTR;                              // 将定时器2的计数值赋值给数组
            RPDPara.DetectCount[RPDPara.injecttimes] = RPDPara.InsetCount[RPDPara.injecttimes]; // 两组数据，一组用于观察原始数据，一组用于处理数据
            TIM2__CNTR                               = 0;                                       // TIM2计数器值清零
            RPDPara.injecttimes++;                                                              // RPD注入拍数累加
            #endif
         }
        
        ClrBit(CMP_SR, CMP3IF);           //清除比较器中断
    }
    /*------通过BEMF做顺风启动功能 -----*/
    #if ((FRDetectMethod == BEMFMethod)&&(TailWind_Mode == TailWind))   
    BEMFDetectFunc();
    #endif
}


/** 
 * @brief        Capture PWM ，用于PWM调速
 * @date         2022-08-07  
 */
void TIM3_INT(void) interrupt 9
{
    if (ReadBit(TIM3_CR1, T3IR))
    {      
        ClrBit(TIM3_CR1, T3IR);
    }
    
    if (ReadBit(TIM3_CR1, T3IP))                                   //周期中断
    {
        ClrBit(TIM3_CR1, T3IP);
    }
    
    if (ReadBit(TIM3_CR1, T3IF))
    {
        ClrBit(TIM3_CR1, T3IF);
    }
}

/** 
 * @brief        FOC中断(Drv中断), 可配置1 | 2 个载波周期执行一次，用于处理响应较高的程序
 * @date         2022-08-07  
 */
void FOC_INT(void) interrupt 3
{    
    if (ReadBit(DRV_SR, DCIF))                                        // 比较中断
    {
		#if (START_MODE == Observer_Start)
		{
            StartupState();
		}
		#endif
		      
        #if ((FRDetectMethod == FOCMethod) && (TailWind_Mode == TailWind))
        {
            TailWindSpeedDetect();                                    //顺逆风检测
        }
        #endif
		
        DRV_SR = (DRV_SR | SYSTIF) & (~DCIF);   // DRV_SR,  SYSTIF  DCIF
    }
}

/** 
 * @brief        1ms定时器中断（SYS TICK中断），用于处理附加功能，如控制环路响应、各种保护等。
 * @date         2022-08-07  
 */
void TIM_1MS_INT(void) interrupt 10
{
    if (ReadBit(DRV_SR, SYSTIF))                             // SYS TICK中断
    {
        g_1mTick = 1;
        SetBit(ADC_CR, ADCBSY);                              //使能ADC的DCBUS采样
		
		/*****电机状态机的时序处理*****/
        if (mcFocCtrl.State_Count > 0)
        {
            mcFocCtrl.State_Count--;
        }
		
        if(VoltDetecExternCnt > 0)  VoltDetecExternCnt--;
    
		WatchDogRefresh();
        
        DRV_SR = (DRV_SR | DCIF) & (~SYSTIF);
    }
    
    if (ReadBit(TIM4_CR1, T4IR))
    {
        ClrBit(TIM4_CR1, T4IR);
    }
    
    if (ReadBit(TIM4_CR1, T4IP))                             //周期中断
    {
        ClrBit(TIM4_CR1, T4IP);
    }
    
    if (ReadBit(TIM4_CR1, T4IF))
    {
        ClrBit(TIM4_CR1, T4IF);
    }
}

/** 
 * @brief        串口中断
 * @date         2022-08-07  
 */
void USART_INT(void)  interrupt 12
{
    if (RI == 1)
    {
        RI = 0;
        Uart.Uredata = UT_DR;                    //读接收数据
    }
}

/* Private variables ----------------------------------------------------------------------------*/
void INT0(void) interrupt 0
{
}
void INT5(void) interrupt 5
{
}
void INT6(void) interrupt 6
{
}
void INT8(void) interrupt 8
{
}
void INT11(void) interrupt 11
{
}
void INT13(void) interrupt 13
{
}
void INT14(void) interrupt 14
{
}
void INT15(void) interrupt 15
{
}




