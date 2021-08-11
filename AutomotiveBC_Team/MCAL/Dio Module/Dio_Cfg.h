/*
 * Dio_Cfg.h
 *
 * Created: 7/13/2021 7:54:56 PM
 *  Author: Ahmed Nabil
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "..\ATMega32_Registers.h"

#define DIO_USED_PINS_NUM		13

/* DIO Configured Port ID's  */
#define DioConf_LCD_RS_PORT_NUM				PORT_A
#define DioConf_LCD_RW_PORT_NUM				PORT_A
#define DioConf_LCD_E_PORT_NUM				PORT_A
#define DioConf_LCD_D4_PORT_NUM				PORT_A
#define DioConf_LCD_D5_PORT_NUM				PORT_A
#define DioConf_LCD_D6_PORT_NUM				PORT_A
#define DioConf_LCD_D7_PORT_NUM				PORT_A
#define DioConf_IN1_D2_PORT_NUM				PORT_D
#define DioConf_IN2_D3_PORT_NUM				PORT_D
#define DioConf_PWM_D4_PORT_NUM				PORT_D
#define DioConf_IN3_D6_PORT_NUM				PORT_D
#define DioConf_IN4_D7_PORT_NUM				PORT_D
#define DioConf_BTN1_B3_PORT_NUM			PORT_B

/* DIO Configured Channel ID's */
#define DioConf_LCD_RS_PIN_NUM				PIN_1
#define DioConf_LCD_RW_PIN_NUM				PIN_2
#define DioConf_LCD_E_PIN_NUM				PIN_3
#define DioConf_LCD_D4_PIN_NUM				PIN_4
#define DioConf_LCD_D5_PIN_NUM				PIN_5
#define DioConf_LCD_D6_PIN_NUM				PIN_6
#define DioConf_LCD_D7_PIN_NUM				PIN_7
#define DioConf_IN1_D2_PIN_NUM				PIN_2
#define DioConf_IN2_D3_PIN_NUM				PIN_3
#define DioConf_PWM_D4_PIN_NUM				PIN_4
#define DioConf_IN3_D6_PIN_NUM				PIN_6
#define DioConf_IN4_D7_PIN_NUM				PIN_7
#define DioConf_BTN1_B3_PIN_NUM				PIN_2

/* Channel Index in the array of structures in Dio_Cfg.c */
#define DIO_LCD_RS_CHANNEL_ID				0
#define DIO_LCD_RW_CHANNEL_ID				1
#define DIO_LCD_E_CHANNEL_ID				2
#define DIO_LCD_D4_CHANNEL_ID				3
#define DIO_LCD_D5_CHANNEL_ID				4
#define DIO_LCD_D6_CHANNEL_ID				5
#define DIO_LCD_D7_CHANNEL_ID				6
#define DIO_IN1_CHANNEL_ID					7
#define DIO_IN2_CHANNEL_ID					8
#define DIO_PWM_CHANNEL_ID					9
#define DIO_IN3_CHANNEL_ID					10
#define DIO_IN4_CHANNEL_ID					11
#define DIO_BTN1_CHANNEL_ID					12
#endif /* DIO_CFG_H_ */