#include "all_func.h"




int main()
{
    int gd = DETECT, gm;
    
    int page = 0;

    SetSVGA64k();//启动SVGA画图界面 
    
    
    mouse_init(); // 初始化鼠标

    //draw_login();
    mouse_on(mouse);

    while (1)
    {
        // 更新鼠标位置
        mouse_show(&mouse);
        switch(page)
        {
            case 0:
            {
                welcome(&page);
                break;
            }
            case 1:
            {
                user_login(&page);
                break;
            }
        }

        
    }
    CloseSVGA();//关闭图形界面 
    
    return 0;
}



