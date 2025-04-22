#include "all_func.h"

FoodOrder Foodorders = {0}; // 订单

void food_order(int index){

    UserList UL = {0};
    USER currentUser;

    int page = 0;// 初始页码
    int totalPage =(shopping_food.itemCount - 6 + 11 ) / 12 + 1 ; // 总页数(向上取整)
    int state = 0; // 判断是否需要完善信息
    
    ReadAllUser(&UL); // 读取用户列表

    currentUser=UL.elem[users.pos];// 获取当前用户信息

    DestroyUList(&UL); // 释放用户列表空间

    Foodorders.station = index; // 食堂编号

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
                    draw_food_order(page);// 绘制用户订单页面
                } else {
                    // 提示：已是第一页
                    PrintCC(550, 25, "已是第一页", HEI, 24, 1, lightred);
                    delay(500);
                    bar1(550, 25, 700, 60, white);
                }
            }
            else if (mouse_press(420, 700, 540, 750) == 1) 
            {
                if (page < totalPage - 1) {
                    page++;
                    draw_food_order(page);// 绘制用户订单页面
                } else {
                    // 提示：已是最后一页
                    PrintCC(550, 25, "已是最后一页", HEI, 24, 1, lightred);
                    delay(500);
                    bar1(550, 25, 700, 60, white);
                }
            }
            else if(mouse_press(800, 700, 1000, 750) == 1)
            { 
                if (currentUser.community == '\0' || strlen(currentUser.number) == 0)// 判断用户信息是否完善
                {
                    draw_info();
                    state = 1;
                }
                else
                {
                    save_food(Foodorders); // 保存订单
                    PrintCC(800, 50, "订单已保存", HEI, 24, 1, lightred);
                    delay(500);
                    bar1(800, 50, 1024, 100, white);
                }
            }
        }
        // 完善用户信息
        if(state==1)
        {
            if(mouse_press(430, 105, 650, 155)==1)
            {
                number_input(currentUser.number, 435, 110, 645, 150); // 输入手机号
            }
            else if(mouse_press(710, 105, 830, 155)==1)
            {
                if(strlen(currentUser.number)==11)
                {
                    save_user(currentUser);
                    PrintCC(800,50,"保存成功",HEI,24,1,lightred);
                    delay(500);
                    bar1(800,50,950,100,snow);
                }
                else
                {
                    PrintCC(800,50,"长度不合法",HEI,24,1,lightred);
                    delay(500);
                    bar1(800,50,950,100,snow);
                }
            }
            else if(mouse_press(440, 180, 560, 230)==1)
            {
                press1(4);//紫菘
                currentUser.community=1;//紫菘
                save_user(currentUser);
            }
            else if(mouse_press(620, 180, 740, 230)==1)
            {
                press1(5);//沁苑
                currentUser.community=2;//沁苑
                save_user(currentUser);
            }
            else if(mouse_press(800, 180, 920, 230)==1)
            {
                press1(6);//韵苑
                currentUser.community=3;//韵苑
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
    char address[100]; // 用户地址
    int i;
    UserList UL = {0};
    FoodList FL = {0};
    USER currentUser;
    FoodOrder *currentFood;

    char* current_time = get_current_time(); // 获取当前时间
    char time_str[100]; // 打印下单时间
    char user_name[100]; // 打印用户名
    char user_phone[100]; // 打印用户手机号
    char order_number; // 打印订单号

    int startIdx = 0;// 起始商品索引
    int itemsPerPage = 0;// 每页商品数量
    int endIdx = 0;// 结束商品索引
    int item_y = 0;// 商品框的y坐标

    float total_amount = 0.0; // 总金额
    char total_str[50]; // 总金额字符串
    int fullPageItemCount = 0; // 满页商品数量

    ReadAllUser(&UL); // 读取用户列表
    currentUser = UL.elem[users.pos]; // 获取当前用户信息

    ReadAllFood(&FL); // 读取订单列表
    Foodorders.id = FL.length + 1; // 订单号

    sprintf(time_str, "下单时间：%s", current_time);
    sprintf(user_name, "用户名：%s", currentUser.name);
    sprintf(user_phone, "手机号：%s", currentUser.number);

    bar1(200, 0, 1024, 768, white); // 清空屏幕

    // 分页按钮
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // 上一页
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // 下一页
    PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue); // 确认并支付
    PrintCC(830, 715, "确认并支付", HEI, 24, 1, deepblue);

    // 页头信息只在第一页显示
    if (page == 0) {
        char order_number_str[20]; // 订单号字符串
        char community[50]; // 社区字符串
        char building[50]; // 楼栋字符串
        sprintf(order_number_str, "订单号：%d", Foodorders.id); // 订单号
        PrintText(250, 50, order_number_str, HEI, 24, 1, black);
        PrintText(250, 100, time_str, HEI, 24, 1, black);
        PrintText(250, 150, user_name, HEI, 24, 1, black);
        PrintText(250, 200, user_phone, HEI, 24, 1, black);
        sprintf(address, "地址：%s", node[currentUser.index].name); // 用户地址
        // switch(currentUser.community){// 根据用户地址显示地址
        //     case 1: strcpy(community,"地址：东区学生公寓"); break;
        //     case 2: strcpy(community,"地址：西区学生公寓"); break;
        //     case 3: strcpy(community,"地址：南区学生公寓"); break;
        //     case 4: strcpy(community,"地址：紫菘学生公寓"); break;
        //     case 5: strcpy(community,"地址：韵苑学生公寓"); break;
        //     default: strcpy(community,"地址：未知"); break;
        // }

        // sprintf(building, "%d栋", currentUser.building);
        // strcat(community,building);
        PrintText(250, 250, address, HEI, 24, 1, black);

        PrintCC(750,250, canteen[Foodorders.station-1].name, HEI, 24, 1, black);//显示食堂名称

        // 表头
        PrintCC(250, 300, "商品详情：", HEI, 24, 1, black);
        PrintCC(750, 300, "数量：", HEI, 24, 1, black);
        PrintCC(900, 300, "金额：", HEI, 24, 1, black);
        PrintText(250, 320, "-------------------------------", HEI, 32, 1, black);// 分隔线

        startIdx = 0;
        itemsPerPage = 6;
    } else {
        startIdx = 6 + (page - 1) * 12;
        itemsPerPage = 12;
    }

    endIdx = startIdx + itemsPerPage;
    if (endIdx > shopping_food.itemCount)// 防止越界
        endIdx = shopping_food.itemCount;

    item_y = (page == 0) ? 350 : 50;
    for (i = startIdx; i < endIdx; i++) {
        char total_str[50]; // 商品总价
        char quantity_str[20]; // 商品数量
        int productIndex = food_carts[i].index_in_foods; // 商品索引
        int quantity = foods[productIndex].quantity;

        sprintf(total_str, "%.2f", foods[productIndex].price * quantity);
        sprintf(quantity_str, "x%d", quantity);

        PrintCC(250, item_y, food_carts[i].name, HEI, 24, 1, black); // 商品名
        PrintText(750, item_y, (unsigned char*)quantity_str, HEI, 24, 1, black);// 商品数量
        PrintText(900, item_y, (unsigned char*)total_str, HEI, 24, 1, black);// 商品金额

        item_y += 50;
    }

    // 判断是否需要在此页显示总金额（当前页没有满）
    fullPageItemCount = (page == 0) ? 6 : 12;// 第一页显示6个商品，其余页显示12个商品
    if ((endIdx - startIdx) < fullPageItemCount||endIdx==shopping_food.itemCount) {// 当前页商品数量不满一页或最后一个商品刚好满页都要打印出总金额
        //如果不是最后一个商品但是满页就不打印总金额
        // 打印分隔线
        PrintText(250, item_y - 30, "-------------------------------", HEI, 32, 1, black);

        // 计算总金额
        total_amount = 0.0;
        for (i = 0; i < shopping_food.itemCount; i++) {
            int productIndex = food_carts[i].index_in_foods;
            int quantity = foods[productIndex].quantity;
            total_amount += foods[productIndex].price * quantity;
            food_carts[i].quantity = quantity; // 记录购物车商品数量
            food_carts[i].price = foods[productIndex].price; // 记录商品价格
        }

        sprintf(total_str, "总金额：%.2f 元", total_amount);
        PrintText(750, item_y + 10, total_str, HEI, 24, 1, black);
    }

    //存储订单信息
    strcpy(Foodorders.order_time, current_time); // 下单时间
    strcpy(Foodorders.user_name, currentUser.name); // 用户名
    strcpy(Foodorders.user_phone, currentUser.number); // 用户手机号

    Foodorders.community=currentUser.community; // 用户社区
    Foodorders.building=currentUser.building; 
    //Foodorders.station=; // 用户取餐地点
    Foodorders.destination=currentUser.index; // 用户送餐地点

    for (i = 0; i < shopping_food.itemCount; i++) {
        Foodorders.item[i] = food_carts[i]; // 购物车内商品信息
    }

    Foodorders.itemCount = shopping_food.itemCount; // 购物车内商品数量
    Foodorders.total_amount = total_amount; // 总金额

    //食堂编号在20行存过了

    DestroyUList(&UL); // 释放用户列表空间
    DestroyFList(&FL); // 释放订单列表空间

}

/****************************
功能说明：得到元素在线性表中的位置
参数说明：线性表，元素
返回值：  如果存在就返回位置，否则返回-1
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
功能说明：在线性表L末尾插入元素 
参数说明：线性表地址，要插入的元素
返回值：  无  
****************************/
void FListInsert(FoodList*FL,FoodOrder Foodorders) 
{
    FoodOrder*newbase=NULL;//创建新基址
    if(FL->length>=FL->listsize)//如果线性表已满
    {
        if((newbase=(FoodOrder*)realloc(FL->elem,(FL->listsize+F_LISTINCEREMENT)*sizeof(FoodOrder)))==NULL)////重新分配内存
        {
        CloseSVGA();
        printf("No enough memory!\n");
        printf("FListInsert\n");
        exit(-1);
        }
        FL->elem=newbase;//更新基址
        FL->listsize+=F_LISTINCEREMENT;//更新线性表容量
    }
    *(FL->elem+(FL->length))=Foodorders;//插入新元素
    FL->length++;//线性表长度加一
}

/**********************
功能说明：保存账单信息函数 
参数说明：账单结构体 
返回值说明:0：保存成功   -1： 保存失败 
**********************/
int save_food(FoodOrder Foodorders) {
    int i = 0;
    FoodList FL = {0};
	int order_pos;
	FILE *fp = NULL;

	ReadAllFood(&FL);//读取所有订单信息

    if ((fp = fopen("data\\Foodorder.dat", "wb")) == NULL) {
        printf("无法打开文件！\n");
        return -1;
    }

    // 先查找订单是否已经存在
	order_pos = FoodOrder_pos(FL, Foodorders);

	if (order_pos == -1)  // 如果订单不存在
	{
		FListInsert(&FL, Foodorders); // 插入订单
	}
	else  // 如果订单存在，更新原有订单信息
	{
		Foodorders.id = FL.elem[order_pos].id; // 保留原订单ID
		FL.elem[order_pos] = Foodorders;
	}


    // 重新将线性表写入文件
    rewind(fp);//将文件指针移动到文件开头
    fwrite(&FL.length, sizeof(short), 1, fp);//写入线性表长度
    fwrite(&FL.listsize, sizeof(short), 1, fp);//写入线性表容量
 
    // 逐个写入数据
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

// 初始化线性表
void ReadAllFood(FoodList *FL) {
    int i = 0;
    short length = 0;//线性表初始长度
    short listsize = 10; //线性表初始容量（能够存储10个订单）
    FILE *fp = NULL;

    if ((fp = fopen("data\\Foodorder.dat", "rb")) == NULL) {//如果打开文件失败
        fp = fopen("data\\Foodorder.dat", "wb");// 如果文件不存在则创建一个新的文件
        if (fp == NULL) {//如果创建文件失败
            printf("无法创建文件！\n");
            return;//无法创建文件则返回，不需要继续执行下面的代码
        }
        fwrite(&length, sizeof(short), 1, fp); //如果创建成功则写入初始长度0
        fwrite(&listsize, sizeof(short), 1, fp); //写入初始容量10
        fclose(fp);//关闭文件
        return;//创建完成后返回，不需要继续执行下面的代码
    }
    //如果打开文件成功则读取长度和容量
    fread(&length, sizeof(short), 1, fp); 
    fread(&listsize, sizeof(short), 1, fp); 
    //把读取的长度和容量赋值给线性表
    FL->length = length;
    FL->listsize = listsize;
    FL->elem = (FoodOrder *)malloc(listsize * sizeof(FoodOrder)); //分配存储空间
    //如果线性表的存储空间分配失败则输出错误信息并退出程序
    if (FL->elem == NULL) {
        printf("No enough memory!\n");
        printf("ReadAllOrder\n");
        fclose(fp);
        exit(-1);
    }
    //如果分配成功就逐个读取订单数据
    //并把读取的数据存储到线性表中
    for (i = 0; i < length; i++) {
        fread(&FL->elem[i], sizeof(FoodOrder), 1, fp);
    }

    fclose(fp);
}