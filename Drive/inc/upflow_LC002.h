#ifndef __UPFLOW_LC002_H
#define __UPFLOW_LC002_H
#include "main.h"
extern int16_t ValueX,ValueY,ValueX_before,ValueY_before,ValueX_a,ValueY_a,Timespan_flow, Valid_flow;

typedef struct optical_flow_data
{
	int16_t flow_x_integral;// X ���ص��ۼ�ʱ���ڵ��ۼ�λ��(radians*10000)
													// [���� 10000 ���Ը߶�(mm)��Ϊʵ��λ��(mm)]
	int16_t flow_y_integral;// Y ���ص��ۼ�ʱ���ڵ��ۼ�λ��(radians*10000)
													// [���� 10000 ���Ը߶�(mm)��Ϊʵ��λ��(mm)]
	uint16_t integration_timespan;// ��һ�η��͹������ݵ����η��͹������ݵ��ۼ�ʱ�䣨us��
	uint16_t ground_distance;// Ԥ����Ĭ��Ϊ 999��0x03E7��
	
	uint8_t valid;// ״ֵ̬:0(0x00)Ϊ�������ݲ����� 
								//245(0xF5)Ϊ�������ݿ���
	
	uint8_t version;//�汾��
}Upixels_OpticalFlow;




#endif
