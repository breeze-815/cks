#include "all_func.h"

Product products[20];
CART carts[20];

void user_shop(){
    int productCount = 0;//��������Ʒ������ʼ��
    int cartCount = 0;//���ﳵ����Ʒ������ʼ��

    init_Products(&productCount);//��ʼ����Ʒ������Ϣ

    mouse_off_arrow(&mouse);
	
	draw_user_shop(products, productCount);//�����û�����ҳ��

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            //user();//�û�ҳ��
		}
        else if(mouse_press(40, 276, 160, 326)==1)
        {
            draw_choice();
            while(1){

                mouse_show_arrow(&mouse);
                if(mouse_press(200, 202, 430, 264)==1){
                    shops.type=1;
                    break;
                }else if(mouse_press(200, 266, 430, 334)==1){
                    shops.type=2;
                    break;
                }else if(mouse_press(200, 336, 430, 400)==1){
                    shops.type=3;
                    break;
                }
            }
            user_shop();//�û�����ҳ��   
        }
        else if(mouse_press(40, 439, 160, 489)==1)
        {
            press1(2);//��������ҳ��
            user_takeout();//�û�����ҳ��    
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            press1(3);//������ҳ��
            user_deliver();//�û����ҳ��  
        }
        else if(mouse_press(800, 700, 1000, 750)==1)
        {
            user_cart();//�û����ﳵҳ��
        }
        else if(mouse_press(200, 0, 320, 50)==1)
        {
            press_item(1);//������Ʒ
        }
        else if(mouse_press(320, 0, 440, 50)==1)
        {
            press_item(2);//�ľ�
        }
        else if(mouse_press(440, 0, 560, 50)==1)
        {
            press_item(3);//��ʳ
        }
        else if(mouse_press(560, 0, 680, 50)==1)
        {
            press_item(4);//����
        }
        else if(mouse_press(680, 0, 800, 50)==1)
        {
            press_item(5);//�˶���Ʒ
        }
        else if(mouse_press(800, 0, 920, 50)==1)
        {
            press_item(6);//ˮ��
        }
        else if(mouse_press(920, 0, 1024, 50)==1)
        {
            press_item(7);//�Ĵ�
        }
        else {
            int mx, my;
            if (mouse_press(mx, my, mx, my) == 1) {
                AddSub(mx, my, productCount, products, carts, cartCount);
            }
        }
    }
}

void draw_user_shop(Product products[],int productCount){
    int i=0;
    int j=0;
    int cnt=0;

    bar1(200, 0, 1024, 768,white);

    Line_Thick(200,50,1024,50,2,deepblue);

    Line_Thick(320,0,320,50,2,deepblue);
    Line_Thick(440,0,440,50,2,deepblue);
    Line_Thick(560,0,560,50,2,deepblue);
    Line_Thick(680,0,680,50,2,deepblue);
    Line_Thick(800,0,800,50,2,deepblue);
    Line_Thick(920,0,920,50,2,deepblue);

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5,1,deepblue);//���ﳵ��ť

    PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
    PrintCC(355,15,"�ľ�",HEI,24,1,grey);
    PrintCC(475,15,"��ʳ",HEI,24,1,grey);
    PrintCC(595,15,"����",HEI,24,1,grey);
    PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
    PrintCC(835,15,"ˮ��",HEI,24,1,grey);
    PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
    PrintCC(860,715,"���ﳵ",HEI,24,1,deepblue);

    for(i=0;i<4;i++){
    	for(j=0;j<3;j++){
    		Line_Thick(270+200*i, 235+200*j, 290+200*i, 235+200*j, 1, deepblue);//����

            Line_Thick(390+200*i, 235+200*j, 370+200*i, 235+200*j, 1, deepblue);//�Ӻ�
            Line_Thick(380+200*i, 225+200*j, 380+200*i, 245+200*j, 1, deepblue);

            PrintCC(270+200*i,75+200*j,products[cnt].name,HEI,24,1,black);//��ʾ��Ʒ����
            PrintText(270+22+200*i, 220+3+200*j, products[cnt].price, HEI, 24, 0, black);//��ʾ��Ʒ�۸�

            Readbmp64k(270+200*i, 100+200*j, products[cnt].photo);//��ʾ��ƷͼƬ
            cnt++;
    	}
    }


    if(shops.type==1){
        PrintCC(220,700,"��ݿ��԰����",HEI,48,1,deepblue);
    }else if(shops.type==2){ 
        PrintCC(220,700,"��Է��԰����",HEI,48,1,deepblue);
    }else if(shops.type==3){
        PrintCC(220,700,"��Է��԰����",HEI,48,1,deepblue);
    }
}

void press_item(int x){
    switch (x)
    {
        case 1:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,deepblue);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 2:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,deepblue);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 3:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,deepblue);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 4:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,deepblue);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }   
        case 5:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,deepblue);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 6:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,deepblue);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 7:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,deepblue);
            break;
        }
    }
}

void init_Products(int *productCount){ 
    strcpy(products[0].name, "��");
    strcpy(products[0].price, "10.00");
    products[0].id = 1;
    strcpy(products[0].photo, "bmp\\pen.bmp");
    

    strcpy(products[1].name, "ɨ��");
    strcpy(products[1].price, "15.00");
    products[1].id = 2;
    strcpy(products[1].photo, "bmp\\saoba.bmp");
    
    strcpy(products[2].name, "�;�");
    strcpy(products[2].price, "12.00");
    products[2].id = 3;
    strcpy(products[2].photo, "bmp\\canju.bmp");

    strcpy(products[3].name, "��");
    strcpy(products[3].price, "5.00");
    products[3].id = 4;
    strcpy(products[3].photo, "bmp\\wan.bmp");

    strcpy(products[4].name, "ˮ��");
    strcpy(products[4].price, "25.00");
    products[4].id = 5;
    strcpy(products[4].photo, "bmp\\shuibei.bmp");

    strcpy(products[5].name, "�¼�");
    strcpy(products[5].price, "10.00");
    products[5].id = 6;
    strcpy(products[5].photo, "bmp\\yijia.bmp");

    *productCount = 6;
}

// ����Ӽ���ť����¼�
void AddSub(int x, int y, int productCount, Product *products, CART *cart, int cartCount) {
    int i=0;
    for (i = 0; i < productCount; i++) {
        int px = 270 + i * 180;
        int py = 220;
        // ���Ű�ť���
        if (x >= px && x <= px + 30 && y >= py + 30 && y <= py + 60) {
            int j = 0;
            for (j = 0; j < cartCount; j++) {
                if (cart[j].productId == products[i].id) {
                    if (cart[j].quantity > 0) {
                        cart[j].quantity--;
                    }
                    break;
                }
            }
        }
        // �ӺŰ�ť���
        if (x >= px + 150 && x <= px + 180 && y >= py + 30 && y <= py + 60) {
            int found = 0;
            int j = 0;
            for (j = 0; j < cartCount; j++) {
                if (cart[j].productId == products[i].id) {
                    cart[j].quantity++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                cart[cartCount].productId = products[i].id;
                cart[cartCount].quantity = 1;
                cartCount++;
            }
        }
    }
}