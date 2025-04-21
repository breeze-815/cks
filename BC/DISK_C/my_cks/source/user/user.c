#include "all_func.h"

Shop shops={0};//存储信息的商店结构体 

void user(int user_pos){
    char test_buf[20];
    int cur_index = -1;
    int cur_community=0;
    int returned_index;
    UserList UL = {0};
    USER currentUser;

    ReadAllUser(&UL); // 读取用户列表

    currentUser=UL.elem[user_pos];// 获取当前用户信息

    DestroyUList(&UL); // 释放用户列表空间
    
    mouse_off_arrow(&mouse);
	
	draw_user(currentUser);

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            DestroyUList(&UL); // 释放用户列表空间
            return;
			//welcome();//首页
		}
        else if(mouse_press(40, 276, 160, 326)==1)
        {
            press1(1);//进入超市页面
            user_shop();//用户超市页面 
            
            //return后从这开始 
            mouse_off_arrow(&mouse);
            bar1(200, 0, 1024, 768, white); // 清除超市界面残留
	        draw_user(currentUser);
	        mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 439, 160, 489)==1)
        {
            press1(2);//进入外卖页面
            user_takeout();//用户外卖页面 

            //return后从这开始 
            mouse_off_arrow(&mouse);
            bar1(200, 0, 1024, 768, white); // 清除超市界面残留
	        draw_user(currentUser);
	        mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            press1(3);//进入快递页面
            user_deliver();//用户快递页面 
            
            //return后从这开始 
            mouse_off_arrow(&mouse);
            bar1(200, 0, 1024, 768, white); // 清除超市界面残留
	        draw_user(currentUser);
	        mouse_on_arrow(mouse);
        }
        else if(mouse_press(430, 105, 650, 155)==1)
        {
            number_input(currentUser.number, 435, 110, 645, 150); // 输入手机号
        }
        else if(mouse_press(710, 105, 830, 155)==1)
        {
            if(strlen(currentUser.number)==11)
            {
                save_user(currentUser);
                PrintCC(800,50,"保存成功",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,950,100,white);
            }
            else
            {
                PrintCC(800,50,"长度不合法",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,950,100,white);
            }
        }
        else if(mouse_press(440, 180, 560, 230)==1)
        {
            cur_index = -1;
            press1(4);//东区
            draw_button(1);
            cur_community=1; 
           
        }
        else if(mouse_press(620, 180, 740, 230)==1)
        {
            cur_index = -1;
            press1(5);//西区
            draw_button(2);
            cur_community=2;
        }
        else if(mouse_press(800, 180, 920, 230)==1)
        {
            cur_index = -1;
            press1(6);//南区
            draw_button(3);
            cur_community=3;
      
        }
        else if(mouse_press(530, 255, 650, 305)==1)
        {
            cur_index = -1;
            press1(7);//紫菘
            draw_button(4);
            cur_community=4;
        }
        else if(mouse_press(750, 255, 870, 305)==1)
        {
            cur_index = -1;
            press1(8);//韵苑
            draw_button(5);
            cur_community=5;
        }
        else if (mouse_press(200, 310, 1024, 768) == 1) { 

            MouseGet(&mouse);
            mouse_off_arrow(&mouse);
            returned_index = press_button(mouse.x, mouse.y, cur_index, cur_community);//获取按钮编号

            if(returned_index>=0)//如果返回值大于等于0,则说明选择了按钮
            {
                currentUser.community = button[returned_index].commmunity;//获取社区编号
                
                currentUser.index = button[returned_index].index;//获取楼号编号

                save_user(currentUser);//保存用户信息
            }

            cur_index = returned_index;//更新当前按钮编号

            mouse_on_arrow(mouse);

            delay(200);
        }
    }
}

void draw_user(USER currentUser)
{
    bar1(0, 0, 1024, 768,white);
    bar1(0, 0, 200, 768,deepblue);//左侧背景
    Readbmp64k(500, 0, "bmp\\hust1.bmp");//背景图

    Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//填色
    Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);//填色
    Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);//填色
    Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);//填色

    Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//返回按钮
    Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);//超市按钮
    Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);//外卖按钮
    Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);//快递按钮
    Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,deepblue);//东区按钮
    Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,deepblue);//西区按钮
    Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,deepblue);//南区按钮
    Draw_Rounded_Rectangle(530, 255, 650, 305, 25, 1,deepblue);//紫菘按钮
    Draw_Rounded_Rectangle(750, 255, 870, 305, 25, 1,deepblue);//韵苑按钮

    Draw_Rounded_Rectangle(430, 105, 650, 155, 5, 1,deepblue);//手机号输入框 
    Draw_Rounded_Rectangle(710, 105, 830, 155, 25, 1,deepblue);//保存按钮

    PrintCC(75,128,"返回",HEI,24,1,deepblue);
    PrintCC(75,291,"超市",HEI,24,1,deepblue);
    PrintCC(75,454,"外卖",HEI,24,1,deepblue);
    PrintCC(75,617,"快递",HEI,24,1,deepblue);
    PrintCC(475,195,"东区",HEI,24,1,deepblue);
    PrintCC(655,195,"西区",HEI,24,1,deepblue);
    PrintCC(835,195,"南区",HEI,24,1,deepblue);
    PrintCC(565,270,"紫菘",HEI,24,1,deepblue);
    PrintCC(785,270,"韵苑",HEI,24,1,deepblue);
    PrintCC(745,120,"保存",HEI,24,1,deepblue);

    PrintCC(250,50,"当前账号类型为：用户",HEI,24,1,deepblue);
    PrintCC(250,120,"请输入手机号：",HEI,24,1,deepblue);
    PrintCC(250,190,"请选择住址：",HEI,24,1,deepblue);
   
    //Readbmp64k(201, 257, "bmp\\map.bmp");
    
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
            PrintCC(475,195,"东区",HEI,24,1,white);
            Fill_Rounded_Rectangle(620, 180, 740, 230, 25, white);
            Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,deepblue);
            PrintCC(655,195,"西区",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(800, 180, 920, 230, 25, white);
            Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,deepblue);
            PrintCC(835,195,"南区",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(530, 255, 650, 305, 25, white);
            Draw_Rounded_Rectangle(530, 255, 650, 305, 25, 1,deepblue);
            PrintCC(565,270,"紫菘",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(750, 255, 870, 305, 25, white);
            Draw_Rounded_Rectangle(750, 255, 870, 305, 25, 1,deepblue);
            PrintCC(785,270,"韵苑",HEI,24,1,deepblue);
            break;
        }
        case 5:{
            Fill_Rounded_Rectangle(440, 180, 560, 230, 25, white);
            Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,deepblue);
            PrintCC(475,195,"东区",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(620, 180, 740, 230, 25, deepblue);
            Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,white);
            PrintCC(655,195,"西区",HEI,24,1,white);
            Fill_Rounded_Rectangle(800, 180, 920, 230, 25, white);
            Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,deepblue);
            PrintCC(835,195,"南区",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(530, 255, 650, 305, 25, white);
            Draw_Rounded_Rectangle(530, 255, 650, 305, 25, 1,deepblue);
            PrintCC(565,270,"紫菘",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(750, 255, 870, 305, 25, white);
            Draw_Rounded_Rectangle(750, 255, 870, 305, 25, 1,deepblue);
            PrintCC(785,270,"韵苑",HEI,24,1,deepblue);
            break;  
        }
        case 6:{
            Fill_Rounded_Rectangle(440, 180, 560, 230, 25, white);
            Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,deepblue);
            PrintCC(475,195,"东区",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(620, 180, 740, 230, 25, white);
            Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,deepblue);
            PrintCC(655,195,"西区",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(800, 180, 920, 230, 25, deepblue);
            Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,white);
            PrintCC(835,195,"南区",HEI,24,1,white);
            Fill_Rounded_Rectangle(530, 255, 650, 305, 25, white);
            Draw_Rounded_Rectangle(530, 255, 650, 305, 25, 1,deepblue);
            PrintCC(565,270,"紫菘",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(750, 255, 870, 305, 25, white);
            Draw_Rounded_Rectangle(750, 255, 870, 305, 25, 1,deepblue);
            PrintCC(785,270,"韵苑",HEI,24,1,deepblue);
            break;
        }
        case 7 :{
            Fill_Rounded_Rectangle(440, 180, 560, 230, 25, white);
            Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,deepblue);
            PrintCC(475,195,"东区",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(620, 180, 740, 230, 25, white);
            Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,deepblue);
            PrintCC(655,195,"西区",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(800, 180, 920, 230, 25, white);
            Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,deepblue);
            PrintCC(835,195,"南区",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(530, 255, 650, 305, 25, deepblue);
            Draw_Rounded_Rectangle(530, 255, 650, 305, 25, 1,white);
            PrintCC(565,270,"紫菘",HEI,24,1,white);
            Fill_Rounded_Rectangle(750, 255, 870, 305, 25, white);
            Draw_Rounded_Rectangle(750, 255, 870, 305, 25, 1,deepblue);
            PrintCC(785,270,"韵苑",HEI,24,1,deepblue);
            break;
        }
        case 8:{
            Fill_Rounded_Rectangle(440, 180, 560, 230, 25, white);
            Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,deepblue);
            PrintCC(475,195,"东区",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(620, 180, 740, 230, 25, white);
            Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,deepblue);
            PrintCC(655,195,"西区",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(800, 180, 920, 230 ,25 ,white);
            Draw_Rounded_Rectangle(800 ,180 ,920 ,230 ,25 ,1 ,deepblue);
            PrintCC(835 ,195 ,"南区" ,HEI ,24 ,1 ,deepblue); 
            Fill_Rounded_Rectangle(530 ,255 ,650 ,305 ,25 ,white);
            Draw_Rounded_Rectangle(530 ,255 ,650 ,305 ,25 ,1 ,deepblue);
            PrintCC(565 ,270 ,"紫菘" ,HEI ,24 ,1 ,deepblue); 
            Fill_Rounded_Rectangle(750 ,255 ,870 ,305 ,25 ,deepblue);
            Draw_Rounded_Rectangle(750 ,255 ,870 ,305 ,25 ,1 ,white);
            PrintCC(785 ,270 ,"韵苑" ,HEI ,24 ,1 ,white); 
            break;
        }
        case 9:{
            Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,deepblue);
            PrintCC(475,195,"东区",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(620, 180, 740, 230, 25, white);
            Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,deepblue);
            PrintCC(655,195,"西区",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(800, 180, 920, 230 ,25 ,white);
            Draw_Rounded_Rectangle(800 ,180 ,920 ,230 ,25 ,1 ,deepblue);
            PrintCC(835 ,195 ,"南区" ,HEI ,24 ,1 ,deepblue); 
            Fill_Rounded_Rectangle(530 ,255 ,650 ,305 ,25 ,white);
            Draw_Rounded_Rectangle(530 ,255 ,650 ,305 ,25 ,1 ,deepblue);
            PrintCC(565 ,270 ,"紫菘" ,HEI ,24 ,1 ,deepblue); 
            Fill_Rounded_Rectangle(750 ,255 ,870 ,305 ,25 ,deepblue);
            Draw_Rounded_Rectangle(750 ,255 ,870 ,305 ,25 ,1 ,white);
            PrintCC(785 ,270 ,"韵苑" ,HEI ,24 ,1 ,white); 
            break;
        }
        default:
            break;
    }
    mouse_on_arrow(mouse);
}

void number_input(char *number,int bar_x1,int bar_y1,int bar_x2,int bar_y2)
{
	int length;
    char number_temp[12]={'\0'};//重新进入该页面时输入框清零
	char showtemp[2]= "\0";//存储输入字符,用于输入框展示
	int i=0,k,temp;  // i为字符个数,temp为从键盘上读取输入字符的ACSII码
	int border; //光标的横坐标	    
	int x1,y1;
	x1=bar_x1+4;
	y1=bar_y1+5;//光标相较于输入框的偏移量
	border=x1+4;//每个字符占8个像素,每输入一个字符光标右移8个像素
	
    if(number_temp[0]=='\0') //如果账号为空，则显示输入框
        bar1(bar_x1, bar_y1, bar_x2, bar_y2,0xFFFF);
    else
    {            //光标定位至文本末尾
        length=strlen(number_temp);
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
				if(('0'<=temp&&temp<='9')&& i <11)//检测为数字或字母，则记录
				{
					hide_cursor(border,y1); //隐藏原光标
					
					number_temp[i]=temp;//字符送入给定字符串，用于保存用户信息
					number[i]=temp;
								
					*showtemp=temp;  //temp转化为字符串
					PrintText(border,y1+2,showtemp,HEI,24,1,0); //显示新的字符串达到画面与实际输入的同步
					i++;	//字符个数自增
					
					number_temp[i]='\0';//标记字符串结尾
                    number[i]='\0';
							
					border+=12;	//光标横坐标右移12像素
					draw_cursor(border,y1);
				}
				else if(temp=='\b'&&i>0)  //检测是否为退格键，是则消除前一个字符
				{
					hide_cursor(border,y1);	//隐藏原光标
					border-=12;	//光标左移12像素
					i--;	//字符个数自减
				
					number_temp[i]='\0';//将存储的字符用0覆盖
                    number[i]='\0';
					
					bar1(border,y1,border+10, y1+24, 0xffff);	//清空原字符
					draw_cursor(border,y1);
				}
				else if(i>=11)
				{
					mouse_off_arrow(&mouse);
					mouse_show_arrow(&mouse);
					PrintCC(750,50,"长度超过限制",HEI,24,1,lightred);
					delay(500);
					bar1(750,50,900,75,white);
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