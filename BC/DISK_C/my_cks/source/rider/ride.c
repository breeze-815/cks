#include "all_func.h"

void rider(int user_pos){
    mouse_off_arrow(&mouse);
	
	draw_rider();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1){
			welcome();//��ҳ
		}else if(mouse_press(40, 276, 160, 326)==1){
            //press1(1);//�����ͼҳ��
            show_map(); 
            dijkstra(&node[1], &node[28]);//����dijkstra�㷨
        }else if(mouse_press(40, 439, 160, 489)==1){
            press1(2);//��������ҳ��
            user_takeout();//�û�����ҳ��      
        }else if(mouse_press(40, 602, 160, 652)==1){
            press1(3);//������ҳ��
            user_deliver();//�û����ҳ��  
        }
        else if(mouse_press(950, 25, 1000, 75)==1)
        {
            CloseSVGA();//�ر�SVGA��ͼ����
            exit(100);
        }
    }
}

void draw_rider()
{
    bar1(0, 0, 1024, 768,0xFFFF);
    bar1(0, 0, 200, 768,0x0235);

    Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//��ɫ
    Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);//��ɫ
    Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);//��ɫ
    Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);//��ɫ

    Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//����
    Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);//����
    Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);//���� 
    Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);//���

    PrintCC(75,128,"����",HEI,24,1,deepblue);
    PrintCC(75,291,"��ͼ",HEI,24,1,deepblue);
    PrintCC(75,454,"����",HEI,24,1,deepblue);
    PrintCC(75,617,"���",HEI,24,1,deepblue);

    PrintCC(250,50,"��ǰ�˺�����Ϊ������",HEI,24,1,deepblue);
    
}

void press3(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    {
        case 1:{
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25,deepblue);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291,"����",HEI,24,1,white);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454,"����",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617,"���",HEI,24,1,deepblue);
            break;
        }
        case 2:{
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291,"����",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25,deepblue);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454,"����",HEI,24,1,white);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617,"���",HEI,24,1,deepblue);
            break;
        }
        case 3:{
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291,"����",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454,"����",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25,deepblue);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617,"���",HEI,24,1,white);
            break;
        }
    }
    mouse_on_arrow(mouse);
}