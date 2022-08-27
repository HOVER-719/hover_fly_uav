/************************************************************************************************
* 程序版本：V2.1
* 程序日期：2021-12-8
* 程序作者：719飞行器实验室： 
*						张润
*						杨晨阳
************************************************************************************************/

#include "main.h"

/************************************************************************************************
* 函  数：void System_Init(void)
* 功  能：初始化函数
* 参  数：    
* 返回值：无 
* 备  注：本程序为STM32飞控新生比赛精简版
************************************************************************************************/
void System_Init(void)
{
	
	LED_Init();										//状态指示灯初始化
	NvicConfig(); 								//系统中断优先级管理（不是中断初始化）		
	Delay_Init(); 								//系统延时初始化
	USART_init(115200);						//调试串口初始化      
	IIC_GPIO_Init(); 							//模拟IIC初始化
	TIM_Init();										//系统时基初始化，TIM4作为系统时基
	MPU6050_Init();	 							//MPU6050初始化
  MOTOR_Init(); 								//电机输出初始化													
	PidParameter_init(); 					//PID参数初始化								
	GENERAL_TIM_Init();						//TIM2和TIM1初始化及其中断初始化 用于对接收机信号进行输入捕获
	
	OLED_Clear();
	OLED_Init();
	
//显示IIC检测到的地址.l
//	uint8_t ID;
//	ID = MPU6050_getDeviceID();
//		OLED_ShowString(6,6,"ID",16);		
//		OLED_Showdecimal(46,6,ID,6,4,16);
	
}

/************************************************************************************************
* 函  数：void Task_Schedule(void)
* 功  能：任务函数
* 参  数：    
* 返回值：无 
* 备  注：本程序为STM32飞控新生比赛精简版
************************************************************************************************/
void Task_Schedule(void)
{
	
	
		if(IMU_Scan) 																												//100Hz
		{
			IMU_Scan  = 0;																									//标志位清零
			Prepare_Data(); 																								//获取姿态解算所需数据
			IMUupdate(&Gyr_rad,&Acc_filt,&Att_Angle); 											//四元数姿态解算
			Control(&Att_Angle,&Gyr_rad,&RC_Control,Airplane_Enable); 			//姿态控制
/*		// OLED显示计算出的三轴角度。为了不影响程序运行速度，现已将显示指令放于 stm32f10x_it.c 5Hz内
			OLED_ShowString(6,2,"pit",16);
			OLED_Showdecimal(46,2,Att_Angle.pit,3,2,16);
			OLED_ShowString(6,4,"rol",16);
			OLED_Showdecimal(46,4,Att_Angle.rol,3,2,16);
			OLED_ShowString(6,6,"yaw",16);
			OLED_Showdecimal(46,6,Att_Angle.yaw,3,2,16);
			OLED_Clear();
*/
		}
		if(LED_Scan) //10Hz
		{
			LED_Scan = 0;
			
			if(!RC_middle&&lock)
			{
				LEDR_H;
				LEDG_H;
				LEDB_H;
				if(loop)
				{
				loop=0;
				LEDG_H;
				}
				else
				{
				loop=1;
				LEDG_L;
				}
			}
			if(!lock)
			{
				if(loop)
				{
				loop=0;
				LEDG_H;
				LEDR_H;
				LEDB_L;
				}
				else
				{
				loop=1;
				LEDG_H;
				LEDR_L;
				LEDB_H;
				}
			
			
			
			}
			
			
		}
		
}


