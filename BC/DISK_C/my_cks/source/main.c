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
            case 2:
            {
                user(&page);//�û�ҳ��
                break;
            }
            case 3:
            {
                //�̼�ҳ��
                break;
            }
            case 4:
            {
                //����ҳ��
                break;
            }
            case 5:
            {   
                user_shop(&page);
                //�û�����ҳ��
                break;
            }
            case 6:
            {
                //�û�����ҳ��
                break;
            }
            case 7:
            {
                //�û����ҳ��
                break;
            }
            case 8:
            {
                break;
            }
        }

        
    }
    CloseSVGA();//�ر�ͼ�ν��� 
    
    return 0;
}



