#include "all_func.h"

int main()
{
   
    int gd = DETECT, gm;
    int distance;
    distance = dijkstra(&node[398], &node[1],2);//����dijkstra�㷨
    SetSVGA64k();//����SVGA��ͼ���� 
    
    mouse_init(); // ��ʼ�����

    mouse_on_arrow(mouse);

    while (1)
    {
        mouse_show_arrow(&mouse);// �������λ��

        welcome();//��ҳ
             
    }
    CloseSVGA();//�ر�ͼ�ν��� 
    //printf("Distance: %d\n", distance); // ��ӡ����
    return 0;
}



