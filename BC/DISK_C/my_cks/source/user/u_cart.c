#include "all_func.h"

void user_cart() {
    int page = 0;// ��ʼҳ��
    int totalPage = (cart.itemCount + 3) / 4; // ����ȡ��
    float sum=0;//�ܼ�

    mouse_off_arrow(&mouse);

    draw_user_cart(carts, cart.itemCount, page,&sum);
    mouse_on_arrow(mouse);

    while (1) {
        mouse_show_arrow(&mouse);

        // ��������̵�
        if (mouse_press(40, 113, 160, 163) == 1) 
		{
            user_shop();
            return;
        }
		else if (mouse_press(800, 700, 1000, 750) == 1)
		{
            if(sum<10.0)
            {
                PrintText(500, 25, "δ��10Ԫ���޷�����", HEI, 24, 1, lightred);
				delay(500);
				bar1(500, 25, 750, 60, white);
            }
            else
            {
                user_order();// ������ɶ�����ť�����붩��ҳ��

                //return����⿪ʼ
                mouse_off_arrow(&mouse);
                bar1(200, 0, 1024, 768, white); // ���ע��������
                draw_user_cart(carts, cart.itemCount, page,&sum);
                mouse_on_arrow(mouse);
            }
            
		}
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_user_cart(carts, cart.itemCount, page,&sum);
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
				draw_user_cart(carts, cart.itemCount, page,&sum);
			} else {
				// ��ʾ���������һҳ
				PrintCC(550, 25, "�������һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 25, 700, 60, white);
			}
		}
		else if(mouse_press(270, 0, 1024, 680) == 1) {
			MouseGet(&mouse);
			AddSub_cart(mouse.x, mouse.y, carts, &cart.itemCount, page,&sum);
			delay(100);
		}
		
    }
}


void draw_user_cart(CartItem carts[], int cartCount, int page,float *sum) {
    int i,k;//ѭ������
    int start = page * 4;// ��ʼ��Ʒ����
    int end = start + 4;// ������Ʒ����
    char sum_str[20];//�ܼ��ַ���
    if (end > cartCount) end = cartCount;// ��ֹԽ��

    bar1(200, 0, 1024, 768, white);
    bar1(0, 250, 199, 768, deepblue);

    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // ��һҳ
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // ��һҳ
    PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue); // ���ɶ���
    PrintCC(850, 715, "���ɶ���", HEI, 24, 1, deepblue);

    for (i = start; i < end; i++) {//��ʾ��Ʒ��Ϣ
        char total_str[50];//��Ʒ�ܼ�
        char quantity_str[20];//��Ʒ����
        char type_str[20];//������
        int y = 10 + 170 * (i - start);//��Ʒ���y����
        int productIndex = carts[i].index_in_products;//��Ʒ����
        int quantity = products[productIndex].quantity;//��Ʒ����

        sprintf(total_str, "���:%.2f", products[productIndex].price * quantity);//�����ת��Ϊ�ַ���
        sprintf(quantity_str, "x%d", quantity);//������ת��Ϊ�ַ���

        switch(products[productIndex].type){//������Ʒ������ʾ������
            case 1: strcpy(type_str, "������Ʒ"); break;
            case 2: strcpy(type_str, "�ľ�"); break;
            case 3: strcpy(type_str, "��ʳ"); break;
            case 4: strcpy(type_str, "����"); break;
            case 5: strcpy(type_str, "�˶���Ʒ"); break;
            case 6: strcpy(type_str, "ˮ��"); break;
            case 7: strcpy(type_str, "�Ĵ�"); break;
            default: strcpy(type_str, "δ֪"); break;
        }
       
        Draw_Rounded_Rectangle(220, y, 1000, y + 150, 30, 1, 0x6B4D);//��Ʒ��
        Readbmp64k(240, y + 15, carts[i].photo);//��ʾ��ƷͼƬ

        PrintCC(370, y + 15, carts[i].name, HEI, 32, 1, 0x0000);//��ʾ��Ʒ��
        PrintCC(370, y + 110, type_str, HEI, 24, 1, 0x0000);//��ʾ������
        PrintText(760, y + 15, (unsigned char*)total_str, HEI, 32, 1, 0x0000);//��ʾ���
        PrintText(920, y + 60, (unsigned char*)quantity_str, HEI, 32, 1, 0x0000);//��ʾ����

        Line_Thick(840, y + 120, 860, y + 120, 1, black); // ����

        Line_Thick(940, y + 120, 960, y + 120, 1, black); // �Ӻź�
        Line_Thick(950, y + 110, 950, y + 130, 1, black); // �Ӻ���
    }

    *sum = 0;
    for (k = 0; k < cart.itemCount; k++) {
        int pIndex = carts[k].index_in_products;
        *sum += products[pIndex].price * products[pIndex].quantity;
    }//�����ܼ�

    sprintf(sum_str, "�ܼ�:%.2f", *sum);
    PrintText(560,710, (unsigned char*)sum_str, HEI, 32, 1, 0x0000);//��ʾ���
}

// ������ʾ��Ʒ����
void draw_user_cart_quantity(CartItem carts[], int index, int y) {
    char total_str[50];
    char quantity_str[20];
    char sum_str[20];
    float sum = 0;
    int i;

    int productIndex = carts[index].index_in_products;
    int quantity = products[productIndex].quantity;

    sprintf(total_str, "���:%.2f", products[productIndex].price * quantity);
    sprintf(quantity_str, "x%d", quantity);

    // === ���¼����������ﳵ�ܼ� ===
    for (i = 0; i < cart.itemCount; i++) {
        int pIndex = carts[i].index_in_products;
        sum += products[pIndex].price * products[pIndex].quantity;
    }
    sprintf(sum_str, "�ܼ�:%.2f", sum);

    // === ���ԭ����ֵ��ʾ���� ===
    bar1(760, y + 15, 990, y + 60, white); // �������
    bar1(920, y + 60, 990, y + 90, white); // ��������
    bar1(560, 710, 790, 750, white);       // �ܼ�����

    // === ��ʾ����ֵ ===
    PrintText(760, y + 15, (unsigned char*)total_str, HEI, 32, 1, 0x0000);     // ��ʾ����Ʒ���
    PrintText(920, y + 60, (unsigned char*)quantity_str, HEI, 32, 1, 0x0000);  // ��ʾ����Ʒ����
    PrintText(560, 710, (unsigned char*)sum_str, HEI, 32, 1, 0x0000);          // ��ʾ�������ﳵ�ܼ�
}


// ��ӻ���ٹ��ﳵ����Ʒ����
void AddSub_cart(int mx, int my, CartItem carts[], int* itemCount, int currentPage,float *sum) {
    int i,k;
    int start = currentPage * 4;
    int end = start + 4;
    if (end > *itemCount) end = *itemCount;

    for (i = start; i < end; i++) {
        int localIndex = i - start;
        int y = 10 + 170 * localIndex;
        int productIndex = carts[i].index_in_products; // ӳ��� products

        // ��������
        if (mx >= 840 && mx <= 860 && my >= y + 115 && my <= y + 125) {
            if (products[productIndex].quantity > 1) {
                products[productIndex].quantity--;
                // ���¼����ܼ�
                *sum = 0;
                for (k = 0; k < cart.itemCount; k++) 
                {
                    int pIndex = carts[k].index_in_products;
                    *sum += products[pIndex].price * products[pIndex].quantity;
                }
                draw_user_cart_quantity(carts, i, y); // �����¸���Ʒ
            } else {
				int j;
                // �Ƴ���Ʒ
                products[productIndex].quantity = 0;

                // �ӹ��ﳵ���Ƴ�
                
                for (j = i; j < *itemCount - 1; j++) {
                    carts[j] = carts[j + 1];
                }
                (*itemCount)--;
                
                // �����ܼ�
                *sum = 0;
                for (k = 0; k < cart.itemCount; k++) 
                {
                    int pIndex = carts[k].index_in_products;
                    *sum += products[pIndex].price * products[pIndex].quantity;
                }
                draw_user_cart(carts, *itemCount, currentPage,&sum); // �ػ�����ҳ��
            }
            return;
        }

        // �Ӻ�����
        if (mx >= 940 && mx <= 960 && my >= y + 115 && my <= y + 125) {
            products[productIndex].quantity++;
            for (k = 0; k < cart.itemCount; k++) {
                int pIndex = carts[k].index_in_products;
                *sum += products[pIndex].price * products[pIndex].quantity;
            }
            draw_user_cart_quantity(carts, i, y); // �����¸���Ʒ
            return;
        }
    }
}



