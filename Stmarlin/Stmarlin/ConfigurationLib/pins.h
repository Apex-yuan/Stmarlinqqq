#ifndef __PINS_H
#define __PINS_H


#define PS_ON_PIN     PF12//PFout(12) //Ŀǰ���������ҷ���ģ�����Ҫ����ʵ�ʵ�·��������

#define X_ENABLE_PIN   PF10  //PFout(10)
#define X_DIR_PIN      PF8  //PFout(8)
#define X_STEP_PIN     PF9  //PFout(9) 

#define Y_ENABLE_PIN   PF7  //PFout(7)  
#define Y_DIR_PIN      PF5  //PFout(5) 
#define Y_STEP_PIN     PF6  //PFout(6)     

#define Z_ENABLE_PIN   PF4  //PFout(4)
#define Z_DIR_PIN      PF2  //PFout(2) 
#define Z_STEP_PIN     PF3  //PFout(3) 

#define E0_ENABLE_PIN  PF1  //PFout(1) 
#define E0_DIR_PIN     PE6  //PEout(6) 
#define E0_STEP_PIN    PF0  //PFout(0)         
    
#define E1_ENABLE_PIN  PE5  //PEout(5)
#define E1_DIR_PIN	   PE3  //PEout(3) 
#define E1_STEP_PIN    PE4  //PEout(4)	 


#define X_MAX_PIN      PA4  //PAin(4)//4
#define X_MIN_PIN      PA5  //PAin(5)//5
#define Y_MAX_PIN      PA6  //PAin(6)//6
#define Y_MIN_PIN      PA7  //PAin(7)//7
#define Z_MAX_PIN      PC4  //PCin(4)//4
#define Z_MIN_PIN      PC5  //PCin(5)//5 

//���ģ��PWM��������������ż���
#define  HEATER_0_PIN   PB0   //PBout(0)	  //E0_PWM  
//#define HEATER_1_PIN  PF11  //PFout(11)	  //E1_PWM 
#define  HEATER_BED_PIN PF13  //PFout(13)	  //BED_PWM
#define  FAN_0_PIN      PF11  //PFout(11)   	//E0_FAN  //����ͷɢ��Ƭ�ϵķ���
#define  FAN_1_PIN      PF12  //PFout(12)   //E1_FAN  
#define  FAN_BED_PIN    PF14  //PFout(14)	  //BED_FAN
#define  FAN_PIN        PB1   //PBout(1)     //ģ��ɢ�ȵķ��ȣ���������ߴ�ӡ������ͨ����Ƭ�������M106 S255

//2016/12/26
//Arduino��ADCģ��ķֱ���Ϊ10λ���ȶ�STM32��ADCģ��ķֱ���Ϊ12λ���ȡ�Ŀǰ���õ��¶Ȳ������
//ԭ�̼��е��¶Ȳ���ʴ˴���Ҫ�����Ƚ�����λ(����2λ�����4)���������python��������һ���¶Ȳ��
//�ĳ�12λ���ȵ�ֵ�ô��Ͳ�������2�ˡ�
//2017/1/12
//ͨ���޸������¶Ȳ���.py�ļ��������������ʺ���stm32Ӧ�õ��¶Ȳ���ʽ����涨���¶�����ʱ��������λȥ�����ˡ�
#define TEMP_0_PIN	   PC0  //((Get_Adc(ADC_Channel_10)))   						// PC0 ADC3_10	E0_TEMP
//#define TEMP_1_PIN	 PC1  //((Get_Adc(ADC_Channel_11)))   						// PC1 ADC3_11	E1_TEMP
#define TEMP_BED_PIN   PC2  //((Get_Adc(ADC_Channel_12)))   						// PC2 ADC3_12  BED_TEMP
#define TEMP_ROOM_PIN  PC3  //((Get_Adc(ADC_Channel_13)))               // PC3 ADC3_13  BED_TEMP


#endif //__PINS_H
