#ifndef __USER_SHOP_H__
#define __USER_SHOP_H__

void user_shop();
void draw_user_shop();
void press_item(int x);
void init_Products(int *productCount);

typedef struct CART
{
	int productId;//��ƷID
    char name[20];//��Ʒ����
    float price;//��Ʒ�۸�
    int quantity;//��Ʒ����

}CART;

typedef struct Product
{
    int id;
    char name[20];
    float price;
    int x1;
    int x2;
    int y1;
    int y2;

} Product;

#endif