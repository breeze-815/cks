#include "all_func.h"

int main()
{
    int gd = DETECT, gm;

    SetSVGA64k();//����SVGA��ͼ���� 
    
    mouse_init(); // ��ʼ�����

    mouse_on_arrow(mouse);

    while (1)
    {
        mouse_show_arrow(&mouse);// �������λ��

        welcome();//��ҳ
             
    }
    CloseSVGA();//�ر�ͼ�ν��� 
    
    return 0;
}



