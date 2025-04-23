#ifndef FOOD_ORDER_H
#define FOOD_ORDER_H

#define F_LIST_INIT_SIZE 10 //���Ա�洢�ռ�ĳ�ʼ������
#define F_LISTINCEREMENT 1  //���Ա�洢�ռ�ķ�������

typedef struct FoodOrder{
    int id;//������
    int community;//�û���ַ
    int building;//¥����
    char user_name[12];//�û���
    char user_phone[12];//�û��ֻ���
    char order_time[20];//�µ�ʱ��
    FoodCart item[20];//���ﳵ����Ʒ��Ϣ
    int itemCount;//���ﳵ����Ʒ��������
    float total_amount;//�ܼ�
    int station;//ʳ�õ�ַ
    int destination;//�ʹ��ַ
    int pick_up_location;//ȡ�͵ص�
} FoodOrder;//������Ϣ  

typedef struct FoodList 
{
	struct FoodOrder* elem;    //�洢�ռ��ַ
	short length;  //��ǰ���ȣ���Ϊ short
	short listsize;  //��ǰ�洢�ռ���������Ϊ short
}FoodList;//�������Ա� 

void food_order(int index);
void draw_food_order(int page);

void InitFList(FoodList*OL);
void ReadAllFood(FoodList *OL);
void DestroyFList(FoodList*OL);
int FoodOrder_pos(FoodList OL,FoodOrder Foodorders);
void FListInsert(FoodList*OL,struct FoodOrder e);
int save_food(FoodOrder FoodOrders);

#endif 