#include "all_func.h"

void user_cart() {
    int page = 0;
    int totalPage = (cart.itemCount + 3) / 4; // 向上取整
    mouse_off_arrow(&mouse);

    draw_user_cart(carts, cart.itemCount, page);
    mouse_on_arrow(mouse);

    while (1) {
        mouse_show_arrow(&mouse);

        // 点击返回商店
        if (mouse_press(40, 113, 160, 163) == 1) 
		{
            user_shop();
            return;
        }
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_user_cart(carts, cart.itemCount, page);
            } else {
                // 提示：已是第一页
                PrintCC(600, 700, "已是第一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(600, 700, 790, 740, white);
            }
        }
		else if (mouse_press(420, 700, 540, 750) == 1) 
		{
			if (page < totalPage - 1) {
				page++;
				draw_user_cart(carts, cart.itemCount, page);
			} else {
				// 提示：已是最后一页
				PrintCC(600, 700, "已是最后一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(600, 700, 790, 740, white);
			}
		}
		else if(mouse_press(270, 0, 1024, 680) == 1) {
			MouseGet(&mouse);
			AddSub_cart(mouse.x, mouse.y, carts, &cart.itemCount, page);
			delay(100);
		}
		
    }
}


void draw_user_cart(CartItem carts[], int cartCount, int page) {
    int i;
    int start = page * 4;
    int end = start + 4;
    if (end > cartCount) end = cartCount;

    bar1(200, 0, 1024, 768, white);
    bar1(0, 250, 199, 768, deepblue);

    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // 上一页
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // 下一页
    PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue); // 生成订单
    PrintCC(850, 715, "生成订单", HEI, 24, 1, deepblue);

    for (i = start; i < end; i++) {
        char total_str[50];
        char quantity_str[20];
        char type_str[20];
        int y = 10 + 170 * (i - start);
        int productIndex = carts[i].index_in_products;
        int quantity = products[productIndex].quantity;

        switch (shops.type) {
            case 1: strcpy(type_str, "紫菘喻园超市"); break;
            case 2: strcpy(type_str, "沁苑喻园超市"); break;
            case 3: strcpy(type_str, "韵苑喻园超市"); break;
            default: strcpy(type_str, "未知超市"); break;
        }

        sprintf(total_str, "总价:%.2f", products[productIndex].price * quantity);
        sprintf(quantity_str, "x%d", quantity);

        Draw_Rounded_Rectangle(220, y, 1000, y + 150, 30, 1, 0x6B4D);
        Readbmp64k(240, y + 15, carts[i].photo);

        PrintCC(370, y + 15, carts[i].name, HEI, 32, 1, 0x0000);//显示商品名
        PrintCC(370, y + 110, type_str, HEI, 24, 1, 0x0000);//显示超市名
        PrintText(760, y + 15, (unsigned char*)total_str, HEI, 32, 1, 0x0000);//显示总价
        PrintText(920, y + 60, (unsigned char*)quantity_str, HEI, 32, 1, 0x0000);//显示数量

        Line_Thick(840, y + 120, 860, y + 120, 1, black); // 减号

        Line_Thick(840, y + 120, 860, y + 120, 1, black); // 减号
        Line_Thick(940, y + 120, 960, y + 120, 1, black); // 加号横
        Line_Thick(950, y + 110, 950, y + 130, 1, black); // 加号竖
    }
}


void draw_user_cart_quantity(CartItem carts[], int index, int y) {
    char total_str[50];
    char quantity_str[20];

    int productIndex = carts[index].index_in_products;
    int quantity = products[productIndex].quantity;

    sprintf(total_str, "总价:%.2f", products[productIndex].price * quantity);
    sprintf(quantity_str, "x%d", quantity);

    bar1(760, y + 15, 990, y + 60, white); // 清除总价区域
    bar1(920, y + 60, 990, y + 90, white); // 清除数量区域

    PrintText(760, y + 15, (unsigned char*)total_str, HEI, 32, 1, 0x0000);
    PrintText(920, y + 60, (unsigned char*)quantity_str, HEI, 32, 1, 0x0000);
}


void AddSub_cart(int mx, int my, CartItem carts[], int* itemCount, int currentPage) {
    int i;
    int start = currentPage * 4;
    int end = start + 4;
    if (end > *itemCount) end = *itemCount;

    for (i = start; i < end; i++) {
        int localIndex = i - start;
        int y = 10 + 170 * localIndex;
        int productIndex = carts[i].index_in_products; // 映射回 products

        // 减号区域
        if (mx >= 840 && mx <= 860 && my >= y + 115 && my <= y + 125) {
            if (products[productIndex].quantity > 1) {
                products[productIndex].quantity--;
                draw_user_cart_quantity(carts, i, y); // 仅更新该商品
            } else {
				int j;
                // 移除商品
                products[productIndex].quantity = 0;

                // 从购物车中移除
                
                for (j = i; j < *itemCount - 1; j++) {
                    carts[j] = carts[j + 1];
                }
                (*itemCount)--;

                draw_user_cart(carts, *itemCount, currentPage); // 重绘整个页面
            }
            return;
        }

        // 加号区域
        if (mx >= 940 && mx <= 960 && my >= y + 115 && my <= y + 125) {
            products[productIndex].quantity++;
            draw_user_cart_quantity(carts, i, y); // 仅更新该商品
            return;
        }
    }
}



