#include "all_func.h"

#define MAX_ACCEPTED_ORDERS 4
#define ORDERS_PER_PAGE   4

#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

AcceptedOrder acp_orders[4]={0};

// �ӵ������Ӷ�Ӧ�б����Ƴ��������� acp_orders
void rider_accept(OrderList *OL, FoodList *FL, DeliverList *DL,
    int type, int local_index, int page ) 
{
    char debg[20];
    int global_index = page * ORDERS_PER_PAGE + local_index;
    int i;
    //extern int delivers.acp_count;
    // ����Ƿ񳬹����ӵ�����
    
    // �������ͣ��洢�� acp_orders ����
    acp_orders[delivers.acp_count].type = type;
    sprintf(debg,"%d",delivers.acp_count);
    PrintText(100, 100, debg, HEI, 24, 1, Red);
    if (type == ORDER_SUPERMARKET) 
    {
        acp_orders[delivers.acp_count].data.order = OL->elem[local_index];

        sprintf(debg,"%d",acp_orders[delivers.acp_count].data.order.pick_up_location);
        PrintText(120, 100, debg, HEI, 24, 1, Red);
        // �ӳ��ж����б��Ƴ��õ�
        // �Ȱ����к���Ԫ����ǰ��һλ
        for (i = local_index; i < OL->length - 1; i++) 
            OL->elem[i] = OL->elem[i + 1];
        OL->length--;

    }

    else if (type == ORDER_FOOD) 
    {
        acp_orders[delivers.acp_count].data.food = FL->elem[local_index];

        // ��ʳƷ�����б��Ƴ��õ�
        for (i = local_index; i < FL->length - 1; i++) 
            FL->elem[i] = FL->elem[i + 1];
        FL->length--;
    }


    else if (type == ORDER_DELIVER) 
    {
        acp_orders[delivers.acp_count].data.deliver = DL->elem[local_index];

        // �ӿ�ݶ����б��Ƴ��õ�
        for (i = local_index; i < DL->length - 1; i++)
            DL->elem[i] = DL->elem[i + 1];
        DL->length--;
    }
    delivers.acp_count++;
    delivers.total_cnt--;
    }



void my_accept_order() {
    int page = 0;
    int total_cnt;
    int type, local,global;
    OrderList OL = {0};
    FoodList FL = {0};
    DeliverList DL = {0};
    ReadAllDeliver(&DL); // ��ȡ����б�
    ReadAllOrder(&OL); // ��ȡ�����б�
    ReadAllFood(&FL); // ��ȡʳƷ�б�
    //total_cnt = OL.length + FL.length + DL.length;
    //draw_accept_order(page, &OL, &FL, &DL, total_cnt);
    draw_my_accept();
    mouse_on_arrow(mouse);

    while (1) {
        mouse_show_arrow(&mouse);
        if(mouse_press(122, 50, 242, 100)==1) //����
        {
            DestroyOList(&OL); // �ͷŶ����б��ڴ�
            DestroyFList(&FL); // �ͷ�ʳƷ�б��ڴ�
            DestroyDList(&DL); // �ͷſ���б��ڴ�
            return;
			//business(users.pos);
		}
        else if(mouse_press(562, 50, 682, 100)==1) //·��
        {
            press3(2); //��ť����
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // ����ӵ��������
            route(acp_orders,4);//����·�߹滮
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_accept_order(page,&OL,&FL,&DL); // ���»��ƶ����б�
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //�ҵ�
        {
            press3(3); //��ť����
            my_accept_order();
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_accept_order(page,&OL,&FL,&DL); // ���»��ƶ����б�
            mouse_on_arrow(mouse);
        }

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

        // �����������緭ҳ�����ص�...
    }
}

void draw_my_accept() {
    int y_offset = 170;
    char pick_up[100], dest[100], distance_str[50], price_str[50];
    int distance_m;
    float dist_km, amount, fee;
    int i;
    char debg[20];
    bar1(0, 150, 1024, 768, white);
    sprintf(debg,"%d",delivers.acp_count);
    PrintText(150, 100, debg, HEI, 24, 1, Red);

    for (i = 0; i < delivers.acp_count; i++) {
        AcceptedOrder *ao = &acp_orders[i];  // �� �ö����飡
        // ����
        Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

        Fill_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, white);
        Draw_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, 1,deepblue);
        PrintCC(750+25, y_offset+35, "����", HEI, 24, 1, deepblue);

        // ȡ����ť
        Fill_Rounded_Rectangle(875, y_offset + 25, 975, y_offset + 75, 25, white);
        Draw_Rounded_Rectangle(875, y_offset + 25, 975, y_offset + 75, 25, 1, deepblue);
        PrintCC(900, y_offset + 35, "ȡ��", HEI, 24, 1, deepblue);
        // ��������ȡ����
        switch (ao->type) {
            case ORDER_SUPERMARKET: {
                int pu   = ao->data.order.pick_up_location;
                int dst  = ao->data.order.destination;
                amount   = ao->data.order.total_amount;

                sprintf(pick_up, "ȡ���㣺%s", node[pu].name);
                sprintf(dest,    "Ŀ�ĵأ�%s", node[dst].name);
                distance_m = dijkstra(&node[pu], &node[dst], 3);
                break;
            }
            case ORDER_FOOD: {
                int pu   = ao->data.food.station;
                int dst  = ao->data.food.destination;
                amount   = ao->data.food.total_amount;

                sprintf(pick_up, "ȡ�͵㣺%s", node[pu].name);
                sprintf(dest,    "Ŀ�ĵأ�%s", node[dst].name);
                distance_m = dijkstra(&node[pu], &node[dst], 3);
                break;
            }
            case ORDER_DELIVER: {
                int pu   = ao->data.deliver.station;
                int dst  = ao->data.deliver.index;
                amount   = 2.0f;

                sprintf(pick_up, "ȡ���㣺%s", node[pu].name);
                sprintf(dest,    "Ŀ�ĵأ�%s", node[dst].name);
                distance_m = dijkstra(&node[pu], &node[dst], 3);
                break;
            }
            default:
                continue;
        }

        // ���㲢��ӡ���롢����
        dist_km = distance_m / 1000.0f;
        fee     = rider_deliver_price(distance_m, amount);

        PrintText(50,  y_offset + 10, pick_up, HEI, 24, 1, BLACK);
        PrintText(50,  y_offset + 60, dest,    HEI, 24, 1, BLACK);
        sprintf(distance_str, "���룺%.2fkm", dist_km);
        PrintText(500, y_offset + 10, distance_str, HEI, 24, 1, BLACK);
        sprintf(price_str,    "���ͷѣ�%.1fԪ", fee);
        PrintText(500, y_offset + 60, price_str,    HEI, 24, 1, BLACK);

        
        y_offset += 120;
    }

    }
