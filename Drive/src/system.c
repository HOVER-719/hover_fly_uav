/************************************************************************************************
* ����汾��V2.1
* �������ڣ�2021-12-8
* �������ߣ�719������ʵ���ң� 
*						����
*						���
************************************************************************************************/

#include "main.h"

/************************************************************************************************
* ��  ����void System_Init(void)
* ��  �ܣ���ʼ������
* ��  ����    
* ����ֵ���� 
* ��  ע��������ΪSTM32�ɿ��������������
************************************************************************************************/
void System_Init(void)
{
	
	LED_Init();										//״ָ̬ʾ�Ƴ�ʼ��
	NvicConfig(); 								//ϵͳ�ж����ȼ����������жϳ�ʼ����		
	Delay_Init(); 								//ϵͳ��ʱ��ʼ��
	USART_init(115200);						//���Դ��ڳ�ʼ��      
	IIC_GPIO_Init(); 							//ģ��IIC��ʼ��
	TIM_Init();										//ϵͳʱ����ʼ����TIM4��Ϊϵͳʱ��
	MPU6050_Init();	 							//MPU6050��ʼ��
  MOTOR_Init(); 								//��������ʼ��													
	PidParameter_init(); 					//PID������ʼ��								
	GENERAL_TIM_Init();						//TIM2��TIM1��ʼ�������жϳ�ʼ�� ���ڶԽ��ջ��źŽ������벶��
	
	OLED_Clear();
	OLED_Init();
	
//��ʾIIC��⵽�ĵ�ַ.l
//	uint8_t ID;
//	ID = MPU6050_getDeviceID();
//		OLED_ShowString(6,6,"ID",16);		
//		OLED_Showdecimal(46,6,ID,6,4,16);
	
}

/************************************************************************************************
* ��  ����void Task_Schedule(void)
* ��  �ܣ�������
* ��  ����    
* ����ֵ���� 
* ��  ע��������ΪSTM32�ɿ��������������
************************************************************************************************/
void Task_Schedule(void)
{
	
	
		if(IMU_Scan) 																												//100Hz
		{
			IMU_Scan  = 0;																									//��־λ����
			Prepare_Data(); 																								//��ȡ��̬������������
			IMUupdate(&Gyr_rad,&Acc_filt,&Att_Angle); 											//��Ԫ����̬����
			Control(&Att_Angle,&Gyr_rad,&RC_Control,Airplane_Enable); 			//��̬����
/*		// OLED��ʾ�����������Ƕȡ�Ϊ�˲�Ӱ����������ٶȣ����ѽ���ʾָ����� stm32f10x_it.c 5Hz��
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


