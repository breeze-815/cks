#include "all_func.h"
//屏幕宽度1024，高度768


int welcome() {
    int i;

    char name[12]="\0";
	char code[12]="\0";
    char judge1[12]="\0";//用于判断的密码
    int current=-5;//判断登陆结果,-5表示未登录,-2表示密码错误，-3表示用户不存在，>=0表示登录成功，返回用户位置

    UserList UL={0};
	ReadAllUser(&UL);

	mouse_off_arrow(&mouse);
	
	draw_basic();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(515, 490, 700, 540)==1)
        {
            DestroyUList(&UL);
			user_register();//进入注册页面
            //return后从这开始

            ReadAllUser(&UL);
            mouse_off_arrow(&mouse);
            bar1(0, 0, 1024, 768, white); // 清除注册界面残留
	        draw_basic();
	        mouse_on_arrow(mouse);
		}
        else if(mouse_press(950, 25, 1000, 75)==1)
        {
            CloseSVGA();//关闭SVGA画图界面
            exit(100);
        }
        else if(mouse_press(300, 330, 700, 380)==1)//点击账号框 
		{
			input_mode(name,code,judge1, 305, 335, 695, 375,1,1);
		}
        else if(mouse_press(300, 410, 700, 460)==1)//点击密码框 
		{
			input_mode(name,code,judge1, 305, 415, 695, 455,2,1);
		}
        else if(mouse_press(300,490, 485, 540)==1)//点击登录
        {
            current=Check_info(UL,name,code);
            
            if(current>=0)
			{
                int user_type = UL.elem[current].type; // 获取用户类型
                users.pos=current;//记录用户位置

                DestroyUList(&UL);//销毁线性表

                // 根据用户类型跳转到不同界面，并传入用户位置
                if (user_type == 1) 
                {
                    user(users.pos); // 用户页面
                } 
                else if (user_type == 2) 
                {
                    business(users.pos); // 商家页面
                } 
                else if (user_type == 3) 
                {
                    rider(users.pos); // 骑手页面
                }
                //return后从这开始
                ReadAllUser(&UL);
                mouse_off_arrow(&mouse);
                bar1(0, 0, 1024, 768, white); // 清除注册界面残留
                draw_basic();
                mouse_on_arrow(mouse);

                for (i = 0; i < sizeof(name); i++) name[i] = '\0';
                for (i = 0; i < sizeof(code); i++) code[i] = '\0';
                for (i = 0; i < sizeof(judge1); i++) judge1[i] = '\0';
			}
			if(current==-2)//密码输入错误 
			{
				PrintCC(430,560,"密码错误",HEI,24,1,0XF800);
                delay(500);
				bar1(430,560,580,590,snow);
			}
			if(current==-3)//用户不存在 
			{
				PrintCC(430,560,"用户不存在",HEI,24,1,0XF800);
                delay(500);
				bar1(430,560,580,590,snow);
			} 
		delay(15);
	    }
    }
}

void draw_basic()
{
    bar1(0, 0, 1024, 768,0xFFFF);

    //Readbmp64k(0, 0, "bmp\\hust.bmp");//读取背景图片
    //Readbmp64k(0, 0, "bmp\\windows.bmp");//

    //Fill_Rounded_Rectangle(200, 148, 824, 600, 30,snow);//填色
    Draw_Rounded_Rectangle(200, 148, 824, 600, 30, 2,0x6B4D);//最外围灰色圆角矩形
    
    Draw_Rounded_Rectangle(300, 330, 700, 380, 5, 1,0xB71C);//账号栏圆角矩形
    Draw_Rounded_Rectangle(300, 410, 700, 460, 5, 1,0xB71C);//密码栏圆角矩形
    Fill_Rounded_Rectangle(300,490, 485, 540, 5,0x435c);//登录按钮//长185，宽50
    Draw_Rounded_Rectangle(515, 490, 700, 540, 5,1,0x0235);//注册按钮//圆角方框，两字，x65，y+13
    Draw_Rounded_Rectangle(950, 25, 1000, 75, 5,1,0x0235);//关闭按钮

    PrintCC(305,225,"校园外卖快递平台",HEI,48,1,0);
    PrintCC(305,345,"账号",HEI,24,1,0XC618);
    PrintCC(305,425,"密码",HEI,24,1,0XC618);
    PrintCC(365,503,"登录",HEI,24,1,0xFFFF);
    PrintCC(580,503,"注册",HEI,24,1,0x0235);
    //PrintText(100,100,"chp123",HEI,16,1,0XC618);
    //Circlefill(50,50,3,0);
}
