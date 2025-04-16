#ifndef USER_FOOD_H
#define USER_FOOD_H

typedef struct Food {
    int id; // 食物ID
    int station; // 食堂编号
    char name[50]; // 食物名称
    float price; // 食物价格
    char photo[50]; // 食物图片路径
    int quantity; // 食物数量
} Food;

typedef struct FoodCart {
    int id;//商品id
    int type;//种类
    char name[20];//商品名称
    float price;//价格
    char photo[50];
    int quantity;//数量
    int index_in_foods;//在商品数组中的索引，即cnt
} FoodCart;//购物车内的商品

typedef struct ShoppingFood{
    FoodCart* items;//购物车内商品
    int itemCount;//购物车内商品种类数量
    int capacity;//购物车容量
} ShoppingFood;//购物车整体

void user_food(int index);
void draw_user_food(int index);
void draw_food_quantity(Food foods[]);
void AddSub_food(int mx, int my, int foodCount, Food foods[], FoodCart food_carts[], int* itemCount);
void addToCart_food(Food f, FoodCart food_carts[], int *itemCount,int index);
void removeFromCart_food(Food f, FoodCart food_carts[], int *itemCount);
#endif