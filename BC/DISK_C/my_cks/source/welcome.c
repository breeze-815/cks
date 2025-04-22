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

	//mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(515, 490, 650, 540)==1)
        {
            DestroyUList(&UL);
			user_register();//进入注册页面
            //return后从这开始

            ReadAllUser(&UL);
            mouse_off_arrow(&mouse);
            Readbmp64k(0, 0, "bmp\\city.bmp");//清除页面残留
	        draw_basic();
	        mouse_on_arrow(mouse);
		}
        else if(mouse_press(950, 25, 1000, 75)==1)
        {
            CloseSVGA();//关闭SVGA画图界面
            exit(100);
        }
        else if(mouse_press(350, 330, 650, 380)==1)//点击账号框 
		{
			input_mode(name,code,judge1, 355, 335, 645, 375,1,1);
		}
        else if(mouse_press(350, 410, 650, 460)==1)//点击密码框 
		{
			input_mode(name,code,judge1, 355, 415, 645, 455,2,1);
		}
        else if(mouse_press(350, 490, 485, 540)==1)//点击登录
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
                draw_basic();
                mouse_on_arrow(mouse);

                for (i = 0; i < sizeof(name); i++) name[i] = '\0';
                for (i = 0; i < sizeof(code); i++) code[i] = '\0';
                for (i = 0; i < sizeof(judge1); i++) judge1[i] = '\0';
			}
			if(current==-2)//密码输入错误 
			{
				PrintCC(430,550,"密码错误",HEI,24,1,lightred);
                delay(500);
				bar1(430,550,580,580,white);
			}
			if(current==-3)//用户不存在 
			{
				PrintCC(430,550,"用户不存在",HEI,24,1,lightred);
                delay(500);
				bar1(430,550,580,580,white);
			} 
		delay(15);
	    }
    }
}

void draw_basic()
{
    Readbmp64k(0, 0, "bmp\\city.bmp");//

    Fill_Rounded_Rectangle(310, 200, 690, 580, 25,white);//填色
    
    Fill_Rounded_Rectangle(350, 330, 650, 380, 5,lightgrew);//账号栏填色
    Fill_Rounded_Rectangle(350, 410, 650, 460, 5,lightgrew);//密码栏填色

    Fill_Rounded_Rectangle(350, 490, 485, 540, 5,0x435c);//登录按钮//长185，宽50
    Draw_Rounded_Rectangle(515, 490, 650, 540, 5,1,0x0235);//注册按钮//圆角方框，两字，x65，y+13
    

    PrintCC(355,245,"校园外卖快递平台",HEI,32,1,0);
    PrintCC(355,285,"基于华中科技大学校园制作",HEI,16,1,0XC618);
    PrintCC(355,345,"账号",HEI,24,1,deepgrew);
    PrintCC(355,425,"密码",HEI,24,1,deepgrew);
    PrintCC(390,503,"登录",HEI,24,1,0xFFFF);
    PrintCC(555,503,"注册",HEI,24,1,0x0235);
    PrintCC(750,50,"关于我们",HEI,16,1,white);
    PrintCC(900,50,"关于产品",HEI,16,1,white);

}
