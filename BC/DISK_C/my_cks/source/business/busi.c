#include "all_func.h"

void business(int user_pos){
    mouse_off_arrow(&mouse);
	
	draw_business();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1){
			welcome();//首页
		}else if(mouse_press(490, 100, 610, 150)==1){
            press2(1);//进入超市页面
            if(mouse_press(250, 200, 250+185, 200+50)==1){
                user_shop();//用户超市页面     
            }
        }else if(mouse_press(670, 100, 790, 150)==1){
            press2(2);//进入餐厅页面
        }else if(mouse_press(40, 602, 160, 652)==1){
            business_order();//商家订单页面
        }
    }
}

void draw_business()
{
    bar1(0, 0, 1024, 768,white);
    bar1(0, 0, 200, 768,deepblue);

    Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//返回填色
    Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//返回//圆角按钮，字的x+35，y+15
    Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);//确认填色
    Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);//确认

    Draw_Rounded_Rectangle(490, 100, 610, 150, 25, 1,deepblue);//超市按钮
    Draw_Rounded_Rectangle(670, 100, 790, 150, 25, 1,deepblue);//餐厅按钮


    PrintCC(75,128,"返回",HEI,24,1,deepblue);
    PrintCC(75,617,"确认",HEI,24,1,deepblue);

    PrintCC(250,50,"当前账号类型为：商家",HEI,24,1,deepblue);
    PrintCC(250,110,"请选择店铺种类：",HEI,24,1,deepblue);

    PrintCC(525,115,"超市",HEI,24,1,deepblue);
    PrintCC(705,115,"餐厅",HEI,24,1,deepblue);

    //Readbmp64k(200, 100, "bmp\\map.bmp");
    
}

void press2(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    {
        case 1:{//进入选择超市页面
            Fill_Rounded_Rectangle(490, 100, 610, 150, 25, deepblue);//超市
            Draw_Rounded_Rectangle(490, 100, 610, 150, 25, 1,deepblue);//超市
            PrintCC(525,115,"超市",HEI,24,1,white);
            Fill_Rounded_Rectangle(670, 100, 790, 150, 25, white);//餐厅
            Draw_Rounded_Rectangle(670, 100, 790, 150, 25, 1,deepblue);//餐厅
            PrintCC(705,115,"餐厅",HEI,24,1,deepblue);

            bar1(205, 195, 1024, 768, white);

            Draw_Rounded_Rectangle(250, 200, 250+185, 200+50, 5,1,0x0235);//注册按钮
            PrintCC(250+17,200+13,"韵苑喻园超市",HEI,24,1,0x0235);
            
            Draw_Rounded_Rectangle(500, 200, 500+185, 200+50, 5,1,0x0235);//注册按钮
            PrintCC(500+17,200+13,"沁苑喻园超市",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(750, 200, 750+185, 200+50, 5,1,0x0235);//注册按钮
            PrintCC(750+17,200+13,"紫菘喻园超市",HEI,24,1,0x0235);

            break;
        }
        case 2:{//进入选择餐厅页面
            Fill_Rounded_Rectangle(490, 100, 610, 150, 25, white);//超市
            Draw_Rounded_Rectangle(490, 100, 610, 150, 25, 1,deepblue);//超市
            PrintCC(525,115,"超市",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(670, 100, 790, 150, 25, deepblue);//餐厅
            Draw_Rounded_Rectangle(670, 100, 790, 150, 25, 1,deepblue);//餐厅
            PrintCC(705,115,"餐厅",HEI,24,1,white);

            bar1(205, 195, 1024, 768, white);

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

            Draw_Rounded_Rectangle(750, 500, 750+185, 500+50, 5,1,0x0235);//注册按钮
            PrintCC(750+17,500+13,"西二食堂",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(250, 600, 250+185, 600+50, 5,1,0x0235);//注册按钮
            PrintCC(250+17,600+13,"东园食堂",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(500, 600, 500+185, 600+50, 5,1,0x0235);//注册按钮
            PrintCC(500+17,600+13,"东教工食堂",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(750, 600, 750+185, 600+50, 5,1,0x0235);//注册按钮
            PrintCC(750+17,600+13,"西园食堂",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(250, 700, 250+185, 700+50, 5,1,0x0235);//注册按钮
            PrintCC(250+17,700+13,"南园食堂",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(500, 700, 500+185, 700+50, 5,1,0x0235);//注册按钮
            PrintCC(500+17,700+13,"中心食堂",HEI,24,1,0x0235);

            Draw_Rounded_Rectangle(750, 700, 750+185, 700+50, 5,1,0x0235);//注册按钮
            PrintCC(750+17,700+13,"韵苑食堂",HEI,24,1,0x0235);

            break;
        }
        case 3:{
            
            break;
        }
        case 4:{

        }
    }
    mouse_on_arrow(mouse);
}