#include <all_func.h>

#define MAX_ACCEPTED_ORDERS 4
#define ORDERS_PER_PAGE   4

#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

AcceptedOrder hst_orders[10]={0};

void my_history_order(int user_pos)
{   
    int page = 0;
    int type, local, global;
    mouse_off_arrow(&mouse);
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
            mouse_off_arrow(&mouse);
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
            press3(3);
            press4(3);
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
            press3(3);
            press4(3);
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
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_my_history_order(); // ���»��ƶ����б�
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 276, 160, 326) == 1) //��Ϣ
        {
            press4(1);
            my_information(user_pos);
            //return����⿪ʼ
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); //����
            draw_my_accept();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 439, 160, 489) == 1) //��ǰ
        {
            press4(2);
            my_accept_order(user_pos);
            //return����⿪ʼ
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 602, 160, 652) == 1) //��ʷ
        {
            press4(3);
            my_history_order(user_pos);
            //return����⿪ʼ
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(750, 195, 850, 245) == 1) //�������1����
        {
            my_history_detail(0,user_pos);
            //return����⿪ʼ
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            //bar1(0, 150, 200, 768, white); // 
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(750, 315, 850, 365)==1) //�������2����
        {
            my_history_detail(1,user_pos);
            //return����⿪ʼ
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            //bar1(0, 150, 200, 768, white); //
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(750, 435, 850, 485) == 1) //�������3����
        {
            my_history_detail(2,user_pos);
            //return����⿪ʼ
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            //bar1(0, 150, 200, 768, white); // 
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(750, 555, 850, 605) == 1) //�������4����
        {
            my_history_detail(3,user_pos);
            //return����⿪ʼ
            press3(3);
            press4(3);
            mouse_on_arrow(mouse);
            //bar1(0, 150, 200, 768, white); // 
            draw_my_history_order();
            mouse_on_arrow(mouse);
        }
    }
}

void move_to_history(AcceptedOrder cur_orders[], int order_idx) 
{
    int j;
    if (num_of_orders.hst_count < 10 && num_of_orders.cur_count >= 0 && order_idx < num_of_orders.cur_count) \
    {
        // ���Ƶ���ʷ�б�ĩβ
        hst_orders[num_of_orders.hst_count++] = cur_orders[order_idx];
        // �� cur_orders ���Ƴ�������Ԫ��ǰ��
        for ( j = order_idx; j < num_of_orders.cur_count - 1; j++) 
            cur_orders[j] = cur_orders[j + 1];
        num_of_orders.cur_count--;
    }
}

void draw_my_history_order()
{
    int y_offset = 170;
    char pick_up[100], dest[100], distance_str[50], price_str[50];
    int distance_m;
    float dist_km, amount, fee;
    int i;
    //char debg[20];
    bar1(200, 150, 1024, 768, white);
    //sprintf(debg,"%d",num_of_orders.hst_count);
    //PrintText(0,  0, debg, HEI, 24, 1, BLACK);
    if (num_of_orders.hst_count == 0)
    PrintCC(450,400,"��ǰ����ʷ����",HEI,32,1,Red);
    else
    {
        for (i = 0; i < num_of_orders.hst_count; i++) 
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
                    int pu   = ho->data.food.station;
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
    
}

void draw_my_history_detail_body(int type, int index)
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
        sprintf(time_str, "�µ�ʱ�䣺%s", hst_orders[index].data.order.order_time);
        sprintf(phone_str, "�ֻ��ţ�%s", hst_orders[index].data.order.user_phone);
        // ȡ����
        sprintf(buf, "ȡ���㣺%s", node[hst_orders[index].data.order.pick_up_location].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // �û���ַ
        sprintf(buf, "�û���ַ��%s", node[hst_orders[index].data.order.destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        // ����
        distance_m = dijkstra(&node[hst_orders[index].data.order.pick_up_location], &node[hst_orders[index].data.order.destination],3); // �������
        distance_km = distance_m / 1000.0; // ת��Ϊ����
        sprintf(show_distance, "���룺%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, black);

        item_price = hst_orders[index].data.order.total_amount; // ��ȡ��Ʒ�۸�
        deliver_price = rider_deliver_price(distance_m, item_price); // �������ͷ���
        hst_orders[index].deliver_price=deliver_price; //���˵����ͷѴ���ṹ����
        sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, black);

    }
    else if (type == ORDER_FOOD) 
    {
        
        sprintf(time_str, "�µ�ʱ�䣺%s", hst_orders[index].data.food.order_time);
        sprintf(phone_str, "�ֻ��ţ�%s", hst_orders[index].data.food.user_phone);
        // ȡ�͵�
        sprintf(buf, "ȡ���㣺%s", node[hst_orders[index].data.food.station].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // �û���ַ
        sprintf(buf, "�û���ַ��%s", node[hst_orders[index].data.food.destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //����
        distance_m = dijkstra(&node[hst_orders[index].data.food.station], &node[hst_orders[index].data.food.destination],3); // �������
        distance_km = distance_m / 1000.0; // ת��Ϊ����
        sprintf(show_distance, "���룺%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, black);

        item_price = hst_orders[index].data.order.total_amount; // ��ȡ��Ʒ�۸�
        deliver_price = rider_deliver_price(distance_m, item_price); // �������ͷ���
        hst_orders[index].deliver_price=deliver_price;
        sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, black);
    }
    else if (type == ORDER_DELIVER) 
    {
        sprintf(time_str, "�µ�ʱ�䣺%s", hst_orders[index].data.deliver.time);
        sprintf(phone_str, "�ֻ��ţ�%s", hst_orders[index].data.deliver.number);
        // ȡ����
        sprintf(buf, "ȡ���㣺%s", node[hst_orders[index].data.deliver.station].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // �û���ַ
        sprintf(buf, "�û���ַ��%s", node[hst_orders[index].data.deliver.destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //����
        distance_m = dijkstra(&node[hst_orders[index].data.deliver.station], &node[hst_orders[index].data.deliver.destination],3); // �������
        distance_km = distance_m / 1000.0; // ת��Ϊ����
        sprintf(show_distance, "���룺%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, 0x0000);

        item_price = 2.0; // ��ȡ��Ʒ�۸�
        deliver_price = rider_deliver_price(distance_m, item_price); // �������ͷ���
        hst_orders[index].deliver_price=deliver_price;
        sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, 0x0000);
    }
    // ��ӡͨ���ֶΣ����ƫ�ƣ�
    PrintText(200, 50  + 150, time_str, HEI, 24, 1, black);
    PrintText(200, 100 + 150, phone_str, HEI, 24, 1, black);
}

void my_history_detail(int index , int user_pos) 
{
    OrderList OL = {0};
    FoodList FL = {0};
    int page = 0;
    int totalPage = 1;
    
    int type;
    type=hst_orders[index].type;

    ReadAllOrder(&OL); // ��ȡ�����б�
    ReadAllFood(&FL); // ��ȡʳƷ�б�

    // ������ҳ��//��һҳ4�����ڶ�ҳ����9��
    if (type == ORDER_SUPERMARKET) {
        totalPage = (OL.elem[index].itemCount - 4 + 8) / 9 + 1;
    } else if (type == ORDER_FOOD) {
        totalPage = (FL.elem[index].itemCount - 4 + 8) / 9 + 1;
    }
    // ORDER_DELIVER ���� totalPage=0

    DestroyOList(&OL); // �ͷſ���б��ڴ�
    DestroyFList(&FL); // �ͷ�ʳƷ�б��ڴ�
    
    draw_my_history_detail(type, index,page);

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
            draw_my_history_detail(type, index,page);
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
            draw_my_history_detail(type, index,page);
        }
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_my_history_detail(type, index,page);
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
				draw_my_history_detail(type, index,page);
			} else {
				// ��ʾ���������һҳ
				PrintCC(630, 715, "�������һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(630, 715, 780, 765, white);
			}
		}
        
    }
    
}


void draw_my_history_detail(int type,int index,int page) 
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

    currentOrder = hst_orders[index].data.order; // ��ǰ����
    currentFood = hst_orders[index].data.food; // ��ǰ����
    currentDeliver = hst_orders[index].data.deliver; // ��ǰ��� 

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
        draw_my_history_detail_body(type, index);

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
        draw_my_history_detail_body(type, index);
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