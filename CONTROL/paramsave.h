/************************************************************************************************
* ����汾��V2.1
* �������ڣ�2021-12-8
* �������ߣ�719������ʵ���ң� 
*						����
*						���
************************************************************************************************/
#ifndef   _MONI_FLASH_H
#define   _MONI_FLASH_H


void TableToParams(void);
void ParamsToTable(void);
void ParamsClearAll(void);
void PID_WriteFlash(void);
void PID_ReadFlash(void);
void PID_ClearFlash(void);
void DefaultParams(void);
void DefaultParams_WriteFlash(void);
#endif
