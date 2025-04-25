#ifndef __MY_HST_H
#define __MY_HST_H
void my_history_order(int user_pos);
void move_to_history(AcceptedOrder cur_orders[], int order_idx);
void draw_my_history_order();
void draw_my_history_detail_body(int type, int index);
void my_history_detail(int index, int user_pos); 
void draw_my_history_detail(int type,int index,int page);
#endif