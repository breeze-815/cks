#include "all_func.h"

void business_order(){
    mouse_off_arrow(&mouse);
	
	draw_business_order();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1){
			business();//商家页面
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

void draw_business_order(){
    bar1(200, 0, 1024, 768,white);

    Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//返回填色
    Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//返回//圆角按钮，字的x+35，y+15
    Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);//确认填色
    Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);//确认

    Draw_Rounded_Rectangle(490, 100, 610, 150, 25, 1,deepblue);//超市
    Draw_Rounded_Rectangle(670, 100, 790, 150, 25, 1,deepblue);//餐厅


    PrintCC(75,128,"返回",HEI,24,1,deepblue);
    PrintCC(75,617,"确认",HEI,24,1,deepblue);

    PrintCC(250,50,"当前账号类型为：商家",HEI,24,1,deepblue);
    PrintCC(250,110,"请选择店铺种类：",HEI,24,1,deepblue);

    PrintCC(525,115,"超市",HEI,24,1,deepblue);
    PrintCC(705,115,"餐厅",HEI,24,1,deepblue);
}