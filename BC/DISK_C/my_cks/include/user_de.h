#ifndef __USER_DE_H__
#define __USER_DE_H__

typedef struct Deliver
{
    int type; // 快递类型
    char name[10]; // 快递名称
    char code[10]; // 快递单号
    char address; // 地址
} Deliver;

void user_deliver();
void draw_user_deliver();
void press_station(int x);
void deliver_input(char *deliver_code,int bar_x1,int bar_y1,int bar_x2,int bar_y2);

#endif