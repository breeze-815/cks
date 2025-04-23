#include "all_func.h"

void business_order(int index){
    int page = 0; // ��ǰҳ��

    OrderList OL = {0};
    FoodList FL = {0};

    ReadAllOrder(&OL); // ��ȡ�����б�
    ReadAllFood(&FL); // ��ȡʳƷ�б�

    mouse_off_arrow(&mouse);
	
	draw_business_order(page,&OL,&FL,index);

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            DestroyOList(&OL); // �ͷŶ����б��ڴ�
            DestroyFList(&FL); // �ͷ�ʳƷ�б��ڴ�
            return;
			//business(users.pos);
		}
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_business_order(page,&OL,&FL,index);
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
                draw_business_order(page,&OL,&FL,index);
			} else {
				// ��ʾ���������һҳ
				PrintCC(550, 35, "�������һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 35, 700, 60, white);
			}
		}
        else if(mouse_press(200, 0, 1024, 680) == 1) {

            int order_index = (mouse.y - 25) / 120 + page * 5; // ���ݵ��λ�ü��㶩������
            //���order_index�ǻ���չʾ��ҳ�����������������food,����target�����������Ϊ�Ǵ�target��չʾ��
            //order_index�Զ��߶�����
            //����index��Ϊ�����ֳ��кͲ�ͬʳ�ã������ʳ�þ�Ҫ��target��չʾ
			MouseGet(&mouse);
            business_detail(order_index,index); // ��ʾ��������

            //return����⿪ʼ
            mouse_off_arrow(&mouse);
            bar1(200, 0, 1024, 768, white); // �����������������
            draw_business_order(page,&OL,&FL,index); // ���»��ƶ����б�
            mouse_on_arrow(mouse);
		}
    }
}

void draw_business_order(int page,OrderList *OL,FoodList *FL,int index){

    int i;
    int cnt=0;
    int y_offset = 25; // ��ʼY��ƫ��

    FoodOrder target_order[12];

    // ÿҳ�����ʾ5������
    int start_index = page * 5; // ��ǰҳ����ʼ��������
    int end_index = start_index + 5; // ��ǰҳ�Ľ�����������

    if(index==0){//
        if (end_index > OL->length) 
        {
            end_index = OL->length; // ��ֹԽ��
        }
    }
    else
    {
        for(i=0;i<FL->length;i++)
        {
        	if(FL->elem[i].station==index)//�ҵ���Ӧ�Ķ���
        	{
        		target_order[cnt]=FL->elem[i];
        		cnt++;

        	}
        }
        if (end_index > cnt) 
        {
            end_index = cnt; // ��ֹԽ��
        }

    }
    
    bar1(200, 0, 1024, 768,white);

    Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//������ɫ
    Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//����//Բ�ǰ�ť���ֵ�x+35��y+15
    PrintCC(75,128,"����",HEI,24,1,deepblue);

    
    for (i = start_index; i < end_index; i++) {
        char order_id[10]; // ����ID�ַ���
        char user_info[16]; // �û���Ϣ�ַ���
        char total_price[10];// �ܼ��ַ���

        if(index==0){
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
        }else if(index>0)
        {
                FoodOrder food_order = target_order[i];// ��ȡ��ǰ����

                // ���ƶ�����
                Draw_Rounded_Rectangle(220, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);
    
                // ��ʾ����������Ϣ
                sprintf(order_id, "����%d", i + 1);
                PrintText(235, y_offset + 15, order_id, HEI, 24, 1, 0x0000);
    
                sprintf(user_info, "�µ��ˣ�%s", food_order.user_name);
                PrintText(235, y_offset + 65, user_info, HEI, 24, 1, 0x0000);
    
                
                sprintf(total_price, "�ܼۣ�%.2f", food_order.total_amount);
                PrintText(800, y_offset + 15, total_price, HEI, 24, 1, 0x0000);
    
                PrintText(665, y_offset + 65, food_order.order_time, HEI, 24, 1, 0x0000);
    
                y_offset += 120; // ÿ��������֮��ļ��
            }
            
        }

    // ���Ʒ�ҳ��ť
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // ��һҳ
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // ��һҳ
    PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);
}

