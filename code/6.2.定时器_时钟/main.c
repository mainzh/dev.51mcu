#include <REGX52.H>
#include "Timer0.h"
#include "LCD1602.h"

/**
  *@brief 定时器_时钟
  *@param 无
  *@retval 无
	*
  */
unsigned char Hour,Min,Sec;
void main()
{
	LCD_Init();
	Timer0_Init();
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowString(2,1,"  :  :");
  while(1)
    {
			LCD_ShowNum(2,1,Hour,2);
			LCD_ShowNum(2,4,Min,2);
			LCD_ShowNum(2,7,Sec,2);
    }
}

/**
*@brief 中断函数：不要在其中执行过长的任务
  *@param 无
  *@retval 无
	*
*/
void Timer0_Rountine() interrupt 1
{
    static unsigned int T0Count;
    TL0 = 0x18;
	  TH0 = 0xFC;
    T0Count ++;
    if(T0Count >= 1000)
    {
        T0Count = 0;
        Sec ++;
			if(Sec >= 60)
			{
				Sec = 0;
				Min ++;
				if(Min >= 60)
				{
					Min = 0;
					Hour ++;
					if(Hour >= 24)
					{
						Hour = 0;
					}
				}
			}
    }
}