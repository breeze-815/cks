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

//���ƶ�����Ϣҳ��
void draw_b_order_info(Order currentOrder) {
    char time_str[100], user_name[100], user_phone[100], order_number_str[20];

    sprintf(order_number_str, "�����ţ�%d", currentOrder.id);
    sprintf(time_str, "�µ�ʱ�䣺%s", currentOrder.order_time);
    sprintf(user_name, "�û�����%s", currentOrder.user_name);
    sprintf(user_phone, "�ֻ��ţ�%s", currentOrder.user_phone);

    PrintText(250, 50, order_number_str, HEI, 24, 1, black);
    PrintText(250, 100, time_str, HEI, 24, 1, black);
    PrintText(250, 150, user_name, HEI, 24, 1, black);
    PrintText(250, 200, user_phone, HEI, 24, 1, black);

    switch (currentOrder.address) {
        case 1: PrintText(250, 250, "��ַ����ݿѧ����Ԣ", HEI, 24, 1, black); break;
        case 2: PrintText(250, 250, "��ַ����Էѧ����Ԣ", HEI, 24, 1, black); break;
        case 3: PrintText(250, 250, "��ַ����Էѧ����Ԣ", HEI, 24, 1, black); break;
        default: PrintText(250, 250, "��ַ��δ֪", HEI, 24, 1, black); break;
    }

    PrintCC(250, 300, "��Ʒ���飺", HEI, 24, 1, black);
    PrintCC(750, 300, "������", HEI, 24, 1, black);
    PrintCC(900, 300, "��", HEI, 24, 1, black);
    PrintText(250, 320, "-------------------------------", HEI, 32, 1, black);
}

//���Ʒ�ҳ��ť
void draw_b_pagination_buttons() {
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue);
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue);
    PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue);
    PrintCC(850, 715, "��ʼ����", HEI, 24, 1, deepblue);
}

//���ƶ�����Ʒ��Ϣ
void draw_b_order_items(Order currentOrder, int startIdx, int endIdx, int item_y) {
    int i;
    char total_str[50], quantity_str[20];
    int quantity;
    float price;

    for (i = startIdx; i < endIdx; i++) {
        quantity = currentOrder.item[i].quantity;
        price = currentOrder.item[i].price;

        sprintf(total_str, "%.2f", price * quantity);
        sprintf(quantity_str, "x%d", quantity);

        PrintCC(250, item_y, currentOrder.item[i].name, HEI, 24, 1, black);
        PrintText(750, item_y, (unsigned char*)quantity_str, HEI, 24, 1, black);
        PrintText(900, item_y, (unsigned char*)total_str, HEI, 24, 1, black);

        item_y += 50;
    }
}

//�����ܽ��
void draw_b_total_amount(Order currentOrder, int item_y) {
    int i;
    float total_amount;
    char total_str[20];

    total_amount = 0.0;
    for (i = 0; i < currentOrder.itemCount; i++) {
        total_amount += currentOrder.item[i].price * currentOrder.item[i].quantity;
    }

    PrintText(250, item_y - 30, "-------------------------------", HEI, 32, 1, black);
    sprintf(total_str, "�ܽ�%.2f Ԫ", total_amount);
    PrintText(750, item_y + 10, total_str, HEI, 24, 1, black);
}

//���ƶ�������ҳ��
void draw_business_detail(OrderList *OL, int order_index, int page) {
    Order currentOrder;
    int startIdx, itemsPerPage, endIdx, item_y;
    int fullPageItemCount;

    currentOrder = OL->elem[order_index];

    if (page == 0) {
        startIdx = 0;
        itemsPerPage = 6;
    } else {
        startIdx = 6 + (page - 1) * 12;
        itemsPerPage = 12;
    }

    if (startIdx + itemsPerPage > currentOrder.itemCount) {
        endIdx = currentOrder.itemCount;
    } else {
        endIdx = startIdx + itemsPerPage;
    }

    if (page == 0) {
        item_y = 350;
    } else {
        item_y = 50;
    }

    fullPageItemCount = (page == 0) ? 6 : 12;

    bar1(200, 0, 1024, 768, white);//��ջ���
    draw_b_pagination_buttons();//���Ʒ�ҳ��ť
    if (page == 0) draw_b_order_info(currentOrder);//���ƶ�����Ϣ
    draw_b_order_items(currentOrder, startIdx, endIdx, item_y);//���ƶ�����Ʒ��Ϣ

    if ((endIdx - startIdx) < fullPageItemCount || endIdx == currentOrder.itemCount) {
        draw_b_total_amount(currentOrder, item_y);//�����ܽ��
    }
}

