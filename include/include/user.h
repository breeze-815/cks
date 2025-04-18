#ifndef __USER_H__
#define __USER_H__

void user(int user_pos);
void draw_user(USER *currentUser);
void draw_choice();
void press1(int x);
void number_input(char *number,int bar_x1,int bar_y1,int bar_x2,int bar_y2);

typedef struct Shop
{
	int type;

}Shop;

#endif