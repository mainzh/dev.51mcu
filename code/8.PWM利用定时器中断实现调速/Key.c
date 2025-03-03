#include <REGX52.H>
#include "Delay.h"

/**
	*@brief 独立按键读取按键键码
	*@param 无
	*@retval KeyNumber 按下按键的键码值 范围(0——4)
	*若按下按键不放，程序将停留在此函数，松开按键，返回按键键码，没有按下按键，返回0
	*若按键按下{消抖；当按键松开；消抖；KeyNumber赋值位按键对应的下标}
	 if(P3_1 == 0){Delay(20);while(P3_1 == 0);Delay(20);KeyNumber = 1;}
	 ... ...(4个)
	*/
unsigned char Key()
{
    unsigned char KeyNumber = 0;
    if(P3_1 == 0){Delay(20);while(P3_1 == 0);Delay(20);KeyNumber = 1;}
    if(P3_0 == 0){Delay(20);while(P3_0 == 0);Delay(20);KeyNumber = 2;}
    if(P3_2 == 0){Delay(20);while(P3_2 == 0);Delay(20);KeyNumber = 3;}
    if(P3_3 == 0){Delay(20);while(P3_3 == 0);Delay(20);KeyNumber = 4;}
    return KeyNumber;
}