#include "all_func.h"

Food foods[12]={
    {1, 1, "���˼�", 15, "food/���˼��׷�.jpg",0},
    {2, 1, "���˼�", 15, "food/���˼��׷�.jpg",0},
    {3, 1, "���˼��׷�", 15, "food/���˼��׷�.jpg",0},
    {4, 1, "���˼��׷�", 15, "food/���˼��׷�.jpg",0},
    {5, 1, "���˼��׷�", 15, "food/���˼��׷�.jpg",0},
    {6, 1, "���˼��׷�", 15, "food/���˼��׷�.jpg",0},
    {7, 1, "���˼��׷�", 15, "food/���˼��׷�.jpg",0},
    {8, 1, "���˼��׷�", 15, "food/���˼��׷�.jpg",0},
    {9, 1, "���˼��׷�", 15, "food/���˼��׷�.jpg",0},
    {10, 1, "���˼��׷�", 15, "food/���˼��׷�.jpg",0},
    {11, 1, "���˼��׷�", 15, "food/���˼��׷�.jpg",0},
    {12, 1, "���˼��׷�", 15, "food/���˼��׷�.jpg",0}
};
FoodCart food_carts[12]={0};//���ﳵ�ڵ���Ʒ
ShoppingFood shopping_food={0};//���ﳵ����

void user_food(int index){
    int foodCount=12;

    mouse_off_arrow(&mouse);
	
	draw_user_food(index);

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            return;
			//
		}
        else if(mouse_press(270, 235, 1070, 835)==1)//�����Ʒ
        {
            MouseGet(&mouse);
            AddSub_food(mouse.x, mouse.y, foodCount, foods, food_carts, &shopping_food.itemCount); 
            draw_food_quantity(foods); //ˢ��ҳ����ʾ���º������
            delay(100);
        }
    }
}


void draw_user_food(int index){
    int cnt=0;
    int i,j;
	bar1(200, 0, 1024, 768, white);
    bar1(0, 250, 199, 768, deepblue);

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5,1,deepblue);//�鿴������ť

    PrintCC(850,715,"�鿴����",HEI,24,1,deepblue);

    switch(index){
        case 1:
            PrintCC(220,700, "��Էѧ��ʳ��", HEI, 48, 1, deepblue);
            break;
        case 2:
            PrintCC(220,700, "��԰ʳ��", HEI, 48, 1, deepblue);
            break;
        case 3:
            PrintCC(220,700, "���̹�ʳ��", HEI, 48, 1, deepblue);
            break;
        case 4:
            PrintCC(220,700, "ѧ��һʳ��", HEI, 48, 1, deepblue);
            break;
        case 5:
            PrintCC(220,700, "ѧ����ʳ��", HEI, 48, 1, deepblue);
            break;
        case 6: 
            PrintCC(220,700, "�Ͼ�԰����", HEI, 48, 1, deepblue);
            break;
        case 7:
            PrintCC(220,700, "��һʳ��", HEI, 48, 1, deepblue);
            break;
        case 8:
            PrintCC(220,700, "����ʳ��", HEI, 48, 1, deepblue);
            break;
        case 9:
            PrintCC(220,700, "��԰����", HEI, 48, 1, deepblue);
            break;
        case 10:
            PrintCC(220,700, "�پ�԰", HEI, 48, 1, deepblue);
            break;
        case 11:
            PrintCC(220,700, "��һʳ��", HEI, 48, 1, deepblue);
            break;
        case 12:
            PrintCC(220,700, "����ʳ��", HEI, 48, 1, deepblue);
            break;
        case 13:
            PrintCC(220,700, "��԰ʳ��", HEI, 48, 1, deepblue);
            break;
        case 14:
            PrintCC(220,700, "���̹�ʳ��", HEI, 48, 1, deepblue);
            break;
        case 15:
            PrintCC(220,700, "��԰ʳ��", HEI, 48, 1, deepblue);
            break;
        case 16:    
            PrintCC(220,700, "��԰ʳ��", HEI, 48, 1, deepblue);
            break;
        case 17:
            PrintCC(220,700, "��԰�̹�ʳ��", HEI, 48, 1, deepblue);
            break;
        case 18:
            PrintCC(220,700, "��԰�̹�ʳ��", HEI, 48, 1, deepblue);
            break;
    }

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