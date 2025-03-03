#include "LCD1602.h"
#include "Delay.h"

/**
  *@brief 显示从0每隔1s +1
  *@param 无
  *@retval 无
	*LCD1602模块的7个函数用法
  */
int Result = 0;
void main()
{
	LCD_Init(); //LCD1602初始化函数
//	LCD_ShowChar(1,1,'A'); //在LCD1602指定位置上显示一个字符，1行1列显示A，单字符用单引号 ''
//	LCD_ShowString(1,3,"Hello"); //在LCD1602指定位置开始显示所给字符串，1行3列显示Hello，字符串用双引号 ""
//	LCD_ShowNum(1,9,123,3); //在LCD1602指定位置开始显示所给数字，1行9列显示123，3位，
//	LCD_ShowSignedNum(1,13,-66,2); //在LCD1602指定位置开始以有符号十进制显示所给数字，1行13列显示-66，2位(不含符号)
//	LCD_ShowHexNum(2,1,0xa8,2); //在LCD1602指定位置开始以十六进制显示所给数字，2行1列显示A8(十六进制)，2位
//	LCD_ShowBinNum(2,4,0xaa,8); //在LCD1602指定位置开始以二进制显示所给数字，2行4列显示aa(二进制以十六进制)，8位
	while(1)
	{
		Delay(1000);
		LCD_ShowNum(1,1,Result++,3);
	}
}