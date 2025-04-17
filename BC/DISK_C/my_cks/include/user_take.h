#ifndef __USER_TAKE_H__
#define __USER_TAKE_H__

typedef struct Canteen {
    int id; // Ê³ÌÃID
    char name[50]; // Ê³ÌÃÃû³Æ
}Canteen;

void user_takeout();
void draw_user_takeout();
int press_canteen(int mx, int my);

#endif