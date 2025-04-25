#include "all_func.h"

Num_of_Orders num_of_orders;

void rider(int user_pos)
{
    //��ȡ��ǰ�û���Ϣ
	UserList UL = {0};
    USER currentUser;
    ReadAllUser(&UL); // ��ȡ�û��б�
    currentUser=UL.elem[user_pos];// ��ȡ��ǰ�û���Ϣ
    DestroyUList(&UL); // �ͷ��û��б�ռ�
    mouse_off_arrow(&mouse);
	draw_rider();//�����ֳ�ʼ������
	mouse_on_arrow(mouse);
    if (currentUser.state == -1) //δ��ʼ��
    {
        rider_Init(&currentUser); //��ʼ���ɹ���״̬��־λ��1
        save_user(currentUser);
    }
    else 
    {
        draw_welcome_rider(currentUser);
    }
	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(122, 50, 242, 100)==1) //����
        {
            return ;
            //welcome()��ҳ
		}
        else if(mouse_press(342, 50, 462, 100)==1) //�ӵ�
        {
            press3(1);//��ť����
            mouse_off_arrow(&mouse);
            accept_order(user_pos);//����ӵ�ҳ��
            //return����⿪ʼ
            mouse_off_arrow(&mouse); //������꣬��ֹ���²к�
            bar1(0, 150, 1024, 768, white); // ����ӵ��������
            draw_rider(); //�ػ�����
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(562, 50, 682, 100)==1) //·��
        {
            press3(2);//��ť����
            mouse_off_arrow(&mouse);
            route(cur_orders,num_of_orders.cur_count,user_pos);//����·�߽���
            //return����⿪ʼ
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); 
            draw_rider();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //�ҵ�
        {
            press3(3); //��ť����
            bar1(0,150,200,768,deepblue);
            my_information(user_pos);//�����ҵ���Ϣ����
            //return����⿪ʼ
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); 
            draw_rider();
            mouse_on_arrow(mouse);
        }
    }
}


void draw_rider()
{
    bar1(0, 0, 1024, 768, white);
    bar1(0, 0, 1024, 150, deepblue);//�ϲఴť����ɫ

    PrintCC(10, 10, "��ǰ�˺�����Ϊ������", HEI, 24, 1, white);
    //���ذ�ť
    Fill_Rounded_Rectangle(122, 50, 242, 100, 25,white);//��ɫ
    Draw_Rounded_Rectangle(122, 50, 242, 100, 25, 1,deepblue);//����
    PrintCC(122+35, 65, "����", HEI, 24, 1, deepblue);//����
    //�ӵ���ť
    Fill_Rounded_Rectangle(342, 50, 462, 100, 25,white);
    Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);
    PrintCC(342+35, 65, "�ӵ�", HEI, 24, 1, deepblue);
    //·�߰�ť
    Fill_Rounded_Rectangle(562, 50, 682, 100, 25,white);
    Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);
    PrintCC(562+35, 65, "·��", HEI, 24, 1, deepblue);
    //�ҵİ�ť
    Fill_Rounded_Rectangle(782, 50, 902, 100, 25,white);
    Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);
    PrintCC(782+35, 65, "�ҵ�", HEI, 24, 1, deepblue);
}

//�����ť��ɫ����
void press3(int x)
{
    mouse_off_arrow(&mouse);
    switch (x)
    { 
        case 1: //����ӵ�
        {
            Fill_Rounded_Rectangle(342, 50, 462, 100, 25, deepblue);
            Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,white);
            PrintCC(342+35, 65, "�ӵ�", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(562, 50, 682, 100, 25, white);
            Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);
            PrintCC(562+35, 65, "·��", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(782, 50, 902, 100, 25, white);
            Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);
            PrintCC(782+35, 65, "�ҵ�", HEI, 24, 1, deepblue);
            break;
        }
        case 2: //���·��
        {
            Fill_Rounded_Rectangle(342, 50, 462, 100, 25, white);
            Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);
            PrintCC(342+35, 65, "�ӵ�", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(562, 50, 682, 100, 25, deepblue);
            Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,white);
            PrintCC(562+35, 65, "·��", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(782, 50, 902, 100, 25, white);
            Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);
            PrintCC(782+35, 65, "�ҵ�", HEI, 24, 1, deepblue);
            break;
        }
        case 3: //����ҵ�
        {
            //PrintCC(100,1, "��������", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(342, 50, 462, 100, 25, white);
            Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);
            PrintCC(342+35, 65, "�ӵ�", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(562, 50, 682, 100, 25, white);
            Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);
            PrintCC(562+35, 65, "·��", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(782, 50, 902, 100, 25, deepblue);
            Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,white);
            PrintCC(782+35, 65,"�ҵ�", HEI ,24 ,1 ,white);
            break;
        }
        case 4: //���ȫְ
        {
            Fill_Rounded_Rectangle(440, 285, 560, 335, 25, deepblue);
            Draw_Rounded_Rectangle(440, 285, 560, 335, 25, 1,white);
            PrintCC(440+35,300,"ȫְ",HEI,24,1,white);
            Fill_Rounded_Rectangle(620, 285, 740, 335, 25, white);
            Draw_Rounded_Rectangle(620, 285, 740, 335, 25, 1,deepblue);
            PrintCC(620+35,300,"��ְ",HEI,24,1,deepblue);
            
            break;
        }
        case 5: //�����ְ
        {
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

//���ֳ�ʼ����������ʼ���ɹ�����1
void rider_Init(USER *currentUser)
{
    mouse_off_arrow(&mouse);
	draw_rider_Init();//�����ֳ�ʼ������
	mouse_on_arrow(mouse);
    while (1)
    {
        mouse_show_arrow(&mouse);
        if(mouse_press(430, 500, 650, 550)==1) //��ʼ��ʱ���������Ϣ
        {
            number_input(currentUser->number, 435, 505, 645, 545); // �����ֻ���
        }
        
        else if(mouse_press(440, 285, 560, 335)==1) //ȫְ��ť
        {
            press3(4);
            currentUser->ocp=1;
            save_user(*currentUser);

        }
        else if(mouse_press(620, 285, 740, 335)==1) //��ְ��ť
        {
            press3(5);
            currentUser->ocp=2;
            save_user(*currentUser);
        }
        else if (mouse_press(710, 500, 830, 550) == 1) 
        {   
            // ��ȷ������ť�����Ϸ���
            if (strlen(currentUser->number) == 11 && currentUser->number != 0) 
            {
                currentUser->state = 1;         // ��ǳ�ʼ�����
                save_user(*currentUser);  // ����������Ϣ
                PrintCC(860,535,"����ɹ�",HEI,24,1,lightred);
                delay(500);
                bar1(860,535,1000,600,white);
                break;
            } else 
            {
                PrintCC(860,535,"���Ȳ��Ϸ�",HEI,24,1,lightred);
                delay(500);
                bar1(860,535,1000,600,white);
            }
        }
    }
}

//�����ֳ�ʼ������
void draw_rider_Init()
{
    Draw_Rounded_Rectangle(430, 500, 650, 550, 5, 1,deepblue);//�ֻ�������� 
    PrintCC(220,510,"�������ֻ��ţ�",HEI,24,1,deepblue);
    
    Draw_Rounded_Rectangle(710, 500, 830, 550, 25, 1,deepblue);//���水ť
    PrintCC(710+35, 515, "����", HEI, 24, 1, deepblue);

    PrintCC(200,300,"��ѡ���������ͣ�",HEI,24,1,deepblue);
    //ȫְ��ť
    Fill_Rounded_Rectangle(440, 285, 560, 335, 25, white);//��ɫ
    Draw_Rounded_Rectangle(440, 285, 560, 335, 25, 1,deepblue);//����
    PrintCC(440+35,300,"ȫְ",HEI,24,1,deepblue);//����
    //��ְ��ť
    Fill_Rounded_Rectangle(620, 285, 740, 335, 25, white); 
    Draw_Rounded_Rectangle(620, 285, 740, 335, 25, 1,deepblue);
    PrintCC(620+35,300,"��ְ",HEI,24,1,deepblue);
}

void draw_welcome_rider(USER currentUser)
{
    char show_name[20];
    sprintf(show_name,"�û���%s",currentUser.name);
    PrintText(350,400,show_name,HEI,32,1,black);
    if(currentUser.ocp == 1)
    PrintText(150,400,"ȫְ����",HEI,32,1,black);
    else
    PrintText(150,400,"��ְ����",HEI,32,1,black);
    
    PrintText(350,600,"��ӭ����",HEI,32,1,black);
}