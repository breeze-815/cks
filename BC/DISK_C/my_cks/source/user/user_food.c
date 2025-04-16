#include "all_func.h"

Food foods[12]={
    {1, 1, "黄焖鸡", 15, "food/黄焖鸡米饭.jpg",0},
    {2, 1, "黄焖鸡", 15, "food/黄焖鸡米饭.jpg",0},
    {3, 1, "黄焖鸡米饭", 15, "food/黄焖鸡米饭.jpg",0},
    {4, 1, "黄焖鸡米饭", 15, "food/黄焖鸡米饭.jpg",0},
    {5, 1, "黄焖鸡米饭", 15, "food/黄焖鸡米饭.jpg",0},
    {6, 1, "黄焖鸡米饭", 15, "food/黄焖鸡米饭.jpg",0},
    {7, 1, "黄焖鸡米饭", 15, "food/黄焖鸡米饭.jpg",0},
    {8, 1, "黄焖鸡米饭", 15, "food/黄焖鸡米饭.jpg",0},
    {9, 1, "黄焖鸡米饭", 15, "food/黄焖鸡米饭.jpg",0},
    {10, 1, "黄焖鸡米饭", 15, "food/黄焖鸡米饭.jpg",0},
    {11, 1, "黄焖鸡米饭", 15, "food/黄焖鸡米饭.jpg",0},
    {12, 1, "黄焖鸡米饭", 15, "food/黄焖鸡米饭.jpg",0}
};
FoodCart food_carts[12]={0};//购物车内的商品
ShoppingFood shopping_food={0};//购物车整体

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
        else if(mouse_press(270, 235, 1070, 835)==1)//点击商品
        {
            MouseGet(&mouse);
            AddSub_food(mouse.x, mouse.y, foodCount, foods, food_carts, &shopping_food.itemCount); 
            draw_food_quantity(foods); //刷新页面显示更新后的数量
            delay(100);
        }
    }
}


void draw_user_food(int index){
    int cnt=0;
    int i,j;
	bar1(200, 0, 1024, 768, white);
    bar1(0, 250, 199, 768, deepblue);

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5,1,deepblue);//查看订单按钮

    PrintCC(850,715,"查看订单",HEI,24,1,deepblue);

    switch(index){
        case 1:
            PrintCC(220,700, "韵苑学生食堂", HEI, 48, 1, deepblue);
            break;
        case 2:
            PrintCC(220,700, "东园食堂", HEI, 48, 1, deepblue);
            break;
        case 3:
            PrintCC(220,700, "东教工食堂", HEI, 48, 1, deepblue);
            break;
        case 4:
            PrintCC(220,700, "学生一食堂", HEI, 48, 1, deepblue);
            break;
        case 5:
            PrintCC(220,700, "学生二食堂", HEI, 48, 1, deepblue);
            break;
        case 6: 
            PrintCC(220,700, "紫荆园餐厅", HEI, 48, 1, deepblue);
            break;
        case 7:
            PrintCC(220,700, "东一食堂", HEI, 48, 1, deepblue);
            break;
        case 8:
            PrintCC(220,700, "东三食堂", HEI, 48, 1, deepblue);
            break;
        case 9:
            PrintCC(220,700, "喻园餐厅", HEI, 48, 1, deepblue);
            break;
        case 10:
            PrintCC(220,700, "百景园", HEI, 48, 1, deepblue);
            break;
        case 11:
            PrintCC(220,700, "西一食堂", HEI, 48, 1, deepblue);
            break;
        case 12:
            PrintCC(220,700, "西二食堂", HEI, 48, 1, deepblue);
            break;
        case 13:
            PrintCC(220,700, "东园食堂", HEI, 48, 1, deepblue);
            break;
        case 14:
            PrintCC(220,700, "东教工食堂", HEI, 48, 1, deepblue);
            break;
        case 15:
            PrintCC(220,700, "西园食堂", HEI, 48, 1, deepblue);
            break;
        case 16:    
            PrintCC(220,700, "南园食堂", HEI, 48, 1, deepblue);
            break;
        case 17:
            PrintCC(220,700, "北园教工食堂", HEI, 48, 1, deepblue);
            break;
        case 18:
            PrintCC(220,700, "南园教工食堂", HEI, 48, 1, deepblue);
            break;
    }

    //显示商品信息
    for(j=0;j<3;j++){
        for(i=0;i<4;i++){//先横向，再竖向
            char quantity_str[20];
            char price_str[20];
            // 使用 sprintf 将 quantity 转换为字符串
            sprintf(quantity_str, "%d", foods[cnt].quantity);
            sprintf(price_str, "%.2f", foods[cnt].price);

            Line_Thick(270+200*i, 235+200*j, 290+200*i, 235+200*j, 1, deepblue);//减号

            Line_Thick(390+200*i, 235+200*j, 370+200*i, 235+200*j, 1, deepblue);//加号
            Line_Thick(380+200*i, 225+200*j, 380+200*i, 245+200*j, 1, deepblue);

            
            PrintCC(270+200*i,75+200*j,foods[cnt].name,HEI,24,1,black);//显示商品名称
            
            PrintText(270+22+200*i, 220+3+200*j,price_str, HEI, 24, 0, black);//显示商品价格
            PrintText(395+200*i,75+200*j, (unsigned char*)quantity_str,HEI,24,0,black);//显示商品数量

        
            Readbmp64k(270+200*i, 100+200*j, foods[cnt].photo);//显示商品图片
            cnt++;
            
        }
    }


}


//重新显示商品数量
void draw_food_quantity(Food foods[]){
    int i=0;
    int j=0;
    int cnt=0;
    //显示商品信息
    for(j=0;j<3;j++){
    	for(i=0;i<4;i++){//先横向，再竖向
            char quantity_str[20];
            // 使用 sprintf 将 quantity 转换为字符串
            sprintf(quantity_str, "%d", foods[cnt].quantity);
            // 调用 PrintText 函数，将 quantity_str 转换为 unsigned char* 类型
            bar1(395+200*i, 75+200*j, 460+200*i, 95+200*j,white);
            PrintText(395+200*i,75+200*j, (unsigned char*)quantity_str,HEI,24,0,black);//显示商品数量
            cnt++;
    	}
    }
}

//加减商品
void AddSub_food(int mx, int my, int foodCount, Food foods[], FoodCart food_carts[], int* itemCount) {
    int i, j, index;
    int baseX = 270, baseY = 235;
    int width = 200, height = 200;

    for (j = 0; j < 3; j++) {
        for (i = 0; i < 4; i++) {
            index = i + j * 4;
            if (index >= foodCount) return;// 超出商品数量，退出

            // 加号区域
            if (mx >= 370 + i * width && mx <= 390 + i * width &&
                my >= 225 + j * height && my <= 245 + j * height) {
                addToCart_food(foods[index], food_carts, itemCount,index);
                foods[index].quantity++;
                return;
            }
            // 减号区域
            if (mx >= 270 + i * width && mx <= 290 + i * width &&
                my >= 225 + j * height && my <= 245 + j * height) {
                if (foods[index].quantity > 0) {
                    foods[index].quantity--;  // 商品页面数量 -1
                    removeFromCart_food(foods[index], food_carts, itemCount);
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
    food_carts[*itemCount].index_in_foods=index;//在商品数组中的索引
    (*itemCount)++;
}

void removeFromCart_food(Food f, FoodCart food_carts[], int *itemCount) {
    int i, j;
    for (i = 0; i < *itemCount; i++) {
        if (food_carts[i].id == f.id) {
            if (food_carts[i].quantity > 1) {
                food_carts[i].quantity--;
            } else if (food_carts[i].quantity == 1) {
                // 如果减到 0，删除这个商品
                for (j = i; j < *itemCount - 1; j++) {
                    food_carts[j] = food_carts[j + 1];
                }
                (*itemCount)--;
            }
            return;
        }
    }
}