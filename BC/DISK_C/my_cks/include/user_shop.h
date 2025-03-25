#ifndef __USER_SHOP_H__
#define __USER_SHOP_H__

typedef struct CART
{
	int productId;//商品ID
    char name[20];//商品名称
    float price;//商品价格
    int quantity;//商品数量

}CART;

typedef struct Product
{
    int id;
    char name[20];
    char price[5];
    int x1;
    int x2;
    int y1;
    int y2;
    char photo[20];

} Product;

void user_shop();
void draw_user_shop(Product products[],int productCount);
void press_item(int x);
void init_Products(int *productCount);
void AddSub(int x, int y, int productCount, Product *products, CART *cart, int cartCount );



#endif