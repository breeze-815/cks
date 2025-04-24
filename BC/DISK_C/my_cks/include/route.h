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
typedef struct  RouteState 
{
    int picked[4];       // ��¼4��������ȡ��״̬
    int delivered[4];    // ��¼4���������Ͳ�״̬
    int remaining;       // ʣ��������
    int current_pos;     // ��ǰλ������
    int next_pos;
    int next_type;       // 0 = ȡ��, 1 = �Ͳ� 
    int seq_pos[8];     // ÿһ��Ҫȥ�Ľڵ�����
    int seq_type[8];    // ÿһ�������ͣ�0=ȡ��,1=�Ͳ�
    int seq_order[8];    // ÿһ����Ӧ�Ķ�������
    int seq_len;                // ���г���
    int seq_cursor;             // ��ǰ����ɲ���
} RouteState;

int random_int(int min, int max);
void route( AcceptedOrder acp_orders[], int n_orders,int user_pos);

int dijkstra(Node *start, Node *end, int j);

void draw_route();
#endif