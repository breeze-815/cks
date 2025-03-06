#include "all_func.h"

void business(int *page){
    mouse_off(&mouse);
	
	draw_business();

	mouse_on(mouse);

	while(1){
		mouse_show(&mouse);

		if(mouse_press(40, 113, 160, 163)==1){
			*page=0;//返回首页
			break;
		}else if(mouse_press(40, 276, 160, 326)==1){
            press1(1);//进入超市页面
            *page=5;
            break;
        }else if(mouse_press(40, 439, 160, 489)==1){
            press1(2);//进入外卖页面
            *page=6;
            break;
        }else if(mouse_press(40, 602, 160, 652)==1){
            press1(3);//进入快递页面
        }
    }
}

void draw_business()
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
    PrintCC(75,291,"超市",HEI,24,1,deepblue);
    PrintCC(75,454,"外卖",HEI,24,1,deepblue);
    PrintCC(75,617,"快递",HEI,24,1,deepblue);

    PrintCC(250,50,"当前账号类型为：商家",HEI,24,1,deepblue);

    Readbmp64k(200, 100, "bmp\\map.bmp");
    
}

void press2(int x){
    mouse_off(&mouse);
    switch (x)
    {
        case 1:{
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25,deepblue);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291,"超市",HEI,24,1,white);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454,"外卖",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617,"快递",HEI,24,1,deepblue);
            break;
        }
        case 2:{
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291,"超市",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25,deepblue);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454,"外卖",HEI,24,1,white);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617,"快递",HEI,24,1,deepblue);
            break;
        }
        case 3:{
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291,"超市",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454,"外卖",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25,deepblue);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617,"快递",HEI,24,1,white);
            break;
        }
    }
    mouse_on(mouse);
}