/************************************************************************************************
* ����汾��V2.1
* �������ڣ�2021-12-8
* �������ߣ�719������ʵ���ң� 
*						����
*						���
************************************************************************************************/
#ifndef   _MAIN_H
#define   _MAIN_H

#include "stdio.h"
#include "stm32f10x.h"
#include "nvic.h"
#include "structconfig.h"
#include "delay.h"
#include "led.h"
#include "usart.h"
#include "iic.h"
#include "tim.h"
#include "mpu6050.h"
#include "imu.h"
#include "pid.h"
#include "control.h"
#include "flash.h"
#include "paramsave.h"
#include "power.h"
#include "remotedata.h"
#include "rc.h"
#include "motor.h"
#include "filter.h"
#include "math.h"



#include "oled.h"
void System_Init(void);
void Task_Schedule(void);


#endif

