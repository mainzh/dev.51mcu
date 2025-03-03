#include "Nixie.h"

/**
  *@brief LED数码管_动态显示 (单片机直接扫描，加上消影)
  *@param 无
  *@retval 无
	* 第几位显示几
  */
void main(){
	while(1){
		Nixie(1,1);
		Nixie(2,2);
		Nixie(3,3);
		Nixie(4,4);
		Nixie(5,5);
		Nixie(6,6);
		Nixie(7,7);
		Nixie(8,8);
	}
}