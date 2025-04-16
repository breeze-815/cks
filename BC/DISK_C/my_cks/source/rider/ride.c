#include "all_func.h"

void rider(int user_pos){
    mouse_off_arrow(&mouse);
	
	draw_rider();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1){
			welcome();//首页
		}else if(mouse_press(40, 276, 160, 326)==1){
            press3(1);//进入接单界面
            //接单界面
        }else if(mouse_press(40, 439, 160, 489)==1){
            show_map(); 
            dijkstra(&node[1], &node[29]);//测试dijkstra算法
        }else if(mouse_press(40, 602, 160, 652)==1){
            press3(2);//进入账户界面
            //账户界面 
        }
        else if(mouse_press(950, 25, 1000, 75)==1)
        {
            CloseSVGA();//关闭SVGA画图界面
            exit(100);
        }
    }
}

void draw_rider()
{
    bar1(0, 0, 1024, 768,0xFFFF);
    bar1(0, 0, 200, 768,0x0235);

    Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//填色
    Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);//填色
    Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);//填色
    Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);//填色

    Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//返回
    Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);//超市
    Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);//外卖 
    Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);//快递

    PrintCC(75,128,"返回",HEI,24,1,deepblue);
    PrintCC(75,291,"接单",HEI,24,1,deepblue);
    PrintCC(75,454,"路线",HEI,24,1,deepblue);
    PrintCC(75,617,"账户",HEI,24,1,deepblue);

    PrintCC(250,50,"当前账号类型为：骑手",HEI,24,1,deepblue);
    
}

void press3(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    { 
        case 1:
        {
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25,deepblue);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291,"接单",HEI,24,1,white);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454,"路线",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617,"账户",HEI,24,1,deepblue);
            break;
        }
        case 2:
        {
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291,"接单",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454,"路线",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25,deepblue);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617,"账户",HEI,24,1,white);
            break;
        }
        }
    mouse_on_arrow(mouse);
}