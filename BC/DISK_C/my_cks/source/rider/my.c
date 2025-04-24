#include <all_func.h>

void my(int user_pos)
{
    UserList UL = {0};
    USER currentUser;
    ReadAllUser(&UL); // 读取用户列表
    currentUser=UL.elem[user_pos];// 获取当前用户信息
    DestroyUList(&UL); // 释放用户列表空间
    mouse_off_arrow(&mouse);
    draw_my(currentUser);
	mouse_on_arrow(mouse);
    
	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(122, 50, 242, 100)==1)
        {
            return ;
            //welcome()首页
		}
        else if(mouse_press(342, 50, 462, 100)==1) //接单
        {
            press3(1);//进入接单界面
            accept_order();//接单页面
            
            //return后从这开始
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // 清除接单界面残留
            draw_my(currentUser);
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(562, 50, 682, 100)==1)
        {
            press3(2);//进入路线规划界面
            route(acp_orders,delivers.acp_count);//进入路线规划界面
            //return后从这开始
            mouse_off_arrow(&mouse);
            bar1(0, 150, 1024, 768, white); // 清除接单界面残留
            draw_my(currentUser);
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(782, 50, 902, 100)==1) //我的
        {
            press3(3); //按钮高亮
            my_accept_order();
            //return后从这开始
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_my(currentUser);
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 276, 160, 326) == 1)
        {
            press4(1);
            my_account();
            //return后从这开始
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_my(currentUser);
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 439, 160, 489) == 1)
        {
            press4(1);
            my_accept_order();
            //return后从这开始
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_my(currentUser);
            mouse_on_arrow(mouse);
        }
        else if(mouse_press(40, 602, 160, 652) == 1)
        {
            my_history_order();
            //return后从这开始
            mouse_on_arrow(mouse);
            bar1(0, 150, 1024, 768, white); // 清除路线界面残留
            draw_my(currentUser);
            mouse_on_arrow(mouse);
        }
    }
}

void draw_my(USER currentUser)
{
    char show_name[20];
    char show_num[30];
    bar1(0, 150, 1024, 768,white);
    bar1(0,150,200,768,deepblue);
    sprintf(show_name,"账号：%s",currentUser.name);
    PrintText(350,200,show_name,HEI,32,1,black);
    sprintf(show_num,"手机号：%s",currentUser.number);
    PrintText(350,400,show_num,HEI,32,1,black);

    if(currentUser.state==0 && currentUser.type==3)
    PrintText(350,600,"骑手类型：全职骑手",HEI,32,1,black);
    else if(currentUser.state == 1 && currentUser.type == 3)
    PrintText(350,600,"骑手类型：兼职骑手",HEI,32,1,black);


    Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);//填色
    Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);//填色
    Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);//填色

    
    Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);//账户按钮
    Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);//当前按钮
    Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);//历史按钮

    PrintCC(75,291,"账户",HEI,24,1,deepblue);
    PrintCC(75,454,"当前",HEI,24,1,deepblue);
    PrintCC(75,617,"历史",HEI,24,1,deepblue);
    
}

void press4(int x)
{
    mouse_off_arrow(&mouse);
    switch (x)
    { 
        case 1:
        {
            
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25, deepblue);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291, "账户", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25, white);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454, "当前", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25, white);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617, "历史", HEI, 24, 1, deepblue);
            break;
        }
        case 2:
        {
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25, white);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75, 291, "账户", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25, deepblue);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75, 454, "当前", HEI, 24, 1, white);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25, white);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75, 617, "历史", HEI, 24, 1, deepblue);
            break;
        }
        case 3:
        {
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25, white);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291, "账户", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25, white);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454, "当前", HEI, 24, 1, deepblue);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25, deepblue);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75, 617, "历史", HEI ,24 ,1 ,white);
            break;
        }
        
        default:
            break;
    }
    mouse_on_arrow(mouse);
}