#include "all_func.h"

void business_order(){
    mouse_off_arrow(&mouse);
	
	draw_business_order();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1){
			business();//�̼�ҳ��
		}else if(mouse_press(490, 100, 610, 150)==1){
            press2(1);//���볬��ҳ��
            if(mouse_press(250, 200, 250+185, 200+50)==1){
                user_shop();//�û�����ҳ�� 
            }
        }else if(mouse_press(670, 100, 790, 150)==1){
            press2(2);//�������ҳ��
        }else if(mouse_press(40, 602, 160, 652)==1){
            business_order();//�̼Ҷ���ҳ��
        }
    }
}

void draw_business_order(){
    bar1(200, 0, 1024, 768,white);

    Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//������ɫ
    Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//����//Բ�ǰ�ť���ֵ�x+35��y+15
    Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);//ȷ����ɫ
    Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);//ȷ��

    Draw_Rounded_Rectangle(490, 100, 610, 150, 25, 1,deepblue);//����
    Draw_Rounded_Rectangle(670, 100, 790, 150, 25, 1,deepblue);//����


    PrintCC(75,128,"����",HEI,24,1,deepblue);
    PrintCC(75,617,"ȷ��",HEI,24,1,deepblue);

    PrintCC(250,50,"��ǰ�˺�����Ϊ���̼�",HEI,24,1,deepblue);
    PrintCC(250,110,"��ѡ��������ࣺ",HEI,24,1,deepblue);

    PrintCC(525,115,"����",HEI,24,1,deepblue);
    PrintCC(705,115,"����",HEI,24,1,deepblue);
}