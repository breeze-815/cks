#include "all_func.h"

int main()
{
    int gd = DETECT, gm;
    
    int page = 0;//ҳ���־

    int shop_type=0;//��������

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
                welcome(&page);//��ҳ
                break;
            }
            case 1:
            {
                user_register(&page);//ע��
                break;
            }
            case 2:
            {
                user(&page,&shop_type);//�û�ҳ��
                break;
            }
            case 3:
            {
                business(&page);//�̼�ҳ��
                break;
            }
            case 4:
            {
                rider(&page);//����ҳ��
                break;
            }
            case 5:
            {   
                user_shop(&page,&shop_type);//�û�����ҳ��               
                break;
            }
            case 6:
            {
                user_takeout(&page,&shop_type);//�û�����ҳ��              
                break;
            }
            case 7:
            {
                user_deliver(&page,&shop_type);//�û����ҳ��  
                break;
            }
            case 8:
            {
                business_order(&page);//�̼Ҷ���ҳ��
                break;
            }
            case 9:
            {
                user_cart(&page);//�û����ﳵҳ��
                break;
            }
        }

        
    }
    CloseSVGA();//�ر�ͼ�ν��� 
    
    return 0;
}



