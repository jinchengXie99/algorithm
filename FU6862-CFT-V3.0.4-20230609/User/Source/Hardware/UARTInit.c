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
 
#include <FU68xx_2.h>
#include <Myproject.h>
/* Private variables ----------------------------------------------------------------------------*/
MCUART Uart;

/** 
 * @brief       UART初始化
 * @data        2022/08/12
 */
void UART_Init(void)
{
    SetBit(PH_SEL, UARTEN);     //p0[6]as UART_RXD; p0[5]as UART_TXD
    UT_MOD1 = 0;
    UT_MOD0 = 1;                //8bit波特率可变UART模式
    SM2 = 0;                    //禁止Mode2和Mode3多机通讯
    REN = 0;                    //使能接收
    ES0 = 0;                    //先关中断
    PUART1 = 0;                 //中断优先级时最低
    PUART0 = 0;
    UT_BAUD = 0x9b;             //default baudrate:9600-0x9b,1200-0x4E1
    ES0 = 0;                    //发送/接受中断使能
}

/** 
 * @brief       SPI数据发送
 * @param(sndBuf) 发送数据
 * @param(len)  数据长度
 * @data        2022/08/12
 */	
void UartTxdate(uint16 * sndBuf, int16 len)
{
    uint16 i = 0;
    
    for (i = 0; i < len; i++)
    {
        UART_SendData(*sndBuf++);
    }
}
/** 
 * @brief       SPI数据发送
 * @param(T_Data) 发送数据
 * @data        2022/08/12
 */	
void UART_SendData(unsigned char T_Data)
{
    UT_DR = T_Data;
    
    while (!(TI == 1));     //等待发送完成
    
    TI = 0;                 //发送完成中断标志位清零
}
