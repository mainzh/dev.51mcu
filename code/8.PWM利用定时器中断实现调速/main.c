#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Timer0.h"

sbit Motor=P1^0;
unsigned char Counter,Compare;
unsigned char KeyNum,Speed;

void main()
{
		/*
			*定时器0初始化，1毫秒@12.000MHz
			 TL0=0x18; //设置定时初值
			 TH0=0xfc; //设置定时初值
			*定时器0初始化，1微妙@12.000MHz (更顺滑)
			 TL0=0x9c; //设置定时初值
			 TH0=0xff; //设置定时初值
		*/
    Timer0_Init();
    
    while(1)
    {
        KeyNum=Key();
        if(KeyNum==1)
        {
            Speed++;
            Speed%=4;
            if(Speed==0){Compare=0;}
            if(Speed==1){Compare=20;}
            if(Speed==2){Compare=50;}
            if(Speed==3){Compare=100;}
        }
        Nixie(1,Speed);
    }
}

void Timer0_Routine() interrupt 1
{
    TL0=0x18; //设置定时初值
		TH0=0xfc; //设置定时初值
    Counter++;
    Counter%=100; //计数器定时自增，到100清零
    if(Counter<Compare)
    {
        Motor=1;
    }
    else
    {
        Motor=0;
    }
}