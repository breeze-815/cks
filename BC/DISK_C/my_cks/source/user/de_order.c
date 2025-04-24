#include "all_func.h"

void de_order() {
    mouse_off_arrow(&mouse);
    draw_de_order();
    mouse_on_arrow(mouse);
    while (1) {
        mouse_show_arrow(&mouse);
        if(mouse_press(40, 113, 160, 163)==1)
        {
            return;
			//welcome();//��ҳ
		}
        else if(mouse_press(40, 276, 160, 326)==1)
        {
            press_func(1);//���볬��ҳ��
            user_shop();//�û�����ҳ�� 
            return;
        }
        else if(mouse_press(40, 439, 160, 489)==1)
        {
            press_func(2);//��������ҳ��
            user_takeout();//�û�����ҳ�� 
            return;
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            press_func(3);//������ҳ��
            user_deliver();//�û����ҳ�� 
            return;
        }else if(mouse_press(800, 700, 1000, 750)==1)//ȷ�ϲ�֧��
        {
            PrintCC(600, 715,"����ɹ�",HEI,24,1,lightred); // ֧���ɹ���ʾ
            delay(500);
            bar1(600, 715,780,750,white); // ���֧���ɹ���ʾ
            return;
        }
    }
}

void draw_de_order() {
    DeliverList DL={0};
    Deliver current; // ��ǰ����
    char time_str[100]; // ��ӡ�µ�ʱ��
    char user_name[100]; // ��ӡ�û���
    char user_phone[100]; // ��ӡ�û��ֻ���
    char order_number[100]; // ��ӡ������
    char address[100]; // ��ӡ�û���ַ
    char community[100]; // �����ַ���
    char building[100]; // ¥���ַ���
    char code[100]; // ȡ�����ַ���
    char company_str[100];// ��ݹ�˾�ַ���
    char station_str[100];// վ���ַ���

    bar1(200, 0, 1024, 768,white);

    ReadAllDeliver(&DL); // ��ȡ���ж���

    current = DL.elem[DL.length-1]; // ��ǰ����

    DestroyDList(&DL); // �ͷŶ����б�ռ�

    sprintf(order_number, "�����ţ�%d", current.id); // ������
    sprintf(time_str, "�µ�ʱ�䣺%s",current.time );
    sprintf(user_name, "�û�����%s", current.name);
    sprintf(user_phone, "�ֻ��ţ�%s", current.number);
    sprintf(code, "ȡ���룺%s", current.code);
    sprintf(company_str, "����̣�%s", companys[current.company-1].name);
    sprintf(station_str, "վ�㣺%s", stations[current.station-1].name);

    if (current.station == 0)
            sprintf(address,"��ַ��δ�󶨵�ַ");
        else
            sprintf(address, "��ַ��%s", node[current.index].name); // �û���ַ
    
    PrintText(250, 50, order_number, HEI, 24, 1, black);//��ʾ������
    PrintText(250, 100, time_str, HEI, 24, 1, black);//��ʾ�µ�ʱ��
    PrintText(250, 150, user_name, HEI, 24, 1, black);//��ʾ�û���
    PrintText(250, 200, user_phone, HEI, 24, 1, black);//��ʾ�ֻ���
    PrintText(250, 250, address, HEI, 24, 1, black);//��ʾ��ַ
    PrintText(250, 300, code, HEI, 24, 1, black);//��ʾȡ����
    PrintText(250, 350, company_str, HEI, 24, 1, black);//��ʾ��ݹ�˾
    PrintText(250, 400, station_str, HEI, 24, 1, black);//��ʾվ��

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue); // ȷ�ϲ�֧��
    PrintCC(830, 715, "ȷ�ϲ�֧��", HEI, 24, 1, deepblue);

}