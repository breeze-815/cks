#include <all_func.h>

void my_information(int user_pos)
{
    UserList UL = {0};
    USER currentUser;
    mouse_off_arrow(&mouse);
    ReadAllUser(&UL); // ��ȡ�û��б�
    currentUser=UL.elem[user_pos];// ��ȡ��ǰ�û���Ϣ
    DestroyUList(&UL); // �ͷ��û��б�ռ�
    draw_my_information(currentUser);
	mouse_on_arrow(mouse);
	while(1)
    {
		mouse_show_arrow(&mouse);
		if(mouse_press(122, 50, 242, 100)==1)
        {
            mouse_off_arrow(&mouse);
            return;
            //rider(int pos)
		}
        else if(mouse_press(342, 50, 462, 100)==1) //�ӵ�
        {
            press3(1);//����ӵ�����
            accept_order(user_pos);//�ӵ�ҳ��
            //return����⿪ʼ
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // ����ӵ��������
            draw_my_information(currentUser);
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(562, 50, 682, 100)==1)
        {
            mouse_off_arrow(&mouse);
            press3(2);//����·�߹滮����
            route(cur_orders,num_of_orders.cur_count,user_pos);//����·�߹滮����
            //return����⿪ʼ
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // ����ӵ��������
            draw_my_information(currentUser);
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //�ҵ�
        {
            mouse_off_arrow(&mouse);
            press3(3); //��ť����
            my_accept_order(user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_my_information(currentUser);
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 439, 160, 489) == 1)//��ǰ
        {
            press4(2);
            my_accept_order(user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_my_information(currentUser);
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 602, 160, 652) == 1)//��ʷ
        {
            press4(3);
            my_history_order(user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_my_information(currentUser);
            mouse_on_arrow(mouse);
        }
    }
}

void draw_my_information(USER currentUser)
{
    char show_name[50];
    char show_num[50];
    char show_account[50];
    bar1(0, 150, 1024, 768,white);
    bar1(0,150,200,768,deepblue);
    sprintf(show_name,"�û���%s",currentUser.name);
    PrintText(350,200,show_name,HEI,32,1,black);
    sprintf(show_num,"�ֻ��ţ�%s",currentUser.number);
    PrintText(350,350,show_num,HEI,32,1,black);

    if(currentUser.ocp==1 && currentUser.type==3)
    PrintText(350,500,"�������ͣ�ȫְ����",HEI,32,1,black);
    else if(currentUser.ocp == 2 && currentUser.type == 3)
    PrintText(350,500,"�������ͣ���ְ����",HEI,32,1,black);

    sprintf(show_account,"�˻���%.2f",currentUser.account);
    PrintText(350,650,show_account,HEI,32,1,black);


    Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);//��ɫ
    Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);//��ɫ
    Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);//��ɫ

    
    Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);//�˻���ť
    Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);//��ǰ��ť
    Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);//��ʷ��ť

    PrintCC(75,291,"�˻�",HEI,24,1,deepblue);
    PrintCC(75,454,"��ǰ",HEI,24,1,deepblue);
    PrintCC(75,617,"��ʷ",HEI,24,1,deepblue);
}

void press4(int x)
{
    mouse_off_arrow(&mouse);
    switch (x)
    { 
        case 1:
        {
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25, deepblue);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,white);
            PrintCC(75,291, "�˻�", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25, white);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454, "��ǰ", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25, white);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617, "��ʷ", HEI, 24, 1, deepblue);
            break;
        }
        case 2:
        {
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25, white);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75, 291, "�˻�", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25, deepblue);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,white);
            PrintCC(75, 454, "��ǰ", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25, white);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75, 617, "��ʷ", HEI, 24, 1, deepblue);
            break;
        }
        case 3:
        {
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25, white);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291, "�˻�", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25, white);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454, "��ǰ", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25, deepblue);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,white);
            PrintCC(75, 617, "��ʷ", HEI ,24 ,1 ,white);
            break;
        }
        default:
            break;
    }
    mouse_on_arrow(mouse);
}