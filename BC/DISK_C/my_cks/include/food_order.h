#ifndef FOOD_ORDER_H
#define FOOD_ORDER_H

#define F_LIST_INIT_SIZE 10 //线性表存储空间的初始分配量
#define F_LISTINCEREMENT 1  //线性表存储空间的分配增量

typedef struct FoodOrder{
    int id;//订单号
    int community;//用户地址
    int building;//楼栋号
    char user_name[12];//用户名
    char user_phone[12];//用户手机号
    char order_time[20];//下单时间
    FoodCart item[20];//购物车内物品信息
    int itemCount;//购物车内物品种类数量
    float total_amount;//总价
    int station;//食堂地址
    int destination;//送达地址
    int pick_up_location;//取餐地点
} FoodOrder;//订单信息  

typedef struct FoodList 
{
	struct FoodOrder* elem;    //存储空间基址
	short length;  //当前长度，改为 short
	short listsize;  //当前存储空间容量，改为 short
}FoodList;//订单线性表 

void food_order(int index);
void draw_food_order(int page);

void InitFList(FoodList*OL);
void ReadAllFood(FoodList *OL);
void DestroyFList(FoodList*OL);
int FoodOrder_pos(FoodList OL,FoodOrder Foodorders);
void FListInsert(FoodList*OL,struct FoodOrder e);
int save_food(FoodOrder FoodOrders);

#endif 