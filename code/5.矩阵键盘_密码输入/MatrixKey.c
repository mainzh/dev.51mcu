#include <REGX52.H>
#include "Delay.h"

/**
	*@brief 矩阵键盘读取按键键码
	*@param 无
	*@retval KeyNumber 按下按键的键码值 范围(0——16)
	*若按下按键不放，程序将停留在此函数，松开按键，返回按键键码，没有按下按键，返回0
	*判断第1行
	 P1 = 0xff; //将P1寄存器默认设为高电平 二进制"1111 1111"
	 P1_7 = 0; //将第1行P17设为低电平 二进制"0"
	 判断第1列
	 若按键按下{消抖；当按键松开；消抖；KeyNumber赋值位按键对应的下标}
	 if(P1_3 == 0){Delay(20);while(P1_3 == 0);Delay(20);KeyNumber = 1;}
	 ... ...(4行4列)
	*/
unsigned char MatrixKey()
{
    unsigned char KeyNumber = 0;
    P1 = 0xff;
    P1_7 = 0;
    if(P1_3 == 0){Delay(20);while(P1_3 == 0);Delay(20);KeyNumber = 1;}
    if(P1_2 == 0){Delay(20);while(P1_2 == 0);Delay(20);KeyNumber = 2;}
    if(P1_1 == 0){Delay(20);while(P1_1 == 0);Delay(20);KeyNumber = 3;}
    if(P1_0 == 0){Delay(20);while(P1_0 == 0);Delay(20);KeyNumber = 4;}
    P1 = 0xff;
    P1_6 = 0;
    if(P1_3 == 0){Delay(20);while(P1_3 == 0);Delay(20);KeyNumber = 5;}
    if(P1_2 == 0){Delay(20);while(P1_2 == 0);Delay(20);KeyNumber = 6;}
    if(P1_1 == 0){Delay(20);while(P1_1 == 0);Delay(20);KeyNumber = 7;}
    if(P1_0 == 0){Delay(20);while(P1_0 == 0);Delay(20);KeyNumber = 8;}
    P1 = 0xff;
    P1_5 = 0;
    if(P1_3 == 0){Delay(20);while(P1_3 == 0);Delay(20);KeyNumber = 9;}
    if(P1_2 == 0){Delay(20);while(P1_2 == 0);Delay(20);KeyNumber = 10;}
    if(P1_1 == 0){Delay(20);while(P1_1 == 0);Delay(20);KeyNumber = 11;}
    if(P1_0 == 0){Delay(20);while(P1_0 == 0);Delay(20);KeyNumber = 12;}
    P1 = 0xff;
    P1_4 = 0;
    if(P1_3 == 0){Delay(20);while(P1_3 == 0);Delay(20);KeyNumber = 13;}
    if(P1_2 == 0){Delay(20);while(P1_2 == 0);Delay(20);KeyNumber = 14;}
    if(P1_1 == 0){Delay(20);while(P1_1 == 0);Delay(20);KeyNumber = 15;}
    if(P1_0 == 0){Delay(20);while(P1_0 == 0);Delay(20);KeyNumber = 16;}
    return KeyNumber;
}