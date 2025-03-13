#include "all_func.h"

int main()
{
    int gd = DETECT, gm;
    
    int page = 0;//页面标志

    int shop_type=0;//超市种类

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
                welcome(&page);//首页
                break;
            }
            case 1:
            {
                user_register(&page);//注册
                break;
            }
            case 2:
            {
                user(&page,&shop_type);//用户页面
                break;
            }
            case 3:
            {
                business(&page);//商家页面
                break;
            }
            case 4:
            {
                rider(&page);//骑手页面
                break;
            }
            case 5:
            {   
                user_shop(&page,&shop_type);//用户超市页面               
                break;
            }
            case 6:
            {
                user_takeout(&page,&shop_type);//用户外卖页面              
                break;
            }
            case 7:
            {
                user_deliver(&page,&shop_type);//用户快递页面  
                break;
            }
            case 8:
            {
                business_order(&page);//商家订单页面
                break;
            }
            case 9:
            {
                user_cart(&page);//用户购物车页面
                break;
            }
        }

        
    }
    CloseSVGA();//关闭图形界面 
    
    return 0;
}



