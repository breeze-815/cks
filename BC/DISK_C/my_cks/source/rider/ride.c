#include "all_func.h"

void rider(int user_pos){
    // OrderList OL = {0};
    // FoodList FL = {0};
    // DeliverList DL = {0};
    // ReadAllDeliver(&DL); // 读取快递列表
    // ReadAllOrder(&OL); // 读取订单列表
    // ReadAllFood(&FL); // 读取食品列表
    // mouse_off_arrow(&mouse);
	UserList UL = {0};
    USER currentUser;
    ReadAllUser(&UL); // 读取用户列表
    currentUser=UL.elem[user_pos];// 获取当前用户信息
    DestroyUList(&UL); // 释放用户列表空间
    mouse_off_arrow(&mouse);
	draw_rider();
	mouse_on_arrow(mouse);
    
	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(122, 50, 242, 100)==1)
        {
            return ;
            //welcome()首页
		}
        else if(mouse_press(342, 50, 462, 100)==1)
        {
            press3(1);//进入接单界面
            accept_order();//接单页面
            
            //return后从这开始
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // 清除接单界面残留
            draw_rider();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(562, 50, 682, 100)==1)
        {
            press3(2);//进入路线规划界面
            route(acp_orders,delivers.acp_count);//进入路线规划界面
            //return后从这开始
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // 清除接单界面残留
            draw_rider();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //我的
        {
            press3(3); //按钮高亮
            my(user_pos);
            //return后从这开始
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_rider();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(430, 500, 650, 550)==1)
        {
            number_input(currentUser.number, 435, 505, 645, 545); // 输入手机号
        }
        else if(mouse_press(710, 500, 830, 550)==1)
        {
            if(strlen(currentUser.number)==11)//判断手机号长度是否合法
            {
                save_user(currentUser);
                PrintCC(860,535,"保存成功",HEI,24,1,lightred);
                delay(500);
                bar1(860,535,1000,600,white);
            }
            else
            {
                PrintCC(860,535,"长度不合法",HEI,24,1,lightred);
                delay(500);
                bar1(860,535,1000,600,white);
            }
        }
        else if(mouse_press(440, 285, 560, 335)==1) //全职按钮
        {
            press3(4);
            currentUser.state=0;
            save_user(currentUser);

        }
        else if(mouse_press(620, 285, 740, 335)==1) //兼职按钮
        {
            press3(5);
            currentUser.state=1;
            save_user(currentUser);
        }
    }

}


void draw_rider(){
    bar1(0, 0, 1024, 768, white);
    bar1(0, 0, 1024, 150, deepblue);
    
    
    Fill_Rounded_Rectangle(122, 50, 242, 100, 25,white);//填色
    Fill_Rounded_Rectangle(342, 50, 462, 100, 25,white);//填色
    Fill_Rounded_Rectangle(562, 50, 682, 100, 25,white);//填色
    Fill_Rounded_Rectangle(782, 50, 902, 100, 25,white);//填色
    Fill_Rounded_Rectangle(440, 285, 560, 335, 25, white);//填色
    Fill_Rounded_Rectangle(620, 285, 740, 335, 25, white);//填色
            
    
    Draw_Rounded_Rectangle(122, 50, 242, 100, 25, 1,deepblue);//返回
    Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);//接单
    Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);//路线
    Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);//我的
    Draw_Rounded_Rectangle(440, 285, 560, 335, 25, 1,deepblue);//全职
    Draw_Rounded_Rectangle(620, 285, 740, 335, 25, 1,deepblue);//兼职
    Draw_Rounded_Rectangle(430, 500, 650, 550, 5, 1,deepblue);//手机号输入框 
    Draw_Rounded_Rectangle(710, 500, 830, 550, 25, 1,deepblue);//保存按钮

    PrintCC(122+35, 65, "返回", HEI, 24, 1, deepblue);
    PrintCC(342+35, 65, "接单", HEI, 24, 1, deepblue);
    PrintCC(562+35, 65, "路线", HEI, 24, 1, deepblue);
    PrintCC(782+35, 65, "我的", HEI, 24, 1, deepblue);
    PrintCC(220,510,"请输入手机号：",HEI,24,1,deepblue);
    PrintCC(200,300,"请选择骑手类型：",HEI,24,1,deepblue);
    PrintCC(10, 10, "当前账号类型为：骑手", HEI, 24, 1, white);
    PrintCC(440+35,300,"全职",HEI,24,1,deepblue);
    PrintCC(620+35,300,"兼职",HEI,24,1,deepblue);
    PrintCC(710+35, 515, "保存", HEI, 24, 1, deepblue);
}


void press3(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    { 
        case 1:
        {
            
            Fill_Rounded_Rectangle(342, 50, 462, 100, 25, deepblue);
            Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);
            PrintCC(342+35, 65, "接单", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(562, 50, 682, 100, 25, white);
            Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);
            PrintCC(562+35, 65, "路线", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(782, 50, 902, 100, 25, white);
            Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);
            PrintCC(782+35, 65, "我的", HEI, 24, 1, deepblue);
            break;
        }
        case 2:
        {
            Fill_Rounded_Rectangle(342, 50, 462, 100, 25, white);
            Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);
            PrintCC(342+35, 65, "接单", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(562, 50, 682, 100, 25, deepblue);
            Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);
            PrintCC(562+35, 65, "路线", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(782, 50, 902, 100, 25, white);
            Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);
            PrintCC(782+35, 65, "我的", HEI, 24, 1, deepblue);
            break;
        }
        case 3:
        {
            Fill_Rounded_Rectangle(342, 50, 462, 100, 25, white);
            Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);
            PrintCC(342+35, 65, "接单", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(562, 50, 682, 100, 25, white);
            Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);
            PrintCC(562+35, 65, "路线", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(782, 50, 902, 100, 25, deepblue);
            Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);
            PrintCC(782+35, 65,"我的", HEI ,24 ,1 ,white);
            break;
        }
        case 4:{
            Fill_Rounded_Rectangle(440, 285, 560, 335, 25, deepblue);
            Draw_Rounded_Rectangle(440, 285, 560, 335, 25, 1,white);
            PrintCC(440+35,300,"全职",HEI,24,1,white);
            Fill_Rounded_Rectangle(620, 285, 740, 335, 25, white);
            Draw_Rounded_Rectangle(620, 285, 740, 335, 25, 1,deepblue);
            PrintCC(620+35,300,"兼职",HEI,24,1,deepblue);
            
            break;
        }
        case 5:{
            Fill_Rounded_Rectangle(440, 285, 560, 335, 25, white);
            Draw_Rounded_Rectangle(440, 285, 560, 335, 25, 1,deepblue);
            PrintCC(440+35,300,"全职",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(620, 285, 740, 335, 25, deepblue);
            Draw_Rounded_Rectangle(620, 285, 740, 335, 25, 1,white);
            PrintCC(620+35,300,"兼职",HEI,24,1,white);
            break;  
        }
        default:
            break;
    }
    mouse_on_arrow(mouse);
}

