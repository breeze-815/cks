#include <all_func.h>

#define MAX_ACCEPTED_ORDERS 4
#define ORDERS_PER_PAGE   4

#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

AcceptedOrder hst_orders[6]={0};

void my_history_order(int user_pos)
{   
    int page = 0;
    int type, local, global;
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
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_my_history_order(); // 重新绘制订单列表
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 439, 160, 489) == 1)
        {
            press4(2);
            my_accept_order(user_pos);
            //return后从这开始
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 602, 160, 652) == 1)
        {
            press4(3);
            my_history_order(user_pos);
            //return后从这开始
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
    }
}

// void add_to_history(Order o) 
// {
//     if (num_of_orders.hst_count < 6) 
//     {
//         memcpy(&hst_orders[num_of_orders.hst_count], o, sizeof(Order));
//         num_of_orders.hst_count++;
//     }
// }

void draw_my_history_order()
{
    int y_offset = 170;
    char pick_up[100], dest[100], distance_str[50], price_str[50];
    int distance_m;
    float dist_km, amount, fee;
    int i;
    
    bar1(200, 150, 1024, 768, white);

    for (i = 0; i < num_of_orders.cur_count; i++) 
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
                int pu   = ho->data.food.pick_up_location;
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