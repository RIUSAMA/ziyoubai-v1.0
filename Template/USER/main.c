#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "sys.h"
#include "led.h"
#include "adc.h"
#include "oled.h"
#include "bmp.h"
#include "timer.h"

//ALIENTEK ̽����STM32F407������ ʵ��0
//STM32F4����ģ��-�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK
//OLEDһ���ַ���16��8

int main(void)
{
	u16 adcx;
	u16 angle;
	float temp;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);    //��ʼ����ʱ����
	OLED_Init();				//��ʼ��OLED
	uart_init(                                                                          115200);	//��ʼ�����ڲ�����Ϊ115200
	LED_Init();					//��ʼ��LED 
	Adc_Init();         //��ʼ��ADC
	TIM3_Int_Init(500-1,8400-1);	//��ʱ��ʱ��84M����Ƶϵ��8400������84M/8400=10Khz�ļ���Ƶ�ʣ�����5000��Ϊ500ms  
//	OLED_Init();				//��ʼ��OLED
//	OLED_ShowString(8,0,"OLED_init...",16);
//	delay_ms(50);
//	OLED_ShowString(80,0,"SUCCESS",16);
//	
//	OLED_ShowString(8,16,"delay_init...",16);
//	delay_init(168);    //��ʼ����ʱ����
//	delay_ms(50);
//	OLED_ShowString(80,16,"SUCCESS",16);
//	
//	OLED_ShowString(8,32,"uart_init...",16);
//	uart_init(115200);	//��ʼ�����ڲ�����Ϊ115200
//	delay_ms(50);
//	OLED_ShowString(80,32,"SUCCESS",16);
//	
//	OLED_ShowString(8,48,"LED_init...",16);
//	LED_Init();					//��ʼ��LED 
//	delay_ms(50);
//	OLED_ShowString(80,48,"SUCCESS",16);
//	
//	OLED_ShowString(8,64,"ADC_init...",16);
//	Adc_Init();         //��ʼ��ADC
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
//		adcx=Get_Adc_Average(ADC_Channel_5,20);//��ȡͨ��5��ת��ֵ��20��ȡƽ��
//		OLED_ShowNum(64,16,adcx,4,16);				//��ʾADCC�������ԭʼֵ
//		printf("%d\r\n",adcx);
//		temp=(float)adcx*(3.3/4096);          //��ȡ�����Ĵ�С����ʵ�ʵ�ѹֵ������3.1111
//		angle=adcx*360/4096;								//��ȡ�����������Ƕ�ֵ
//		printf("%f\r\n",temp);
//		printf("%d\r\n",angle);
//		adcx=temp;                            //��ֵ�������ָ�adcx��������ΪadcxΪu16����
//		OLED_ShowNum(40,32,adcx,1,16);				//��ʾ��ѹֵ���������֣�3.1111�Ļ������������ʾ3
//		temp-=adcx;                           //���Ѿ���ʾ����������ȥ��������С�����֣�����3.1111-3=0.1111
//		temp*=1000;                           //С�����ֳ���1000�����磺0.1111��ת��Ϊ111.1���൱�ڱ�����λС����
//		OLED_ShowNum(56,32,temp,3,16);				//��ʾС�����֣�ǰ��ת��Ϊ��������ʾ����������ʾ�ľ���111.
//		OLED_ShowNum(56,48,angle,3,16);				//��ʾ�Ƕ�ֵ
//		OLED_Refresh();
		LED0=!LED0;
		delay_ms(50);	
	}
}

/*
�ֲ��н��⵽����15��ʱ���main.cԴ�����£�
#include "stm32f4xx.h"

//ALIENTEK ̽����STM32F407������ ʵ��0
//STM32F4����ģ��-�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK
  
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


