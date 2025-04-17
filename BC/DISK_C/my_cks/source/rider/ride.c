#include "all_func.h"

void rider(int user_pos){
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
            route();//进入路线规划界面
            //dijkstra(&node[1], &node[29]);//测试dijkstra算法
            //return后从这开始
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // 清除接单界面残留
            draw_rider();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1)
        {
            press3(3);//进入账户界面
            account();//账户页面
            //return后从这开始
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // 清除接单界面残留
            draw_rider();
            mouse_on_arrow(mouse);
        }
    }
}

// void draw_rider()
// {
//     bar1(0, 0, 1024, 768,0xFFFF);
//     bar1(0, 0, 200, 768,0x0235);

//     Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//填色
//     Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);//填色
//     Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);//填色
//     Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);//填色

//     Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//返回
//     Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);//接单
//     Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);//路线 
//     Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);//账户

//     PrintCC(75,128,"返回",HEI,24,1,deepblue);
//     PrintCC(75,291,"接单",HEI,24,1,deepblue);
//     PrintCC(75,454,"路线",HEI,24,1,deepblue);
//     PrintCC(75,617,"账户",HEI,24,1,deepblue);

//     PrintCC(250,50,"当前账号类型为：骑手",HEI,24,1,deepblue);
    
// }

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
    PrintCC(782+35, 65, "账户", HEI, 24, 1, deepblue);
    
    PrintCC(10, 10, "当前账号类型为：骑手", HEI, 24, 1, white);

}


void press3(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    { 
        case 1:
        {
            // Fill_Rounded_Rectangle(40, 276, 160, 326, 25,deepblue);
            // Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            // PrintCC(75,291,"接单",HEI,24,1,white);
            // Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);
            // Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            // PrintCC(75,454,"路线",HEI,24,1,deepblue);
            // Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);
            // Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            // PrintCC(75,617,"账户",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(342, 50, 462, 100, 25, deepblue);
            Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,white);
            PrintCC(342+35, 65, "接单", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(562, 50, 682, 100, 25, white);
            Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);
            PrintCC(562+35, 65, "路线", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(782, 50, 902, 100, 25, white);
            Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);
            PrintCC(782+35, 65, "账户", HEI, 24, 1, deepblue);
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
            PrintCC(782+35, 65, "账户", HEI, 24, 1, deepblue);
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
            PrintCC(782+35, 65,"账户", HEI ,24 ,1 ,white);
            break;
        }
        }
    mouse_on_arrow(mouse);
}