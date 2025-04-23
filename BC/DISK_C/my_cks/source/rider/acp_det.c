#include "all_func.h"

#define MAX_COMBINED_ORDERS 20
#define ORDERS_PER_PAGE   4     // 每页显示商品数

#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

void draw_order_detail_header(int type, int local_index,OrderList *OL, FoodList *FL, DeliverList *DL) 
{

    char buf[128];
    // 通用：下单时间、手机号
    char time_str[64];
    char phone_str[64];
    char show_distance[20];
    char show_deliver_price[20];
    int distance_m;
    float distance_km;
    float item_price;
    float deliver_price;
    if (type == ORDER_SUPERMARKET) {
        Order *o = &OL->elem[local_index];
        sprintf(time_str, "下单时间：%s", o->order_time);
        sprintf(phone_str, "手机号：%s", o->user_phone);
        // 取货点（相对区域顶部偏移 +150）
        sprintf(buf, "取货点：%s", node[o->pick_up_location].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // 用户地址
        sprintf(buf, "用户地址：%s", node[o->destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //距离
        distance_m = dijkstra(&node[o->pick_up_location], &node[o->destination],3); // 计算距离
        distance_km = distance_m / 1000.0; // 转换为公里
        sprintf(show_distance, "距离：%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, 0x0000);

        item_price = o->total_amount; // 获取商品价格
        deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
        sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, 0x0000);

    }
    else if (type == ORDER_FOOD) {
        FoodOrder *f = &FL->elem[local_index];
        sprintf(time_str, "下单时间：%s", f->order_time);
        sprintf(phone_str, "手机号：%s", f->user_phone);
        // 取货点（相对区域顶部偏移 +150）
        sprintf(buf, "取货点：%s", node[f->pick_up_location].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // 用户地址
        sprintf(buf, "用户地址：%s", node[f->destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //距离
        distance_m = dijkstra(&node[f->pick_up_location], &node[f->destination],3); // 计算距离
        distance_km = distance_m / 1000.0; // 转换为公里
        sprintf(show_distance, "距离：%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, 0x0000);

        item_price = f->total_amount; // 获取商品价格
        deliver_price = rider_deliver_price(distance_m, item_price); // 计算配送费用
        sprintf(show_deliver_price, "配送费：%.1f元", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, 0x0000);
    }
    else if (type == ORDER_DELIVER) {
        Deliver *d = &DL->elem[local_index];
        sprintf(time_str, "下单时间：%s", d->time);
        sprintf(phone_str, "手机号：%s", d->number);
        // 取货点（相对区域顶部偏移 +150）
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

void draw_items(int type, int local_index,OrderList *OL, FoodList *FL,int page) 
{
    int i;
    int start = page * ORDERS_PER_PAGE;
    int end;
    char name_buf[64], qty_buf[32], price_buf[32];
    int y = 350 + 150;  // 初始y偏移350，再加150

    if (type == ORDER_SUPERMARKET) {
        Order *o = &OL->elem[local_index];
        end = start + ORDERS_PER_PAGE;
        if (end > o->itemCount) end = o->itemCount;
        for (i = start; i < end; i++) {
            sprintf(name_buf, "%s", o->item[i].name);
            sprintf(qty_buf, "x%d", o->item[i].quantity);
            sprintf(price_buf, "%.2f", o->item[i].price * o->item[i].quantity);
            PrintText(250, y, name_buf, HEI, 24, 1, black);
            PrintText(750, y, qty_buf, HEI, 24, 1, black);
            PrintText(900, y, price_buf, HEI, 24, 1, black);
            y += 50;
        }
    }
    else if (type == ORDER_FOOD) {
        FoodOrder *f = &FL->elem[local_index];
        end = start + ORDERS_PER_PAGE;
        if (end > f->itemCount) end = f->itemCount;
        for (i = start; i < end; i++) {
            sprintf(name_buf, "%s", f->item[i].name);
            sprintf(qty_buf, "x%d", f->item[i].quantity);
            sprintf(price_buf, "%.2f", f->item[i].price * f->item[i].quantity);
            PrintText(250, y, name_buf, HEI, 24, 1, black);
            PrintText(750, y, qty_buf, HEI, 24, 1, black);
            PrintText(900, y, price_buf, HEI, 24, 1, black);
            y += 50;
        }
    }
}

void draw_order_detail(int type,OrderList *OL, FoodList *FL, DeliverList *DL,
    int local_index, int page, int totalPage) 
{
    // 将详情页绘制在 0,150 到 1024,768 区域
    bar1(0, 150, 1024, 768, white);

    // 分页按钮（超市和外卖类型）
    if (type != ORDER_DELIVER) {
        Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue);
        PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
        Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue);
        PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);
    }

    // 接单按钮（替换开始备货）
    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue);
    PrintCC(850, 715, "接单", HEI, 24, 1, deepblue);

    // 绘制头部
    draw_order_detail_header(type, local_index, OL, FL, DL);

    if (type == ORDER_DELIVER) {
        // 只展示取件码（相对偏移）
        char code_buf[64];
        Deliver *d = &DL->elem[local_index];
        sprintf(code_buf, "取件码：%s", d->code);
        PrintText(250, 400 + 150, code_buf, HEI, 32, 1, black);
    } else {
        // 表头（相对偏移）
        PrintCC(200, 330 + 150, "商品详情", HEI, 24, 1, black);
        PrintCC(650, 330 + 150, "数量", HEI, 24, 1, black);
        PrintCC(800, 330 + 150, "金额", HEI, 24, 1, black);
        PrintText(150, 350 + 150, "------------------------------------", HEI, 32, 1, black);
        // 商品列表
        draw_items(type, local_index, OL, FL, page);
    }
}

void accept_order_detail(int local_index, int type) {
    OrderList OL = {0};
    FoodList FL = {0};
    DeliverList DL = {0};
    int page = 0;
    int totalPage = 1;
    
    ReadAllOrder(&OL);
    ReadAllFood(&FL);
    ReadAllDeliver(&DL);

    // 计算总页数
    if (type == ORDER_SUPERMARKET) {
        totalPage = (OL.elem[local_index].itemCount + ORDERS_PER_PAGE - 1) / ORDERS_PER_PAGE;
    } else if (type == ORDER_FOOD) {
        totalPage = (FL.elem[local_index].itemCount + ORDERS_PER_PAGE - 1) / ORDERS_PER_PAGE;
    }
    // ORDER_DELIVER 保持 totalPage=1

    draw_order_detail(type, &OL, &FL, &DL, local_index, page, totalPage);

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
            route(acp_orders,4);//骑手路线规划
            //return后从这开始
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_accept_order(page,&OL,&FL,&DL); // 重新绘制订单列表
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //账户
        {
            press3(3); //按钮高亮
        }
    }
}
