#include <REGX52.H>
#include "Delay.h"

/**
  *@brief LED数码管段码数组
	*取值范围 (0——9)
  */
unsigned char NixieTable[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

/**
  *@brief LED数码管显示
  *@param Location：位选，显示第几位LED模块，取值范围 (0——8)
  *@param Number：段选，显示什么数字，取值范围 (0——9)，由 NixieTable[] 数组决定
  *@retval 无
  *switch(Location) //显示第几位LED模块，P24,P23,P21引脚控制
  *P0 = NixieTable[Number]; //显示什么数字，P0寄存器控制
  *Delay(1); //数字显示1ms(稳定)
  *P0 = 0x00; //清零数字显示(消影)
  */
void Nixie(unsigned char Location, Number){
	switch(Location){
		case 1: P2_4=1;P2_3=1;P2_2=1;break;
		case 2: P2_4=1;P2_3=1;P2_2=0;break;
    case 3: P2_4=1;P2_3=0;P2_2=1;break;
    case 4: P2_4=1;P2_3=0;P2_2=0;break;
    case 5: P2_4=0;P2_3=1;P2_2=1;break;
    case 6: P2_4=0;P2_3=1;P2_2=0;break;
    case 7: P2_4=0;P2_3=0;P2_2=1;break;
    case 8: P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0 = NixieTable[Number];
	Delay(1);
	P0 = 0x00;
}