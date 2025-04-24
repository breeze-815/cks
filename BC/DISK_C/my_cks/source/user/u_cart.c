#include "all_func.h"

void user_cart() {
    int page = 0;// 初始页码
    int totalPage = (cart.itemCount + 3) / 4; // 向上取整
    float sum=0;//总价

    mouse_off_arrow(&mouse);

    draw_user_cart(carts, cart.itemCount, page,&sum);
    mouse_on_arrow(mouse);

    while (1) {
        mouse_show_arrow(&mouse);

        // 点击返回商店
        if (mouse_press(40, 113, 160, 163) == 1) 
		{
            user_shop();
            return;
        }
		else if (mouse_press(800, 700, 1000, 750) == 1)
		{
            if(sum<10.0)
            {
                PrintText(500, 25, "未满10元，无法配送", HEI, 24, 1, lightred);
				delay(500);
				bar1(500, 25, 750, 60, white);
            }
            else
            {
                user_order();// 点击生成订单按钮，进入订单页面

                //return后从这开始
                mouse_off_arrow(&mouse);
                bar1(200, 0, 1024, 768, white); // 清除注册界面残留
                draw_user_cart(carts, cart.itemCount, page,&sum);
                mouse_on_arrow(mouse);
            }
            
		}
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_user_cart(carts, cart.itemCount, page,&sum);
            } else {
                // 提示：已是第一页
                PrintCC(550, 25, "已是第一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 25, 700, 60, white);
            }
        }
		else if (mouse_press(420, 700, 540, 750) == 1) 
		{
			if (page < totalPage - 1) {
				page++;
				draw_user_cart(carts, cart.itemCount, page,&sum);
			} else {
				// 提示：已是最后一页
				PrintCC(550, 25, "已是最后一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 25, 700, 60, white);
			}
		}
		else if(mouse_press(270, 0, 1024, 680) == 1) {
			MouseGet(&mouse);
			AddSub_cart(mouse.x, mouse.y, carts, &cart.itemCount, page,&sum);
			delay(100);
		}
		
    }
}


void draw_user_cart(CartItem carts[], int cartCount, int page,float *sum) {
    int i,k;//循环变量
    int start = page * 4;// 起始商品索引
    int end = start + 4;// 结束商品索引
    char sum_str[20];//总价字符串
    if (end > cartCount) end = cartCount;// 防止越界

    bar1(200, 0, 1024, 768, white);
    bar1(0, 250, 199, 768, deepblue);

    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // 上一页
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // 下一页
    PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue); // 生成订单
    PrintCC(850, 715, "生成订单", HEI, 24, 1, deepblue);

    for (i = start; i < end; i++) {//显示商品信息
        char total_str[50];//商品总价
        char quantity_str[20];//商品数量
        char type_str[20];//种类名
        int y = 10 + 170 * (i - start);//商品框的y坐标
        int productIndex = carts[i].index_in_products;//商品索引
        int quantity = products[productIndex].quantity;//商品数量

        sprintf(total_str, "金额:%.2f", products[productIndex].price * quantity);//将金额转换为字符串
        sprintf(quantity_str, "x%d", quantity);//将数量转换为字符串

        switch(products[productIndex].type){//根据商品类型显示种类名
            case 1: strcpy(type_str, "生活用品"); break;
            case 2: strcpy(type_str, "文具"); break;
            case 3: strcpy(type_str, "零食"); break;
            case 4: strcpy(type_str, "饮料"); break;
            case 5: strcpy(type_str, "运动用品"); break;
            case 6: strcpy(type_str, "水果"); break;
            case 7: strcpy(type_str, "文创"); break;
            default: strcpy(type_str, "未知"); break;
        }
       
        Draw_Rounded_Rectangle(220, y, 1000, y + 150, 30, 1, 0x6B4D);//商品框
        Readbmp64k(240, y + 15, carts[i].photo);//显示商品图片

        PrintCC(370, y + 15, carts[i].name, HEI, 32, 1, 0x0000);//显示商品名
        PrintCC(370, y + 110, type_str, HEI, 24, 1, 0x0000);//显示种类名
        PrintText(760, y + 15, (unsigned char*)total_str, HEI, 32, 1, 0x0000);//显示金额
        PrintText(920, y + 60, (unsigned char*)quantity_str, HEI, 32, 1, 0x0000);//显示数量

        Line_Thick(840, y + 120, 860, y + 120, 1, black); // 减号

        Line_Thick(940, y + 120, 960, y + 120, 1, black); // 加号横
        Line_Thick(950, y + 110, 950, y + 130, 1, black); // 加号竖
    }

    *sum = 0;
    for (k = 0; k < cart.itemCount; k++) {
        int pIndex = carts[k].index_in_products;
        *sum += products[pIndex].price * products[pIndex].quantity;
    }//计算总价

    sprintf(sum_str, "总价:%.2f", *sum);
    PrintText(560,710, (unsigned char*)sum_str, HEI, 32, 1, 0x0000);//显示金额
}

// 更新显示商品数量
void draw_user_cart_quantity(CartItem carts[], int index, int y) {
    char total_str[50];
    char quantity_str[20];
    char sum_str[20];
    float sum = 0;
    int i;

    int productIndex = carts[index].index_in_products;
    int quantity = products[productIndex].quantity;

    sprintf(total_str, "金额:%.2f", products[productIndex].price * quantity);
    sprintf(quantity_str, "x%d", quantity);

    // === 重新计算整个购物车总价 ===
    for (i = 0; i < cart.itemCount; i++) {
        int pIndex = carts[i].index_in_products;
        sum += products[pIndex].price * products[pIndex].quantity;
    }
    sprintf(sum_str, "总价:%.2f", sum);

    // === 清除原有数值显示区域 ===
    bar1(760, y + 15, 990, y + 60, white); // 金额区域
    bar1(920, y + 60, 990, y + 90, white); // 数量区域
    bar1(560, 710, 790, 750, white);       // 总价区域

    // === 显示新数值 ===
    PrintText(760, y + 15, (unsigned char*)total_str, HEI, 32, 1, 0x0000);     // 显示该商品金额
    PrintText(920, y + 60, (unsigned char*)quantity_str, HEI, 32, 1, 0x0000);  // 显示该商品数量
    PrintText(560, 710, (unsigned char*)sum_str, HEI, 32, 1, 0x0000);          // 显示整个购物车总价
}


// 添加或减少购物车中商品数量
void AddSub_cart(int mx, int my, CartItem carts[], int* itemCount, int currentPage,float *sum) {
    int i,k;
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
                // 重新计算总价
                *sum = 0;
                for (k = 0; k < cart.itemCount; k++) 
                {
                    int pIndex = carts[k].index_in_products;
                    *sum += products[pIndex].price * products[pIndex].quantity;
                }
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
                
                // 更新总价
                *sum = 0;
                for (k = 0; k < cart.itemCount; k++) 
                {
                    int pIndex = carts[k].index_in_products;
                    *sum += products[pIndex].price * products[pIndex].quantity;
                }
                draw_user_cart(carts, *itemCount, currentPage,&sum); // 重绘整个页面
            }
            return;
        }

        // 加号区域
        if (mx >= 940 && mx <= 960 && my >= y + 115 && my <= y + 125) {
            products[productIndex].quantity++;
            for (k = 0; k < cart.itemCount; k++) {
                int pIndex = carts[k].index_in_products;
                *sum += products[pIndex].price * products[pIndex].quantity;
            }
            draw_user_cart_quantity(carts, i, y); // 仅更新该商品
            return;
        }
    }
}



