#include "all_func.h"

Order orders = {0}; // 订单

void user_order(){

    int page = 0;// 初始页码
    int totalPage =(cart.itemCount - 6 + 11 ) / 12 + 1 ; // 总页数(向上取整)

    mouse_off_arrow(&mouse);

    draw_user_order(page);

    mouse_on_arrow(mouse);

    while(1){
        mouse_show_arrow(&mouse);

        if (mouse_press(40, 113, 160, 163) == 1) 
        {
            user_cart();// 返回用户购物车页面
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
            save_order(orders); // 保存订单
            PrintCC(800, 50, "订单已保存", HEI, 24, 1, lightred);
            delay(500);
            bar1(800, 50, 1024, 100, white);
        }
    }
}

void draw_page_header(USER *currentUser, int order_id, char *current_time) {
    char time_str[100], user_name[100], user_phone[100], order_number_str[20];

    sprintf(order_number_str, "订单号：%d", order_id);
    sprintf(time_str, "下单时间：%s", current_time);
    sprintf(user_name, "用户名：%s", currentUser->name);
    sprintf(user_phone, "手机号：%s", currentUser->number);

    PrintText(250, 50, order_number_str, HEI, 24, 1, black);
    PrintText(250, 100, time_str, HEI, 24, 1, black);
    PrintText(250, 150, user_name, HEI, 24, 1, black);
    PrintText(250, 200, user_phone, HEI, 24, 1, black);

    switch (currentUser->address) {
        case 1: PrintText(250, 250, "地址：紫菘学生公寓", HEI, 24, 1, black); break;
        case 2: PrintText(250, 250, "地址：沁苑学生公寓", HEI, 24, 1, black); break;
        case 3: PrintText(250, 250, "地址：韵苑学生公寓", HEI, 24, 1, black); break;
        default: PrintText(250, 250, "地址：未知", HEI, 24, 1, black); break;
    }

    PrintCC(250, 300, "商品详情：", HEI, 24, 1, black);
    PrintCC(750, 300, "数量：", HEI, 24, 1, black);
    PrintCC(900, 300, "金额：", HEI, 24, 1, black);
    PrintText(250, 320, "-------------------------------", HEI, 32, 1, black);
}

void draw_pagination_buttons() {
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue);
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue);
    PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue);
    PrintCC(830, 715, "确认并支付", HEI, 24, 1, deepblue);
}

void draw_order_items(int startIdx, int endIdx, int item_y) {
    int i;
    for (i = startIdx; i < endIdx; i++) {
        int productIndex = carts[i].index_in_products;
        int quantity = products[productIndex].quantity;
        char total_str[50], quantity_str[20];

        sprintf(total_str, "%.2f", products[productIndex].price * quantity);
        sprintf(quantity_str, "x%d", quantity);

        PrintCC(250, item_y, carts[i].name, HEI, 24, 1, black);
        PrintText(750, item_y, (unsigned char*)quantity_str, HEI, 24, 1, black);
        PrintText(900, item_y, (unsigned char*)total_str, HEI, 24, 1, black);

        item_y += 50;
    }
}

void draw_total_amount(int item_y) {
    float total_amount = 0.0;
    char total_str[50];
    int i;

    PrintText(250, item_y - 30, "-------------------------------", HEI, 32, 1, black);

    for ( i = 0; i < cart.itemCount; i++) {
        int productIndex = carts[i].index_in_products;
        int quantity = products[productIndex].quantity;
        total_amount += products[productIndex].price * quantity;
        carts[i].quantity = quantity;
        carts[i].price = products[productIndex].price;
    }

    sprintf(total_str, "总金额：%.2f 元", total_amount);
    PrintText(750, item_y + 10, total_str, HEI, 24, 1, black);
}

void store_order_data(char *current_time, USER *currentUser, float total_amount) {
    int i;
    strcpy(orders.order_time, current_time);
    strcpy(orders.user_name, currentUser->name);
    strcpy(orders.user_phone, currentUser->number);
    orders.address = currentUser->address;
    
    for ( i = 0; i < cart.itemCount; i++) {
        orders.item[i] = carts[i];
    }
    orders.itemCount = cart.itemCount;
    orders.total_amount = total_amount;
}

void draw_user_order(int page) {
    int startIdx, itemsPerPage, endIdx, item_y, fullPageItemCount;
    UserList UL = {0};
    OrderList OL = {0};
    USER *currentUser;
    char *current_time;
    float total_amount;

    ReadAllUser(&UL);
    currentUser = &UL.elem[users.pos];

    ReadAllOrder(&OL);
    orders.id = OL.length + 1;

    current_time = get_current_time();

    bar1(200, 0, 1024, 768, white);
    draw_pagination_buttons();

    if (page == 0) {
        draw_page_header(currentUser, orders.id, current_time);
        startIdx = 0;
        itemsPerPage = 6;
    } else {
        startIdx = 6 + (page - 1) * 12;
        itemsPerPage = 12;
    }

    endIdx = startIdx + itemsPerPage;
    if (endIdx > cart.itemCount)
        endIdx = cart.itemCount;

    item_y = (page == 0) ? 350 : 50;
    draw_order_items(startIdx, endIdx, item_y);

    fullPageItemCount = (page == 0) ? 6 : 12;
    if ((endIdx - startIdx) < fullPageItemCount || endIdx == cart.itemCount) {
        draw_total_amount(item_y);
    }

    store_order_data(current_time, currentUser, total_amount);
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