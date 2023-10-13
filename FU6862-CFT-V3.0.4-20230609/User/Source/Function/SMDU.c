/*  -------------------------- (C) COPYRIGHT 2022 Fortiortech ShenZhen ---------------------------*/
/**
 * @copyright (C) COPYRIGHT 2022 Fortiortech Shenzhen
 * @file      xxx.c
 * @author    Fortiortech  Appliction Team
 * @since     Create:2021-08-01
 * @date      Last modify:2022-8-03
 * @note      Last modify author is Leo.li
 * @brief
 */

#include <FU68xx_2_SMDU.h>
/********************************************************************************
    Internal Routine Prototypes
********************************************************************************/

/** 
 * @brief       PI
 * @param[in]   Xn1: 误差值
 * @return      PI1_UKH
 * @date        2022-07-29
 */
int16 HW_One_PI(int16 Xn1)
{
    PI1_EK =  Xn1;                                                                               //填入EK
    SMDU_RunBlock(1, PI);
    return PI1_UKH;
}


/** 
 * @brief       PI
 * @param[in]   Xn2: 误差值
 * @return      PI2_UKH
 * @date        2022-07-29
 */
int16 HW_One_PI2(int16 Xn2)
{
    PI2_EK =  Xn2;                                                                               //填入EK
    SMDU_RunBlock(2, PI);
    return PI2_UKH;
}


/** 
 * @brief       低通滤波
 * @param[in]   Xn1: 当前输入值
 * @param[in]   Xn0: 上一次滤波输出值
 * @param[in]   K:  LPF滤波系数
 * @return      LPF0_YH
 * @date        2022-07-29
 */
int16 LPFFunction(int16 Xn1, int16 Xn0, int8 K)
{
    LPF0_K = K << 8;
    LPF0_X = Xn1;
    LPF0_YH = Xn0;
    SMDU_RunBlock(0, LPF);
    return LPF0_YH;
}


int16 MUL_X_MDU(int16 Xn1, int16 Xn0)
{
    MUL0_MA = Xn1;
    MUL0_MB = Xn0;
    SMDU_RunBlock(0, S1MUL);
    return MUL0_MCH;
}


/** 
 * @brief       计算幅值
 * @param[in]   Xn1: COS
 * @param[in]   Xn0: SIN
 * @return      SCAT1_RES1
 * @date        2022-07-29
 */
int16 Atan_Us_MDU(int16 Xn1, int16 Xn0)
{
    SCAT1_COS = Xn1;
    SCAT1_SIN = Xn0;
    SCAT1_THE = 0;
    SMDU_RunBlock(1, ATAN);
    return SCAT1_RES1;
}

/** 
 * @brief       计算Is
 * @param[in]   Xn1: 被除数高位
 * @param[in]   Xn0: 被除数低位
 * @param[in]   Yn:  除数
 * @return      DIV0_DQL
 * @date        2022-07-29
 */
int16 DivQ_L_MDU(uint16 Xn1, uint16 Xn0, uint16 Yn)
{
    DIV0_DAH = Xn1;
    DIV0_DAL = Xn0;
    DIV0_DB  = Yn;
    SMDU_RunBlock(0, DIV);
    return DIV0_DQL;
}

/** 
 * @brief       计算Is
 * @param[in]   i_alp: alp轴电流
 * @param[in]   i_bet: bet轴电流
 * @return      is
 * @date        2022-07-29
 */
uint16 SqrtI_alpbet(int16 i_alp, int16 i_bet)
{
    SCAT2_COS    =   i_alp;
    SCAT2_SIN    =   i_bet;
    SMDU_RunBlock(2, ATAN);
    return SCAT2_RES1;
}