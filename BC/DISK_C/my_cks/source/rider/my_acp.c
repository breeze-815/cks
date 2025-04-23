#include "all_func.h"

#define MAX_ACCEPTED_ORDERS 4
#define ORDERS_PER_PAGE   4

#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

AcceptedOrder acp_orders[4];
// 全局接单数组，只存储全局索引

// 接单处理：从对应列表中移除，并加入 acp_orders
void rider_accept(OrderList *OL, FoodList *FL, DeliverList *DL,
    int type, int local_index, int page ) 
{
    
    int global_index = page * ORDERS_PER_PAGE + local_index;
    int i;
    //extern int delivers.acp_count;
    // 检查是否超过最大接单数量
    if ( delivers.acp_count== MAX_ACCEPTED_ORDERS) {
    PrintText(100, 100, "接单数量已达上限！", HEI, 24, 1, Red);
    }

    else{
    // 根据类型，存储进 acp_orders 数组
    acp_orders[delivers.acp_count].type = type;
    if (type == ORDER_SUPERMARKET) 
    {
        acp_orders[delivers.acp_count].data.order = OL->elem[local_index];

        // 从超市订单列表移除该单
        for (i = local_index; i < OL->length - 1; i++)
        {
            OL->elem[i] = OL->elem[i + 1];
            OL->length--;
        }
    }

    else if (type == ORDER_FOOD) 
    {
        acp_orders[delivers.acp_count].data.food = FL->elem[local_index];

        // 从食品订单列表移除该单
        for (i = local_index; i < FL->length - 1; i++)
        {
            FL->elem[i] = FL->elem[i + 1];
            FL->length--;
        }
    }


    else if (type == ORDER_DELIVER) 
    {
        acp_orders[delivers.acp_count].data.deliver = DL->elem[local_index];

        // 从快递订单列表移除该单
        for (i = local_index; i < DL->length - 1; i++)
        {
            DL->elem[i] = DL->elem[i + 1];
            DL->length--;
        }
    }
    delivers.acp_count++;
    delivers.total_cnt--;
    return delivers.acp_count;
    }
}


void my_accept_order() {
    int page = 0;
    int total_cnt;
    int type, local,global;
    
    
    //total_cnt = OL.length + FL.length + DL.length;
    //draw_accept_order(page, &OL, &FL, &DL, total_cnt);
    draw_my_accept();
    mouse_on_arrow(mouse);

    while (1) {
        // mouse_show_arrow(&mouse);
        
        // if (mouse_press(850, 170 + 25, 950, 170 + 75) == 1) {
        //     global = page * ORDERS_PER_PAGE + 0;
        //     if (global < OL.length + FL.length + DL.length) 
        //     {
        //         if (global < OL.length) 
        //         {
        //             type = ORDER_SUPERMARKET; 
        //             local = global;
        //         }
        //         else if (global < OL.length + FL.length) 
        //         {
        //             type = ORDER_FOOD; 
        //             local = global - OL.length;
        //         }
        //         else 
        //         {
        //             type = ORDER_DELIVER; 
        //             local = global - OL.length - FL.length;
        //         }
        //         rider_accept(&OL, &FL, &DL, type, local, page,delivers.acp_count);
        //         total_cnt--;
        //         bar1(0,150,1024,768,white);
        //         draw_accept_order(page, &OL, &FL, &DL, total_cnt);
        //     }
        // }
        // // #2
        // else if (mouse_press(850, 290 + 25, 950, 290 + 75) == 1) {
        //         global = page * ORDERS_PER_PAGE + 1;
        //     if (global < OL.length + FL.length + DL.length) 
        //     {
        //         if (global < OL.length) 
        //         {
        //             type = ORDER_SUPERMARKET; 
        //             local = global;
        //         }
        //         else if (global < OL.length + FL.length) 
        //         {
        //             type = ORDER_FOOD; 
        //             local = global - OL.length;
        //         }
        //         else 
        //         {
        //             type = ORDER_DELIVER; 
        //             local = global - OL.length - FL.length;
        //         }
        //         rider_accept(&OL, &FL, &DL, type, local, page);
        //         total_cnt--;
        //         bar1(0,150,1024,768,white);
        //         draw_accept_order(page, &OL, &FL, &DL, total_cnt);
        //     }
        // }
        // // #3
        // else if (mouse_press(850, 410 + 25, 950, 410 + 75) == 1) {
        //     global = page * ORDERS_PER_PAGE + 2;
        //     if (global < OL.length + FL.length + DL.length) 
        //     {
        //         if (global < OL.length) 
        //         {
        //             type = ORDER_SUPERMARKET; 
        //             local = global;
        //         }
        //         else if (global < OL.length + FL.length) 
        //         {
        //             type = ORDER_FOOD; 
        //             local = global - OL.length;
        //         }
        //         else 
        //         {
        //             type = ORDER_DELIVER; 
        //             local = global - OL.length - FL.length;
        //         }
        //         rider_accept(&OL, &FL, &DL, type, local, page);
        //         total_cnt--;
        //         bar1(0,150,1024,768,white);
        //         draw_accept_order(page, &OL, &FL, &DL, total_cnt);
        //     }
        // }
        // // #4
        // else if (mouse_press(850, 530 + 25, 950, 530 + 75) == 1) {
        //     global = page * ORDERS_PER_PAGE + 3;
        //     if (global < OL.length + FL.length + DL.length) 
        //     {
        //         if (global < OL.length) 
        //         {
        //             type = ORDER_SUPERMARKET; 
        //             local = global;
        //         }
        //         else if (global < OL.length + FL.length) 
        //         {
        //             type = ORDER_FOOD; 
        //             local = global - OL.length;
        //         }
        //         else 
        //         {
        //             type = ORDER_DELIVER; 
        //             local = global - OL.length - FL.length;
        //         }
        //         rider_accept(&OL, &FL, &DL, type, local, page);
        //         total_cnt--;
        //         bar1(0,150,1024,768,white);
        //         draw_accept_order(page, &OL, &FL, &DL, total_cnt);
        //     }
        // }

        // 其它交互，如翻页、返回等...
    }
}

void draw_my_accept() {
    int y_offset = 170;
    char pick_up[100], dest[100], distance_str[50], price_str[50];
    int distance_m;
    float dist_km, amount, fee;
    int i;

    bar1(0, 150, 1024, 768, white);

    for (i = 0; i < delivers.acp_count; i++) {
        AcceptedOrder *ao = &acp_orders[i];  // ← 用对数组！
        // 画框
        Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

        // 根据类型取数据
        switch (ao->type) {
            case ORDER_SUPERMARKET: {
                int pu   = ao->data.order.pick_up_location;
                int dst  = ao->data.order.destination;
                amount   = ao->data.order.total_amount;

                sprintf(pick_up, "取货点：%s", node[pu].name);
                sprintf(dest,    "目的地：%s", node[dst].name);
                distance_m = dijkstra(&node[pu], &node[dst], 3);
                break;
            }
            case ORDER_FOOD: {
                int pu   = ao->data.food.station;
                int dst  = ao->data.food.destination;
                amount   = ao->data.food.total_amount;

                sprintf(pick_up, "取餐点：%s", node[pu].name);
                sprintf(dest,    "目的地：%s", node[dst].name);
                distance_m = dijkstra(&node[pu], &node[dst], 3);
                break;
            }
            case ORDER_DELIVER: {
                int pu   = ao->data.deliver.station;
                int dst  = ao->data.deliver.index;
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

        PrintText(50,  y_offset + 10, pick_up, HEI, 24, 1, BLACK);
        PrintText(50,  y_offset + 60, dest,    HEI, 24, 1, BLACK);
        sprintf(distance_str, "距离：%.2fkm", dist_km);
        PrintText(500, y_offset + 10, distance_str, HEI, 24, 1, BLACK);
        sprintf(price_str,    "配送费：%.1f元", fee);
        PrintText(500, y_offset + 60, price_str,    HEI, 24, 1, BLACK);

        // 取消按钮
        Fill_Rounded_Rectangle(875, y_offset + 25, 975, y_offset + 75, 25, white);
        Draw_Rounded_Rectangle(875, y_offset + 25, 975, y_offset + 75, 25, 1, RED);
        PrintCC(900, y_offset + 50, "取消", HEI, 24, 1, RED);

        y_offset += 120;
    }

    // 返回按钮
    Draw_Rounded_Rectangle(122, 50, 242, 100, 25, 1, deepblue);
    PrintCC(182, 75, "返回", HEI, 24, 1, deepblue);
}
