#include "all_func.h"

void business(int user_pos){

    UserList UL = {0};
    USER currentUser;
    int shop_type=0;//商店类型，1为超市，2为餐厅
    int code[12]={0};//绑定码
    int state=0;//状态，0为未绑定，1为已输入绑定码，2为已绑定
    int page=0;//0为未选择，1为超市，2为餐厅
    int last_canteen_index = -1; // 记录上一个被按下的按钮
    int temp_index = -1; // 临时变量,选择食堂/超市时不保存
    int index=-1;//食堂/超市编号
    

    ReadAllUser(&UL); // 读取用户列表

    currentUser=UL.elem[user_pos];// 获取当前用户信息

    DestroyUList(&UL); // 释放用户列表空间

    mouse_off_arrow(&mouse);
	
	draw_business();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            DestroyUList(&UL); // 释放用户列表空间
            return;
			//welcome();//首页
		}
        else if(mouse_press(430, 110, 650, 160)==1)//输入手机号
        {
            number_input(currentUser.number, 435, 115, 645, 155); // 输入手机号
        }
        else if(mouse_press(710, 110, 830, 160)==1)//保存手机号
        {
            if(strlen(currentUser.number)==11)
            {
                save_user(currentUser);
                PrintCC(700,50,"保存成功",HEI,24,1,lightred);
                delay(500);
                bar1(600,50,1024,100,white);
            }
            else
            {
                PrintCC(700,50,"长度不合法",HEI,24,1,lightred);
                delay(500);
                bar1(600,50,1024,100,white);
            }
        }
        
        

        //输入绑定码后但未选择店铺
        if(state==1)
        {
            if(mouse_press(490, 260, 610, 310)==1)
            {
                press_type(1);//选择为超市经营者
                shop_type=1;//超市
                page=1;
                
            }
            else if(mouse_press(670, 260, 790, 310)==1)
            {
                press_type(2);//选择为餐厅经营者
                shop_type=2;//餐厅
                page=2;
            }
            else if(mouse_press(205, 325, 1024, 680)==1)//选择具体食堂/超市
            {
                MouseGet(&mouse);
                mouse_off_arrow(&mouse);
                if(page==1)//超市
                {
                    temp_index=0;//选择超市
                    choose_market(mouse.x, mouse.y);
                }

                if(page==2)//餐厅
                {
                    temp_index=choose_canteen(mouse.x, mouse.y, &last_canteen_index);
                }
                mouse_on_arrow(mouse);
            }
            else if(mouse_press(800, 700, 1000, 750)==1)//确认绑定
            {
                index=temp_index;//保存
                bar1(600,50,1024,100,white);
                PrintCC(700,50,"绑定成功",HEI,24,1,lightred);
                delay(500);
                bar1(600,50,1024,100,white);
                state=2;//已绑定
                currentUser.state=index;//已绑定
                save_user(currentUser);

            }else if(mouse_press(40, 602, 160, 652)==1)//查看订单
            {
                PrintCC(750,50,"请先选择绑定的店铺",HEI,24,1,lightred);
                delay(500);
                bar1(600,50,1024,100,white);
            }
            
        }

        //未绑定
        if(state==0&&currentUser.state==-1)
        {
            if(mouse_press(490, 260, 610, 310)==1||
               mouse_press(670, 260, 790, 310)==1||
               mouse_press(40, 602, 160, 652)==1)
            {
                PrintCC(800,50,"请先进行绑定操作",HEI,24,1,lightred);
                delay(500);
                bar1(600,50,1024,100,white);
                
            }
            else if(mouse_press(430, 185, 650, 235)==1)//输入绑定码
            {
                number_input(code, 435, 190, 645, 230); // 输入绑定码
            }
            else if(mouse_press(710, 185, 830, 235)==1)//确认绑定
            {
                if(strcmp(code,"111")==0)
                {
                    PrintCC(800,50,"验证成功",HEI,24,1,lightred);
                    delay(500);
                    bar1(600,50,1024,100,white);
                    state=1;//已绑定
                }
                else
                {
                    PrintCC(800,50,"验证失败",HEI,24,1,lightred);
                    delay(500);
                    bar1(600,50,1024,100,white);
                }
            }
        }

        //已绑定
        if(state==2||currentUser.state!=-1)
        {
        	if(mouse_press(40, 602, 160, 652)==1)//查看订单
            {
                if(currentUser.state!=-1) index=currentUser.state;//如果已经存在文件里直接读取
                DestroyUList(&UL); // 释放用户列表空间
                business_order(index);//商家订单页面
                
                //return后从这开始
                mouse_off_arrow(&mouse);
                bar1(200, 0, 1024, 768, white); // 清除注册界面残留
                draw_business();
                mouse_on_arrow(mouse);
    
            }
            if(mouse_press(205, 185, 1024,  680)==1)
            {
                bar1(600,50,1024,100,white);
                PrintCC(650,50,"已绑定，无法更改",HEI,24,1,lightred);
            }
        }
    }
}

void draw_business()
{
    bar1(0, 0, 1024, 768,white);
    bar1(0, 0, 200, 768,deepblue);

    Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//返回填色
    Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//返回//圆角按钮，字的x+35，y+15
    Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);//确认填色
    Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);//确认

    Draw_Rounded_Rectangle(490, 260, 610, 310, 25, 1,deepblue);//超市按钮
    Draw_Rounded_Rectangle(670, 260, 790, 310, 25, 1,deepblue);//餐厅按钮

    Draw_Rounded_Rectangle(430, 110, 650, 160, 5, 1,deepblue);//手机号输入框 
    Draw_Rounded_Rectangle(710, 110, 830, 160, 25, 1,deepblue);//保存手机号按钮
    Draw_Rounded_Rectangle(430, 185, 650, 235, 5, 1,deepblue);//绑定码输入框
    Draw_Rounded_Rectangle(710, 185, 830, 235, 25, 1,deepblue);//确认按钮
    //Draw_Rounded_Rectangle(430, 330, 650, 375, 5, 1,deepblue);//查看订单按钮

    PrintCC(75,128,"返回",HEI,24,1,deepblue);
    PrintCC(52,617,"查看订单",HEI,24,1,deepblue);

    PrintCC(250,50,"当前账号类型为：商家",HEI,24,1,deepblue);

    PrintCC(250,125,"请输入手机号：",HEI,24,1,deepblue);
    PrintCC(745,125,"保存",HEI,24,1,deepblue);
    PrintCC(250,200,"请输入绑定码：",HEI,24,1,deepblue);
    PrintCC(745,200,"确认",HEI,24,1,deepblue);

    PrintCC(250,275,"请选择店铺种类：",HEI,24,1,deepblue);
    PrintCC(525,275,"超市",HEI,24,1,deepblue);
    PrintCC(705,275,"餐厅",HEI,24,1,deepblue);
  
}

void press_type(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    {
        case 1:{//进入选择超市页面
            Fill_Rounded_Rectangle(490, 260, 610, 310, 25, deepblue);//超市
            Draw_Rounded_Rectangle(490, 260, 610, 310, 25, 1,deepblue);//超市
            PrintCC(525,275,"超市",HEI,24,1,white);
            Fill_Rounded_Rectangle(670, 260, 790, 310, 25, white);//餐厅
            Draw_Rounded_Rectangle(670, 260, 790, 310, 25, 1,deepblue);//餐厅
            PrintCC(705,275,"餐厅",HEI,24,1,deepblue);

            draw_market();

            break;
        }
        case 2:{//进入选择餐厅页面
            Fill_Rounded_Rectangle(490, 260, 610, 310, 25, white);//超市
            Draw_Rounded_Rectangle(490, 260, 610, 310, 25, 1,deepblue);//超市
            PrintCC(525,275,"超市",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(670, 260, 790, 310, 25, deepblue);//餐厅
            Draw_Rounded_Rectangle(670, 260, 790, 310, 25, 1,deepblue);//餐厅
            PrintCC(705,275,"餐厅",HEI,24,1,white);

            draw_canteen();

            break;
        }
        
    }
    mouse_on_arrow(mouse);
}

void draw_market(){
    bar1(205, 325, 1024, 768, white);

    Draw_Rounded_Rectangle(250, 330, 250+185, 330+50, 5,1,0x0235);
    PrintCC(250+17,330+13,"韵苑喻园超市",HEI,24,1,0x0235);
            
    Draw_Rounded_Rectangle(500, 330, 500+185, 330+50, 5,1,0x0235);
    PrintCC(500+17,330+13,"沁苑喻园超市",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 330, 750+185, 330+50, 5,1,0x0235);
    PrintCC(750+17,330+13,"紫菘喻园超市",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue); // 确认绑定
    PrintCC(870, 715, "确定", HEI, 24, 1, deepblue);

    PrintCC(600,50,"仅能绑定一次，请慎重操作",HEI,24,1,lightred);

}

void draw_canteen(){
    int i,j;
    int cnt=0;
    bar1(205, 325, 1024, 768, white);

    //打印食堂名称
    for(i=0;i<6;i++){
    	for(j=0;j<3;j++){
            if(cnt==17) break;
    		Draw_Rounded_Rectangle(250+250*j, 330+60*i, 250+250*j+185, 330+60*i+50, 5,1,deepblue);
            PrintCC(250+250*j+17,330+60*i+13,canteen[cnt].name,HEI,24,1,deepblue);
            cnt++;
    	}
    }

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue); // 确认绑定
    PrintCC(870, 715, "确定", HEI, 24, 1, deepblue);

    PrintCC(600,50,"仅能绑定一次，请慎重操作",HEI,24,1,lightred);

}

void choose_market(int mx,int my){
	if(mx>=250&&mx<=250+185&&my>=330&&my<=330+50)//韵苑
    {
        Fill_Rounded_Rectangle(250, 330, 250+185, 330+50, 5,deepblue);
		Draw_Rounded_Rectangle(250, 330, 250+185, 330+50, 5,1,deepblue);
        PrintCC(250+17,330+13,"韵苑喻园超市",HEI,24,1,white);
                
        Fill_Rounded_Rectangle(500, 330, 500+185, 330+50, 5,white);
        Draw_Rounded_Rectangle(500, 330, 500+185, 330+50, 5,1,deepblue);
        PrintCC(500+17,330+13,"沁苑喻园超市",HEI,24,1,deepblue);

        Fill_Rounded_Rectangle(750, 330, 750+185, 330+50, 5,white);
        Draw_Rounded_Rectangle(750, 330, 750+185, 330+50, 5,1,deepblue);
        PrintCC(750+17,330+13,"紫菘喻园超市",HEI,24,1,deepblue);


	}
    else if(mx>=500&&mx<=500+185&&my>=330&&my<=330+50)//沁苑
    {
		Fill_Rounded_Rectangle(250, 330, 250+185, 330+50, 5,white);
		Draw_Rounded_Rectangle(250, 330, 250+185, 330+50, 5,1,deepblue);
        PrintCC(250+17,330+13,"韵苑喻园超市",HEI,24,1,deepblue);
                
        Fill_Rounded_Rectangle(500, 330, 500+185, 330+50, 5,deepblue);
        Draw_Rounded_Rectangle(500, 330, 500+185, 330+50, 5,1,deepblue);
        PrintCC(500+17,330+13,"沁苑喻园超市",HEI,24,1,white);

        Fill_Rounded_Rectangle(750, 330, 750+185, 330+50, 5,white);
        Draw_Rounded_Rectangle(750, 330, 750+185, 330+50, 5,1,deepblue);
        PrintCC(750+17,330+13,"紫菘喻园超市",HEI,24,1,deepblue);
	}
    else if(mx>=750&&mx<=750+185&&my>=330&&my<=330+50)//紫菘
    {
		Fill_Rounded_Rectangle(250, 330, 250+185, 330+50, 5,white);
		Draw_Rounded_Rectangle(250, 330, 250+185, 330+50, 5,1,deepblue);
        PrintCC(250+17,330+13,"韵苑喻园超市",HEI,24,1,deepblue);
                
        Fill_Rounded_Rectangle(500, 330, 500+185, 330+50, 5,white);
        Draw_Rounded_Rectangle(500, 330, 500+185, 330+50, 5,1,deepblue);
        PrintCC(500+17,330+13,"沁苑喻园超市",HEI,24,1,deepblue);

        Fill_Rounded_Rectangle(750, 330, 750+185, 330+50, 5,deepblue);
        Draw_Rounded_Rectangle(750, 330, 750+185, 330+50, 5,1,deepblue);
        PrintCC(750+17,330+13,"紫菘喻园超市",HEI,24,1,white);
	}
}

int choose_canteen(int x, int y, int* last_index) {
    int i, j;
    int index = -1;

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) { 
            int x1 = 250 + 250 * j;
            int y1 = 330 + 60 * i;
            int x2 = x1 + 185;
            int y2 = y1 + 50;

            if(i * 3 + j >= 17) break; // 超出食堂数量则退出

            if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
                index = i * 3 + j;

                // 恢复上一个按钮
                if (*last_index != -1 && *last_index != index) {
                    int pre_row = *last_index / 3;
                    int pre_col = *last_index % 3;
                    int pre_x1 = 250 + 250 * pre_col;
                    int pre_y1 = 330 + 60 * pre_row;
                    int pre_x2 = pre_x1 + 185;
                    int pre_y2 = pre_y1 + 50;

                    Fill_Rounded_Rectangle(pre_x1, pre_y1, pre_x2, pre_y2, 5, white);
                    Draw_Rounded_Rectangle(pre_x1, pre_y1, pre_x2, pre_y2, 5, 1, deepblue);
                    PrintCC(pre_x1 + 17, pre_y1 + 13, canteen[*last_index].name, HEI, 24, 1, deepblue);
                }

                // 当前按钮高亮
                Fill_Rounded_Rectangle(x1, y1, x2, y2, 5, deepblue);
                Draw_Rounded_Rectangle(x1, y1, x2, y2, 5, 1, deepblue);
                PrintCC(x1 + 17, y1 + 13, canteen[index].name, HEI, 24, 1, white);

                *last_index = index;
                return index + 1; // 返回食堂编号（1~18）
            }
        }
    }
}


