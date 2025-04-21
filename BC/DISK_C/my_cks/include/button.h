#ifndef __BUTTON_H__
#define __BUTTON_H__

typedef struct Button{
    int commmunity; // 社区编号
    int x1, y1, x2, y2; // 按钮坐标
    int index;          // 楼栋索引
    int number;        // 楼栋号
} Button;
void draw_button(int x); 
int press_button(int mx, int my, int cur_index, int cur_community); // cur_index: 当前按钮索引
#endif