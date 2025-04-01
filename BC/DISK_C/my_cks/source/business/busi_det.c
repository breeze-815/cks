#include "all_func.h"
void business_detail(int order_index) {
    
    OrderList OL = {0};

    int page = 0;// 初始页码
    int totalPage; // 总页数

    ReadAllOrder(&OL); // 读取订单列表

    totalPage =(OL.elem[order_index].itemCount  - 6 + 11 ) / 12 + 1 ; // 总页数(向上取整)

    mouse_off_arrow(&mouse);

    draw_business_detail(&OL, order_index ,page); // 绘制订单详情页面

    mouse_on_arrow(mouse);

    while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            DestroyOList(&OL); // 释放订单列表内存
            return;
			//business_order();//返回
		}
        else if (mouse_press(220, 700, 340, 750) == 1) 
		{
            if (page > 0) {
                page--;
                draw_business_detail(&OL, order_index ,page);
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
				draw_business_detail(&OL, order_index ,page);
			} else {
				// 提示：已是最后一页
				PrintCC(550, 25, "已是最后一页", HEI, 24, 1, lightred);
				delay(500);
				bar1(550, 25, 700, 60, white);
			}
		}
    }
}

void draw_business_detail(OrderList *OL ,int order_index,int page) {
    int i;
    Order currentOrder ; 

    char current_time[20]; // 获取当前时间
    char time_str[100]; // 打印下单时间
    char user_name[100]; // 打印用户名
    char user_phone[100]; // 打印用户手机号
    char order_number; // 打印订单号

    int startIdx = 0;// 起始商品索引
    int itemsPerPage = 0;// 每页商品数量
    int endIdx = 0;// 结束商品索引
    int item_y = 0;// 商品框的y坐标

    float total_amount = 0.0; // 总金额
    char total_str[20]; // 总金额字符串
    int fullPageItemCount = 0; // 满页商品数量

    currentOrder = OL->elem[order_index]; // 当前订单
    strcpy(current_time, currentOrder.order_time);

    sprintf(time_str, "下单时间：%s", current_time);
    sprintf(user_name, "用户名：%s", currentOrder.user_name);
    sprintf(user_phone, "手机号：%s", currentOrder.user_phone);

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
        sprintf(order_number_str, "订单号：%d", currentOrder.id); // 订单号
        PrintText(250, 50, order_number_str, HEI, 24, 1, black);
        PrintText(250, 100, time_str, HEI, 24, 1, black);
        PrintText(250, 150, user_name, HEI, 24, 1, black);
        PrintText(250, 200, user_phone, HEI, 24, 1, black);

        switch(currentOrder.address){// 根据用户地址显示地址
            case 1: PrintText(250, 250, "地址：紫菘学生公寓", HEI, 24, 1, black); break;
            case 2: PrintText(250, 250, "地址：沁苑学生公寓", HEI, 24, 1, black); break;
            case 3: PrintText(250, 250, "地址：韵苑学生公寓", HEI, 24, 1, black); break;
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
    if (endIdx > currentOrder.itemCount)// 防止越界
        endIdx = currentOrder.itemCount;

    item_y = (page == 0) ? 350 : 50;
    for (i = startIdx; i < endIdx; i++) {
        char total_str[50]; // 商品总价
        char quantity_str[20]; // 商品数量
        int quantity = currentOrder.item[i].quantity; // 商品数量
        float price = currentOrder.item[i].price; // 商品价格

        sprintf(total_str, "%.2f", price * quantity);
        sprintf(quantity_str, "x%d", quantity);

        PrintCC(250, item_y, currentOrder.item[i].name, HEI, 24, 1, black); // 商品名
        PrintText(750, item_y, (unsigned char*)quantity_str, HEI, 24, 1, black);
        PrintText(900, item_y, (unsigned char*)total_str, HEI, 24, 1, black);

        item_y += 50;
    }

    // 判断是否需要在此页显示总金额（当前页没有满）
    fullPageItemCount = (page == 0) ? 6 : 12;// 第一页显示6个商品，其余页显示12个商品
    if ((endIdx - startIdx) < fullPageItemCount||endIdx==currentOrder.itemCount) {// 当前页商品数量不满一页或最后一个商品刚好满页都要打印出总金额
        //如果不是最后一个商品但是满页就不打印总金额
        // 打印分隔线
        PrintText(250, item_y - 30, "-------------------------------", HEI, 32, 1, black);

        // 计算总金额
        total_amount = 0.0;
        for (i = 0; i < currentOrder.itemCount; i++) {
            int quantity = currentOrder.item[i].quantity; // 商品数量
            float price = currentOrder.item[i].price; // 商品价格
            total_amount += price * quantity;
        }

        sprintf(total_str, "总金额：%.2f 元", total_amount);
        PrintText(750, item_y + 10, total_str, HEI, 24, 1, black);
    
    }
}