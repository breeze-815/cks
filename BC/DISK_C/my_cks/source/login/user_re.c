#include "all_func.h"
//��Ļ���1024���߶�768
USER users={0};//�洢��Ϣ���û��ṹ�� 

void user_register(){
    
	char judge[12]="\0";//�����жϵ����� 

    users.state=-1;//��ʼ��Ϊ-1������δ��

	mouse_off_arrow(&mouse);
	
	draw_register();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(300,490, 480, 540)==1){
            return;
            //welcome();//��ҳ
		}
        else if(mouse_press(300, 250, 420, 300)==1)
        {
            press(1);//����"�û�"
            users.type=1;
        }
        else if(mouse_press(300, 330, 420, 380)==1)
        {
            press(2);//����"�̼�"
            users.type=2;
        }
        else if(mouse_press(300, 410, 420, 460)==1)
        {
            press(3);//����"����"
            users.type=3;
        }
        else if(mouse_press(450, 250, 700, 300)==1)//�����˺�
        {
            input_mode(users.name,users.code,judge,455,255,695,295,1,0);
		}
        else if(mouse_press(450, 330, 700, 380)==1)//��������
        {   
			input_mode(users.name,users.code,judge,455,335,695,375,2,0);
		}
		else if(mouse_press(450, 410, 700, 460)==1)//������������
        {   
			input_mode(users.name,users.code,judge,455,415,695,455,3,0);
		}
        if(mouse_press(520, 490, 700, 540)==1)//���ȷ�ϼ�
        {   
            if(users.type!=0)
            {
			    if(strcmp(users.name,"\0")!=0)//�û�����Ϊ�� 
                {
				    if(strcmp(users.code,"\0")!=0)//���벻Ϊ�� 
                    {
					    if(!strcmp(users.code,judge))//����������ͬ 
                        {
				            if(save_user(users)==0)
                            {
                                PrintCC(430,550,"ע��ɹ�",HEI,24,1,lightred);
                                delay(500);
                                bar1(430,550,650,580,white);
                            }
                            else if(save_user(users)==-2)//�û����Ѵ���
                            {
                                PrintCC(430,550,"�û����ѱ�ע��",HEI,24,1,lightred);
                                delay(500);
                                bar1(430,550,650,580,white);
                            }
			            }
			            else
			            {
                            PrintCC(430,550,"�������벻��ͬ",HEI,24,1,lightred);
                            delay(500);
                            bar1(430,550,650,580,white);
			            }  
				    }
				    else
				    {
					    PrintCC(430,550,"����Ϊ��",HEI,24,1,lightred);
                        delay(500);
                        bar1(430,550,650,580,white);
				    }	
			    }
			    else
			    {
				    PrintCC(430,550,"�û���Ϊ��",HEI,24,1,lightred);
                    delay(500);
				    bar1(430,550,650,580,white);
			    }	
            }
            else
            {
                PrintCC(430,550,"δѡ���û�����",HEI,24,1,lightred);
                delay(500);
                bar1(430,550,650,580,white);
            }
		}
    }
}
void draw_register()
{
    Readbmp64k(0, 0, "bmp\\city.bmp");

    Fill_Rounded_Rectangle(250, 200, 750, 580, 30,snow);//��ɫ

    Fill_Rounded_Rectangle(450, 250, 700, 300, 5,lightgrew);//�˺�����ɫ
    Fill_Rounded_Rectangle(450, 330, 700, 380, 5,lightgrew);//��������ɫ
    Fill_Rounded_Rectangle(450, 410, 700, 460, 5,lightgrew);//ȷ����������ɫ

    Draw_Rounded_Rectangle(300, 250, 420, 300, 25, 1,0x0235);//�û���ť
    Draw_Rounded_Rectangle(300, 330, 420, 380, 25, 1,0x0235);//�̼Ұ�ť
    Draw_Rounded_Rectangle(300, 410, 420, 460, 25, 1,0x0235);//���ְ�ť
    
    Fill_Rounded_Rectangle(300,490, 480, 540, 5,0x435c);//���ذ�ť
    Draw_Rounded_Rectangle(520, 490, 700, 540, 5,1,0x0235);//����ע�ᰴť
    
    PrintCC(455,265,"�˺�",HEI,24,1,0XC618);
    PrintCC(455,345,"����",HEI,24,1,0XC618);
    PrintCC(455,425,"ȷ������",HEI,24,1,0XC618);
    PrintCC(360,503,"����",HEI,24,1,0xFFFF);
    PrintCC(560,503,"����ע��",HEI,24,1,0x0235);
    PrintCC(335,265,"�û�",HEI,24,1,0x0235);
    PrintCC(335,345,"�̼�",HEI,24,1,0x0235);
    PrintCC(335,425,"����",HEI,24,1,0x0235);
}

void press(int x){
    mouse_off_arrow(&mouse);
    switch (x)
    {
        case 1:{
            Fill_Rounded_Rectangle(300, 250, 420, 300, 25,0x0235);
            Draw_Rounded_Rectangle(300, 250, 420, 300, 25, 1,0x0235);
            PrintCC(335,265,"�û�",HEI,24,1,0xFFFF);
            Fill_Rounded_Rectangle(300, 330, 420, 380, 25,0xFFFF);
            Draw_Rounded_Rectangle(300, 330, 420, 380, 25, 1,0x0235);
            PrintCC(335,345,"�̼�",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(300, 410, 420, 460, 25,0xFFFF);
            Draw_Rounded_Rectangle(300, 410, 420, 460, 25, 1,0x0235);
            PrintCC(335,425,"����",HEI,24,1,0x0235);
            break;
        }
        case 2:{
            Fill_Rounded_Rectangle(300, 250, 420, 300, 25,0xFFFF);
            Draw_Rounded_Rectangle(300, 250, 420, 300, 25, 1,0x0235);
            PrintCC(335,265,"�û�",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(300, 330, 420, 380, 25,0x0235);
            Draw_Rounded_Rectangle(300, 330, 420, 380, 25, 1,0x0235);
            PrintCC(335,345,"�̼�",HEI,24,1,0xFFFF);
            Fill_Rounded_Rectangle(300, 410, 420, 460, 25,0xFFFF);
            Draw_Rounded_Rectangle(300, 410, 420, 460, 25, 1,0x0235);
            PrintCC(335,425,"����",HEI,24,1,0x0235);
            break;
        }
        case 3:{
            Fill_Rounded_Rectangle(300, 250, 420, 300, 25,0xFFFF);
            Draw_Rounded_Rectangle(300, 250, 420, 300, 25, 1,0x0235);
            PrintCC(335,265,"�û�",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(300, 330, 420, 380, 25,0xFFFF);
            Draw_Rounded_Rectangle(300, 330, 420, 380, 25, 1,0x0235);
            PrintCC(335,345,"�̼�",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(300, 410, 420, 460, 25,0x0235);
            Draw_Rounded_Rectangle(300, 410, 420, 460, 25, 1,0x0235);
            PrintCC(335,425,"����",HEI,24,1,0xFFFF);
            break;
        }
    }
    mouse_on_arrow(mouse);
}
