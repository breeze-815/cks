#include "all_func.h"

Product products[84]=
{
/*1===========================================================================*/
    {1, 1, "��", 5.00, "bmp\\shop\\pen.bmp", 0},
    {2, 1, "ɨ��", 12.00, "bmp\\shop\\saoba.bmp", 0},
    {3, 1, "�;�", 10.00, "bmp\\shop\\canju.bmp", 0},
    {4, 1, "��", 3.00, "bmp\\shop\\wan.bmp", 0},
    {5, 1, "ˮ��", 15.00, "bmp\\shop\\shuibei.bmp", 0},
    {6, 1, "�¼�", 5.00, "bmp\\shop\\yijia.bmp", 0},
    {7, 1, "��ˢ", 10.00, "bmp\\shop\\yashua.bmp", 0},
    {8, 1, "�ϰ�", 18.00, "bmp\\shop\\tuoba.bmp", 0},
    {9, 1, "��ͷ", 20.00, "bmp\\shop\\zhentou.bmp", 0},
    {10, 1, "ë��", 12.00, "bmp\\shop\\maojin.bmp", 0},
    {11, 1, "�ҹ�", 1.00, "bmp\\shop\\guagou.bmp", 0},
    {12, 1, "��Ͱ����", 10.00, "bmp\\shop\\matong.bmp", 0},
/*2===========================================================================*/
    {13, 2, "�ڱ�", 2.00, "bmp\\shop\\blackbi.bmp", 0},
    {14, 2, "���", 3.00, "bmp\\shop\\redbi.bmp", 0},
    {15, 2, "Ǧ��", 4.00, "bmp\\shop\\qianbi.bmp", 0},
    {16, 2, "�ֱ�", 35.00, "bmp\\shop\\gangbi.bmp", 0},
    {17, 2, "����", 12.00, "bmp\\shop\\jiandao.bmp", 0},
    {18, 2, "��Ƥ", 2.00, "bmp\\shop\\xiangpi.bmp", 0},
    {19, 2, "����", 8.00, "bmp\\shop\\chizi.bmp", 0},
    {20, 2, "����", 2.00, "bmp\\shop\\jiaodai.bmp", 0},
    {21, 2, "���彺", 4.00, "bmp\\shop\\jiao.bmp", 0},
    {22, 2, "������", 6.00, "bmp\\shop\\xiuzheng.bmp", 0}, 
    {23, 2, "�ʼǱ�", 3.00, "bmp\\shop\\benzi.bmp", 0},
    {24, 2, "�����", 15.00, "bmp\\shop\\dingshu.bmp", 0},
/*3===========================================================================*/
    {25, 3, "��Ƭ", 7.00, "bmp\\shop\\shupian.bmp", 0},
    {26, 3, "����԰����", 1.00, "bmp\\shop\\daliyuan.bmp", 0},
    {27, 3, "�����±���", 8.00, "bmp\\shop\\aoliao.bmp", 0},
    {28, 3, "�ɿ���", 10.00, "bmp\\shop\\chocolate.bmp", 0},
    {29, 3, "����", 1.00, "bmp\\shop\\cookie.bmp", 0},
    {30, 3, "����", 1.00, "bmp\\shop\\cookie.bmp", 0},
    {31, 3, "����", 1.00, "bmp\\shop\\cookie.bmp", 0},
    {32, 3, "����", 1.00, "bmp\\shop\\cookie.bmp", 0},
    {33, 3, "����", 1.00, "bmp\\shop\\cookie.bmp", 0},
    {34, 3, "����", 1.00, "bmp\\shop\\cookie.bmp", 0},
    {35, 3, "����", 1.00, "bmp\\shop\\cookie.bmp", 0},
    {36, 3, "����", 1.00, "bmp\\shop\\cookie.bmp", 0},
/*4===========================================================================*/
    {37, 4, "����", 5.00, "bmp\\shop\\kele.bmp", 0},
    {38, 4, "ѩ��", 5.00, "bmp\\shop\\xixi.bmp", 0},
    {39, 4, "�Ҵ�", 5.00, "bmp\\shop\\fenda.bmp", 0},
    {40, 4, "�����", 5.00, "bmp\\shop\\bingtao.bmp", 0},
    {41, 4, "����ʽ", 5.00, "bmp\\shop\\bingmeng.bmp", 0},
    {42, 4, "������", 5.00, "bmp\\shop\\bingcoffee.bmp", 0},
    {43, 4, "����", 5.00, "bmp\\shop\\bingtea.bmp", 0},
    {44, 4, "������", 5.00, "bmp\\shop\\bingcoffee.bmp", 0},
    {45, 4, "������", 5.00, "bmp\\shop\\bingcoffee.bmp", 0},
    {46, 4, "������", 5.00, "bmp\\shop\\bingcoffee.bmp", 0},
    {47, 4, "������", 5.00, "bmp\\shop\\bingcoffee.bmp", 0},
    {48, 4, "������", 5.00, "bmp\\shop\\bingcoffee.bmp", 0},
/*5===========================================================================*/
    {49, 5, "����", 10.00, "bmp\\shop\\lanqiu.bmp", 0},
    {50, 5, "����", 10.00, "bmp\\shop\\zuqiu.bmp", 0},
    {51, 5, "��ë��", 10.00, "bmp\\shop\\yidongqiu.bmp", 0},
    {52, 5, "ƹ����", 10.00, "bmp\\shop\\pingpangqiu.bmp", 0},
    {53, 5, "����", 10.00, "bmp\\shop\\wenti.bmp", 0},
    {54, 5, "����", 10.00, "bmp\\shop\\quanqiu.bmp", 0},
    {55, 5, "������", 10.00, "bmp\\shop\\wenti.bmp", 0},
    {56, 5, "������", 10.00, "bmp\\shop\\wenti.bmp", 0},    
    {57, 5, "������", 10.00, "bmp\\shop\\wenti.bmp", 0},
    {58, 5, "������", 10.00, "bmp\\shop\\wenti.bmp", 0},
    {59, 5, "������", 10.00, "bmp\\shop\\wenti.bmp", 0},
    {60, 5, "������", 10.00, "bmp\\shop\\wenti.bmp", 0},
/*6===========================================================================*/
    {61, 6, "ƻ��", 10.00, "bmp\\shop\\apple.bmp", 0},
    {62, 6, "�㽶", 10.00, "bmp\\shop\\banana.bmp", 0},
    {63, 6, "��", 10.00, "bmp\\shop\\pear.bmp", 0},
    {64, 6, "����", 10.00, "bmp\\shop\\orange.bmp", 0},
    {65, 6, "��ݮ", 10.00, "bmp\\shop\\strawberry.bmp", 0},
    {66, 6, "����", 10.00, "bmp\\shop\\grape.bmp", 0},
    {67, 6, "����", 10.00, "bmp\\shop\\pineapple.bmp", 0},
    {68, 6, "����", 10.00, "bmp\\shop\\pineapple.bmp", 0},
    {69, 6, "����", 10.00, "bmp\\shop\\pineapple.bmp", 0},
    {70, 6, "����", 10.00, "bmp\\shop\\pineapple.bmp", 0},
    {71, 6, "����", 10.00, "bmp\\shop\\pineapple.bmp", 0},
    {72, 6, "����", 10.00, "bmp\\shop\\pineapple.bmp", 0},
/*7===========================================================================*/
    {73, 7, "��", 10.00, "bmp\\shop\\book.bmp", 0},
    {74, 7, "��", 10.00, "bmp\\shop\\book.bmp", 0},
    {75, 7, "��", 10.00, "bmp\\shop\\book.bmp", 0},
    {76, 7, "��", 10.00, "bmp\\shop\\book.bmp", 0},
    {77, 7, "��", 10.00, "bmp\\shop\\book.bmp", 0},
    {78, 7, "��", 10.00, "bmp\\shop\\book.bmp", 0},
    {79, 7, "��", 10.00, "bmp\\shop\\book.bmp", 0},
    {80, 7, "��", 10.00, "bmp\\shop\\book.bmp", 0},
    {81, 7, "��", 10.00, "bmp\\shop\\book.bmp", 0},
    {82, 7, "��", 10.00, "bmp\\shop\\book.bmp", 0},
    {83, 7, "��", 10.00, "bmp\\shop\\book.bmp", 0},
    {84, 7, "��", 10.00, "bmp\\shop\\book.bmp", 0},
/*===========================================================================*/
};
CartItem carts[84]={0};
ShoppingCart cart={0};

void user_shop(){
    int productCount = 84;//��������Ʒ������ʼ��
    int currentpage = 1;//��ǰҳ���ʼ��

    mouse_off_arrow(&mouse);//�������
	
	draw_user_shop(products, productCount,currentpage);//�����û�����ҳ��

	mouse_on_arrow(mouse);//��ʾ���

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            return;
			//welcome();//��ҳ
		}
        else if(mouse_press(40, 276, 160, 326)==1)
        {
            press1(1);//���볬��ҳ��
            user_shop();//�û�����ҳ�� 
            return;
        }
        else if(mouse_press(40, 439, 160, 489)==1)
        {
            press1(2);//��������ҳ��
            user_takeout();//�û�����ҳ�� 
            return;
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            press1(3);//������ҳ��
            user_deliver();//�û����ҳ�� 
            return;
        }
        else if(mouse_press(800, 700, 1000, 750)==1)
        {
            user_cart();//�û����ﳵҳ��
            break;
        }
        else if(mouse_press(200, 0, 320, 50)==1)
        {
            currentpage = 1;//������Ʒ
            draw_user_shop(products, productCount,currentpage);//�����û�����ҳ��

        }
        else if(mouse_press(320, 0, 440, 50)==1)
        {
            currentpage = 2;//�ľ�
            draw_user_shop(products, productCount,currentpage);//�����û�����ҳ��
        }
        else if(mouse_press(440, 0, 560, 50)==1)
        {
            currentpage = 3;//��ʳ
            draw_user_shop(products, productCount,currentpage);//�����û�����ҳ��
        }
        else if(mouse_press(560, 0, 680, 50)==1)
        {
            currentpage = 4;//����
            draw_user_shop(products, productCount,currentpage);//�����û�����ҳ��
        }
        else if(mouse_press(680, 0, 800, 50)==1)
        {
            currentpage = 5;//�˶���Ʒ
            draw_user_shop(products, productCount,currentpage);//�����û�����ҳ��
        }
        else if(mouse_press(800, 0, 920, 50)==1)
        {
            currentpage = 6;//ˮ��
            draw_user_shop(products, productCount,currentpage);//�����û�����ҳ��
        }
        else if(mouse_press(920, 0, 1024, 50)==1)
        {
            currentpage = 7;//�Ĵ�
            draw_user_shop(products, productCount,currentpage);//�����û�����ҳ��
        }
        else if(mouse_press(270, 235, 1070, 835)==1)//�����Ʒ
        {
            MouseGet(&mouse);
            AddSub(mouse.x, mouse.y, productCount, products, carts, &cart.itemCount, currentpage - 1); //ע��currentpage��1��ʼ������indexʱ���1
            draw_user_shop_quantity(products, productCount, currentpage); //ˢ��ҳ����ʾ���º������
            delay(100);
        }
    }
}

//�����û�����ҳ��
void draw_user_shop(Product products[],int productCount,int currentpage){
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

    PrintCC(860,715,"���ﳵ",HEI,24,1,deepblue);
    PrintCC(220,700,"��԰����",HEI,48,1,deepblue);

    //��ʾ��ͬ��Ʒ����
    switch (currentpage)
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

    cnt=(currentpage-1)*12;//������ʾ��һҳ����Ʒ

    //��ʾ��Ʒ��Ϣ
    for(j=0;j<3;j++){
    	for(i=0;i<4;i++){//�Ⱥ���������
            char quantity_str[20];
            char price_str[20];
            // ʹ�� sprintf �� quantity ת��Ϊ�ַ���
            sprintf(quantity_str, "%d", products[cnt].quantity);
            sprintf(price_str, "%.2f", products[cnt].price);

    		Line_Thick(270+200*i, 235+200*j, 290+200*i, 235+200*j, 1, deepblue);//����

            Line_Thick(390+200*i, 235+200*j, 370+200*i, 235+200*j, 1, deepblue);//�Ӻ�
            Line_Thick(380+200*i, 225+200*j, 380+200*i, 245+200*j, 1, deepblue);

            
            PrintCC(270+200*i,75+200*j,products[cnt].name,HEI,24,1,black);//��ʾ��Ʒ����
            
            PrintText(270+22+200*i, 220+3+200*j,price_str, HEI, 24, 0, black);//��ʾ��Ʒ�۸�
            PrintText(395+200*i,75+200*j, (unsigned char*)quantity_str,HEI,24,0,black);//��ʾ��Ʒ����

        
            Readbmp64k(270+200*i, 100+200*j, products[cnt].photo);//��ʾ��ƷͼƬ
            cnt++;
            
    	}
    }
 
}

//������ʾ��Ʒ����
void draw_user_shop_quantity(Product products[],int productCount,int currentpage){
    int i=0;
    int j=0;
    int cnt=0;
    cnt=(currentpage-1)*12;//������ʾ��һҳ����Ʒ

    //��ʾ��Ʒ��Ϣ
    for(j=0;j<3;j++){
    	for(i=0;i<4;i++){//�Ⱥ���������
            char quantity_str[20];
            // ʹ�� sprintf �� quantity ת��Ϊ�ַ���
            sprintf(quantity_str, "%d", products[cnt].quantity);
            // ���� PrintText �������� quantity_str ת��Ϊ unsigned char* ����
            bar1(395+200*i, 75+200*j, 460+200*i, 95+200*j,white);
            PrintText(395+200*i,75+200*j, (unsigned char*)quantity_str,HEI,24,0,black);//��ʾ��Ʒ����
            cnt++;
            
    	}
    }
}

//�Ӽ���Ʒ
void AddSub(int mx, int my, int productCount, Product products[], CartItem carts[], int* itemCount, int currentPage) {
    int i, j, index;
    int baseX = 270, baseY = 235;
    int width = 200, height = 200;

    for (j = 0; j < 3; j++) {
        for (i = 0; i < 4; i++) {
            index = currentPage * 12 + i + j * 4;
            if (index >= productCount) return;

            // �Ӻ�����
            if (mx >= 370 + i * width && mx <= 390 + i * width &&
                my >= 225 + j * height && my <= 245 + j * height) {
                addToCart(products[index], carts, itemCount,index);
                products[index].quantity++;
                return;
            }
            // ��������
            if (mx >= 270 + i * width && mx <= 290 + i * width &&
                my >= 225 + j * height && my <= 245 + j * height) {
                if (products[index].quantity > 0) {
                    products[index].quantity--;  // ��Ʒҳ������ -1
                    removeFromCart(products[index], carts, itemCount);
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

void addToCart(Product p, CartItem carts[], int *itemCount,int index) {
    int i=0;
    for (i = 0; i < *itemCount; i++) {
        if (carts[i].id == p.id) {
            carts[i].quantity++;
            return;
        }
    }
    carts[*itemCount].id = p.id;
    strcpy(carts[*itemCount].name, p.name);
    strcpy(carts[*itemCount].photo, p.photo);
    carts[*itemCount].price=p.price;
    carts[*itemCount].quantity = 1;
    carts[*itemCount].index_in_products=index;//����Ʒ�����е�����
    (*itemCount)++;
}

void removeFromCart(Product p, CartItem carts[], int *itemCount) {
    int i, j;
    for (i = 0; i < *itemCount; i++) {
        if (carts[i].id == p.id) {
            if (carts[i].quantity > 1) {
                carts[i].quantity--;
            } else if (carts[i].quantity == 1) {
                // ������� 0��ɾ�������Ʒ
                for (j = i; j < *itemCount - 1; j++) {
                    carts[j] = carts[j + 1];
                }
                (*itemCount)--;
            }
            return;
        }
    }
}

