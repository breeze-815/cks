#include "all_func.h"

Deliver deliver={0};//�洢��Ϣ�Ŀ�ݽṹ��

void user_deliver(){

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
            deliver_input(deliver.code, 445, 40, 655, 80); // ����ȡ����
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

    Draw_Rounded_Rectangle(250, 175, 250+185, 175+50, 5,1,0x0235);//ע�ᰴť
    PrintCC(250+40,175+13,"˳����",HEI,24,1,0x0235);
    
    Draw_Rounded_Rectangle(500, 175, 500+185, 175+50, 5,1,0x0235);//ע�ᰴť
    PrintCC(500+40,175+13,"�ϴ���",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(750, 175, 750+185, 175+50, 5,1,0x0235);//ע�ᰴť
    PrintCC(750+40,175+13,"��ͨ���",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 250, 250+185, 250+50, 5,1,0x0235);//ע�ᰴť
    PrintCC(250+40,250+13,"��ͨ���",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 250, 500+185, 250+50, 5,1,0x0235);//ע�ᰴť
    PrintCC(500+40,250+13,"�������",HEI,24,1,0x0235);  

    Draw_Rounded_Rectangle(750, 250, 750+185, 250+50, 5,1,0x0235);//ע�ᰴť
    PrintCC(750+40,250+13,"�������",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(250, 325, 250+185, 325+50, 5,1,0x0235);//ע�ᰴť
    PrintCC(250+40,325+13,"Բͨ���",HEI,24,1,0x0235);

    Draw_Rounded_Rectangle(500, 325, 500+185, 325+50, 5,1,0x0235);//ע�ᰴť
    PrintCC(500+40,325+13,"�������",HEI,24,1,0x0235);
}

void press_station(int x){
    switch (x)
    {
        case 1:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,deepblue);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 2:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,deepblue);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 3:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,deepblue);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 4:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,deepblue);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }   
        case 5:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,deepblue);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 6:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,deepblue);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,grey);
            break;
        }
        case 7:{
            PrintCC(210,15,"������Ʒ",HEI,24,1,grey);
            PrintCC(355,15,"�ľ�",HEI,24,1,grey);
            PrintCC(475,15,"��ʳ",HEI,24,1,grey);
            PrintCC(595,15,"����",HEI,24,1,grey);
            PrintCC(690,15,"�˶���Ʒ",HEI,24,1,grey);
            PrintCC(835,15,"ˮ��",HEI,24,1,grey);
            PrintCC(955,15,"�Ĵ�",HEI,24,1,deepblue);
            break;
        }
    }
}

void deliver_input(char *deliver_code,int bar_x1,int bar_y1,int bar_x2,int bar_y2)
{
	int length;
	char showtemp[2]= "\0";//�洢�����ַ�,���������չʾ
	int i=0,k,temp;  // iΪ�ַ�����,tempΪ�Ӽ����϶�ȡ�����ַ���ACSII��
	int border; //���ĺ�����	    
	int x1,y1;
	x1=bar_x1+4;
	y1=bar_y1+5;//��������������ƫ����
	border=x1+4;//ÿ���ַ�ռ8������,ÿ����һ���ַ��������8������
	
    if(deliver_code[0]=='\0') //���ȡ����Ϊ�գ�����ʾ�����
        bar1(bar_x1, bar_y1, bar_x2, bar_y2,0xFFFF);
    else
    {            //��궨λ���ı�ĩβ
        length=strlen(deliver_code);
        i=length;
        border+=12*i;
        cursor(border,y1);
    }	

	while(1) 
    {
		cursor(border,y1);
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
					hide_cursor(border,y1); //����ԭ���
					
					deliver_code[i]=temp;//�ַ���������ַ��������ڱ���ȡ������Ϣ
								
					*showtemp=temp;  //tempת��Ϊ�ַ���
					PrintText(border,y1+2,showtemp,HEI,24,1,0); //��ʾ�µ��ַ����ﵽ������ʵ�������ͬ��
					i++;	//�ַ���������
					
					deliver_code[i]='\0';//����ַ�����β
							
					border+=12;	//������������12����
					draw_cursor(border,y1);
				}
				else if(temp=='\b'&&i>0)  //����Ƿ�Ϊ�˸������������ǰһ���ַ�
				{
					hide_cursor(border,y1);	//����ԭ���
					border-=12;	//�������12����
					i--;	//�ַ������Լ�
				
					deliver_code[i]='\0';//���洢���ַ���0����
					
					bar1(border,y1,border+10, y1+24, 0xffff);	//���ԭ�ַ�
					draw_cursor(border,y1);
				}
				else if(i>=10)
				{
					mouse_off_arrow(&mouse);
					mouse_show_arrow(&mouse);
					PrintCC(750,100,"���ȳ�������",HEI,24,1,lightred);
					delay(500);
					bar1(750,100,900,125,white);
				}
			}
			else
			{	
				break;
			}
		}
		else if (mouse_press(bar_x1,bar_y1,bar_x2,bar_y2)==2)  //�������
		{
			hide_cursor(border,y1);//���ع��
			break;
		}	
	}
}	