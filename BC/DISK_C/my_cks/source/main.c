#include "all_func.h"




int main()
{
    int gd = DETECT, gm;
    
    SetSVGA64k();//����SVGA��ͼ���� 
    
    
    mouse_init(); // ��ʼ�����

    draw_login();
    mouse_on(mouse);

    while (1)
    {
        

        // �������λ��
        mouse_show(&mouse);

        
    }
    CloseSVGA();//�ر�ͼ�ν��� 
    
    return 0;
}



