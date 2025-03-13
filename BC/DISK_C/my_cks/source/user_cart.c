#include "all_func.h"

void user_cart(int *page){
    mouse_off(&mouse);
	
	draw_user_cart();

	mouse_on(mouse);

	while(1){
		mouse_show(&mouse);

		if(mouse_press(40, 113, 160, 163)==1){
			*page=2;//·µ»ØÊ×Ò³
			break;
		}
    }
}

void draw_user_cart(){
    bar1(200, 0, 1024, 768,white);
}