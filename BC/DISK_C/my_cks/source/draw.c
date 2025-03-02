#include <all_func.h>
void draw_login()
{
	bar1(0, 0, 1024, 768,0xD5B1);

	Fill_Rounded_Rectangle(200,220, 800, 630, 30,0xFFFF);
	Draw_Rounded_Rectangle(200, 220, 800, 630, 30, 2,0xC618);//最外围灰色圆角矩形
	
	Draw_Rounded_Rectangle(300, 330, 700, 380, 5, 1,0xAEFC);//账号栏圆角矩形
	Draw_Rounded_Rectangle(300, 410, 700, 460, 5, 1,0xAEFC);//密码栏圆角矩形
	Fill_Rounded_Rectangle(300,490, 485, 540, 5,0x435c);//登录按钮
	Draw_Rounded_Rectangle(515, 490, 700, 540, 5,1,0x0235);//注册按钮
	PrintCC(305,250,"校园外卖快递平台",HEI,48,1,0);
	PrintCC(305,345,"账号",HEI,24,1,0XC618);
	PrintCC(305,425,"密码",HEI,24,1,0XC618);
	PrintCC(365,503,"登录",HEI,24,1,0xFFFF);
	PrintCC(580,503,"注册",HEI,24,1,0x0235);
	
}

