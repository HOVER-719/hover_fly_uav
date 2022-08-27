#ifndef __UPFLOW_LC002_H
#define __UPFLOW_LC002_H
#include "main.h"
extern int16_t ValueX,ValueY,ValueX_before,ValueY_before,ValueX_a,ValueY_a,Timespan_flow, Valid_flow;

typedef struct optical_flow_data
{
	int16_t flow_x_integral;// X 像素点累计时间内的累加位移(radians*10000)
													// [除以 10000 乘以高度(mm)后为实际位移(mm)]
	int16_t flow_y_integral;// Y 像素点累计时间内的累加位移(radians*10000)
													// [除以 10000 乘以高度(mm)后为实际位移(mm)]
	uint16_t integration_timespan;// 上一次发送光流数据到本次发送光流数据的累计时间（us）
	uint16_t ground_distance;// 预留。默认为 999（0x03E7）
	
	uint8_t valid;// 状态值:0(0x00)为光流数据不可用 
								//245(0xF5)为光流数据可用
	
	uint8_t version;//版本号
}Upixels_OpticalFlow;




#endif
