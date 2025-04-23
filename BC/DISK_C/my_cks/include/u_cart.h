#ifndef __USER_CART_H__
#define __USER_CART_H__

void user_cart();
void draw_user_cart(CartItem carts[], int cartCount, int page,float *sum);
void draw_user_cart_quantity(CartItem carts[], int index, int y);
void AddSub_cart(int mx, int my, CartItem carts[], int* itemCount, int currentPage,float *sum);
#endif