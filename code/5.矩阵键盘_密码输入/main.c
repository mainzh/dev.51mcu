#include "MatrixKey.h"
#include "LCD1602.h"

/**
  *@brief 矩阵键盘输入密码
  *@param 无
  *@retval 无
	*if(KeyNumber <= 10) //若按下S1——S10按键，输入密码
	*if(count < 4) //如果输入次数<4，执行下面的程序，输入超过4次，则无效
	*PassWord *= 10; //密码左移一位
	 初始密码0000
       输入1
           0000*10 = 0000
           0000+1  = 0001
       输入2
           0001*10 = 0010
           0010+2  = 0012
       输入3
           0012*10 = 0120
           0120+3  = 0123
	*PassWord += KeyNumber % 10; //获取一位密码，若为S10则将S10赋值为0
	*if(KeyNumber = 11) //若按下S11按键，确认
	*if(KeyNumber = 12) //若按下S12按键，取消
  */
unsigned char KeyNumber;
unsigned int PassWord,count;
void main()
{
    LCD_Init();
    LCD_ShowString(1,1,"MatrixKey:");
    while(1)
    {
        KeyNumber = MatrixKey();
        if(KeyNumber)
        {
            if(KeyNumber <= 10)
            {
                if(count < 4)
                {
                PassWord *= 10;
                PassWord += KeyNumber % 10;
                count++; //计次+1
                }
                LCD_ShowNum(2,1,PassWord,4); //更新显示
            }
            if(KeyNumber == 11)
            {
                if(PassWord == 2345) //如果密码 = 正确密码
                {
                    LCD_ShowString(1,14,"OK "); //显示OK
                    PassWord = 0; //密码清零
                    count = 0; //计次清零
                    LCD_ShowNum(2,1,PassWord,4); //更新显示
                }
                else
                {
                    LCD_ShowString(1,14,"ERR"); //显示ERR
                    PassWord = 0; //密码清零
                    count = 0; //计次清零
                    LCD_ShowNum(2,1,PassWord,4); //更新显示
                }
            }
            if(KeyNumber == 12)
            {
                PassWord = 0; //密码清零
                count = 0; //计次清零
                LCD_ShowNum(2,1,PassWord,4); //更新显示
            }
        }
    }
}