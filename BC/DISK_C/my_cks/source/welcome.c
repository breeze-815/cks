#include "all_func.h"
//��Ļ���1024���߶�768


int welcome(int *page){
	mouse_off(&mouse);
	
	draw_basic();

	mouse_on(mouse);

	while(1){
		mouse_show(&mouse);

		if(mouse_press(515, 490, 700, 540)==1){
			*page=1;//����ע�����
			break;
		}else if(mouse_press(300,330,700,380)==1){
            bar1(305,335,695,375,0xFFFF);
            cursor(305,340);
            
		delay(15);
	    }
    }
}

void draw_basic()
{
    bar1(0, 0, 1024, 768,0xFFFF);

    Fill_Rounded_Rectangle(200, 148, 824, 600, 30,0xFFDF);//��ɫ
    Draw_Rounded_Rectangle(200, 148, 824, 600, 30, 2,0x6B4D);//����Χ��ɫԲ�Ǿ���
    
    Draw_Rounded_Rectangle(300, 330, 700, 380, 5, 1,0xB71C);//�˺���Բ�Ǿ���
    Draw_Rounded_Rectangle(300, 410, 700, 460, 5, 1,0xB71C);//������Բ�Ǿ���
    Fill_Rounded_Rectangle(300,490, 485, 540, 5,0x435c);//��¼��ť
    Draw_Rounded_Rectangle(515, 490, 700, 540, 5,1,0x0235);//ע�ᰴť
    PrintCC(305,225,"У԰�������ƽ̨",HEI,48,1,0);
    PrintCC(305,345,"�˺�",HEI,24,1,0XC618);
    PrintCC(305,425,"����",HEI,24,1,0XC618);
    PrintCC(365,503,"��¼",HEI,24,1,0xFFFF);
    PrintCC(580,503,"ע��",HEI,24,1,0x0235);
    PrintText(100,100,"chp123",HEI,16,1,0XC618);
    
}

