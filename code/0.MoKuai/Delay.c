
/**
  *@brief 延时函数 1ms@12MHz
  *@param ms毫秒
  *@retval 无
	* 用stc-isp工具生成延时1ms程序，再改变到延时任意ms
	* while(ms--) //当 ms !=0，执行延时1ms；再 ms-1 != 0，执行延时1ms；循环，直到 ms=0，程序结束
  */
void Delay(unsigned int ms){
	unsigned char i,j;
	while(ms--){
		i = 2;
		j = 239;
		do{
			while(--j);
		} while(--i);
	}
}