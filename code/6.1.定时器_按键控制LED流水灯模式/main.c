#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.H>

/**
  *@brief 定时器_按键控制LED流水灯模式
  *@param 无
  *@retval 无
	*按键按下从1到0，0到1
	 if(KeyNum == 1)
				{
					LEDMode ++;
					if(LEDMode >= 2) LEDMode = 0;
				}
  */
unsigned char KeyNum,LEDMode;
void main()
{
	P2 = 0xfe;
  Timer0_Init();
  while(1)
    {
			KeyNum = Key();
			if(KeyNum)
			{
				if(KeyNum == 1)
				{
					LEDMode ++;
					if(LEDMode >= 2) LEDMode = 0;
				}
			}
    }
}

/**
  *@brief 定时器_按键控制LED流水灯模式
  *@param 无
  *@retval 无
	*_cror_循环右移_crol_循环左移
	 **unsigned char a = 0x01; //0000 0001
     a = _cror_(a,1); //a=0x80 1000 0000
	 循环左右移：将位移动到最高/低位，循环到最低/高位
	 按位左右移：将位移动到最高/低位，移除后用0替代空位
*/
void Timer0_Rountine() interrupt 1
{
    static unsigned int T0Count;
    TL0 = 0x18;
	  TH0 = 0xFC;
    T0Count ++;
    if(T0Count >= 500)
    {
        T0Count = 0;
        if(LEDMode == 0)
					P2 = _crol_(P2,1);
				if(LEDMode == 1)
					P2 = _cror_(P2,1);
    }
}