#include "stm32f10x.h" 
#include "ESP.h"
int num;
float sum;

uint8_t ReceiveVis(void)
{
	if(ESP_GetRxFlag()==1)
	{
		return Vis;//0����ͣ 1���� 2���� 3��ǰ 4���� 5�������߶�
		//num=HexNum;
		//sum=(float)num;
		//OLED_ShowChar(1,1, Vis);
		//OLED_ShowHexNum(3,1,sum,3);
	}
}

float ReceiveNum(void)
{
	if(ESP_GetRxFlag()==1)
	{
		
		num=HexNum;
		sum=(float)num;
		//OLED_ShowChar(1,1, Vis);
		//OLED_ShowHexNum(3,1,sum,3);
		return sum;
	}
}