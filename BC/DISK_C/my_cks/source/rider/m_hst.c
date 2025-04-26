#include <all_func.h>

#define MAX_ACCEPTED_ORDERS 4
#define ORDERS_PER_PAGE   4

#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

AcceptedOrder hst_orders[10]={0};

void my_history_order(int user_pos)
{   
    int page = 0;
    int type, local, global;
    mouse_off_arrow(&mouse);
    // OrderList OL = {0};
    // FoodList FL = {0};
    // DeliverList DL = {0};
    // ReadAllDeliver(&DL); // 读取快递列表
    // ReadAllOrder(&OL); // 读取订单列表
    // ReadAllFood(&FL); // 读取食品列表
    //total_cnt = OL.length + FL.length + DL.length;
    //draw_accept_order(page, &OL, &FL, &DL, total_cnt);
    draw_my_history_order();
    mouse_on_arrow(mouse);

    while (1) {
        mouse_show_arrow(&mouse);
        if(mouse_press(122, 50, 242, 100)==1) //返回
        {
            mouse_off_arrow(&mouse);
            // DestroyOList(&OL); // 释放订单列表内存
            // DestroyFList(&FL); // 释放食品列表内存
            // DestroyDList(&DL); // 释放快递列表内存
            return;
			//my_information;
		}
        else if(mouse_press(342, 50, 462, 100)==1)
        {
            press3(1);//进入接单界面
            mouse_off_arrow(&mouse);
            accept_order(user_pos);//接单页面
            //return后从这开始
            press3(3);
            press4(3);
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // 清除接单界面残留
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(562, 50, 682, 100)==1) //路线
        {
            press3(2); //按钮高亮
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // 清除接单界面残留
            route(cur_orders,num_of_orders.cur_count,user_pos);//骑手路线规划
            //return后从这开始
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_my_history_order(); // 重新绘制订单列表
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //我的
        {
            press3(3); //按钮高亮
            mouse_off_arrow(&mouse);
            my_information(user_pos);
            //return后从这开始
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_my_history_order(); // 重新绘制订单列表
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 276, 160, 326) == 1) //信息
        {
            press4(1);
            my_information(user_pos);
            //return后从这开始
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); //清屏
            draw_my_accept();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 439, 160, 489) == 1) //当前
        {
            press4(2);
            my_accept_order(user_pos);
            //return后从这开始
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 602, 160, 652) == 1) //历史
        {
            press4(3);
            my_history_order(user_pos);
            //return后从这开始
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(750, 195, 850, 245) == 1) //点击订单1详情
        {
            my_history_detail(0,user_pos);
            //return后从这开始
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            //bar1(0, 150, 200, 768, white); // 
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(750, 315, 850, 365)==1) //点击订单2详情
        {
            my_history_detail(1,user_pos);
            //return后从这开始
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            //bar1(0, 150, 200, 768, white); //
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(750, 435, 850, 485) == 1) //点击订单3详情
        {
            my_history_detail(2,user_pos);
            //return后从这开始
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            //bar1(0, 150, 200, 768, white); // 
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(750, 555, 850, 605) == 1) //点击订单4详情
        {
            my_history_detail(3,user_pos);
            //return后从这开始
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            //bar1(0, 150, 200, 768, white); // 
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
    }
}

void move_to_history(AcceptedOrder cur_orders[], int order_idx) 
{
    int j;
    if (num_of_orders.hst_count < 10 && num_of_orders.cur_count >= 0 && order_idx < num_of_orders.cur_count) \
    {
        // 复制到历史列表末尾
        hst_orders[num_of_orders.hst_count++] = cur_orders[order_idx];
        // 从 cur_orders 中移除：后续元素前移
        for ( j = order_idx; j < num_of_orders.cur_count - 1; j++) 
            cur_orders[j] = cur_orders[j + 1];
        num_of_orders.cur_count--;
    }
}

void draw_my_history_order()
{
    int y_offset = 170;
    char pick_up[100], dest[100], distance_str[50], price_str[50];
    int distance_m;
    float dist_km, amount, fee;
    int i;
    //char debg[20];
    bar1(200, 150, 1024, 768, white);
    //sprintf(debg,"%d",num_of_orders.hst_count);
    //PrintText(0,  0, debg, HEI, 24, 1, BLACK);
    if (num_of_orders.hst_count == 0)
    PrintCC(450,400,"当前无历史订单",HEI,32,1,Red);
    else
    {
        for (i = 0; i < num_of_orders.hst_count; i++) 
        {
            AcceptedOrder *ho = &hst_orders[i]; 
            // 画框
            Draw_Rounded_Rectangle(220, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);
    
            Fill_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, white);
            Draw_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, 1,deepblue);
            PrintCC(750+25, y_offset+35, "详情", HEI, 24, 1, deepblue);
    
            // // 取消按钮
            // Fill_Rounded_Rectangle(875, y_offset + 25, 975, y_offset + 75, 25, white);
            // Draw_Rounded_Rectangle(875, y_offset + 25, 975, y_offset + 75, 25, 1, deepblue);
            // PrintCC(900, y_offset + 35, "取消", HEI, 24, 1, deepblue);
            // 根据类型取数据
            switch (ho->type) {
                case ORDER_SUPERMARKET: {
                    int pu   = ho->data.order.pick_up_location;
                    int dst  = ho->data.order.destination;
                    amount   = ho->data.order.total_amount;
    
                    sprintf(pick_up, "取货点：%s", node[pu].name);
                    sprintf(dest,    "目的地：%s", node[dst].name);
                    distance_m = dijkstra(&node[pu], &node[dst], 3);
                    break;
                }
                case ORDER_FOOD: {
                    int pu   = ho->data.food.station;
                    int dst  = ho->data.food.destination;
                    amount   = ho->data.food.total_amount;
    
                    sprintf(pick_up, "取餐点：%s", node[pu].name);
                    sprintf(dest,    "目的地：%s", node[dst].name);
                    distance_m = dijkstra(&node[pu], &node[dst], 3);
                    break;
                }
                case ORDER_DELIVER: {
                    int pu   = ho->data.deliver.station+408;
                    int dst  = ho->data.deliver.index;
                    amount   = 2.0f;
                    sprintf(pick_up, "取货点：%s", node[pu].name);
                    sprintf(dest,    "目的地：%s", node[dst].name);
                    distance_m = dijkstra(&node[pu], &node[dst], 3);
                    break;
                }
                default:
                    continue;
            }
    
            // 计算并打印距离、费用
            dist_km = distance_m / 1000.0f;
            fee     = rider_deliver_price(distance_m, amount);
    
            PrintText(250,  y_offset + 10, pick_up, HEI, 24, 1, BLACK);
            PrintText(250,  y_offset + 60, dest,    HEI, 24, 1, BLACK);
            sprintf(distance_str, "距离：%.2fkm", dist_km);
            PrintText(500, y_offset + 10, distance_str, HEI, 24, 1, BLACK);
            sprintf(price_str,    "配送费：%.1f元", fee);
            PrintText(500, y_offset + 60, price_str,    HEI, 24, 1, BLACK);
            y_offset += 120;
        }
    }
    
}

void draw_my_history_detail_body(int type, int index)
{
    char buf[128];
    // 通用：下单时间、手机号
    char time_str[64];
    char phone_str[64];
    char show_distance[30];
    char show_deliver_price[30];
    int distance_m;
    float distance_km;
    float item_price;
    float deliver_price;
    
    if (type == ORDER_SUPERMARKET) 
    {
        sprintf(time_str, "下单时间：%s", hst_orders[index].data.order.order_time);
        sprintf(phone_str, "手机号：%s", hst_orders[index].data.order.user_phone);
        // 取货点
        sprintf(buf, "取货点：%s", node[hst_orders[index].data.order.pick_up_location].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // 用户地址
        sprintf(buf, "用户地址：%s", node[hst_orders[index].data.order.destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        // 距离
        distance_m = dijkstra(&node[hst_orders[index].data.order.pick_up_location], &node[hst_orders[index].data.order.destination],3); // 计算距离
        distance_km = distance_m / 1000.0; // 转换为公里
        sprintf(show_distance, "距离：%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, black);

        item_price = hst_orders[index].data.order.total_amount; // 获取商品价格
        deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
        hst_orders[index].deliver_price=deliver_price; //将此单配送费存进结构体中
        sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, black);

    }
    else if (type == ORDER_FOOD) 
    {
        
        sprintf(time_str, "下单时间：%s", hst_orders[index].data.food.order_time);
        sprintf(phone_str, "手机号：%s", hst_orders[index].data.food.user_phone);
        // 取餐点
        sprintf(buf, "取货点：%s", node[hst_orders[index].data.food.station].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // 用户地址
        sprintf(buf, "用户地址：%s", node[hst_orders[index].data.food.destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //距离
        distance_m = dijkstra(&node[hst_orders[index].data.food.station], &node[hst_orders[index].data.food.destination],3); // 计算距离
        distance_km = distance_m / 1000.0; // 转换为公里
        sprintf(show_distance, "距离：%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, black);

        item_price = hst_orders[index].data.order.total_amount; // 获取商品价格
        deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
        hst_orders[index].deliver_price=deliver_price;
        sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, black);
    }
    else if (type == ORDER_DELIVER) 
    {
        sprintf(time_str, "下单时间：%s", hst_orders[index].data.deliver.time);
        sprintf(phone_str, "手机号：%s", hst_orders[index].data.deliver.number);
        // 取货点
        sprintf(buf, "取货点：%s", node[hst_orders[index].data.deliver.station].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // 用户地址
        sprintf(buf, "用户地址：%s", node[hst_orders[index].data.deliver.destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //距离
        distance_m = dijkstra(&node[hst_orders[index].data.deliver.station], &node[hst_orders[index].data.deliver.destination],3); // 计算距离
        distance_km = distance_m / 1000.0; // 转换为公里
        sprintf(show_distance, "距离：%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, 0x0000);

        item_price = 2.0; // 获取商品价格
        deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
        hst_orders[index].deliver_price=deliver_price;
        sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, 0x0000);
    }
    // 打印通用字段（相对偏移）
    PrintText(200, 50  + 150, time_str, HEI, 24, 1, black);
    PrintText(200, 100 + 150, phone_str, HEI, 24, 1, black);
}

void my_history_detail(int index , int user_pos) 
{
    OrderList OL = {0};
    FoodList FL = {0};
    int page = 0;
    int totalPage = 1;
    
    int type;
    type=hst_orders[index].type;

    ReadAllOrder(&OL); // 读取订单列表
    ReadAllFood(&FL); // 读取食品列表

    // 计算总页数//第一页4个，第二页后面9个
    if (type == ORDER_SUPERMARKET) {
        totalPage = (OL.elem[index].itemCount - 4 + 8) / 9 + 1;
    } else if (type == ORDER_FOOD) {
        totalPage = (FL.elem[index].itemCount - 4 + 8) / 9 + 1;
    }
    // ORDER_DELIVER 保持 totalPage=0

    DestroyOList(&OL); // 释放快递列表内存
    DestroyFList(&FL); // 释放食品列表内存
    
    draw_my_history_detail(type, index,page);

    mouse_on_arrow(mouse);
    while (1) 
    {
        mouse_show_arrow(&mouse);
        // 返回按钮
        if(mouse_press(122, 50, 242, 100)==1) //返回
        {
            return;
			//my_accept_order(users.pos);
		}
        else if(mouse_press(562, 50, 682, 100)==1) //路线
        {
            press3(2); //按钮高亮
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); 
            route(cur_orders, num_of_orders.cur_count,user_pos);//骑手路线规划
            //return后从这开始
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); 
            draw_my_history_detail(type, index,page);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //我的
        {
            press3(3); //按钮高亮
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); 
            my_information(user_pos);
            //return后从这开始
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white);  
            draw_my_history_detail(type, index,page);
        }
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_my_history_detail(type, index,page);
            } else {
                // 提示：已是第一页
                PrintCC(630, 715, "已是第一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(630, 715, 780, 765, white);
            }
        }
		else if (mouse_press(420, 700, 540, 750) == 1) 
		{
			if (page < totalPage - 1) {
				page++;
				draw_my_history_detail(type, index,page);
			} else {
				// 提示：已是最后一页
				PrintCC(630, 715, "已是最后一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(630, 715, 780, 765, white);
			}
		}
        
    }
    
}


void draw_my_history_detail(int type,int index,int page) 
{
    int i;
    Order currentOrder ; 
    FoodOrder currentFood;
    Deliver currentDeliver;

    char current_time[100]; // 获取当前时间
    char time_str[100]; // 打印下单时间
    char user_name[100]; // 打印用户名
    char user_phone[100]; // 打印用户手机号
    char order_number; // 打印订单号
    char address[100]; // 打印用户地址
    int startIdx = 0;// 起始商品索引
    int itemsPerPage = 0;// 每页商品数量
    int endIdx = 0;// 结束商品索引
    int item_y = 0;// 商品框的y坐标

    float total_amount = 0.0; // 总金额
    char total_str[100]; // 总金额字符串
    int fullPageItemCount = 0; // 满页商品数量
    // 清屏
    bar1(0, 150, 1024, 768, white);

    currentOrder = hst_orders[index].data.order; // 当前订单
    currentFood = hst_orders[index].data.food; // 当前订单
    currentDeliver = hst_orders[index].data.deliver; // 当前快递 

    // 绘制主体部分
    

    // 分页按钮（超市和外卖类型）
    if (type != ORDER_DELIVER) {
        Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue);
        PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
        Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue);
        PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);
    }

    // 第一页绘制头部
    if(page==0&&type!=ORDER_DELIVER)
    {
        draw_my_history_detail_body(type, index);

        // 表头
        PrintCC(200, 400, "商品详情", HEI, 24, 1, black);
        PrintCC(650, 400, "数量", HEI, 24, 1, black);
        PrintCC(800, 400, "金额", HEI, 24, 1, black);
        PrintText(200, 420, "-------------------------------", HEI, 32, 1, black); 

        startIdx = 0;
        itemsPerPage = 4;//第一页4个，第二页后面9个
    }
    else if(page==0&&type==ORDER_DELIVER)
    {
        draw_my_history_detail_body(type, index);
    }
    else // 其他页
    {
        startIdx = 4 + (page - 1) * 9;
        itemsPerPage = 9;
    }

    endIdx = startIdx + itemsPerPage;

    if (type == ORDER_DELIVER) {
        // 只展示取件码
        char code_buf[64];
        sprintf(code_buf, "取件码：%s", currentDeliver.code);
        PrintText(200, 400, code_buf, HEI, 32, 1, black);
    } else {
        

        if (type == ORDER_SUPERMARKET)//超市订单
        {
            if (endIdx > currentOrder.itemCount)// 防止越界
                endIdx = currentOrder.itemCount;
        }
        else if(type==ORDER_FOOD)//食堂订单
        {
            if (endIdx > currentFood.itemCount)// 防止越界
                endIdx = currentFood.itemCount;
        }

        item_y = (page == 0) ? 450 : 200;
        for (i = startIdx; i < endIdx; i++) {
            char total_str[100]; // 商品总价
            char quantity_str[100]; // 商品数量

            if(type == ORDER_SUPERMARKET)//超市订单
            {
                int quantity = currentOrder.item[i].quantity; // 商品数量
                float price = currentOrder.item[i].price; // 商品价格

                sprintf(total_str, "%.2f", price * quantity);
                sprintf(quantity_str, "x%d", quantity);

                PrintCC(200, item_y, currentOrder.item[i].name, HEI, 24, 1, black); // 商品名
            }
            else if(type==ORDER_FOOD)//食堂订单
            {
                int quantity = currentFood.item[i].quantity; // 商品数量
                float price = currentFood.item[i].price; // 商品价格

                sprintf(total_str, "%.2f", price * quantity);
                sprintf(quantity_str, "x%d", quantity);

                PrintCC(200, item_y, currentFood.item[i].name, HEI, 24, 1, black); // 商品名
            }
            
            PrintText(650, item_y, (unsigned char*)quantity_str, HEI, 24, 1, black);// 商品数量
            PrintText(800, item_y, (unsigned char*)total_str, HEI, 24, 1, black);// 商品总价

            item_y += 50;
        }

        // 判断是否需要在此页显示总金额（当前页没有满）
        fullPageItemCount = (page == 0) ? 4 : 9;// 第一页显示4个商品，其余页显示9个商品

        if (type == ORDER_SUPERMARKET)
        {
            if ((endIdx - startIdx) < fullPageItemCount||endIdx==currentOrder.itemCount) {// 当前页商品数量不满一页或最后一个商品刚好满页都要打印出总金额
                //如果不是最后一个商品但是满页就不打印总金额
                // 打印分隔线
                PrintText(200, item_y - 30, "-------------------------------", HEI, 32, 1, black);
        
                // 计算总金额
                total_amount = 0.0;
                for (i = 0; i < currentOrder.itemCount; i++) {
                    int quantity = currentOrder.item[i].quantity; // 商品数量
                    float price = currentOrder.item[i].price; // 商品价格
                    total_amount += price * quantity;
                }
        
                sprintf(total_str, "总金额：%.2f 元", total_amount);
                PrintText(650, item_y + 10, total_str, HEI, 24, 1, black);
            
            }
        }
        else 
        {
            if ((endIdx - startIdx) < fullPageItemCount||endIdx==currentFood.itemCount) {// 当前页商品数量不满一页或最后一个商品刚好满页都要打印出总金额
                //如果不是最后一个商品但是满页就不打印总金额
                // 打印分隔线
                PrintText(200, item_y - 30, "-------------------------------", HEI, 32, 1, black);
        
                // 计算总金额
                total_amount = 0.0;
                for (i = 0; i < currentFood.itemCount; i++) {
                    int quantity = currentFood.item[i].quantity; // 商品数量
                    float price = currentFood.item[i].price; // 商品价格
                    total_amount += price * quantity;
                }
        
                sprintf(total_str, "总金额：%.2f 元", total_amount);
                PrintText(750, item_y + 10, total_str, HEI, 24, 1, black);
            
            }
        }
    }
}