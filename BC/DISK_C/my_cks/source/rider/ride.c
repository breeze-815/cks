#include "all_func.h"

void rider(int user_pos){
    // OrderList OL = {0};
    // FoodList FL = {0};
    // DeliverList DL = {0};
    // ReadAllDeliver(&DL); // ��ȡ����б�
    // ReadAllOrder(&OL); // ��ȡ�����б�
    // ReadAllFood(&FL); // ��ȡʳƷ�б�
    // mouse_off_arrow(&mouse);
	
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
            my_accept_order();
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_rider();
            mouse_on_arrow(mouse);
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

    Draw_Rounded_Rectangle(122, 50, 242, 100, 25, 1,deepblue);//����
    Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);//�ӵ�
    Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);//·��
    Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);//�˻�

    PrintCC(122+35, 65, "����", HEI, 24, 1, deepblue);
    PrintCC(342+35, 65, "�ӵ�", HEI, 24, 1, deepblue);
    PrintCC(562+35, 65, "·��", HEI, 24, 1, deepblue);
    PrintCC(782+35, 65, "�ҵ�", HEI, 24, 1, deepblue);
    
    PrintCC(10, 10, "��ǰ�˺�����Ϊ������", HEI, 24, 1, white);

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
        }
    mouse_on_arrow(mouse);
}