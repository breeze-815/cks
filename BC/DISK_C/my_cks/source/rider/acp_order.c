#include  <all_func.h>

#define MAX_COMBINED_ORDERS 20
#define ORDERS_PER_PAGE   4

#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

void accept_order() // 
{
    int page = 0; // ��ǰҳ��
    int clicked;
    int order_index;
    int total_cnt; // ��������
    OrderList OL = {0};
    FoodList FL = {0};
    DeliverList DL = {0};

    ReadAllDeliver(&DL); // ��ȡ����б�
    ReadAllOrder(&OL); // ��ȡ�����б�
    ReadAllFood(&FL); // ��ȡʳƷ�б�

    total_cnt = OL.length + FL.length + DL.length; // ���㶩������
    mouse_off_arrow(&mouse);
	
	draw_accept_order(page,&OL,&FL,&DL,total_cnt); // ���ƽӵ�ҳ��

	mouse_on_arrow(mouse);

	while(1){
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
            draw_accept_order(page,&OL,&FL,&DL,total_cnt); // ���»��ƶ����б�
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //�˻�
        {
            press3(3); //��ť����
        }
        else if (mouse_press(220, 700, 340, 750) == 1) // ��һҳ
		{
            if (page > 0) {
                page--;
                draw_accept_order(page,&OL,&FL,&DL,total_cnt); // �����û�����ҳ��
            } else {
                // ��ʾ�����ǵ�һҳ
                PrintCC(550, 700, "���ǵ�һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 700, 700, 750, white);
            }
        }
        else if (mouse_press(420, 700, 540, 750) == 1)  // ��һҳ
		{
			if ((page + 1) * 5 < total_cnt) 
            {
				page++;
                draw_accept_order(page,&OL,&FL,&DL,total_cnt);
			} 
            else {
				// ��ʾ���������һҳ
				PrintCC(550, 700, "�������һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 700, 700, 750, white);
			}
		}
        
        else if (mouse_press(750, 170 + 25, 850, 170 + 75) == 1) {
            int type, local_index;
            int global_index = page * ORDERS_PER_PAGE + 0;
            if (global_index < total_cnt) {
                if (global_index < OL.length) {
                    type = ORDER_SUPERMARKET; local_index = global_index;
                } else if (global_index < OL.length + FL.length) {
                    type = ORDER_FOOD; local_index = global_index - OL.length;
                } else {
                    type = ORDER_DELIVER; local_index = global_index - OL.length - FL.length;
                }
                accept_order_detail(local_index, type,total_cnt);
                bar1(0,150,1024,768,white); draw_accept_order(page,&OL,&FL,&DL,total_cnt);
            }
        }
        // ��2�����鰴ť��x[750,850], y[290+25,290+75]
        else if (mouse_press(750, 290 + 25, 850, 290 + 75) == 1) {
            int type, local_index;
            int global_index = page * ORDERS_PER_PAGE + 1;
            if (global_index < total_cnt) {
                
                if (global_index < OL.length) {
                    type = ORDER_SUPERMARKET; local_index = global_index;
                } else if (global_index < OL.length + FL.length) {
                    type = ORDER_FOOD; local_index = global_index - OL.length;
                } else {
                    type = ORDER_DELIVER; local_index = global_index - OL.length - FL.length;
                }
                accept_order_detail(local_index, type,total_cnt);
                bar1(0,150,1024,768,white); draw_accept_order(page,&OL,&FL,&DL,total_cnt);
            }
        }
        // ��3�����鰴ť��x[750,850], y[410+25,410+75]
        else if (mouse_press(750, 410 + 25, 850, 410 + 75) == 1) {
            int type, local_index;
            int global_index = page * ORDERS_PER_PAGE + 2;
            if (global_index < total_cnt) {
                
                if (global_index < OL.length) {
                    type = ORDER_SUPERMARKET; local_index = global_index;
                } else if (global_index < OL.length + FL.length) {
                    type = ORDER_FOOD; local_index = global_index - OL.length;
                } else {
                    type = ORDER_DELIVER; local_index = global_index - OL.length - FL.length;
                }
                accept_order_detail(local_index, type,total_cnt);
                bar1(0,150,1024,768,white); draw_accept_order(page,&OL,&FL,&DL,total_cnt);
            }
        }
        // ��4�����鰴ť��x[750,850], y[530+25,530+75]
        else if (mouse_press(750, 530 + 25, 850, 530 + 75) == 1) {
            int type, local_index;
            int global_index = page * ORDERS_PER_PAGE + 3;
            if (global_index < total_cnt) {
                
                if (global_index < OL.length) {
                    type = ORDER_SUPERMARKET; local_index = global_index;
                } else if (global_index < OL.length + FL.length) {
                    type = ORDER_FOOD; local_index = global_index - OL.length;
                } else {
                    type = ORDER_DELIVER; local_index = global_index - OL.length - FL.length;
                }
                accept_order_detail(local_index, type,total_cnt);
                bar1(0,150,1024,768,white); draw_accept_order(page,&OL,&FL,&DL,total_cnt);
            }
        }
    }
}
    
double rider_deliver_price(int distance_m, float order_amount) 
{
    const double price_per_km   = 0.5;   // ÿ�������ͷѣ�Ԫ��
    const double base_price     = 2.0;   // �𲽼ۣ�Ԫ��
    const double price_ratio    = 0.05;  // ��Ʒ��� 5% �Ӽ�

    // �� �� ����ø�������
    double dist_km = (double)distance_m / 1000.0;

    // �����ܷ�
    double total = base_price
                    + dist_km * price_per_km
                    + order_amount * price_ratio;

    return total;
}

void draw_accept_order(int page, OrderList *OL, FoodList *FL, DeliverList *DL ,int total_cnt) // ���ƽӵ�ҳ��
{
    int i,j;
    int cnt = 0;
    int y_offset = 170; // ��ʼY��ƫ��

    int start_index = page * 4; // ��ǰҳ����ʼ��������
    int end_index = start_index + 4; // ��ǰҳ�Ľ�����������

    if (end_index > total_cnt) 
        {
            end_index = total_cnt; // ��ֹԽ��
        }
    
    bar1(0, 150, 1024, 768, white); // �����Ļ

    // ���ƶ���
    for (i = start_index; i < end_index; i++) {

        char show_pick_up[20]; // ȡ�͵ص�
        char show_destination[20]; // Ŀ�ĵ�
        char show_distance[20]; // ����
        char show_deliver_price[20]; // ���ͷ���

        int distance_m; // ����
        float distance_km; // ����
        float item_price;// ��Ʒ�۸�
        double deliver_price;// 

        if(i<OL->length)//��չʾ���ж���
        {
            Order order = OL->elem[i]; // ��ȡ��ǰ����

            // ���ƶ�����
            Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

            Fill_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, white);
            Draw_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, 1,deepblue);
            PrintCC(750+25, y_offset+30, "����", HEI, 24, 1, deepblue);
            
            Fill_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, white);
            Draw_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, 1,deepblue);
            PrintCC(875+25, y_offset+30, "�ӵ�", HEI, 24, 1, deepblue);

            // ��ʾ����������Ϣ
            sprintf(show_pick_up, "ȡ���㣺%s", node[order.pick_up_location].name);
            PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, 0x0000);

            sprintf(show_destination, "�ͻ��㣺%s", node[order.destination].name);
            PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, 0x0000);

            distance_m = dijkstra(&node[order.pick_up_location], &node[order.destination],3); // �������
            distance_km = distance_m / 1000.0; // ת��Ϊ����
            sprintf(show_distance, "���룺%.2fkm", distance_km);
            PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, 0x0000);

            item_price = order.total_amount; // ��ȡ��Ʒ�۸�
            deliver_price = rider_deliver_price(distance_m, item_price); // �������ͷ���
            sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
            PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, 0x0000);

            y_offset += 120; // ÿ��������֮��ļ��
        }
        else if (i >= OL->length && i < OL->length + FL->length) // Ȼ��չʾʳ�ö���
        {
            FoodOrder food_order = FL->elem[i - OL->length]; // ��ȡ��ǰ����

            Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

            Fill_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, white);
            Draw_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, 1,deepblue);
            PrintCC(750+25, y_offset+30, "����", HEI, 24, 1, deepblue);
            
            Fill_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, white);
            Draw_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, 1,deepblue);
            PrintCC(875+25, y_offset+30, "�ӵ�", HEI, 24, 1, deepblue);

            // ��ʾ����������Ϣ
            sprintf(show_pick_up, "ȡ���㣺%s", node[food_order.station].name);
            PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, 0x0000);

            sprintf(show_destination, "�ͻ��㣺%s", node[food_order.destination].name);
            PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, 0x0000);

            distance_m = dijkstra(&node[food_order.station], &node[food_order.destination],3); // �������
            distance_km = distance_m / 1000.0; // ת��Ϊ����
            sprintf(show_distance, "���룺%.2fkm", distance_km);
            PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, 0x0000);

            item_price = food_order.total_amount; // ��ȡ��Ʒ�۸�
            deliver_price = rider_deliver_price(distance_m, item_price); // �������ͷ���
            sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
            PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, 0x0000);

            y_offset += 120; // ÿ��������֮��ļ��
        }
        else if(i >= OL->length + FL->length)//���չʾ��ݴ�ȡ����
        {
            Deliver deliver = DL->elem[i - OL->length - FL->length]; // ��ȡ��ǰ����

            Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

            Fill_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, white);
            Draw_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, 1,deepblue);
            PrintCC(750+25, y_offset+30, "����", HEI, 24, 1, deepblue);
            
            Fill_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, white);
            Draw_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, 1,deepblue);
            PrintCC(875+25, y_offset+30, "�ӵ�", HEI, 24, 1, deepblue);
            // ��ʾ����������Ϣ
            sprintf(show_pick_up, "ȡ���㣺%s", node[deliver.station].name);
            PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, 0x0000);

            sprintf(show_destination, "�ͻ��㣺%s", node[deliver.index].name);
            PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, 0x0000);

            distance_m = dijkstra(&node[deliver.station], &node[deliver.index],3); // �������
            distance_km = distance_m / 1000.0; // ת��Ϊ����
            sprintf(show_distance, "���룺%.2fkm", distance_km);
            PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, 0x0000);

            item_price = 2.0; // ��ȡ��Ʒ�۸�
            deliver_price = rider_deliver_price(distance_m, item_price); // �������ͷ���
            sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
            PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, 0x0000);
            y_offset += 120; // ÿ��������֮��ļ��
        }
    }
    // ���Ʒ�ҳ��ť
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // ��һҳ
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // ��һҳ
    PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);
} 


