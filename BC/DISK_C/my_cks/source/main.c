#include "all_func.h"

int main()
{
    int gd = DETECT, gm;
    
    int page = 0;//ҳ���־

    SetSVGA64k();//����SVGA��ͼ���� 
    
    mouse_init(); // ��ʼ�����

    mouse_on(mouse);

    while (1)
    {
        mouse_show(&mouse);// �������λ��

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
        }

        
    }
    CloseSVGA();//�ر�ͼ�ν��� 
    
    return 0;
}



