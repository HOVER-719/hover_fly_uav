/************************************************************************************************
* ����汾��V2.1
* �������ڣ�2021-12-8
* �������ߣ�719������ʵ���ң� 
*						����
*						���
************************************************************************************************/
#ifndef   _PID_H_
#define   _PID_H_

#include "main.h"
void PidParameter_init(void);
void PID_Postion_Cal(PID_TYPE*PID,float target,float measure);
void UnControl_Check(void);
#endif
