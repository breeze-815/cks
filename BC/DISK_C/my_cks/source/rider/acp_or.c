#include  <all_func.h>

#define ORDERS_PER_PAGE   4
#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

void accept_order(int user_pos) // 接单界面
{
    int page = 0; // 当前页码
    int clicked;
    int type=0, local_index=0, global_index=0; //type为订单种类，超市为0，外卖为1，代取为2；local_index为各订单在当前种类中的序号；global_index为各订单在所有订单中的序号
    //char debg[20];
    OrderList OL = {0}; //创建超市，外卖，订单线性空表，便于读取
    FoodList FL = {0};
    DeliverList DL = {0};
    ReadAllOrder(&OL); // 读取订单列表
    ReadAllFood(&FL); // 读取食品列表
    ReadAllDeliver(&DL); // 读取快递列表
    mouse_off_arrow(&mouse);
    num_of_orders.total_cnt = OL.length + FL.length + DL.length; // 计算订单总数
	draw_accept_order(page,&OL,&FL,&DL); // 绘制接单页面
	mouse_on_arrow(mouse);
    //sprintf(debg,"%d",num_of_orders.cur_count);
    //PrintText(1,1,debg,HEI,32,1,black);
	while(1)
    {
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
            DestroyOList(&OL); // 释放订单列表内存
            DestroyFList(&FL); // 释放食品列表内存
            DestroyDList(&DL); // 释放快递列表内存
            route(cur_orders,num_of_orders.cur_count,user_pos); //进入路线界面
            //return后从这开始
            mouse_on_arrow(mouse);
            ReadAllOrder(&OL); // 读取订单列表
            ReadAllFood(&FL); // 读取食品列表
            ReadAllDeliver(&DL); // 读取快递列表
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_accept_order(page,&OL,&FL,&DL); // 重新绘制接单界面
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //我的
        {
            press3(3); //按钮高亮
            mouse_off_arrow(&mouse);
            my_information(user_pos);
            DestroyOList(&OL); // 释放订单列表内存
            DestroyFList(&FL); // 释放食品列表内存
            DestroyDList(&DL); // 释放快递列表内存
            //return后从这开始
            ReadAllOrder(&OL); // 读取订单列表
            ReadAllFood(&FL); // 读取食品列表
            ReadAllDeliver(&DL); // 读取快递列表
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_accept_order(page,&OL,&FL,&DL); // 重新绘制接单界面
            mouse_on_arrow(mouse);
        }
        else if (mouse_press(220, 700, 340, 750) == 1) // 上一页
		{
            if (page > 0) //判断是否能上一页
            {
                page--;
                draw_accept_order(page,&OL,&FL,&DL); // 绘制用户订单页面
            } 
            else // 打印提示
            {
                PrintCC(550, 700, "已是第一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 700, 700, 750, white); //覆盖打印字样
            }
        }
        else if (mouse_press(420, 700, 540, 750) == 1)  // 下一页
		{
			if ((page + 1) * 4 < num_of_orders.total_cnt)  //判断能否下一页
            {
				page++;
                draw_accept_order(page,&OL,&FL,&DL); // 绘制用户订单页面
			} 
            else // 打印提示
            {
				PrintCC(550, 700, "已是最后一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 700, 700, 750, white);
			}
		}
        else if (mouse_press(750, 170 + 25, 850, 170 + 75) == 1) //点击页面第一个订单详情按钮的位置
        {
            global_index = page * ORDERS_PER_PAGE + 0; //计算全局索引
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL); //由全局索引计算订单类型和内部索引
            if (global_index < num_of_orders.total_cnt) //防止越界
            {
                DestroyOList(&OL); // 释放订单列表内存
                DestroyFList(&FL); // 释放食品列表内存
                DestroyDList(&DL); // 释放快递列表内存
                show_order_detail(local_index, type, user_pos); //进入订单详情页
                //return后从这返回
                ReadAllOrder(&OL); // 读取订单列表
                ReadAllFood(&FL); // 读取食品列表
                ReadAllDeliver(&DL); // 读取快递列表
                bar1(0,150,1024,768,white); //清楚订单详情页残留
                draw_accept_order(page,&OL,&FL,&DL); //画订单展示页
            }
        }
        else if (mouse_press(750, 290 + 25, 850, 290 + 75) == 1) //点击页面第二个订单详情按钮的位置
        {
            global_index = page * ORDERS_PER_PAGE + 1;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            if (global_index < num_of_orders.total_cnt) 
            {
                DestroyOList(&OL); // 释放订单列表内存
                DestroyFList(&FL); // 释放食品列表内存
                DestroyDList(&DL); // 释放快递列表内存
                show_order_detail(local_index, type, user_pos);
                //return后从这返回
                ReadAllOrder(&OL); // 读取订单列表
                ReadAllFood(&FL); // 读取食品列表
                ReadAllDeliver(&DL); // 读取快递列表
                bar1(0,150,1024,768,white); 
                draw_accept_order(page,&OL,&FL,&DL);
            }
        }
        else if (mouse_press(750, 410 + 25, 850, 410 + 75) == 1) //点击页面第三个订单详情按钮的位置
        {
            global_index = page * ORDERS_PER_PAGE + 2;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            if (global_index < num_of_orders.total_cnt) 
            {
                DestroyOList(&OL); // 释放订单列表内存
                DestroyFList(&FL); // 释放食品列表内存
                DestroyDList(&DL); // 释放快递列表内存
                show_order_detail(local_index, type, user_pos);
                //return后从这返回
                ReadAllOrder(&OL); // 读取订单列表
                ReadAllFood(&FL); // 读取食品列表
                ReadAllDeliver(&DL); // 读取快递列表
                bar1(0,150,1024,768,white); 
                draw_accept_order(page,&OL,&FL,&DL);
            }
        }
        else if (mouse_press(750, 530 + 25, 850, 530 + 75) == 1) //点击页面第四个订单详情按钮的位置
        {
            global_index = page * ORDERS_PER_PAGE + 3;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            if (global_index < num_of_orders.total_cnt) 
            {
                DestroyOList(&OL); // 释放订单列表内存
                DestroyFList(&FL); // 释放食品列表内存
                DestroyDList(&DL); // 释放快递列表内存
                show_order_detail(local_index, type, user_pos);
                //return后从这返回
                ReadAllOrder(&OL); // 读取订单列表
                ReadAllFood(&FL); // 读取食品列表
                ReadAllDeliver(&DL); // 读取快递列表
                bar1(0,150,1024,768,white); 
                draw_accept_order(page,&OL,&FL,&DL);
            }
        }
        else if (mouse_press(875, 170 + 25, 975, 170 + 75) == 1) //点击页面第一个订单接单按钮的位置
        {
            global_index = page * ORDERS_PER_PAGE + 0;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            
            if (num_of_orders.cur_count == 4)
            { 
                //打印提示
                PrintText(100, 100, "接单数量已达上限！", HEI, 24, 1, Red);
                delay(500);
                bar1(100,100,500,130,deepblue);
            }
            else
            {
                add_my_accept(&OL, &FL, &DL, type, local_index); //加入接单列表
                //重画订单展示列表
                bar1(0, 150, 1024, 768, white);
                draw_accept_order(page, &OL, &FL, &DL);
            }
        }
        else if (mouse_press(875, 290 + 25, 975, 290 + 75) == 1) //点击页面第二个订单接单按钮的位置
        {
            global_index = page * ORDERS_PER_PAGE + 1;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            if (global_index < num_of_orders.total_cnt) 
            {
                if ( num_of_orders.cur_count== 4)
                { 
                    PrintText(100, 100, "接单数量已达上限！", HEI, 24, 1, Red);
                    delay(500);
                    bar1(100,100,500,130,deepblue);
                }
                else
                {
                    add_my_accept(&OL, &FL, &DL, type, local_index);
                    //重画订单展示列表
                    bar1(0, 150, 1024, 768, white);
                    draw_accept_order(page, &OL, &FL, &DL);
                }
            }
        }
        else if (mouse_press(875, 410 + 25, 975, 410 + 75) == 1) //点击页面第三个订单接单按钮的位置
        {
            global_index = page * ORDERS_PER_PAGE + 2;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
        if (global_index < num_of_orders.total_cnt) 
        {
            if ( num_of_orders.cur_count== 4)
            { 
                PrintText(100, 100, "接单数量已达上限！", HEI, 24, 1, Red);
                delay(500);
                bar1(100,100,500,130,deepblue);
            }
            else
            {
                add_my_accept(&OL, &FL, &DL, type, local_index);
                bar1(0, 150, 1024, 768, white);
                draw_accept_order(page, &OL, &FL, &DL);
            }
        }
    }
        else if (mouse_press(875, 530 + 25, 975, 530 + 75) == 1) //点击页面第四个订单接单按钮的位置
        {
            global_index = page * ORDERS_PER_PAGE + 3;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            if (global_index < num_of_orders.total_cnt) 
            {
                if ( num_of_orders.cur_count== 4)
                { 
                    PrintText(100, 100, "接单数量已达上限！", HEI, 24, 1, Red);
                    delay(500);
                    bar1(100,100,500,130,deepblue);
                }
                else
                {
                    add_my_accept(&OL, &FL, &DL, type, local_index);
                    //重画订单展示列表
                    bar1(0, 150, 1024, 768, white);
                    draw_accept_order(page, &OL, &FL, &DL);
                }
            
            }
        }
    }
}
    
double rider_deliver_price(int distance_m, float order_amount) //计算配送费
{
    const double price_per_km   = 0.5;   // 每公里配送费（元）
    const double base_price     = 2.0;   // 起步价（元）
    const double price_ratio    = 0.05;  // 商品金额 5% 加价

    double dist_km = (double)distance_m / 1000.0; //单位换算
    double total = base_price + dist_km * price_per_km + order_amount * price_ratio;// 计算总费
    return total;
}

void draw_accept_order(int page, OrderList *OL, FoodList *FL, DeliverList *DL) // 绘制接单页面
{
    int i,j;
    int y_offset = 170; // 初始Y轴偏移
    int start_index = page * 4; // 当前页的起始订单索引
    int end_index = start_index + 4; // 当前页的结束订单索引
    char debg[20];
    if (end_index > num_of_orders.total_cnt) 
        end_index = num_of_orders.total_cnt; // 防止越界
    
    bar1(0, 150, 1024, 768, white); // 清空屏幕
    sprintf(debg,"%d",num_of_orders.total_cnt);
    PrintText(0,0,debg,HEI,36,1,Red);
    
    if(num_of_orders.total_cnt==0)
    PrintCC(400,400,"当前无可接订单",HEI,36,1,Red);
    else
    {
        // 绘制订单
        for (i = start_index; i < end_index; i++) 
        {
            char show_pick_up[20]; // 取餐地点
            char show_destination[20]; // 目的地
            char show_distance[20]; // 距离
            char show_deliver_price[20]; // 配送费用
            int distance_m; // 距离
            float distance_km; // 距离
            float item_price;// 商品价格
            double deliver_price;//配送费

            if(i < OL->length) //先展示超市订单
            {
                //char debg[20];
                Order order = OL->elem[i]; // 获取当前订单
                //绘制订单框
                // sprintf(debg,"%d",i);
                // PrintText(0,0,debg,HEI,24,1,black);
                // sprintf(debg,"%d",order.pick_up_location);
                // PrintText(0,50,debg,HEI,32,1,black);
                Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, deepgrey);
                //绘制详情按钮
                Fill_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, white);
                Draw_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, 1,deepblue);
                PrintCC(750+25, y_offset+30, "详情", HEI, 24, 1, deepblue);
                //绘制接单按钮
                Fill_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, white);
                Draw_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, 1,deepblue);
                PrintCC(875+25, y_offset+30, "接单", HEI, 24, 1, deepblue);
                // 显示订单简略信息
                sprintf(show_pick_up, "取货点：%s", node[order.pick_up_location].name); //展示取货点
                PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, black);

                sprintf(show_destination, "送货点：%s", node[order.destination].name); //展示送货点
                PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, black);

                distance_m = dijkstra(&node[order.pick_up_location], &node[order.destination],3); // 计算距离
                distance_km = distance_m / 1000.0; // 转换为公里
                sprintf(show_distance, "距离：%.2fkm", distance_km); //展示距离
                PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, black);

                item_price = order.total_amount; // 获取商品价格
                deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
                sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
                PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, black);

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

                sprintf(show_pick_up, "取餐点：%s", node[food_order.station].name);
                PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, black);

                sprintf(show_destination, "送餐点：%s", node[food_order.destination].name);
                PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, black);

                distance_m = dijkstra(&node[food_order.station], &node[food_order.destination],3); 
                distance_km = distance_m / 1000.0; 
                sprintf(show_distance, "距离：%.2fkm", distance_km);
                PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, black);

                item_price = food_order.total_amount; 
                deliver_price = rider_deliver_price(distance_m, item_price); 
                sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
                PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, black);

                y_offset += 120; // 每个订单框之间的间距
            }
            else if(i >= OL->length + FL->length)//最后展示快递代取订单
            {
                Deliver deliver = DL->elem[i - OL->length - FL->length]; 

                Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

                Fill_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, white);
                Draw_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, 1,deepblue);
                PrintCC(750+25, y_offset+30, "详情", HEI, 24, 1, deepblue);
                
                Fill_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, white);
                Draw_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, 1,deepblue);
                PrintCC(875+25, y_offset+30, "接单", HEI, 24, 1, deepblue);
                
                sprintf(show_pick_up, "取货点：%s", node[deliver.station+408].name);
                PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, black);

                sprintf(show_destination, "送货点：%s", node[deliver.index].name);
                PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, black);

                distance_m = dijkstra(&node[deliver.station], &node[deliver.index],3); 
                distance_km = distance_m / 1000.0; 
                sprintf(show_distance, "距离：%.2fkm", distance_km);
                PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, black);

                item_price = 2.0; 
                deliver_price = rider_deliver_price(distance_m, item_price); 
                sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
                PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, black);

                y_offset += 120; 
            }
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
    const OrderList *OL, const FoodList *FL, const DeliverList *DL) //基于先显示超市订单，再显示外卖订单，最后显示代取订单，由总索引计算订单类型和本地索引
{
    if (global_index < OL->length) //全局索引小于超市订单数，则为超市订单 
    {
        *type = ORDER_SUPERMARKET;
        *local_index = global_index;
    } 
    else if (global_index < OL->length + FL->length) //全局索引小于超市加外卖订单，则为外卖订单
    {
        *type = ORDER_FOOD;
        *local_index = global_index - OL->length; //本地索引由总索引减去超市订单数
    } 
    else if (global_index < OL->length + FL->length + DL->length) //剩余的为代取订单
    {
        *type = ORDER_DELIVER;
        *local_index = global_index - OL->length - FL->length; //本地索引由总索引减去超市订单数和外卖订单数
    }
}


