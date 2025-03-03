#include "all_func.h"
//ÆÁÄ»¿í¶È1024£¬¸ß¶È768


int welcome(int *page){
	mouse_off(&mouse);
	
	draw_basic();

	mouse_on(mouse);

	while(1){
		mouse_show(&mouse);

		if(mouse_press(300,490, 485, 540)==1){
			*page=1;
			break;
		}

        if(mouse_press(300,330,700,380)==1){
            bar1(305,335,695,375,0xFFFF);
            cursor();
		delay(15);
	}
}
}

void draw_basic()
{
    bar1(0, 0, 1024, 768,0xFFFF);

    Fill_Rounded_Rectangle(200,180, 800, 630, 30,0xFFDF);
    Draw_Rounded_Rectangle(200, 148, 824, 600, 30, 2,0x6B4D);//×îÍâÎ§»ÒÉ«Ô²½Ç¾ØÐÎ


    
    Draw_Rounded_Rectangle(300, 330, 700, 380, 5, 1,0xB71C);//ÕËºÅÀ¸Ô²½Ç¾ØÐÎ
    Draw_Rounded_Rectangle(300, 410, 700, 460, 5, 1,0xB71C);//ÃÜÂëÀ¸Ô²½Ç¾ØÐÎ
    Fill_Rounded_Rectangle(300,490, 485, 540, 5,0x435c);//µÇÂ¼°´Å¥
    Draw_Rounded_Rectangle(515, 490, 700, 540, 5,1,0x0235);//×¢²á°´Å¥
    PrintCC(305,225,"Ð£Ô°ÍâÂô¿ìµÝÆ½Ì¨",HEI,48,1,0);
    PrintCC(305,345,"ÕËºÅ",HEI,24,1,0XC618);
    PrintCC(305,425,"ÃÜÂë",HEI,24,1,0XC618);
    PrintCC(365,503,"µÇÂ¼",HEI,24,1,0xFFFF);
    PrintCC(580,503,"×¢²á",HEI,24,1,0x0235);
    PrintText(100,100,"chp123",HEI,16,1,0XC618);
    
}

