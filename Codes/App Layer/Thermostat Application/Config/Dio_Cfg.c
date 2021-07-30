/*
 * Dio_Cfg.c
 *
 * Created: 7/13/2021 7:55:09 PM
 *  Author: Ahmed Nabil
 */ 

#include "Dio_Cfg.h"
#include "Dio.h"

strDio_Config_t strDio_pins[DIO_USED_PINS_NUM]=
{
	{DioConf_COL_1_PORT_NUM, DioConf_COL_1_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_HIGH},
	{DioConf_COL_2_PORT_NUM, DioConf_COL_2_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_HIGH},
	{DioConf_COL_3_PORT_NUM, DioConf_COL_3_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_HIGH},
	{DioConf_ROW_A_PORT_NUM, DioConf_ROW_A_PIN_NUM, DIO_PIN_DIR_INPUT, PIN_PUR},
	{DioConf_ROW_B_PORT_NUM, DioConf_ROW_B_PIN_NUM, DIO_PIN_DIR_INPUT, PIN_PUR},
	{DioConf_ROW_C_PORT_NUM, DioConf_ROW_C_PIN_NUM, DIO_PIN_DIR_INPUT, PIN_PUR},
	{DioConf_ROW_D_PORT_NUM, DioConf_ROW_D_PIN_NUM, DIO_PIN_DIR_INPUT, PIN_PUR},
	{DioConf_LCD_RS_PORT_NUM, DioConf_LCD_RS_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW},
	{DioConf_LCD_RW_PORT_NUM, DioConf_LCD_RW_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW},
	{DioConf_LCD_E_PORT_NUM, DioConf_LCD_E_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW},
	{DioConf_LCD_D4_PORT_NUM, DioConf_LCD_D4_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW},
	{DioConf_LCD_D5_PORT_NUM, DioConf_LCD_D5_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW},
	{DioConf_LCD_D6_PORT_NUM, DioConf_LCD_D6_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW},
	{DioConf_LCD_D7_PORT_NUM, DioConf_LCD_D7_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW},
	{DioConf_IN1_B0_PORT_NUM, DioConf_IN1_B0_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW},
	{DioConf_IN2_B1_PORT_NUM, DioConf_IN2_B1_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW},
	{DioConf_PWM_B2_PORT_NUM, DioConf_PWM_B2_PIN_NUM, DIO_PIN_DIR_OUTPUT, PIN_LOW}
};

