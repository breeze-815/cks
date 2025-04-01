#include "all_func.h"
void business_detail(int order_index) {
    
    OrderList OL = {0};

    int page = 0;// ��ʼҳ��
    int totalPage; // ��ҳ��

    ReadAllOrder(&OL); // ��ȡ�����б�

    totalPage =(OL.elem[order_index].itemCount  - 6 + 11 ) / 12 + 1 ; // ��ҳ��(����ȡ��)

    mouse_off_arrow(&mouse);

    draw_business_detail(&OL, order_index ,page); // ���ƶ�������ҳ��

    mouse_on_arrow(mouse);

    while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            DestroyOList(&OL); // �ͷŶ����б��ڴ�
            return;
			//business_order();//����
		}
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_business_detail(&OL, order_index ,page);
            } else {
                // ��ʾ�����ǵ�һҳ
                PrintCC(550, 25, "���ǵ�һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 25, 700, 60, white);
            }
        }
		else if (mouse_press(420, 700, 540, 750) == 1) 
		{
			if (page < totalPage - 1) {
				page++;
				draw_business_detail(&OL, order_index ,page);
			} else {
				// ��ʾ���������һҳ
				PrintCC(550, 25, "�������һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 25, 700, 60, white);
			}
		}
    }
}

void draw_business_detail(OrderList *OL ,int order_index,int page) {
    int i;
    Order currentOrder ; 

    char current_time[20]; // ��ȡ��ǰʱ��
    char time_str[100]; // ��ӡ�µ�ʱ��
    char user_name[100]; // ��ӡ�û���
    char user_phone[100]; // ��ӡ�û��ֻ���
    char order_number; // ��ӡ������

    int startIdx = 0;// ��ʼ��Ʒ����
    int itemsPerPage = 0;// ÿҳ��Ʒ����
    int endIdx = 0;// ������Ʒ����
    int item_y = 0;// ��Ʒ���y����

    float total_amount = 0.0; // �ܽ��
    char total_str[20]; // �ܽ���ַ���
    int fullPageItemCount = 0; // ��ҳ��Ʒ����

    currentOrder = OL->elem[order_index]; // ��ǰ����
    strcpy(current_time, currentOrder.order_time);

    sprintf(time_str, "�µ�ʱ�䣺%s", current_time);
    sprintf(user_name, "�û�����%s", currentOrder.user_name);
    sprintf(user_phone, "�ֻ��ţ�%s", currentOrder.user_phone);

    bar1(200, 0, 1024, 768, white); // �����Ļ

    // ��ҳ��ť
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // ��һҳ
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // ��һҳ
    PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue); // ȷ�ϲ�֧��
    PrintCC(830, 715, "ȷ�ϲ�֧��", HEI, 24, 1, deepblue);

    // ҳͷ��Ϣֻ�ڵ�һҳ��ʾ
    if (page == 0) {
        char order_number_str[20]; // �������ַ���
        sprintf(order_number_str, "�����ţ�%d", currentOrder.id); // ������
        PrintText(250, 50, order_number_str, HEI, 24, 1, black);
        PrintText(250, 100, time_str, HEI, 24, 1, black);
        PrintText(250, 150, user_name, HEI, 24, 1, black);
        PrintText(250, 200, user_phone, HEI, 24, 1, black);

        switch(currentOrder.address){// �����û���ַ��ʾ��ַ
            case 1: PrintText(250, 250, "��ַ����ݿѧ����Ԣ", HEI, 24, 1, black); break;
            case 2: PrintText(250, 250, "��ַ����Էѧ����Ԣ", HEI, 24, 1, black); break;
            case 3: PrintText(250, 250, "��ַ����Էѧ����Ԣ", HEI, 24, 1, black); break;
            default: PrintText(250, 250, "��ַ��δ֪", HEI, 24, 1, black); break;
        }

        // ��ͷ
        PrintCC(250, 300, "��Ʒ���飺", HEI, 24, 1, black);
        PrintCC(750, 300, "������", HEI, 24, 1, black);
        PrintCC(900, 300, "��", HEI, 24, 1, black);
        PrintText(250, 320, "-------------------------------", HEI, 32, 1, black);// �ָ���

        startIdx = 0;
        itemsPerPage = 6;
    } else {
        startIdx = 6 + (page - 1) * 12;
        itemsPerPage = 12;
    }

    endIdx = startIdx + itemsPerPage;
    if (endIdx > currentOrder.itemCount)// ��ֹԽ��
        endIdx = currentOrder.itemCount;

    item_y = (page == 0) ? 350 : 50;
    for (i = startIdx; i < endIdx; i++) {
        char total_str[50]; // ��Ʒ�ܼ�
        char quantity_str[20]; // ��Ʒ����
        int quantity = currentOrder.item[i].quantity; // ��Ʒ����
        float price = currentOrder.item[i].price; // ��Ʒ�۸�

        sprintf(total_str, "%.2f", price * quantity);
        sprintf(quantity_str, "x%d", quantity);

        PrintCC(250, item_y, currentOrder.item[i].name, HEI, 24, 1, black); // ��Ʒ��
        PrintText(750, item_y, (unsigned char*)quantity_str, HEI, 24, 1, black);
        PrintText(900, item_y, (unsigned char*)total_str, HEI, 24, 1, black);

        item_y += 50;
    }

    // �ж��Ƿ���Ҫ�ڴ�ҳ��ʾ�ܽ���ǰҳû������
    fullPageItemCount = (page == 0) ? 6 : 12;// ��һҳ��ʾ6����Ʒ������ҳ��ʾ12����Ʒ
    if ((endIdx - startIdx) < fullPageItemCount||endIdx==currentOrder.itemCount) {// ��ǰҳ��Ʒ��������һҳ�����һ����Ʒ�պ���ҳ��Ҫ��ӡ���ܽ��
        //����������һ����Ʒ������ҳ�Ͳ���ӡ�ܽ��
        // ��ӡ�ָ���
        PrintText(250, item_y - 30, "-------------------------------", HEI, 32, 1, black);

        // �����ܽ��
        total_amount = 0.0;
        for (i = 0; i < currentOrder.itemCount; i++) {
            int quantity = currentOrder.item[i].quantity; // ��Ʒ����
            float price = currentOrder.item[i].price; // ��Ʒ�۸�
            total_amount += price * quantity;
        }

        sprintf(total_str, "�ܽ�%.2f Ԫ", total_amount);
        PrintText(750, item_y + 10, total_str, HEI, 24, 1, black);
    
    }
}