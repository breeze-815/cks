#include "all_func.h"

void business_order(){
    int page = 0; // 当前页码

    OrderList OL = {0};

    ReadAllOrder(&OL); // 读取订单列表

    mouse_off_arrow(&mouse);
	
	draw_business_order(page,&OL);

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            DestroyOList(&OL); // 释放订单列表内存
            return;
			//business(users.pos);
		}
        else if(mouse_press(490, 100, 610, 150)==1)
        {
            press_type(1);//进入超市页面
        }
        else if(mouse_press(670, 100, 790, 150)==1)
        {
            press_type(2);//进入选择餐厅页面
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            business_order();//商家订单页面
        }else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_business_order(page,&OL);
            } else {
                // 提示：已是第一页
                PrintCC(550, 35, "已是第一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 35, 700, 60, white);
            }
        }
		else if (mouse_press(420, 700, 540, 750) == 1) 
		{
			if ((page + 1) * 5 < OL.length) {
				page++;
                draw_business_order(page,&OL);
			} else {
				// 提示：已是最后一页
				PrintCC(550, 35, "已是最后一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 35, 700, 60, white);
			}
		}
        else if(mouse_press(200, 0, 1024, 680) == 1) {
            int order_index = (mouse.y - 25) / 120 + page * 5; // 根据点击位置计算订单索引

			MouseGet(&mouse);

            if (order_index >= 0 && order_index < OL.length) 
            {
                business_detail(order_index); // 显示订单详情
                //return后从这开始
                mouse_off_arrow(&mouse);
                bar1(200, 0, 1024, 768, white); // 清除订单详情界面残留
                draw_business_order(page,&OL); // 重新绘制订单列表
                mouse_on_arrow(mouse);
            }
		}
    }
}

void draw_business_order(int page,OrderList *OL){

    int i;
    int y_offset = 25; // 初始Y轴偏移

    int orders_per_page = 5; // 每页最多显示5个订单
    int start_index = page * orders_per_page; // 当前页的起始订单索引
    int end_index = start_index + orders_per_page; // 当前页的结束订单索引

    if (end_index > OL->length) {
        end_index = OL->length; // 防止越界
    }

    bar1(200, 0, 1024, 768,white);

    Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//返回填色
    Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//返回//圆角按钮，字的x+35，y+15
    PrintCC(75,128,"返回",HEI,24,1,deepblue);

    
    for (i = start_index; i < end_index; i++) {
        char order_id[10]; // 订单ID字符串
        char user_info[16]; // 用户信息字符串
        char total_price[10];// 总价字符串

        Order order = OL->elem[i]; // 获取当前订单

        // 绘制订单框
        Draw_Rounded_Rectangle(220, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

        // 显示订单简略信息
        sprintf(order_id, "订单%d", i + 1);
        PrintText(235, y_offset + 15, order_id, HEI, 24, 1, 0x0000);

        sprintf(user_info, "下单人：%s", order.user_name);
        PrintText(235, y_offset + 65, user_info, HEI, 24, 1, 0x0000);

        
        sprintf(total_price, "总价：%.2f", order.total_amount);
        PrintText(800, y_offset + 15, total_price, HEI, 24, 1, 0x0000);

        PrintText(665, y_offset + 65, order.order_time, HEI, 24, 1, 0x0000);

        y_offset += 120; // 每个订单框之间的间距
    }

    // 绘制翻页按钮
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // 上一页
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // 下一页
    PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);
}

