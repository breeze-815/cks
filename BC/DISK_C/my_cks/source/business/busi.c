#include "all_func.h"

void business(int user_pos){

    UserList UL = {0};
    USER *currentUser;
    int shop_type=0;//商店类型，1为超市，2为餐厅
    int code[12]={0};//绑定码

    ReadAllUser(&UL); // 读取用户列表

    currentUser=&UL.elem[user_pos];// 获取当前用户信息

    mouse_off_arrow(&mouse);
	
	draw_business();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            DestroyUList(&UL); // 释放用户列表内存
            return;
			//welcome();//首页
		}
        else if(mouse_press(490, 260, 610, 310)==1)
        {
            press_type(1);//选择为超市经营者
            shop_type=1;//超市
            
        }
        else if(mouse_press(670, 260, 790, 310)==1)
        {
            press_type(2);//选择为餐厅经营者
            shop_type=2;//餐厅
        }
        else if(mouse_press(40, 602, 160, 652)==1)//查看订单
        {
            
            business_order();//商家订单页面
            
            //return后从这开始
            mouse_off_arrow(&mouse);
            bar1(200, 0, 1024, 768, white); // 清除注册界面残留
            draw_business();
            mouse_on_arrow(mouse);

        }
        else if(mouse_press(430, 110, 650, 160)==1)//输入手机号
        {
            number_input(currentUser->number, 435, 115, 645, 155); // 输入手机号
        }
        else if(mouse_press(710, 110, 830, 160)==1)//保存手机号
        {
            if(strlen(currentUser->number)==11)
            {
                save_user(*currentUser);
                PrintCC(800,50,"保存成功",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,1024,100,white);
            }
            else
            {
                PrintCC(800,50,"长度不合法",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,1024,100,white);
            }
        }
        else if(mouse_press(430, 185, 650, 235)==1)//输入绑定码
        {
            number_input(code, 435, 190, 645, 230); // 输入绑定码
        }
        else if(mouse_press(710, 110, 830, 160)==1)//保存手机号
        {
            if(strlen(currentUser->number)==11)
            {
                save_user(*currentUser);
                PrintCC(800,50,"保存成功",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,1024,100,white);
            }
            else
            {
                PrintCC(800,50,"长度不合法",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,1024,100,white);
            }
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

    Draw_Rounded_Rectangle(490, 260, 610, 310, 25, 1,deepblue);//超市按钮
    Draw_Rounded_Rectangle(670, 260, 790, 310, 25, 1,deepblue);//餐厅按钮

    Draw_Rounded_Rectangle(430, 110, 650, 160, 5, 1,deepblue);//手机号输入框 
    Draw_Rounded_Rectangle(710, 110, 830, 160, 25, 1,deepblue);//保存手机号按钮
    Draw_Rounded_Rectangle(430, 185, 650, 235, 5, 1,deepblue);//绑定码输入框
    Draw_Rounded_Rectangle(710, 185, 830, 235, 25, 1,deepblue);//确认按钮
    //Draw_Rounded_Rectangle(430, 330, 650, 375, 5, 1,deepblue);//查看订单按钮

    PrintCC(75,128,"返回",HEI,24,1,deepblue);
    PrintCC(52,617,"查看订单",HEI,24,1,deepblue);

    PrintCC(250,50,"当前账号类型为：商家",HEI,24,1,deepblue);

    PrintCC(250,125,"请输入手机号：",HEI,24,1,deepblue);
    PrintCC(745,125,"保存",HEI,24,1,deepblue);
    PrintCC(250,200,"请输入绑定码：",HEI,24,1,deepblue);
    PrintCC(745,200,"确认",HEI,24,1,deepblue);

    PrintCC(250,275,"请选择店铺种类：",HEI,24,1,deepblue);
    PrintCC(525,275,"超市",HEI,24,1,deepblue);
    PrintCC(705,275,"餐厅",HEI,24,1,deepblue);

    //Readbmp64k(200, 100, "bmp\\map.bmp");
    
}

void press_type(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    {
        case 1:{//进入选择超市页面
            Fill_Rounded_Rectangle(490, 260, 610, 310, 25, deepblue);//超市
            Draw_Rounded_Rectangle(490, 260, 610, 310, 25, 1,deepblue);//超市
            PrintCC(525,275,"超市",HEI,24,1,white);
            Fill_Rounded_Rectangle(670, 260, 790, 310, 25, white);//餐厅
            Draw_Rounded_Rectangle(670, 260, 790, 310, 25, 1,deepblue);//餐厅
            PrintCC(705,275,"餐厅",HEI,24,1,deepblue);

            draw_market();

            break;
        }
        case 2:{//进入选择餐厅页面
            Fill_Rounded_Rectangle(490, 260, 610, 310, 25, white);//超市
            Draw_Rounded_Rectangle(490, 260, 610, 310, 25, 1,deepblue);//超市
            PrintCC(525,275,"超市",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(670, 260, 790, 310, 25, deepblue);//餐厅
            Draw_Rounded_Rectangle(670, 260, 790, 310, 25, 1,deepblue);//餐厅
            PrintCC(705,275,"餐厅",HEI,24,1,white);

            draw_canteen();

            break;
        }
        
    }
    mouse_on_arrow(mouse);
}

void draw_market(){
    bar1(205, 325, 1024, 768, white);

    Draw_Rounded_Rectangle(250, 330, 250+185, 330+50, 5,1,0x0235);
    PrintCC(250+17,330+13,"韵苑学生食堂",HEI,24,1,0x0235);
            
    Draw_Rounded_Rectangle(500, 330, 500+185, 330+50, 5,1,0x0235);
    PrintCC(500+17,330+13,"东园食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 330, 750+185, 330+50, 5,1,0x0235);
    PrintCC(750+17,330+13,"东教工食堂",HEI,24,1,0x0235);

}

void draw_canteen(){
    bar1(205, 325, 1024, 768, white);

    Draw_Rounded_Rectangle(250, 330, 250+185, 330+50, 5,1,0x0235);
    PrintCC(250+17,330+13,"韵苑学生食堂",HEI,24,1,0x0235);
            
    Draw_Rounded_Rectangle(500, 330, 500+185, 330+50, 5,1,0x0235);
    PrintCC(500+17,330+13,"东园食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 330, 750+185, 330+50, 5,1,0x0235);
    PrintCC(750+17,330+13,"东教工食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 390, 250+185, 390+50, 5,1,0x0235);
    PrintCC(250+17,390+13,"学生一食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 390, 500+185, 390+50, 5,1,0x0235);
    PrintCC(500+17,390+13,"学生二食堂",HEI,24,1,0x0235);  

    Draw_Rounded_Rectangle(750, 390, 750+185, 390+50, 5,1,0x0235);
    PrintCC(750+17,390+13,"紫荆园餐厅",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 450, 250+185, 450+50, 5,1,0x0235);
    PrintCC(250+17,450+13,"东一食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 450, 500+185, 450+50, 5,1,0x0235);
    PrintCC(500+17,450+13,"东三食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 450, 750+185, 450+50, 5,1,0x0235);
    PrintCC(750+17,450+13,"喻园餐厅",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 510, 250+185, 510+50, 5,1,0x0235);
    PrintCC(250+17,510+13,"百景园",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 510, 500+185, 510+50, 5,1,0x0235);
    PrintCC(500+17,510+13,"西一食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 510, 750+185, 510+50, 5,1,0x0235);
    PrintCC(750+17,510+13,"西二食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 570, 250+185, 570+50, 5,1,0x0235);
    PrintCC(250+17,570+13,"东园食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 570, 500+185, 570+50, 5,1,0x0235);
    PrintCC(500+17,570+13,"东教工食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 570, 750+185, 570+50, 5,1,0x0235);
    PrintCC(750+17,570+13,"西园食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 630, 250+185, 630+50, 5,1,0x0235);
    PrintCC(250+17,630+13,"南园食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 630, 500+185, 630+50, 5,1,0x0235);
    PrintCC(500+17,630+13,"中心食堂",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 630, 750+185, 630+50, 5,1,0x0235);
    PrintCC(750+17,630+13,"韵苑食堂",HEI,24,1,0x0235);
}