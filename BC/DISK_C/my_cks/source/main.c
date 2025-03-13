#include "all_func.h"

int main()
{
    int gd = DETECT, gm;

    SetSVGA64k();//启动SVGA画图界面 
    
    mouse_init(); // 初始化鼠标

    mouse_on_arrow(mouse);

    while (1)
    {
        mouse_show_arrow(&mouse);// 更新鼠标位置

        welcome();//首页
             
    }
    CloseSVGA();//关闭图形界面 
    
    return 0;
}



