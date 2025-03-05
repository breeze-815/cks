#include "all_func.h"

int main()
{
    int gd = DETECT, gm;
    
    int page = 0;//页面标志

    SetSVGA64k();//启动SVGA画图界面 
    
    mouse_init(); // 初始化鼠标

    mouse_on(mouse);

    while (1)
    {
        mouse_show(&mouse);// 更新鼠标位置

        switch(page)
        {
            case 0:
            {
                welcome(&page);
                break;
            }
            case 1:
            {
                user_register(&page);
                break;
            }
            case 2:
            {
                user(&page);//用户页面
                break;
            }
            case 3:
            {
                //商家页面
                break;
            }
            case 4:
            {
                //骑手页面
                break;
            }
            case 5:
            {   
                user_shop(&page);
                //用户超市页面
                break;
            }
            case 6:
            {
                //用户外卖页面
                break;
            }
            case 7:
            {
                //用户快递页面
                break;
            }
            case 8:
            {
                break;
            }
        }

        
    }
    CloseSVGA();//关闭图形界面 
    
    return 0;
}



