#ifndef ACP_ORDER_H
#define ACP_ORDER_H
void accept_order();   
void draw_accept_order(int page, OrderList *OL, FoodList *FL, DeliverList *DL ,int total_cnt); // ���ƽӵ�ҳ��
double rider_deliver_price(int distance_m, float order_amount) ;
#endif