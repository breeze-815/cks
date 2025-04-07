#include "all_func.h"

void business(int user_pos){

    UserList UL = {0};
    USER *currentUser;
    int shop_type=0;//�̵����ͣ�1Ϊ���У�2Ϊ����
    int code[12]={0};//����

    ReadAllUser(&UL); // ��ȡ�û��б�

    currentUser=&UL.elem[user_pos];// ��ȡ��ǰ�û���Ϣ

    mouse_off_arrow(&mouse);
	
	draw_business();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            DestroyUList(&UL); // �ͷ��û��б��ڴ�
            return;
			//welcome();//��ҳ
		}
        else if(mouse_press(490, 260, 610, 310)==1)
        {
            press_type(1);//ѡ��Ϊ���о�Ӫ��
            shop_type=1;//����
            
        }
        else if(mouse_press(670, 260, 790, 310)==1)
        {
            press_type(2);//ѡ��Ϊ������Ӫ��
            shop_type=2;//����
        }
        else if(mouse_press(40, 602, 160, 652)==1)//�鿴����
        {
            
            business_order();//�̼Ҷ���ҳ��
            
            //return����⿪ʼ
            mouse_off_arrow(&mouse);
            bar1(200, 0, 1024, 768, white); // ���ע��������
            draw_business();
            mouse_on_arrow(mouse);

        }
        else if(mouse_press(430, 110, 650, 160)==1)//�����ֻ���
        {
            number_input(currentUser->number, 435, 115, 645, 155); // �����ֻ���
        }
        else if(mouse_press(710, 110, 830, 160)==1)//�����ֻ���
        {
            if(strlen(currentUser->number)==11)
            {
                save_user(*currentUser);
                PrintCC(800,50,"����ɹ�",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,1024,100,white);
            }
            else
            {
                PrintCC(800,50,"���Ȳ��Ϸ�",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,1024,100,white);
            }
        }
        else if(mouse_press(430, 185, 650, 235)==1)//�������
        {
            number_input(code, 435, 190, 645, 230); // �������
        }
        else if(mouse_press(710, 110, 830, 160)==1)//�����ֻ���
        {
            if(strlen(currentUser->number)==11)
            {
                save_user(*currentUser);
                PrintCC(800,50,"����ɹ�",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,1024,100,white);
            }
            else
            {
                PrintCC(800,50,"���Ȳ��Ϸ�",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,1024,100,white);
            }
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

    Draw_Rounded_Rectangle(490, 260, 610, 310, 25, 1,deepblue);//���а�ť
    Draw_Rounded_Rectangle(670, 260, 790, 310, 25, 1,deepblue);//������ť

    Draw_Rounded_Rectangle(430, 110, 650, 160, 5, 1,deepblue);//�ֻ�������� 
    Draw_Rounded_Rectangle(710, 110, 830, 160, 25, 1,deepblue);//�����ֻ��Ű�ť
    Draw_Rounded_Rectangle(430, 185, 650, 235, 5, 1,deepblue);//���������
    Draw_Rounded_Rectangle(710, 185, 830, 235, 25, 1,deepblue);//ȷ�ϰ�ť
    //Draw_Rounded_Rectangle(430, 330, 650, 375, 5, 1,deepblue);//�鿴������ť

    PrintCC(75,128,"����",HEI,24,1,deepblue);
    PrintCC(52,617,"�鿴����",HEI,24,1,deepblue);

    PrintCC(250,50,"��ǰ�˺�����Ϊ���̼�",HEI,24,1,deepblue);

    PrintCC(250,125,"�������ֻ��ţ�",HEI,24,1,deepblue);
    PrintCC(745,125,"����",HEI,24,1,deepblue);
    PrintCC(250,200,"��������룺",HEI,24,1,deepblue);
    PrintCC(745,200,"ȷ��",HEI,24,1,deepblue);

    PrintCC(250,275,"��ѡ��������ࣺ",HEI,24,1,deepblue);
    PrintCC(525,275,"����",HEI,24,1,deepblue);
    PrintCC(705,275,"����",HEI,24,1,deepblue);

    //Readbmp64k(200, 100, "bmp\\map.bmp");
    
}

void press_type(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    {
        case 1:{//����ѡ����ҳ��
            Fill_Rounded_Rectangle(490, 260, 610, 310, 25, deepblue);//����
            Draw_Rounded_Rectangle(490, 260, 610, 310, 25, 1,deepblue);//����
            PrintCC(525,275,"����",HEI,24,1,white);
            Fill_Rounded_Rectangle(670, 260, 790, 310, 25, white);//����
            Draw_Rounded_Rectangle(670, 260, 790, 310, 25, 1,deepblue);//����
            PrintCC(705,275,"����",HEI,24,1,deepblue);

            draw_market();

            break;
        }
        case 2:{//����ѡ�����ҳ��
            Fill_Rounded_Rectangle(490, 260, 610, 310, 25, white);//����
            Draw_Rounded_Rectangle(490, 260, 610, 310, 25, 1,deepblue);//����
            PrintCC(525,275,"����",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(670, 260, 790, 310, 25, deepblue);//����
            Draw_Rounded_Rectangle(670, 260, 790, 310, 25, 1,deepblue);//����
            PrintCC(705,275,"����",HEI,24,1,white);

            draw_canteen();

            break;
        }
        
    }
    mouse_on_arrow(mouse);
}

void draw_market(){
    bar1(205, 325, 1024, 768, white);

    Draw_Rounded_Rectangle(250, 330, 250+185, 330+50, 5,1,0x0235);
    PrintCC(250+17,330+13,"��Էѧ��ʳ��",HEI,24,1,0x0235);
            
    Draw_Rounded_Rectangle(500, 330, 500+185, 330+50, 5,1,0x0235);
    PrintCC(500+17,330+13,"��԰ʳ��",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 330, 750+185, 330+50, 5,1,0x0235);
    PrintCC(750+17,330+13,"���̹�ʳ��",HEI,24,1,0x0235);

}

void draw_canteen(){
    bar1(205, 325, 1024, 768, white);

    Draw_Rounded_Rectangle(250, 330, 250+185, 330+50, 5,1,0x0235);
    PrintCC(250+17,330+13,"��Էѧ��ʳ��",HEI,24,1,0x0235);
            
    Draw_Rounded_Rectangle(500, 330, 500+185, 330+50, 5,1,0x0235);
    PrintCC(500+17,330+13,"��԰ʳ��",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 330, 750+185, 330+50, 5,1,0x0235);
    PrintCC(750+17,330+13,"���̹�ʳ��",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 390, 250+185, 390+50, 5,1,0x0235);
    PrintCC(250+17,390+13,"ѧ��һʳ��",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 390, 500+185, 390+50, 5,1,0x0235);
    PrintCC(500+17,390+13,"ѧ����ʳ��",HEI,24,1,0x0235);  

    Draw_Rounded_Rectangle(750, 390, 750+185, 390+50, 5,1,0x0235);
    PrintCC(750+17,390+13,"�Ͼ�԰����",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 450, 250+185, 450+50, 5,1,0x0235);
    PrintCC(250+17,450+13,"��һʳ��",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 450, 500+185, 450+50, 5,1,0x0235);
    PrintCC(500+17,450+13,"����ʳ��",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 450, 750+185, 450+50, 5,1,0x0235);
    PrintCC(750+17,450+13,"��԰����",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 510, 250+185, 510+50, 5,1,0x0235);
    PrintCC(250+17,510+13,"�پ�԰",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 510, 500+185, 510+50, 5,1,0x0235);
    PrintCC(500+17,510+13,"��һʳ��",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 510, 750+185, 510+50, 5,1,0x0235);
    PrintCC(750+17,510+13,"����ʳ��",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 570, 250+185, 570+50, 5,1,0x0235);
    PrintCC(250+17,570+13,"��԰ʳ��",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 570, 500+185, 570+50, 5,1,0x0235);
    PrintCC(500+17,570+13,"���̹�ʳ��",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 570, 750+185, 570+50, 5,1,0x0235);
    PrintCC(750+17,570+13,"��԰ʳ��",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 630, 250+185, 630+50, 5,1,0x0235);
    PrintCC(250+17,630+13,"��԰ʳ��",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 630, 500+185, 630+50, 5,1,0x0235);
    PrintCC(500+17,630+13,"����ʳ��",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 630, 750+185, 630+50, 5,1,0x0235);
    PrintCC(750+17,630+13,"��Էʳ��",HEI,24,1,0x0235);
}