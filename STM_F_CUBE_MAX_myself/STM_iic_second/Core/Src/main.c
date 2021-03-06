/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdint.h> 

char Hzk16[16][64]={
	
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xF8,0xF8,0xF0,0xF0,0xE0,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0xF8,0xF8,0xF8,0xF8,0xF0,0xE0,0xE0,0xC0,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x30,0x70,0xF0,0xF0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xE0,0xF8,0xFE,0xFF,0xFF,0xFF,0x7F,0x1F,0x0F,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x0F,0x3F,0x7F,0xFE,0xFE,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xF0,0xF8,0xFE,0xFF,0x7F,0x3F,0x0F,0x07,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x0F,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xF8,0xE0,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x30,0x38,0x3C,0x3E,0x1F,0x0F,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x1F,0x1F,0x1F,0x1F,0x0F,0x07,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x03,0x0F,0x1F,0x1F,0x1F,0x0F,0x0F,0x07,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"???",0*/
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0xF0,0xE0,0xC0,0xC0,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xC0,0xE0,0xF0,0xF0,0xF0},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xFE,0xFE,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0xFE,0xFF,0xFF,0xFF,0xFF,0xFE,0x0C,0x0C,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xFF,0xFF,0xFF,0xFF},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0xFF,0xFF,0xFF,0xFF},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x80,0xFF,0xFF,0xFF,0xFF,0xFF,0x19,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0xFF,0xFF,0xFF,0xFF},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x7F,0x7F,0x3F,0x3F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x0F,0x0F,0x0F,0x07,0x07,0x00,0x80,0xE0,0xF8,0xFF,0xFF,0xFF,0x7F,0x1F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xF0,0xF8,0xFC,0x7E,0x3F,0x1F,0x0F,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x60,0x60,0xE0,0xE0,0xE0,0xE0,0xE0,0xC0,0xC0,0xC0,0xE0,0xFF,0xFF,0xFF,0xFF},/*"???",1*/	
 
};
char suzu[20][16] = {/*--  ??????:  ???  --*/
/*--  ??????12;  ????????????????????????????????????x???=16x16   --*/
0x04,0xFC,0xFC,0xFC,0xFE,0xFE,0xFC,0xFC,0xFC,0xFC,0xFE,0xFE,0xFC,0xFC,0x74,0x00,
0x04,0xD4,0xD5,0x5F,0x7F,0xEF,0xBF,0xFF,0xFD,0x7D,0x1F,0x37,0x63,0x63,0xC0,0x00,

/*--  ??????:  ???  --*/
/*--  ??????12;  ????????????????????????????????????x???=16x16   --*/
0x10,0x10,0x10,0x10,0x10,0x10,0x10,0xFE,0xFE,0x10,0x10,0x10,0x10,0x10,0x10,0x00,
0x00,0x00,0xFF,0xFF,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0x81,0xFF,0xFF,0xFE,0x00,

/*--  ??????:  ???  --*/
/*--  ??????12;  ????????????????????????????????????x???=16x16   --*/
0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFE,0xFC,0x80,0x80,0x80,0x80,0x80,0x80,0x00,
0x80,0x80,0x80,0x80,0x80,0x80,0xFF,0xFF,0xFF,0x80,0x80,0x80,0x80,0x80,0x80,0x00,

/*--  ??????:  ???  --*/
/*--  ??????12;  ????????????????????????????????????x???=16x16   --*/
0x00,0xF0,0xF0,0x96,0x9E,0x9C,0x90,0xF0,0xF0,0x98,0x9C,0x9E,0xF6,0xF0,0x00,0x00,
0x10,0x13,0x17,0x14,0x14,0x14,0x14,0xFF,0xFF,0x14,0x14,0x14,0x17,0x17,0x10,0x00,

/*--  ??????:  ???  --*/
/*--  ??????12;  ????????????????????????????????????x???=16x16   --*/
0x20,0x20,0x20,0x20,0x20,0x20,0xA0,0xFE,0xFE,0x20,0x20,0x20,0x20,0x20,0x20,0x00,
0x80,0xC0,0xC0,0x60,0x70,0x3C,0x1F,0x07,0x07,0x0F,0x3C,0x70,0x60,0xC0,0xC0,0x00,

/*--  ??????:  ???  --*/
/*--  ??????12;  ????????????????????????????????????x???=16x16   --*/
0x00,0x80,0xFC,0xFE,0xFC,0x98,0xB8,0xB8,0x20,0xFE,0xFE,0x24,0x2C,0xBC,0xB8,0x00,
0x1F,0x7F,0x7F,0x60,0x60,0x7E,0xFF,0xFF,0xE0,0x73,0x3F,0x7E,0xEF,0x87,0xF9,0x00,

/*--  ??????:  ???  --*/
/*--  ??????12;  ????????????????????????????????????x???=16x16   --*/
0x08,0x08,0x08,0xE8,0xF8,0xB8,0xBA,0xBE,0xBE,0xB8,0xB8,0xF8,0xE8,0x08,0x08,0x00,
0x00,0xFE,0xFE,0x02,0x7B,0x7B,0x4B,0x4B,0x4B,0x4B,0xFB,0xFB,0x82,0xFE,0xFE,0x00,

/*--  ??????:  ???  --*/
/*--  ??????12;  ????????????????????????????????????x???=16x16   --*/
0x20,0x20,0xFE,0xFE,0x20,0x20,0xFC,0xFC,0xE4,0x64,0x64,0x64,0x66,0xE6,0xC6,0x00,
0x20,0x30,0x3F,0x9F,0xD8,0xF8,0xBF,0x8F,0xC7,0xDF,0x7C,0x78,0x7E,0xCF,0xC3,0x00,

/*--  ??????:  ???  --*/
/*--  ??????12;  ????????????????????????????????????x???=16x16   --*/
0x00,0x04,0x04,0x04,0xFC,0xFC,0x04,0x04,0x04,0x44,0xFC,0xFC,0xCC,0xC0,0x80,0x00,
0x80,0xC0,0xF0,0x3F,0x0F,0x01,0x40,0xC0,0xC0,0x80,0x80,0x80,0xC0,0xFF,0x3F,0x00,

/*--  ??????:  ???  --*/
/*--  ??????12;  ????????????????????????????????????x???=16x16   --*/
0x20,0x20,0xFE,0xFE,0xE0,0xFC,0xFC,0xB4,0xF4,0xF4,0xF4,0xF4,0xB4,0xFC,0xFC,0xFC,
0x0C,0x0F,0xFF,0xFF,0x07,0xFF,0xFF,0x1F,0x3F,0x3F,0xB0,0xBF,0xBF,0xFF,0xFF,0xFF,
};

char suzu2[4][37]= 
{0xE1,0x01,0x01,0x00,0x00,0x80,0x00,0x10,0x88,0x84,0x83,0x03,0x01,0x01,0x01,0x01,
0x01,0x01,0x03,0x03,0x03,0x07,0x07,0x0F,0x0F,0x0F,0x1F,0x5F,0xDF,0xFF,0xFF,0xFF,
0x7F,0xBF,0xBF,0x3E,0x3E,0x01,0x01,0x09,0x0D,0x3F,0xBF,0xFE,0x7F,0xCD,0xC7,0x07,
0x7E,0xF2,0x18,0x3A,0x38,0x18,0x08,0x00,0x00,0x08,0x0C,0x0C,0x04,0x0C,0x08,0x00,
0x1C,0x0F,0xFF,0x7F,0xCB,0xFE,0x3F,0x35,0x1F,0x03,0x00,0x00,0x00,0x00,0x04,0x01,
0x01,0x03,0x00,0x0C,0x00,0x01,0x00,0x00,0x00,0x70,0x60,0x20,0x00,0x00,0x00,0x00,
0x00,0x30,0x32,0xF6,0x00,0x00,0x32,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0xE0,
0xF0,0xFA,0xF8,0xC0,0xC0,0xE0,0xFE,0xFE,0xFF,0xFC,0xF0,0xE0,0xC0,0x84,0x38,0xF0,
0x80,0x00,0x68,0x38,0xF0,0xF0,0xF8,0xFC,0x3F,0xC4,0xFE,0xFE,0xFF,0xFF,0xFF,0xFA,
0xF0,0xC0,0xF8,0xF0
};
#define I2C_SCL_L() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET)/* I2C?????????????????????SCL*/
#define I2C_SCL_H() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET)							
#define I2C_SDA_L() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET)/* I2C?????????????????????SDA*/
#define I2C_SDA_H() HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET)
 
 
#define OLED_CMD  0	//?????????
#define OLED_DATA 1	//?????????
 
/*GPIO_WriteBit???GPIO_SetBits??????:
 *?????????IO??????0???1??? GPIO_WriteBit(GPIOA,GPIO_Pin_8 , 0);
 *???????????????IO??????1???GPIO_SetBits(GPIOD,GPIO_Pin_0 | GPIO_Pin_5 | GPIO_Pin_6);
 */

typedef unsigned char   u8t;      ///< range: 0 .. 255
void I2C_Start(void); 
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_WR_Byte(unsigned dat,unsigned cmd);
void OLED_ShowCHinese(u8t x,u8t y,u8t no,u8t font_height,u8t font_width);
void OLED_Clear(void);
void OLED_On(void);
void OLED_Display_On(void);
void Delay_us(uint32_t us); 
void SDA_OUT(void); 
void Write_I2C_Byte(unsigned char I2C_Byte);
void I2C_Wait_Ack(void);
void I2C_Stop(void);
unsigned char read_ack(void);
void I2C_Wait_Ack(void);

unsigned char read_ack()
{
	unsigned char is_ack;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
	Delay_us(1); 
	
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
	Delay_us(1);
	is_ack = 1;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	return is_ack;
}

void I2C_Wait_Ack()
{
	while (!read_ack() );
}
void SDA_OUT(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	/*Configure GPIO pins :  PB9 */
	GPIO_InitStruct.Pin = GPIO_PIN_7;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
}
 
void Write_I2C_Command(unsigned char I2C_Command){
	 I2C_Start();
	 Write_I2C_Byte(0x78);           					//????????????Address(7???+0)------>dec:120 = bin:01111000 = hex:0x78
	 I2C_Wait_Ack();	
	 Write_I2C_Byte(0x00);					                //??????????????????????????????-------->????????????
	 I2C_Wait_Ack();	
	 Write_I2C_Byte(I2C_Command); 
	 I2C_Wait_Ack();	
	 I2C_Stop();
}
 
/*I2C Write Data*/ 
void Write_I2C_Data(unsigned char I2C_Data){
	 I2C_Start();
	 Write_I2C_Byte(0x78);							//????????????
	 I2C_Wait_Ack();	
	 Write_I2C_Byte(0x40);							//??????????????????????????????
	 I2C_Wait_Ack();	
	 Write_I2C_Byte(I2C_Data);
	 I2C_Wait_Ack();	
	 I2C_Stop();
}
 
/*??????cmd???0??????????????????????????????
 *??????cmd???1??????????????????????????????
 */
void OLED_WR_Byte(unsigned dat,unsigned cmd){
	 if(cmd)
	 {
			Write_I2C_Data(dat);  	//?????????
	 }
	 else 
	 {
			Write_I2C_Command(dat);	//?????????
	 }
}
 
void  OLED_Init(){	 
	 Delay_us(200);
	 OLED_WR_Byte(0xAE,OLED_CMD);							//????????????
	
	 OLED_WR_Byte(0x40,OLED_CMD);			 				//????????????????????? [5:0],??????.
	 OLED_WR_Byte(0xB0,OLED_CMD);			   	 			//???????????????
 
	 OLED_WR_Byte(0xC8,OLED_CMD);							//????????????????????????
 
	 OLED_WR_Byte(0x81,OLED_CMD);							//???????????????
	 OLED_WR_Byte(0xFF,OLED_CMD);							
 
	 OLED_WR_Byte(0xA1,OLED_CMD);							//??????????????????
 
	 OLED_WR_Byte(0xA6,OLED_CMD);							//??????????????????;bit0:1,????????????;0,????????????
	
	 OLED_WR_Byte(0xA8,OLED_CMD);							//????????????????????????
	 OLED_WR_Byte(0x1F,OLED_CMD);
	
	 OLED_WR_Byte(0xD3,OLED_CMD);							//?????????????????????
	 OLED_WR_Byte(0x00,OLED_CMD);
	
	 OLED_WR_Byte(0xD5,OLED_CMD);
	 OLED_WR_Byte(0xF0,OLED_CMD);
	
	 OLED_WR_Byte(0xD9,OLED_CMD);							//?????????????????????
	 OLED_WR_Byte(0x22,OLED_CMD);
	
	 OLED_WR_Byte(0xDA,OLED_CMD);							//??????COM??????????????????
	 OLED_WR_Byte(0x02,OLED_CMD);							//[1:0],00??????????????????;01??????????????????;10,???????????????;??????10;
	
	 OLED_WR_Byte(0xDB,OLED_CMD);							//??????VCOMH ????????????
	 OLED_WR_Byte(0x49,OLED_CMD);
	
	 OLED_WR_Byte(0x8D,OLED_CMD);							//???????????????
	 OLED_WR_Byte(0x14,OLED_CMD);							
	 OLED_WR_Byte(0xAF,OLED_CMD);							//????????????
	 OLED_Clear();	 
}
 
/*??????*/
void OLED_Clear(void){  
	 u8t i,n;		    
	 for(i=0;i<8;i++)  
	 {  
			OLED_WR_Byte (0xb0+i,OLED_CMD);    				//??????????????????0~7???
			OLED_WR_Byte (0x00,OLED_CMD);      				//?????????????????????????????????
			OLED_WR_Byte (0x10,OLED_CMD);      				//?????????????????????????????????   
			for(n=0;n<128;n++)
			OLED_WR_Byte (0,OLED_DATA); 
	 } 														//????????????
}
 
/*??????????????????8?????????????????????while?????????????????????*/
void OLED_On(void){  
	 u8t i,n;		    
	 for(i=0;i<8;i++)  									 //8????????????
	 {  
			/*????????????????????????*/
			OLED_WR_Byte (0xb0+i,OLED_CMD);    				//??????????????????0~7???0xb0	 b2???b??????????????????2??????2?????? 
			OLED_WR_Byte (0x00,OLED_CMD);      				//?????????????????????????????????	 03???0?????????????????????3?????????4??????3???
			OLED_WR_Byte (0x10,OLED_CMD);      				//?????????????????????????????????	 10: 1?????????????????????0?????????3??????0???
		
			for(n=0;n<128;n++)
			OLED_WR_Byte (1,OLED_DATA);			                //128???????????????????????????
	 } 														//????????????
}
 
void OLED_Display_On(void){
	 OLED_WR_Byte(0X8D,OLED_CMD);  				  			//SET DCDC??????
	 OLED_WR_Byte(0X14,OLED_CMD);  				  			//DCDC ON
	 OLED_WR_Byte(0XAF,OLED_CMD);  				  			//DISPLAY ON
}

 
void I2C_Start()
{	
	SDA_OUT();    												
	I2C_SCL_H();	
	Delay_us(1);	
	I2C_SDA_H();
	Delay_us(1);
	I2C_SDA_L();
	Delay_us(1);
	
}
 
void I2C_Stop()
{
	 SDA_OUT();
	 I2C_SCL_H();
	 Delay_us(1);
	 I2C_SDA_L();
	 Delay_us(1);
	 I2C_SDA_H();	
	 Delay_us(1);
	
}
 
/*??????C?????????????????????????????????C51????????????????????????????????????????????????????????????????????????????????????NOp??????
 *?????????????????????????????????8M????????????????????????1us*/
void Delay_us(uint32_t  us)                	
{
	uint32_t i;
 
        for(i = 0; i < us; i++)
	{
		__nop();	                											
	}
}
 
void I2C_SDA_IN(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};	
	
	/*Configure GPIO pins :  PB9 */
	GPIO_InitStruct.Pin = GPIO_PIN_7;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
 
}
 

 
void I2C_SCL_OUT(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	/*Configure GPIO pins :  PB8 */
	GPIO_InitStruct.Pin = GPIO_PIN_6;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
}
void I2C_Ack(void)
{
  SDA_OUT();
	I2C_SCL_H();
	Delay_us(2);
	I2C_SDA_L();
	Delay_us(4);
	I2C_SDA_H();
	Delay_us(2);
	I2C_SCL_L();
	Delay_us(2);
 
}
 
void I2C_NAck(void)
{
	SDA_OUT();
	I2C_SCL_H();
	Delay_us(2);
	I2C_SDA_H();
	Delay_us(4);
	I2C_SDA_L();
	Delay_us(2);
	I2C_SCL_L();
	Delay_us(2);
 
}


void Write_I2C_Byte(unsigned char I2C_Byte){
	 unsigned char i;
	 unsigned char m,da;
	 da=I2C_Byte;
	 I2C_SCL_L();
 	 for(i=0;i<8;i++)
	 {
			m=da;
			m=m&0x80;
			if(m==0x80)				//0x80:1000 0000????????????1 ????????????????????????????????????????????????I2C_Byte?????????????????????
				{I2C_SDA_H();}
			else 
				I2C_SDA_L();
			da=da<<1;
			I2C_SCL_H();
			Delay_us(5);	
			I2C_SCL_L();
			Delay_us(1);	
	 }
}

 
/*???????????????????????????????????????????????????*/
void OLED_Set_Pos(unsigned char x, unsigned char y)
{ 	
	 OLED_WR_Byte(0xb0+y,OLED_CMD);
	 OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);
	 OLED_WR_Byte((x&0x0f),OLED_CMD); 
} 
 
/*????????????
 *?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
 *x??????????????????????????????  
 *y: ??????????????????????????? 
 *no: ???????????????????????????????????????hzk[][]??????????????????,???????????????????????????????????????????????????
 *??????????????????font_width???????????????????????????????????????????????????????????????????????????
 *font_height?????????????????????????????????????????????????????????,????????????????????????32*128-----0~7???8????????????4??????
 */
void OLED_ShowCHinese(u8t x,u8t y,u8t no,u8t font_width,u8t font_height){     			    
	u8t t, i;
        for(i=0;i<(font_height/8);i++)				/*font_height????????????32??????????????????8????????????????????????4??????*/
	 {
			OLED_Set_Pos(x,y+i);	
			for(t=0;t<font_width;t++)		/*font_width????????????128????????????????????????*/
			{	
					OLED_WR_Byte(suzu2[(font_height/8)*no+i][t],OLED_DATA);
			}		
	 }		
}

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint8_t i, j;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
	
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
	 
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	OLED_Init();
		OLED_Display_On();
    OLED_On(); 

    OLED_ShowCHinese(0,0,0,64,64);        /*???*/
    OLED_ShowCHinese(64,0,1,64,64);       /*???*/
		
    OLED_Clear();
		OLED_ShowCHinese(0,0,0,16,16);
		OLED_ShowCHinese(16,0,1,16,16);
		OLED_ShowCHinese(32,0,2,16,16);
		OLED_ShowCHinese(48,0,3,16,16);
		OLED_ShowCHinese(64,0,4,16,16);
		OLED_ShowCHinese(80,0,5,16,16);
		OLED_ShowCHinese(96,0,6,16,16);
		OLED_ShowCHinese(112,0,7,16,16);
		OLED_ShowCHinese(0,2,8,16,16);
		OLED_ShowCHinese(16,2,9,16,16);
		HAL_Delay(200);
		OLED_Clear();
		
		OLED_ShowCHinese(0,0,0,37,32);
		HAL_Delay(200);
		OLED_Clear();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	
	} 														//????????????

  
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

