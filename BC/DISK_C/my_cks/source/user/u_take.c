#include "all_func.h"

Canteen canteen[17]={
    {1,"��Էѧ��ʳ��"},
    {2,"��԰ʳ��"},
    {3,"ѧһʳ��"},
    {4,"ѧ��ʳ��"},
    {5,"���̹�ʳ��"},
    {6,"��԰ʳ��"},
    {7,"����¥ʳ��"},
    {8,"��һʳ��"},
    {9,"�Ͼ�԰����"},
    {10,"����ʳ��"},
    {11,"����ʳ��"},
    {12,"��һʳ��"},
    {13,"����ʳ��"},
    {14,"����ʳ��"},
    {15,"�پ�԰����"},
    {16,"����԰����"},
    {17,"�ٻ�԰����"}
};
void user_takeout(){
    int index=0;
    
    mouse_off_arrow(&mouse);
	
	draw_user_takeout();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
            return;
			//welcome();//��ҳ
		}
        else if(mouse_press(40, 276, 160, 326)==1)
        {
            press_func(1);//���볬��ҳ��
            user_shop();//�û�����ҳ�� 
            return;
        }
        else if(mouse_press(40, 439, 160, 489)==1)
        {
            press_func(2);//��������ҳ��
            user_takeout();//�û�����ҳ�� 
            return;
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            press_func(3);//������ҳ��
            user_deliver();//�û����ҳ�� 
            return;
        }else if(mouse_press(200, 0, 1024, 768)==1)//ѡ��ʳ��
        {
            int mx,my;
            MouseGet(&mouse);
            mx=mouse.x;
            my=mouse.y;
            index=press_canteen(mx,my);//��ȡʳ�ñ��
            if(index<18&&index>0)
            { 
                user_food(index);//�����Ʒҳ��

                //return����⿪ʼ
                mouse_off_arrow(&mouse);
                bar1(200, 0, 1024, 768, white); // ���ע��������
                draw_user_takeout();
                mouse_on_arrow(mouse);
            }

        }
        
    }
}
void draw_user_takeout(){
    int i,j;
    int cnt=0;
    bar1(200, 0, 1024, 768,white);

    PrintCC(250,50,"��ѡ��ʳ��",HEI,24,1,deepblue);

    for(i=0;i<6;i++){
        for(j=0;j<3;j++){
            if(i*3+j>=17) break; // ����ʳ���������˳�
            Draw_Rounded_Rectangle(250+250*j, 120+80*i, 250+250*j+185, 120+80*i+50, 5,1,0x0235);
            PrintCC(250+250*j+17,120+80*i+13,canteen[cnt].name,HEI,24,1,0x0235);
            cnt++;
        }
    }
}

int press_canteen(int mx, int my){
    int row = (my - 120) / 80;
    int col = (mx - 250) / 250;

    // ÿ����ť�ľ�ȷ����
    int btn_x = 250 + col * 250;
    int btn_y = 120 + row * 80;

    if(mx >= btn_x && mx <= btn_x + 185 && my >= btn_y && my <= btn_y + 50){
        if(row * 3 + col >= 17) return -1; // ����ʳ���������˳�
        return row * 3 + col + 1;// ��������
    }
}

