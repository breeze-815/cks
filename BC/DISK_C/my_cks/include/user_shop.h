#ifndef __USER_SHOP_H__
#define __USER_SHOP_H__

void user_shop(int *page,int *shop_type);
void draw_user_shop(int *shop_type);
void press_item(int x);
void init_Products();

typedef struct CART
{
	int productId;
    char name[20];
    float price;
    int quantity;

}CART;

typedef struct Product
{
    int id;
    char name[20];
    float price;

} Product;

#endif