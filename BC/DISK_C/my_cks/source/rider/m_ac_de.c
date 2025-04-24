#include "all_func.h"

#define ORDERS_PER_PAGE   4     
#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

void draw_my_order_detail_body(int type, int index)
{
    char buf[128];
    // ͨ�ã��µ�ʱ�䡢�ֻ���
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
        sprintf(time_str, "�µ�ʱ�䣺%s", cur_orders[index].data.order.order_time);
        sprintf(phone_str, "�ֻ��ţ�%s", cur_orders[index].data.order.user_phone);
        // ȡ����
        sprintf(buf, "ȡ���㣺%s", node[cur_orders[index].data.order.pick_up_location].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // �û���ַ
        sprintf(buf, "�û���ַ��%s", node[cur_orders[index].data.order.destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        // ����
        distance_m = dijkstra(&node[cur_orders[index].data.order.pick_up_location], &node[cur_orders[index].data.order.destination],3); // �������
        distance_km = distance_m / 1000.0; // ת��Ϊ����
        sprintf(show_distance, "���룺%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, black);

        item_price = cur_orders[index].data.order.total_amount; // ��ȡ��Ʒ�۸�
        deliver_price = rider_deliver_price(distance_m, item_price); // �������ͷ���
        cur_orders[index].deliver_price=deliver_price; //���˵����ͷѴ���ṹ����
        sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, black);

    }
    else if (type == ORDER_FOOD) 
    {
        
        sprintf(time_str, "�µ�ʱ�䣺%s", cur_orders[index].data.food.order_time);
        sprintf(phone_str, "�ֻ��ţ�%s", cur_orders[index].data.food.user_phone);
        // ȡ�͵�
        sprintf(buf, "ȡ���㣺%s", node[cur_orders[index].data.food.pick_up_location].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // �û���ַ
        sprintf(buf, "�û���ַ��%s", node[cur_orders[index].data.food.destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //����
        distance_m = dijkstra(&node[cur_orders[index].data.food.pick_up_location], &node[cur_orders[index].data.food.destination],3); // �������
        distance_km = distance_m / 1000.0; // ת��Ϊ����
        sprintf(show_distance, "���룺%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, black);

        item_price = cur_orders[index].data.order.total_amount; // ��ȡ��Ʒ�۸�
        deliver_price = rider_deliver_price(distance_m, item_price); // �������ͷ���
        cur_orders[index].deliver_price=deliver_price;
        sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, black);
    }
    else if (type == ORDER_DELIVER) 
    {
        sprintf(time_str, "�µ�ʱ�䣺%s", cur_orders[index].data.deliver.time);
        sprintf(phone_str, "�ֻ��ţ�%s", cur_orders[index].data.deliver.number);
        // ȡ����
        sprintf(buf, "ȡ���㣺%s", node[cur_orders[index].data.deliver.station].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // �û���ַ
        sprintf(buf, "�û���ַ��%s", node[cur_orders[index].data.deliver.destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //����
        distance_m = dijkstra(&node[cur_orders[index].data.deliver.station], &node[cur_orders[index].data.deliver.destination],3); // �������
        distance_km = distance_m / 1000.0; // ת��Ϊ����
        sprintf(show_distance, "���룺%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, 0x0000);

        item_price = 2.0; // ��ȡ��Ʒ�۸�
        deliver_price = rider_deliver_price(distance_m, item_price); // �������ͷ���
        cur_orders[index].deliver_price=deliver_price;
        sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, 0x0000);
    }
    // ��ӡͨ���ֶΣ����ƫ�ƣ�
    PrintText(200, 50  + 150, time_str, HEI, 24, 1, black);
    PrintText(200, 100 + 150, phone_str, HEI, 24, 1, black);
}


//δ��
//����ҳ����չʾ�����������ݣ�ֻ�г��к�����������
// void draw_my_order_items(int type, int index)
// {
//     int i;
//     int page=0;
//     int start;
//     int end; 
//     int y = 500;  // �������ʼƫ����
//     char name_buf[64], qty_buf[32], price_buf[32];
    
//     start = page * ORDERS_PER_PAGE;
//     end = start + ORDERS_PER_PAGE;
//     if (type == ORDER_SUPERMARKET) 
//     {
//         Order *o = &OL->elem[local_index];
        
//         if (end > o->itemCount) //��ֹԽ��
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
    
    int type;
    type=cur_orders[index].type;
    
    draw_my_order_detail(type, index);

    mouse_on_arrow(mouse);
    while (1) 
    {
        mouse_show_arrow(&mouse);
        // ���ذ�ť
        if(mouse_press(122, 50, 242, 100)==1) //����
        {
            return;
			//my_accept_order(users.pos);
		}
        else if(mouse_press(562, 50, 682, 100)==1) //·��
        {
            press3(2); //��ť����
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); 
            route(cur_orders, num_of_orders.cur_count,user_pos);//����·�߹滮
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); 
            draw_my_order_detail(type, index);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //�ҵ�
        {
            press3(3); //��ť����
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); 
            my_information(user_pos);
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white);  
            draw_my_order_detail(type, index);
        }
        
    }
}

void draw_my_order_detail(int type,int index) 
{
    // ����
    bar1(0, 150, 1024, 768, white);


    // �������岿��
    draw_my_order_detail_body(type, index);

    if (type == ORDER_DELIVER) //�����ǿ�ݴ�ȡ
    {
        // ֻ����չʾȡ����
        char code_buf[64];
        sprintf(code_buf, "ȡ���룺%s",cur_orders[index].data.deliver.code);//��ȡ�˵���ȡ������ʾ
        PrintText(250, 400 + 150, code_buf, HEI, 32, 1, black);
    } 
    else //�����ǳ�����������
    {
        // �����嵥��ͷ
        PrintCC(200, 330 + 150, "��Ʒ����", HEI, 24, 1, black);
        PrintCC(650, 330 + 150, "����", HEI, 24, 1, black);
        PrintCC(800, 330 + 150, "���", HEI, 24, 1, black);
        PrintText(150, 350 + 150, "------------------------------------", HEI, 32, 1, black);
        // �嵥�б�
        //draw_my_order_items(type, cur_orders[index]);
    }
}




