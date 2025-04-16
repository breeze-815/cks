#ifndef __USER_SHOP_H__
#define __USER_SHOP_H__

typedef struct CartItem{
    int id;//商品id
    int type;//种类
    char name[20];//商品名称
    float price;//价格
    char photo[50];
    int quantity;//数量
    int index_in_products;//在商品数组中的索引，即cnt
} CartItem;//购物车内的商品

typedef struct ShoppingCart{
    CartItem* items;//购物车内商品
    int itemCount;//购物车内商品种类数量
    int capacity;//购物车容量
} ShoppingCart;//购物车整体

typedef struct Product
{
    int id;
    int type;
    char name[20];
    float price;
    char photo[50];
    int quantity;//数量

} Product;//商品



void user_shop();
void draw_user_shop(Product products[],int productCount,int currentpage);
void draw_user_shop_quantity(Product products[],int productCount,int currentpage);
void init_Products(int *productCount);
void AddSub(int mx, int my, int productCount, Product products[], CartItem carts[], int *cartCount, int currentPage);
void addToCart(Product p, CartItem carts[], int *cartCount,int index);
void removeFromCart(Product p, CartItem carts[], int *cartCount);

#endif