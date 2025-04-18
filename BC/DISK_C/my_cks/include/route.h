#ifndef ROUTE_H
#define ROUTE_H

typedef struct Node { 
    int x, y;
    int adj_nodes[6];
    int distance[6];
    int num_of_adj_nodes;
} Node; 


typedef struct Acp_order{
    char id [5];//订单号
    int pick_up_index;
    int destination_index;
    int community;//用户地址
    int building;//楼栋号
    //int pick_up_loction;//取货地点
    char user_name[12];//用户名
    char user_phone[12];//用户手机号
    //char order_time[20];//下单时间
} Acp_order;
void draw_route();
void dijkstra(struct Node *start, struct Node *end);
void route();
int Manhattan_Distance(int x1, int y1, int x2, int y2) ;
void dispatch_orders(int start_idx, Acp_order acp_orders[], int n_orders) ;
void draw_finish_button() ;
#endif