#include "all_func.h"

void business(int user_pos){
    mouse_off_arrow(&mouse);
	
	draw_business();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1){
			welcome();//��ҳ
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

void draw_business()
{
    bar1(0, 0, 1024, 768,white);
    bar1(0, 0, 200, 768,deepblue);

    Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//������ɫ
    Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//����//Բ�ǰ�ť���ֵ�x+35��y+15
    Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);//ȷ����ɫ
    Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);//ȷ��

    Draw_Rounded_Rectangle(490, 100, 610, 150, 25, 1,deepblue);//���а�ť
    Draw_Rounded_Rectangle(670, 100, 790, 150, 25, 1,deepblue);//������ť


    PrintCC(75,128,"����",HEI,24,1,deepblue);
    PrintCC(75,617,"ȷ��",HEI,24,1,deepblue);

    PrintCC(250,50,"��ǰ�˺�����Ϊ���̼�",HEI,24,1,deepblue);
    PrintCC(250,110,"��ѡ��������ࣺ",HEI,24,1,deepblue);

    PrintCC(525,115,"����",HEI,24,1,deepblue);
    PrintCC(705,115,"����",HEI,24,1,deepblue);

    //Readbmp64k(200, 100, "bmp\\map.bmp");
    
}

void press2(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    {
        case 1:{//����ѡ����ҳ��
            Fill_Rounded_Rectangle(490, 100, 610, 150, 25, deepblue);//����
            Draw_Rounded_Rectangle(490, 100, 610, 150, 25, 1,deepblue);//����
            PrintCC(525,115,"����",HEI,24,1,white);
            Fill_Rounded_Rectangle(670, 100, 790, 150, 25, white);//����
            Draw_Rounded_Rectangle(670, 100, 790, 150, 25, 1,deepblue);//����
            PrintCC(705,115,"����",HEI,24,1,deepblue);

            bar1(205, 195, 1024, 768, white);

            Draw_Rounded_Rectangle(250, 200, 250+185, 200+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(250+17,200+13,"��Է��԰����",HEI,24,1,0x0235);
            
            Draw_Rounded_Rectangle(500, 200, 500+185, 200+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(500+17,200+13,"��Է��԰����",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(750, 200, 750+185, 200+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(750+17,200+13,"��ݿ��԰����",HEI,24,1,0x0235);

            break;
        }
        case 2:{//����ѡ�����ҳ��
            Fill_Rounded_Rectangle(490, 100, 610, 150, 25, white);//����
            Draw_Rounded_Rectangle(490, 100, 610, 150, 25, 1,deepblue);//����
            PrintCC(525,115,"����",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(670, 100, 790, 150, 25, deepblue);//����
            Draw_Rounded_Rectangle(670, 100, 790, 150, 25, 1,deepblue);//����
            PrintCC(705,115,"����",HEI,24,1,white);

            bar1(205, 195, 1024, 768, white);

            Draw_Rounded_Rectangle(250, 200, 250+185, 200+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(250+17,200+13,"��Էѧ��ʳ��",HEI,24,1,0x0235);
            
            Draw_Rounded_Rectangle(500, 200, 500+185, 200+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(500+17,200+13,"��԰ʳ��",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(750, 200, 750+185, 200+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(750+17,200+13,"���̹�ʳ��",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(250, 300, 250+185, 300+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(250+17,300+13,"ѧ��һʳ��",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(500, 300, 500+185, 300+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(500+17,300+13,"ѧ����ʳ��",HEI,24,1,0x0235);  

            Draw_Rounded_Rectangle(750, 300, 750+185, 300+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(750+17,300+13,"�Ͼ�԰����",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(250, 400, 250+185, 400+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(250+17,400+13,"��һʳ��",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(500, 400, 500+185, 400+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(500+17,400+13,"����ʳ��",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(750, 400, 750+185, 400+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(750+17,400+13,"��԰����",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(250, 500, 250+185, 500+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(250+17,500+13,"�پ�԰",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(500, 500, 500+185, 500+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(500+17,500+13,"��һʳ��",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(750, 500, 750+185, 500+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(750+17,500+13,"����ʳ��",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(250, 600, 250+185, 600+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(250+17,600+13,"��԰ʳ��",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(500, 600, 500+185, 600+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(500+17,600+13,"���̹�ʳ��",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(750, 600, 750+185, 600+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(750+17,600+13,"��԰ʳ��",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(250, 700, 250+185, 700+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(250+17,700+13,"��԰ʳ��",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(500, 700, 500+185, 700+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(500+17,700+13,"����ʳ��",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(750, 700, 750+185, 700+50, 5,1,0x0235);//ע�ᰴť
            PrintCC(750+17,700+13,"��Էʳ��",HEI,24,1,0x0235);

            break;
        }
        case 3:{
            
            break;
        }
        case 4:{

        }
    }
    mouse_on_arrow(mouse);
}