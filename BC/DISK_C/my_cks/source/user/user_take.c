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
    int mx=0;
    int my=0;

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
            press1(1);//���볬��ҳ��
            user_shop();//�û�����ҳ�� 
            return;
        }
        else if(mouse_press(40, 439, 160, 489)==1)
        {
            press1(2);//��������ҳ��
            user_takeout();//�û�����ҳ�� 
            return;
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            press1(3);//������ҳ��
            user_deliver();//�û����ҳ�� 
            return;
        }else if(mouse_press(200, 0, 1024, 768)==1)//ѡ��ʳ��
        {
            MouseGet(&mouse);
            mx=mouse.x;
            my=mouse.y;
            index=press_canteen(mx,my);//��ȡʳ�ñ��
            user_food(index);//�����Ʒҳ��

            //return����⿪ʼ
            mouse_off_arrow(&mouse);
            bar1(200, 0, 1024, 768, white); // ���ע��������
            draw_user_takeout();
            mouse_on_arrow(mouse);

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
        Draw_Rounded_Rectangle(250+250*j, 120+80*i, 250+250*j+185, 120+80*i+50, 5,1,0x0235);
        PrintCC(250+250*j+17,120+80*i+13,canteen[cnt].name,HEI,24,1,0x0235);
        cnt++;
        }
    }

    // Draw_Rounded_Rectangle(250, 120, 250+185, 120+50, 5,1,0x0235);
    // PrintCC(250+17,120+13,"��Էѧ��ʳ��",HEI,24,1,0x0235);
            
    // Draw_Rounded_Rectangle(500, 120, 500+185, 120+50, 5,1,0x0235);
    // PrintCC(500+17,120+13,"��԰ʳ��",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(750, 120, 750+185, 120+50, 5,1,0x0235);
    // PrintCC(750+17,120+13,"���̹�ʳ��",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(250, 200, 250+185, 200+50, 5,1,0x0235);
    // PrintCC(250+17,200+13,"ѧ��һʳ��",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(500, 200, 500+185, 200+50, 5,1,0x0235);
    // PrintCC(500+17,200+13,"ѧ����ʳ��",HEI,24,1,0x0235);  

    // Draw_Rounded_Rectangle(750, 200, 750+185, 200+50, 5,1,0x0235);
    // PrintCC(750+17,200+13,"�Ͼ�԰����",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(250, 280, 250+185, 280+50, 5,1,0x0235);
    // PrintCC(250+17,280+13,"��һʳ��",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(500, 280, 500+185, 280+50, 5,1,0x0235);
    // PrintCC(500+17,280+13,"����ʳ��",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(750, 280, 750+185, 280+50, 5,1,0x0235);
    // PrintCC(750+17,280+13,"��԰����",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(250, 360, 250+185, 360+50, 5,1,0x0235);
    // PrintCC(250+17,360+13,"�پ�԰",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(500, 360, 500+185, 360+50, 5,1,0x0235);
    // PrintCC(500+17,360+13,"��һʳ��",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(750, 360, 750+185, 360+50, 5,1,0x0235);
    // PrintCC(750+17,360+13,"����ʳ��",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(250, 440, 250+185, 440+50, 5,1,0x0235);
    // PrintCC(250+17,440+13,"��԰ʳ��",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(500, 440, 500+185, 440+50, 5,1,0x0235);
    // PrintCC(500+17,440+13,"���̹�ʳ��",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(750, 440, 750+185, 440+50, 5,1,0x0235);
    // PrintCC(750+17,440+13,"��԰ʳ��",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(250, 520, 250+185, 520+50, 5,1,0x0235);
    // PrintCC(250+17,520+13,"��԰ʳ��",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(500, 520, 500+185, 520+50, 5,1,0x0235);
    // PrintCC(500+17,520+13,"����ʳ��",HEI,24,1,0x0235);

    // Draw_Rounded_Rectangle(750, 520, 750+185, 520+50, 5,1,0x0235);
    // PrintCC(750+17,520+13,"��Էʳ��",HEI,24,1,0x0235);
}

int press_canteen(int mx, int my){
    //if(mx < 250 || mx > 935 || my < 120 || my > 570) return; // �߽���

    int row = (my - 120) / 80;
    int col = (mx - 250) / 250;

    // ÿ����ť�ľ�ȷ����
    int btn_x = 250 + col * 250;
    int btn_y = 120 + row * 80;

    if(mx >= btn_x && mx <= btn_x + 185 && my >= btn_y && my <= btn_y + 50){
        int index = row * 3 + col + 1;// ��������
    }
}

