#include "all_func.h"

Shop shops={0};//�洢��Ϣ���̵�ṹ�� 

void user(){
    
    mouse_off_arrow(&mouse);
	
	draw_user();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(40, 113, 160, 163)==1)
        {
			welcome();//��ҳ
		}
        else if(mouse_press(40, 276, 160, 326)==1)
        {
            draw_choice();
            while(1){
                mouse_show_arrow(&mouse);

                if(mouse_press(200, 202, 430, 264)==1){
                    shops.type=1;
                    break;
                }else if(mouse_press(200, 266, 430, 334)==1){
                    shops.type=2;
                    break;
                }else if(mouse_press(200, 336, 430, 400)==1){
                    shops.type=3;
                    break;
                }
            }
            user_shop();//�û�����ҳ��           
        }
        else if(mouse_press(40, 439, 160, 489)==1)
        {
            press1(2);//��������ҳ��
            user_takeout();//�û�����ҳ�� 
            break;
        }
        else if(mouse_press(40, 602, 160, 652)==1)
        {
            press1(3);//������ҳ��
            user_deliver();//�û����ҳ��  
            break;
        }
        else if(mouse_press(430, 105, 650, 155)==1)
        {
            number_mode(users.number, 435, 110, 645, 150);//�����ֻ���
        }
        else if(mouse_press(710, 105, 830, 155)==1)
        {
            if(strlen(users.number)==11)
            {
                save_user(users);
                PrintCC(800,50,"����ɹ�",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,1024,100,snow);
            }
            else
            {
                PrintCC(800,50,"���Ȳ��Ϸ�",HEI,24,1,lightred);
                delay(500);
                bar1(800,50,1024,100,snow);
            }
        }
        else if(mouse_press(440, 180, 560, 230)==1)
        {
            press1(4);//��ݿ
            users.address=1;
            save_user(users);
        }
        else if(mouse_press(620, 180, 740, 230)==1)
        {
            press1(5);//��Է
            users.address=2;
            save_user(users);
        }
        else if(mouse_press(800, 180, 920, 230)==1)
        {
            press1(6);//��Է
            users.address=3;
            save_user(users);
        }
    }
}

void draw_user()
{
    bar1(0, 0, 1024, 768,0xFFFF);
    bar1(0, 0, 200, 768,0x0235);

    Fill_Rounded_Rectangle(40, 113, 160, 163, 25,white);//��ɫ
    Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);//��ɫ
    Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);//��ɫ
    Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);//��ɫ

    Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1,deepblue);//���ذ�ť
    Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);//���а�ť
    Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);//������ť
    Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);//��ݰ�ť
    Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,deepblue);//��ݿ��ť
    Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,deepblue);//��Է��ť
    Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,deepblue);//��Է��ť

    Draw_Rounded_Rectangle(430, 105, 650, 155, 5, 1,deepblue);//�ֻ�������� 
    Draw_Rounded_Rectangle(710, 105, 830, 155, 25, 1,deepblue);//���水ť

    PrintCC(75,128,"����",HEI,24,1,deepblue);
    PrintCC(75,291,"����",HEI,24,1,deepblue);
    PrintCC(75,454,"����",HEI,24,1,deepblue);
    PrintCC(75,617,"���",HEI,24,1,deepblue);
    PrintCC(475,195,"��ݿ",HEI,24,1,deepblue);
    PrintCC(655,195,"��Է",HEI,24,1,deepblue);
    PrintCC(835,195,"��Է",HEI,24,1,deepblue);
    PrintCC(745,120,"����",HEI,24,1,deepblue);

    PrintCC(250,50,"��ǰ�˺�����Ϊ���û�",HEI,24,1,deepblue);
    PrintCC(250,120,"�������ֻ��ţ�",HEI,24,1,deepblue);
    PrintCC(250,190,"��ѡ��סַ��",HEI,24,1,deepblue);
    
    Readbmp64k(201, 257, "bmp\\map.bmp");
    
}

void draw_choice(){
    Fill_Rounded_Rectangle(200, 202, 430, 400, 30,snow);//��ɫ
    Draw_Rounded_Rectangle(200, 202, 430, 400, 30, 2,deepblue);//����Χ��ɫԲ�Ǿ���

    Line_Thick(220, 265, 400, 265, 1,deepblue);
    Line_Thick(220, 335, 400, 335, 1,deepblue);
    
    PrintCC(240,225,"��ݿ��԰����",HEI,24,1,deepblue);
    PrintCC(240,290,"��Է��԰����",HEI,24,1,deepblue);
    PrintCC(240,355,"��Է��԰����",HEI,24,1,deepblue);

}

void press1(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    {
        case 1:{
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25,deepblue);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291,"����",HEI,24,1,white);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454,"����",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617,"���",HEI,24,1,deepblue);
            break;
        }
        case 2:{
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291,"����",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25,deepblue);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454,"����",HEI,24,1,white);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617,"���",HEI,24,1,deepblue);
            break;
        }
        case 3:{
            Fill_Rounded_Rectangle(40, 276, 160, 326, 25,white);
            Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
            PrintCC(75,291,"����",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);
            Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
            PrintCC(75,454,"����",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(40, 602, 160, 652, 25,deepblue);
            Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
            PrintCC(75,617,"���",HEI,24,1,white);
            break;
        }
        case 4:{
            Fill_Rounded_Rectangle(440, 180, 560, 230, 25, deepblue);
            Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,white);
            PrintCC(475,195,"��ݿ",HEI,24,1,white);
            Fill_Rounded_Rectangle(620, 180, 740, 230, 25, white);
            Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,deepblue);
            PrintCC(655,195,"��Է",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(800, 180, 920, 230, 25, white);
            Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,deepblue);
            PrintCC(835,195,"��Է",HEI,24,1,deepblue);
            break;
        }
        case 5:{
            Fill_Rounded_Rectangle(440, 180, 560, 230, 25, white);
            Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,deepblue);
            PrintCC(475,195,"��ݿ",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(620, 180, 740, 230, 25, deepblue);
            Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,white);
            PrintCC(655,195,"��Է",HEI,24,1,white);
            Fill_Rounded_Rectangle(800, 180, 920, 230, 25, white);
            Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,deepblue);
            PrintCC(835,195,"��Է",HEI,24,1,deepblue);
            break;  
        }
        case 6:{
            Fill_Rounded_Rectangle(440, 180, 560, 230, 25, white);
            Draw_Rounded_Rectangle(440, 180, 560, 230, 25, 1,deepblue);
            PrintCC(475,195,"��ݿ",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(620, 180, 740, 230, 25, white);
            Draw_Rounded_Rectangle(620, 180, 740, 230, 25, 1,deepblue);
            PrintCC(655,195,"��Է",HEI,24,1,deepblue);
            Fill_Rounded_Rectangle(800, 180, 920, 230, 25, deepblue);
            Draw_Rounded_Rectangle(800, 180, 920, 230, 25, 1,white);
            PrintCC(835,195,"��Է",HEI,24,1,white);
            break;
        }
    }
    mouse_on_arrow(mouse);
}

void number_mode(char *number,int bar_x1,int bar_y1,int bar_x2,int bar_y2)
{
	int length;
	char showtemp[2]= "\0";//�洢�����ַ�,���������չʾ
	int i=0,k,temp;  // iΪ�ַ�����,tempΪ�Ӽ����϶�ȡ�����ַ���ACSII��
	int border; //���ĺ�����	    
	int x1,y1;
	x1=bar_x1+4;
	y1=bar_y1+5;//��������������ƫ����
	border=x1+4;//ÿ���ַ�ռ8������,ÿ����һ���ַ��������8������
	
    if(number[0]=='\0') //����˺�Ϊ�գ�����ʾ�����
        bar1(bar_x1, bar_y1, bar_x2, bar_y2,0xFFFF);
    else
    {            //��궨λ���ı�ĩβ
        length=strlen(number);
        i=length;
        border+=8*i;
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
				if(('0'<=temp&&temp<='9')&& i <11)//���Ϊ���ֻ���ĸ�����¼
				{
					hide_cursor(border,y1); //����ԭ���
					
					number[i]=temp;//�ַ���������ַ��������ڱ����û���Ϣ
								
					*showtemp=temp;  //tempת��Ϊ�ַ���
					PrintText(border,y1-2,showtemp,HEI,16,1,0); //��ʾ�µ��ַ����ﵽ������ʵ�������ͬ��
					i++;	//�ַ���������
					
					number[i]='\0';//����ַ�����β
							
					border+=8;	//������������8����
					draw_cursor(border,y1);
				}
				else if(temp=='\b'&&i>0)  //����Ƿ�Ϊ�˸������������ǰһ���ַ�
				{
					hide_cursor(border,y1);	//����ԭ���
					border-=8;	//�������8����
					i--;	//�ַ������Լ�
				
					number[i]='\0';//���洢���ַ���0����
					
					bar1(border,y1,border+8, y1+16, 0xffff);	//���ԭ�ַ�
					draw_cursor(border,y1);
				}
				else if(i>=11)
				{
					mouse_off_arrow(&mouse);
					mouse_show_arrow(&mouse);
					PrintCC(750,50,"���ȳ�������",HEI,24,1,lightred);
					delay(500);
					bar1(750,50,900,75,snow);
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
			
	// hide_cursor(border,y1);	//���ع��
	}
}	