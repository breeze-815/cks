#ifndef __USER_DE_H__
#define __USER_DE_H__

typedef struct Deliver
{
    int type; // �������
    char name[10]; // �������
    char code[10]; // ��ݵ���
    char address; // ��ַ
} Deliver;

void user_deliver();
void draw_user_deliver();
void press_station(int x);
void deliver_input(char *deliver_code,int bar_x1,int bar_y1,int bar_x2,int bar_y2);

#endif