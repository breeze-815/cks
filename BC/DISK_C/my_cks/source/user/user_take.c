#include "all_func.h"

Canteen canteen[17]={
    {1,"韵苑学生食堂"},
    {2,"东园食堂"},
    {3,"学一食堂"},
    {4,"学二食堂"},
    {5,"东教工食堂"},
    {6,"喻园食堂"},
    {7,"集贤楼食堂"},
    {8,"东一食堂"},
    {9,"紫荆园餐厅"},
    {10,"东三食堂"},
    {11,"东四食堂"},
    {12,"西一食堂"},
    {13,"西二食堂"},
    {14,"西三食堂"},
    {15,"百景园餐厅"},
    {16,"集锦园餐厅"},
    {17,"百惠园餐厅"}
};
void user_takeout(){
    int index=0;
    int mx=0;
    int my=0;

    mouse_off_arrow(&mouse);
	
	draw_user_takeout();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            return;
			//welcome();//首页
		}
        else if(mouse_press(40, 276, 160, 326)==1)
        {
            press1(1);//进入超市页面
            user_shop();//用户超市页面 
            return;
        }
        else if(mouse_press(40, 439, 160, 489)==1)
        {
            press1(2);//进入外卖页面
            user_takeout();//用户外卖页面 
            return;
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            press1(3);//进入快递页面
            user_deliver();//用户快递页面 
            return;
        }else if(mouse_press(200, 0, 1024, 768)==1)//选择食堂
        {
            MouseGet(&mouse);
            mx=mouse.x;
            my=mouse.y;
            index=press_canteen(mx,my);//获取食堂编号
            user_food(index);//进入菜品页面

            //return后从这开始
            mouse_off_arrow(&mouse);
            bar1(200, 0, 1024, 768, white); // 清除注册界面残留
            draw_user_takeout();
            mouse_on_arrow(mouse);

        }
        
    }
}
void draw_user_takeout(){
    int i,j;
    int cnt=0;
    bar1(200, 0, 1024, 768,white);

    PrintCC(250,50,"请选择食堂",HEI,24,1,deepblue);

    for(i=0;i<6;i++){
        for(j=0;j<3;j++){
        Draw_Rounded_Rectangle(250+250*j, 120+80*i, 250+250*j+185, 120+80*i+50, 5,1,0x0235);
        PrintCC(250+250*j+17,120+80*i+13,canteen[cnt].name,HEI,24,1,0x0235);
        cnt++;
        }
    }

    // Draw_Rounded_Rectangle(250, 120, 250+185, 120+50, 5,1,0x0235);
    // PrintCC(250+17,120+13,"韵苑学生食堂",HEI,24,1,0x0235);
            
    // Draw_Rounded_Rectangle(500, 120, 500+185, 120+50, 5,1,0x0235);
    // PrintCC(500+17,120+13,"东园食堂",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(750, 120, 750+185, 120+50, 5,1,0x0235);
    // PrintCC(750+17,120+13,"东教工食堂",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(250, 200, 250+185, 200+50, 5,1,0x0235);
    // PrintCC(250+17,200+13,"学生一食堂",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(500, 200, 500+185, 200+50, 5,1,0x0235);
    // PrintCC(500+17,200+13,"学生二食堂",HEI,24,1,0x0235);  

    // Draw_Rounded_Rectangle(750, 200, 750+185, 200+50, 5,1,0x0235);
    // PrintCC(750+17,200+13,"紫荆园餐厅",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(250, 280, 250+185, 280+50, 5,1,0x0235);
    // PrintCC(250+17,280+13,"东一食堂",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(500, 280, 500+185, 280+50, 5,1,0x0235);
    // PrintCC(500+17,280+13,"东三食堂",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(750, 280, 750+185, 280+50, 5,1,0x0235);
    // PrintCC(750+17,280+13,"喻园餐厅",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(250, 360, 250+185, 360+50, 5,1,0x0235);
    // PrintCC(250+17,360+13,"百景园",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(500, 360, 500+185, 360+50, 5,1,0x0235);
    // PrintCC(500+17,360+13,"西一食堂",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(750, 360, 750+185, 360+50, 5,1,0x0235);
    // PrintCC(750+17,360+13,"西二食堂",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(250, 440, 250+185, 440+50, 5,1,0x0235);
    // PrintCC(250+17,440+13,"东园食堂",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(500, 440, 500+185, 440+50, 5,1,0x0235);
    // PrintCC(500+17,440+13,"东教工食堂",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(750, 440, 750+185, 440+50, 5,1,0x0235);
    // PrintCC(750+17,440+13,"西园食堂",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(250, 520, 250+185, 520+50, 5,1,0x0235);
    // PrintCC(250+17,520+13,"南园食堂",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(500, 520, 500+185, 520+50, 5,1,0x0235);
    // PrintCC(500+17,520+13,"中心食堂",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(750, 520, 750+185, 520+50, 5,1,0x0235);
    // PrintCC(750+17,520+13,"韵苑食堂",HEI,24,1,0x0235);
}

int press_canteen(int mx, int my){
    //if(mx < 250 || mx > 935 || my < 120 || my > 570) return; // 边界检查

    int row = (my - 120) / 80;
    int col = (mx - 250) / 250;

    // 每个按钮的精确区域
    int btn_x = 250 + col * 250;
    int btn_y = 120 + row * 80;

    if(mx >= btn_x && mx <= btn_x + 185 && my >= btn_y && my <= btn_y + 50){
        int index = row * 3 + col + 1;// 计算索引
    }
}

