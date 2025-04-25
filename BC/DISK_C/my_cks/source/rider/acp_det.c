#include "all_func.h"

#define ORDERS_PER_PAGE   4     
#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

void draw_order_detail_header(int type, int local_index,OrderList *OL, FoodList *FL, DeliverList *DL) 
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
        Order *o = &OL->elem[local_index]; 
        sprintf(time_str, "下单时间：%s", o->order_time);
        sprintf(phone_str, "手机号：%s", o->user_phone);
        // 取货点
        sprintf(buf, "取货点：%s", node[o->pick_up_location].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // 用户地址
        sprintf(buf, "用户地址：%s", node[o->destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        // 距离
        distance_m = dijkstra(&node[o->pick_up_location], &node[o->destination],3); // 计算距离
        distance_km = distance_m / 1000.0; // 转换为公里
        sprintf(show_distance, "距离：%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, 0x0000);

        item_price = o->total_amount; // 获取商品价格
        deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
        sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, 0x0000);

    }
    else if (type == ORDER_FOOD) 
    {
        FoodOrder *f = &FL->elem[local_index];
        sprintf(time_str, "下单时间：%s", f->order_time);
        sprintf(phone_str, "手机号：%s", f->user_phone);
        // 取餐点
        sprintf(buf, "取货点：%s", node[f->station].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // 用户地址
        sprintf(buf, "用户地址：%s", node[f->destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //距离
        distance_m = dijkstra(&node[f->station], &node[f->destination],3); // 计算距离
        distance_km = distance_m / 1000.0; // 转换为公里
        sprintf(show_distance, "距离：%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, 0x0000);

        item_price = f->total_amount; // 获取商品价格
        deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
        sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, 0x0000);
    }
    else if (type == ORDER_DELIVER) 
    {
        Deliver *d = &DL->elem[local_index];
        sprintf(time_str, "下单时间：%s", d->time);
        sprintf(phone_str, "手机号：%s", d->number);
        // 取货点
        sprintf(buf, "取货点：%s", node[d->station].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // 用户地址
        sprintf(buf, "用户地址：%s", node[d->index].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //距离
        distance_m = dijkstra(&node[d->station], &node[d->index],3); // 计算距离
        distance_km = distance_m / 1000.0; // 转换为公里
        sprintf(show_distance, "距离：%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, 0x0000);

        item_price = 2.0; // 获取商品价格
        deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
        sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, 0x0000);
    }
    // 打印通用字段（相对偏移）
    PrintText(200, 50  + 150, time_str, HEI, 24, 1, black);
    PrintText(200, 100 + 150, phone_str, HEI, 24, 1, black);
}

void draw_order_detail(int type,OrderList *OL, FoodList *FL, DeliverList *DL,
    int local_index, int page) 
{
    int i;
    Order currentOrder ; 
    FoodOrder currentFood;

    char current_time[20]; // 获取当前时间
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
    char total_str[20]; // 总金额字符串
    int fullPageItemCount = 0; // 满页商品数量
    
    bar1(0, 150, 1024, 768, white);// 将详情页绘制在 0,150 到 1024,768 区域

    currentOrder = OL->elem[local_index]; // 当前订单
    currentFood = FL->elem[local_index]; // 当前订单

    // 分页按钮（超市和外卖类型）
    if (type != ORDER_DELIVER) {
        Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue);
        PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
        Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue);
        PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);
    }

    // 接单按钮
    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue);
    PrintCC(850, 715, "接单", HEI, 24, 1, deepblue);

    
    // 第一页绘制头部
    if(page==0&&type!=ORDER_DELIVER)
    {
        draw_order_detail_header(type, local_index, OL, FL, DL);

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
        draw_order_detail_header(type, local_index, OL, FL, DL);
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
        Deliver *d = &DL->elem[local_index];
        sprintf(code_buf, "取件码：%s", d->code);
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

//进入所接订单详情
void show_order_detail(int local_index, int type, int user_pos) 
{
    OrderList OL = {0};
    FoodList FL = {0};
    DeliverList DL = {0};
    int page = 0;
    int totalPage = 1;
    
    ReadAllOrder(&OL);
    ReadAllFood(&FL);
    ReadAllDeliver(&DL);

    // 计算总页数//第一页4个，第二页后面9个
    if (type == ORDER_SUPERMARKET) {
        totalPage = (OL.elem[local_index].itemCount - 4 + 8) / 9 + 1;
    } else if (type == ORDER_FOOD) {
        totalPage = (FL.elem[local_index].itemCount - 4 + 8) / 9 + 1;
    }
    // ORDER_DELIVER 保持 totalPage=0

    // 绘制订单详情
    draw_order_detail(type, &OL, &FL, &DL, local_index, page);

    mouse_on_arrow(mouse);
    while (1) {
        mouse_show_arrow(&mouse);
        // 返回按钮（假设位置同原来）
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
            route(cur_orders,num_of_orders.cur_count,user_pos);//骑手路线规划
            //return后从这开始
            ReadAllOrder(&OL);
            ReadAllFood(&FL);
            ReadAllDeliver(&DL);
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_accept_order(page,&OL,&FL,&DL); // 重新绘制订单列表
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //我的
        {
            press3(3); //按钮高亮
            press4(1);
            DestroyOList(&OL); // 释放订单列表内存
            DestroyFList(&FL); // 释放食品列表内存
            DestroyDList(&DL); // 释放快递列表内存
            my_information(user_pos);//进入我的信息界面
            //return后从这开始
            ReadAllOrder(&OL);
            ReadAllFood(&FL);
            ReadAllDeliver(&DL);
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); 
            draw_rider();
            mouse_on_arrow(mouse);
        }
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_order_detail(type, &OL, &FL, &DL, local_index, page);
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
				draw_order_detail(type, &OL, &FL, &DL, local_index, page);
			} else {
				// 提示：已是最后一页
				PrintCC(630, 715, "已是最后一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(630, 715, 780, 765, white);
			}
		}
    }
}
