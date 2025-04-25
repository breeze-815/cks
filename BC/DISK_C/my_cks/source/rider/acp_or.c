#include  <all_func.h>

#define ORDERS_PER_PAGE   4
#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

void accept_order(int user_pos) // �ӵ�����
{
    int page = 0; // ��ǰҳ��
    int clicked;
    int type=0, local_index=0, global_index=0; //typeΪ�������࣬����Ϊ0������Ϊ1����ȡΪ2��local_indexΪ�������ڵ�ǰ�����е���ţ�global_indexΪ�����������ж����е����
    //char debg[20];
    OrderList OL = {0}; //�������У��������������Կձ����ڶ�ȡ
    FoodList FL = {0};
    DeliverList DL = {0};
    ReadAllOrder(&OL); // ��ȡ�����б�
    ReadAllFood(&FL); // ��ȡʳƷ�б�
    ReadAllDeliver(&DL); // ��ȡ����б�
    mouse_off_arrow(&mouse);
    num_of_orders.total_cnt = OL.length + FL.length + DL.length; // ���㶩������
	draw_accept_order(page,&OL,&FL,&DL); // ���ƽӵ�ҳ��
	mouse_on_arrow(mouse);
    //sprintf(debg,"%d",num_of_orders.cur_count);
    //PrintText(1,1,debg,HEI,32,1,black);
	while(1)
    {
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
            DestroyOList(&OL); // �ͷŶ����б��ڴ�
            DestroyFList(&FL); // �ͷ�ʳƷ�б��ڴ�
            DestroyDList(&DL); // �ͷſ���б��ڴ�
            route(cur_orders,num_of_orders.cur_count,user_pos); //����·�߽���
            //return����⿪ʼ
            mouse_on_arrow(mouse);
            ReadAllOrder(&OL); // ��ȡ�����б�
            ReadAllFood(&FL); // ��ȡʳƷ�б�
            ReadAllDeliver(&DL); // ��ȡ����б�
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_accept_order(page,&OL,&FL,&DL); // ���»��ƽӵ�����
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //�ҵ�
        {
            press3(3); //��ť����
            mouse_off_arrow(&mouse);
            my_information(user_pos);
            DestroyOList(&OL); // �ͷŶ����б��ڴ�
            DestroyFList(&FL); // �ͷ�ʳƷ�б��ڴ�
            DestroyDList(&DL); // �ͷſ���б��ڴ�
            //return����⿪ʼ
            ReadAllOrder(&OL); // ��ȡ�����б�
            ReadAllFood(&FL); // ��ȡʳƷ�б�
            ReadAllDeliver(&DL); // ��ȡ����б�
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // ���·�߽������
            draw_accept_order(page,&OL,&FL,&DL); // ���»��ƽӵ�����
            mouse_on_arrow(mouse);
        }
        else if (mouse_press(220, 700, 340, 750) == 1) // ��һҳ
		{
            if (page > 0) //�ж��Ƿ�����һҳ
            {
                page--;
                draw_accept_order(page,&OL,&FL,&DL); // �����û�����ҳ��
            } 
            else // ��ӡ��ʾ
            {
                PrintCC(550, 700, "���ǵ�һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 700, 700, 750, white); //���Ǵ�ӡ����
            }
        }
        else if (mouse_press(420, 700, 540, 750) == 1)  // ��һҳ
		{
			if ((page + 1) * 4 < num_of_orders.total_cnt)  //�ж��ܷ���һҳ
            {
				page++;
                draw_accept_order(page,&OL,&FL,&DL); // �����û�����ҳ��
			} 
            else // ��ӡ��ʾ
            {
				PrintCC(550, 700, "�������һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 700, 700, 750, white);
			}
		}
        else if (mouse_press(750, 170 + 25, 850, 170 + 75) == 1) //���ҳ���һ���������鰴ť��λ��
        {
            global_index = page * ORDERS_PER_PAGE + 0; //����ȫ������
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL); //��ȫ���������㶩�����ͺ��ڲ�����
            if (global_index < num_of_orders.total_cnt) //��ֹԽ��
            {
                DestroyOList(&OL); // �ͷŶ����б��ڴ�
                DestroyFList(&FL); // �ͷ�ʳƷ�б��ڴ�
                DestroyDList(&DL); // �ͷſ���б��ڴ�
                show_order_detail(local_index, type, user_pos); //���붩������ҳ
                //return����ⷵ��
                ReadAllOrder(&OL); // ��ȡ�����б�
                ReadAllFood(&FL); // ��ȡʳƷ�б�
                ReadAllDeliver(&DL); // ��ȡ����б�
                bar1(0,150,1024,768,white); //�����������ҳ����
                draw_accept_order(page,&OL,&FL,&DL); //������չʾҳ
            }
        }
        else if (mouse_press(750, 290 + 25, 850, 290 + 75) == 1) //���ҳ��ڶ����������鰴ť��λ��
        {
            global_index = page * ORDERS_PER_PAGE + 1;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            if (global_index < num_of_orders.total_cnt) 
            {
                DestroyOList(&OL); // �ͷŶ����б��ڴ�
                DestroyFList(&FL); // �ͷ�ʳƷ�б��ڴ�
                DestroyDList(&DL); // �ͷſ���б��ڴ�
                show_order_detail(local_index, type, user_pos);
                //return����ⷵ��
                ReadAllOrder(&OL); // ��ȡ�����б�
                ReadAllFood(&FL); // ��ȡʳƷ�б�
                ReadAllDeliver(&DL); // ��ȡ����б�
                bar1(0,150,1024,768,white); 
                draw_accept_order(page,&OL,&FL,&DL);
            }
        }
        else if (mouse_press(750, 410 + 25, 850, 410 + 75) == 1) //���ҳ��������������鰴ť��λ��
        {
            global_index = page * ORDERS_PER_PAGE + 2;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            if (global_index < num_of_orders.total_cnt) 
            {
                DestroyOList(&OL); // �ͷŶ����б��ڴ�
                DestroyFList(&FL); // �ͷ�ʳƷ�б��ڴ�
                DestroyDList(&DL); // �ͷſ���б��ڴ�
                show_order_detail(local_index, type, user_pos);
                //return����ⷵ��
                ReadAllOrder(&OL); // ��ȡ�����б�
                ReadAllFood(&FL); // ��ȡʳƷ�б�
                ReadAllDeliver(&DL); // ��ȡ����б�
                bar1(0,150,1024,768,white); 
                draw_accept_order(page,&OL,&FL,&DL);
            }
        }
        else if (mouse_press(750, 530 + 25, 850, 530 + 75) == 1) //���ҳ����ĸ��������鰴ť��λ��
        {
            global_index = page * ORDERS_PER_PAGE + 3;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            if (global_index < num_of_orders.total_cnt) 
            {
                DestroyOList(&OL); // �ͷŶ����б��ڴ�
                DestroyFList(&FL); // �ͷ�ʳƷ�б��ڴ�
                DestroyDList(&DL); // �ͷſ���б��ڴ�
                show_order_detail(local_index, type, user_pos);
                //return����ⷵ��
                ReadAllOrder(&OL); // ��ȡ�����б�
                ReadAllFood(&FL); // ��ȡʳƷ�б�
                ReadAllDeliver(&DL); // ��ȡ����б�
                bar1(0,150,1024,768,white); 
                draw_accept_order(page,&OL,&FL,&DL);
            }
        }
        else if (mouse_press(875, 170 + 25, 975, 170 + 75) == 1) //���ҳ���һ�������ӵ���ť��λ��
        {
            global_index = page * ORDERS_PER_PAGE + 0;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            
            if (num_of_orders.cur_count == 4)
            { 
                //��ӡ��ʾ
                PrintText(100, 100, "�ӵ������Ѵ����ޣ�", HEI, 24, 1, Red);
                delay(500);
                bar1(100,100,500,130,deepblue);
            }
            else
            {
                add_my_accept(&OL, &FL, &DL, type, local_index); //����ӵ��б�
                //�ػ�����չʾ�б�
                bar1(0, 150, 1024, 768, white);
                draw_accept_order(page, &OL, &FL, &DL);
            }
        }
        else if (mouse_press(875, 290 + 25, 975, 290 + 75) == 1) //���ҳ��ڶ��������ӵ���ť��λ��
        {
            global_index = page * ORDERS_PER_PAGE + 1;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            if (global_index < num_of_orders.total_cnt) 
            {
                if ( num_of_orders.cur_count== 4)
                { 
                    PrintText(100, 100, "�ӵ������Ѵ����ޣ�", HEI, 24, 1, Red);
                    delay(500);
                    bar1(100,100,500,130,deepblue);
                }
                else
                {
                    add_my_accept(&OL, &FL, &DL, type, local_index);
                    //�ػ�����չʾ�б�
                    bar1(0, 150, 1024, 768, white);
                    draw_accept_order(page, &OL, &FL, &DL);
                }
            }
        }
        else if (mouse_press(875, 410 + 25, 975, 410 + 75) == 1) //���ҳ������������ӵ���ť��λ��
        {
            global_index = page * ORDERS_PER_PAGE + 2;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
        if (global_index < num_of_orders.total_cnt) 
        {
            if ( num_of_orders.cur_count== 4)
            { 
                PrintText(100, 100, "�ӵ������Ѵ����ޣ�", HEI, 24, 1, Red);
                delay(500);
                bar1(100,100,500,130,deepblue);
            }
            else
            {
                add_my_accept(&OL, &FL, &DL, type, local_index);
                bar1(0, 150, 1024, 768, white);
                draw_accept_order(page, &OL, &FL, &DL);
            }
        }
    }
        else if (mouse_press(875, 530 + 25, 975, 530 + 75) == 1) //���ҳ����ĸ������ӵ���ť��λ��
        {
            global_index = page * ORDERS_PER_PAGE + 3;
            get_ordtyp_locind(global_index,&type,&local_index,&OL,&FL,&DL);
            if (global_index < num_of_orders.total_cnt) 
            {
                if ( num_of_orders.cur_count== 4)
                { 
                    PrintText(100, 100, "�ӵ������Ѵ����ޣ�", HEI, 24, 1, Red);
                    delay(500);
                    bar1(100,100,500,130,deepblue);
                }
                else
                {
                    add_my_accept(&OL, &FL, &DL, type, local_index);
                    //�ػ�����չʾ�б�
                    bar1(0, 150, 1024, 768, white);
                    draw_accept_order(page, &OL, &FL, &DL);
                }
            
            }
        }
    }
}
    
double rider_deliver_price(int distance_m, float order_amount) //�������ͷ�
{
    const double price_per_km   = 0.5;   // ÿ�������ͷѣ�Ԫ��
    const double base_price     = 2.0;   // �𲽼ۣ�Ԫ��
    const double price_ratio    = 0.05;  // ��Ʒ��� 5% �Ӽ�

    double dist_km = (double)distance_m / 1000.0; //��λ����
    double total = base_price + dist_km * price_per_km + order_amount * price_ratio;// �����ܷ�
    return total;
}

void draw_accept_order(int page, OrderList *OL, FoodList *FL, DeliverList *DL) // ���ƽӵ�ҳ��
{
    int i,j;
    int y_offset = 170; // ��ʼY��ƫ��
    int start_index = page * 4; // ��ǰҳ����ʼ��������
    int end_index = start_index + 4; // ��ǰҳ�Ľ�����������
    char debg[20];
    if (end_index > num_of_orders.total_cnt) 
        end_index = num_of_orders.total_cnt; // ��ֹԽ��
    
    bar1(0, 150, 1024, 768, white); // �����Ļ
    sprintf(debg,"%d",num_of_orders.total_cnt);
    PrintText(0,0,debg,HEI,36,1,Red);
    
    if(num_of_orders.total_cnt==0)
    PrintCC(400,400,"��ǰ�޿ɽӶ���",HEI,36,1,Red);
    else
    {
        // ���ƶ���
        for (i = start_index; i < end_index; i++) 
        {
            char show_pick_up[20]; // ȡ�͵ص�
            char show_destination[20]; // Ŀ�ĵ�
            char show_distance[20]; // ����
            char show_deliver_price[20]; // ���ͷ���
            int distance_m; // ����
            float distance_km; // ����
            float item_price;// ��Ʒ�۸�
            double deliver_price;//���ͷ�

            if(i < OL->length) //��չʾ���ж���
            {
                //char debg[20];
                Order order = OL->elem[i]; // ��ȡ��ǰ����
                //���ƶ�����
                // sprintf(debg,"%d",i);
                // PrintText(0,0,debg,HEI,24,1,black);
                // sprintf(debg,"%d",order.pick_up_location);
                // PrintText(0,50,debg,HEI,32,1,black);
                Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, deepgrey);
                //�������鰴ť
                Fill_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, white);
                Draw_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, 1,deepblue);
                PrintCC(750+25, y_offset+30, "����", HEI, 24, 1, deepblue);
                //���ƽӵ���ť
                Fill_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, white);
                Draw_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, 1,deepblue);
                PrintCC(875+25, y_offset+30, "�ӵ�", HEI, 24, 1, deepblue);
                // ��ʾ����������Ϣ
                sprintf(show_pick_up, "ȡ���㣺%s", node[order.pick_up_location].name); //չʾȡ����
                PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, black);

                sprintf(show_destination, "�ͻ��㣺%s", node[order.destination].name); //չʾ�ͻ���
                PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, black);

                distance_m = dijkstra(&node[order.pick_up_location], &node[order.destination],3); // �������
                distance_km = distance_m / 1000.0; // ת��Ϊ����
                sprintf(show_distance, "���룺%.2fkm", distance_km); //չʾ����
                PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, black);

                item_price = order.total_amount; // ��ȡ��Ʒ�۸�
                deliver_price = rider_deliver_price(distance_m, item_price); // �������ͷ���
                sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
                PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, black);

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

                sprintf(show_pick_up, "ȡ�͵㣺%s", node[food_order.station].name);
                PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, black);

                sprintf(show_destination, "�Ͳ͵㣺%s", node[food_order.destination].name);
                PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, black);

                distance_m = dijkstra(&node[food_order.station], &node[food_order.destination],3); 
                distance_km = distance_m / 1000.0; 
                sprintf(show_distance, "���룺%.2fkm", distance_km);
                PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, black);

                item_price = food_order.total_amount; 
                deliver_price = rider_deliver_price(distance_m, item_price); 
                sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
                PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, black);

                y_offset += 120; // ÿ��������֮��ļ��
            }
            else if(i >= OL->length + FL->length)//���չʾ��ݴ�ȡ����
            {
                Deliver deliver = DL->elem[i - OL->length - FL->length]; 

                Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

                Fill_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, white);
                Draw_Rounded_Rectangle(750, y_offset+25, 850, y_offset+75, 25, 1,deepblue);
                PrintCC(750+25, y_offset+30, "����", HEI, 24, 1, deepblue);
                
                Fill_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, white);
                Draw_Rounded_Rectangle(875, y_offset+25, 975, y_offset+75, 25, 1,deepblue);
                PrintCC(875+25, y_offset+30, "�ӵ�", HEI, 24, 1, deepblue);
                
                sprintf(show_pick_up, "ȡ���㣺%s", node[deliver.station+408].name);
                PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, black);

                sprintf(show_destination, "�ͻ��㣺%s", node[deliver.index].name);
                PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, black);

                distance_m = dijkstra(&node[deliver.station], &node[deliver.index],3); 
                distance_km = distance_m / 1000.0; 
                sprintf(show_distance, "���룺%.2fkm", distance_km);
                PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, black);

                item_price = 2.0; 
                deliver_price = rider_deliver_price(distance_m, item_price); 
                sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
                PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, black);

                y_offset += 120; 
            }
        }
    }
    
    // ���Ʒ�ҳ��ť
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // ��һҳ
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // ��һҳ
    PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);
} 


void get_ordtyp_locind(int global_index,
    int *type, int *local_index,
    const OrderList *OL, const FoodList *FL, const DeliverList *DL) //��������ʾ���ж���������ʾ���������������ʾ��ȡ�����������������㶩�����ͺͱ�������
{
    if (global_index < OL->length) //ȫ������С�ڳ��ж���������Ϊ���ж��� 
    {
        *type = ORDER_SUPERMARKET;
        *local_index = global_index;
    } 
    else if (global_index < OL->length + FL->length) //ȫ������С�ڳ��м�������������Ϊ��������
    {
        *type = ORDER_FOOD;
        *local_index = global_index - OL->length; //������������������ȥ���ж�����
    } 
    else if (global_index < OL->length + FL->length + DL->length) //ʣ���Ϊ��ȡ����
    {
        *type = ORDER_DELIVER;
        *local_index = global_index - OL->length - FL->length; //������������������ȥ���ж�����������������
    }
}


