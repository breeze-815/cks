#ifndef USER_FOOD_H
#define USER_FOOD_H

typedef struct Food {
    int id; // ʳ��ID
    int station; // ʳ�ñ��
    char name[50]; // ʳ������
    float price; // ʳ��۸�
    char photo[50]; // ʳ��ͼƬ·��
    int quantity; // ʳ������
} Food;

typedef struct FoodCart {
    int id;//��Ʒid
    int type;//����
    char name[20];//��Ʒ����
    float price;//�۸�
    char photo[50];
    int quantity;//����
    int index_in_foods;//����Ʒ�����е���������cnt
} FoodCart;//���ﳵ�ڵ���Ʒ

typedef struct ShoppingFood{
    FoodCart* items;//���ﳵ����Ʒ
    int itemCount;//���ﳵ����Ʒ��������
    int capacity;//���ﳵ����
} ShoppingFood;//���ﳵ����

void user_food(int index);
void draw_user_food(int index);
void draw_food_quantity(Food foods[]);
void AddSub_food(int mx, int my, int foodCount, Food foods[], FoodCart food_carts[], int* itemCount);
void addToCart_food(Food f, FoodCart food_carts[], int *itemCount,int index);
void removeFromCart_food(Food f, FoodCart food_carts[], int *itemCount);
#endif