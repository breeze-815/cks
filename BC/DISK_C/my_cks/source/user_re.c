#include "all_func.h"
//��Ļ���1024���߶�768
int user_register(int *page){
    struct USER temp={0};//�洢��Ϣ���û��ṹ�� 
	char judge[10]="\0";//�����жϵ�����

	mouse_off(&mouse);
	
	draw_register();

	mouse_on(mouse);

	while(1){
		mouse_show(&mouse);

		if(mouse_press(450,490, 635, 540)==1){
			*page=0;//����
			break;
		}
        else if(mouse_press(230, 250, 350, 300)==1)
        {
            press(1);//����"�û�"
        }
        else if(mouse_press(230, 330, 350, 380)==1)
        {
            press(2);//����"�̼�"
        }
        else if(mouse_press(230, 410, 350, 460)==1)
        {
            press(3);//����"����"
        }
        else if(mouse_press(450, 250, 850, 300)==1)//�����˺�
        {
            bar1(455, 255, 845, 295,0xFFFF);
            strcpy(temp.name,"\0");
            //cursor(455,260);
            Getinfo(455,260,temp.name,10,455,260,845,295);
		}
        else if(mouse_press(450, 330, 850, 380)==1)//��������
        {   
			mouse_off(&mouse);
			bar1(455, 335, 845, 375,0xffff);
			strcpy(temp.code,"\0");
			Getcode(455,340,temp.code,10,450, 330, 850, 380);
			mouse_on(mouse);
		}
		else if(mouse_press(450, 410, 850, 460)==1)//������������
        {   
			mouse_off(&mouse);
			bar1(455, 415, 845, 455,0xffff);
			strcpy(judge,"\0");
			Getcode(455,420,judge,10,450, 410, 850, 460);
			mouse_on(mouse);
		}if(mouse_press(665, 490, 850, 540)==1)//���ȷ�ϼ�
        {     
			if(strcmp(temp.name,"\0")!=0)//�û�����Ϊ�� 
            {
				if(strcmp(temp.code,"\0")!=0)//���벻Ϊ�� 
                {
					if(!strcmp(temp.code,judge))//����������ͬ 
                    {
				      if(save_user(temp)==0)
                      {
                        *page=2;
				        break;
                      }
                      else
                      {
                        PrintCC(570,575,"�û����ѱ�ע��",HEI,24,1,0XF800);
                        delay(1500);
				        bar1(570,575,800,600,0xffff);
                      }
			        }
			        else
			        {
                        PrintCC(570,575,"�������벻��ͬ",HEI,24,1,0XF800);
				        delay(1500);
				        bar1(570,575,800,600,0xffff);
			        }  
				}
				else
				{
					PrintCC(570,575,"����Ϊ��",HEI,24,1,0XF800);
				    delay(1500);
				    bar1(570,575,800,600,0xffff);
				}	
			}
			else
			{
				PrintCC(570,575,"�û���Ϊ��",HEI,24,1,0XF800);
				delay(1500);
				bar1(570,575,800,600,0xffff);
			}	
		}
    }
}
void draw_register()
{
    bar1(0, 0, 1024, 768,0xFFFF);

    Fill_Rounded_Rectangle(100, 108, 924, 640, 30,0xFFDF);//��ɫ
    Draw_Rounded_Rectangle(100, 108, 924, 640, 30, 2,0x6B4D);//����Χ��ɫԲ�Ǿ���

    Draw_Rounded_Rectangle(450, 250, 850, 300, 5, 1,0xB71C);//�˺���Բ�Ǿ���
    Draw_Rounded_Rectangle(450, 330, 850, 380, 5, 1,0xB71C);//������Բ�Ǿ���
    Draw_Rounded_Rectangle(450, 410, 850, 460, 5, 1,0xB71C);//ȷ��������Բ�Ǿ���

    Draw_Rounded_Rectangle(230, 250, 350, 300, 25, 1,0x0235);//�û�
    Draw_Rounded_Rectangle(230, 330, 350, 380, 25, 1,0x0235);//�̼�
    Draw_Rounded_Rectangle(230, 410, 350, 460, 25, 1,0x0235);//����
    
    Fill_Rounded_Rectangle(450,490, 635, 540, 5,0x435c);//���ذ�ť
    Draw_Rounded_Rectangle(665, 490, 850, 540, 5,1,0x0235);//����ע�ᰴť
    
    PrintCC(455,265,"�˺�",HEI,24,1,0XC618);
    PrintCC(455,345,"����",HEI,24,1,0XC618);
    PrintCC(455,425,"ȷ������",HEI,24,1,0XC618);
    PrintCC(515,503,"����",HEI,24,1,0xFFFF);
    PrintCC(710,503,"����ע��",HEI,24,1,0x0235);
    PrintCC(265,265,"�û�",HEI,24,1,0x0235);
    PrintCC(265,345,"�̼�",HEI,24,1,0x0235);
    PrintCC(265,425,"����",HEI,24,1,0x0235);
}

void press(int x){
    mouse_off(&mouse);
    switch (x)
    {
        case 1:{
            Fill_Rounded_Rectangle(230, 250, 350, 300, 25,0x0235);
            Draw_Rounded_Rectangle(230, 250, 350, 300, 25, 1,0x0235);
            PrintCC(265,265,"�û�",HEI,24,1,0xFFFF);
            Fill_Rounded_Rectangle(230, 330, 350, 380, 25,0xFFFF);
            Draw_Rounded_Rectangle(230, 330, 350, 380, 25, 1,0x0235);
            PrintCC(265,345,"�̼�",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(230, 410, 350, 460, 25,0xFFFF);
            Draw_Rounded_Rectangle(230, 410, 350, 460, 25, 1,0x0235);
            PrintCC(265,425,"����",HEI,24,1,0x0235);
            break;
        }
        case 2:{
            Fill_Rounded_Rectangle(230, 250, 350, 300, 25,0xFFFF);
            Draw_Rounded_Rectangle(230, 250, 350, 300, 25, 1,0x0235);
            PrintCC(265,265,"�û�",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(230, 330, 350, 380, 25,0x0235);
            Draw_Rounded_Rectangle(230, 330, 350, 380, 25, 1,0x0235);
            PrintCC(265,345,"�̼�",HEI,24,1,0xFFFF);
            Fill_Rounded_Rectangle(230, 410, 350, 460, 25,0xFFFF);
            Draw_Rounded_Rectangle(230, 410, 350, 460, 25, 1,0x0235);
            PrintCC(265,425,"����",HEI,24,1,0x0235);
            break;
        }
        case 3:{
            Fill_Rounded_Rectangle(230, 250, 350, 300, 25,0xFFFF);
            Draw_Rounded_Rectangle(230, 250, 350, 300, 25, 1,0x0235);
            PrintCC(265,265,"�û�",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(230, 330, 350, 380, 25,0xFFFF);
            Draw_Rounded_Rectangle(230, 330, 350, 380, 25, 1,0x0235);
            PrintCC(265,345,"�̼�",HEI,24,1,0x0235);
            Fill_Rounded_Rectangle(230, 410, 350, 460, 25,0x0235);
            Draw_Rounded_Rectangle(230, 410, 350, 460, 25, 1,0x0235);
            PrintCC(265,425,"����",HEI,24,1,0xFFFF);
            break;
        }
    }
    mouse_on(mouse);
}
