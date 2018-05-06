#ifndef __STMARLIN_H
#define __STMARLIN_H

/* Stmarlin�ײ�����ͷ�ļ� */
#include "Configuration.h"
#include "pins.h"
#include "fastio.h"
/*ST��׼��ͷ�ļ�*/
#include "stm32f10x.h"
/* C��׼�⺯��ͷ�ļ� */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>
#include <stdbool.h>
#include <string.h>


#define VERSION_STRING  "2.0.0"

//avr��Ƭ�����ù����ṹ��������洢�������ݴ洢���ֿ��������ݴ洢��RAMͨ���Ƚ�С��������洢��Flash�ռ�Ƚϴ�
//��˾���Ҫ��ռ�ÿռ�ϴ�Ĳ���Ҫ�ı�����ݷ���Flash�С�
//#define __ATTR_PROGMEM__ __attribute__((__progmem__))
//#define PROGMEM __ATTR_PROGMEM__
//# define PSTR(s) ((const PROGMEM char *)(s)) //��������һ����ָ̬�룬��ָ��ָ�����洢���ռ��е�һ���ַ���

#define	PSTR(s) ((const char*)(s)) //����һ����ָ̬�룬��ָ��ָ�����ݴ洢����һ���ַ�������s //P����ָ�룬STR�����ַ��� 
//#define true 0x1
//#define false 0x00
//#define bool u8
 
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
//#define round(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define square(x) x*x
//#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt))) //�޷�����



#define OK_KEY (Get_Adc_Average(ADC_Channel_15,10)>3250)

void get_command(void);
void process_commands(void);
void manage_inactivity(void);

#define  enable_x()  WRITE(X_ENABLE_PIN, X_ENABLE_ON)  //X_ENABLE_PIN = X_ENABLE_ON
#define disable_x()	 WRITE(X_ENABLE_PIN, !X_ENABLE_ON)  //X_ENABLE_PIN = !X_ENABLE_ON

#define  enable_y()  WRITE(Y_ENABLE_PIN, Y_ENABLE_ON)  //Y_ENABLE_PIN=Y_ENABLE_ON
#define disable_y()	 WRITE(Y_ENABLE_PIN, !Y_ENABLE_ON)  //Y_ENABLE_PIN=!Y_ENABLE_ON

#define  enable_z()  WRITE(Z_ENABLE_PIN, Z_ENABLE_ON)  //Z_ENABLE_PIN=Z_ENABLE_ON
#define disable_z()	 WRITE(Z_ENABLE_PIN, !Z_ENABLE_ON)  //Z_ENABLE_PIN=!Z_ENABLE_ON

#define  enable_e0() WRITE(E0_ENABLE_PIN, E_ENABLE_ON)  //E0_ENABLE_PIN=E_ENABLE_ON
#define disable_e0() WRITE(E0_ENABLE_PIN, !E_ENABLE_ON)  //E0_ENABLE_PIN=!E_ENABLE_ON

#define  enable_e1() WRITE(E1_ENABLE_PIN, E_ENABLE_ON)  //E1_ENABLE_PIN=E_ENABLE_ON
#define disable_e1() WRITE(E1_ENABLE_PIN, !E_ENABLE_ON)  //E1_ENABLE_PIN=!E_ENABLE_ON

enum AxisEnum {X_AXIS=0, Y_AXIS=1, Z_AXIS=2, E_AXIS=3};

#define SERIAL_ERROR_START	printf("Error:")
#define SERIAL_ECHO_START	printf("echo:")
void loop(void);
void setup(void);
void FlushSerialRequestResend(void);
void ClearToSend(void);

//extern inline void gcode_G4(void);


void get_coordinates(void);
void prepare_move(void);
void kill(void);
void Stop(void);

bool IsStopped(void);

void enquecommand(const char *cmd); //put an ascii command at the end of the current buffer.
//void enquecommand_P(const char *cmd); //put an ascii command at the end of the current buffer, read from flash
void prepare_arc_move(uint8_t isclockwise);

void clamp_to_software_endstops(float target[3]);

#define CRITICAL_SECTION_START  __disable_irq();
#define CRITICAL_SECTION_END    __enable_irq();
extern float homing_feedrate[];
extern bool axis_relative_modes[];
extern int feedmultiply;
extern int extrudemultiply; // Sets extrude multiply factor (in percent)
extern float current_position[NUM_AXIS] ;
extern float add_homeing[3];
extern float min_pos[3];
extern float max_pos[3];
extern int fanSpeed;
extern unsigned long starttime;
#ifdef BARICUDA
extern int ValvePressure;
extern int EtoPPressure;
#endif

#ifdef FWRETRACT
extern bool autoretract_enabled;
extern bool retracted;
extern float retract_length, retract_feedrate, retract_zlift;
extern float retract_recover_length, retract_recover_feedrate;
#endif

extern unsigned long starttime;
extern unsigned long stoptime;

extern bool lcd_contiune_print_after_poweroff;
extern unsigned long poweroff_sdpos;
extern float poweroff_position_z;
extern char poweroff_printing_filename[30];

// Handling multiple extruders pins
extern uint8_t active_extruder;
#endif
