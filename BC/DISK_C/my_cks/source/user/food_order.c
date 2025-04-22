#include "all_func.h"

FoodOrder Foodorders = {0}; // ����

void food_order(int index){

    UserList UL = {0};
    USER currentUser;

    int page = 0;// ��ʼҳ��
    int totalPage =(shopping_food.itemCount - 6 + 11 ) / 12 + 1 ; // ��ҳ��(����ȡ��)
    int state = 0; // �ж��Ƿ���Ҫ������Ϣ
    
    ReadAllUser(&UL); // ��ȡ�û��б�

    currentUser=UL.elem[users.pos];// ��ȡ��ǰ�û���Ϣ

    DestroyUList(&UL); // �ͷ��û��б�ռ�

    Foodorders.station = index; // ʳ�ñ��

    mouse_off_arrow(&mouse);

    draw_food_order(page);

    mouse_on_arrow(mouse);

    while(1){
        mouse_show_arrow(&mouse);

        if (mouse_press(40, 113, 160, 163) == 1) 
        {
            //
            return;
        }
        if(state==0)
        {
            if (mouse_press(220, 700, 340, 750) == 1) 
            {
                if (page > 0) {
                    page--;
                    draw_food_order(page);// �����û�����ҳ��
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
                    draw_food_order(page);// �����û�����ҳ��
                } else {
                    // ��ʾ���������һҳ
                    PrintCC(550, 25, "�������һҳ", HEI, 24, 1, lightred);
                    delay(500);
                    bar1(550, 25, 700, 60, white);
                }
            }
            else if(mouse_press(800, 700, 1000, 750) == 1)
            { 
                if (currentUser.community == '\0' || strlen(currentUser.number) == 0)// �ж��û���Ϣ�Ƿ�����
                {
                    draw_info();
                    state = 1;
                }
                else
                {
                    save_food(Foodorders); // ���涩��
                    PrintCC(800, 50, "�����ѱ���", HEI, 24, 1, lightred);
                    delay(500);
                    bar1(800, 50, 1024, 100, white);
                }
            }
        }
        // �����û���Ϣ
        if(state==1)
        {
            if(mouse_press(430, 105, 650, 155)==1)
            {
                number_input(currentUser.number, 435, 110, 645, 150); // �����ֻ���
            }
            else if(mouse_press(710, 105, 830, 155)==1)
            {
                if(strlen(currentUser.number)==11)
                {
                    save_user(currentUser);
                    PrintCC(800,50,"����ɹ�",HEI,24,1,lightred);
                    delay(500);
                    bar1(800,50,950,100,snow);
                }
                else
                {
                    PrintCC(800,50,"���Ȳ��Ϸ�",HEI,24,1,lightred);
                    delay(500);
                    bar1(800,50,950,100,snow);
                }
            }
            else if(mouse_press(440, 180, 560, 230)==1)
            {
                press1(4);//��ݿ
                currentUser.community=1;//��ݿ
                save_user(currentUser);
            }
            else if(mouse_press(620, 180, 740, 230)==1)
            {
                press1(5);//��Է
                currentUser.community=2;//��Է
                save_user(currentUser);
            }
            else if(mouse_press(800, 180, 920, 230)==1)
            {
                press1(6);//��Է
                currentUser.community=3;//��Է
                save_user(currentUser);
            } 

            if(mouse_press(200, 250, 1024, 768)==1)
            {
                state = 0;
                draw_food_order(page);
            }
        }
    }
}

void draw_food_order(int page){
    char address[100]; // �û���ַ
    int i;
    UserList UL = {0};
    FoodList FL = {0};
    USER currentUser;
    FoodOrder *currentFood;

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
    currentUser = UL.elem[users.pos]; // ��ȡ��ǰ�û���Ϣ

    ReadAllFood(&FL); // ��ȡ�����б�
    Foodorders.id = FL.length + 1; // ������

    sprintf(time_str, "�µ�ʱ�䣺%s", current_time);
    sprintf(user_name, "�û�����%s", currentUser.name);
    sprintf(user_phone, "�ֻ��ţ�%s", currentUser.number);

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
        char community[50]; // �����ַ���
        char building[50]; // ¥���ַ���
        sprintf(order_number_str, "�����ţ�%d", Foodorders.id); // ������
        PrintText(250, 50, order_number_str, HEI, 24, 1, black);
        PrintText(250, 100, time_str, HEI, 24, 1, black);
        PrintText(250, 150, user_name, HEI, 24, 1, black);
        PrintText(250, 200, user_phone, HEI, 24, 1, black);
        sprintf(address, "��ַ��%s", node[currentUser.index].name); // �û���ַ
        // switch(currentUser.community){// �����û���ַ��ʾ��ַ
        //     case 1: strcpy(community,"��ַ������ѧ����Ԣ"); break;
        //     case 2: strcpy(community,"��ַ������ѧ����Ԣ"); break;
        //     case 3: strcpy(community,"��ַ������ѧ����Ԣ"); break;
        //     case 4: strcpy(community,"��ַ����ݿѧ����Ԣ"); break;
        //     case 5: strcpy(community,"��ַ����Էѧ����Ԣ"); break;
        //     default: strcpy(community,"��ַ��δ֪"); break;
        // }

        // sprintf(building, "%d��", currentUser.building);
        // strcat(community,building);
        PrintText(250, 250, address, HEI, 24, 1, black);

        PrintCC(750,250, canteen[Foodorders.station-1].name, HEI, 24, 1, black);//��ʾʳ������

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
    if (endIdx > shopping_food.itemCount)// ��ֹԽ��
        endIdx = shopping_food.itemCount;

    item_y = (page == 0) ? 350 : 50;
    for (i = startIdx; i < endIdx; i++) {
        char total_str[50]; // ��Ʒ�ܼ�
        char quantity_str[20]; // ��Ʒ����
        int productIndex = food_carts[i].index_in_foods; // ��Ʒ����
        int quantity = foods[productIndex].quantity;

        sprintf(total_str, "%.2f", foods[productIndex].price * quantity);
        sprintf(quantity_str, "x%d", quantity);

        PrintCC(250, item_y, food_carts[i].name, HEI, 24, 1, black); // ��Ʒ��
        PrintText(750, item_y, (unsigned char*)quantity_str, HEI, 24, 1, black);// ��Ʒ����
        PrintText(900, item_y, (unsigned char*)total_str, HEI, 24, 1, black);// ��Ʒ���

        item_y += 50;
    }

    // �ж��Ƿ���Ҫ�ڴ�ҳ��ʾ�ܽ���ǰҳû������
    fullPageItemCount = (page == 0) ? 6 : 12;// ��һҳ��ʾ6����Ʒ������ҳ��ʾ12����Ʒ
    if ((endIdx - startIdx) < fullPageItemCount||endIdx==shopping_food.itemCount) {// ��ǰҳ��Ʒ��������һҳ�����һ����Ʒ�պ���ҳ��Ҫ��ӡ���ܽ��
        //����������һ����Ʒ������ҳ�Ͳ���ӡ�ܽ��
        // ��ӡ�ָ���
        PrintText(250, item_y - 30, "-------------------------------", HEI, 32, 1, black);

        // �����ܽ��
        total_amount = 0.0;
        for (i = 0; i < shopping_food.itemCount; i++) {
            int productIndex = food_carts[i].index_in_foods;
            int quantity = foods[productIndex].quantity;
            total_amount += foods[productIndex].price * quantity;
            food_carts[i].quantity = quantity; // ��¼���ﳵ��Ʒ����
            food_carts[i].price = foods[productIndex].price; // ��¼��Ʒ�۸�
        }

        sprintf(total_str, "�ܽ�%.2f Ԫ", total_amount);
        PrintText(750, item_y + 10, total_str, HEI, 24, 1, black);
    }

    //�洢������Ϣ
    strcpy(Foodorders.order_time, current_time); // �µ�ʱ��
    strcpy(Foodorders.user_name, currentUser.name); // �û���
    strcpy(Foodorders.user_phone, currentUser.number); // �û��ֻ���

    Foodorders.community=currentUser.community; // �û�����
    Foodorders.building=currentUser.building; 
    //Foodorders.station=; // �û�ȡ�͵ص�
    Foodorders.destination=currentUser.index; // �û��Ͳ͵ص�

    for (i = 0; i < shopping_food.itemCount; i++) {
        Foodorders.item[i] = food_carts[i]; // ���ﳵ����Ʒ��Ϣ
    }

    Foodorders.itemCount = shopping_food.itemCount; // ���ﳵ����Ʒ����
    Foodorders.total_amount = total_amount; // �ܽ��

    //ʳ�ñ����20�д����

    DestroyUList(&UL); // �ͷ��û��б�ռ�
    DestroyFList(&FL); // �ͷŶ����б�ռ�

}

/****************************
����˵�����õ�Ԫ�������Ա��е�λ��
����˵�������Ա�Ԫ��
����ֵ��  ������ھͷ���λ�ã����򷵻�-1
****************************/

int FoodOrder_pos(FoodList FL,FoodOrder Foodorders)
{
	int i=-1;
	for(i=0;i<FL.length;i++)
	{
		if(Foodorders.id == FL.elem[i].id)
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
void FListInsert(FoodList*FL,FoodOrder Foodorders) 
{
    FoodOrder*newbase=NULL;//�����»�ַ
    if(FL->length>=FL->listsize)//������Ա�����
    {
        if((newbase=(FoodOrder*)realloc(FL->elem,(FL->listsize+F_LISTINCEREMENT)*sizeof(FoodOrder)))==NULL)////���·����ڴ�
        {
        CloseSVGA();
        printf("No enough memory!\n");
        printf("FListInsert\n");
        exit(-1);
        }
        FL->elem=newbase;//���»�ַ
        FL->listsize+=F_LISTINCEREMENT;//�������Ա�����
    }
    *(FL->elem+(FL->length))=Foodorders;//������Ԫ��
    FL->length++;//���Ա��ȼ�һ
}

/**********************
����˵���������˵���Ϣ���� 
����˵�����˵��ṹ�� 
����ֵ˵��:0������ɹ�   -1�� ����ʧ�� 
**********************/
int save_food(FoodOrder Foodorders) {
    int i = 0;
    FoodList FL = {0};
	int order_pos;
	FILE *fp = NULL;

	ReadAllFood(&FL);//��ȡ���ж�����Ϣ

    if ((fp = fopen("data\\Foodorder.dat", "wb")) == NULL) {
        printf("�޷����ļ���\n");
        return -1;
    }

    // �Ȳ��Ҷ����Ƿ��Ѿ�����
	order_pos = FoodOrder_pos(FL, Foodorders);

	if (order_pos == -1)  // �������������
	{
		FListInsert(&FL, Foodorders); // ���붩��
	}
	else  // ����������ڣ�����ԭ�ж�����Ϣ
	{
		Foodorders.id = FL.elem[order_pos].id; // ����ԭ����ID
		FL.elem[order_pos] = Foodorders;
	}


    // ���½����Ա�д���ļ�
    rewind(fp);//���ļ�ָ���ƶ����ļ���ͷ
    fwrite(&FL.length, sizeof(short), 1, fp);//д�����Ա���
    fwrite(&FL.listsize, sizeof(short), 1, fp);//д�����Ա�����
 
    // ���д������
    for (i = 0; i < FL.length; i++) {
        fwrite(&FL.elem[i], sizeof(FoodOrder), 1, fp);
    }

    fclose(fp);
    DestroyFList(&FL);
    return 0;
}

void DestroyFList(FoodList*FL)	
{
	free(FL->elem);
    FL->elem=NULL;
	FL->listsize=0;
	FL->length=0;
}

// ��ʼ�����Ա�
void ReadAllFood(FoodList *FL) {
    int i = 0;
    short length = 0;//���Ա��ʼ����
    short listsize = 10; //���Ա��ʼ�������ܹ��洢10��������
    FILE *fp = NULL;

    if ((fp = fopen("data\\Foodorder.dat", "rb")) == NULL) {//������ļ�ʧ��
        fp = fopen("data\\Foodorder.dat", "wb");// ����ļ��������򴴽�һ���µ��ļ�
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
    FL->length = length;
    FL->listsize = listsize;
    FL->elem = (FoodOrder *)malloc(listsize * sizeof(FoodOrder)); //����洢�ռ�
    //������Ա�Ĵ洢�ռ����ʧ�������������Ϣ���˳�����
    if (FL->elem == NULL) {
        printf("No enough memory!\n");
        printf("ReadAllOrder\n");
        fclose(fp);
        exit(-1);
    }
    //�������ɹ��������ȡ��������
    //���Ѷ�ȡ�����ݴ洢�����Ա���
    for (i = 0; i < length; i++) {
        fread(&FL->elem[i], sizeof(FoodOrder), 1, fp);
    }

    fclose(fp);
}