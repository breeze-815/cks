#include <all_func.h>
#define MAX_COMBINED_ORDERS 20  /* 最多合并订单数 */
void accept_order() // 
{
    int page = 0; // 当前页码
    int clicked;
    int order_index;
    int total_cnt; // 订单总数
    OrderList OL = {0};
    FoodList FL = {0};
    DeliverList DL = {0};

    ReadAllDeliver(&DL); 
    ReadAllOrder(&OL); // 读取订单列表
    ReadAllFood(&FL); // 读取食品列表

    total_cnt = OL.length + FL.length + DL.length; // 计算订单总数
    mouse_off_arrow(&mouse);
	
	draw_accept_order(page,&OL,&FL,&DL,total_cnt); // 绘制接单页面

    
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
            draw_accept_order(page,&OL,&FL,&DL,total_cnt); // 重新绘制订单列表
            mouse_on_arrow(mouse);
        }
        else if (mouse_press(220, 700, 340, 750) == 1) // 上一页
		{
            if (page > 0) {
                page--;
                draw_accept_order(page,&OL,&FL,&DL,total_cnt); // 绘制用户订单页面
            } else {
                // 提示：已是第一页
                PrintCC(550, 35, "已是第一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 35, 700, 60, white);
            }
        }
        else if (mouse_press(420, 700, 540, 750) == 1)  // 下一页
		{
			if ((page + 1) * 5 < total_cnt) 
            {
				page++;
                draw_accept_order(page,&OL,&FL,&DL,total_cnt);
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
            draw_accept_order(page,&OL,&FL,&DL,total_cnt);// 重新绘制订单列表
            mouse_on_arrow(mouse);
		}
        else if(mouse_press(782, 50, 902, 100)==1) //账户
        {
            press3(3); //按钮高亮
        }
        else if(mouse_press(20, 150, 1000, 680) == 1) {  
            clicked = (mouse.y - 170) / 130;  
            /* 1) 先获取最新鼠标坐标 */
            MouseGet(&mouse);
    
            /* 2) 根据 y 坐标算出点击的是本页第几条（每条高 130px，从 y=170 开始） */
            
            if (clicked >= 0 && clicked < 4) {
                /* 3) 算出全局订单索引 */
                order_index = clicked + page * 4;
    
                /* 4) 跳转到订单详情页 */
                //ord_det(page, order_index, &OL, &FL);
    
                /* 5) 从详情页返回后，重绘接单列表 */
                mouse_off_arrow(&mouse);
                bar1(0, 150, 1024, 768, white);
                draw_accept_order(page,&OL,&FL,&DL,total_cnt);
                mouse_on_arrow(mouse);
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

// void draw_accept_order(int page, OrderList *OL, FoodList *FL)
// {
//     /* 所有变量声明放在最前面，兼容 C89/旧编译器 */
//     int       i, j;
//     int       total_cnt;
//     int       y_offset;
//     int       per_page;
//     int       base_idx, global_idx;
//     int       dist_m;
//     double    dist_km, fee;
//     char      buf1[32], buf2[32], buf3[32], buf4[32];
//     Order     order;
//     FoodOrder fo;

//     /*—— 初始化 ——*/
//     per_page  = 4;
//     total_cnt = OL->length + FL->length;
//     base_idx  = page * per_page;
//     y_offset  = 170;

//     /*—— 清屏 ——*/
//     bar1(0, 150, 1024, 768, white);

//     /*—— 循环绘制本页条目 ——*/
//     for (j = 0; j < per_page; j++) {
//         global_idx = base_idx + j;
//         if (global_idx >= total_cnt) break;

//         /* 绘制背景框 */
//         Draw_Rounded_Rectangle(20, y_offset,
//                                1000, y_offset + 100,
//                                30, 1, 0x6B4D);

//         if (global_idx < OL->length) {
//             /* —— 超市订单 —— */
//             order = OL->elem[global_idx];
//             sprintf(buf1, "取餐：%s", node[order.pick_up_location].name);
//             sprintf(buf2, "送达：%s", node[order.destination].name);
//             PrintText( 50, y_offset + 10, buf1, HEI, 24, 1, 0x0000);
//             PrintText( 50, y_offset + 60, buf2, HEI, 24, 1, 0x0000);
//             dist_m  = dijkstra(&node[order.pick_up_location],
//                                &node[order.destination], 3);
//             dist_km = dist_m / 1000.0;
//             sprintf(buf3, "距离：%.2fkm", dist_km);
//             PrintText(500, y_offset + 10, buf3, HEI, 24, 1, 0x0000);
//             fee = rider_deliver_price(dist_m, order.total_amount);
//             sprintf(buf4, "配送费：%.1f元", fee);
//             PrintText(500, y_offset + 60, buf4, HEI, 24, 1, 0x0000);
//         } else {
//             /* —— 食堂订单 —— */
//             fo = FL->elem[global_idx - OL->length];
//             sprintf(buf1, "取餐：%s", node[fo.pick_up_location].name);
//             sprintf(buf2, "送达：%s", node[fo.destination].name);
//             PrintText( 50, y_offset + 10, buf1, HEI, 24, 1, 0x0000);
//             PrintText( 50, y_offset + 60, buf2, HEI, 24, 1, 0x0000);
//             dist_m  = dijkstra(&node[fo.pick_up_location],
//                                &node[fo.destination], 3);
//             dist_km = dist_m / 1000.0;
//             sprintf(buf3, "距离：%.2fkm", dist_km);
//             PrintText(500, y_offset + 10, buf3, HEI, 24, 1, 0x0000);
//             fee = rider_deliver_price(dist_m, fo.total_amount);
//             sprintf(buf4, "配送费：%.1f元", fee);
//             PrintText(500, y_offset + 60, buf4, HEI, 24, 1, 0x0000);
//         }

//         y_offset += 130;
//     }

//     /*—— 绘制翻页按钮 ——*/
//     Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue);
//     Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue);
//     PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
//     PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);
// }


// void draw_accept_order(int page,OrderList *OL,FoodList *FL) // 绘制接单页面
// {
//     int i;
//     int cnt=0;
//     int y_offset = 170; // 初始Y轴偏移
//     // 每页最多显示4个订单
//     int start_index = page * 4; // 当前页的起始订单索引
//     int end_index = start_index + 4; // 当前页的结束订单索引
//     cnt = OL->length;  // 订单总数
    
//     if (end_index > cnt) 
//     {
//         end_index = cnt; // 防止越界
//     }

//     bar1(0, 150, 1024, 768,white);

//     for (i = start_index; i < end_index; i++) 
//     {
//         char show_pick_up[20]; // 取餐地点
//         char show_destination[20]; // 目的地
//         char show_distance[20]; // 距离
//         char show_deliver_price[20]; // 配送费用
//         int distance_m; // 距离
//         float distance_km; // 距离
//         float item_price;
//         double deliver_price;// 总价字符串

//         Order order = OL->elem[i]; // 获取当前订单
        
//         // 绘制订单框
//         Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

//         // 显示订单简略信息
//         sprintf(show_pick_up, "取货点：%s", node[order.pick_up_location].name);
//         PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, 0x0000);

//         sprintf(show_destination, "送货点：%s", node[order.destination].name);
//         PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, 0x0000);

//         distance_m = dijkstra(&node[order.pick_up_location], &node[order.destination],3); // 计算距离
//         distance_km = distance_m / 1000.0; // 转换为公里
//         sprintf(show_distance, "距离：%.2fkm", distance_km);
//         PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, 0x0000);

//         item_price = order.total_amount; // 获取商品价格
//         deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
//         sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
//         PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, 0x0000);
        

//         y_offset += 130; // 每个订单框之间的间距
//     }
//     // 绘制翻页按钮
//     Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // 上一页
//     Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // 下一页
//     PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
//     PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);   
// }

// void draw_accept_order(int page, OrderList *OL, FoodList *FL)
// {
//     /* 所有变量声明放在最前面，适应 C89/旧编译器 */
//     int          i, cnt;
//     int          y_offset;
//     int          per_page;
//     int          start, end;
//     int          dist_m;
//     double       dist_km, fee;
//     FoodOrder    combined[MAX_COMBINED_ORDERS];
//     char         buf1[32], buf2[32], buf3[32], buf4[32];
//     FoodOrder   *o;

//     /*—— 初始化 ——*/
//     cnt      = 0;
//     y_offset = 170;
//     per_page = 4;

//     /*—— 1) 合并超市订单 ——*/
//     for (i = 0; i < OL->length && cnt < MAX_COMBINED_ORDERS; i++) {
//         /* 使用 pick_up_location 字段记录取餐节点，不要覆盖 station */
//         combined[cnt].pick_up_location = OL->elem[i].pick_up_location;
//         combined[cnt].destination      = OL->elem[i].destination;
//         combined[cnt].total_amount     = OL->elem[i].total_amount;
//         strcpy(combined[cnt].user_name,  OL->elem[i].user_name);
//         strcpy(combined[cnt].order_time, OL->elem[i].order_time);
//         combined[cnt].station = 0;  /* 标记来源为超市，可根据需要保留 */
//         cnt++;
//     }

//     /*—— 2) 合并所有食堂订单 ——*/
//     for (i = 0; i < FL->length && cnt < MAX_COMBINED_ORDERS; i++) {
//         combined[cnt++] = FL->elem[i];
//     }

//     /*—— 3) 分页计算 ——*/
//     start = page * per_page;
//     end   = start + per_page;
//     if (start > cnt) start = cnt;
//     if (end   > cnt) end   = cnt;

//     /*—— 4) 清屏 ——*/
//     bar1(0, 150, 1024, 768, white);

//     /*—— 5) 绘制当前页订单 ——*/
//     for (i = start; i < end; i++) {
//         o = &combined[i];

//         /* 背景框 */
//         Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

//         /* 取送地址 */
//         sprintf(buf1, "取餐：%s", node[o->pick_up_location].name);
//         sprintf(buf2, "送达：%s", node[o->destination].name);
//         PrintText( 50, y_offset + 10, buf1, HEI, 24, 1, 0x0000);
//         PrintText( 50, y_offset + 60, buf2, HEI, 24, 1, 0x0000);

//         /* 计算并显示距离 */
//         dist_m  = dijkstra(&node[o->pick_up_location],
//                            &node[o->destination], 3);
//         dist_km = dist_m / 1000.0;
//         sprintf(buf3, "距离：%.2fkm", dist_km);
//         PrintText(500, y_offset + 10, buf3, HEI, 24, 1, 0x0000);

//         /* 计算并显示配送费 */
//         fee = rider_deliver_price(dist_m, o->total_amount);
//         sprintf(buf4, "配送费：%.1f元", fee);
//         PrintText(500, y_offset + 60, buf4, HEI, 24, 1, 0x0000);

//         y_offset += 130;
//     }

//     /*—— 6) 翻页按钮 ——*/
//     Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue);
//     Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue);
//     PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
//     PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);
// }

void draw_accept_order(int page, OrderList *OL, FoodList *FL, DeliverList *DL ,int total_cnt) // 绘制接单页面
{
    int i,j;
    int cnt = 0;
    int y_offset = 170; // 初始Y轴偏移
    FoodOrder food_order;
    //FoodOrder target_order[20]; // 用于存储目标订单

    int start_index = page * 4; // 当前页的起始订单索引
    int end_index = start_index + 4; // 当前页的结束订单索引

    if (end_index > total_cnt) 
        {
            end_index = total_cnt; // 防止越界
        }
    


    bar1(0, 150, 1024, 768, white); // 清空屏幕

    for (i = start_index; i < end_index; i++) {
        char order_id[10]; // 订单ID字符串
        char user_info[16]; // 用户信息字符串
        char total_price[10];// 总价字符串

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

        y_offset += 120; // 每个订单框之间的间距

        if (i >= OL->length) 
        {
            food_order = FL->elem[i - OL->length+1]; // 获取当前订单
                // target_order[j] = FL->elem[j]; // 获取目标订单
                // food_order = target_order[j];// 获取当前订单 
            //     if(FL->elem[i].station==1)//找到对应的订单
        	// {
        	// 	target_order[cnt]=FL->elem[i];
        	// 	cnt++;

        	// }   
                Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

                // 显示订单简略信息
                sprintf(show_pick_up, "取货点：%s", node[food_order.station].name);
                PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, 0x0000);

                sprintf(show_destination, "送货点：%s", node[food_order.destination].name);
                PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, 0x0000);

                distance_m = dijkstra(&node[food_order.station], &node[food_order.destination],3); // 计算距离
                distance_km = distance_m / 1000.0; // 转换为公里
                sprintf(show_distance, "距离：%.2fkm", distance_km);
                PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, 0x0000);

                item_price = food_order.total_amount; // 获取商品价格
                deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
                sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
                PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, 0x0000);
        



                // // 显示订单简略信息
                // sprintf(order_id, "订单%d", i + 1);
                // PrintText(235, y_offset + 15, order_id, HEI, 24, 1, 0x0000);

                // sprintf(user_info, "下单人：%s", food_order.user_name);
                // PrintText(235, y_offset + 65, user_info, HEI, 24, 1, 0x0000);

                
                // sprintf(total_price, "总价：%.2f", food_order.total_amount);
                // PrintText(800, y_offset + 15, total_price, HEI, 24, 1, 0x0000);

                // PrintText(665, y_offset + 65, food_order.order_time, HEI, 24, 1, 0x0000);

                y_offset += 120; // 每个订单框之间的间距
        }
    }
        // if (i >= FL->length + OL->length) {
        //     break; // 防止越界
        // }
    // 绘制翻页按钮
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // 上一页
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // 下一页
    PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);
}
// void draw_accept_order(int page, OrderList *OL, FoodList *FL, DeliverList *DL, int total_cnt) {
//     int y_offset = 170;
//     const int per_page = 4;
//     int start_index = page * per_page;
//     int end_index = start_index + per_page;
//     int i,fl_idx;
//     FoodOrder food_order;
//     bar1(0, 150, 1024, 768, white);

//     for (i = start_index; i < end_index && i < total_cnt; i++) {
//         char show_pick_up[32], show_destination[32], show_distance[32], show_deliver_price[32];
//         int distance_m;
//         float distance_km, deliver_price;

//         // 区分订单类型
//         if (i < OL->length) {
//             // ========== 超市订单处理 ==========
//             Order order = OL->elem[i];
//             sprintf(show_pick_up, "取货点：%s", node[order.pick_up_location].name);
//             sprintf(show_destination, "送货点：%s", node[order.destination].name);
//             distance_m = dijkstra(&node[order.pick_up_location], &node[order.destination], 3);
//         } else {
//             // ========== 食堂订单处理 ==========
//             fl_idx = i - OL->length;
//             if (fl_idx >= FL->length) break; // 防御越界
//             food_order = FL->elem[fl_idx];
//             sprintf(show_pick_up, "取货点：%s", node[food_order.pick_up_location].name);
//             sprintf(show_destination, "送货点：%s", node[food_order.destination].name);
//             distance_m = dijkstra(&node[food_order.pick_up_location], &node[food_order.destination], 3);
//         }

//         // ========== 统一绘制逻辑 ==========
//         distance_km = distance_m / 1000.0f;
//         deliver_price = rider_deliver_price(distance_m, 
//             (i < OL->length) ? OL->elem[i].total_amount : FL->elem[i - OL->length].total_amount
//         );

//         Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);
//         PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, 0x0000);
//         PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, 0x0000);
//         sprintf(show_distance, "距离：%.2fkm", distance_km);
//         PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, 0x0000);
//         sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
//         PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, 0x0000);

//         y_offset += 120;
//     }

//     // 翻页按钮绘制（略）
// }