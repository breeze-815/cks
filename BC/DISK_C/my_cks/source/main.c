#include "all_func.h"

int main()
{
    int distance;
    int gd = DETECT, gm;
    SetSVGA64k();//����SVGA��ͼ���� 
    
    mouse_init(); // ��ʼ�����

    mouse_on_arrow(mouse);

    while (1)
    {
        mouse_show_arrow(&mouse);// �������λ��

        welcome();//��ҳ
    }
    //distance=dijkstra(&node[7], &node[12], 3);
    //printf("%d",distance);
    return 0;
}



