#include <all_func.h>
void draw_login()
{
	bar1(0, 0, 1024, 768,0xD5B1);

	Fill_Rounded_Rectangle(200,220, 800, 630, 30,0xFFFF);
	Draw_Rounded_Rectangle(200, 220, 800, 630, 30, 2,0xC618);//����Χ��ɫԲ�Ǿ���
	
	Draw_Rounded_Rectangle(300, 330, 700, 380, 5, 1,0xAEFC);//�˺���Բ�Ǿ���
	Draw_Rounded_Rectangle(300, 410, 700, 460, 5, 1,0xAEFC);//������Բ�Ǿ���
	Fill_Rounded_Rectangle(300,490, 485, 540, 5,0x435c);//��¼��ť
	Draw_Rounded_Rectangle(515, 490, 700, 540, 5,1,0x0235);//ע�ᰴť
	PrintCC(305,250,"У԰�������ƽ̨",HEI,48,1,0);
	PrintCC(305,345,"�˺�",HEI,24,1,0XC618);
	PrintCC(305,425,"����",HEI,24,1,0XC618);
	PrintCC(365,503,"��¼",HEI,24,1,0xFFFF);
	PrintCC(580,503,"ע��",HEI,24,1,0x0235);
	
}

