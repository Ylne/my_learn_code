#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"



#define KEY0  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)//读取按键0
#define KEY1  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3)//读取按键1
#define KEY2   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)//读取按键3
#define KEY3   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)//读取按键4 
 

#define KEY0_PRES	1		 
#define KEY1_PRES	2		
#define KEY2_PRES	3		 
#define KEY3_PRES	4	

void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8 mode);  	//按键扫描函数					    
#endif
