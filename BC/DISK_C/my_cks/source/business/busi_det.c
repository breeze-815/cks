#include "all_func.h"
void business_detail(int order_index,int index) {
    
    OrderList OL = {0};
    FoodList FL = {0};
    FoodOrder target_order[12];

    int page = 0;// ��ʼҳ��
    int totalPage; // ��ҳ��
    int i;
    int cnt=0;

    ReadAllOrder(&OL); // ��ȡ�����б�
    ReadAllFood(&FL); // ��ȡʳ���б�


    //�������ֶ�����Դ�������Ҽ�����ҳ��
    if(index==0){
        totalPage =(OL.elem[order_index].itemCount  - 6 + 11 ) / 12 + 1 ; // ��ҳ��(����ȡ��)
    }else {
        for(i=0;i<FL.length;i++)
        {
        	if(FL.elem[i].station==index)//�ҵ���Ӧ�Ķ���
        	{
        		target_order[cnt]=FL.elem[i];//����target_order����,��ʱ���target��OL.elem�ǲ��е�
        		cnt++;

        	}
        }
        totalPage =(target_order[order_index].itemCount - 6 + 11 ) / 12 + 1 ; // ��ҳ��(����ȡ��)
    }


    mouse_off_arrow(&mouse);

    draw_business_detail(&OL,target_order, order_index ,page,index); // ���ƶ�������ҳ��

    mouse_on_arrow(mouse);

    while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            DestroyOList(&OL); // �ͷŶ����б��ڴ�
            DestroyFList(&FL); // �ͷ�ʳ���б��ڴ�
            return;
			//business_order();//����
		}
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_business_detail(&OL,target_order, order_index ,page,index);
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
				draw_business_detail(&OL,target_order, order_index ,page,index);
			} else {
				// ��ʾ���������һҳ
				PrintCC(550, 25, "�������һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 25, 700, 60, white);
			}
		}
    }
}

void draw_business_detail(OrderList *OL ,FoodOrder target_order[],int order_index,int page,int index) {
    int i;
    Order currentOrder ; 
    FoodOrder currentFood;

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

    bar1(200, 0, 1024, 768, white); // �����Ļ

    // ��ҳ��ť
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // ��һҳ
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // ��һҳ
    PrintCC(245, 715, "��һҳ", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "��һҳ", HEI, 24, 1, deepblue);

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue); // ��ʼ����
    PrintCC(850, 715, "��ʼ����", HEI, 24, 1, deepblue);

    if(index==0)
    {
        currentOrder = OL->elem[order_index]; // ��ǰ����
        strcpy(current_time, currentOrder.order_time);

        sprintf(time_str, "�µ�ʱ�䣺%s", current_time);
        sprintf(user_name, "�û�����%s", currentOrder.user_name);
        sprintf(user_phone, "�ֻ��ţ�%s", currentOrder.user_phone);
    }
    else 
    {
        currentFood = target_order[order_index]; // ��ǰ����
        strcpy(current_time, currentFood.order_time);

        sprintf(time_str, "�µ�ʱ�䣺%s", current_time);
        sprintf(user_name, "�û�����%s", currentFood.user_name);
        sprintf(user_phone, "�ֻ��ţ�%s", currentFood.user_phone);
    }


    // ҳͷ��Ϣֻ�ڵ�һҳ��ʾ
    if (page == 0) {
        char order_number_str[20]; // �������ַ���
        char community[50]; // �����ַ���
        char building[50]; // ¥���ַ���


        if(index==0)
        {
            sprintf(order_number_str, "�����ţ�%d", currentOrder.id); // ������
            switch(currentOrder.community){// �����û���ַ��ʾ��ַ
                case 1: strcpy(community,"��ַ������ѧ����Ԣ"); break;
                case 2: strcpy(community,"��ַ������ѧ����Ԣ"); break;
                case 3: strcpy(community,"��ַ������ѧ����Ԣ"); break;
                case 4: strcpy(community,"��ַ����ݿѧ����Ԣ"); break;
                case 5: strcpy(community,"��ַ����Էѧ����Ԣ"); break;
                default: strcpy(community,"��ַ��δ֪"); break;
            }
            sprintf(building, "%d��", currentOrder.building);
        }
        else 
        {
            sprintf(order_number_str, "�����ţ�%d", currentFood.id); // ������
            switch(currentFood.community){// �����û���ַ��ʾ��ַ
                case 1: strcpy(community,"��ַ������ѧ����Ԣ"); break;
                case 2: strcpy(community,"��ַ������ѧ����Ԣ"); break;
                case 3: strcpy(community,"��ַ������ѧ����Ԣ"); break;
                case 4: strcpy(community,"��ַ����ݿѧ����Ԣ"); break;
                case 5: strcpy(community,"��ַ����Էѧ����Ԣ"); break;
                default: strcpy(community,"��ַ��δ֪"); break;
            }
            sprintf(building, "%d��", currentFood.building);
        }
        
        PrintText(250, 50, order_number_str, HEI, 24, 1, black);
        PrintText(250, 100, time_str, HEI, 24, 1, black);
        PrintText(250, 150, user_name, HEI, 24, 1, black);
        PrintText(250, 200, user_phone, HEI, 24, 1, black);

<<<<<<< Updated upstream
        switch(currentOrder.address){// �����û���ַ��ʾ��ַ
            case 1: PrintText(250, 250, "��ַ����ݿѧ����Ԣ", HEI, 24, 1, black); break;
            case 2: PrintText(250, 250, "��ַ����Էѧ����Ԣ", HEI, 24, 1, black); break;
            case 3: PrintText(250, 250, "��ַ����Էѧ����Ԣ", HEI, 24, 1, black); break;
            default: PrintText(250, 250, "��ַ��δ֪", HEI, 24, 1, black); break;
        }
=======
        strcat(community,building);
        PrintText(250, 250, community, HEI, 24, 1, black);
>>>>>>> Stashed changes

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

    if (index==0)
    {
        if (endIdx > currentOrder.itemCount)// ��ֹԽ��
            endIdx = currentOrder.itemCount;
    }
    else 
    {
        if (endIdx > currentFood.itemCount)// ��ֹԽ��
            endIdx = currentFood.itemCount;
    }

    item_y = (page == 0) ? 350 : 50;
    for (i = startIdx; i < endIdx; i++) {
        char total_str[50]; // ��Ʒ�ܼ�
        char quantity_str[20]; // ��Ʒ����

        if(index==0)
        {
            int quantity = currentOrder.item[i].quantity; // ��Ʒ����
            float price = currentOrder.item[i].price; // ��Ʒ�۸�

            sprintf(total_str, "%.2f", price * quantity);
            sprintf(quantity_str, "x%d", quantity);

            PrintCC(250, item_y, currentOrder.item[i].name, HEI, 24, 1, black); // ��Ʒ��
        }
        else 
        {
            int quantity = currentFood.item[i].quantity; // ��Ʒ����
            float price = currentFood.item[i].price; // ��Ʒ�۸�

            sprintf(total_str, "%.2f", price * quantity);
            sprintf(quantity_str, "x%d", quantity);

            PrintCC(250, item_y, currentFood.item[i].name, HEI, 24, 1, black); // ��Ʒ��
        }
        

        

        PrintText(750, item_y, (unsigned char*)quantity_str, HEI, 24, 1, black);// ��Ʒ����
        PrintText(900, item_y, (unsigned char*)total_str, HEI, 24, 1, black);// ��Ʒ�ܼ�

        item_y += 50;
    }

    // �ж��Ƿ���Ҫ�ڴ�ҳ��ʾ�ܽ���ǰҳû������
    fullPageItemCount = (page == 0) ? 6 : 12;// ��һҳ��ʾ6����Ʒ������ҳ��ʾ12����Ʒ

    if (index==0)
    {
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
    else 
    {
        if ((endIdx - startIdx) < fullPageItemCount||endIdx==currentFood.itemCount) {// ��ǰҳ��Ʒ��������һҳ�����һ����Ʒ�պ���ҳ��Ҫ��ӡ���ܽ��
            //����������һ����Ʒ������ҳ�Ͳ���ӡ�ܽ��
            // ��ӡ�ָ���
            PrintText(250, item_y - 30, "-------------------------------", HEI, 32, 1, black);
    
            // �����ܽ��
            total_amount = 0.0;
            for (i = 0; i < currentFood.itemCount; i++) {
                int quantity = currentFood.item[i].quantity; // ��Ʒ����
                float price = currentFood.item[i].price; // ��Ʒ�۸�
                total_amount += price * quantity;
            }
    
            sprintf(total_str, "�ܽ�%.2f Ԫ", total_amount);
            PrintText(750, item_y + 10, total_str, HEI, 24, 1, black);
        
        }
    }
    
}