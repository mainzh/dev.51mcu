#include <REGX52.H>
#include "Delay.h"

/**
  *@brief 按键按下再松开，改变LED状态(按键消抖)
  *@param 无
  *@retval 无
  *if(P3_1 == 0){ //若P31为0，则判断按键K1:P31按下
     Delay(20); //延时20ms，按键按下消抖
     while(P3_1 == 0); //当按键仍按下，就执行空循环，否则判断按键松开，跳过此循环
     Delay(20); //延时20ms，按键松开消抖
     P2_0 = ~P2_0; //P20位取反，改变LED状态
   }
  */
void main(){
	while(1){
		if(P3_1 == 0){
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			P2_0 = ~P2_0;
		}
	}
}