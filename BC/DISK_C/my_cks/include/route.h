#ifndef ROUTE_H
#define ROUTE_H
#include "arrange.h"
typedef struct Node { 
    int x, y;
    int adj_nodes[6];
    int distance[6];
    int num_of_adj_nodes;
    char name [20];//�ڵ�����
} Node; 

// ��route�����ⲿ��������״̬�ṹ��
typedef struct  RouteState {
    int picked[4];       // ��¼4��������ȡ��״̬
    int delivered[4];    // ��¼4���������Ͳ�״̬
    int remaining;       // ʣ��������
    int current_pos;     // ��ǰλ������
    int next_pos;
    int next_type;       // 0 = ȡ��, 1 = �Ͳ� 
} RouteState;

int random_int(int min, int max);
void route( AcceptedOrder acp_orders[], int n_orders);

int dijkstra(Node *start, Node *end, int j);

void draw_route();
#endif