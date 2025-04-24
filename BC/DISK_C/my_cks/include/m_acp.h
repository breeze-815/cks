#ifndef __MY_ACP_H
#define __MY_ACP_H

void add_my_accept(OrderList *OL, FoodList *FL, DeliverList *DL,int type, int local_index);
void delete_my_order(int index);
void my_accept_order(int user_pos);
void draw_my_accept();
void cut_current_order(int index);

#endif