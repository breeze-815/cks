#include "all_func.h"

void de_order() {
    mouse_off_arrow(&mouse);
    draw_de_order();
    mouse_on_arrow(mouse);
    while (1) {
        mouse_show_arrow(&mouse);
        if(mouse_press(40, 113, 160, 163)==1)
        {
            return;
			//welcome();//首页
		}
        else if(mouse_press(40, 276, 160, 326)==1)
        {
            press_func(1);//进入超市页面
            user_shop();//用户超市页面 
            return;
        }
        else if(mouse_press(40, 439, 160, 489)==1)
        {
            press_func(2);//进入外卖页面
            user_takeout();//用户外卖页面 
            return;
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            press_func(3);//进入快递页面
            user_deliver();//用户快递页面 
            return;
        }else if(mouse_press(800, 700, 1000, 750)==1)//确认并支付
        {
            PrintCC(600, 715,"保存成功",HEI,24,1,lightred); // 支付成功提示
            delay(500);
            bar1(600, 715,780,750,white); // 清除支付成功提示
            return;
        }
    }
}

void draw_de_order() {
    DeliverList DL={0};
    Deliver current; // 当前订单
    char time_str[100]; // 打印下单时间
    char user_name[100]; // 打印用户名
    char user_phone[100]; // 打印用户手机号
    char order_number[100]; // 打印订单号
    char address[100]; // 打印用户地址
    char community[100]; // 社区字符串
    char building[100]; // 楼栋字符串
    char code[100]; // 取件码字符串
    char company_str[100];// 快递公司字符串
    char station_str[100];// 站点字符串

    bar1(200, 0, 1024, 768,white);

    ReadAllDeliver(&DL); // 读取所有订单

    current = DL.elem[DL.length-1]; // 当前订单

    DestroyDList(&DL); // 释放订单列表空间

    sprintf(order_number, "订单号：%d", current.id); // 订单号
    sprintf(time_str, "下单时间：%s",current.time );
    sprintf(user_name, "用户名：%s", current.name);
    sprintf(user_phone, "手机号：%s", current.number);
    sprintf(code, "取件码：%s", current.code);
    sprintf(company_str, "快递商：%s", companys[current.company-1].name);
    sprintf(station_str, "站点：%s", stations[current.station-1].name);

    if (current.station == 0)
            sprintf(address,"地址：未绑定地址");
        else
            sprintf(address, "地址：%s", node[current.index].name); // 用户地址
    
    PrintText(250, 50, order_number, HEI, 24, 1, black);//显示订单号
    PrintText(250, 100, time_str, HEI, 24, 1, black);//显示下单时间
    PrintText(250, 150, user_name, HEI, 24, 1, black);//显示用户名
    PrintText(250, 200, user_phone, HEI, 24, 1, black);//显示手机号
    PrintText(250, 250, address, HEI, 24, 1, black);//显示地址
    PrintText(250, 300, code, HEI, 24, 1, black);//显示取件码
    PrintText(250, 350, company_str, HEI, 24, 1, black);//显示快递公司
    PrintText(250, 400, station_str, HEI, 24, 1, black);//显示站点

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue); // 确认并支付
    PrintCC(830, 715, "确认并支付", HEI, 24, 1, deepblue);

}