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


// typedef struct Acp_order{
//     char id [5];//������
//     int pick_up_index;
//     int destination_index;
//     int community;//�û���ַ
//     int building;//¥����
//     //int pick_up_loction;//ȡ���ص�
//     char user_name[12];//�û���
//     char user_phone[12];//�û��ֻ���
//     //char order_time[20];//�µ�ʱ��
// } Acp_order;

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