#include <all_func.h>
#define MAX_COMBINED_ORDERS 20  /* ���ϲ������� */
void accept_order() // 
{
    int page = 0; // ��ǰҳ��
    int clicked;
    int order_index;
    int total_cnt; // ��������
    OrderList OL = {0};
    FoodList FL = {0};
    DeliverList DL = {0};

    ReadAllDeliver(&DL); 
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
        else if (mouse_press(220, 700, 340, 750) == 1) // ��һҳ
		{
            if (page > 0) {
                page--;
                draw_accept_order(page,&OL,&FL,&DL,total_cnt); // �����û�����ҳ��
            } else {
                // ��ʾ�����ǵ�һҳ
                PrintCC(550, 35, "���ǵ�һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 35, 700, 60, white);
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
				PrintCC(550, 35, "�������һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 35, 700, 60, white);
			}
		}
        else if(mouse_press(0, 150, 1024, 680) == 1) {

            //int order_index = (mouse.y - 25) / 120 + page * 5; // ���ݵ��λ�ü��㶩������
            //���order_index�ǻ���չʾ��ҳ�����������������food,����target�����������Ϊ�Ǵ�target��չʾ��
            //order_index�Զ��߶�����
            //����index��Ϊ�����ֳ��кͲ�ͬʳ�ã������ʳ�þ�Ҫ��target��չʾ
			MouseGet(&mouse);
            //business_detail(order_index,index); // ��ʾ��������

            //return����⿪ʼ
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // �����������������
            draw_accept_order(page,&OL,&FL,&DL,total_cnt);// ���»��ƶ����б�
            mouse_on_arrow(mouse);
		}
        else if(mouse_press(782, 50, 902, 100)==1) //�˻�
        {
            press3(3); //��ť����
        }
        else if(mouse_press(20, 150, 1000, 680) == 1) {  
            clicked = (mouse.y - 170) / 130;  
            /* 1) �Ȼ�ȡ����������� */
            MouseGet(&mouse);
    
            /* 2) ���� y �������������Ǳ�ҳ�ڼ�����ÿ���� 130px���� y=170 ��ʼ�� */
            
            if (clicked >= 0 && clicked < 4) {
                /* 3) ���ȫ�ֶ������� */
                order_index = clicked + page * 4;
    
                /* 4) ��ת����������ҳ */
                //ord_det(page, order_index, &OL, &FL);
    
                /* 5) ������ҳ���غ��ػ�ӵ��б� */
                mouse_off_arrow(&mouse);
                bar1(0, 150, 1024, 768, white);
                draw_accept_order(page,&OL,&FL,&DL,total_cnt);
                mouse_on_arrow(mouse);
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

// void draw_accept_order(int page, OrderList *OL, FoodList *FL)
// {
//     /* ���б�������������ǰ�棬���� C89/�ɱ����� */
//     int       i, j;
//     int       total_cnt;
//     int       y_offset;
//     int       per_page;
//     int       base_idx, global_idx;
//     int       dist_m;
//     double    dist_km, fee;
//     char      buf1[32], buf2[32], buf3[32], buf4[32];
//     Order     order;
//     FoodOrder fo;

//     /*���� ��ʼ�� ����*/
//     per_page  = 4;
//     total_cnt = OL->length + FL->length;
//     base_idx  = page * per_page;
//     y_offset  = 170;

//     /*���� ���� ����*/
//     bar1(0, 150, 1024, 768, white);

//     /*���� ѭ�����Ʊ�ҳ��Ŀ ����*/
//     for (j = 0; j < per_page; j++) {
//         global_idx = base_idx + j;
//         if (global_idx >= total_cnt) break;

//         /* ���Ʊ����� */
//         Draw_Rounded_Rectangle(20, y_offset,
//                                1000, y_offset + 100,
//                                30, 1, 0x6B4D);

//         if (global_idx < OL->length) {
//             /* ���� ���ж��� ���� */
//             order = OL->elem[global_idx];
//             sprintf(buf1, "ȡ�ͣ�%s", node[order.pick_up_location].name);
//             sprintf(buf2, "�ʹ%s", node[order.destination].name);
//             PrintText( 50, y_offset + 10, buf1, HEI, 24, 1, 0x0000);
//             PrintText( 50, y_offset + 60, buf2, HEI, 24, 1, 0x0000);
//             dist_m  = dijkstra(&node[order.pick_up_location],
//                                &node[order.destination], 3);
//             dist_km = dist_m / 1000.0;
//             sprintf(buf3, "���룺%.2fkm", dist_km);
//             PrintText(500, y_offset + 10, buf3, HEI, 24, 1, 0x0000);
//             fee = rider_deliver_price(dist_m, order.total_amount);
//             sprintf(buf4, "���ͷѣ�%.1fԪ", fee);
//             PrintText(500, y_offset + 60, buf4, HEI, 24, 1, 0x0000);
//         } else {
//             /* ���� ʳ�ö��� ���� */
//             fo = FL->elem[global_idx - OL->length];
//             sprintf(buf1, "ȡ�ͣ�%s", node[fo.pick_up_location].name);
//             sprintf(buf2, "�ʹ%s", node[fo.destination].name);
//             PrintText( 50, y_offset + 10, buf1, HEI, 24, 1, 0x0000);
//             PrintText( 50, y_offset + 60, buf2, HEI, 24, 1, 0x0000);
//             dist_m  = dijkstra(&node[fo.pick_up_location],
//                                &node[fo.destination], 3);
//             dist_km = dist_m / 1000.0;
//             sprintf(buf3, "���룺%.2fkm", dist_km);
//             PrintText(500, y_offset + 10, buf3, HEI, 24, 1, 0x0000);
//             fee = rider_deliver_price(dist_m, fo.total_amount);
//             sprintf(buf4, "���ͷѣ�%.1fԪ", fee);
//             PrintText(500, y_offset + 60, buf4, HEI, 24, 1, 0x0000);
//         }

//         y_offset += 130;
//     }

//     /*���� ���Ʒ�ҳ��ť ����*/
//     Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue);
//     Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue);
//     PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
//     PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);
// }


// void draw_accept_order(int page,OrderList *OL,FoodList *FL) // ���ƽӵ�ҳ��
// {
//     int i;
//     int cnt=0;
//     int y_offset = 170; // ��ʼY��ƫ��
//     // ÿҳ�����ʾ4������
//     int start_index = page * 4; // ��ǰҳ����ʼ��������
//     int end_index = start_index + 4; // ��ǰҳ�Ľ�����������
//     cnt = OL->length;  // ��������
    
//     if (end_index > cnt) 
//     {
//         end_index = cnt; // ��ֹԽ��
//     }

//     bar1(0, 150, 1024, 768,white);

//     for (i = start_index; i < end_index; i++) 
//     {
//         char show_pick_up[20]; // ȡ�͵ص�
//         char show_destination[20]; // Ŀ�ĵ�
//         char show_distance[20]; // ����
//         char show_deliver_price[20]; // ���ͷ���
//         int distance_m; // ����
//         float distance_km; // ����
//         float item_price;
//         double deliver_price;// �ܼ��ַ���

//         Order order = OL->elem[i]; // ��ȡ��ǰ����
        
//         // ���ƶ�����
//         Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

//         // ��ʾ����������Ϣ
//         sprintf(show_pick_up, "ȡ���㣺%s", node[order.pick_up_location].name);
//         PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, 0x0000);

//         sprintf(show_destination, "�ͻ��㣺%s", node[order.destination].name);
//         PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, 0x0000);

//         distance_m = dijkstra(&node[order.pick_up_location], &node[order.destination],3); // �������
//         distance_km = distance_m / 1000.0; // ת��Ϊ����
//         sprintf(show_distance, "���룺%.2fkm", distance_km);
//         PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, 0x0000);

//         item_price = order.total_amount; // ��ȡ��Ʒ�۸�
//         deliver_price = rider_deliver_price(distance_m, item_price); // �������ͷ���
//         sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
//         PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, 0x0000);
        

//         y_offset += 130; // ÿ��������֮��ļ��
//     }
//     // ���Ʒ�ҳ��ť
//     Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // ��һҳ
//     Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // ��һҳ
//     PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
//     PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);   
// }

// void draw_accept_order(int page, OrderList *OL, FoodList *FL)
// {
//     /* ���б�������������ǰ�棬��Ӧ C89/�ɱ����� */
//     int          i, cnt;
//     int          y_offset;
//     int          per_page;
//     int          start, end;
//     int          dist_m;
//     double       dist_km, fee;
//     FoodOrder    combined[MAX_COMBINED_ORDERS];
//     char         buf1[32], buf2[32], buf3[32], buf4[32];
//     FoodOrder   *o;

//     /*���� ��ʼ�� ����*/
//     cnt      = 0;
//     y_offset = 170;
//     per_page = 4;

//     /*���� 1) �ϲ����ж��� ����*/
//     for (i = 0; i < OL->length && cnt < MAX_COMBINED_ORDERS; i++) {
//         /* ʹ�� pick_up_location �ֶμ�¼ȡ�ͽڵ㣬��Ҫ���� station */
//         combined[cnt].pick_up_location = OL->elem[i].pick_up_location;
//         combined[cnt].destination      = OL->elem[i].destination;
//         combined[cnt].total_amount     = OL->elem[i].total_amount;
//         strcpy(combined[cnt].user_name,  OL->elem[i].user_name);
//         strcpy(combined[cnt].order_time, OL->elem[i].order_time);
//         combined[cnt].station = 0;  /* �����ԴΪ���У��ɸ�����Ҫ���� */
//         cnt++;
//     }

//     /*���� 2) �ϲ�����ʳ�ö��� ����*/
//     for (i = 0; i < FL->length && cnt < MAX_COMBINED_ORDERS; i++) {
//         combined[cnt++] = FL->elem[i];
//     }

//     /*���� 3) ��ҳ���� ����*/
//     start = page * per_page;
//     end   = start + per_page;
//     if (start > cnt) start = cnt;
//     if (end   > cnt) end   = cnt;

//     /*���� 4) ���� ����*/
//     bar1(0, 150, 1024, 768, white);

//     /*���� 5) ���Ƶ�ǰҳ���� ����*/
//     for (i = start; i < end; i++) {
//         o = &combined[i];

//         /* ������ */
//         Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

//         /* ȡ�͵�ַ */
//         sprintf(buf1, "ȡ�ͣ�%s", node[o->pick_up_location].name);
//         sprintf(buf2, "�ʹ%s", node[o->destination].name);
//         PrintText( 50, y_offset + 10, buf1, HEI, 24, 1, 0x0000);
//         PrintText( 50, y_offset + 60, buf2, HEI, 24, 1, 0x0000);

//         /* ���㲢��ʾ���� */
//         dist_m  = dijkstra(&node[o->pick_up_location],
//                            &node[o->destination], 3);
//         dist_km = dist_m / 1000.0;
//         sprintf(buf3, "���룺%.2fkm", dist_km);
//         PrintText(500, y_offset + 10, buf3, HEI, 24, 1, 0x0000);

//         /* ���㲢��ʾ���ͷ� */
//         fee = rider_deliver_price(dist_m, o->total_amount);
//         sprintf(buf4, "���ͷѣ�%.1fԪ", fee);
//         PrintText(500, y_offset + 60, buf4, HEI, 24, 1, 0x0000);

//         y_offset += 130;
//     }

//     /*���� 6) ��ҳ��ť ����*/
//     Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue);
//     Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue);
//     PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
//     PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);
// }

void draw_accept_order(int page, OrderList *OL, FoodList *FL, DeliverList *DL ,int total_cnt) // ���ƽӵ�ҳ��
{
    int i,j;
    int cnt = 0;
    int y_offset = 170; // ��ʼY��ƫ��
    FoodOrder food_order;
    //FoodOrder target_order[20]; // ���ڴ洢Ŀ�궩��

    int start_index = page * 4; // ��ǰҳ����ʼ��������
    int end_index = start_index + 4; // ��ǰҳ�Ľ�����������

    if (end_index > total_cnt) 
        {
            end_index = total_cnt; // ��ֹԽ��
        }
    


    bar1(0, 150, 1024, 768, white); // �����Ļ

    for (i = start_index; i < end_index; i++) {
        char order_id[10]; // ����ID�ַ���
        char user_info[16]; // �û���Ϣ�ַ���
        char total_price[10];// �ܼ��ַ���

        char show_pick_up[20]; // ȡ�͵ص�
        char show_destination[20]; // Ŀ�ĵ�
        char show_distance[20]; // ����
        char show_deliver_price[20]; // ���ͷ���
        int distance_m; // ����
        float distance_km; // ����
        float item_price;
        double deliver_price;// �ܼ��ַ���
        Order order = OL->elem[i]; // ��ȡ��ǰ����

        // ���ƶ�����
        Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

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

        if (i >= OL->length) 
        {
            food_order = FL->elem[i - OL->length+1]; // ��ȡ��ǰ����
                // target_order[j] = FL->elem[j]; // ��ȡĿ�궩��
                // food_order = target_order[j];// ��ȡ��ǰ���� 
            //     if(FL->elem[i].station==1)//�ҵ���Ӧ�Ķ���
        	// {
        	// 	target_order[cnt]=FL->elem[i];
        	// 	cnt++;

        	// }   
                Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

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
        



                // // ��ʾ����������Ϣ
                // sprintf(order_id, "����%d", i + 1);
                // PrintText(235, y_offset + 15, order_id, HEI, 24, 1, 0x0000);

                // sprintf(user_info, "�µ��ˣ�%s", food_order.user_name);
                // PrintText(235, y_offset + 65, user_info, HEI, 24, 1, 0x0000);

                
                // sprintf(total_price, "�ܼۣ�%.2f", food_order.total_amount);
                // PrintText(800, y_offset + 15, total_price, HEI, 24, 1, 0x0000);

                // PrintText(665, y_offset + 65, food_order.order_time, HEI, 24, 1, 0x0000);

                y_offset += 120; // ÿ��������֮��ļ��
        }
    }
        // if (i >= FL->length + OL->length) {
        //     break; // ��ֹԽ��
        // }
    // ���Ʒ�ҳ��ť
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // ��һҳ
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // ��һҳ
    PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);
}
// void draw_accept_order(int page, OrderList *OL, FoodList *FL, DeliverList *DL, int total_cnt) {
//     int y_offset = 170;
//     const int per_page = 4;
//     int start_index = page * per_page;
//     int end_index = start_index + per_page;
//     int i,fl_idx;
//     FoodOrder food_order;
//     bar1(0, 150, 1024, 768, white);

//     for (i = start_index; i < end_index && i < total_cnt; i++) {
//         char show_pick_up[32], show_destination[32], show_distance[32], show_deliver_price[32];
//         int distance_m;
//         float distance_km, deliver_price;

//         // ���ֶ�������
//         if (i < OL->length) {
//             // ========== ���ж������� ==========
//             Order order = OL->elem[i];
//             sprintf(show_pick_up, "ȡ���㣺%s", node[order.pick_up_location].name);
//             sprintf(show_destination, "�ͻ��㣺%s", node[order.destination].name);
//             distance_m = dijkstra(&node[order.pick_up_location], &node[order.destination], 3);
//         } else {
//             // ========== ʳ�ö������� ==========
//             fl_idx = i - OL->length;
//             if (fl_idx >= FL->length) break; // ����Խ��
//             food_order = FL->elem[fl_idx];
//             sprintf(show_pick_up, "ȡ���㣺%s", node[food_order.pick_up_location].name);
//             sprintf(show_destination, "�ͻ��㣺%s", node[food_order.destination].name);
//             distance_m = dijkstra(&node[food_order.pick_up_location], &node[food_order.destination], 3);
//         }

//         // ========== ͳһ�����߼� ==========
//         distance_km = distance_m / 1000.0f;
//         deliver_price = rider_deliver_price(distance_m, 
//             (i < OL->length) ? OL->elem[i].total_amount : FL->elem[i - OL->length].total_amount
//         );

//         Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);
//         PrintText(50, y_offset + 10, show_pick_up, HEI, 24, 1, 0x0000);
//         PrintText(50, y_offset + 60, show_destination, HEI, 24, 1, 0x0000);
//         sprintf(show_distance, "���룺%.2fkm", distance_km);
//         PrintText(500, y_offset + 10, show_distance, HEI, 24, 1, 0x0000);
//         sprintf(show_deliver_price, "���ͷѣ�%.1fԪ", deliver_price);
//         PrintText(500, y_offset + 60, show_deliver_price, HEI, 24, 1, 0x0000);

//         y_offset += 120;
//     }

//     // ��ҳ��ť���ƣ��ԣ�
// }