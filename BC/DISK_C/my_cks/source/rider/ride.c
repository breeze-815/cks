#include "all_func.h"

void rider(int user_pos){
    // OrderList OL = {0};
    // FoodList FL = {0};
    // DeliverList DL = {0};
    // ReadAllDeliver(&DL); // ��ȡ����б�
    // ReadAllOrder(&OL); // ��ȡ�����б�
    // ReadAllFood(&FL); // ��ȡʳƷ�б�
    // mouse_off_arrow(&mouse);
	UserList UL = {0};
    USER currentUser;
    ReadAllUser(&UL); // ��ȡ�û��б�
    currentUser=UL.elem[user_pos];// ��ȡ��ǰ�û���Ϣ
    DestroyUList(&UL); // �ͷ��û��б�ռ�
    mouse_off_arrow(&mouse);
	draw_rider();
	mouse_on_arrow(mouse);
    
	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(122, 50, 242, 100)==1)
        {
            return ;
            //welcome()��ҳ
		}
        else if(mouse_press(342, 50, 462, 100)==1)
        {
            press3(1);//����ӵ�����
            accept_order();//�ӵ�ҳ��
            
            //return����⿪ʼ
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // ����ӵ��������
            draw_rider();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(562, 50, 682, 100)==1)
        {
            press3(2);//����·�߹滮����
            route(acp_orders,delivers.acp_count);//����·�߹滮����
            //return����⿪ʼ
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // ����ӵ��������
            draw_rider();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //�ҵ�
        {
            press3(3); //��ť����
            my(user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_rider();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(430, 500, 650, 550)==1)
        {
            number_input(currentUser.number, 435, 505, 645, 545); // �����ֻ���
        }
        else if(mouse_press(710, 500, 830, 550)==1)
        {
            if(strlen(currentUser.number)==11)//�ж��ֻ��ų����Ƿ�Ϸ�
            {
                save_user(currentUser);
                PrintCC(860,535,"����ɹ�",HEI,24,1,lightred);
                delay(500);
                bar1(860,535,1000,600,white);
            }
            else
            {
                PrintCC(860,535,"���Ȳ��Ϸ�",HEI,24,1,lightred);
                delay(500);
                bar1(860,535,1000,600,white);
            }
        }
        else if(mouse_press(440, 285, 560, 335)==1) //ȫְ��ť
        {
            press3(4);
            currentUser.state=0;
            save_user(currentUser);

        }
        else if(mouse_press(620, 285, 740, 335)==1) //��ְ��ť
        {
            press3(5);
            currentUser.state=1;
            save_user(currentUser);
        }
    }

}


void draw_rider(){
    bar1(0, 0, 1024, 768, white);
    bar1(0, 0, 1024, 150, deepblue);
    
    
    Fill_Rounded_Rectangle(122, 50, 242, 100, 25,white);//��ɫ
    Fill_Rounded_Rectangle(342, 50, 462, 100, 25,white);//��ɫ
    Fill_Rounded_Rectangle(562, 50, 682, 100, 25,white);//��ɫ
    Fill_Rounded_Rectangle(782, 50, 902, 100, 25,white);//��ɫ
    Fill_Rounded_Rectangle(440, 285, 560, 335, 25, white);//��ɫ
    Fill_Rounded_Rectangle(620, 285, 740, 335, 25, white);//��ɫ
            
    
    Draw_Rounded_Rectangle(122, 50, 242, 100, 25, 1,deepblue);//����
    Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);//�ӵ�
    Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);//·��
    Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);//�ҵ�
    Draw_Rounded_Rectangle(440, 285, 560, 335, 25, 1,deepblue);//ȫְ
    Draw_Rounded_Rectangle(620, 285, 740, 335, 25, 1,deepblue);//��ְ
    Draw_Rounded_Rectangle(430, 500, 650, 550, 5, 1,deepblue);//�ֻ�������� 
    Draw_Rounded_Rectangle(710, 500, 830, 550, 25, 1,deepblue);//���水ť

    PrintCC(122+35, 65, "����", HEI, 24, 1, deepblue);
    PrintCC(342+35, 65, "�ӵ�", HEI, 24, 1, deepblue);
    PrintCC(562+35, 65, "·��", HEI, 24, 1, deepblue);
    PrintCC(782+35, 65, "�ҵ�", HEI, 24, 1, deepblue);
    PrintCC(220,510,"�������ֻ��ţ�",HEI,24,1,deepblue);
    PrintCC(200,300,"��ѡ���������ͣ�",HEI,24,1,deepblue);
    PrintCC(10, 10, "��ǰ�˺�����Ϊ������", HEI, 24, 1, white);
    PrintCC(440+35,300,"ȫְ",HEI,24,1,deepblue);
    PrintCC(620+35,300,"��ְ",HEI,24,1,deepblue);
    PrintCC(710+35, 515, "����", HEI, 24, 1, deepblue);
}


void press3(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    { 
        case 1:
        {
            
            Fill_Rounded_Rectangle(342, 50, 462, 100, 25, deepblue);
            Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);
            PrintCC(342+35, 65, "�ӵ�", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(562, 50, 682, 100, 25, white);
            Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);
            PrintCC(562+35, 65, "·��", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(782, 50, 902, 100, 25, white);
            Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);
            PrintCC(782+35, 65, "�ҵ�", HEI, 24, 1, deepblue);
            break;
        }
        case 2:
        {
            Fill_Rounded_Rectangle(342, 50, 462, 100, 25, white);
            Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);
            PrintCC(342+35, 65, "�ӵ�", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(562, 50, 682, 100, 25, deepblue);
            Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);
            PrintCC(562+35, 65, "·��", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(782, 50, 902, 100, 25, white);
            Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);
            PrintCC(782+35, 65, "�ҵ�", HEI, 24, 1, deepblue);
            break;
        }
        case 3:
        {
            Fill_Rounded_Rectangle(342, 50, 462, 100, 25, white);
            Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);
            PrintCC(342+35, 65, "�ӵ�", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(562, 50, 682, 100, 25, white);
            Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);
            PrintCC(562+35, 65, "·��", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(782, 50, 902, 100, 25, deepblue);
            Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);
            PrintCC(782+35, 65,"�ҵ�", HEI ,24 ,1 ,white);
            break;
        }
        case 4:{
            Fill_Rounded_Rectangle(440, 285, 560, 335, 25, deepblue);
            Draw_Rounded_Rectangle(440, 285, 560, 335, 25, 1,white);
            PrintCC(440+35,300,"ȫְ",HEI,24,1,white);
            Fill_Rounded_Rectangle(620, 285, 740, 335, 25, white);
            Draw_Rounded_Rectangle(620, 285, 740, 335, 25, 1,deepblue);
            PrintCC(620+35,300,"��ְ",HEI,24,1,deepblue);
            
            break;
        }
        case 5:{
            Fill_Rounded_Rectangle(440, 285, 560, 335, 25, white);
            Draw_Rounded_Rectangle(440, 285, 560, 335, 25, 1,deepblue);
            PrintCC(440+35,300,"ȫְ",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(620, 285, 740, 335, 25, deepblue);
            Draw_Rounded_Rectangle(620, 285, 740, 335, 25, 1,white);
            PrintCC(620+35,300,"��ְ",HEI,24,1,white);
            break;  
        }
        default:
            break;
    }
    mouse_on_arrow(mouse);
}

