#include "all_func.h"
//��Ļ���1024���߶�768


int welcome() {
    int i;

    char name[12]="\0";
	char code[12]="\0";
    char judge1[12]="\0";//�����жϵ�����
    int current=-5;//�жϵ�½���,-5��ʾδ��¼,-2��ʾ�������-3��ʾ�û������ڣ�>=0��ʾ��¼�ɹ��������û�λ��

    UserList UL={0};
	ReadAllUser(&UL);

	mouse_off_arrow(&mouse);
	
	draw_basic();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(515, 490, 700, 540)==1)
        {
            DestroyUList(&UL);
			user_register();//����ע��ҳ��
            //return����⿪ʼ

            ReadAllUser(&UL);
            mouse_off_arrow(&mouse);
            bar1(0, 0, 1024, 768, white); // ���ע��������
	        draw_basic();
	        mouse_on_arrow(mouse);
		}
        else if(mouse_press(950, 25, 1000, 75)==1)
        {
            CloseSVGA();//�ر�SVGA��ͼ����
            exit(100);
        }
        else if(mouse_press(300, 330, 700, 380)==1)//����˺ſ� 
		{
			input_mode(name,code,judge1, 305, 335, 695, 375,1,1);
		}
        else if(mouse_press(300, 410, 700, 460)==1)//�������� 
		{
			input_mode(name,code,judge1, 305, 415, 695, 455,2,1);
		}
        else if(mouse_press(300,490, 485, 540)==1)//�����¼
        {
            current=Check_info(UL,name,code);
            
            if(current>=0)
			{
                int user_type = UL.elem[current].type; // ��ȡ�û�����
                users.pos=current;//��¼�û�λ��

                DestroyUList(&UL);//�������Ա�

                // �����û�������ת����ͬ���棬�������û�λ��
                if (user_type == 1) 
                {
                    user(users.pos); // �û�ҳ��
                } 
                else if (user_type == 2) 
                {
                    business(users.pos); // �̼�ҳ��
                } 
                else if (user_type == 3) 
                {
                    rider(users.pos); // ����ҳ��
                }
                //return����⿪ʼ
                ReadAllUser(&UL);
                mouse_off_arrow(&mouse);
                bar1(0, 0, 1024, 768, white); // ���ע��������
                draw_basic();
                mouse_on_arrow(mouse);

                for (i = 0; i < sizeof(name); i++) name[i] = '\0';
                for (i = 0; i < sizeof(code); i++) code[i] = '\0';
                for (i = 0; i < sizeof(judge1); i++) judge1[i] = '\0';
			}
			if(current==-2)//����������� 
			{
				PrintCC(430,560,"�������",HEI,24,1,0XF800);
                delay(500);
				bar1(430,560,580,590,snow);
			}
			if(current==-3)//�û������� 
			{
				PrintCC(430,560,"�û�������",HEI,24,1,0XF800);
                delay(500);
				bar1(430,560,580,590,snow);
			} 
		delay(15);
	    }
    }
}

void draw_basic()
{
    bar1(0, 0, 1024, 768,0xFFFF);

    //Readbmp64k(0, 0, "bmp\\hust.bmp");//��ȡ����ͼƬ
    //Readbmp64k(0, 0, "bmp\\windows.bmp");//

    //Fill_Rounded_Rectangle(200, 148, 824, 600, 30,snow);//��ɫ
    Draw_Rounded_Rectangle(200, 148, 824, 600, 30, 2,0x6B4D);//����Χ��ɫԲ�Ǿ���
    
    Draw_Rounded_Rectangle(300, 330, 700, 380, 5, 1,0xB71C);//�˺���Բ�Ǿ���
    Draw_Rounded_Rectangle(300, 410, 700, 460, 5, 1,0xB71C);//������Բ�Ǿ���
    Fill_Rounded_Rectangle(300,490, 485, 540, 5,0x435c);//��¼��ť//��185����50
    Draw_Rounded_Rectangle(515, 490, 700, 540, 5,1,0x0235);//ע�ᰴť//Բ�Ƿ������֣�x65��y+13
    Draw_Rounded_Rectangle(950, 25, 1000, 75, 5,1,0x0235);//�رհ�ť

    PrintCC(305,225,"У԰�������ƽ̨",HEI,48,1,0);
    PrintCC(305,345,"�˺�",HEI,24,1,0XC618);
    PrintCC(305,425,"����",HEI,24,1,0XC618);
    PrintCC(365,503,"��¼",HEI,24,1,0xFFFF);
    PrintCC(580,503,"ע��",HEI,24,1,0x0235);
    //PrintText(100,100,"chp123",HEI,16,1,0XC618);
    //Circlefill(50,50,3,0);
}
