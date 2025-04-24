#include "all_func.h"

#define MAX_ACCEPTED_ORDERS 4
#define ORDERS_PER_PAGE   4

#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

AcceptedOrder cur_orders[4]={0};

// �ӵ������Ӷ�Ӧչʾ�б����Ƴ��������� cur_orders
void add_my_accept(OrderList *OL, FoodList *FL, DeliverList *DL,int type, int local_index) 
{
    int i;
   //��ֹԽ��
    cur_orders[num_of_orders.cur_count].type = type;
    
    if (type == ORDER_SUPERMARKET) 
    {
        cur_orders[num_of_orders.cur_count].data.order = OL->elem[local_index];
        // �ӳ��ж����б��Ƴ��õ�
        // �Ȱ����к���Ԫ����ǰ��һλ���ٰѶ�������һ
        for (i = local_index; i < OL->length - 1; i++) 
            OL->elem[i] = OL->elem[i + 1];
        OL->length--;
        save_OL(OL);

    }
    else if (type == ORDER_FOOD) 
    {
        cur_orders[num_of_orders.cur_count].data.food = FL->elem[local_index];
        // ��ʳƷ�����б��Ƴ��õ�
        for (i = local_index; i < FL->length - 1; i++) 
            FL->elem[i] = FL->elem[i + 1];
        FL->length--;
        save_FL(FL);
    }
    else if (type == ORDER_DELIVER) 
    {
        cur_orders[num_of_orders.cur_count].data.deliver = DL->elem[local_index];
        // �ӿ�ݶ����б��Ƴ��õ�
        for (i = local_index; i < DL->length - 1; i++)
            DL->elem[i] = DL->elem[i + 1];
        DL->length--;
        save_DL(DL);
    }
    num_of_orders.cur_count++; //��ǰ�ӵ�����
    num_of_orders.total_cnt--; //չʾ�������� 
}

//���ҵ��б����Ƴ�
void delete_my_order(int index)
{
    int type;
    OrderList OL = {0}; //�������У��������������Կձ����ڶ�ȡ
    FoodList FL = {0};
    DeliverList DL = {0};
    ReadAllOrder(&OL); // ��ȡ�����б�
    ReadAllFood(&FL); // ��ȡʳƷ�б�
    ReadAllDeliver(&DL); // ��ȡ����б�
    type = cur_orders[index].type;

    cut_current_order(index); 
    
    if (type == ORDER_SUPERMARKET) 
    {
        save_order(cur_orders[index].data.order);
    }

    if (type == ORDER_FOOD) 
    {
        save_food(cur_orders[index].data.food);
    }

    if (type == ORDER_DELIVER) 
    {
        save_Deliver(cur_orders[index].data.deliver);
    }
}
    
void my_accept_order(int user_pos) 
{
    draw_my_accept();
    mouse_on_arrow(mouse);

    while (1) {
        mouse_show_arrow(&mouse);
        if(mouse_press(122, 50, 242, 100)==1) //����
        {
         
            return;
			//my_information(users.pos);
		}
        else if(mouse_press(342, 50, 462, 100)==1) //�ӵ�
        {
            press3(1);//��ť����
            mouse_off_arrow(&mouse);
            accept_order(user_pos);//�ӵ�ҳ��
            //return����⿪ʼ
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // ����
            draw_my_accept();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(562, 50, 682, 100)==1) //·��
        {
            press3(2); //��ť����
            mouse_off_arrow(&mouse);
            route(cur_orders,num_of_orders.cur_count,user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); 
            draw_my_accept();  
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //�ҵ�
        {
            press3(3); //��ť����
            mouse_off_arrow(&mouse);
            my_information(user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); 
            draw_my_accept();  
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 276, 160, 326) == 1)
        {
            press4(1);
            my_information(user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_my_accept();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 602, 160, 652) == 1)
        {
            press4(3);
            my_history_order(user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_my_accept();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(750, 195, 850, 245) == 1) //�������1����
        {
            my_accept_detail(0,user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 
            draw_my_accept();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(750, 315, 850, 365)==1) //�������2����
        {
            my_accept_detail(1,user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); //
            draw_my_accept();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(750, 435, 850, 485) == 1) //�������3����
        {
            my_accept_detail(2,user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 
            draw_my_accept();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(750, 555, 850, 605) == 1) //�������4����
        {
            my_accept_detail(3,user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 
            draw_my_accept();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(875, 195, 975, 245) == 1) //���ȡ������1
        {
            delete_my_order(0);
            //ɾ��������ҵĵ�ǰ�б�
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 
            draw_my_accept();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(875, 315, 975, 365)==1) //���ȡ������2
        {
            delete_my_order(1);
            //ɾ��������ҵĵ�ǰ�б�
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); //
            draw_my_accept();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(875, 435, 975, 485) == 1) //���ȡ������3
        {
            delete_my_order(2);
            //ɾ��������ҵĵ�ǰ�б�
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 
            draw_my_accept();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(875, 555, 975, 605) == 1) //���ȡ������4
        {
            delete_my_order(3);
            //ɾ��������ҵĵ�ǰ�б�
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 
            draw_my_accept();
            mouse_on_arrow(mouse);
        }
    }
}

void draw_my_accept() 
{
    int y_offset = 170;
    char pick_up[100], dest[100], distance_str[50], price_str[50];
    int distance_m;
    float dist_km, amount, fee;
    int i;
    char debg[20];
    bar1(200, 150, 1024, 768, white);
    sprintf(debg,"%d",num_of_orders.cur_count);
    PrintText(150, 100, debg, HEI, 24, 1, Red);

    for (i = 0; i < num_of_orders.cur_count; i++) {
        AcceptedOrder *ao = &cur_orders[i]; 
        // ����
        Draw_Rounded_Rectangle(220, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

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
                int pu   = ao->data.food.pick_up_location;
                int dst  = ao->data.food.destination;
                amount   = ao->data.food.total_amount;

                sprintf(pick_up, "ȡ�͵㣺%s", node[pu].name);
                sprintf(dest,    "Ŀ�ĵأ�%s", node[dst].name);
                distance_m = dijkstra(&node[pu], &node[dst], 3);
                break;
            }
            case ORDER_DELIVER: {
                int pu   = ao->data.deliver.station+408;
                int dst  = ao->data.deliver.index;
                amount   = 2.0f;

                sprintf(debg,"deliver_station=%d",pu);
                PrintText(200, 50, debg, HEI, 24, 1, 0x0000);
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

void cut_current_order(int index) //���б���ɾ��ĳ������
{
    int i;
    for ( i = index; i < num_of_orders.cur_count - 1; i++) 
    {
        cur_orders[i] = cur_orders[i+1];//����Ķ�����ǰ��ĸ���
        route_state.picked[i]   = route_state.picked[i+1];// ͬ���ƶ� picked[] / delivered[] ����
        route_state.delivered[i]= route_state.delivered[i+1];
    }
    num_of_orders.cur_count--; 
}

