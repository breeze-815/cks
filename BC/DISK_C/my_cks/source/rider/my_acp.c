#include "all_func.h"

#define MAX_ACCEPTED_ORDERS 4
#define ORDERS_PER_PAGE   4

#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

// ȫ�ֽӵ����飬ֻ�洢ȫ������

// �ӵ������Ӷ�Ӧ�б����Ƴ��������� acp_orders
void rider_accept(OrderList *OL, FoodList *FL, DeliverList *DL,
    int type, int local_index, int page) 
{
    int global_index = page * ORDERS_PER_PAGE + local_index;
    int i;
    extern int acp_count;
    // ����Ƿ񳬹����ӵ�����
    if (acp_count >= MAX_ACCEPTED_ORDERS) {
    PrintText(100, 100, "�ӵ������Ѵ����ޣ�", HEI, 24, 1, Red);
    return;
    }

    // �������ͣ��洢�� acp_orders ����
    acp_orders[acp_count].type = type;
    if (type == ORDER_SUPERMARKET) 
    {
        acp_orders[acp_count].data.order = OL->elem[local_index];

        // �ӳ��ж����б��Ƴ��õ�
        for (i = local_index; i < OL->length - 1; i++)
        {
            OL->elem[i] = OL->elem[i + 1];
            OL->length--;
        }
    }

    else if (type == ORDER_FOOD) 
    {
        acp_orders[acp_count].data.food = FL->elem[local_index];

        // ��ʳƷ�����б��Ƴ��õ�
        for (i = local_index; i < FL->length - 1; i++)
        {
            FL->elem[i] = FL->elem[i + 1];
            FL->length--;
        }
    }


    else if (type == ORDER_DELIVER) 
    {
        acp_orders[acp_count].data.deliver = DL->elem[local_index];

        // �ӿ�ݶ����б��Ƴ��õ�
        for (i = local_index; i < DL->length - 1; i++)
        {
            DL->elem[i] = DL->elem[i + 1];
            DL->length--;
        }
    }
    acp_count++;
}


void my_accept_order() {
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

        // �����������緭ҳ�����ص�...
    }
}
