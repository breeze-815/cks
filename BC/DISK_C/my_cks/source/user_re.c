#include "all_func.h"
//屏幕宽度1024，高度768
struct USER users={0};//存储信息的用户结构体 

void user_register(int *page){
    
	char judge[10]="\0";//用于判断的密码 

	mouse_off(&mouse);
	
	draw_register();

	mouse_on(mouse);

	while(1){
		mouse_show(&mouse);

		if(mouse_press(450,490, 635, 540)==1){
			*page=0;//返回
			break;
		}
        else if(mouse_press(230, 250, 350, 300)==1)
        {
            press(1);//按下"用户"
            users.type=1;
        }
        else if(mouse_press(230, 330, 350, 380)==1)
        {
            press(2);//按下"商家"
            users.type=2;
        }
        else if(mouse_press(230, 410, 350, 460)==1)
        {
            press(3);//按下"骑手"
            users.type=3;
        }
        else if(mouse_press(450, 250, 850, 300)==1)//输入账号
        {
            
            Get_account(455,256,users.name,judge,455,255,845,295);
		}
        else if(mouse_press(450, 330, 850, 380)==1)//输入密码
        {   
			Get_code(455,336,users.code,judge,455,335,845,375);
		}
		else if(mouse_press(450, 410, 850, 460)==1)//重新输入密码
        {   
			Check_code(455,416,judge,455,415,845,455);
		}
        if(mouse_press(665, 490, 850, 540)==1)//点击确认键
        {   
            if(users.type!=0)
            {
			    if(strcmp(users.name,"\0")!=0)//用户名不为空 
                {
				    if(strcmp(users.code,"\0")!=0)//密码不为空 
                    {
					    if(!strcmp(users.code,judge))//两次密码相同 
                        {
				            if(save_user(users)==0)
                            {
                                PrintCC(570,575,"注册成功",HEI,24,1,0);
                                delay(1500);
				                bar1(570,575,800,600,snow);
                            }
                            else
                            {
                                PrintCC(570,575,"用户名已被注册",HEI,24,1,0XF800);
                                delay(1500);
				                bar1(570,575,800,600,snow);
                            }
			            }
			            else
			            {
                            PrintCC(570,575,"两次密码不相同",HEI,24,1,0XF800);
				            delay(1500);
				            bar1(570,575,800,600,snow);
			            }  
				    }
				    else
				    {
					    PrintCC(570,575,"密码为空",HEI,24,1,0XF800);
				        delay(1500);
				        bar1(570,575,800,600,snow);
				    }	
			    }
			    else
			    {
				    PrintCC(570,575,"用户名为空",HEI,24,1,0XF800);
				    delay(1500);
				    bar1(570,575,800,600,snow);
			    }	
            }
            else
            {
                PrintCC(570,575,"未选择用户类型",HEI,24,1,0XF800);
                delay(1500);
                bar1(570,575,800,600,snow);
            }
		}
    }
}
void draw_register()
{
    bar1(0, 0, 1024, 768,0xFFFF);

    Fill_Rounded_Rectangle(100, 108, 924, 640, 30,snow);//填色
    Draw_Rounded_Rectangle(100, 108, 924, 640, 30, 2,0x6B4D);//最外围灰色圆角矩形

    Draw_Rounded_Rectangle(450, 250, 850, 300, 5, 1,0xB71C);//账号栏圆角矩形
    Draw_Rounded_Rectangle(450, 330, 850, 380, 5, 1,0xB71C);//密码栏圆角矩形
    Draw_Rounded_Rectangle(450, 410, 850, 460, 5, 1,0xB71C);//确认密码栏圆角矩形

    Draw_Rounded_Rectangle(230, 250, 350, 300, 25, 1,0x0235);//用户
    Draw_Rounded_Rectangle(230, 330, 350, 380, 25, 1,0x0235);//商家
    Draw_Rounded_Rectangle(230, 410, 350, 460, 25, 1,0x0235);//骑手
    
    Fill_Rounded_Rectangle(450,490, 635, 540, 5,0x435c);//返回按钮
    Draw_Rounded_Rectangle(665, 490, 850, 540, 5,1,0x0235);//立即注册按钮
    
    PrintCC(455,265,"账号",HEI,24,1,0XC618);
    PrintCC(455,345,"密码",HEI,24,1,0XC618);
    PrintCC(455,425,"确认密码",HEI,24,1,0XC618);
    PrintCC(515,503,"返回",HEI,24,1,0xFFFF);
    PrintCC(710,503,"立即注册",HEI,24,1,0x0235);
    PrintCC(265,265,"用户",HEI,24,1,0x0235);
    PrintCC(265,345,"商家",HEI,24,1,0x0235);
    PrintCC(265,425,"骑手",HEI,24,1,0x0235);
}

void press(int x){
    mouse_off(&mouse);
    switch (x)
    {
        case 1:{
            Fill_Rounded_Rectangle(230, 250, 350, 300, 25,0x0235);
            Draw_Rounded_Rectangle(230, 250, 350, 300, 25, 1,0x0235);
            PrintCC(265,265,"用户",HEI,24,1,0xFFFF);
            Fill_Rounded_Rectangle(230, 330, 350, 380, 25,0xFFFF);
            Draw_Rounded_Rectangle(230, 330, 350, 380, 25, 1,0x0235);
            PrintCC(265,345,"商家",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(230, 410, 350, 460, 25,0xFFFF);
            Draw_Rounded_Rectangle(230, 410, 350, 460, 25, 1,0x0235);
            PrintCC(265,425,"骑手",HEI,24,1,0x0235);
            break;
        }
        case 2:{
            Fill_Rounded_Rectangle(230, 250, 350, 300, 25,0xFFFF);
            Draw_Rounded_Rectangle(230, 250, 350, 300, 25, 1,0x0235);
            PrintCC(265,265,"用户",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(230, 330, 350, 380, 25,0x0235);
            Draw_Rounded_Rectangle(230, 330, 350, 380, 25, 1,0x0235);
            PrintCC(265,345,"商家",HEI,24,1,0xFFFF);
            Fill_Rounded_Rectangle(230, 410, 350, 460, 25,0xFFFF);
            Draw_Rounded_Rectangle(230, 410, 350, 460, 25, 1,0x0235);
            PrintCC(265,425,"骑手",HEI,24,1,0x0235);
            break;
        }
        case 3:{
            Fill_Rounded_Rectangle(230, 250, 350, 300, 25,0xFFFF);
            Draw_Rounded_Rectangle(230, 250, 350, 300, 25, 1,0x0235);
            PrintCC(265,265,"用户",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(230, 330, 350, 380, 25,0xFFFF);
            Draw_Rounded_Rectangle(230, 330, 350, 380, 25, 1,0x0235);
            PrintCC(265,345,"商家",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(230, 410, 350, 460, 25,0x0235);
            Draw_Rounded_Rectangle(230, 410, 350, 460, 25, 1,0x0235);
            PrintCC(265,425,"骑手",HEI,24,1,0xFFFF);
            break;
        }
    }
    mouse_on(mouse);
}
