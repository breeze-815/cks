#include "all_func.h"

void business_order(){
    int page = 0; // ��ǰҳ��

    OrderList OL = {0};

    ReadAllOrder(&OL); // ��ȡ�����б�

    mouse_off_arrow(&mouse);
	
	draw_business_order(page,&OL);

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            DestroyOList(&OL); // �ͷŶ����б��ڴ�
            return;
			//business(users.pos);
		}
        else if(mouse_press(490, 100, 610, 150)==1)
        {
            press_type(1);//���볬��ҳ��
        }
        else if(mouse_press(670, 100, 790, 150)==1)
        {
            press_type(2);//����ѡ�����ҳ��
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            business_order();//�̼Ҷ���ҳ��
        }else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_business_order(page,&OL);
            } else {
                // ��ʾ�����ǵ�һҳ
                PrintCC(550, 35, "���ǵ�һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 35, 700, 60, white);
            }
        }
		else if (mouse_press(420, 700, 540, 750) == 1) 
		{
			if ((page + 1) * 5 < OL.length) {
				page++;
                draw_business_order(page,&OL);
			} else {
				// ��ʾ���������һҳ
				PrintCC(550, 35, "�������һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 35, 700, 60, white);
			}
		}
        else if(mouse_press(200, 0, 1024, 680) == 1) {
            int order_index = (mouse.y - 25) / 120 + page * 5; // ���ݵ��λ�ü��㶩������

			MouseGet(&mouse);

            if (order_index >= 0 && order_index < OL.length) 
            {
                business_detail(order_index); // ��ʾ��������
                //return����⿪ʼ
                mouse_off_arrow(&mouse);
                bar1(200, 0, 1024, 768, white); // �����������������
                draw_business_order(page,&OL); // ���»��ƶ����б�
                mouse_on_arrow(mouse);
            }
		}
    }
}

void draw_business_order(int page,OrderList *OL){

    int i;
    int y_offset = 25; // ��ʼY��ƫ��

    int orders_per_page = 5; // ÿҳ�����ʾ5������
    int start_index = page * orders_per_page; // ��ǰҳ����ʼ��������
    int end_index = start_index + orders_per_page; // ��ǰҳ�Ľ�����������

    if (end_index > OL->length) {
        end_index = OL->length; // ��ֹԽ��
    }

    bar1(200, 0, 1024, 768,white);

    Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//������ɫ
    Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//����//Բ�ǰ�ť���ֵ�x+35��y+15
    PrintCC(75,128,"����",HEI,24,1,deepblue);

    
    for (i = start_index; i < end_index; i++) {
        char order_id[10]; // ����ID�ַ���
        char user_info[16]; // �û���Ϣ�ַ���
        char total_price[10];// �ܼ��ַ���

        Order order = OL->elem[i]; // ��ȡ��ǰ����

        // ���ƶ�����
        Draw_Rounded_Rectangle(220, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

        // ��ʾ����������Ϣ
        sprintf(order_id, "����%d", i + 1);
        PrintText(235, y_offset + 15, order_id, HEI, 24, 1, 0x0000);

        sprintf(user_info, "�µ��ˣ�%s", order.user_name);
        PrintText(235, y_offset + 65, user_info, HEI, 24, 1, 0x0000);

        
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

