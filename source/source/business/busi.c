#include "all_func.h"

void business(int user_pos){

    UserList UL = {0};
    USER *currentUser;
    int shop_type=0;//�̵����ͣ�1Ϊ���У�2Ϊ����
    int code[12]={0};//����
    int state=0;//״̬��0Ϊδ�󶨣�1Ϊ�Ѱ�
    int page=0;//0Ϊδѡ��1Ϊ���У�2Ϊ����
    int last_canteen_index = -1; // ��¼��һ�������µİ�ť
    int index=-1;//ʳ��/���б��
    

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
        else if(mouse_press(710, 185, 830, 235)==1)//ȷ�ϰ�
        {
            if(strcmp(code,"111")==0)
            {
                PrintCC(800,50,"�󶨳ɹ�",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,1024,100,white);
                state=1;//�Ѱ�
            }
            else
            {
                PrintCC(800,50,"��ʧ��",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,1024,100,white);
            }
        }

        //�󶨺�
        if(state==1)
        {
            if(mouse_press(490, 260, 610, 310)==1)
            {
                press_type(1);//ѡ��Ϊ���о�Ӫ��
                shop_type=1;//����
                page=1;
                
            }
            else if(mouse_press(670, 260, 790, 310)==1)
            {
                press_type(2);//ѡ��Ϊ������Ӫ��
                shop_type=2;//����
                page=2;
            }
            else if(mouse_press(40, 602, 160, 652)==1)//�鿴����
            {
                
                business_order(index);//�̼Ҷ���ҳ��
                
                //return����⿪ʼ
                mouse_off_arrow(&mouse);
                bar1(200, 0, 1024, 768, white); // ���ע��������
                draw_business();
                mouse_on_arrow(mouse);
    
            }
            else if(mouse_press(205, 325, 1024, 768)==1)//ѡ�����ʳ��/����
            {
                
                MouseGet(&mouse);
                mouse_off_arrow(&mouse);
                if(page==1)//����
                {
                    index=0;//ѡ����
                }

                if(page==2)//����
                {
                    index=choose_canteen(mouse.x, mouse.y, &last_canteen_index);
                }
                mouse_on_arrow(mouse);
            }
        }

        //δ��
        if(state==0)
        {
            if(mouse_press(490, 260, 610, 310)==1||
               mouse_press(670, 260, 790, 310)==1||
               mouse_press(40, 602, 160, 652)==1)
            {
                PrintCC(800,50,"���Ƚ��а󶨲���",HEI,24,1,lightred);
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
    PrintCC(250+17,330+13,"��Է��԰����",HEI,24,1,0x0235);
            
    Draw_Rounded_Rectangle(500, 330, 500+185, 330+50, 5,1,0x0235);
    PrintCC(500+17,330+13,"��Է��԰����",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 330, 750+185, 330+50, 5,1,0x0235);
    PrintCC(750+17,330+13,"��ݿ��԰����",HEI,24,1,0x0235);

}

void draw_canteen(){
    int i,j;
    int cnt=0;
    bar1(205, 325, 1024, 768, white);

    //��ӡʳ������
    for(i=0;i<6;i++){
    	for(j=0;j<3;j++){
    		Draw_Rounded_Rectangle(250+250*j, 330+60*i, 250+250*j+185, 330+60*i+50, 5,1,deepblue);
            PrintCC(250+250*j+17,330+60*i+13,canteen[cnt].name,HEI,24,1,deepblue);
            cnt++;
    	}
    }

}

void choose_market(int x){
	
}

int choose_canteen(int x, int y, int* last_index) {
    int i, j;
    int index = -1;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            int x1 = 250 + 250 * j;
            int y1 = 330 + 60 * i;
            int x2 = x1 + 185;
            int y2 = y1 + 50;

            if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
                index = i * 3 + j;

                // �ָ���һ����ť
                if (*last_index != -1 && *last_index != index) {
                    int pre_row = *last_index / 3;
                    int pre_col = *last_index % 3;
                    int pre_x1 = 250 + 250 * pre_col;
                    int pre_y1 = 330 + 60 * pre_row;
                    int pre_x2 = pre_x1 + 185;
                    int pre_y2 = pre_y1 + 50;

                    Fill_Rounded_Rectangle(pre_x1, pre_y1, pre_x2, pre_y2, 5, white);
                    Draw_Rounded_Rectangle(pre_x1, pre_y1, pre_x2, pre_y2, 5, 1, deepblue);
                    PrintCC(pre_x1 + 17, pre_y1 + 13, canteen[*last_index].name, HEI, 24, 1, deepblue);
                }

                // ��ǰ��ť����
                Fill_Rounded_Rectangle(x1, y1, x2, y2, 5, deepblue);
                Draw_Rounded_Rectangle(x1, y1, x2, y2, 5, 1, deepblue);
                PrintCC(x1 + 17, y1 + 13, canteen[index].name, HEI, 24, 1, white);

                *last_index = index;
                return index + 1; // ����ʳ�ñ�ţ�1~18��
            }
        }
    }
}


