#include "all_func.h"

Product products[50]={0};
CartItem carts[50]={0};
ShoppingCart cart={0};

void user_shop(){
    int productCount = 0;//超市里商品数量初始化
    int currentpage = 1;//当前页面初始化

    init_Products(&productCount);//初始化商品所有信息

    mouse_off_arrow(&mouse);//隐藏鼠标
	
	draw_user_shop(products, productCount,currentpage);//绘制用户超市页面

	mouse_on_arrow(mouse);//显示鼠标

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            user(users.pos);//用户页面
		}
        else if(mouse_press(40, 276, 160, 326)==1)
        {
            press1(1);//进入超市页面
            user_shop();//用户超市页面   
        }
        else if(mouse_press(40, 439, 160, 489)==1)
        {
            press1(2);//进入外卖页面
            user_takeout();//用户外卖页面    
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            press1(3);//进入快递页面
            user_deliver();//用户快递页面  
        }
        else if(mouse_press(800, 700, 1000, 750)==1)
        {
            user_cart();//用户购物车页面
        }
        else if(mouse_press(200, 0, 320, 50)==1)
        {
            currentpage = 1;//生活用品
            draw_user_shop(products, productCount,currentpage);//绘制用户超市页面

        }
        else if(mouse_press(320, 0, 440, 50)==1)
        {
            currentpage = 2;//文具
            draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
        }
        else if(mouse_press(440, 0, 560, 50)==1)
        {
            currentpage = 3;//零食
            draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
        }
        else if(mouse_press(560, 0, 680, 50)==1)
        {
            currentpage = 4;//饮料
            draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
        }
        else if(mouse_press(680, 0, 800, 50)==1)
        {
            currentpage = 5;//运动用品
            draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
        }
        else if(mouse_press(800, 0, 920, 50)==1)
        {
            currentpage = 6;//水果
            draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
        }
        else if(mouse_press(920, 0, 1024, 50)==1)
        {
            currentpage = 7;//文创
            draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
        }
        else if(mouse_press(270, 235, 1070, 835)==1)//点击商品
        {
            MouseGet(&mouse);
            AddSub(mouse.x, mouse.y, productCount, products, carts, &cart.itemCount, currentpage - 1); //注意currentpage从1开始，计算index时需减1
            draw_user_shop_quantity(products, productCount, currentpage); //刷新页面显示更新后的数量
            delay(100);
        }
    }
}

//绘制用户超市页面
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

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5,1,deepblue);//购物车按钮

    PrintCC(860,715,"购物车",HEI,24,1,deepblue);
    PrintCC(220,700,"喻园超市",HEI,48,1,deepblue);

    //显示不同商品类型
    switch (currentpage)
    {
        case 1:{
            PrintCC(210,15,"生活用品",HEI,24,1,deepblue);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 2:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,deepblue);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 3:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,deepblue);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 4:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,deepblue);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }   
        case 5:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,deepblue);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 6:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,deepblue);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 7:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,deepblue);
            break;
        }
    }

    cnt=(currentpage-1)*12;//决定显示哪一页的商品

    //显示商品信息
    for(j=0;j<3;j++){
    	for(i=0;i<4;i++){//先横向，再竖向
            char quantity_str[20];
            char price_str[20];
            // 使用 sprintf 将 quantity 转换为字符串
            sprintf(quantity_str, "%d", products[cnt].quantity);
            sprintf(price_str, "%.2f", products[cnt].price);

    		Line_Thick(270+200*i, 235+200*j, 290+200*i, 235+200*j, 1, deepblue);//减号

            Line_Thick(390+200*i, 235+200*j, 370+200*i, 235+200*j, 1, deepblue);//加号
            Line_Thick(380+200*i, 225+200*j, 380+200*i, 245+200*j, 1, deepblue);

            
            PrintCC(270+200*i,75+200*j,products[cnt].name,HEI,24,1,black);//显示商品名称
            
            PrintText(270+22+200*i, 220+3+200*j,price_str, HEI, 24, 0, black);//显示商品价格
            PrintText(390+200*i,75+200*j, (unsigned char*)quantity_str,HEI,24,0,black);//显示商品数量

        
            Readbmp64k(270+200*i, 100+200*j, products[cnt].photo);//显示商品图片
            cnt++;
            
    	}
    }
 
}

//重新显示商品数量
void draw_user_shop_quantity(Product products[],int productCount,int currentpage){
    int i=0;
    int j=0;
    int cnt=0;
    cnt=(currentpage-1)*12;//决定显示哪一页的商品

    //显示商品信息
    for(j=0;j<3;j++){
    	for(i=0;i<4;i++){//先横向，再竖向
            char quantity_str[20];
            // 使用 sprintf 将 quantity 转换为字符串
            sprintf(quantity_str, "%d", products[cnt].quantity);
            // 调用 PrintText 函数，将 quantity_str 转换为 unsigned char* 类型
            bar1(390+200*i, 75+200*j, 460+200*i, 95+200*j,white);
            PrintText(390+200*i,75+200*j, (unsigned char*)quantity_str,HEI,24,0,black);//显示商品数量
            cnt++;
            
    	}
    }
}

//初始化商品信息
void init_Products(int *productCount){ 
    int i;
   
    strcpy(products[0].name, "盆");
    products[0].price = 5.00;
    products[0].id = 1;
    products[0].type = 1;
    strcpy(products[0].photo, "bmp\\pen.bmp");
    

    strcpy(products[1].name, "扫把");
    products[1].price = 12.00;
    products[1].id = 2;
    products[1].type = 1;
    strcpy(products[1].photo, "bmp\\saoba.bmp");
    
    strcpy(products[2].name, "餐具");
    products[2].price = 10.00;
    products[2].id = 3;
    products[2].type = 1;
    strcpy(products[2].photo, "bmp\\canju.bmp");

    strcpy(products[3].name, "碗");
    products[3].price = 3.00;
    products[3].id = 4;
    products[3].type = 1;
    strcpy(products[3].photo, "bmp\\wan.bmp");

    strcpy(products[4].name, "水杯");
    products[4].price = 15.00;
    products[4].id = 5;
    products[4].type = 1;
    strcpy(products[4].photo, "bmp\\shuibei.bmp");

    strcpy(products[5].name, "衣架");
    products[5].price = 5.00;
    products[5].id = 6;
    products[5].type = 1;
    strcpy(products[5].photo, "bmp\\yijia.bmp");

    strcpy(products[6].name, "牙刷");
    products[6].price = 10.00;
    products[6].id = 7;
    products[6].type = 1;
    strcpy(products[6].photo, "bmp\\yashua.bmp");

    strcpy(products[7].name, "拖把");
    products[7].price = 18.00;
    products[7].id = 8;
    products[7].type = 1;
    strcpy(products[7].photo, "bmp\\tuoba.bmp");

    strcpy(products[8].name, "枕头");
    products[8].price = 20.00;
    products[8].id = 9;
    products[8].type = 1;
    strcpy(products[8].photo, "bmp\\zhentou.bmp");

    strcpy(products[9].name, "毛巾");
    products[9].price = 12.00;
    products[9].id = 10;
    products[9].type = 1;
    strcpy(products[9].photo, "bmp\\maojin.bmp");

    strcpy(products[10].name, "挂钩");
    products[10].price = 1.00;
    products[10].id = 11;
    products[10].type = 1;
    strcpy(products[10].photo, "bmp\\guagou.bmp");

    strcpy(products[11].name, "马桶塞子");
    products[11].price = 12.00;
    products[11].id = 12;
    products[11].type = 1;
    strcpy(products[11].photo, "bmp\\matong.bmp");
/*===========================================================================*/
    strcpy(products[12].name, "黑笔");
    products[12].price = 3.00;
    products[12].id = 13;
    products[12].type = 2;
    strcpy(products[12].photo, "bmp\\blackbi.bmp");

    strcpy(products[13].name, "红笔");
    products[13].price = 3.00;
    products[13].id = 14;
    products[13].type = 2;
    strcpy(products[13].photo, "bmp\\redbi.bmp");

    strcpy(products[14].name, "铅笔");
    products[14].price = 2.00;  
    products[14].id = 15;
    products[14].type = 2;
    strcpy(products[14].photo, "bmp\\qianbi.bmp");

    strcpy(products[15].name, "钢笔");
    products[15].price = 35.00;
    products[15].id = 16;
    products[15].type = 2;
    strcpy(products[15].photo, "bmp\\gangbi.bmp");

    strcpy(products[16].name, "剪刀");
    products[16].price = 12.00;
    products[16].id = 17;
    products[16].type = 2;
    strcpy(products[16].photo, "bmp\\jiandao.bmp");

    strcpy(products[17].name, "橡皮");
    products[17].price = 2.00;
    products[17].id = 18;
    products[17].type = 2;  
    strcpy(products[17].photo, "bmp\\xiangpi.bmp");

    strcpy(products[18].name, "尺子");
    products[18].price = 8.00;
    products[18].id = 19;
    products[18].type = 2;
    strcpy(products[18].photo, "bmp\\chizi.bmp");

    strcpy(products[19].name, "胶带");
    products[19].price = 2.00;
    products[19].id = 20;
    products[19].type = 2;
    strcpy(products[19].photo, "bmp\\jiaodai.bmp");

    strcpy(products[20].name, "固体胶");
    products[20].price = 4.00;
    products[20].id = 21;
    products[20].type = 2;
    strcpy(products[20].photo, "bmp\\jiao.bmp");

    strcpy(products[21].name, "修正带");
    products[21].price = 6.00;
    products[21].id = 22;
    products[21].type = 2;  
    strcpy(products[21].photo, "bmp\\xiuzheng.bmp");

    strcpy(products[22].name, "笔记本");
    products[22].price = 3.00;
    products[22].id = 23;
    products[22].type = 2;
    strcpy(products[22].photo, "bmp\\benzi.bmp");

    strcpy(products[23].name, "订书机");
    products[23].price = 15.00;
    products[23].id = 24;
    products[23].type = 2;
    strcpy(products[23].photo, "bmp\\dingshu.bmp");


    *productCount = 24;

}

//加减商品
void AddSub(int mx, int my, int productCount, Product products[], CartItem carts[], int* itemCount, int currentPage) {
    int i, j, index;
    int baseX = 270, baseY = 235;
    int width = 200, height = 200;

    for (j = 0; j < 3; j++) {
        for (i = 0; i < 4; i++) {
            index = currentPage * 12 + i + j * 4;
            if (index >= productCount) return;

            // 加号区域
            if (mx >= 370 + i * width && mx <= 390 + i * width &&
                my >= 225 + j * height && my <= 245 + j * height) {
                addToCart(products[index], carts, itemCount,index);
                products[index].quantity++;
                return;
            }
            // 减号区域
            if (mx >= 270 + i * width && mx <= 290 + i * width &&
                my >= 225 + j * height && my <= 245 + j * height) {
                if (products[index].quantity > 0) {
                    products[index].quantity--;  // 商品页面数量 -1
                    removeFromCart(products[index], carts, itemCount);
                }else {
                    PrintCC(220,660,"此商品已从购物车中移除",HEI,24,1,lightred);
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
    carts[*itemCount].index_in_products=index;//在商品数组中的索引
    (*itemCount)++;
}

void removeFromCart(Product p, CartItem carts[], int *itemCount) {
    int i, j;
    for (i = 0; i < *itemCount; i++) {
        if (carts[i].id == p.id) {
            if (carts[i].quantity > 1) {
                carts[i].quantity--;
            } else if (carts[i].quantity == 1) {
                // 如果减到 0，删除这个商品
                for (j = i; j < *itemCount - 1; j++) {
                    carts[j] = carts[j + 1];
                }
                (*itemCount)--;
            }
            return;
        }
    }
}

