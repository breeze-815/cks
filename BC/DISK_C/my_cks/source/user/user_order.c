#include "all_func.h"

Order orders = {0}; // 订单

void user_order(){

    UserList UL = {0};
    USER *currentUser;

    int page = 0;// 初始页码
    int totalPage =(cart.itemCount - 6 + 11 ) / 12 + 1 ; // 总页数(向上取整)
    
    ReadAllUser(&UL); // 读取用户列表

    currentUser=&UL.elem[users.pos];// 获取当前用户信息

    DestroyUList(&UL); // 释放用户列表空间

    mouse_off_arrow(&mouse);

    draw_user_order(page);

    mouse_on_arrow(mouse);

    while(1){
        mouse_show_arrow(&mouse);

        if (mouse_press(40, 113, 160, 163) == 1) 
        {
            //user_cart();// 返回用户购物车页面
            return;
        }
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_user_order(page);// 绘制用户订单页面
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
				draw_user_order(page);// 绘制用户订单页面
			} else {
				// 提示：已是最后一页
				PrintCC(550, 25, "已是最后一页", HEI, 24, 1, lightred);
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
                save_order(orders); // 保存订单
                PrintCC(800, 50, "订单已保存", HEI, 24, 1, lightred);
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
    currentUser = &UL.elem[users.pos]; // 获取当前用户信息

    ReadAllOrder(&OL); // 读取订单列表
    orders.id = OL.length + 1; // 订单号

    sprintf(time_str, "下单时间：%s", current_time);
    sprintf(user_name, "用户名：%s", currentUser->name);
    sprintf(user_phone, "手机号：%s", currentUser->number);

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
        sprintf(order_number_str, "订单号：%d", orders.id); // 订单号
        PrintText(250, 50, order_number_str, HEI, 24, 1, black);
        PrintText(250, 100, time_str, HEI, 24, 1, black);
        PrintText(250, 150, user_name, HEI, 24, 1, black);
        PrintText(250, 200, user_phone, HEI, 24, 1, black);

        switch(currentUser->community){// 根据用户地址显示地址
            case 0: PrintText(250, 250, "地址：是零", HEI, 24, 1, black); break;
            case 1: PrintText(250, 250, "地址：东区学生公寓", HEI, 24, 1, black); break;
            case 2: PrintText(250, 250, "地址：西区学生公寓", HEI, 24, 1, black); break;
            case 3: PrintText(250, 250, "地址：南区学生公寓", HEI, 24, 1, black); break;
            case 4: PrintText(250, 250, "地址：紫菘学生公寓", HEI, 24, 1, black); break;
            case 5: PrintText(250, 250, "地址：韵苑学生公寓", HEI, 24, 1, black); break;
            default: PrintText(250, 250, "地址：未知", HEI, 24, 1, black); break;
        }

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
    if (endIdx > cart.itemCount)// 防止越界
        endIdx = cart.itemCount;

    item_y = (page == 0) ? 350 : 50;
    for (i = startIdx; i < endIdx; i++) {
        char total_str[50]; // 商品总价
        char quantity_str[20]; // 商品数量
        int productIndex = carts[i].index_in_products; // 商品索引
        int quantity = products[productIndex].quantity;

        sprintf(total_str, "%.2f", products[productIndex].price * quantity);
        sprintf(quantity_str, "x%d", quantity);

        PrintCC(250, item_y, carts[i].name, HEI, 24, 1, black); // 商品名
        PrintText(750, item_y, (unsigned char*)quantity_str, HEI, 24, 1, black);
        PrintText(900, item_y, (unsigned char*)total_str, HEI, 24, 1, black);

        item_y += 50;
    }

    // 判断是否需要在此页显示总金额（当前页没有满）
    fullPageItemCount = (page == 0) ? 6 : 12;// 第一页显示6个商品，其余页显示12个商品
    if ((endIdx - startIdx) < fullPageItemCount||endIdx==cart.itemCount) {// 当前页商品数量不满一页或最后一个商品刚好满页都要打印出总金额
        //如果不是最后一个商品但是满页就不打印总金额
        // 打印分隔线
        PrintText(250, item_y - 30, "-------------------------------", HEI, 32, 1, black);

        // 计算总金额
        total_amount = 0.0;
        for (i = 0; i < cart.itemCount; i++) {
            int productIndex = carts[i].index_in_products;
            int quantity = products[productIndex].quantity;
            total_amount += products[productIndex].price * quantity;
            carts[i].quantity = quantity; // 记录购物车商品数量
            carts[i].price = products[productIndex].price; // 记录商品价格
        }

        sprintf(total_str, "总金额：%.2f 元", total_amount);
        PrintText(750, item_y + 10, total_str, HEI, 24, 1, black);
    }

    //存储订单信息
    strcpy(orders.order_time, current_time); // 下单时间
    strcpy(orders.user_name, currentUser->name); // 用户名
    strcpy(orders.user_phone, currentUser->number); // 用户手机号
    orders.community=currentUser->community; // 用户社区
    orders.building=currentUser->building; 
    for (i = 0; i < cart.itemCount; i++) {
        orders.item[i] = carts[i]; // 购物车内商品信息
    }
    orders.itemCount = cart.itemCount; // 购物车内商品数量
    orders.total_amount = total_amount; // 总金额

}

void draw_info(){

    Fill_Rounded_Rectangle(225, 25, 1000, 250, 30,snow);//填色
    Draw_Rounded_Rectangle(225, 25, 1000, 250, 30, 2,0x6B4D);//最外围灰色圆角矩形框

    PrintCC(250, 50, "请先完善个人信息", HEI, 24, 1, lightred);

    Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,deepblue);//紫菘按钮
    Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,deepblue);//沁苑按钮
    Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,deepblue);//韵苑按钮

    Draw_Rounded_Rectangle(430, 105, 650, 155, 5, 1,deepblue);//手机号输入框 
    Draw_Rounded_Rectangle(710, 105, 830, 155, 25, 1,deepblue);//保存按钮

    PrintCC(250,120,"请输入手机号：",HEI,24,1,deepblue);
    PrintCC(250,190,"请选择住址：",HEI,24,1,deepblue);
    PrintCC(745,120,"保存",HEI,24,1,deepblue);
}
// 获取当前时间并转换为字符串
char* get_current_time() {
    time_t rawtime;
    struct tm * timeinfo;
    static char buffer[20];

    // 获取当前时间
    time(&rawtime);
    // 将时间转换为本地时间
    timeinfo = localtime(&rawtime);

    // 将时间转换为字符串
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return buffer;
}

/****************************
功能说明：得到元素在线性表中的位置
参数说明：线性表，元素
返回值：  如果存在就返回位置，否则返回-1
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
功能说明：在线性表L末尾插入元素 
参数说明：线性表地址，要插入的元素
返回值：  无  
****************************/
void OListInsert(OrderList*OL,Order orders) 
{
    Order*newbase=NULL;//创建新基址
    if(OL->length>=OL->listsize)//如果线性表已满
    {
        if((newbase=(Order*)realloc(OL->elem,(OL->listsize+O_LISTINCEREMENT)*sizeof(Order)))==NULL)////重新分配内存
        {
        CloseSVGA();
        printf("No enough memory!\n");
        printf("OListInsert\n");
        exit(-1);
        }
        OL->elem=newbase;//更新基址
        OL->listsize+=O_LISTINCEREMENT;//更新线性表容量
    }
    *(OL->elem+(OL->length))=orders;//插入新元素
    OL->length++;//线性表长度加一
}

/**********************
功能说明：保存账单信息函数 
参数说明：账单结构体 
返回值说明:0：保存成功   -1： 保存失败 
**********************/
int save_order(Order orders) {
    int i = 0;
    OrderList OL = {0};
	int order_pos;
	FILE *fp = NULL;

	ReadAllOrder(&OL);//读取所有订单信息

    if ((fp = fopen("data\\order.dat", "wb")) == NULL) {
        printf("无法打开文件！\n");
        return -1;
    }

    // 先查找订单是否已经存在
	order_pos = Order_pos(OL, orders);

	if (order_pos == -1)  // 如果订单不存在
	{
		OListInsert(&OL, orders); // 插入订单
	}
	else  // 如果订单存在，更新原有订单信息
	{
		orders.id = OL.elem[order_pos].id; // 保留原订单ID
		OL.elem[order_pos] = orders;
	}


    // 重新将线性表写入文件
    rewind(fp);//将文件指针移动到文件开头
    fwrite(&OL.length, sizeof(short), 1, fp);//写入线性表长度
    fwrite(&OL.listsize, sizeof(short), 1, fp);//写入线性表容量
 
    // 逐个写入数据
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

// 初始化线性表
void ReadAllOrder(OrderList *OL) {
    int i = 0;
    short length = 0;//线性表初始长度
    short listsize = 10; //线性表初始容量（能够存储10个订单）
    FILE *fp = NULL;

    if ((fp = fopen("data\\order.dat", "rb")) == NULL) {//如果打开文件失败
        fp = fopen("data\\order.dat", "wb");// 如果文件不存在则创建一个新的文件
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
    OL->length = length;
    OL->listsize = listsize;
    OL->elem = (Order *)malloc(listsize * sizeof(Order)); //分配存储空间
    //如果线性表的存储空间分配失败则输出错误信息并退出程序
    if (OL->elem == NULL) {
        printf("No enough memory!\n");
        printf("ReadAllOrder\n");
        fclose(fp);
        exit(-1);
    }
    //如果分配成功就逐个读取订单数据
    //并把读取的数据存储到线性表中
    for (i = 0; i < length; i++) {
        fread(&OL->elem[i], sizeof(Order), 1, fp);
    }

    fclose(fp);
}