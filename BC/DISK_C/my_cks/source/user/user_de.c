#include "all_func.h"

Deliver deliver={0};//存储信息的快递结构体

void user_deliver(){

    mouse_off_arrow(&mouse);
	
	draw_user_deliver();

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
        }
        else if(mouse_press(440, 35, 660, 85)==1)
        {
            deliver_input(deliver.code, 445, 40, 655, 80); // 输入取件码
        }
    }
}

void draw_user_deliver(){
    bar1(200, 0, 1024, 768,white);

    Draw_Rounded_Rectangle(440, 35, 660, 85, 5, 1,deepblue);//取件码输入框 
    Draw_Rounded_Rectangle(730, 35, 850, 85, 25, 1,deepblue);//保存按钮

    PrintCC(250,50,"请输入取件码：",HEI,24,1,deepblue);
    PrintCC(250,120,"请选择服务提供商：",HEI,24,1,deepblue);
    PrintCC(765,50,"保存",HEI,24,1,deepblue);

    Draw_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,1,0x0235);//注册按钮
    PrintCC(250+40,175+13,"顺丰快递",HEI,24,1,0x0235);
    
    Draw_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,1,0x0235);//注册按钮
    PrintCC(500+40,175+13,"韵达快递",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,1,0x0235);//注册按钮
    PrintCC(750+40,175+13,"申通快递",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,1,0x0235);//注册按钮
    PrintCC(250+40,250+13,"中通快递",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,1,0x0235);//注册按钮
    PrintCC(500+40,250+13,"京东快递",HEI,24,1,0x0235);  

    Draw_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,1,0x0235);//注册按钮
    PrintCC(750+40,250+13,"邮政快递",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,1,0x0235);//注册按钮
    PrintCC(250+40,325+13,"圆通快递",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,1,0x0235);//注册按钮
    PrintCC(500+40,325+13,"其他快递",HEI,24,1,0x0235);
}

void press_station(int x){
    switch (x)
    {
        case 1:{
            PrintCC(210,15,"生活用品",HEI,24,1,deepblue);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 2:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,deepblue);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 3:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,deepblue);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 4:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,deepblue);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }   
        case 5:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,deepblue);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 6:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,deepblue);
            PrintCC(955,15,"文创",HEI,24,1,grey);
            break;
        }
        case 7:{
            PrintCC(210,15,"生活用品",HEI,24,1,grey);
            PrintCC(355,15,"文具",HEI,24,1,grey);
            PrintCC(475,15,"零食",HEI,24,1,grey);
            PrintCC(595,15,"饮料",HEI,24,1,grey);
            PrintCC(690,15,"运动用品",HEI,24,1,grey);
            PrintCC(835,15,"水果",HEI,24,1,grey);
            PrintCC(955,15,"文创",HEI,24,1,deepblue);
            break;
        }
    }
}

void deliver_input(char *deliver_code,int bar_x1,int bar_y1,int bar_x2,int bar_y2)
{
	int length;
	char showtemp[2]= "\0";//存储输入字符,用于输入框展示
	int i=0,k,temp;  // i为字符个数,temp为从键盘上读取输入字符的ACSII码
	int border; //光标的横坐标	    
	int x1,y1;
	x1=bar_x1+4;
	y1=bar_y1+5;//光标相较于输入框的偏移量
	border=x1+4;//每个字符占8个像素,每输入一个字符光标右移8个像素
	
    if(deliver_code[0]=='\0') //如果取件码为空，则显示输入框
        bar1(bar_x1, bar_y1, bar_x2, bar_y2,0xFFFF);
    else
    {            //光标定位至文本末尾
        length=strlen(deliver_code);
        i=length;
        border+=12*i;
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
				if((('0'<=temp&&temp<='9')||('a'<=temp&&temp<='z')||('A'<=temp && temp<='Z')||(temp=='-'))&& i <10)//检测为数字或字母或-，则记录
				{
					hide_cursor(border,y1); //隐藏原光标
					
					deliver_code[i]=temp;//字符送入给定字符串，用于保存取件码信息
								
					*showtemp=temp;  //temp转化为字符串
					PrintText(border,y1+2,showtemp,HEI,24,1,0); //显示新的字符串达到画面与实际输入的同步
					i++;	//字符个数自增
					
					deliver_code[i]='\0';//标记字符串结尾
							
					border+=12;	//光标横坐标右移12像素
					draw_cursor(border,y1);
				}
				else if(temp=='\b'&&i>0)  //检测是否为退格键，是则消除前一个字符
				{
					hide_cursor(border,y1);	//隐藏原光标
					border-=12;	//光标左移12像素
					i--;	//字符个数自减
				
					deliver_code[i]='\0';//将存储的字符用0覆盖
					
					bar1(border,y1,border+10, y1+24, 0xffff);	//清空原字符
					draw_cursor(border,y1);
				}
				else if(i>=10)
				{
					mouse_off_arrow(&mouse);
					mouse_show_arrow(&mouse);
					PrintCC(750,100,"长度超过限制",HEI,24,1,lightred);
					delay(500);
					bar1(750,100,900,125,white);
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
	}
}	