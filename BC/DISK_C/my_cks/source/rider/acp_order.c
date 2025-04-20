#include <all_func.h>

void accept_order()
{
    int page = 0; // 当前页码

    OrderList OL = {0};

    ReadAllOrder(&OL); // 读取订单列表

    mouse_off_arrow(&mouse);
	
	draw_accept_order(page,&OL);

    
	//mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);
    
		if(mouse_press(122, 50, 242, 100)==1)
        {
            DestroyOList(&OL); // 释放订单列表内存
            return;
			//business(users.pos);
		}
        else if(mouse_press(342, 50, 462, 100)==1)
        {
            press3(1);
            //route();//进入路线规划界面
            //dijkstra(&node[1], &node[29]);//测试dijkstra算法
            //return后从这开始
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // 清除接单界面残留
            draw_rider();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(562, 50, 682, 100)==1)
        {
            press3(2);
        }
        else if(mouse_press(782, 50, 902, 100)==1)
        {
            press3(3);
        }
		// {
        //     if (page > 0) {
        //         page--;
        //         //draw_business_order(page,&OL);
        //     } else {
        //         // 提示：已是第一页
        //         PrintCC(550, 35, "已是第一页", HEI, 24, 1, lightred);
		// 		delay(500);
		// 		bar1(550, 35, 700, 60, white);
        //     }
        // }
		// else if (mouse_press(420, 700, 540, 750) == 1) 
		// {
		// 	if ((page + 1) * 5 < OL.length) {
		// 		page++;
        //         draw_business_order(page,&OL);
		// 	} else {
		// 		// 提示：已是最后一页
		// 		PrintCC(550, 35, "已是最后一页", HEI, 24, 1, lightred);
		// 		delay(500);
		// 		bar1(550, 35, 700, 60, white);
		// 	}
		// }
        // else if(mouse_press(200, 0, 1024, 680) == 1) {
        //     int order_index = (mouse.y - 25) / 120 + page * 5; // 根据点击位置计算订单索引

		// 	MouseGet(&mouse);

        //     if (order_index >= 0 && order_index < OL.length) 
        //     {
        //         business_detail(order_index); // 显示订单详情
        //         //return后从这开始
        //         mouse_off_arrow(&mouse);
        //         bar1(200, 0, 1024, 768, white); // 清除订单详情界面残留
        //         draw_business_order(page,&OL); // 重新绘制订单列表
        //         mouse_on_arrow(mouse);
        //     }
		// }
    }
}

void draw_accept_order(int page,OrderList *OL)
{
    char debug_buf[100]; // 调试信息缓冲区
    int i;
    int y_offset = 170; // 初始Y轴偏移

    int orders_per_page = 5; // 每页最多显示5个订单
    int start_index = page * orders_per_page; // 当前页的起始订单索引
    int end_index = start_index + orders_per_page; // 当前页的结束订单索引

    // int community; // 用户社区
    // int building; // 用户栋数
    // int pick_up_location; //取餐地点
    char total_price[10];// 总价字符串

    if (end_index > OL->length) {
        end_index = OL->length; // 防止越界
    }

    bar1(0, 150, 1024, 768, white);

    // Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//返回填色
    // Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//返回//圆角按钮，字的x+35，y+15
    // PrintCC(75,128,"返回",HEI,24,1,deepblue);
    // 显示调试信息
    
    for (i = start_index; i < end_index; i++) {
            Order order = OL->elem[i]; // 获取当前订单
            // DEBUG：打印到控制台
            
            sprintf(debug_buf,"DEBUG[%d]: community=%d, pick_up_loction=%d\n",
                i, order.community, order.pick_up_location);
            PrintText(35, y_offset+15, debug_buf, HEI, 24, 1, lightred); 

        

        // 绘制订单框
        Draw_Rounded_Rectangle(20, y_offset, 1000, y_offset + 100, 30, 1, 0x6B4D);

        // switch (expression)
        // {
        // case constant expression:
        //     /* code */
        //     break;
        
        // default:
        //     break;
        // }
        // switch (order.pick_up_loction)
        // {
        //     case 0:
        //         PrintText(35, y_offset + 15, "是零", HEI, 24, 1, 0x0000);
        //         break;
        //     case 1:
        //         PrintText(35, y_offset + 15, "韵苑学生食堂", HEI, 24, 1, 0x0000);
        //         break;
        //     case 2:
        //         PrintText(35, y_offset + 15, "东园学生食堂", HEI, 24, 1, 0x0000);
        //         break;
        //     case 3:
        //         PrintText(35, y_offset + 15, "学生一食堂", HEI, 24, 1, 0x0000);
        //         break;
        //     case 4:
        //         PrintText(35, y_offset + 15, "学生二食堂", HEI, 24, 1, 0x0000);
        //         break;
        //     case 5:
        //         PrintText(35, y_offset + 15, "东教工食堂", HEI, 24, 1, 0x0000);
        //         break;
        //     case 6:
        //         PrintText(35, y_offset + 15, "喻园食堂", HEI, 24, 1, 0x0000);
        //         break;
        //     case 7:
        //         PrintText(35, y_offset + 15, "集贤楼食堂", HEI, 24, 1, 0x0000);
        //         break;
        //     case 8:
        //         PrintText(35, y_offset + 15, "东一食堂", HEI, 24, 1, 0x0000);
        //         break;
        //     case 9:
        //         PrintText(35, y_offset + 15, "紫荆园餐厅", HEI, 24, 1, 0x0000);
        //         break;
        //     case 10:
        //         PrintText(35, y_offset + 15, "东三食堂", HEI, 24, 1, 0x0000);
        //         break;
        //     case 11:
        //         PrintText(35, y_offset + 15, "东四食堂", HEI, 24, 1, 0x0000);
        //         break;
        //     case 12:
        //         PrintText(35, y_offset + 15, "西一学生食堂", HEI, 24, 1, 0x0000);
        //         break;
        //     case 13:
        //         PrintText(35, y_offset + 15, "西二学生食堂", HEI, 24, 1, 0x0000);
        //         break;
        //     case 14:
        //         PrintText(35, y_offset + 15, "西三学生食堂", HEI, 24, 1, 0x0000);
        //         break;
        //     case 15:
        //         PrintText(35, y_offset + 15, "百景园餐厅", HEI, 24, 1, 0x0000);
        //         break;
        //     case 16:
        //         PrintText(35, y_offset + 15, "集锦园餐厅", HEI, 24, 1, 0x0000);
        //         break;
        //     case 17:
        //         PrintText(35, y_offset + 15, "百惠园餐厅", HEI, 24, 1, 0x0000);
        //         break;
        //     case 18:
        //         PrintText(35, y_offset + 15, "韵苑学生超市", HEI, 24, 1, 0x0000);
        //         break;
        //     case 19:
        //         PrintText(35, y_offset + 15, "喻园学生超市", HEI, 24, 1, 0x0000);
        //         break;
        //     case 20:
        //         PrintText(35, y_offset + 15, "西区学生超市", HEI, 24, 1, 0x0000);
        //         break;
        // }

        // switch (order.community)
        // {
        //     case 0:
        //         PrintText(500, y_offset + 15, "是零", HEI, 24, 1, 0x0000);
        //         break;
        //     case 1:
        //         PrintText(500, y_offset + 15, "东区学生宿舍", HEI, 24, 1, 0x0000);
        //         break;
        //     case 2:
        //         PrintText(500, y_offset + 15, "西区学生宿舍", HEI, 24, 1, 0x0000);
        //         break;
        //     case 3:
        //         PrintText(500, y_offset + 15, "南区学生宿舍", HEI, 24, 1, 0x0000);
        //         break;
        //     case 4:
        //         PrintText(500, y_offset + 15, "紫菘学生宿舍", HEI, 24, 1, 0x0000);
        //         break;
        //     case 5:
        //         PrintText(500, y_offset + 15, "韵苑学生宿舍", HEI, 24, 1, 0x0000);
        //         break;
        // }
        // // 显示订单简略信息
        // sprintf(order_id, "订单%d", i + 1);
        // PrintText(35, y_offset + 15, order_id, HEI, 24, 1, 0x0000);

        // sprintf(user_info, "下单人：%s", order.user_name);
        // PrintText(35, y_offset + 65, user_info, HEI, 24, 1, 0x0000);

        
        sprintf(total_price, "总价：%.2f", order.total_amount);
        PrintText(800, y_offset + 15, total_price, HEI, 24, 1, 0x0000);

        PrintText(665, y_offset + 65, order.order_time, HEI, 24, 1, 0x0000);

        y_offset += 120; // 每个订单框之间的间距
    }

    // 绘制翻页按钮
    Draw_Rounded_Rectangle(220, 700, 340, 750, 25, 1, deepblue); // 上一页
    Draw_Rounded_Rectangle(420, 700, 540, 750, 25, 1, deepblue); // 下一页
    PrintCC(245, 715, "上一页", HEI, 24, 1, deepblue);
    PrintCC(445, 715, "下一页", HEI, 24, 1, deepblue);   
}