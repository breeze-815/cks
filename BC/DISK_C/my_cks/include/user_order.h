#ifndef __USER_ORDER_H__
#define __USER_ORDER_H__

#define O_LIST_INIT_SIZE 10 //���Ա�洢�ռ�ĳ�ʼ������
#define O_LISTINCEREMENT 1  //���Ա�洢�ռ�ķ�������

typedef struct Order{
    int id;//������
    int address;//�û���ַ
    char user_name[12];//�û���
    char user_phone[12];//�û��ֻ���
    char order_time[20];//�µ�ʱ��
    CartItem item[20];//���ﳵ����Ʒ��Ϣ
    int itemCount;//���ﳵ����Ʒ��������
    float total_amount;//�ܼ�
} Order;//������Ϣ

typedef struct OrderList
{
	struct Order* elem;    //�洢�ռ��ַ
	short length;  //��ǰ���ȣ���Ϊ short
	short listsize;  //��ǰ�洢�ռ���������Ϊ short
}OrderList;//�������Ա� 

void user_order();

void draw_page_header(USER *currentUser, int order_id, char *current_time);
void draw_pagination_buttons();
void draw_order_items(int startIdx, int endIdx, int item_y);
void draw_total_amount(int item_y);
void store_order_data(char *current_time, USER *currentUser, float total_amount);
void draw_user_order(int page);
<<<<<<< HEAD
void draw_info();

void draw_user_order(int page);


=======
>>>>>>> parent of 36a1d1b (更改输入框)
char* get_current_time();

void InitOList(OrderList*OL);
void ReadAllOrder(OrderList *OL);
void DestroyOList(OrderList*OL);
int Order_pos(OrderList OL,Order orders);
void OListInsert(OrderList*OL,struct Order e);
int save_order(Order orders);

#endif