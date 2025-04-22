#ifndef ROUTE_H
#define ROUTE_H
#include "arrange.h"
typedef struct Node { 
    int x, y;
    int adj_nodes[6];
    int distance[6];
    int num_of_adj_nodes;
    char name [20];//节点名称
} Node; 


// typedef struct Acp_order{
//     char id [5];//订单号
//     int pick_up_index;
//     int destination_index;
//     int community;//用户地址
//     int building;//楼栋号
//     //int pick_up_loction;//取货地点
//     char user_name[12];//用户名
//     char user_phone[12];//用户手机号
//     //char order_time[20];//下单时间
// } Acp_order;

// 在route函数外部定义任务状态结构体
typedef struct  RouteState {
    int picked[4];       // 记录4个订单的取餐状态
    int delivered[4];    // 记录4个订单的送餐状态
    int remaining;       // 剩余任务数
    int current_pos;     // 当前位置索引
    int next_pos;
    int next_type;       // 0 = 取餐, 1 = 送餐 
} RouteState;

int random_int(int min, int max);
void route( AcceptedOrder acp_orders[], int n_orders);


int dijkstra(Node *start, Node *end, int j);




void draw_route();
#endif