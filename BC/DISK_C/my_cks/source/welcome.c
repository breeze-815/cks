#include "all_func.h"
//��Ļ���1024���߶�768


int welcome(int *page){

    char name[10]="\0";
	char code[10]="\0";
    char judge1[10]="\0";//�����жϵ�����
    int i=-5;

    UserList UL={0};
	InitUList(&UL);
	ReadAllUser(&UL);
	mouse_off(&mouse);
	
	draw_basic();

	mouse_on(mouse);

	while(1){
		mouse_show(&mouse);

		if(mouse_press(515, 490, 700, 540)==1)
        {
			*page=1;//����ע�����
			break;
		}
        else if(mouse_press(300, 330, 700, 380)==1)//����˺ſ� 
		{
			Get_account(305, 336,name,judge1, 305, 335, 695, 375);
		}
        else if(mouse_press(300, 410, 700, 460)==1)//�������� 
		{
			Get_code(305, 416,code,judge1, 305, 415, 695, 455);
		}
        else if(mouse_press(300,490, 485, 540)==1)//�����¼
        {
            i=Check_info(UL,name,code);
            if(i>=0)
			{
				//*unum=i;
				DestroyUList(&UL);
				*page=2;      //����������
                break;
			}
			if(i==-2)//����������� 
			{
				PrintCC(570,575,"�������",HEI,24,1,0XF800);
			    delay(1500);
				bar1(570,550,690,574,0xffff);
			}
			if(i==-3)//�û������� 
			{
				PrintCC(570,575,"�û�������",HEI,24,1,0XF800);
			    delay(1500);
				bar1(570,550,570+144,574,0xffff);
			} 
		delay(15);
	    }
    }
}

void draw_basic()
{
    bar1(0, 0, 1024, 768,0xFFFF);

    Fill_Rounded_Rectangle(200, 148, 824, 600, 30,0xFFDF);//��ɫ
    Draw_Rounded_Rectangle(200, 148, 824, 600, 30, 2,0x6B4D);//����Χ��ɫԲ�Ǿ���
    
    Draw_Rounded_Rectangle(300, 330, 700, 380, 5, 1,0xB71C);//�˺���Բ�Ǿ���
    Draw_Rounded_Rectangle(300, 410, 700, 460, 5, 1,0xB71C);//������Բ�Ǿ���
    Fill_Rounded_Rectangle(300,490, 485, 540, 5,0x435c);//��¼��ť
    Draw_Rounded_Rectangle(515, 490, 700, 540, 5,1,0x0235);//ע�ᰴť
    PrintCC(305,225,"У԰�������ƽ̨",HEI,48,1,0);
    PrintCC(305,345,"�˺�",HEI,24,1,0XC618);
    PrintCC(305,425,"����",HEI,24,1,0XC618);
    PrintCC(365,503,"��¼",HEI,24,1,0xFFFF);
    PrintCC(580,503,"ע��",HEI,24,1,0x0235);
    PrintText(100,100,"chp123",HEI,16,1,0XC618);
    Circlefill(50,50,3,0);
}
