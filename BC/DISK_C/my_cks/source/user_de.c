#include "all_func.h"

void user_deliver(int *page,int *shop_type){

    mouse_off(&mouse);
	
	draw_user_deliver();

	mouse_on(mouse);

	while(1){
		mouse_show(&mouse);

		if(mouse_press(40, 113, 160, 163)==1){
			*page=2;//返回首页
			break;
		}else if(mouse_press(40, 276, 160, 326)==1){
            draw_choice();
            while(1){
                mouse_show(&mouse);

                if(mouse_press(200, 202, 430, 264)==1){
                    *shop_type=1;
                    break;
                }else if(mouse_press(200, 266, 430, 334)==1){
                    *shop_type=2;
                    break;
                }else if(mouse_press(200, 336, 430, 400)==1){
                    *shop_type=3;
                    break;
                }
            }
            *page=5;
            break;
        }else if(mouse_press(40, 439, 160, 489)==1){
            press1(2);//进入外卖页面
            *page=6;
            break;
        }else if(mouse_press(40, 602, 160, 652)==1){
            press1(3);//进入快递页面
            *page=7;
            break;
        }else if(mouse_press(200, 0, 320, 50)==1){
            press_item(1);//生活用品
        }else if(mouse_press(320, 0, 440, 50)==1){
            press_item(2);//文具
        }else if(mouse_press(440, 0, 560, 50)==1){
            press_item(3);//零食
        }else if(mouse_press(560, 0, 680, 50)==1){
            press_item(4);//饮料
        }else if(mouse_press(680, 0, 800, 50)==1){
            press_item(5);//运动用品
        }else if(mouse_press(800, 0, 920, 50)==1){
            press_item(6);//水果
        }else if(mouse_press(920, 0, 1024, 50)==1){
            press_item(7);//文创
        }
    }
}

void draw_user_deliver(){
    bar1(200, 0, 1024, 768,white);

    PrintCC(250,50,"请输入取件码：",HEI,24,1,deepblue);
    PrintCC(250,120,"请选择驿站：",HEI,24,1,deepblue);

    Draw_Rounded_Rectangle(250, 200, 250+185, 200+50, 5,1,0x0235);//注册按钮
    PrintCC(250+17,200+13,"韵苑学生食堂",HEI,24,1,0x0235);
    
    Draw_Rounded_Rectangle(500, 200, 500+185, 200+50, 5,1,0x0235);//注册按钮
    PrintCC(500+17,200+13,"东园食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 200, 750+185, 200+50, 5,1,0x0235);//注册按钮
    PrintCC(750+17,200+13,"东教工食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 300, 250+185, 300+50, 5,1,0x0235);//注册按钮
    PrintCC(250+17,300+13,"学生一食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 300, 500+185, 300+50, 5,1,0x0235);//注册按钮
    PrintCC(500+17,300+13,"学生二食堂",HEI,24,1,0x0235);  

    Draw_Rounded_Rectangle(750, 300, 750+185, 300+50, 5,1,0x0235);//注册按钮
    PrintCC(750+17,300+13,"紫荆园餐厅",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 400, 250+185, 400+50, 5,1,0x0235);//注册按钮
    PrintCC(250+17,400+13,"东一食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 400, 500+185, 400+50, 5,1,0x0235);//注册按钮
    PrintCC(500+17,400+13,"东三食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 400, 750+185, 400+50, 5,1,0x0235);//注册按钮
    PrintCC(750+17,400+13,"喻园餐厅",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 500, 250+185, 500+50, 5,1,0x0235);//注册按钮
    PrintCC(250+17,500+13,"百景园",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 500, 500+185, 500+50, 5,1,0x0235);//注册按钮
    PrintCC(500+17,500+13,"西一食堂",HEI,24,1,0x0235);


}

void press_station(int x){
    switch (x)
    {
        case 1:{
            PrintCC(210,15,"生活用品",HEI,24,1,deepblue);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 2:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,deepblue);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 3:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,deepblue);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 4:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,deepblue);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }   
        case 5:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,deepblue);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 6:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,deepblue);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 7:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,deepblue);
            break;
        }
    }
}