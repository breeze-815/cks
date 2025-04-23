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