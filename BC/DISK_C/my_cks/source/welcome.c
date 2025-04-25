#include "all_func.h"

int welcome() {

    int i;//循环变量

    char name[12]="\0";//用户名
	char code[12]="\0";//密码
    char judge[12]="\0";//用于判断的密码
    int result=-5;//判断登陆结果,-5表示未登录,-2表示密码错误，-3表示用户不存在，>=0表示登录成功，返回用户位置

    int state=0;//判断是否在登录注册界面

    UserList UL={0};
	ReadAllUser(&UL);

	mouse_off_arrow(&mouse);
	
	draw_basic();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);
        
        if(state==0)//在登录注册界面
        {
            if(mouse_press(515, 490, 650, 540)==1)//点击注册
            {
                DestroyUList(&UL);//销毁线性表
                user_register();//进入注册页面
                //return后从这开始
    
                ReadAllUser(&UL);//重新读取用户信息
                mouse_off_arrow(&mouse);
                draw_basic();
                mouse_on_arrow(mouse);
            }
            else if(mouse_press(750,50,850,100)==1)
            {
                draw_about_us();//关于我们
                state=1;
            }
            else if(mouse_press(900,50,950,100)==1)
            {
                draw_about_product();//关于产品
                state=1;
            }
            else if(mouse_press(350, 330, 650, 380)==1)//点击账号框 
            {
                input_mode(name,code,judge, 355, 335, 645, 375,1,1);//输入账号
            }
            else if(mouse_press(350, 410, 650, 460)==1)//点击密码框 
            {
                input_mode(name,code,judge, 355, 415, 645, 455,2,1);//输入密码
            }
            else if(mouse_press(350, 490, 485, 540)==1)//点击登录
            {
                result=Check_info(UL,name,code);//判断账号密码是否正确
                
                if(result >= 0)
                {
                    int user_type = UL.elem[result].type; // 获取用户类型
                    users.pos=result  ;//记录用户位置

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
                    
                    // 清空输入框内容
                    for (i = 0; i < sizeof(name); i++) name[i] = '\0';
                    for (i = 0; i < sizeof(code); i++) code[i] = '\0';
                    for (i = 0; i < sizeof(judge); i++) judge[i] = '\0';
                }
                if(result ==-2)//密码输入错误 
                {
                    PrintCC(430,550,"密码错误",HEI,24,1,lightred);
                    delay(500);
                    bar1(430,550,580,580,white);
                }
                if(result ==-3)//用户不存在 
                {
                    PrintCC(430,550,"用户不存在",HEI,24,1,lightred);
                    delay(500);
                    bar1(430,550,580,580,white);
                } 
            delay(15);
            }

        }

        if(state==1)
        {
            if(mouse_press(750,50,850,100)==1)
            {
                draw_about_us();//关于我们
                state=1;
            }
            else if(mouse_press(900,50,950,100)==1)
            {
                draw_about_product();//关于产品
                state=1;
            }
            else if(mouse_press(700, 225,720,245)==1)
            {
                mouse_off_arrow(&mouse);
                draw_basic();//返回登录界面
                mouse_on_arrow(mouse);
                state=0;
            }
        }
    }
}


void draw_basic()
{
    Readbmp64k(0, 0, "bmp\\city.bmp");

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


void draw_about_us() 
{
	Fill_Rounded_Rectangle(250, 200, 750, 580, 30, white); // 背景框

    Line_Thick(700, 225, 720, 245, 1, black);//"x"
    Line_Thick(700, 245, 720, 225, 1, black);//

    PrintText(270, 225, "联系我们", HEI, 32, 1, 0x0000); // 标题（黑色）

    PrintText(270, 300, "本系统由华中科技大学人工智能与自动化", HEI, 24, 1, 0x0000);
    PrintText(270, 330, "学院智能2402班的曹瀚鹏，张子恒完成。", HEI, 24, 1, 0x0000);
    PrintText(270, 360, "曹瀚鹏主要负责完成骑手端编写及路径", HEI, 24, 1, 0x0000);
    PrintText(270, 390, "规划操作，张子恒主要负责完成用户和", HEI, 24, 1, 0x0000);
    PrintText(270, 420, "商家信息存储，订单展示功能", HEI, 24, 1, 0x0000);
    PrintText(270, 450, "如有问题，请联系：", HEI, 24, 1, 0x0000);
    PrintText(270, 480, "曹瀚鹏  2960473693", HEI, 24, 1, 0x0000);
    PrintText(270, 510, "张子恒  2496100220", HEI, 24, 1, 0x0000);
}
void draw_about_product() 
{
    Fill_Rounded_Rectangle(250, 200, 750, 580, 30, white); // 背景框

    Line_Thick(700, 225, 720, 245, 1, black);//"X"
    Line_Thick(700, 245, 720, 225, 1, black);//

    PrintText(270, 225, "产品介绍", HEI, 32, 1, 0x0000); // 标题（黑色）

    PrintText(270, 300, "本系统模拟了校园内外卖配送超市购物配", HEI, 24, 1, 0x0000);
    PrintText(270, 330, "送及快递代取的完整流程，涵盖用户注册", HEI, 24, 1, 0x0000);
    PrintText(270, 360, "与管理、商家管理、订单处理、骑手配送", HEI, 24, 1, 0x0000);
    PrintText(270, 390, "等功能。通过合理的数据选取与系统设计", HEI, 24, 1, 0x0000);
    PrintText(270, 420, "该系统可为校园内的学生、教师、食堂及", HEI, 24, 1, 0x0000);
    PrintText(270, 450, "超市商家、配送骑手等提供一体化的线上", HEI, 24, 1, 0x0000);
    PrintText(270, 480, "交易与配送服务。结合骑手路径优化功能", HEI, 24, 1, 0x0000);
    PrintText(270, 510, "该系统能够提高配送效率，减少配送成本", HEI, 24, 1, 0x0000);
    PrintText(270, 540, "保障订单的及时送达。", HEI, 24, 1, 0x0000);
}

