#include "all_func.h"
void business_detail(){
    mouse_off_arrow(&mouse);

    mouse_on_arrow(mouse);

    mouse_on_arrow(mouse);

    while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
			business_order();//
		}
    }
}