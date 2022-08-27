#include "upflow_LC002.h"




uint8_t RXTime2=0;//����
int16_t ValueX,ValueY,ValueX_before,ValueY_before,ValueX_a,ValueY_a,Timespan_flow, Valid_flow;
uint8_t LC002_BUFFER[16];
Upixels_OpticalFlow optical_flow_dataR;
void USART3_IRQHandler(void)
{
		if(USART_GetITStatus(USART3,USART_IT_RXNE) != RESET) //�жϲ��� 
	{
		USART_ClearITPendingBit(USART3,USART_IT_RXNE); //����жϱ�־
			 LC002_BUFFER[RXTime2] = USART_ReceiveData(USART3);
		RXTime2++;
	//	MUSART1_SendData(0xAA);
		if(LC002_BUFFER[0]!=0xFE)	 
			{
			//	MUSART1_SendData(0xBB);
			RXTime2=0;
			}
			
		if(RXTime2>1&&LC002_BUFFER[1]!=0x0A)
			{
			RXTime2=0;
			}
		if(LC002_BUFFER[RXTime2]==0x55)
			{
				ValueX=(LC002_BUFFER[2]|(LC002_BUFFER[3]<<8))*0.2+ValueX_before*0.8;//�����˲�
				ValueY=(LC002_BUFFER[4]|(LC002_BUFFER[5]<<8))*0.2+ValueY_before*0.8;
				Timespan_flow=LC002_BUFFER[6]|(LC002_BUFFER[7]<<8);
				ValueX_a=ValueX-ValueX_before;//���ٶ�
				ValueY_a=ValueY-ValueY_before;
				ValueX_before=ValueX;
				ValueY_before=ValueY;
				
				Valid_flow=LC002_BUFFER[10];//״ֵ̬��0(0x00)Ϊ�������ݲ����ã� 245(0xF5)Ϊ�������ݿ���
				//MUSART1_SendData(Valid_flow);
				//MUSART1_SendData(LC002_BUFFER[0]);
				//MUSART1_SendData(LC002_BUFFER[1]);
				//MUSART1_SendData(LC002_BUFFER[2]);
				//MUSART1_SendData(LC002_BUFFER[3]);
				//MUSART1_SendData(LC002_BUFFER[4]);
				//MUSART1_SendData(LC002_BUFFER[5]);
				//MUSART1_SendData(LC002_BUFFER[6]);
				//MUSART1_SendData(LC002_BUFFER[7]);
				//MUSART1_SendData(LC002_BUFFER[8]);
				//MUSART1_SendData(LC002_BUFFER[9]);
				//MUSART1_SendData(LC002_BUFFER[10]);
				//MUSART1_SendData(LC002_BUFFER[11]);
				//MUSART1_SendData(LC002_BUFFER[12]);
				//MUSART1_SendData(LC002_BUFFER[13]);
		
				RXTime2=0;
			}
	}

}


