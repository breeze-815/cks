#ifndef __USER_ORDER_H__
#define __USER_ORDER_H__

#define O_LIST_INIT_SIZE 10 //线性表存储空间的初始分配量
#define O_LISTINCEREMENT 1  //线性表存储空间的分配增量

typedef struct Order{
    int id;//订单号
    int community;//用户地址
    int building;//楼栋号
    char user_name[12];//用户名
    char user_phone[12];//用户手机号
    char order_time[20];//下单时间
    CartItem item[20];//购物车内物品信息
    int itemCount;//购物车内物品种类数量
    float total_amount;//总价
} Order;//订单信息

typedef struct OrderList
{
	struct Order* elem;    //存储空间基址
	short length;  //当前长度，改为 short
	short listsize;  //当前存储空间容量，改为 short
}OrderList;//订单线性表 

void user_order();
void draw_user_order(int page);
void draw_info();

char* get_current_time();

void InitOList(OrderList*OL);
void ReadAllOrder(OrderList *OL);
void DestroyOList(OrderList*OL);
int Order_pos(OrderList OL,Order orders);
void OListInsert(OrderList*OL,struct Order e);
int save_order(Order orders);

#endif