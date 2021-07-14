#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "sys.h"
#include "led.h"
#include "adc.h"
#include "oled.h"
#include "bmp.h"
#include "timer.h"

//ALIENTEK 探索者STM32F407开发板 实验0
//STM32F4工程模板-库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK
//OLED一个字符高16宽8

int main(void)
{
	u16 adcx;
	u16 angle;
	float temp;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);    //初始化延时函数
	OLED_Init();				//初始化OLED
	uart_init(                                                                          115200);	//初始化串口波特率为115200
	LED_Init();					//初始化LED 
	Adc_Init();         //初始化ADC
	TIM3_Int_Init(500-1,8400-1);	//定时器时钟84M，分频系数8400，所以84M/8400=10Khz的计数频率，计数5000次为500ms  
//	OLED_Init();				//初始化OLED
//	OLED_ShowString(8,0,"OLED_init...",16);
//	delay_ms(50);
//	OLED_ShowString(80,0,"SUCCESS",16);
//	
//	OLED_ShowString(8,16,"delay_init...",16);
//	delay_init(168);    //初始化延时函数
//	delay_ms(50);
//	OLED_ShowString(80,16,"SUCCESS",16);
//	
//	OLED_ShowString(8,32,"uart_init...",16);
//	uart_init(115200);	//初始化串口波特率为115200
//	delay_ms(50);
//	OLED_ShowString(80,32,"SUCCESS",16);
//	
//	OLED_ShowString(8,48,"LED_init...",16);
//	LED_Init();					//初始化LED 
//	delay_ms(50);
//	OLED_ShowString(80,48,"SUCCESS",16);
//	
//	OLED_ShowString(8,64,"ADC_init...",16);
//	Adc_Init();         //初始化ADC
//	delay_ms(50);
//	OLED_ShowString(80,64,"SUCCESS",16);
//	
//	OLED_Clear();

	OLED_ShowString(8,0,"testing...",16);
	OLED_ShowString(8,16,"VAL:",16);
	OLED_ShowString(8,32,"VOL:0.000V",16);
	OLED_ShowString(8,48,"angle:",16);
	
	while(1)
	{ 
//		adcx=Get_Adc_Average(ADC_Channel_5,20);//获取通道5的转换值，20次取平均
//		OLED_ShowNum(64,16,adcx,4,16);				//显示ADCC采样后的原始值
//		printf("%d\r\n",adcx);
//		temp=(float)adcx*(3.3/4096);          //获取计算后的带小数的实际电压值，比如3.1111
//		angle=adcx*360/4096;								//获取计算后的整数角度值
//		printf("%f\r\n",temp);
//		printf("%d\r\n",angle);
//		adcx=temp;                            //赋值整数部分给adcx变量，因为adcx为u16整形
//		OLED_ShowNum(40,32,adcx,1,16);				//显示电压值的整数部分，3.1111的话，这里就是显示3
//		temp-=adcx;                           //把已经显示的整数部分去掉，留下小数部分，比如3.1111-3=0.1111
//		temp*=1000;                           //小数部分乘以1000，例如：0.1111就转换为111.1，相当于保留三位小数。
//		OLED_ShowNum(56,32,temp,3,16);				//显示小数部分（前面转换为了整形显示），这里显示的就是111.
//		OLED_ShowNum(56,48,angle,3,16);				//显示角度值
//		OLED_Refresh();
		LED0=!LED0;
		delay_ms(50);	
	}
}

/*
手册中讲解到步骤15的时候的main.c源码如下：
#include "stm32f4xx.h"

//ALIENTEK 探索者STM32F407开发板 实验0
//STM32F4工程模板-库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK
  
void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}

int main(void)
{

  GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOF, &GPIO_InitStructure);

  while(1){
		GPIO_SetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		Delay(0x7FFFFF);
		GPIO_ResetBits(GPIOF,GPIO_Pin_9|GPIO_Pin_10);
		Delay(0x7FFFFF);
	
	}
}
*/


