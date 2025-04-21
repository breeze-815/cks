#include <all_func.h>

void accept_order()
{
    int page = 0; // ��ǰҳ��

    OrderList OL = {0};
    FoodList FL = {0};

    ReadAllOrder(&OL); // ��ȡ�����б�
    ReadAllFood(&FL); // ��ȡʳƷ�б�

    mouse_off_arrow(&mouse);
	
	draw_accept_order(page,&OL,&FL);

    
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
            draw_accept_order(page,&OL,&FL);
            mouse_on_arrow(mouse);
        }
        else if (mouse_press(220, 700, 340, 750) == 1) // ��һҳ
		{
            if (page > 0) {
                page--;
                draw_accept_order(page,&OL,&FL); // �����û�����ҳ��
            } else {
                // ��ʾ�����ǵ�һҳ
                PrintCC(550, 35, "���ǵ�һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 35, 700, 60, white);
            }
        }
        else if (mouse_press(420, 700, 540, 750) == 1)  // ��һҳ
		{
			if ((page + 1) * 5 < OL.length) 
            {
				page++;
                draw_accept_order(page,&OL,&FL);
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
            draw_accept_order(page,&OL,&FL); // ���»��ƶ����б�
            mouse_on_arrow(mouse);
		}
        else if(mouse_press(782, 50, 902, 100)==1) //�˻�
        {
            press3(3); //��ť����
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

void draw_accept_order(int page,OrderList *OL,FoodList *FL) // ���ƽӵ�ҳ��
{
    int i;
    int cnt=0;
    int y_offset = 170; // ��ʼY��ƫ��
    // ÿҳ�����ʾ4������
    int start_index = page * 4; // ��ǰҳ����ʼ��������
    int end_index = start_index + 4; // ��ǰҳ�Ľ�����������
    cnt = OL->length;  // ��������
    
    if (end_index > cnt) 
    {
        end_index = cnt; // ��ֹԽ��
    }

    bar1(0, 150, 1024, 768,white);

    for (i = start_index; i < end_index; i++) 
    {
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
        

        y_offset += 130; // ÿ��������֮��ļ��
    }
    // ���Ʒ�ҳ��ť
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // ��һҳ
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // ��һҳ
    PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);   
}