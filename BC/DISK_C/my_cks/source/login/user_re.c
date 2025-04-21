#include "all_func.h"
//屏幕宽度1024，高度768
USER users={0};//存储信息的用户结构体 

void user_register(){
    
	char judge[12]="\0";//用于判断的密码 

    users.state=-1;//初始化为-1，代表未绑定

	mouse_off_arrow(&mouse);
	
	draw_register();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(300,490, 480, 540)==1){
            return;
            //welcome();//首页
		}
        else if(mouse_press(300, 250, 420, 300)==1)
        {
            press(1);//按下"用户"
            users.type=1;
        }
        else if(mouse_press(300, 330, 420, 380)==1)
        {
            press(2);//按下"商家"
            users.type=2;
        }
        else if(mouse_press(300, 410, 420, 460)==1)
        {
            press(3);//按下"骑手"
            users.type=3;
        }
        else if(mouse_press(450, 250, 700, 300)==1)//输入账号
        {
            input_mode(users.name,users.code,judge,455,255,695,295,1,0);
		}
        else if(mouse_press(450, 330, 700, 380)==1)//输入密码
        {   
			input_mode(users.name,users.code,judge,455,335,695,375,2,0);
		}
		else if(mouse_press(450, 410, 700, 460)==1)//重新输入密码
        {   
			input_mode(users.name,users.code,judge,455,415,695,455,3,0);
		}
        if(mouse_press(520, 490, 700, 540)==1)//点击确认键
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
                                PrintCC(430,550,"注册成功",HEI,24,1,lightred);
                                delay(500);
                                bar1(430,550,650,580,white);
                            }
                            else if(save_user(users)==-2)//用户名已存在
                            {
                                PrintCC(430,550,"用户名已被注册",HEI,24,1,lightred);
                                delay(500);
                                bar1(430,550,650,580,white);
                            }
			            }
			            else
			            {
                            PrintCC(430,550,"两次密码不相同",HEI,24,1,lightred);
                            delay(500);
                            bar1(430,550,650,580,white);
			            }  
				    }
				    else
				    {
					    PrintCC(430,550,"密码为空",HEI,24,1,lightred);
                        delay(500);
                        bar1(430,550,650,580,white);
				    }	
			    }
			    else
			    {
				    PrintCC(430,550,"用户名为空",HEI,24,1,lightred);
                    delay(500);
				    bar1(430,550,650,580,white);
			    }	
            }
            else
            {
                PrintCC(430,550,"未选择用户类型",HEI,24,1,lightred);
                delay(500);
                bar1(430,550,650,580,white);
            }
		}
    }
}
void draw_register()
{
    Readbmp64k(0, 0, "bmp\\city.bmp");

    Fill_Rounded_Rectangle(250, 200, 750, 580, 30,snow);//填色

    Fill_Rounded_Rectangle(450, 250, 700, 300, 5,lightgrew);//账号栏填色
    Fill_Rounded_Rectangle(450, 330, 700, 380, 5,lightgrew);//密码栏填色
    Fill_Rounded_Rectangle(450, 410, 700, 460, 5,lightgrew);//确认密码栏填色

    Draw_Rounded_Rectangle(300, 250, 420, 300, 25, 1,0x0235);//用户按钮
    Draw_Rounded_Rectangle(300, 330, 420, 380, 25, 1,0x0235);//商家按钮
    Draw_Rounded_Rectangle(300, 410, 420, 460, 25, 1,0x0235);//骑手按钮
    
    Fill_Rounded_Rectangle(300,490, 480, 540, 5,0x435c);//返回按钮
    Draw_Rounded_Rectangle(520, 490, 700, 540, 5,1,0x0235);//立即注册按钮
    
    PrintCC(455,265,"账号",HEI,24,1,0XC618);
    PrintCC(455,345,"密码",HEI,24,1,0XC618);
    PrintCC(455,425,"确认密码",HEI,24,1,0XC618);
    PrintCC(360,503,"返回",HEI,24,1,0xFFFF);
    PrintCC(560,503,"立即注册",HEI,24,1,0x0235);
    PrintCC(335,265,"用户",HEI,24,1,0x0235);
    PrintCC(335,345,"商家",HEI,24,1,0x0235);
    PrintCC(335,425,"骑手",HEI,24,1,0x0235);
}

void press(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    {
        case 1:{
            Fill_Rounded_Rectangle(300, 250, 420, 300, 25,0x0235);
            Draw_Rounded_Rectangle(300, 250, 420, 300, 25, 1,0x0235);
            PrintCC(335,265,"用户",HEI,24,1,0xFFFF);
            Fill_Rounded_Rectangle(300, 330, 420, 380, 25,0xFFFF);
            Draw_Rounded_Rectangle(300, 330, 420, 380, 25, 1,0x0235);
            PrintCC(335,345,"商家",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(300, 410, 420, 460, 25,0xFFFF);
            Draw_Rounded_Rectangle(300, 410, 420, 460, 25, 1,0x0235);
            PrintCC(335,425,"骑手",HEI,24,1,0x0235);
            break;
        }
        case 2:{
            Fill_Rounded_Rectangle(300, 250, 420, 300, 25,0xFFFF);
            Draw_Rounded_Rectangle(300, 250, 420, 300, 25, 1,0x0235);
            PrintCC(335,265,"用户",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(300, 330, 420, 380, 25,0x0235);
            Draw_Rounded_Rectangle(300, 330, 420, 380, 25, 1,0x0235);
            PrintCC(335,345,"商家",HEI,24,1,0xFFFF);
            Fill_Rounded_Rectangle(300, 410, 420, 460, 25,0xFFFF);
            Draw_Rounded_Rectangle(300, 410, 420, 460, 25, 1,0x0235);
            PrintCC(335,425,"骑手",HEI,24,1,0x0235);
            break;
        }
        case 3:{
            Fill_Rounded_Rectangle(300, 250, 420, 300, 25,0xFFFF);
            Draw_Rounded_Rectangle(300, 250, 420, 300, 25, 1,0x0235);
            PrintCC(335,265,"用户",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(300, 330, 420, 380, 25,0xFFFF);
            Draw_Rounded_Rectangle(300, 330, 420, 380, 25, 1,0x0235);
            PrintCC(335,345,"商家",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(300, 410, 420, 460, 25,0x0235);
            Draw_Rounded_Rectangle(300, 410, 420, 460, 25, 1,0x0235);
            PrintCC(335,425,"骑手",HEI,24,1,0xFFFF);
            break;
        }
    }
    mouse_on_arrow(mouse);
}
