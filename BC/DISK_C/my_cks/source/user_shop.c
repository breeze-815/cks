#include "all_func.h"

void user_shop(int *page,int *shop_type){

    mouse_off(&mouse);
	
	draw_user_shop(shop_type);

	mouse_on(mouse);

	while(1){
		mouse_show(&mouse);

		if(mouse_press(40, 113, 160, 163)==1){
            *page=2;//�����û���ҳ
            break;
		}else if(mouse_press(40, 276, 160, 326)==1){
            draw_choice();
            while(1){
                mouse_show(&mouse);

                if(mouse_press(200, 202, 430, 264)==1){
                    *shop_type=1;
                    break;
                }else if(mouse_press(200, 266, 430, 334)==1){
                    *shop_type=2;
                    break;
                }else if(mouse_press(200, 336, 430, 400)==1){
                    *shop_type=3;
                    break;
                }
            }
            *page=5;
            break;
        }else if(mouse_press(40, 439, 160, 489)==1){
            press1(2);//��������ҳ��
            *page=6;
            break;
        }else if(mouse_press(40, 602, 160, 652)==1){
            press1(3);//������ҳ��
            *page=7;
            break;
        }else if(mouse_press(750, 650, 950, 700)==1){
            *page=8;//���ﳵҳ��
            break;
        }else if(mouse_press(200, 0, 320, 50)==1){
            press_item(1);//������Ʒ
        }else if(mouse_press(320, 0, 440, 50)==1){
            press_item(2);//�ľ�
        }else if(mouse_press(440, 0, 560, 50)==1){
            press_item(3);//��ʳ
        }else if(mouse_press(560, 0, 680, 50)==1){
            press_item(4);//����
        }else if(mouse_press(680, 0, 800, 50)==1){
            press_item(5);//�˶���Ʒ
        }else if(mouse_press(800, 0, 920, 50)==1){
            press_item(6);//ˮ��
        }else if(mouse_press(920, 0, 1024, 50)==1){
            press_item(7);//�Ĵ�
        }
    }
}

void draw_user_shop(int *shop_type){
    bar1(200, 0, 1024, 768,white);

    Line_Thick(200,50,1024,50,2,deepblue);
    //Line_Thick(200,1,1024,1,2,deepblue);

    Line_Thick(320,0,320,50,2,deepblue);
    Line_Thick(440,0,440,50,2,deepblue);
    Line_Thick(560,0,560,50,2,deepblue);
    Line_Thick(680,0,680,50,2,deepblue);
    Line_Thick(800,0,800,50,2,deepblue);
    Line_Thick(920,0,920,50,2,deepblue);

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5,1,deepblue);//���ﳵ��ť

    PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
    PrintCC(355,15,"�ľ�",HEI,24,1,grey);
    PrintCC(475,15,"��ʳ",HEI,24,1,grey);
    PrintCC(595,15,"����",HEI,24,1,grey);
    PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
    PrintCC(835,15,"ˮ��",HEI,24,1,grey);
    PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
    PrintCC(860,715,"���ﳵ",HEI,24,1,deepblue);

    bar2(630,280,750,400,deepblue);
    bar2(810,280,930,400,deepblue);

    bar2(270,460,390,580,deepblue);//120*120
    bar2(450,460,570,580,deepblue);
    bar2(630,460,750,580,deepblue);
    bar2(810,460,930,580,deepblue);

    PrintCC(315,240,"��",HEI,24,1,deepblue);
    Readbmp64k(270, 100, "bmp\\pen.bmp");//��
    Readbmp64k(450, 100, "bmp\\saoba.bmp");//ɨ��
    Readbmp64k(630, 100, "bmp\\canju.bmp");//�;�
    Readbmp64k(810, 100, "bmp\\wan.bmp");//��
    Readbmp64k(270, 280, "bmp\\shuibei.bmp");//ˮ��
    Readbmp64k(450, 280, "bmp\\yijia.bmp");//�¼�
    
    if(*shop_type==1){
        PrintCC(220,700,"��ݿ��԰����",HEI,48,1,deepblue);
    }else if(*shop_type==2){ 
        PrintCC(220,700,"��Է��԰����",HEI,48,1,deepblue);
    }else if(*shop_type==3){
        PrintCC(220,700,"��Է��԰����",HEI,48,1,deepblue);
    }
}

void press_item(int x){
    switch (x)
    {
        case 1:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,deepblue);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 2:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,deepblue);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 3:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,deepblue);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 4:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,deepblue);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }   
        case 5:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,deepblue);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 6:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,deepblue);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 7:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,deepblue);
            break;
        }
    }
}