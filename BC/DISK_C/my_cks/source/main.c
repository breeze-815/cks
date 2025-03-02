#include "all_func.h"




int main()
{
    int gd = DETECT, gm;
    
    SetSVGA64k();//启动SVGA画图界面 
    
    
    mouse_init(); // 初始化鼠标

    draw_login();
    mouse_on(mouse);

    while (1)
    {
        

        // 更新鼠标位置
        mouse_show(&mouse);

        
    }
    CloseSVGA();//关闭图形界面 
    
    return 0;
}



