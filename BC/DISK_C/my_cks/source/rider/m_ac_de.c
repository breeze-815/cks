#include "all_func.h"

#define ORDERS_PER_PAGE   4     
#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

void draw_my_order_detail_body(int type, int index)
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
        sprintf(time_str, "下单时间：%s", cur_orders[index].data.order.order_time);
        sprintf(phone_str, "手机号：%s", cur_orders[index].data.order.user_phone);
        // 取货点
        sprintf(buf, "取货点：%s", node[cur_orders[index].data.order.pick_up_location].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // 用户地址
        sprintf(buf, "用户地址：%s", node[cur_orders[index].data.order.destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        // 距离
        distance_m = dijkstra(&node[cur_orders[index].data.order.pick_up_location], &node[cur_orders[index].data.order.destination],3); // 计算距离
        distance_km = distance_m / 1000.0; // 转换为公里
        sprintf(show_distance, "距离：%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, black);

        item_price = cur_orders[index].data.order.total_amount; // 获取商品价格
        deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
        cur_orders[index].deliver_price=deliver_price; //将此单配送费存进结构体中
        sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, black);

    }
    else if (type == ORDER_FOOD) 
    {
        
        sprintf(time_str, "下单时间：%s", cur_orders[index].data.food.order_time);
        sprintf(phone_str, "手机号：%s", cur_orders[index].data.food.user_phone);
        // 取餐点
        sprintf(buf, "取货点：%s", node[cur_orders[index].data.food.pick_up_location].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // 用户地址
        sprintf(buf, "用户地址：%s", node[cur_orders[index].data.food.destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //距离
        distance_m = dijkstra(&node[cur_orders[index].data.food.pick_up_location], &node[cur_orders[index].data.food.destination],3); // 计算距离
        distance_km = distance_m / 1000.0; // 转换为公里
        sprintf(show_distance, "距离：%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, black);

        item_price = cur_orders[index].data.order.total_amount; // 获取商品价格
        deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
        cur_orders[index].deliver_price=deliver_price;
        sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, black);
    }
    else if (type == ORDER_DELIVER) 
    {
        sprintf(time_str, "下单时间：%s", cur_orders[index].data.deliver.time);
        sprintf(phone_str, "手机号：%s", cur_orders[index].data.deliver.number);
        // 取货点
        sprintf(buf, "取货点：%s", node[cur_orders[index].data.deliver.station].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // 用户地址
        sprintf(buf, "用户地址：%s", node[cur_orders[index].data.deliver.destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //距离
        distance_m = dijkstra(&node[cur_orders[index].data.deliver.station], &node[cur_orders[index].data.deliver.destination],3); // 计算距离
        distance_km = distance_m / 1000.0; // 转换为公里
        sprintf(show_distance, "距离：%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, 0x0000);

        item_price = 2.0; // 获取商品价格
        deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
        cur_orders[index].deliver_price=deliver_price;
        sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, 0x0000);
    }
    // 打印通用字段（相对偏移）
    PrintText(200, 50  + 150, time_str, HEI, 24, 1, black);
    PrintText(200, 100 + 150, phone_str, HEI, 24, 1, black);
}


//未改
//详情页面中展示订单具体内容，只有超市和外卖订单有
// void draw_my_order_items(int type, int index)
// {
//     int i;
//     int page=0;
//     int start;
//     int end; 
//     int y = 500;  // 纵坐标初始偏移量
//     char name_buf[64], qty_buf[32], price_buf[32];
    
//     start = page * ORDERS_PER_PAGE;
//     end = start + ORDERS_PER_PAGE;
//     if (type == ORDER_SUPERMARKET) 
//     {
//         Order *o = &OL->elem[local_index];
        
//         if (end > o->itemCount) //防止越界
//         end = o->itemCount;
//         for (i = start; i < end; i++) {
//             sprintf(name_buf, "%s", o->item[i].name);
//             sprintf(qty_buf, "x%d", o->item[i].quantity);
//             sprintf(price_buf, "%.2f", o->item[i].price * o->item[i].quantity);
//             PrintText(250, y, name_buf, HEI, 24, 1, black);
//             PrintText(750, y, qty_buf, HEI, 24, 1, black);
//             PrintText(900, y, price_buf, HEI, 24, 1, black);
//             y += 50;
//         }
//     }
//     else if (type == ORDER_FOOD) {
//         FoodOrder *f = &FL->elem[local_index];
//         end = start + ORDERS_PER_PAGE;
//         if (end > f->itemCount) 
//         end = f->itemCount;
//         for (i = start; i < end; i++) {
//             sprintf(name_buf, "%s", f->item[i].name);
//             sprintf(qty_buf, "x%d", f->item[i].quantity);
//             sprintf(price_buf, "%.2f", f->item[i].price * f->item[i].quantity);
//             PrintText(250, y, name_buf, HEI, 24, 1, black);
//             PrintText(750, y, qty_buf, HEI, 24, 1, black);
//             PrintText(900, y, price_buf, HEI, 24, 1, black);
//             y += 50;
//         }
//     }
// }

void my_accept_detail(int index , int user_pos) 
{
    OrderList OL = {0};
    FoodList FL = {0};
    int page = 0;
    int totalPage = 1;
    
    int type;
    type=cur_orders[index].type;

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
    
    draw_my_order_detail(type, index,page);

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
            draw_my_order_detail(type, index,page);
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
            draw_my_order_detail(type, index,page);
        }
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_my_order_detail(type, index,page);
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
				draw_my_order_detail(type, index,page);
			} else {
				// 提示：已是最后一页
				PrintCC(630, 715, "已是最后一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(630, 715, 780, 765, white);
			}
		}
        
    }
}

void draw_my_order_detail(int type,int index,int page) 
{
    int i;
    Order currentOrder ; 
    FoodOrder currentFood;
    Deliver currentDeliver;
    OrderList OL;
    FoodList FL;
    DeliverList DL;

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

    ReadAllOrder(&OL); // 读取订单列表
    ReadAllFood(&FL); // 读取食品列表
    ReadAllDeliver(&DL); // 读取快递列表
    currentOrder = OL.elem[index]; // 当前订单
    currentFood = FL.elem[index]; // 当前订单
    currentDeliver = DL.elem[index]; // 当前快递
    DestroyOList(&OL); // 释放快递列表内存
    DestroyFList(&FL); // 释放食品列表内存
    DestroyDList(&DL); // 释放快递列表内存

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
        draw_my_order_detail_body(type, index);

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
        draw_my_order_detail_body(type, index);
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




