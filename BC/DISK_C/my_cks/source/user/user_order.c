#include "all_func.h"
void user_order(){

    mouse_off_arrow(&mouse);

    draw_user_order();

    mouse_on_arrow(mouse);

    while(1){
        mouse_show_arrow(&mouse);
        if (mouse_press(40, 113, 160, 163) == 1) 
		{
            user_cart();
            return;
        }
    }
}

void draw_user_order(){
    bar1(200, 0, 1024, 768, white);
    
}