#include "all_func.h"

Deliver delivers={0};//�洢��Ϣ�Ŀ�ݽṹ��

void user_deliver(){
    UserList UL = {0};
    USER *currentUser;

    ReadAllUser(&UL); // ��ȡ�û��б�

    currentUser=&UL.elem[users.pos];// ��ȡ��ǰ�û���Ϣ

    DestroyUList(&UL); // �ͷ��û��б�ռ�

    mouse_off_arrow(&mouse);
	
	draw_user_deliver();

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
        }
        else if(mouse_press(440, 35, 660, 85)==1)
        {
            deliver_input(delivers.code, 445, 40, 655, 80); // ����ȡ����
        }
        else if(mouse_press(730, 35, 850, 85)==1)//���涩���Ű�ť
        {
        	save_Deliver(delivers);
            PrintCC(750, 120, "����ɹ�", HEI, 24, 1, lightred);
            delay(500);
            bar1(750, 120, 1024, 160, white);
        }
        else if(mouse_press(800, 700, 1000, 750)==1)
        {
            save_Deliver(delivers);
            PrintCC(750, 120, "�����ѱ���", HEI, 24, 1, lightred);
            delay(500);
            bar1(750, 120, 1024, 160, white);
        }
        else if(mouse_press(250, 175, 250+185, 175+50)==1)
        {
            press_station(1);          
        }
        else if(mouse_press(500, 175, 500+185, 175+50)==1)
        {
            press_station(2);
        }
        else if(mouse_press(750, 175, 750+185, 175+50)==1)
        {
            press_station(3);
        }
        else if(mouse_press(250, 250, 250+185, 250+50)==1)
        {
            press_station(4);
        }
        else if(mouse_press(500, 250, 500+185, 250+50)==1)
        {
            press_station(5);
        }
        else if(mouse_press(750, 250, 750+185, 250+50)==1)
        {
            press_station(6);
        }
        else if(mouse_press(250, 325, 250+185, 325+50)==1)
        {
            press_station(7);
        }
        else if(mouse_press(500, 325, 500+185, 325+50)==1)
        {
            press_station(8);
        }
    }
}

void draw_user_deliver(){
    bar1(200, 0, 1024, 768,white);

    Draw_Rounded_Rectangle(440, 35, 660, 85, 5, 1,deepblue);//ȡ��������� 
    Draw_Rounded_Rectangle(730, 35, 850, 85, 25, 1,deepblue);//���水ť

    PrintCC(250,50,"������ȡ���룺",HEI,24,1,deepblue);
    PrintCC(250,120,"��ѡ������ṩ�̣�",HEI,24,1,deepblue);
    PrintCC(765,50,"����",HEI,24,1,deepblue);

    Draw_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,1,deepblue);
    PrintCC(250+40,175+13,"˳����",HEI,24,1,deepblue);
    
    Draw_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,1,deepblue);
    PrintCC(500+40,175+13,"�ϴ���",HEI,24,1,deepblue);

    Draw_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,1,deepblue);
    PrintCC(750+40,175+13,"��ͨ���",HEI,24,1,deepblue);

    Draw_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,1,deepblue);
    PrintCC(250+40,250+13,"��ͨ���",HEI,24,1,deepblue);

    Draw_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,1,deepblue);
    PrintCC(500+40,250+13,"�������",HEI,24,1,deepblue);  

    Draw_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,1,deepblue);
    PrintCC(750+40,250+13,"�������",HEI,24,1,deepblue);

    Draw_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,1,deepblue);
    PrintCC(250+40,325+13,"Բͨ���",HEI,24,1,deepblue);

    Draw_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,1,deepblue);
    PrintCC(500+40,325+13,"�������",HEI,24,1,deepblue);

    Draw_Rounded_Rectangle(800, 700, 1000, 750, 5, 1, deepblue); // ���ɶ���
    PrintCC(850, 715, "���ɶ���", HEI, 24, 1, deepblue);
}

void press_station(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    {
        case 1:{
            Fill_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,deepblue);
            Draw_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,1,deepblue);
            PrintCC(250+40,175+13,"˳����",HEI,24,1,white);

            Fill_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,1,deepblue);
            PrintCC(500+40,175+13,"�ϴ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,1,deepblue);
            PrintCC(750+40,175+13,"��ͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,1,deepblue);
            PrintCC(250+40,250+13,"��ͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,1,deepblue);
            PrintCC(500+40,250+13,"�������",HEI,24,1,deepblue);  

            Fill_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,1,deepblue);
            PrintCC(750+40,250+13,"�������",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,white);
            Draw_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,1,deepblue);
            PrintCC(250+40,325+13,"Բͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,white);
            Draw_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,1,deepblue);
            PrintCC(500+40,325+13,"�������",HEI,24,1,deepblue);
            break;
        }
        case 2:{
            Fill_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,1,deepblue);
            PrintCC(250+40,175+13,"˳����",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,deepblue);
            Draw_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,1,deepblue);
            PrintCC(500+40,175+13,"�ϴ���",HEI,24,1,white);

            Fill_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,1,deepblue);
            PrintCC(750+40,175+13,"��ͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,1,deepblue);
            PrintCC(250+40,250+13,"��ͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,1,deepblue);
            PrintCC(500+40,250+13,"�������",HEI,24,1,deepblue);  

            Fill_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,1,deepblue);
            PrintCC(750+40,250+13,"�������",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,white);
            Draw_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,1,deepblue);
            PrintCC(250+40,325+13,"Բͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,white);
            Draw_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,1,deepblue);
            PrintCC(500+40,325+13,"�������",HEI,24,1,deepblue);
            break;
        }
        case 3:{
            Fill_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,1,deepblue);
            PrintCC(250+40,175+13,"˳����",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,1,deepblue);
            PrintCC(500+40,175+13,"�ϴ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,deepblue);
            Draw_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,1,deepblue);
            PrintCC(750+40,175+13,"��ͨ���",HEI,24,1,white);

            Fill_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,1,deepblue);
            PrintCC(250+40,250+13,"��ͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,1,deepblue);
            PrintCC(500+40,250+13,"�������",HEI,24,1,deepblue);  

            Fill_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,1,deepblue);
            PrintCC(750+40,250+13,"�������",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,white);
            Draw_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,1,deepblue);
            PrintCC(250+40,325+13,"Բͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,white);
            Draw_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,1,deepblue);
            PrintCC(500+40,325+13,"�������",HEI,24,1,deepblue);
            break;
        }
        case 4:{
            Fill_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,1,deepblue);
            PrintCC(250+40,175+13,"˳����",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,1,deepblue);
            PrintCC(500+40,175+13,"�ϴ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,1,deepblue);
            PrintCC(750+40,175+13,"��ͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,deepblue);
            Draw_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,1,deepblue);
            PrintCC(250+40,250+13,"��ͨ���",HEI,24,1,white);

            Fill_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,1,deepblue);
            PrintCC(500+40,250+13,"�������",HEI,24,1,deepblue);  

            Fill_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,1,deepblue);
            PrintCC(750+40,250+13,"�������",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,white);
            Draw_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,1,deepblue);
            PrintCC(250+40,325+13,"Բͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,white);
            Draw_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,1,deepblue);
            PrintCC(500+40,325+13,"�������",HEI,24,1,deepblue);
            break;
        }   
        case 5:{
            Fill_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,1,deepblue);
            PrintCC(250+40,175+13,"˳����",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,1,deepblue);
            PrintCC(500+40,175+13,"�ϴ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,1,deepblue);
            PrintCC(750+40,175+13,"��ͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,1,deepblue);
            PrintCC(250+40,250+13,"��ͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,deepblue);
            Draw_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,1,deepblue);
            PrintCC(500+40,250+13,"�������",HEI,24,1,white);  

            Fill_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,1,deepblue);
            PrintCC(750+40,250+13,"�������",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,white);
            Draw_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,1,deepblue);
            PrintCC(250+40,325+13,"Բͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,white);
            Draw_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,1,deepblue);
            PrintCC(500+40,325+13,"�������",HEI,24,1,deepblue);
            break;
        }
        case 6:{
            Fill_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,1,deepblue);
            PrintCC(250+40,175+13,"˳����",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,1,deepblue);
            PrintCC(500+40,175+13,"�ϴ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,1,deepblue);
            PrintCC(750+40,175+13,"��ͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,1,deepblue);
            PrintCC(250+40,250+13,"��ͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,1,deepblue);
            PrintCC(500+40,250+13,"�������",HEI,24,1,deepblue);  

            Fill_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,deepblue);
            Draw_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,1,deepblue);
            PrintCC(750+40,250+13,"�������",HEI,24,1,white);

            Fill_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,white);
            Draw_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,1,deepblue);
            PrintCC(250+40,325+13,"Բͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,white);
            Draw_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,1,deepblue);
            PrintCC(500+40,325+13,"�������",HEI,24,1,deepblue);
            break;
        }
        case 7:{
            Fill_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,1,deepblue);
            PrintCC(250+40,175+13,"˳����",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,1,deepblue);
            PrintCC(500+40,175+13,"�ϴ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,1,deepblue);
            PrintCC(750+40,175+13,"��ͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,1,deepblue);
            PrintCC(250+40,250+13,"��ͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,1,deepblue);
            PrintCC(500+40,250+13,"�������",HEI,24,1,deepblue);  

            Fill_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,1,deepblue);
            PrintCC(750+40,250+13,"�������",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,deepblue);
            Draw_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,1,deepblue);
            PrintCC(250+40,325+13,"Բͨ���",HEI,24,1,white);

            Fill_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,white);
            Draw_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,1,deepblue);
            PrintCC(500+40,325+13,"�������",HEI,24,1,deepblue);
            break;
        }
        case 8:{
        	Fill_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,1,deepblue);
            PrintCC(250+40,175+13,"˳����",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,1,deepblue);
            PrintCC(500+40,175+13,"�ϴ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,white);
            Draw_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,1,deepblue);
            PrintCC(750+40,175+13,"��ͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,1,deepblue);
            PrintCC(250+40,250+13,"��ͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,1,deepblue);
            PrintCC(500+40,250+13,"�������",HEI,24,1,deepblue);  

            Fill_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,white);
            Draw_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,1,deepblue);
            PrintCC(750+40,250+13,"�������",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,white);
            Draw_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,1,deepblue);
            PrintCC(250+40,325+13,"Բͨ���",HEI,24,1,deepblue);

            Fill_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,deepblue);
            Draw_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,1,deepblue);
            PrintCC(500+40,325+13,"�������",HEI,24,1,white);
            break;
        }
    }
    mouse_on_arrow(mouse);
    delivers.station=x;
    save_Deliver(delivers);
}

void deliver_input(char *deliver_code,int bar_x1,int bar_y1,int bar_x2,int bar_y2)
{
	int length;
	char showtemp[2]= "\0";//�洢�����ַ�,���������չʾ
	int i=0,k,temp;  // iΪ�ַ�����,tempΪ�Ӽ����϶�ȡ�����ַ���ACSII��
	int bDeliver; //���ĺ�����	    
	int x1,y1;
	x1=bar_x1+4;
	y1=bar_y1+5;//��������������ƫ����
	bDeliver=x1+4;//ÿ���ַ�ռ8������,ÿ����һ���ַ��������8������
	
    if(deliver_code[0]=='\0') //���ȡ����Ϊ�գ�����ʾ�����
        bar1(bar_x1, bar_y1, bar_x2, bar_y2,0xFFFF);
    else
    {            //��궨λ���ı�ĩβ
        length=strlen(deliver_code);
        i=length;
        bDeliver+=12*i;
        cursor(bDeliver,y1);
    }	

	while(1) 
    {
		cursor(bDeliver,y1);
		if(mouse_location(455,255,845,295)==1 && mouse_location(455,335,845,375)==1 && mouse_location(455,415,845,455)==1)
			mouse_show_cursor(&mouse);
		else
			mouse_show_arrow(&mouse);
		if(bioskey(1)) //����м�������
		{
			temp=bioskey(0)&0x00ff; //��ȡ��������
			if(temp!='\r'&&temp!='\n')	//������벻Ϊ�س�����������������������
			{
				if((('0'<=temp&&temp<='9')||('a'<=temp&&temp<='z')||('A'<=temp && temp<='Z')||(temp=='-'))&& i <10)//���Ϊ���ֻ���ĸ��-�����¼
				{
					hide_cursor(bDeliver,y1); //����ԭ���
					
					deliver_code[i]=temp;//�ַ���������ַ��������ڱ���ȡ������Ϣ
								
					*showtemp=temp;  //tempת��Ϊ�ַ���
					PrintText(bDeliver,y1+2,showtemp,HEI,24,1,0); //��ʾ�µ��ַ����ﵽ������ʵ�������ͬ��
					i++;	//�ַ���������
					
					deliver_code[i]='\0';//����ַ�����β
							
					bDeliver+=12;	//������������12����
					draw_cursor(bDeliver,y1);
				}
				else if(temp=='\b'&&i>0)  //����Ƿ�Ϊ�˸������������ǰһ���ַ�
				{
					hide_cursor(bDeliver,y1);	//����ԭ���
					bDeliver-=12;	//�������12����
					i--;	//�ַ������Լ�
				
					deliver_code[i]='\0';//���洢���ַ���0����
					
					bar1(bDeliver,y1,bDeliver+10, y1+24, 0xffff);	//���ԭ�ַ�
					draw_cursor(bDeliver,y1);
				}
				else if(i>=10)
				{
					mouse_off_arrow(&mouse);
					mouse_show_arrow(&mouse);
					PrintCC(750,120,"���ȳ�������",HEI,24,1,lightred);
					delay(500);
					bar1(750,120,900,160,white);
				}
			}
			else
			{	
				break;
			}
		}
		else if (mouse_press(bar_x1,bar_y1,bar_x2,bar_y2)==2)  //�������
		{
			hide_cursor(bDeliver,y1);//���ع��
			break;
		}	
	}
}	

int Deliver_pos(DeliverList DL,Deliver delivers)
{
	int i=-1;
	for(i=0;i<DL.length;i++)
	{
		if(delivers.id == DL.elem[i].id)
		{
			return i;
		}	
	}
	return -1;
}

void DListInsert(DeliverList*DL,Deliver delivers) 
{
    Deliver*newbase=NULL;//�����»�ַ
    if(DL->length>=DL->listsize)//������Ա�����
    {
        if((newbase=(Deliver*)realloc(DL->elem,(DL->listsize+D_LISTINCEREMENT)*sizeof(Deliver)))==NULL)////���·����ڴ�
        {
        CloseSVGA();
        printf("No enough memory!\n");
        printf("DListInsert\n");
        exit(-1);
        }
        DL->elem=newbase;//���»�ַ
        DL->listsize+=D_LISTINCEREMENT;//�������Ա�����
    }
    *(DL->elem+(DL->length))=delivers;//������Ԫ��
    DL->length++;//���Ա��ȼ�һ
}

int save_Deliver(Deliver delivers) {
    int i = 0;
    DeliverList DL = {0};
	int deliver_pos;
	FILE *fp = NULL;

	ReadAllDeliver(&DL);//��ȡ���ж�����Ϣ

    if ((fp = fopen("data\\Deliver.dat", "wb")) == NULL) {
        printf("�޷����ļ���\n");
        return -1;
    }

    // �Ȳ��Ҷ����Ƿ��Ѿ�����
	deliver_pos = Deliver_pos(DL, delivers);

	if (deliver_pos == -1)  // �������������
	{
		DListInsert(&DL, delivers); // ���붩��
	}
	else  // ����������ڣ�����ԭ�ж�����Ϣ
	{
		delivers.id = DL.elem[deliver_pos].id; // ����ԭ����ID
		DL.elem[deliver_pos] = delivers;
	}


    // ���½����Ա�д���ļ�
    rewind(fp);//���ļ�ָ���ƶ����ļ���ͷ
    fwrite(&DL.length, sizeof(short), 1, fp);//д�����Ա���
    fwrite(&DL.listsize, sizeof(short), 1, fp);//д�����Ա�����
 
    // ���д������
    for (i = 0; i < DL.length; i++) {
        fwrite(&DL.elem[i], sizeof(Deliver), 1, fp);
    }

    fclose(fp);
    DestroyDList(&DL);
    return 0;
}

void DestroyDList(DeliverList*DL)	
{
	free(DL->elem);
	DL->listsize=0;
	DL->length=0;
}

void ReadAllDeliver(DeliverList *DL) {
    int i = 0;
    short length = 0;//���Ա��ʼ����
    short listsize = 10; //���Ա��ʼ�������ܹ��洢10��������
    FILE *fp = NULL;

    if ((fp = fopen("data\\Deliver.dat", "rb")) == NULL) {//������ļ�ʧ��
        fp = fopen("data\\Deliver.dat", "wb");// ����ļ��������򴴽�һ���µ��ļ�
        if (fp == NULL) {//��������ļ�ʧ��
            printf("�޷������ļ���\n");
            return;//�޷������ļ��򷵻أ�����Ҫ����ִ������Ĵ���
        }
        fwrite(&length, sizeof(short), 1, fp); //��������ɹ���д���ʼ����0
        fwrite(&listsize, sizeof(short), 1, fp); //д���ʼ����10
        fclose(fp);//�ر��ļ�
        return;//������ɺ󷵻أ�����Ҫ����ִ������Ĵ���
    }
    //������ļ��ɹ����ȡ���Ⱥ�����
    fread(&length, sizeof(short), 1, fp); 
    fread(&listsize, sizeof(short), 1, fp); 
    //�Ѷ�ȡ�ĳ��Ⱥ�������ֵ�����Ա�
    DL->length = length;
    DL->listsize = listsize;
    DL->elem = (Deliver *)malloc(listsize * sizeof(Deliver)); //����洢�ռ�
    //������Ա�Ĵ洢�ռ����ʧ�������������Ϣ���˳�����
    if (DL->elem == NULL) {
        printf("No enough memory!\n");
        printf("ReadAllDeliver\n");
        fclose(fp);
        exit(-1);
    }
    //�������ɹ��������ȡ��������
    //���Ѷ�ȡ�����ݴ洢�����Ա���
    for (i = 0; i < length; i++) {
        fread(&DL->elem[i], sizeof(Deliver), 1, fp);
    }

    fclose(fp);
}