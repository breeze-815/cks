#ifndef __BUTTON_H__
#define __BUTTON_H__

typedef struct Button{
    int commmunity; // �������
    int x1, y1, x2, y2; // ��ť����
    int index;          // ¥������
    int number;        // ¥����
} Button;
void draw_button(int x); 
int press_button(int mx, int my, int cur_index, int cur_community); // cur_index: ��ǰ��ť����
#endif