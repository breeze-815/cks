#include "all_func.h"

void rider(int user_pos){
    // OrderList OL = {0};
    // FoodList FL = {0};
    // DeliverList DL = {0};
    // ReadAllDeliver(&DL); // 读取快递列表
    // ReadAllOrder(&OL); // 读取订单列表
    // ReadAllFood(&FL); // 读取食品列表
    // mouse_off_arrow(&mouse);
	
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
            my_accept_order();
            //return后从这开始
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_rider();
            mouse_on_arrow(mouse);
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

    Draw_Rounded_Rectangle(122, 50, 242, 100, 25, 1,deepblue);//返回
    Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);//接单
    Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);//路线
    Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);//账户

    PrintCC(122+35, 65, "返回", HEI, 24, 1, deepblue);
    PrintCC(342+35, 65, "接单", HEI, 24, 1, deepblue);
    PrintCC(562+35, 65, "路线", HEI, 24, 1, deepblue);
    PrintCC(782+35, 65, "我的", HEI, 24, 1, deepblue);
    
    PrintCC(10, 10, "当前账号类型为：骑手", HEI, 24, 1, white);

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
        }
    mouse_on_arrow(mouse);
}