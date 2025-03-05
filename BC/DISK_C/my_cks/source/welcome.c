#include "all_func.h"
//屏幕宽度1024，高度768


int welcome(int *page){

    char name[10]="\0";
	char code[10]="\0";
    char judge1[10]="\0";//用于判断的密码
    int i=-5;

    UserList UL={0};
	InitUList(&UL);
	ReadAllUser(&UL);
	mouse_off(&mouse);
	
	draw_basic();

	mouse_on(mouse);

	while(1){
		mouse_show(&mouse);

		if(mouse_press(515, 490, 700, 540)==1)
        {
			*page=1;//进入注册界面
			break;
		}
        else if(mouse_press(300, 330, 700, 380)==1)//点击账号框 
		{
			Get_account(305, 336,name,judge1, 305, 335, 695, 375);
		}
        else if(mouse_press(300, 410, 700, 460)==1)//点击密码框 
		{
			Get_code(305, 416,code,judge1, 305, 415, 695, 455);
		}
        else if(mouse_press(300,490, 485, 540)==1)//点击登录
        {
            i=Check_info(UL,name,code);
            if(i>=0)
			{
				//*unum=i;
				DestroyUList(&UL);
				*page=2;      //进入主界面
                break;
			}
			if(i==-2)//密码输入错误 
			{
				PrintCC(570,575,"密码错误",HEI,24,1,0XF800);
			    delay(1500);
				bar1(570,550,690,574,0xffff);
			}
			if(i==-3)//用户不存在 
			{
				PrintCC(570,575,"用户不存在",HEI,24,1,0XF800);
			    delay(1500);
				bar1(570,550,570+144,574,0xffff);
			} 
		delay(15);
	    }
    }
}

void draw_basic()
{
    bar1(0, 0, 1024, 768,0xFFFF);

    Fill_Rounded_Rectangle(200, 148, 824, 600, 30,0xFFDF);//填色
    Draw_Rounded_Rectangle(200, 148, 824, 600, 30, 2,0x6B4D);//最外围灰色圆角矩形
    
    Draw_Rounded_Rectangle(300, 330, 700, 380, 5, 1,0xB71C);//账号栏圆角矩形
    Draw_Rounded_Rectangle(300, 410, 700, 460, 5, 1,0xB71C);//密码栏圆角矩形
    Fill_Rounded_Rectangle(300,490, 485, 540, 5,0x435c);//登录按钮
    Draw_Rounded_Rectangle(515, 490, 700, 540, 5,1,0x0235);//注册按钮
    PrintCC(305,225,"校园外卖快递平台",HEI,48,1,0);
    PrintCC(305,345,"账号",HEI,24,1,0XC618);
    PrintCC(305,425,"密码",HEI,24,1,0XC618);
    PrintCC(365,503,"登录",HEI,24,1,0xFFFF);
    PrintCC(580,503,"注册",HEI,24,1,0x0235);
    PrintText(100,100,"chp123",HEI,16,1,0XC618);
    Circlefill(50,50,3,0);
}
