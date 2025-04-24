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
    // ReadAllDeliver(&DL); // ��ȡ����б�
    // ReadAllOrder(&OL); // ��ȡ�����б�
    // ReadAllFood(&FL); // ��ȡʳƷ�б�
    //total_cnt = OL.length + FL.length + DL.length;
    //draw_accept_order(page, &OL, &FL, &DL, total_cnt);
    draw_my_history_order();
    mouse_on_arrow(mouse);

    while (1) {
        mouse_show_arrow(&mouse);
        if(mouse_press(122, 50, 242, 100)==1) //����
        {
            // DestroyOList(&OL); // �ͷŶ����б��ڴ�
            // DestroyFList(&FL); // �ͷ�ʳƷ�б��ڴ�
            // DestroyDList(&DL); // �ͷſ���б��ڴ�
            return;
			//my_information;
		}
        else if(mouse_press(342, 50, 462, 100)==1)
        {
            press3(1);//����ӵ�����
            mouse_off_arrow(&mouse);
            accept_order(user_pos);//�ӵ�ҳ��
            //return����⿪ʼ
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // ����ӵ��������
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(562, 50, 682, 100)==1) //·��
        {
            press3(2); //��ť����
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // ����ӵ��������
            route(cur_orders,num_of_orders.cur_count,user_pos);//����·�߹滮
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_my_history_order(); // ���»��ƶ����б�
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //�ҵ�
        {
            press3(3); //��ť����
            mouse_off_arrow(&mouse);
            my_information(user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_my_history_order(); // ���»��ƶ����б�
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 439, 160, 489) == 1)
        {
            press4(2);
            my_accept_order(user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 602, 160, 652) == 1)
        {
            press4(3);
            my_history_order(user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
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
        // ����
        Draw_Rounded_Rectangle(220, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

        Fill_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, white);
        Draw_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, 1,deepblue);
        PrintCC(750+25, y_offset+35, "����", HEI, 24, 1, deepblue);

        // // ȡ����ť
        // Fill_Rounded_Rectangle(875, y_offset + 25, 975, y_offset + 75, 25, white);
        // Draw_Rounded_Rectangle(875, y_offset + 25, 975, y_offset + 75, 25, 1, deepblue);
        // PrintCC(900, y_offset + 35, "ȡ��", HEI, 24, 1, deepblue);
        // ��������ȡ����
        switch (ho->type) {
            case ORDER_SUPERMARKET: {
                int pu   = ho->data.order.pick_up_location;
                int dst  = ho->data.order.destination;
                amount   = ho->data.order.total_amount;

                sprintf(pick_up, "ȡ���㣺%s", node[pu].name);
                sprintf(dest,    "Ŀ�ĵأ�%s", node[dst].name);
                distance_m = dijkstra(&node[pu], &node[dst], 3);
                break;
            }
            case ORDER_FOOD: {
                int pu   = ho->data.food.pick_up_location;
                int dst  = ho->data.food.destination;
                amount   = ho->data.food.total_amount;

                sprintf(pick_up, "ȡ�͵㣺%s", node[pu].name);
                sprintf(dest,    "Ŀ�ĵأ�%s", node[dst].name);
                distance_m = dijkstra(&node[pu], &node[dst], 3);
                break;
            }
            case ORDER_DELIVER: {
                int pu   = ho->data.deliver.station+408;
                int dst  = ho->data.deliver.index;
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

        PrintText(250,  y_offset + 10, pick_up, HEI, 24, 1, BLACK);
        PrintText(250,  y_offset + 60, dest,    HEI, 24, 1, BLACK);
        sprintf(distance_str, "���룺%.2fkm", dist_km);
        PrintText(500, y_offset + 10, distance_str, HEI, 24, 1, BLACK);
        sprintf(price_str,    "���ͷѣ�%.1fԪ", fee);
        PrintText(500, y_offset + 60, price_str,    HEI, 24, 1, BLACK);
        y_offset += 120;
    }
}