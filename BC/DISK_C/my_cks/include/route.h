#ifndef ROUTE_H
#define ROUTE_H

typedef struct Node { 
    int x, y;
    int adj_nodes[6];
    int distance[6];
    int num_of_adj_nodes;
} Node; 


typedef struct Acp_order{
    char id [5];//������
    int pick_up_index;
    int destination_index;
    int community;//�û���ַ
    int building;//¥����
    //int pick_up_loction;//ȡ���ص�
    char user_name[12];//�û���
    char user_phone[12];//�û��ֻ���
    //char order_time[20];//�µ�ʱ��
} Acp_order;
void draw_route();
void dijkstra(struct Node *start, struct Node *end);
void route();
int Manhattan_Distance(int x1, int y1, int x2, int y2) ;
void dispatch_orders(int start_idx, Acp_order acp_orders[], int n_orders) ;
void draw_finish_button() ;
#endif