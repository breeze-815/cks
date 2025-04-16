#include "all_func.h"

Order orders = {0}; // ����

void user_order(){

    UserList UL = {0};
    USER *currentUser;

    int page = 0;// ��ʼҳ��
    int totalPage =(cart.itemCount - 6 + 11 ) / 12 + 1 ; // ��ҳ��(����ȡ��)
    
    ReadAllUser(&UL); // ��ȡ�û��б�

    currentUser=&UL.elem[users.pos];// ��ȡ��ǰ�û���Ϣ

    DestroyUList(&UL); // �ͷ��û��б�ռ�

    mouse_off_arrow(&mouse);

    draw_user_order(page);

    mouse_on_arrow(mouse);

    while(1){
        mouse_show_arrow(&mouse);

        if (mouse_press(40, 113, 160, 163) == 1) 
        {
            //user_cart();// �����û����ﳵҳ��
            return;
        }
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_user_order(page);// �����û�����ҳ��
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
				draw_user_order(page);// �����û�����ҳ��
			} else {
				// ��ʾ���������һҳ
				PrintCC(550, 25, "�������һҳ", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 25, 700, 60, white);
			}
		}
        else if(mouse_press(800, 700, 1000, 750) == 1)
        { 
            if (currentUser->community == '\0' || strlen(currentUser->number) == 0)
            {
                draw_info();
            }
            else
            {
                save_order(orders); // ���涩��
                PrintCC(800, 50, "�����ѱ���", HEI, 24, 1, lightred);
                delay(500);
                bar1(800, 50, 1024, 100, white);
            }
        }
    }
}

void draw_user_order(int page){
    int i;
    UserList UL = {0};
    OrderList OL = {0};
    USER *currentUser;
    Order *currentOrder;

    char* current_time = get_current_time(); // ��ȡ��ǰʱ��
    char time_str[100]; // ��ӡ�µ�ʱ��
    char user_name[100]; // ��ӡ�û���
    char user_phone[100]; // ��ӡ�û��ֻ���
    char order_number; // ��ӡ������

    int startIdx = 0;// ��ʼ��Ʒ����
    int itemsPerPage = 0;// ÿҳ��Ʒ����
    int endIdx = 0;// ������Ʒ����
    int item_y = 0;// ��Ʒ���y����

    float total_amount = 0.0; // �ܽ��
    char total_str[50]; // �ܽ���ַ���
    int fullPageItemCount = 0; // ��ҳ��Ʒ����

    ReadAllUser(&UL); // ��ȡ�û��б�
    currentUser = &UL.elem[users.pos]; // ��ȡ��ǰ�û���Ϣ

    ReadAllOrder(&OL); // ��ȡ�����б�
    orders.id = OL.length + 1; // ������

    sprintf(time_str, "�µ�ʱ�䣺%s", current_time);
    sprintf(user_name, "�û�����%s", currentUser->name);
    sprintf(user_phone, "�ֻ��ţ�%s", currentUser->number);

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
        sprintf(order_number_str, "�����ţ�%d", orders.id); // ������
        PrintText(250, 50, order_number_str, HEI, 24, 1, black);
        PrintText(250, 100, time_str, HEI, 24, 1, black);
        PrintText(250, 150, user_name, HEI, 24, 1, black);
        PrintText(250, 200, user_phone, HEI, 24, 1, black);

        switch(currentUser->community){// �����û���ַ��ʾ��ַ
            case 0: PrintText(250, 250, "��ַ������", HEI, 24, 1, black); break;
            case 1: PrintText(250, 250, "��ַ������ѧ����Ԣ", HEI, 24, 1, black); break;
            case 2: PrintText(250, 250, "��ַ������ѧ����Ԣ", HEI, 24, 1, black); break;
            case 3: PrintText(250, 250, "��ַ������ѧ����Ԣ", HEI, 24, 1, black); break;
            case 4: PrintText(250, 250, "��ַ����ݿѧ����Ԣ", HEI, 24, 1, black); break;
            case 5: PrintText(250, 250, "��ַ����Էѧ����Ԣ", HEI, 24, 1, black); break;
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
    if (endIdx > cart.itemCount)// ��ֹԽ��
        endIdx = cart.itemCount;

    item_y = (page == 0) ? 350 : 50;
    for (i = startIdx; i < endIdx; i++) {
        char total_str[50]; // ��Ʒ�ܼ�
        char quantity_str[20]; // ��Ʒ����
        int productIndex = carts[i].index_in_products; // ��Ʒ����
        int quantity = products[productIndex].quantity;

        sprintf(total_str, "%.2f", products[productIndex].price * quantity);
        sprintf(quantity_str, "x%d", quantity);

        PrintCC(250, item_y, carts[i].name, HEI, 24, 1, black); // ��Ʒ��
        PrintText(750, item_y, (unsigned char*)quantity_str, HEI, 24, 1, black);
        PrintText(900, item_y, (unsigned char*)total_str, HEI, 24, 1, black);

        item_y += 50;
    }

    // �ж��Ƿ���Ҫ�ڴ�ҳ��ʾ�ܽ���ǰҳû������
    fullPageItemCount = (page == 0) ? 6 : 12;// ��һҳ��ʾ6����Ʒ������ҳ��ʾ12����Ʒ
    if ((endIdx - startIdx) < fullPageItemCount||endIdx==cart.itemCount) {// ��ǰҳ��Ʒ��������һҳ�����һ����Ʒ�պ���ҳ��Ҫ��ӡ���ܽ��
        //����������һ����Ʒ������ҳ�Ͳ���ӡ�ܽ��
        // ��ӡ�ָ���
        PrintText(250, item_y - 30, "-------------------------------", HEI, 32, 1, black);

        // �����ܽ��
        total_amount = 0.0;
        for (i = 0; i < cart.itemCount; i++) {
            int productIndex = carts[i].index_in_products;
            int quantity = products[productIndex].quantity;
            total_amount += products[productIndex].price * quantity;
            carts[i].quantity = quantity; // ��¼���ﳵ��Ʒ����
            carts[i].price = products[productIndex].price; // ��¼��Ʒ�۸�
        }

        sprintf(total_str, "�ܽ�%.2f Ԫ", total_amount);
        PrintText(750, item_y + 10, total_str, HEI, 24, 1, black);
    }

    //�洢������Ϣ
    strcpy(orders.order_time, current_time); // �µ�ʱ��
    strcpy(orders.user_name, currentUser->name); // �û���
    strcpy(orders.user_phone, currentUser->number); // �û��ֻ���
    orders.community=currentUser->community; // �û�����
    orders.building=currentUser->building; 
    for (i = 0; i < cart.itemCount; i++) {
        orders.item[i] = carts[i]; // ���ﳵ����Ʒ��Ϣ
    }
    orders.itemCount = cart.itemCount; // ���ﳵ����Ʒ����
    orders.total_amount = total_amount; // �ܽ��

}

void draw_info(){

    Fill_Rounded_Rectangle(225, 25, 1000, 250, 30,snow);//��ɫ
    Draw_Rounded_Rectangle(225, 25, 1000, 250, 30, 2,0x6B4D);//����Χ��ɫԲ�Ǿ��ο�

    PrintCC(250, 50, "�������Ƹ�����Ϣ", HEI, 24, 1, lightred);

    Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,deepblue);//��ݿ��ť
    Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,deepblue);//��Է��ť
    Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,deepblue);//��Է��ť

    Draw_Rounded_Rectangle(430, 105, 650, 155, 5, 1,deepblue);//�ֻ�������� 
    Draw_Rounded_Rectangle(710, 105, 830, 155, 25, 1,deepblue);//���水ť

    PrintCC(250,120,"�������ֻ��ţ�",HEI,24,1,deepblue);
    PrintCC(250,190,"��ѡ��סַ��",HEI,24,1,deepblue);
    PrintCC(745,120,"����",HEI,24,1,deepblue);
}
// ��ȡ��ǰʱ�䲢ת��Ϊ�ַ���
char* get_current_time() {
    time_t rawtime;
    struct tm * timeinfo;
    static char buffer[20];

    // ��ȡ��ǰʱ��
    time(&rawtime);
    // ��ʱ��ת��Ϊ����ʱ��
    timeinfo = localtime(&rawtime);

    // ��ʱ��ת��Ϊ�ַ���
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return buffer;
}

/****************************
����˵�����õ�Ԫ�������Ա��е�λ��
����˵�������Ա�Ԫ��
����ֵ��  ������ھͷ���λ�ã����򷵻�-1
****************************/

int Order_pos(OrderList OL,Order orders)
{
	int i=-1;
	for(i=0;i<OL.length;i++)
	{
		if(orders.id == OL.elem[i].id)
		{
			return i;
		}	
	}
	return -1;
}

/****************************
����˵���������Ա�Lĩβ����Ԫ�� 
����˵�������Ա��ַ��Ҫ�����Ԫ��
����ֵ��  ��  
****************************/
void OListInsert(OrderList*OL,Order orders) 
{
    Order*newbase=NULL;//�����»�ַ
    if(OL->length>=OL->listsize)//������Ա�����
    {
        if((newbase=(Order*)realloc(OL->elem,(OL->listsize+O_LISTINCEREMENT)*sizeof(Order)))==NULL)////���·����ڴ�
        {
        CloseSVGA();
        printf("No enough memory!\n");
        printf("OListInsert\n");
        exit(-1);
        }
        OL->elem=newbase;//���»�ַ
        OL->listsize+=O_LISTINCEREMENT;//�������Ա�����
    }
    *(OL->elem+(OL->length))=orders;//������Ԫ��
    OL->length++;//���Ա��ȼ�һ
}

/**********************
����˵���������˵���Ϣ���� 
����˵�����˵��ṹ�� 
����ֵ˵��:0������ɹ�   -1�� ����ʧ�� 
**********************/
int save_order(Order orders) {
    int i = 0;
    OrderList OL = {0};
	int order_pos;
	FILE *fp = NULL;

	ReadAllOrder(&OL);//��ȡ���ж�����Ϣ

    if ((fp = fopen("data\\order.dat", "wb")) == NULL) {
        printf("�޷����ļ���\n");
        return -1;
    }

    // �Ȳ��Ҷ����Ƿ��Ѿ�����
	order_pos = Order_pos(OL, orders);

	if (order_pos == -1)  // �������������
	{
		OListInsert(&OL, orders); // ���붩��
	}
	else  // ����������ڣ�����ԭ�ж�����Ϣ
	{
		orders.id = OL.elem[order_pos].id; // ����ԭ����ID
		OL.elem[order_pos] = orders;
	}


    // ���½����Ա�д���ļ�
    rewind(fp);//���ļ�ָ���ƶ����ļ���ͷ
    fwrite(&OL.length, sizeof(short), 1, fp);//д�����Ա���
    fwrite(&OL.listsize, sizeof(short), 1, fp);//д�����Ա�����
 
    // ���д������
    for (i = 0; i < OL.length; i++) {
        fwrite(&OL.elem[i], sizeof(Order), 1, fp);
    }

    fclose(fp);
    DestroyOList(&OL);
    return 0;
}

void DestroyOList(OrderList*OL)	
{
	free(OL->elem);
	OL->listsize=0;
	OL->length=0;
}

// ��ʼ�����Ա�
void ReadAllOrder(OrderList *OL) {
    int i = 0;
    short length = 0;//���Ա��ʼ����
    short listsize = 10; //���Ա��ʼ�������ܹ��洢10��������
    FILE *fp = NULL;

    if ((fp = fopen("data\\order.dat", "rb")) == NULL) {//������ļ�ʧ��
        fp = fopen("data\\order.dat", "wb");// ����ļ��������򴴽�һ���µ��ļ�
        if (fp == NULL) {//��������ļ�ʧ��
            printf("�޷������ļ���\n");
            return;//�޷������ļ��򷵻أ�����Ҫ����ִ������Ĵ���
        }
        fwrite(&length, sizeof(short), 1, fp); //��������ɹ���д���ʼ����0
        fwrite(&listsize, sizeof(short), 1, fp); //д���ʼ����10
        fclose(fp);//�ر��ļ�
        return;//������ɺ󷵻أ�����Ҫ����ִ������Ĵ���
    }
    //������ļ��ɹ����ȡ���Ⱥ�����
    fread(&length, sizeof(short), 1, fp); 
    fread(&listsize, sizeof(short), 1, fp); 
    //�Ѷ�ȡ�ĳ��Ⱥ�������ֵ�����Ա�
    OL->length = length;
    OL->listsize = listsize;
    OL->elem = (Order *)malloc(listsize * sizeof(Order)); //����洢�ռ�
    //������Ա�Ĵ洢�ռ����ʧ�������������Ϣ���˳�����
    if (OL->elem == NULL) {
        printf("No enough memory!\n");
        printf("ReadAllOrder\n");
        fclose(fp);
        exit(-1);
    }
    //�������ɹ��������ȡ��������
    //���Ѷ�ȡ�����ݴ洢�����Ա���
    for (i = 0; i < length; i++) {
        fread(&OL->elem[i], sizeof(Order), 1, fp);
    }

    fclose(fp);
}