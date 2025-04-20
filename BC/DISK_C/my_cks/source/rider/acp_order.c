#include <all_func.h>

void accept_order()
{
    int page = 0; // ��ǰҳ��

    OrderList OL = {0};

    ReadAllOrder(&OL); // ��ȡ�����б�

    mouse_off_arrow(&mouse);
	
	draw_accept_order(page,&OL);

    
	//mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);
    
		if(mouse_press(122, 50, 242, 100)==1)
        {
            DestroyOList(&OL); // �ͷŶ����б��ڴ�
            return;
			//business(users.pos);
		}
        else if(mouse_press(342, 50, 462, 100)==1)
        {
            press3(1);
            //route();//����·�߹滮����
            //dijkstra(&node[1], &node[29]);//����dijkstra�㷨
            //return����⿪ʼ
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // ����ӵ��������
            draw_rider();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(562, 50, 682, 100)==1)
        {
            press3(2);
        }
        else if(mouse_press(782, 50, 902, 100)==1)
        {
            press3(3);
        }
		// {
        //     if (page > 0) {
        //         page--;
        //         //draw_business_order(page,&OL);
        //     } else {
        //         // ��ʾ�����ǵ�һҳ
        //         PrintCC(550, 35, "���ǵ�һҳ", HEI, 24, 1, lightred);
		// 		delay(500);
		// 		bar1(550, 35, 700, 60, white);
        //     }
        // }
		// else if (mouse_press(420, 700, 540, 750) == 1) 
		// {
		// 	if ((page + 1) * 5 < OL.length) {
		// 		page++;
        //         draw_business_order(page,&OL);
		// 	} else {
		// 		// ��ʾ���������һҳ
		// 		PrintCC(550, 35, "�������һҳ", HEI, 24, 1, lightred);
		// 		delay(500);
		// 		bar1(550, 35, 700, 60, white);
		// 	}
		// }
        // else if(mouse_press(200, 0, 1024, 680) == 1) {
        //     int order_index = (mouse.y - 25) / 120 + page * 5; // ���ݵ��λ�ü��㶩������

		// 	MouseGet(&mouse);

        //     if (order_index >= 0 && order_index < OL.length) 
        //     {
        //         business_detail(order_index); // ��ʾ��������
        //         //return����⿪ʼ
        //         mouse_off_arrow(&mouse);
        //         bar1(200, 0, 1024, 768, white); // �����������������
        //         draw_business_order(page,&OL); // ���»��ƶ����б�
        //         mouse_on_arrow(mouse);
        //     }
		// }
    }
}

void draw_accept_order(int page,OrderList *OL)
{
    char debug_buf[100]; // ������Ϣ������
    int i;
    int y_offset = 170; // ��ʼY��ƫ��

    int orders_per_page = 5; // ÿҳ�����ʾ5������
    int start_index = page * orders_per_page; // ��ǰҳ����ʼ��������
    int end_index = start_index + orders_per_page; // ��ǰҳ�Ľ�����������

    // int community; // �û�����
    // int building; // �û�����
    // int pick_up_location; //ȡ�͵ص�
    char total_price[10];// �ܼ��ַ���

    if (end_index > OL->length) {
        end_index = OL->length; // ��ֹԽ��
    }

    bar1(0, 150, 1024, 768, white);

    // Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//������ɫ
    // Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//����//Բ�ǰ�ť���ֵ�x+35��y+15
    // PrintCC(75,128,"����",HEI,24,1,deepblue);
    // ��ʾ������Ϣ
    
    for (i = start_index; i < end_index; i++) {
            Order order = OL->elem[i]; // ��ȡ��ǰ����
            // DEBUG����ӡ������̨
            
            sprintf(debug_buf,"DEBUG[%d]: community=%d, pick_up_loction=%d\n",
                i, order.community, order.pick_up_location);
            PrintText(35, y_offset+15, debug_buf, HEI, 24, 1, lightred); 

        

        // ���ƶ�����
        Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

        // switch (expression)
        // {
        // case constant expression:
        //     /* code */
        //     break;
        
        // default:
        //     break;
        // }
        // switch (order.pick_up_loction)
        // {
        //     case 0:
        //         PrintText(35, y_offset + 15, "����", HEI, 24, 1, 0x0000);
        //         break;
        //     case 1:
        //         PrintText(35, y_offset + 15, "��Էѧ��ʳ��", HEI, 24, 1, 0x0000);
        //         break;
        //     case 2:
        //         PrintText(35, y_offset + 15, "��԰ѧ��ʳ��", HEI, 24, 1, 0x0000);
        //         break;
        //     case 3:
        //         PrintText(35, y_offset + 15, "ѧ��һʳ��", HEI, 24, 1, 0x0000);
        //         break;
        //     case 4:
        //         PrintText(35, y_offset + 15, "ѧ����ʳ��", HEI, 24, 1, 0x0000);
        //         break;
        //     case 5:
        //         PrintText(35, y_offset + 15, "���̹�ʳ��", HEI, 24, 1, 0x0000);
        //         break;
        //     case 6:
        //         PrintText(35, y_offset + 15, "��԰ʳ��", HEI, 24, 1, 0x0000);
        //         break;
        //     case 7:
        //         PrintText(35, y_offset + 15, "����¥ʳ��", HEI, 24, 1, 0x0000);
        //         break;
        //     case 8:
        //         PrintText(35, y_offset + 15, "��һʳ��", HEI, 24, 1, 0x0000);
        //         break;
        //     case 9:
        //         PrintText(35, y_offset + 15, "�Ͼ�԰����", HEI, 24, 1, 0x0000);
        //         break;
        //     case 10:
        //         PrintText(35, y_offset + 15, "����ʳ��", HEI, 24, 1, 0x0000);
        //         break;
        //     case 11:
        //         PrintText(35, y_offset + 15, "����ʳ��", HEI, 24, 1, 0x0000);
        //         break;
        //     case 12:
        //         PrintText(35, y_offset + 15, "��һѧ��ʳ��", HEI, 24, 1, 0x0000);
        //         break;
        //     case 13:
        //         PrintText(35, y_offset + 15, "����ѧ��ʳ��", HEI, 24, 1, 0x0000);
        //         break;
        //     case 14:
        //         PrintText(35, y_offset + 15, "����ѧ��ʳ��", HEI, 24, 1, 0x0000);
        //         break;
        //     case 15:
        //         PrintText(35, y_offset + 15, "�پ�԰����", HEI, 24, 1, 0x0000);
        //         break;
        //     case 16:
        //         PrintText(35, y_offset + 15, "����԰����", HEI, 24, 1, 0x0000);
        //         break;
        //     case 17:
        //         PrintText(35, y_offset + 15, "�ٻ�԰����", HEI, 24, 1, 0x0000);
        //         break;
        //     case 18:
        //         PrintText(35, y_offset + 15, "��Էѧ������", HEI, 24, 1, 0x0000);
        //         break;
        //     case 19:
        //         PrintText(35, y_offset + 15, "��԰ѧ������", HEI, 24, 1, 0x0000);
        //         break;
        //     case 20:
        //         PrintText(35, y_offset + 15, "����ѧ������", HEI, 24, 1, 0x0000);
        //         break;
        // }

        // switch (order.community)
        // {
        //     case 0:
        //         PrintText(500, y_offset + 15, "����", HEI, 24, 1, 0x0000);
        //         break;
        //     case 1:
        //         PrintText(500, y_offset + 15, "����ѧ������", HEI, 24, 1, 0x0000);
        //         break;
        //     case 2:
        //         PrintText(500, y_offset + 15, "����ѧ������", HEI, 24, 1, 0x0000);
        //         break;
        //     case 3:
        //         PrintText(500, y_offset + 15, "����ѧ������", HEI, 24, 1, 0x0000);
        //         break;
        //     case 4:
        //         PrintText(500, y_offset + 15, "��ݿѧ������", HEI, 24, 1, 0x0000);
        //         break;
        //     case 5:
        //         PrintText(500, y_offset + 15, "��Էѧ������", HEI, 24, 1, 0x0000);
        //         break;
        // }
        // // ��ʾ����������Ϣ
        // sprintf(order_id, "����%d", i + 1);
        // PrintText(35, y_offset + 15, order_id, HEI, 24, 1, 0x0000);

        // sprintf(user_info, "�µ��ˣ�%s", order.user_name);
        // PrintText(35, y_offset + 65, user_info, HEI, 24, 1, 0x0000);

        
        sprintf(total_price, "�ܼۣ�%.2f", order.total_amount);
        PrintText(800, y_offset + 15, total_price, HEI, 24, 1, 0x0000);

        PrintText(665, y_offset + 65, order.order_time, HEI, 24, 1, 0x0000);

        y_offset += 120; // ÿ��������֮��ļ��
    }

    // ���Ʒ�ҳ��ť
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // ��һҳ
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // ��һҳ
    PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);   
}