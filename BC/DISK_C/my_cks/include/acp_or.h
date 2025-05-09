#ifndef ACP_ORDER_H
#define ACP_ORDER_H
void accept_order(int user_pos); 
double rider_deliver_price(int distance_m, float order_amount);
void draw_accept_order(int page, OrderList *OL, FoodList *FL, DeliverList *DL);
void get_ordtyp_locind(int global_index,
    int *type, int *local_index,
    const OrderList *OL, const FoodList *FL, const DeliverList *DL);
#endif