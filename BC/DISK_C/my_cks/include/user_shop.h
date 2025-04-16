#ifndef __USER_SHOP_H__
#define __USER_SHOP_H__

typedef struct CartItem{
    int id;//��Ʒid
    int type;//����
    char name[20];//��Ʒ����
    float price;//�۸�
    char photo[50];
    int quantity;//����
    int index_in_products;//����Ʒ�����е���������cnt
} CartItem;//���ﳵ�ڵ���Ʒ

typedef struct ShoppingCart{
    CartItem* items;//���ﳵ����Ʒ
    int itemCount;//���ﳵ����Ʒ��������
    int capacity;//���ﳵ����
} ShoppingCart;//���ﳵ����

typedef struct Product
{
    int id;
    int type;
    char name[20];
    float price;
    char photo[50];
    int quantity;//����

} Product;//��Ʒ



void user_shop();
void draw_user_shop(Product products[],int productCount,int currentpage);
void draw_user_shop_quantity(Product products[],int productCount,int currentpage);
void init_Products(int *productCount);
void AddSub(int mx, int my, int productCount, Product products[], CartItem carts[], int *cartCount, int currentPage);
void addToCart(Product p, CartItem carts[], int *cartCount,int index);
void removeFromCart(Product p, CartItem carts[], int *cartCount);

#endif