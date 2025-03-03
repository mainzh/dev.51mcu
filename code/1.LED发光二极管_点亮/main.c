#include <REGX52.H>

/**
  *@brief 主函数
  *@param 无
  *@retval 无
	* 有且仅有一个main函数，是整个程序开始执行的入口
	* 点亮一个LED(LED1:P20) (位操作方法)
	  因此LED是共阳极连接，所只要给另一端低电平，即可点亮LED
		给P2寄存器(8位，分别控制8个I/O口)赋值 1111 1110 (0xfe) ，即最低位0，其余位1，最低位P20为低电平
	* 循环体
	  while(1){
	  	
	  }
  */
void main(){
	P2=0xfe;
	while(1){
		
	}
}