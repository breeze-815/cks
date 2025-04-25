#include "all_func.h"

#define ORDERS_PER_PAGE   4     
#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

void draw_order_detail_header(int type, int local_index,OrderList *OL, FoodList *FL, DeliverList *DL) 
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
        Order *o = &OL->elem[local_index]; 
        sprintf(time_str, "�µ�ʱ�䣺%s", o->order_time);
        sprintf(phone_str, "�ֻ��ţ�%s", o->user_phone);
        // ȡ����
        sprintf(buf, "ȡ���㣺%s", node[o->pick_up_location].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // �û���ַ
        sprintf(buf, "�û���ַ��%s", node[o->destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        // ����
        distance_m = dijkstra(&node[o->pick_up_location], &node[o->destination],3); // �������
        distance_km = distance_m / 1000.0; // ת��Ϊ����
        sprintf(show_distance, "���룺%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, 0x0000);

        item_price = o->total_amount; // ��ȡ��Ʒ�۸�
        deliver_price = rider_deliver_price(distance_m, item_price); // �������ͷ���
        sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, 0x0000);

    }
    else if (type == ORDER_FOOD) 
    {
        FoodOrder *f = &FL->elem[local_index];
        sprintf(time_str, "�µ�ʱ�䣺%s", f->order_time);
        sprintf(phone_str, "�ֻ��ţ�%s", f->user_phone);
        // ȡ�͵�
        sprintf(buf, "ȡ���㣺%s", node[f->station].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // �û���ַ
        sprintf(buf, "�û���ַ��%s", node[f->destination].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //����
        distance_m = dijkstra(&node[f->station], &node[f->destination],3); // �������
        distance_km = distance_m / 1000.0; // ת��Ϊ����
        sprintf(show_distance, "���룺%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, 0x0000);

        item_price = f->total_amount; // ��ȡ��Ʒ�۸�
        deliver_price = rider_deliver_price(distance_m, item_price); // �������ͷ���
        sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, 0x0000);
    }
    else if (type == ORDER_DELIVER) 
    {
        Deliver *d = &DL->elem[local_index];
        sprintf(time_str, "�µ�ʱ�䣺%s", d->time);
        sprintf(phone_str, "�ֻ��ţ�%s", d->number);
        // ȡ����
        sprintf(buf, "ȡ���㣺%s", node[d->station].name);
        PrintText(200, 150 + 150, buf, HEI, 24, 1, black);
        // �û���ַ
        sprintf(buf, "�û���ַ��%s", node[d->index].name);
        PrintText(500, 150 + 150, buf, HEI, 24, 1, black);
        //����
        distance_m = dijkstra(&node[d->station], &node[d->index],3); // �������
        distance_km = distance_m / 1000.0; // ת��Ϊ����
        sprintf(show_distance, "���룺%.2fkm", distance_km);
        PrintText(200, 200 + 150, show_distance, HEI, 24, 1, 0x0000);

        item_price = 2.0; // ��ȡ��Ʒ�۸�
        deliver_price = rider_deliver_price(distance_m, item_price); // �������ͷ���
        sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
        PrintText(500, 200+150, show_deliver_price, HEI, 24, 1, 0x0000);
    }
    // ��ӡͨ���ֶΣ����ƫ�ƣ�
    PrintText(200, 50  + 150, time_str, HEI, 24, 1, black);
    PrintText(200, 100 + 150, phone_str, HEI, 24, 1, black);
}

void draw_order_detail(int type,OrderList *OL, FoodList *FL, DeliverList *DL,
    int local_index, int page) 
{
    int i;
    Order currentOrder ; 
    FoodOrder currentFood;

    char current_time[20]; // ��ȡ��ǰʱ��
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
    char total_str[20]; // �ܽ���ַ���
    int fullPageItemCount = 0; // ��ҳ��Ʒ����
    
    bar1(0, 150, 1024, 768, white);// ������ҳ������ 0,150 �� 1024,768 ����

    currentOrder = OL->elem[local_index]; // ��ǰ����
    currentFood = FL->elem[local_index]; // ��ǰ����

    // ��ҳ��ť�����к��������ͣ�
    if (type != ORDER_DELIVER) {
        Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue);
        PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
        Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue);
        PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);
    }

    // �ӵ���ť
    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue);
    PrintCC(850, 715, "�ӵ�", HEI, 24, 1, deepblue);

    
    // ��һҳ����ͷ��
    if(page==0&&type!=ORDER_DELIVER)
    {
        draw_order_detail_header(type, local_index, OL, FL, DL);

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
        draw_order_detail_header(type, local_index, OL, FL, DL);
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
        Deliver *d = &DL->elem[local_index];
        sprintf(code_buf, "ȡ���룺%s", d->code);
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

//�������Ӷ�������
void show_order_detail(int local_index, int type, int user_pos) 
{
    OrderList OL = {0};
    FoodList FL = {0};
    DeliverList DL = {0};
    int page = 0;
    int totalPage = 1;
    
    ReadAllOrder(&OL);
    ReadAllFood(&FL);
    ReadAllDeliver(&DL);

    // ������ҳ��//��һҳ4�����ڶ�ҳ����9��
    if (type == ORDER_SUPERMARKET) {
        totalPage = (OL.elem[local_index].itemCount - 4 + 8) / 9 + 1;
    } else if (type == ORDER_FOOD) {
        totalPage = (FL.elem[local_index].itemCount - 4 + 8) / 9 + 1;
    }
    // ORDER_DELIVER ���� totalPage=0

    // ���ƶ�������
    draw_order_detail(type, &OL, &FL, &DL, local_index, page);

    mouse_on_arrow(mouse);
    while (1) {
        mouse_show_arrow(&mouse);
        // ���ذ�ť������λ��ͬԭ����
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
            DestroyOList(&OL); // �ͷŶ����б��ڴ�
            DestroyFList(&FL); // �ͷ�ʳƷ�б��ڴ�
            DestroyDList(&DL); // �ͷſ���б��ڴ�
            route(cur_orders,num_of_orders.cur_count,user_pos);//����·�߹滮
            //return����⿪ʼ
            ReadAllOrder(&OL);
            ReadAllFood(&FL);
            ReadAllDeliver(&DL);
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_accept_order(page,&OL,&FL,&DL); // ���»��ƶ����б�
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //�ҵ�
        {
            press3(3); //��ť����
            press4(1);
            DestroyOList(&OL); // �ͷŶ����б��ڴ�
            DestroyFList(&FL); // �ͷ�ʳƷ�б��ڴ�
            DestroyDList(&DL); // �ͷſ���б��ڴ�
            my_information(user_pos);//�����ҵ���Ϣ����
            //return����⿪ʼ
            ReadAllOrder(&OL);
            ReadAllFood(&FL);
            ReadAllDeliver(&DL);
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); 
            draw_rider();
            mouse_on_arrow(mouse);
        }
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_order_detail(type, &OL, &FL, &DL, local_index, page);
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
				draw_order_detail(type, &OL, &FL, &DL, local_index, page);
			} else {
				// ��ʾ���������һҳ
				PrintCC(630, 715, "�������һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(630, 715, 780, 765, white);
			}
		}
    }
}
