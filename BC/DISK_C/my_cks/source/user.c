#include "all_func.h"

Shop shops={0};//存储信息的商店结构体 

void user(){
    
    mouse_off_arrow(&mouse);
	
	draw_user();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
			welcome();//首页
		}
        else if(mouse_press(40, 276, 160, 326)==1)
        {
            draw_choice();
            while(1){
                mouse_show_arrow(&mouse);

                if(mouse_press(200, 202, 430, 264)==1){
                    shops.type=1;
                    break;
                }else if(mouse_press(200, 266, 430, 334)==1){
                    shops.type=2;
                    break;
                }else if(mouse_press(200, 336, 430, 400)==1){
                    shops.type=3;
                    break;
                }
            }
            user_shop();//用户超市页面           
        }
        else if(mouse_press(40, 439, 160, 489)==1)
        {
            press1(2);//进入外卖页面
            user_takeout();//用户外卖页面 
            break;
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            press1(3);//进入快递页面
            user_deliver();//用户快递页面  
            break;
        }
        else if(mouse_press(430, 105, 650, 155)==1)
        {
            number_mode(users.number, 435, 110, 645, 150);//输入手机号
        }
        else if(mouse_press(710, 105, 830, 155)==1)
        {
            if(strlen(users.number)==11)
            {
                save_user(users);
                PrintCC(800,50,"保存成功",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,1024,100,snow);
            }
            else
            {
                PrintCC(800,50,"长度不合法",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,1024,100,snow);
            }
        }
        else if(mouse_press(440, 180, 560, 230)==1)
        {
            press1(4);//紫菘
            users.address=1;
            save_user(users);
        }
        else if(mouse_press(620, 180, 740, 230)==1)
        {
            press1(5);//沁苑
            users.address=2;
            save_user(users);
        }
        else if(mouse_press(800, 180, 920, 230)==1)
        {
            press1(6);//韵苑
            users.address=3;
            save_user(users);
        }
    }
}

void draw_user()
{
    bar1(0, 0, 1024, 768,0xFFFF);
    bar1(0, 0, 200, 768,0x0235);

    Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//填色
    Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);//填色
    Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);//填色
    Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);//填色

    Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//返回按钮
    Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);//超市按钮
    Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);//外卖按钮
    Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);//快递按钮
    Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,deepblue);//紫菘按钮
    Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,deepblue);//沁苑按钮
    Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,deepblue);//韵苑按钮

    Draw_Rounded_Rectangle(430, 105, 650, 155, 5, 1,deepblue);//手机号输入框 
    Draw_Rounded_Rectangle(710, 105, 830, 155, 25, 1,deepblue);//保存按钮

    PrintCC(75,128,"返回",HEI,24,1,deepblue);
    PrintCC(75,291,"超市",HEI,24,1,deepblue);
    PrintCC(75,454,"外卖",HEI,24,1,deepblue);
    PrintCC(75,617,"快递",HEI,24,1,deepblue);
    PrintCC(475,195,"紫菘",HEI,24,1,deepblue);
    PrintCC(655,195,"沁苑",HEI,24,1,deepblue);
    PrintCC(835,195,"韵苑",HEI,24,1,deepblue);
    PrintCC(745,120,"保存",HEI,24,1,deepblue);

    PrintCC(250,50,"当前账号类型为：用户",HEI,24,1,deepblue);
    PrintCC(250,120,"请输入手机号：",HEI,24,1,deepblue);
    PrintCC(250,190,"请选择住址：",HEI,24,1,deepblue);
    
    Readbmp64k(201, 257, "bmp\\map.bmp");
    
}

void draw_choice(){
    Fill_Rounded_Rectangle(200, 202, 430, 400, 30,snow);//填色
    Draw_Rounded_Rectangle(200, 202, 430, 400, 30, 2,deepblue);//最外围灰色圆角矩形

    Line_Thick(220, 265, 400, 265, 1,deepblue);
    Line_Thick(220, 335, 400, 335, 1,deepblue);
    
    PrintCC(240,225,"紫菘喻园超市",HEI,24,1,deepblue);
    PrintCC(240,290,"沁苑喻园超市",HEI,24,1,deepblue);
    PrintCC(240,355,"韵苑喻园超市",HEI,24,1,deepblue);

}

void press1(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    {
        case 1:{
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25,deepblue);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291,"超市",HEI,24,1,white);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454,"外卖",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617,"快递",HEI,24,1,deepblue);
            break;
        }
        case 2:{
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291,"超市",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25,deepblue);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454,"外卖",HEI,24,1,white);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617,"快递",HEI,24,1,deepblue);
            break;
        }
        case 3:{
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291,"超市",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454,"外卖",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25,deepblue);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617,"快递",HEI,24,1,white);
            break;
        }
        case 4:{
            Fill_Rounded_Rectangle(440, 180, 560, 230, 25, deepblue);
            Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,white);
            PrintCC(475,195,"紫菘",HEI,24,1,white);
            Fill_Rounded_Rectangle(620, 180, 740, 230, 25, white);
            Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,deepblue);
            PrintCC(655,195,"沁苑",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(800, 180, 920, 230, 25, white);
            Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,deepblue);
            PrintCC(835,195,"韵苑",HEI,24,1,deepblue);
            break;
        }
        case 5:{
            Fill_Rounded_Rectangle(440, 180, 560, 230, 25, white);
            Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,deepblue);
            PrintCC(475,195,"紫菘",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(620, 180, 740, 230, 25, deepblue);
            Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,white);
            PrintCC(655,195,"沁苑",HEI,24,1,white);
            Fill_Rounded_Rectangle(800, 180, 920, 230, 25, white);
            Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,deepblue);
            PrintCC(835,195,"韵苑",HEI,24,1,deepblue);
            break;  
        }
        case 6:{
            Fill_Rounded_Rectangle(440, 180, 560, 230, 25, white);
            Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,deepblue);
            PrintCC(475,195,"紫菘",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(620, 180, 740, 230, 25, white);
            Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,deepblue);
            PrintCC(655,195,"沁苑",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(800, 180, 920, 230, 25, deepblue);
            Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,white);
            PrintCC(835,195,"韵苑",HEI,24,1,white);
            break;
        }
    }
    mouse_on_arrow(mouse);
}

void number_mode(char *number,int bar_x1,int bar_y1,int bar_x2,int bar_y2)
{
	int length;
	char showtemp[2]= "\0";//存储输入字符,用于输入框展示
	int i=0,k,temp;  // i为字符个数,temp为从键盘上读取输入字符的ACSII码
	int border; //光标的横坐标	    
	int x1,y1;
	x1=bar_x1+4;
	y1=bar_y1+5;//光标相较于输入框的偏移量
	border=x1+4;//每个字符占8个像素,每输入一个字符光标右移8个像素
	
    if(number[0]=='\0') //如果账号为空，则显示输入框
        bar1(bar_x1, bar_y1, bar_x2, bar_y2,0xFFFF);
    else
    {            //光标定位至文本末尾
        length=strlen(number);
        i=length;
        border+=8*i;
        cursor(border,y1);
    }	

	while(1) 
    {
		cursor(border,y1);
		if(mouse_location(455,255,845,295)==1 && mouse_location(455,335,845,375)==1 && mouse_location(455,415,845,455)==1)
			mouse_show_cursor(&mouse);
		else
			mouse_show_arrow(&mouse);
		if(bioskey(1)) //如果有键盘输入
		{
			temp=bioskey(0)&0x00ff; //获取键盘输入
			if(temp!='\r'&&temp!='\n')	//检测输入不为回车键，则继续，否则输入结束
			{
				if(('0'<=temp&&temp<='9')&& i <11)//检测为数字或字母，则记录
				{
					hide_cursor(border,y1); //隐藏原光标
					
					number[i]=temp;//字符送入给定字符串，用于保存用户信息
								
					*showtemp=temp;  //temp转化为字符串
					PrintText(border,y1-2,showtemp,HEI,16,1,0); //显示新的字符串达到画面与实际输入的同步
					i++;	//字符个数自增
					
					number[i]='\0';//标记字符串结尾
							
					border+=8;	//光标横坐标右移8像素
					draw_cursor(border,y1);
				}
				else if(temp=='\b'&&i>0)  //检测是否为退格键，是则消除前一个字符
				{
					hide_cursor(border,y1);	//隐藏原光标
					border-=8;	//光标左移8像素
					i--;	//字符个数自减
				
					number[i]='\0';//将存储的字符用0覆盖
					
					bar1(border,y1,border+8, y1+16, 0xffff);	//清空原字符
					draw_cursor(border,y1);
				}
				else if(i>=11)
				{
					mouse_off_arrow(&mouse);
					mouse_show_arrow(&mouse);
					PrintCC(750,50,"长度超过限制",HEI,24,1,lightred);
					delay(500);
					bar1(750,50,900,75,snow);
				}
			}
			else
			{
				
				break;
			}
		}
		else if (mouse_press(bar_x1,bar_y1,bar_x2,bar_y2)==2)  //点击框外
		{
			hide_cursor(border,y1);//隐藏光标
			break;
		}	
			
	// hide_cursor(border,y1);	//隐藏光标
	}
}	