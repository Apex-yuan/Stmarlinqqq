/**
  ******************************************************************************
  * @file    main.c
  * @author  xiaoyuan
  * @version V2.0.0
  * @date    2018-1-29
  * @brief   �ṩC�������������
  ******************************************************************************
  * @attention
  *
  ******************************************************************************
  */
  
#include "stmarlin.h"
#include "usart.h"
#include "timer.h"
#include "delay.h"

#include "key.h"
#include "exfuns.h"
#include "flash.h"
#include "lcd12864.h"
#include "lcd12864_menu.h"
#include "malloc.h"

/**
  * @brief  C������������һ��C���Ժ���ִ����ʼ�ĵط�
  * @param  none
  * @retval none
  */
int main(void)
{	
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2

  delay_init();			     //��ʱ��ʼ��
 	Usart1Init(BAUDRATE); 	 //����1��ʼ��  
  TIM3_Int_Init(9,7199);  //���ڷ���ϵͳ����ʱ�䣨1ms��ʱ�жϣ�
  TIM2_Int_Init(99,7199); //���ڰ����Ķ�ʱ��⣨10ms��ʱ�жϣ�
  
   	 KEY_Init();				//������ʼ�� 
	 //AT24CXX_Init();    //AT24CXX��ʼ�� 
	 SPI_Flash_Init();  //W25Qxx��ʼ��
	 LCD12864_Init();   //ST7920 lcd12864�ײ������ĳ�ʼ��
	 //*****************************��ʼ�����������	****************************// 										  
   mem_init();				      //�ڴ�س�ʼ��
   exfuns_init();		        //Ϊfatfs��ر��������ڴ�
   f_mount(fs[0],"0:",1); 	//����SD��  
//   f_mount(fs[1],"1:",1); 	//���ع���FLASH.	
	 lcd_menuInit();          //��Ļ�˵���ʼ��
  
 	setup(); //ִ�д�ӡ��������ĳ�ʼ������
  
	while(1) 
	{		
		loop(); //��ӡ����ѭ����
	}
  //return 0;
}

/////�����ļ�ϵͳ
//#include "exfuns.h"
//#include "ff.h"
//#include "malloc.h"
//#include "cardreader.h"

//int main(void)
//{
//  u32 total,free;
//  Usart1Init(BAUDRATE); 	 //����1��ʼ��
//  exfuns_init();							//Ϊfatfs��ر��������ڴ�				 
//  f_mount(fs[0],"0:",1); 					//����SD�� 
//  
//  while(exf_getfree("0",&total,&free))	//�õ�SD������������ʣ������
//	{
//		printf("SD Card Fatfs Error!\n");
//	}								
//  printf("FATFS OK!\n");
//  printf("SD Total Size: %ldMB",total>>10); //��ʾSD�������� MB
//  printf("SD  Free Size: %ldMB",free>>10); //��ʾSD��ʣ������ MB
//  
////  gcode_ls("0:\\GCODE");
//  
//  while(1)
//  {
//    
//  }
//}
