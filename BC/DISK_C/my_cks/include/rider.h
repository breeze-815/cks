#ifndef __RIDER_H__
#define __RIDER_H__

typedef struct Num_of_Orders
{
    int total_cnt;  //总共订单
    int cur_count;  //当前数量
    int hst_count;  //历史数量
}Num_of_Orders;

void rider(int user_pos);
void draw_rider();
void press3(int x);
int rider_Init(USER currentUser);
void draw_rider_Init();
void draw_welcome_rider(USER currentUser);

#endif