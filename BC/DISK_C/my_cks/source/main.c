#include "all_func.h"




int main()
{
    int gd = DETECT, gm;
    
    int page = 0;

    SetSVGA64k();//����SVGA��ͼ���� 
    
    
    mouse_init(); // ��ʼ�����

    //draw_login();
    mouse_on(mouse);

    while (1)
    {
        // �������λ��
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
    CloseSVGA();//�ر�ͼ�ν��� 
    
    return 0;
}



