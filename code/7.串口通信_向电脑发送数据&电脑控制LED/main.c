#include <REGX52.H>
#include "Uart.h"

void main()
{
	Uart_Init();
	while(1)
	{
		
	}
}

/**
  *@brief 串口向电脑发送数据&电脑通过串口控制LED
  *@param 
  *@retval 
	*需用到串口助手
	 在发送端输入要赋值给P2寄存器的值，P2所控制LED随之控制
	 并将该值显示在接受端
  */
void Uart_Routine() interrupt 4
{
	if(RI == 1)
		{
			P2 = ~SBUF;
			Uart_SendByte(SBUF);
			RI = 0;
		}
}