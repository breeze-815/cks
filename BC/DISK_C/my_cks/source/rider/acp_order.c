#include <all_func.h>

void accept_order()
{
    int page = 0; // 当前页码

    OrderList OL = {0};
    FoodList FL = {0};

    ReadAllOrder(&OL); // 读取订单列表
    ReadAllFood(&FL); // 读取食品列表

    mouse_off_arrow(&mouse);
	
	draw_accept_order(page,&OL,&FL);

    
	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);
    
		if(mouse_press(122, 50, 242, 100)==1) //返回
        {
            DestroyOList(&OL); // 释放订单列表内存
            DestroyFList(&FL); // 释放食品列表内存
            return;
			//business(users.pos);
		}
        else if(mouse_press(562, 50, 682, 100)==1) //路线
        {
            press3(2); //按钮高亮
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // 清除接单界面残留
            route(acp_orders,4);//骑手路线规划
            //return后从这开始
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_accept_order(page,&OL,&FL);
            mouse_on_arrow(mouse);
        }
        else if (mouse_press(220, 700, 340, 750) == 1) // 上一页
		{
            if (page > 0) {
                page--;
                draw_accept_order(page,&OL,&FL); // 绘制用户订单页面
            } else {
                // 提示：已是第一页
                PrintCC(550, 35, "已是第一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 35, 700, 60, white);
            }
        }
        else if (mouse_press(420, 700, 540, 750) == 1)  // 下一页
		{
			if ((page + 1) * 5 < OL.length) 
            {
				page++;
                draw_accept_order(page,&OL,&FL);
			} 
            else {
				// 提示：已是最后一页
				PrintCC(550, 35, "已是最后一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 35, 700, 60, white);
			}
		}
        else if(mouse_press(0, 150, 1024, 680) == 1) {

            //int order_index = (mouse.y - 25) / 120 + page * 5; // 根据点击位置计算订单索引
            //这个order_index是基于展示的页面计算的索引，如果是food,就是target里的索引，因为是从target中展示的
            //order_index对二者都适用
            //传入index是为了区分超市和不同食堂，如果是食堂就要用target来展示
			MouseGet(&mouse);
            //business_detail(order_index,index); // 显示订单详情

            //return后从这开始
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // 清除订单详情界面残留
            draw_accept_order(page,&OL,&FL); // 重新绘制订单列表
            mouse_on_arrow(mouse);
		}
        else if(mouse_press(782, 50, 902, 100)==1) //账户
        {
            press3(3); //按钮高亮
        }
    }
}

double rider_deliver_price(int distance_m, float order_amount) 
{
    const double price_per_km   = 0.5;   // 每公里配送费（元）
    const double base_price     = 2.0;   // 起步价（元）
    const double price_ratio    = 0.05;  // 商品金额 5% 加价

    // 米 → 公里，用浮点运算
    double dist_km = (double)distance_m / 1000.0;

    // 计算总费
    double total = base_price
                 + dist_km * price_per_km
                 + order_amount * price_ratio;

    return total;
}

void draw_accept_order(int page,OrderList *OL,FoodList *FL) // 绘制接单页面
{
    int i;
    int cnt=0;
    int y_offset = 170; // 初始Y轴偏移
    // 每页最多显示4个订单
    int start_index = page * 4; // 当前页的起始订单索引
    int end_index = start_index + 4; // 当前页的结束订单索引
    cnt = OL->length;  // 订单总数
    
    if (end_index > cnt) 
    {
        end_index = cnt; // 防止越界
    }

    bar1(0, 150, 1024, 768,white);

    for (i = start_index; i < end_index; i++) 
    {
        char show_pick_up[20]; // 取餐地点
        char show_destination[20]; // 目的地
        char show_distance[20]; // 距离
        char show_deliver_price[20]; // 配送费用
        int distance_m; // 距离
        float distance_km; // 距离
        float item_price;
        double deliver_price;// 总价字符串

        Order order = OL->elem[i]; // 获取当前订单
        
        // 绘制订单框
        Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

        // 显示订单简略信息
        sprintf(show_pick_up, "取货点：%s", node[order.pick_up_location].name);
        PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, 0x0000);

        sprintf(show_destination, "送货点：%s", node[order.destination].name);
        PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, 0x0000);

        distance_m = dijkstra(&node[order.pick_up_location], &node[order.destination],3); // 计算距离
        distance_km = distance_m / 1000.0; // 转换为公里
        sprintf(show_distance, "距离：%.2fkm", distance_km);
        PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, 0x0000);

        item_price = order.total_amount; // 获取商品价格
        deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
        sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
        PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, 0x0000);
        

        y_offset += 130; // 每个订单框之间的间距
    }
    // 绘制翻页按钮
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // 上一页
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // 下一页
    PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);   
}