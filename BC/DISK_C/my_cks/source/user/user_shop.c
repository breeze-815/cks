#include "all_func.h"

Product products[84]=
{
/*1===========================================================================*/
    {1, 1, "盆", 5.00, "bmp\\shop\\pen.bmp", 0},
    {2, 1, "扫把", 12.00, "bmp\\shop\\saoba.bmp", 0},
    {3, 1, "餐具", 10.00, "bmp\\shop\\canju.bmp", 0},
    {4, 1, "碗", 3.00, "bmp\\shop\\wan.bmp", 0},
    {5, 1, "水杯", 15.00, "bmp\\shop\\shuibei.bmp", 0},
    {6, 1, "衣架", 5.00, "bmp\\shop\\yijia.bmp", 0},
    {7, 1, "牙刷", 10.00, "bmp\\shop\\yashua.bmp", 0},
    {8, 1, "拖把", 18.00, "bmp\\shop\\tuoba.bmp", 0},
    {9, 1, "枕头", 20.00, "bmp\\shop\\zhentou.bmp", 0},
    {10, 1, "毛巾", 12.00, "bmp\\shop\\maojin.bmp", 0},
    {11, 1, "挂钩", 1.00, "bmp\\shop\\guagou.bmp", 0},
    {12, 1, "马桶塞子", 10.00, "bmp\\shop\\matong.bmp", 0},
/*2===========================================================================*/
    {13, 2, "黑笔", 2.00, "bmp\\shop\\blackbi.bmp", 0},
    {14, 2, "红笔", 3.00, "bmp\\shop\\redbi.bmp", 0},
    {15, 2, "铅笔", 4.00, "bmp\\shop\\qianbi.bmp", 0},
    {16, 2, "钢笔", 35.00, "bmp\\shop\\gangbi.bmp", 0},
    {17, 2, "剪刀", 12.00, "bmp\\shop\\jiandao.bmp", 0},
    {18, 2, "橡皮", 2.00, "bmp\\shop\\xiangpi.bmp", 0},
    {19, 2, "尺子", 8.00, "bmp\\shop\\chizi.bmp", 0},
    {20, 2, "胶带", 2.00, "bmp\\shop\\jiaodai.bmp", 0},
    {21, 2, "固体胶", 4.00, "bmp\\shop\\jiao.bmp", 0},
    {22, 2, "修正带", 6.00, "bmp\\shop\\xiuzheng.bmp", 0}, 
    {23, 2, "笔记本", 3.00, "bmp\\shop\\benzi.bmp", 0},
    {24, 2, "订书机", 15.00, "bmp\\shop\\dingshu.bmp", 0},
/*3===========================================================================*/
    {25, 3, "薯片", 7.00, "bmp\\shop\\shupian.bmp", 0},
    {26, 3, "达利园蛋糕", 1.00, "bmp\\shop\\dali.bmp", 0},
    {27, 3, "奥利奥饼干", 8.00, "bmp\\shop\\aoliao.bmp", 0},
    {28, 3, "辣条", 5.00, "bmp\\shop\\latiao.bmp", 0},
    {29, 3, "大白兔奶糖", 1.00, "bmp\\shop\\dabaitu.bmp", 0},
    {30, 3, "卤鹌鹑蛋", 1.00, "bmp\\shop\\ludan.bmp", 0},
    {31, 3, "巧克力", 1.00, "bmp\\shop\\defu.bmp", 0},
    {32, 3, "锅巴", 1.00, "bmp\\shop\\guoba.bmp", 0},
    {33, 3, "吐司面包", 1.00, "bmp\\shop\\tusi.bmp", 0},
    {34, 3, "鸡腿", 1.00, "bmp\\shop\\jitui.bmp", 0},
    {35, 3, "方便面", 1.00, "bmp\\shop\\paomian.bmp", 0},
    {36, 3, "薄荷糖", 1.00, "bmp\\shop\\bohe.bmp", 0},
/*4===========================================================================*/
    {37, 4, "可口可乐", 3.00, "bmp\\shop\\kekou.bmp", 0},
    {38, 4, "百事可乐", 3.00, "bmp\\shop\\baishi.bmp", 0},
    {39, 4, "芬达", 3.00, "bmp\\shop\\fenda.bmp", 0},
    {40, 4, "阿萨姆奶茶", 4.00, "bmp\\shop\\asamu.bmp", 0},
    {41, 4, "茶兀", 5.00, "bmp\\shop\\chapi.bmp", 0},
    {42, 4, "脉动", 5.00, "bmp\\shop\\maidong.bmp", 0},
    {43, 4, "雪碧", 3.00, "bmp\\shop\\xuebi.bmp", 0},
    {44, 4, "冰红茶", 3.00, "bmp\\shop\\bing.bmp", 0},
    {45, 4, "绿茶", 3.00, "bmp\\shop\\lv.bmp", 0},
    {46, 4, "优酸乳", 2.00, "bmp\\shop\\you.bmp", 0},
    {47, 4, "纯牛奶", 4.00, "bmp\\shop\\milk.bmp", 0},
    {48, 4, "酸奶", 5.00, "bmp\\shop\\suan.bmp", 0},
/*5===========================================================================*/
    {49, 5, "篮球", 10.00, "bmp\\shop\\lanqiu.bmp", 0},
    {50, 5, "足球", 10.00, "bmp\\shop\\zuqiu.bmp", 0},
    {51, 5, "羽毛球", 10.00, "bmp\\shop\\yu.bmp", 0},
    {52, 5, "乒乓球", 10.00, "bmp\\shop\\ping.bmp", 0},
    {53, 5, "网球", 10.00, "bmp\\shop\\wang.bmp", 0},
    {54, 5, "排球", 10.00, "bmp\\shop\\pai.bmp", 0},
    {55, 5, "网球拍", 10.00, "bmp\\shop\\wangpai.bmp", 0},
    {56, 5, "羽毛球拍", 10.00, "bmp\\shop\\yupai.bmp", 0},    
    {57, 5, "乒乓球拍", 10.00, "bmp\\shop\\pingpai.bmp", 0},
    {58, 5, "跳绳", 10.00, "bmp\\shop\\tiao.bmp", 0},
    {59, 5, "哑铃", 10.00, "bmp\\shop\\ya.bmp", 0},
    {60, 5, "运动背包", 50.00, "bmp\\shop\\beibao.bmp", 0},
/*6===========================================================================*/
    {61, 6, "苹果", 10.00, "bmp\\shop\\apple.bmp", 0},
    {62, 6, "哈密瓜", 10.00, "bmp\\shop\\hami.bmp", 0},
    {63, 6, "梨", 10.00, "bmp\\shop\\pear.bmp", 0},
    {64, 6, "橘子", 10.00, "bmp\\shop\\orange.bmp", 0},
    {65, 6, "草莓", 10.00, "bmp\\shop\\cao.bmp", 0},
    {66, 6, "西瓜", 10.00, "bmp\\shop\\xigua.bmp", 0},
    {67, 6, "火龙果", 10.00, "bmp\\shop\\huo.bmp", 0},
    {68, 6, "芒果", 10.00, "bmp\\shop\\mango.bmp", 0},
    {69, 6, "猕猴桃", 10.00, "bmp\\shop\\mihou.bmp", 0},
    {70, 6, "蓝莓", 10.00, "bmp\\shop\\lan.bmp", 0},
    {71, 6, "樱桃", 10.00, "bmp\\shop\\yingtao.bmp", 0},
    {72, 6, "圣女果", 10.00, "bmp\\shop\\shengnv.bmp", 0},
/*7===========================================================================*/
    {73, 7, "笔记本套装", 10.00, "bmp\\shop\\bijitao.bmp", 0},
    {74, 7, "茶杯套装", 10.00, "bmp\\shop\\chatao.bmp", 0},
    {75, 7, "书签套装", 10.00, "bmp\\shop\\shutao.bmp", 0},
    {76, 7, "帆布包", 10.00, "bmp\\shop\\fanbu.bmp", 0},
    {77, 7, "钥匙扣", 10.00, "bmp\\shop\\yaoshi.bmp", 0},
    {78, 7, "明信片", 10.00, "bmp\\shop\\mingxin.bmp", 0},
    {79, 7, "文创直尺", 10.00, "bmp\\shop\\wenchi.bmp", 0},
    {80, 7, "冰箱贴", 10.00, "bmp\\shop\\bingx.bmp", 0},
    {81, 7, "文化衫", 10.00, "bmp\\shop\\wenshan.bmp", 0},
    {82, 7, "金属书签", 10.00, "bmp\\shop\\jinqian.bmp", 0},
    {83, 7, "金属吊坠", 10.00, "bmp\\shop\\jinzhui.bmp", 0},
    {84, 7, "校徽", 10.00, "bmp\\shop\\xiaohui.bmp", 0},
/*===========================================================================*/
};
CartItem carts[84]={0};
ShoppingCart cart={0};

void user_shop(){
    int productCount = 84;//超市里商品数量初始化
    int currentpage = 1;//当前页面初始化
    int state=0;//0为未点击排序，1为已点击排序

    mouse_off_arrow(&mouse);//隐藏鼠标
	
	draw_user_shop(products, productCount,currentpage);//绘制用户超市页面

	mouse_on_arrow(mouse);//显示鼠标

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            int i;
            for(i=0;i<productCount;i++)
            {
                products[i].quantity=0;//清空商品数量
            }
            cart.itemCount=0;//清空购物车
            cart.items=NULL;//清空购物车
            
            return;
			//welcome();//首页
		}
        else if(mouse_press(40, 276, 160, 326)==1)
        {
            press1(1);//进入超市页面
            user_shop();//用户超市页面 
            return;
        }
        else if(mouse_press(40, 439, 160, 489)==1)
        {
            press1(2);//进入外卖页面
            user_takeout();//用户外卖页面 
            return;
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            press1(3);//进入快递页面
            user_deliver();//用户快递页面 
            return;
        }
        else if(mouse_press(800, 700, 1000, 750)==1)
        {
            user_cart();//用户购物车页面
            break;
        }else if(mouse_press(220,75, 250, 90)==1)
        {
            mouse_off_arrow(&mouse);//隐藏鼠标
            draw_sort();//绘制排序页面
            mouse_on_arrow(mouse);//显示鼠标
            state=1;//已点击排序
        }
        else if(mouse_press(200, 0, 320, 50)==1)
        {
            currentpage = 1;//生活用品
            mouse_off_arrow(&mouse);//隐藏鼠标
            draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
            mouse_on_arrow(mouse);//显示鼠标

        }
        else if(mouse_press(320, 0, 440, 50)==1)
        {
            currentpage = 2;//文具
            mouse_off_arrow(&mouse);//隐藏鼠标
            draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
            mouse_on_arrow(mouse);//显示鼠标
        }
        else if(mouse_press(440, 0, 560, 50)==1)
        {
            currentpage = 3;//零食
            mouse_off_arrow(&mouse);//隐藏鼠标
            draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
            mouse_on_arrow(mouse);//显示鼠标
        }
        else if(mouse_press(560, 0, 680, 50)==1)
        {
            currentpage = 4;//饮料
            mouse_off_arrow(&mouse);//隐藏鼠标
            draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
            mouse_on_arrow(mouse);//显示鼠标
        }
        else if(mouse_press(680, 0, 800, 50)==1)
        {
            currentpage = 5;//运动用品
            mouse_off_arrow(&mouse);//隐藏鼠标
            draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
            mouse_on_arrow(mouse);//显示鼠标
        }
        else if(mouse_press(800, 0, 920, 50)==1)
        {
            currentpage = 6;//水果
            mouse_off_arrow(&mouse);//隐藏鼠标
            draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
            mouse_on_arrow(mouse);//显示鼠标
        }
        else if(mouse_press(920, 0, 1024, 50)==1)
        {
            currentpage = 7;//文创
            mouse_off_arrow(&mouse);//隐藏鼠标
            draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
            mouse_on_arrow(mouse);//显示鼠标
        }
        else if(mouse_press(270, 235, 1070, 835)==1)//点击商品
        {
            MouseGet(&mouse);
            AddSub(mouse.x, mouse.y, productCount, products, carts, &cart.itemCount, currentpage - 1); //注意currentpage从1开始，计算index时需减1
            draw_user_shop_quantity(products, productCount, currentpage); //刷新页面显示更新后的数量
            delay(100);
        }

        //点击排序
        if (state == 1) {
            if (mouse_press(205, 95, 445, 144) == 1) // 点击从高到低
            {
                int i, j;
                int cnt = (currentpage - 1) * 12; // 当前页起始下标
                int end = cnt + 12;
        
                for (i = cnt; i < end - 1; i++) {
                    for (j = cnt; j < end - 1 - (i - cnt); j++) {
                        if (products[j].price < products[j + 1].price) {
                            Product temp = products[j];
                            products[j] = products[j + 1];
                            products[j + 1] = temp;
                        }
                    }
                }

                mouse_off_arrow(&mouse);//隐藏鼠标
                draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
                mouse_on_arrow(mouse);//显示鼠标
                state=0;
            }
            else if(mouse_press(205, 146, 445, 295)==1)//点击从低到高
            {
            	int i, j;
                int cnt = (currentpage - 1) * 12; // 当前页起始下标
                int end = cnt + 12;
        
                for (i = cnt; i < end - 1; i++) {
                    for (j = cnt; j < end - 1 - (i - cnt); j++) {
                        if (products[j].price > products[j + 1].price) {
                            Product temp = products[j];
                            products[j] = products[j + 1];
                            products[j + 1] = temp;
                        }
                    }
                }

                mouse_off_arrow(&mouse);//隐藏鼠标
                draw_user_shop(products, productCount,currentpage);//绘制用户超市页面
                mouse_on_arrow(mouse);//显示鼠标
                state=0;
            }

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

    Line_Thick(220,75,235,90,1,black);//
    Line_Thick(235,90,250,75,1,black);//



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
            PrintText(395+200*i,75+200*j, (unsigned char*)quantity_str,HEI,24,0,black);//显示商品数量

        
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
            bar1(395+200*i, 75+200*j, 460+200*i, 95+200*j,white);
            PrintText(395+200*i,75+200*j, (unsigned char*)quantity_str,HEI,24,0,black);//显示商品数量
            cnt++;
            
    	}
    }
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

void draw_sort(){
	Fill_Rounded_Rectangle(205, 95, 455, 200, 30,snow);//填色
    Draw_Rounded_Rectangle(205, 95, 455, 200, 30, 1,0x6B4D);//最外围灰色圆角矩形

    PrintText(225, 110,"价格从高到低排序",HEI,24,1,black);
    Line_Thick(215, 145, 445, 145, 1, deepgrew);//横线
    PrintText(225, 160,"价格从低到高排序",HEI,24,1,black);
}