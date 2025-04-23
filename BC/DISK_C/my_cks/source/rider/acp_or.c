#include  <all_func.h>

#define MAX_COMBINED_ORDERS 20
#define ORDERS_PER_PAGE   4

#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

void accept_order() // 
{
    int page = 0; // 当前页码
    int clicked;
    int order_index;
    int type=0, local_index=0, global_index=0;
    char debg[200];
    //int delivers.acp_count; // 订单总数
    //int acp_count=0; //接单总数
    OrderList OL = {0};
    FoodList FL = {0};
    DeliverList DL = {0};
    delivers.acp_count=0;
    ReadAllDeliver(&DL); // 读取快递列表
    ReadAllOrder(&OL); // 读取订单列表
    ReadAllFood(&FL); // 读取食品列表
    
    delivers.total_cnt = OL.length + FL.length + DL.length; // 计算订单总数
    mouse_off_arrow(&mouse);
	
	draw_accept_order(page,&OL,&FL,&DL); // 绘制接单页面

    // DestroyDList(&DL);
    // DestroyFList(&OL);
    // DestroyOList(&OL);

	mouse_on_arrow(mouse);
    
    // sprintf(debg,"OL=%d,FL=%d,DL=%d",OL.length,FL.length,DL.length);
    // PrintText(200, 50, debg, HEI, 24, 1, Red);
	while(1){
		mouse_show_arrow(&mouse);
    
		if(mouse_press(122, 50, 242, 100)==1) //返回
        {
            DestroyOList(&OL); // 释放订单列表内存
            DestroyFList(&FL); // 释放食品列表内存
            DestroyDList(&DL); // 释放快递列表内存
            return;
			//business(users.pos);
		}
        else if(mouse_press(562, 50, 682, 100)==1) //路线
        {
            press3(2); //按钮高亮
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // 清除接单界面残留
            route(acp_orders,delivers.acp_count);//骑手路线规划
            //return后从这开始
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_accept_order(page,&OL,&FL,&DL); // 重新绘制订单列表
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //我的
        {
            press3(3); //按钮高亮
            mouse_off_arrow(&mouse);
            my_accept_order();
            //return后从这开始
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_accept_order(page,&OL,&FL,&DL); // 重新绘制订单列表
            mouse_on_arrow(mouse);
        }
        else if (mouse_press(220, 700, 340, 750) == 1) // 上一页
		{
            if (page > 0) {
                page--;
                draw_accept_order(page,&OL,&FL,&DL); // 绘制用户订单页面
            } else {
                // 提示：已是第一页
                PrintCC(550, 700, "已是第一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 700, 700, 750, white);
            }
        }
        else if (mouse_press(420, 700, 540, 750) == 1)  // 下一页
		{
			if ((page + 1) * 5 < delivers.acp_count) 
            {
				page++;
                draw_accept_order(page,&OL,&FL,&DL);
			} 
            else {
				// 提示：已是最后一页
				PrintCC(550, 700, "已是最后一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 700, 700, 750, white);
			}
		}
        
        else if (mouse_press(750, 170 + 25, 850, 170 + 75) == 1) {
            global_index = page * ORDERS_PER_PAGE + 0;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            if (global_index < delivers.total_cnt) {
                if (global_index < OL.length) {
                    type = ORDER_SUPERMARKET; local_index = global_index;
                } else if (global_index < OL.length + FL.length) {
                    type = ORDER_FOOD; local_index = global_index - OL.length;
                } else {
                    type = ORDER_DELIVER; local_index = global_index - OL.length - FL.length;
                }
                accept_order_detail(local_index, type);
                bar1(0,150,1024,768,white); 
                draw_accept_order(page,&OL,&FL,&DL);
            }
        }
        // 第2条详情按钮：x[750,850], y[290+25,290+75]
        else if (mouse_press(750, 290 + 25, 850, 290 + 75) == 1) {
            global_index = page * ORDERS_PER_PAGE + 1;
            sprintf(debg,"acp_count=%d",delivers.acp_count);
            PrintText(100, 50, debg, HEI, 24, 1, Red);
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            if (global_index < delivers.total_cnt) {
                
                if (global_index < OL.length) {
                    type = ORDER_SUPERMARKET; local_index = global_index;
                } else if (global_index < OL.length + FL.length) {
                    type = ORDER_FOOD; local_index = global_index - OL.length;
                } else {
                    type = ORDER_DELIVER; local_index = global_index - OL.length - FL.length;
                }
                accept_order_detail(local_index, type);
                bar1(0,150,1024,768,white); 
                draw_accept_order(page,&OL,&FL,&DL);
            }
        }
        // 第3条详情按钮：x[750,850], y[410+25,410+75]
        else if (mouse_press(750, 410 + 25, 850, 410 + 75) == 1) {
            global_index = page * ORDERS_PER_PAGE + 2;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            if (global_index < delivers.total_cnt) {
                
                if (global_index < OL.length) {
                    type = ORDER_SUPERMARKET; local_index = global_index;
                } else if (global_index < OL.length + FL.length) {
                    type = ORDER_FOOD; local_index = global_index - OL.length;
                } else {
                    type = ORDER_DELIVER; local_index = global_index - OL.length - FL.length;
                }
                accept_order_detail(local_index, type);
                bar1(0,150,1024,768,white); 
                draw_accept_order(page,&OL,&FL,&DL);
            }
        }
        // 第4条详情按钮：x[750,850], y[530+25,530+75]
        else if (mouse_press(750, 530 + 25, 850, 530 + 75) == 1) {
            global_index = page * ORDERS_PER_PAGE + 3;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            if (global_index < delivers.total_cnt) {
                
                if (global_index < OL.length) {
                    type = ORDER_SUPERMARKET; local_index = global_index;
                } else if (global_index < OL.length + FL.length) {
                    type = ORDER_FOOD; local_index = global_index - OL.length;
                } else {
                    type = ORDER_DELIVER; local_index = global_index - OL.length - FL.length;
                }
                accept_order_detail(local_index, type);
                bar1(0,150,1024,768,white); draw_accept_order(page,&OL,&FL,&DL);
            }
        }
        // 接单按钮 #1：对应列表第 1 条
    else if (mouse_press(875, 170 + 25, 975, 170 + 75) == 1) {
            global_index = page * ORDERS_PER_PAGE + 0;
            // sprintf(debg,"global=%d",global_index);
            // PrintText(250, 50, debg, HEI, 24, 1, Red);
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            
            if ( delivers.acp_count == 4)
            { 
                PrintText(100, 100, "接单数量已达上限！", HEI, 24, 1, Red);
                delay(500);
                bar1(100,100,500,130,deepblue);
            }
            else
            {
                sprintf(debg,"OL=%d,FL=%d,DL=%d,gloidx=%d,locidx=%d,type=%d",OL.length,FL.length,DL.length,global_index,local_index,type);
                PrintText(350, 30,debg, HEI, 24, 1, Red);
                //PrintText(0, 0,"jinruelse", HEI, 24, 1, Red);
                rider_accept(&OL, &FL, &DL, type, local_index, page);
                bar1(0, 150, 1024, 768, white);
                sprintf(debg,"OL=%d,FL=%d,DL=%d,gloidx=%d,locidx=%d,type=%d",OL.length,FL.length,DL.length,global_index,local_index,type);
                PrintText(0, 0,debg, HEI, 24, 1, Red);
                draw_accept_order(page, &OL, &FL, &DL);
            }
           
        }
    // 接单按钮 #2：对应列表第 2 条
    else if (mouse_press(875, 290 + 25, 975, 290 + 75) == 1) {
            global_index = page * ORDERS_PER_PAGE + 1;
            //sprintf(debg,"global=%d",global_index);
            //PrintText(350, 50, debg, HEI, 24, 1, Red);
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            sprintf(debg,"OL=%d,FL=%d,DL=%d,gloidx=%d,locidx=%d,type=%d",OL.length,FL.length,DL.length,global_index,local_index,type);
            PrintText(350, 50, debg, HEI, 24, 1, Red);
            if (global_index < delivers.total_cnt) {
                if ( delivers.acp_count== 4)
                { 
                    PrintText(100, 100, "接单数量已达上限！", HEI, 24, 1, Red);
                    delay(500);
                    bar1(100,100,500,130,deepblue);
                }
                else
                {
                    rider_accept(&OL, &FL, &DL, type, local_index, page);
                    bar1(0, 150, 1024, 768, white);
                    draw_accept_order(page, &OL, &FL, &DL);
                }
               
            }
    }
    // 接单按钮 #3：对应列表第 3 条
    else if (mouse_press(875, 410 + 25, 975, 410 + 75) == 1) {
        global_index = page * ORDERS_PER_PAGE + 2;
        // sprintf(debg,"global=%d",global_index);
        //     PrintText(450, 50, debg, HEI, 24, 1, Red);
        get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
        sprintf(debg,"OL=%d,FL=%d,DL=%d,gloidx=%d,locidx=%d,type=%d",OL.length,FL.length,DL.length,global_index,local_index,type);
            PrintText(350, 70, debg, HEI, 24, 1, Red);
        if (global_index < delivers.total_cnt) {
            if ( delivers.acp_count== 4)
            { 
                PrintText(100, 100, "接单数量已达上限！", HEI, 24, 1, Red);
                delay(500);
                bar1(100,100,500,130,deepblue);
            }
            else
            {
                rider_accept(&OL, &FL, &DL, type, local_index, page);
                bar1(0, 150, 1024, 768, white);
                draw_accept_order(page, &OL, &FL, &DL);
            }
           
        }
    }
    // 接单按钮 #4：对应列表第 4 条
    else if (mouse_press(875, 530 + 25, 975, 530 + 75) == 1) {
        global_index = page * ORDERS_PER_PAGE + 3;
        get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
        if (global_index < delivers.total_cnt) {
            if ( delivers.acp_count== 4)
            { 
                PrintText(100, 100, "接单数量已达上限！", HEI, 24, 1, Red);
                delay(500);
                bar1(100,100,500,130,deepblue);
            }
            else
            {
                rider_accept(&OL, &FL, &DL, type, local_index, page);
                bar1(0, 150, 1024, 768, white);
                draw_accept_order(page, &OL, &FL, &DL);
            }
           
        }
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

void draw_accept_order(int page, OrderList *OL, FoodList *FL, DeliverList *DL) // 绘制接单页面
{
    int i,j;
    int cnt = 0;
    int y_offset = 170; // 初始Y轴偏移

    int start_index = page * 4; // 当前页的起始订单索引
    int end_index = start_index + 4; // 当前页的结束订单索引

    if (end_index > delivers.total_cnt) 
        {
            end_index = delivers.total_cnt; // 防止越界
        }
    
    bar1(0, 150, 1024, 768, white); // 清空屏幕

    // 绘制订单
    for (i = start_index; i < end_index; i++) {

        char show_pick_up[20]; // 取餐地点
        char show_destination[20]; // 目的地
        char show_distance[20]; // 距离
        char show_deliver_price[20]; // 配送费用

        int distance_m; // 距离
        float distance_km; // 距离
        float item_price;// 商品价格
        double deliver_price;// 

        if(i<OL->length)//先展示超市订单
        {
            Order order = OL->elem[i]; // 获取当前订单

            // 绘制订单框
            Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

            Fill_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, white);
            Draw_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, 1,deepblue);
            PrintCC(750+25, y_offset+30, "详情", HEI, 24, 1, deepblue);
            
            Fill_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, white);
            Draw_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, 1,deepblue);
            PrintCC(875+25, y_offset+30, "接单", HEI, 24, 1, deepblue);

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

            y_offset += 120; // 每个订单框之间的间距
        }
        else if (i >= OL->length && i < OL->length + FL->length) // 然后展示食堂订单
        {
            FoodOrder food_order = FL->elem[i - OL->length]; // 获取当前订单

            Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

            Fill_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, white);
            Draw_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, 1,deepblue);
            PrintCC(750+25, y_offset+30, "详情", HEI, 24, 1, deepblue);
            
            Fill_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, white);
            Draw_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, 1,deepblue);
            PrintCC(875+25, y_offset+30, "接单", HEI, 24, 1, deepblue);

            // 显示订单简略信息
            sprintf(show_pick_up, "取餐点：%s", node[food_order.station].name);
            PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, 0x0000);

            sprintf(show_destination, "取餐点：%s", node[food_order.destination].name);
            PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, 0x0000);

            distance_m = dijkstra(&node[food_order.station], &node[food_order.destination],3); // 计算距离
            distance_km = distance_m / 1000.0; // 转换为公里
            sprintf(show_distance, "距离：%.2fkm", distance_km);
            PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, 0x0000);

            item_price = food_order.total_amount; // 获取商品价格
            deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
            sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
            PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, 0x0000);

            y_offset += 120; // 每个订单框之间的间距
        }
        else if(i >= OL->length + FL->length)//最后展示快递代取订单
        {
            Deliver deliver = DL->elem[i - OL->length - FL->length]; // 获取当前订单

            Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

            Fill_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, white);
            Draw_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, 1,deepblue);
            PrintCC(750+25, y_offset+30, "详情", HEI, 24, 1, deepblue);
            
            Fill_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, white);
            Draw_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, 1,deepblue);
            PrintCC(875+25, y_offset+30, "接单", HEI, 24, 1, deepblue);
            // 显示订单简略信息
            sprintf(show_pick_up, "取货点：%s", node[deliver.station+408].name);
            PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, 0x0000);

            sprintf(show_destination, "送货点：%s", node[deliver.index].name);
            PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, 0x0000);

            distance_m = dijkstra(&node[deliver.station], &node[deliver.index],3); // 计算距离
            distance_km = distance_m / 1000.0; // 转换为公里
            sprintf(show_distance, "距离：%.2fkm", distance_km);
            PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, 0x0000);

            item_price = 2.0; // 获取商品价格
            deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
            sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
            PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, 0x0000);
            y_offset += 120; // 每个订单框之间的间距
        }
    }
    // 绘制翻页按钮
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // 上一页
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // 下一页
    PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);
} 


void get_ordtyp_locind(int global_index,
    int *type, int *local_index,
    const OrderList *OL, const FoodList *FL, const DeliverList *DL)
{
    if (global_index < OL->length) {
        *type = ORDER_SUPERMARKET;
        *local_index = global_index;
    } else if (global_index < OL->length + FL->length) {
        *type = ORDER_FOOD;
        *local_index = global_index - OL->length;
    } else if (global_index < OL->length + FL->length + DL->length) {
        *type = ORDER_DELIVER;
        *local_index = global_index - OL->length - FL->length;
    }
}

