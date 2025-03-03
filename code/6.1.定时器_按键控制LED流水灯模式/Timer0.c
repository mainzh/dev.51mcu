#include <REGX52.H>

/**
	*@brief 定时器0初始化，1毫秒@12.000MHz
	*@param 无
	*@retval 无
	*TMOD定时器模式寄存器
	 TMOD = 0x01; //0000 0001 这会影响高4位代表的定时器1的状态   
	 TMOD &= 0xf0; 即TMOD = TMOD & 0xf0;
   TMOD |= 0x01; 即TMOD = TMOD | 0x01;
	 
	*TL0 = 64535 % 256 +1; //Timer Low 0设初值 这里有差1us：不+1，则=23，十六进制为0x17；+1 则=24 十六进制为0x18
   TH0 = 64535 / 256; //Timer High 0 设初值 约等于252 十六进制为0xfc
	 **16位定时器1ms推导
   TL0、TH0共可计数0——65535
   选择12T模式，每隔1us计数 +1，共可计65535us
   则64535us 离计数器溢出 65535us 差值 1000us，即计时时间为1ms
   将64535 分开到TL0、TH0
   若十进制123 分开到两个0——99的盒子中：
   低位123%100=23  高位123/100=1  就分开到高低位中
	*TCON定时器控制寄存器
	 TF0 = 0; //定时器T0溢出中断标志 清零
   TR0 = 1; //定时器T0的运行控制位 开启计数
	*配置中断寄存器ET0、EA、PT0
	*/
void Timer0_Init()
{
	TMOD &= 0xF0; //设置定时器模式
	TMOD |= 0x01; //设置定时器模式
	TL0 = 0x18; //设置定时初值
	TH0 = 0xFC; //设置定时初值
	TF0 = 0; //清除TF0标志
	TR0 = 1; //定时器0开始计时
  ET0 = 1; //T0的溢出中断允许位
  EA = 1; //CPU总中断允许控制位
  PT0 = 0; //定时器0中断优先级控制位 默认为0  
}

/**
  *@brief 定时器中断子程序  模板 (放在主函数下面)
  *@param 无
  *@retval 无
	*函数体改成自己的函数
	*static unsigned int T0Count; 加static 将变量定义成静态局部变量，退出此函数时变量值不会被清除
	 也可不加static ，但要把此变量定义放外面变成全局变量
	*重新赋初值1ms
	 TL0 = 0x18; //设置定时初值
	 TH0 = 0xFC; //设置定时初值
	*T0Count ++; //每执行一次该中断子程序(1ms)，将变量T0Count +1
	*if(T0Count >= 1000) //若计数 1000次 后，即过1s后，执行if中程序
	 T0Count = 0; //将计数清零，重新计数，过1s后，再次执行if中程序
****
void Timer0_Rountine() interrupt 1
{
    static unsigned int T0Count;
    TL0 = 0x18;
	  TH0 = 0xFC;
    T0Count ++;
    if(T0Count >= 1000)
    {
        T0Count = 0;
        函数体;
    }
}
  */