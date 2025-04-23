#include "all_func.h"

Food foods[12]={
    {1, 1, "���˼��׷�", 20, "bmp\\canteen\\huang.bmp",0},
    {2, 1, "±�ⷹ", 15, "bmp\\canteen\\lurou.bmp",0},
    {3, 1, "������", 10, "bmp\\canteen\\dan.bmp",0},
    {4, 1, "���ӷ�", 10, "bmp\\canteen\\hefen.bmp",0},
    {5, 1, "ţ������", 12, "bmp\\canteen\\niurou.bmp",0},
    {6, 1, "���Ѽ�����", 8, "bmp\\canteen\\fanqie.bmp",0},
    {7, 1, "������", 12, "bmp\\canteen\\hong.bmp",0},
    {8, 1, "�������", 4, "bmp\\canteen\\cai.bmp",0},
    {9, 1, "С����", 3, "bmp\\canteen\\xiaomi.bmp",0},
    {10, 1, "�˱���", 3, "bmp\\canteen\\babao.bmp",0},
    {11, 1, "�Ź���ź��", 8, "bmp\\canteen\\ou.bmp",0},
    {12, 1, "�ϲ˵�����", 2, "bmp\\canteen\\zicai.bmp",0}
};
FoodCart food_carts[12]={0};//���ﳵ�ڵ���Ʒ
ShoppingFood shopping_food={0};//���ﳵ����

void user_food(int index){
    int foodCount=12;
    int state=0;//0Ϊδѡ������1Ϊѡ������

    mouse_off_arrow(&mouse);
	
	draw_user_food(index);

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            int i;
            for(i=0;i<foodCount;i++)
            {
                foods[i].quantity=0;//�����Ʒ����
            }
            shopping_food.itemCount=0;//��չ��ﳵ
            shopping_food.items=NULL;//��չ��ﳵ

            return;
		}
        else if(mouse_press(800, 700, 1000, 750)==1)//�鿴����
        {
            food_order(index);//�鿴����

            //return����⿪ʼ
            mouse_off_arrow(&mouse);
            bar1(200, 0, 1024, 768, white); // ���ע��������
            draw_user_food(index);
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(270, 235, 1070, 835)==1)//�����Ʒ
        {
            MouseGet(&mouse);
            AddSub_food(mouse.x, mouse.y, foodCount, foods, food_carts, &shopping_food.itemCount); 
            draw_food_quantity(foods); //ˢ��ҳ����ʾ���º������
            delay(100);
        }
        else if(mouse_press(220,75, 250, 90)==1)
        {
            mouse_off_arrow(&mouse);//�������
            draw_sort();//��������ҳ��
            mouse_on_arrow(mouse);//��ʾ���
            state=1;//�ѵ������
        }

        if (state == 1) {
            if (mouse_press(205, 95, 445, 144) == 1) // ����Ӹߵ���
            {
                int i, j;
        
                for (i = 0; i < 12 - 1; i++) {
                    for (j = 0; j < 12 - 1 - i ; j++) {
                        if (foods[j].price < foods[j + 1].price) {
                            Food temp = foods[j];
                            foods[j] = foods[j + 1];
                            foods[j + 1] = temp;
                        }
                    }
                }

                mouse_off_arrow(&mouse);//�������
                draw_user_food(index);
                mouse_on_arrow(mouse);//��ʾ���
                state=0;
            }
            else if(mouse_press(205, 146, 445, 295)==1)//����ӵ͵���
            {
            	int i, j;
        
                for (i = 0; i < 12 - 1; i++) {
                    for (j = 0; j < 12 - 1 - i ; j++) {
                        if (foods[j].price > foods[j + 1].price) {
                            Food temp = foods[j];
                            foods[j] = foods[j + 1];
                            foods[j + 1] = temp;
                        }
                    }
                }

                mouse_off_arrow(&mouse);//�������
                draw_user_food(index);
                mouse_on_arrow(mouse);//��ʾ���
                state=0;
            }

        }
    }
}


void draw_user_food(int index){
    int cnt=0;
    int i,j;
	bar1(200, 0, 1024, 768, white);
    bar1(0, 250, 199, 768, deepblue);

    Line_Thick(220,75,235,90,1,black);//
    Line_Thick(235,90,250,75,1,black);//

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5,1,deepblue);//�鿴������ť

    PrintCC(850,715,"�鿴����",HEI,24,1,deepblue);

    PrintCC(220,700, canteen[index-1].name, HEI, 48, 1, deepblue);//��ʾʳ������

    //��ʾ��Ʒ��Ϣ
    for(j=0;j<3;j++){
        for(i=0;i<4;i++){//�Ⱥ���������


            char quantity_str[20];
            char price_str[20];
            // ʹ�� sprintf �� quantity ת��Ϊ�ַ���
            sprintf(quantity_str, "%d", foods[cnt].quantity);
            sprintf(price_str, "%.2f", foods[cnt].price);

            Line_Thick(270+200*i, 235+200*j, 290+200*i, 235+200*j, 1, deepblue);//����

            Line_Thick(390+200*i, 235+200*j, 370+200*i, 235+200*j, 1, deepblue);//�Ӻ�
            Line_Thick(380+200*i, 225+200*j, 380+200*i, 245+200*j, 1, deepblue);

            
            PrintCC(270+200*i,75+200*j,foods[cnt].name,HEI,24,1,black);//��ʾ��Ʒ����
            
            PrintText(270+22+200*i, 220+3+200*j,price_str, HEI, 24, 0, black);//��ʾ��Ʒ�۸�
            PrintText(395+200*i,75+200*j, (unsigned char*)quantity_str,HEI,24,0,black);//��ʾ��Ʒ����

        
            Readbmp64k(270+200*i, 100+200*j, foods[cnt].photo);//��ʾ��ƷͼƬ
            cnt++;
            
        }
    }


}


//������ʾ��Ʒ����
void draw_food_quantity(Food foods[]){
    int i=0;
    int j=0;
    int cnt=0;
    //��ʾ��Ʒ��Ϣ
    for(j=0;j<3;j++){
    	for(i=0;i<4;i++){//�Ⱥ���������
            char quantity_str[20];
            // ʹ�� sprintf �� quantity ת��Ϊ�ַ���
            sprintf(quantity_str, "%d", foods[cnt].quantity);
            // ���� PrintText �������� quantity_str ת��Ϊ unsigned char* ����
            bar1(395+200*i, 75+200*j, 460+200*i, 95+200*j,white);
            PrintText(395+200*i,75+200*j, (unsigned char*)quantity_str,HEI,24,0,black);//��ʾ��Ʒ����
            cnt++;
    	}
    }
}

//�Ӽ���Ʒ
void AddSub_food(int mx, int my, int foodCount, Food foods[], FoodCart food_carts[], int* itemCount) {
    int i, j, index;
    int baseX = 270, baseY = 235;
    int width = 200, height = 200;

    for (j = 0; j < 3; j++) {
        for (i = 0; i < 4; i++) {
            index = i + j * 4;
            if (index >= foodCount) return;// ������Ʒ�������˳�

            // �Ӻ�����
            if (mx >= 370 + i * width && mx <= 390 + i * width &&
                my >= 225 + j * height && my <= 245 + j * height) {
                addToCart_food(foods[index], food_carts, itemCount,index);
                foods[index].quantity++;
                return;
            }
            // ��������
            if (mx >= 270 + i * width && mx <= 290 + i * width &&
                my >= 225 + j * height && my <= 245 + j * height) {
                if (foods[index].quantity > 0) {
                    foods[index].quantity--;  // ��Ʒҳ������ -1
                    removeFromCart_food(foods[index], food_carts, itemCount);
                }else {
                    PrintCC(220,660,"����Ʒ�Ѵӹ��ﳵ���Ƴ�",HEI,24,1,lightred);
                    delay(500);
                    bar1(220,660,800,700,white);
                }
                return;
            }   
        }
    }
}

void addToCart_food(Food f, FoodCart food_carts[], int *itemCount,int index) {
    int i=0;
    for (i = 0; i < *itemCount; i++) {
        if (food_carts[i].id == f.id) {
            food_carts[i].quantity++;
            return;
        }
    }
    food_carts[*itemCount].id = f.id;
    strcpy(food_carts[*itemCount].name, f.name);
    strcpy(food_carts[*itemCount].photo, f.photo);
    food_carts[*itemCount].price=f.price;
    food_carts[*itemCount].quantity = 1;
    food_carts[*itemCount].index_in_foods=index;//����Ʒ�����е�����
    (*itemCount)++;
}

void removeFromCart_food(Food f, FoodCart food_carts[], int *itemCount) {
    int i, j;
    for (i = 0; i < *itemCount; i++) {
        if (food_carts[i].id == f.id) {
            if (food_carts[i].quantity > 1) {
                food_carts[i].quantity--;
            } else if (food_carts[i].quantity == 1) {
                // ������� 0��ɾ�������Ʒ
                for (j = i; j < *itemCount - 1; j++) {
                    food_carts[j] = food_carts[j + 1];
                }
                (*itemCount)--;
            }
            return;
        }
    }
}
