#include "stm32f10x.h" 
#include "ESP.h"
int num;
float sum;
extern float t_yaw;
extern float t_pitch;
extern float t_roll;
extern uint16_t t_height;

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

uint8_t ReceiveNum_Gettarget(void)
{
	int8_t i;
for(i=0;i<5;i++)
{
switch (ReceiveVis())
{
case 0:
	return 0;
	break;
case 1:  t_pitch= ReceiveNum();
    break;
case 2:  t_roll= -ReceiveNum();
    break;
case 3:  t_roll= ReceiveNum();
    break;
case 4:  t_pitch= -ReceiveNum();
    break;
case 5: t_height=(uint16_t)ReceiveNum();
    break;
default:
	break;
}
}
return 1;

}