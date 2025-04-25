#include "all_func.h"

Num_of_Orders num_of_orders;

void rider(int user_pos)
{
    //获取当前用户信息
	UserList UL = {0};
    USER currentUser;
    ReadAllUser(&UL); // 读取用户列表
    currentUser=UL.elem[user_pos];// 获取当前用户信息
    DestroyUList(&UL); // 释放用户列表空间
    mouse_off_arrow(&mouse);
	draw_rider();//画骑手初始化界面
	mouse_on_arrow(mouse);
    if (currentUser.state == -1) //未初始化
    {
        rider_Init(&currentUser); //初始化成功后将状态标志位置1
        save_user(currentUser);
    }
    else 
    {
        draw_welcome_rider(currentUser);
    }
	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(122, 50, 242, 100)==1) //返回
        {
            return ;
            //welcome()首页
		}
        else if(mouse_press(342, 50, 462, 100)==1) //接单
        {
            press3(1);//按钮高亮
            mouse_off_arrow(&mouse);
            accept_order(user_pos);//进入接单页面
            //return后从这开始
            mouse_off_arrow(&mouse); //隐藏鼠标，防止留下残痕
            bar1(0, 150, 1024, 768, white); // 清除接单界面残留
            draw_rider(); //重画界面
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(562, 50, 682, 100)==1) //路线
        {
            press3(2);//按钮高亮
            mouse_off_arrow(&mouse);
            route(cur_orders,num_of_orders.cur_count,user_pos);//进入路线界面
            //return后从这开始
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); 
            draw_rider();
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //我的
        {
            press3(3); //按钮高亮
            bar1(0,150,200,768,deepblue);
            my_information(user_pos);//进入我的信息界面
            //return后从这开始
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); 
            draw_rider();
            mouse_on_arrow(mouse);
        }
    }
}


void draw_rider()
{
    bar1(0, 0, 1024, 768, white);
    bar1(0, 0, 1024, 150, deepblue);//上侧按钮栏底色

    PrintCC(10, 10, "当前账号类型为：骑手", HEI, 24, 1, white);
    //返回按钮
    Fill_Rounded_Rectangle(122, 50, 242, 100, 25,white);//填色
    Draw_Rounded_Rectangle(122, 50, 242, 100, 25, 1,deepblue);//轮廓
    PrintCC(122+35, 65, "返回", HEI, 24, 1, deepblue);//打字
    //接单按钮
    Fill_Rounded_Rectangle(342, 50, 462, 100, 25,white);
    Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);
    PrintCC(342+35, 65, "接单", HEI, 24, 1, deepblue);
    //路线按钮
    Fill_Rounded_Rectangle(562, 50, 682, 100, 25,white);
    Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);
    PrintCC(562+35, 65, "路线", HEI, 24, 1, deepblue);
    //我的按钮
    Fill_Rounded_Rectangle(782, 50, 902, 100, 25,white);
    Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);
    PrintCC(782+35, 65, "我的", HEI, 24, 1, deepblue);
}

//点击按钮反色功能
void press3(int x)
{
    mouse_off_arrow(&mouse);
    switch (x)
    { 
        case 1: //点击接单
        {
            Fill_Rounded_Rectangle(342, 50, 462, 100, 25, deepblue);
            Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,white);
            PrintCC(342+35, 65, "接单", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(562, 50, 682, 100, 25, white);
            Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);
            PrintCC(562+35, 65, "路线", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(782, 50, 902, 100, 25, white);
            Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);
            PrintCC(782+35, 65, "我的", HEI, 24, 1, deepblue);
            break;
        }
        case 2: //点击路线
        {
            Fill_Rounded_Rectangle(342, 50, 462, 100, 25, white);
            Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);
            PrintCC(342+35, 65, "接单", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(562, 50, 682, 100, 25, deepblue);
            Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,white);
            PrintCC(562+35, 65, "路线", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(782, 50, 902, 100, 25, white);
            Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,deepblue);
            PrintCC(782+35, 65, "我的", HEI, 24, 1, deepblue);
            break;
        }
        case 3: //点击我的
        {
            //PrintCC(100,1, "进入三三", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(342, 50, 462, 100, 25, white);
            Draw_Rounded_Rectangle(342, 50, 462, 100, 25, 1,deepblue);
            PrintCC(342+35, 65, "接单", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(562, 50, 682, 100, 25, white);
            Draw_Rounded_Rectangle(562, 50, 682, 100, 25, 1,deepblue);
            PrintCC(562+35, 65, "路线", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(782, 50, 902, 100, 25, deepblue);
            Draw_Rounded_Rectangle(782, 50, 902, 100, 25, 1,white);
            PrintCC(782+35, 65,"我的", HEI ,24 ,1 ,white);
            break;
        }
        case 4: //点击全职
        {
            Fill_Rounded_Rectangle(440, 285, 560, 335, 25, deepblue);
            Draw_Rounded_Rectangle(440, 285, 560, 335, 25, 1,white);
            PrintCC(440+35,300,"全职",HEI,24,1,white);
            Fill_Rounded_Rectangle(620, 285, 740, 335, 25, white);
            Draw_Rounded_Rectangle(620, 285, 740, 335, 25, 1,deepblue);
            PrintCC(620+35,300,"兼职",HEI,24,1,deepblue);
            
            break;
        }
        case 5: //点击兼职
        {
            Fill_Rounded_Rectangle(440, 285, 560, 335, 25, white);
            Draw_Rounded_Rectangle(440, 285, 560, 335, 25, 1,deepblue);
            PrintCC(440+35,300,"全职",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(620, 285, 740, 335, 25, deepblue);
            Draw_Rounded_Rectangle(620, 285, 740, 335, 25, 1,white);
            PrintCC(620+35,300,"兼职",HEI,24,1,white);
            break;  
        }
        default:
            break;
    }
    mouse_on_arrow(mouse);
}

//骑手初始化函数，初始化成功返回1
void rider_Init(USER *currentUser)
{
    mouse_off_arrow(&mouse);
	draw_rider_Init();//画骑手初始化界面
	mouse_on_arrow(mouse);
    while (1)
    {
        mouse_show_arrow(&mouse);
        if(mouse_press(430, 500, 650, 550)==1) //初始化时输入个人信息
        {
            number_input(currentUser->number, 435, 505, 645, 545); // 输入手机号
        }
        
        else if(mouse_press(440, 285, 560, 335)==1) //全职按钮
        {
            press3(4);
            currentUser->ocp=1;
            save_user(*currentUser);

        }
        else if(mouse_press(620, 285, 740, 335)==1) //兼职按钮
        {
            press3(5);
            currentUser->ocp=2;
            save_user(*currentUser);
        }
        else if (mouse_press(710, 500, 830, 550) == 1) 
        {   
            // “确定”按钮，检查合法性
            if (strlen(currentUser->number) == 11 && currentUser->number != 0) 
            {
                currentUser->state = 1;         // 标记初始化完成
                save_user(*currentUser);  // 保存完整信息
                PrintCC(860,535,"保存成功",HEI,24,1,lightred);
                delay(500);
                bar1(860,535,1000,600,white);
                break;
            } else 
            {
                PrintCC(860,535,"长度不合法",HEI,24,1,lightred);
                delay(500);
                bar1(860,535,1000,600,white);
            }
        }
    }
}

//画骑手初始化界面
void draw_rider_Init()
{
    Draw_Rounded_Rectangle(430, 500, 650, 550, 5, 1,deepblue);//手机号输入框 
    PrintCC(220,510,"请输入手机号：",HEI,24,1,deepblue);
    
    Draw_Rounded_Rectangle(710, 500, 830, 550, 25, 1,deepblue);//保存按钮
    PrintCC(710+35, 515, "保存", HEI, 24, 1, deepblue);

    PrintCC(200,300,"请选择骑手类型：",HEI,24,1,deepblue);
    //全职按钮
    Fill_Rounded_Rectangle(440, 285, 560, 335, 25, white);//填色
    Draw_Rounded_Rectangle(440, 285, 560, 335, 25, 1,deepblue);//轮廓
    PrintCC(440+35,300,"全职",HEI,24,1,deepblue);//打字
    //兼职按钮
    Fill_Rounded_Rectangle(620, 285, 740, 335, 25, white); 
    Draw_Rounded_Rectangle(620, 285, 740, 335, 25, 1,deepblue);
    PrintCC(620+35,300,"兼职",HEI,24,1,deepblue);
}

void draw_welcome_rider(USER currentUser)
{
    char show_name[20];
    sprintf(show_name,"用户：%s",currentUser.name);
    PrintText(350,400,show_name,HEI,32,1,black);
    if(currentUser.ocp == 1)
    PrintText(150,400,"全职骑手",HEI,32,1,black);
    else
    PrintText(150,400,"兼职骑手",HEI,32,1,black);
    
    PrintText(350,600,"欢迎回来",HEI,32,1,black);
}