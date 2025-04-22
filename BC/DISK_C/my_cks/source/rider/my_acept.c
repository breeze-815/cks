#include "all_func.h"

#define MAX_ACCEPTED_ORDERS 4
#define ORDERS_PER_PAGE   4

#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

// 全局接单数组，只存储全局索引
static int acp_orders[4];
static int acp_count = 0;
static int acp_orders_index[4];// 全局接单数组，只存储全局索引
static int acp_count = 0;





// 接单处理：从对应列表中移除，并加入 acp_orders
void add_to_accepted(OrderList *OL, FoodList *FL, DeliverList *DL,
                  int type, int local_index, int page) {
    int global_index = page * 4 + local_index;
    int i;
    // 加入我的接单
    if (acp_count < 4) {
        acp_orders_index[acp_count++] = global_index;
    }
    // 从原列表移除
    if (type == 0) {
        for (i = local_index; i < OL->length - 1; i++)
            OL->elem[i] = OL->elem[i + 1];
        OL->length--;
    }
    else if (type == 1) {
        for (i = local_index; i < FL->length - 1; i++)
            FL->elem[i] = FL->elem[i + 1];
        FL->length--;
    }
    else if (type == 2) {
        for (i = local_index; i < DL->length - 1; i++)
            DL->elem[i] = DL->elem[i + 1];
        DL->length--;
    }
}


// 通过全局索引，反推类型和本地索引
void get_ordtyp_locind(int global_index, int *type, int *local_index, 
    const OrderList *OL, const FoodList *FL, const DeliverList *DL) 
{
    if (global_index < OL->length) 
    {
        *type = 0;
        *local_index = global_index;
    } 
    else if (global_index < OL->length + FL->length) 
    {
        *type = 1;
        *local_index = global_index - OL->length;
    } 
    else if (global_index < OL->length + FL->length + DL->length) 
    {
        *type = 2;
        *local_index = global_index - OL->length - FL->length;
    } 
    else 
    {
        *type = -1;  // 越界错误
        *local_index = -1;
    }
} 

void accept_order() {
    int page = 0;
    int total_cnt;
    int type, local,global;
    OrderList OL = {0};
    FoodList FL = {0};
    DeliverList DL = {0};
    ReadAllOrder(&OL);
    ReadAllFood(&FL);
    ReadAllDeliver(&DL);
    
    total_cnt = OL.length + FL.length + DL.length;
    draw_accept_order(page, &OL, &FL, &DL, total_cnt);
    mouse_on_arrow(mouse);

    while (1) {
        mouse_show_arrow(&mouse);
        
        if (mouse_press(850, 170 + 25, 950, 170 + 75) == 1) {
            global = page * ORDERS_PER_PAGE + 0;
            if (global < OL.length + FL.length + DL.length) 
            {
                if (global < OL.length) 
                {
                    type = ORDER_SUPERMARKET; 
                    local = global;
                }
                else if (global < OL.length + FL.length) 
                {
                    type = ORDER_FOOD; 
                    local = global - OL.length;
                }
                else 
                {
                    type = ORDER_DELIVER; 
                    local = global - OL.length - FL.length;
                }
                rider_accept(&OL, &FL, &DL, type, local, page);
                total_cnt--;
                bar1(0,150,1024,768,white);
                draw_accept_order(page, &OL, &FL, &DL, total_cnt);
            }
        }
        // #2
        else if (mouse_press(850, 290 + 25, 950, 290 + 75) == 1) {
                global = page * ORDERS_PER_PAGE + 1;
            if (global < OL.length + FL.length + DL.length) 
            {
                if (global < OL.length) 
                {
                    type = ORDER_SUPERMARKET; 
                    local = global;
                }
                else if (global < OL.length + FL.length) 
                {
                    type = ORDER_FOOD; 
                    local = global - OL.length;
                }
                else 
                {
                    type = ORDER_DELIVER; 
                    local = global - OL.length - FL.length;
                }
                rider_accept(&OL, &FL, &DL, type, local, page);
                total_cnt--;
                bar1(0,150,1024,768,white);
                draw_accept_order(page, &OL, &FL, &DL, total_cnt);
            }
        }
        // #3
        else if (mouse_press(850, 410 + 25, 950, 410 + 75) == 1) {
            global = page * ORDERS_PER_PAGE + 2;
            if (global < OL.length + FL.length + DL.length) 
            {
                if (global < OL.length) 
                {
                    type = ORDER_SUPERMARKET; 
                    local = global;
                }
                else if (global < OL.length + FL.length) 
                {
                    type = ORDER_FOOD; 
                    local = global - OL.length;
                }
                else 
                {
                    type = ORDER_DELIVER; 
                    local = global - OL.length - FL.length;
                }
                rider_accept(&OL, &FL, &DL, type, local, page);
                total_cnt--;
                bar1(0,150,1024,768,white);
                draw_accept_order(page, &OL, &FL, &DL, total_cnt);
            }
        }
        // #4
        else if (mouse_press(850, 530 + 25, 950, 530 + 75) == 1) {
            global = page * ORDERS_PER_PAGE + 3;
            if (global < OL.length + FL.length + DL.length) 
            {
                if (global < OL.length) 
                {
                    type = ORDER_SUPERMARKET; 
                    local = global;
                }
                else if (global < OL.length + FL.length) 
                {
                    type = ORDER_FOOD; 
                    local = global - OL.length;
                }
                else 
                {
                    type = ORDER_DELIVER; 
                    local = global - OL.length - FL.length;
                }
                rider_accept(&OL, &FL, &DL, type, local, page);
                total_cnt--;
                bar1(0,150,1024,768,white);
                draw_accept_order(page, &OL, &FL, &DL, total_cnt);
            }
        }

        // 其它交互，如翻页、返回等...
    }
}
