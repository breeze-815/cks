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
        sprintf(buf, "ȡ���㣺%s", node[cur_orders[index].data.food.station].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // �û���ַ
        sprintf(buf, "�û���ַ��%s", node[cur_orders[index].data.food.destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //����
        distance_m = dijkstra(&node[cur_orders[index].data.food.station], &node[cur_orders[index].data.food.destination],3); // �������
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

void my_accept_detail(int index , int user_pos) 
{
    OrderList OL = {0};
    FoodList FL = {0};
    int page = 0;
    int totalPage = 1;
    
    int type;
    type=cur_orders[index].type;

    //ReadAllOrder(&OL); // ��ȡ�����б�
    //ReadAllFood(&FL); // ��ȡʳƷ�б�

    // ������ҳ��//��һҳ4�����ڶ�ҳ����9��
    if (type == ORDER_SUPERMARKET) {
        totalPage = (OL.elem[index].itemCount - 4 + 8) / 9 + 1;
    } else if (type == ORDER_FOOD) {
        totalPage = (FL.elem[index].itemCount - 4 + 8) / 9 + 1;
    }
    // ORDER_DELIVER ���� totalPage=0

    DestroyOList(&OL); // �ͷſ���б��ڴ�
    DestroyFList(&FL); // �ͷ�ʳƷ�б��ڴ�
    
    draw_my_order_detail(type, index,page);

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
            draw_my_order_detail(type, index,page);
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
            draw_my_order_detail(type, index,page);
        }
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_my_order_detail(type, index,page);
            } else {
                // ��ʾ�����ǵ�һҳ
                PrintCC(630, 715, "���ǵ�һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(630, 715, 780, 765, white);
            }
        }
		else if (mouse_press(420, 700, 540, 750) == 1) 
		{
			if (page < totalPage - 1) {
				page++;
				draw_my_order_detail(type, index,page);
			} else {
				// ��ʾ���������һҳ
				PrintCC(630, 715, "�������һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(630, 715, 780, 765, white);
			}
		}
        
    }
}

void draw_my_order_detail(int type,int index,int page) 
{
    int i;
    Order currentOrder ; 
    FoodOrder currentFood;
    Deliver currentDeliver;

    char current_time[100]; // ��ȡ��ǰʱ��
    char time_str[100]; // ��ӡ�µ�ʱ��
    char user_name[100]; // ��ӡ�û���
    char user_phone[100]; // ��ӡ�û��ֻ���
    char order_number; // ��ӡ������
    char address[100]; // ��ӡ�û���ַ
    int startIdx = 0;// ��ʼ��Ʒ����
    int itemsPerPage = 0;// ÿҳ��Ʒ����
    int endIdx = 0;// ������Ʒ����
    int item_y = 0;// ��Ʒ���y����

    float total_amount = 0.0; // �ܽ��
    char total_str[100]; // �ܽ���ַ���
    int fullPageItemCount = 0; // ��ҳ��Ʒ����
    // ����
    bar1(0, 150, 1024, 768, white);

    currentOrder = cur_orders[index].data.order; // ��ǰ����
    currentFood = cur_orders[index].data.food; // ��ǰ����
    currentDeliver = cur_orders[index].data.deliver; // ��ǰ��� 

    // �������岿��
    

    // ��ҳ��ť�����к��������ͣ�
    if (type != ORDER_DELIVER) {
        Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue);
        PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
        Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue);
        PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);
    }

    // ��һҳ����ͷ��
    if(page==0&&type!=ORDER_DELIVER)
    {
        draw_my_order_detail_body(type, index);

        // ��ͷ
        PrintCC(200, 400, "��Ʒ����", HEI, 24, 1, black);
        PrintCC(650, 400, "����", HEI, 24, 1, black);
        PrintCC(800, 400, "���", HEI, 24, 1, black);
        PrintText(200, 420, "-------------------------------", HEI, 32, 1, black); 

        startIdx = 0;
        itemsPerPage = 4;//��һҳ4�����ڶ�ҳ����9��
    }
    else if(page==0&&type==ORDER_DELIVER)
    {
        draw_my_order_detail_body(type, index);
    }
    else // ����ҳ
    {
        startIdx = 4 + (page - 1) * 9;
        itemsPerPage = 9;
    }

    endIdx = startIdx + itemsPerPage;

    if (type == ORDER_DELIVER) {
        // ֻչʾȡ����
        char code_buf[64];
        sprintf(code_buf, "ȡ���룺%s", currentDeliver.code);
        PrintText(200, 400, code_buf, HEI, 32, 1, black);
    } else {
        

        if (type == ORDER_SUPERMARKET)//���ж���
        {
            if (endIdx > currentOrder.itemCount)// ��ֹԽ��
                endIdx = currentOrder.itemCount;
        }
        else if(type==ORDER_FOOD)//ʳ�ö���
        {
            if (endIdx > currentFood.itemCount)// ��ֹԽ��
                endIdx = currentFood.itemCount;
        }

        item_y = (page == 0) ? 450 : 200;
        for (i = startIdx; i < endIdx; i++) {
            char total_str[100]; // ��Ʒ�ܼ�
            char quantity_str[100]; // ��Ʒ����

            if(type == ORDER_SUPERMARKET)//���ж���
            {
                int quantity = currentOrder.item[i].quantity; // ��Ʒ����
                float price = currentOrder.item[i].price; // ��Ʒ�۸�

                sprintf(total_str, "%.2f", price * quantity);
                sprintf(quantity_str, "x%d", quantity);

                PrintCC(200, item_y, currentOrder.item[i].name, HEI, 24, 1, black); // ��Ʒ��
            }
            else if(type==ORDER_FOOD)//ʳ�ö���
            {
                int quantity = currentFood.item[i].quantity; // ��Ʒ����
                float price = currentFood.item[i].price; // ��Ʒ�۸�

                sprintf(total_str, "%.2f", price * quantity);
                sprintf(quantity_str, "x%d", quantity);

                PrintCC(200, item_y, currentFood.item[i].name, HEI, 24, 1, black); // ��Ʒ��
            }
            
            PrintText(650, item_y, (unsigned char*)quantity_str, HEI, 24, 1, black);// ��Ʒ����
            PrintText(800, item_y, (unsigned char*)total_str, HEI, 24, 1, black);// ��Ʒ�ܼ�

            item_y += 50;
        }

        // �ж��Ƿ���Ҫ�ڴ�ҳ��ʾ�ܽ���ǰҳû������
        fullPageItemCount = (page == 0) ? 4 : 9;// ��һҳ��ʾ4����Ʒ������ҳ��ʾ9����Ʒ

        if (type == ORDER_SUPERMARKET)
        {
            if ((endIdx - startIdx) < fullPageItemCount||endIdx==currentOrder.itemCount) {// ��ǰҳ��Ʒ��������һҳ�����һ����Ʒ�պ���ҳ��Ҫ��ӡ���ܽ��
                //����������һ����Ʒ������ҳ�Ͳ���ӡ�ܽ��
                // ��ӡ�ָ���
                PrintText(200, item_y - 30, "-------------------------------", HEI, 32, 1, black);
        
                // �����ܽ��
                total_amount = 0.0;
                for (i = 0; i < currentOrder.itemCount; i++) {
                    int quantity = currentOrder.item[i].quantity; // ��Ʒ����
                    float price = currentOrder.item[i].price; // ��Ʒ�۸�
                    total_amount += price * quantity;
                }
        
                sprintf(total_str, "�ܽ�%.2f Ԫ", total_amount);
                PrintText(650, item_y + 10, total_str, HEI, 24, 1, black);
            
            }
        }
        else 
        {
            if ((endIdx - startIdx) < fullPageItemCount||endIdx==currentFood.itemCount) {// ��ǰҳ��Ʒ��������һҳ�����һ����Ʒ�պ���ҳ��Ҫ��ӡ���ܽ��
                //����������һ����Ʒ������ҳ�Ͳ���ӡ�ܽ��
                // ��ӡ�ָ���
                PrintText(200, item_y - 30, "-------------------------------", HEI, 32, 1, black);
        
                // �����ܽ��
                total_amount = 0.0;
                for (i = 0; i < currentFood.itemCount; i++) {
                    int quantity = currentFood.item[i].quantity; // ��Ʒ����
                    float price = currentFood.item[i].price; // ��Ʒ�۸�
                    total_amount += price * quantity;
                }
        
                sprintf(total_str, "�ܽ�%.2f Ԫ", total_amount);
                PrintText(750, item_y + 10, total_str, HEI, 24, 1, black);
            
            }
        }
    }
}




