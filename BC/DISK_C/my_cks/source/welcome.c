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

	//mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);

		if(mouse_press(515, 490, 650, 540)==1)
        {
            DestroyUList(&UL);
			user_register();//����ע��ҳ��
            //return����⿪ʼ

            ReadAllUser(&UL);
            mouse_off_arrow(&mouse);
            Readbmp64k(0, 0, "bmp\\city.bmp");//���ҳ�����
	        draw_basic();
	        mouse_on_arrow(mouse);
		}
        else if(mouse_press(950, 25, 1000, 75)==1)
        {
            CloseSVGA();//�ر�SVGA��ͼ����
            exit(100);
        }
        else if(mouse_press(350, 330, 650, 380)==1)//����˺ſ� 
		{
			input_mode(name,code,judge1, 355, 335, 645, 375,1,1);
		}
        else if(mouse_press(350, 410, 650, 460)==1)//�������� 
		{
			input_mode(name,code,judge1, 355, 415, 645, 455,2,1);
		}
        else if(mouse_press(350, 490, 485, 540)==1)//�����¼
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
                draw_basic();
                mouse_on_arrow(mouse);

                for (i = 0; i < sizeof(name); i++) name[i] = '\0';
                for (i = 0; i < sizeof(code); i++) code[i] = '\0';
                for (i = 0; i < sizeof(judge1); i++) judge1[i] = '\0';
			}
			if(current==-2)//����������� 
			{
				PrintCC(430,550,"�������",HEI,24,1,lightred);
                delay(500);
				bar1(430,550,580,580,white);
			}
			if(current==-3)//�û������� 
			{
				PrintCC(430,550,"�û�������",HEI,24,1,lightred);
                delay(500);
				bar1(430,550,580,580,white);
			} 
		delay(15);
	    }
    }
}

void draw_basic()
{
    Readbmp64k(0, 0, "bmp\\city.bmp");//

    Fill_Rounded_Rectangle(310, 200, 690, 580, 25,white);//��ɫ
    
    Fill_Rounded_Rectangle(350, 330, 650, 380, 5,lightgrew);//�˺�����ɫ
    Fill_Rounded_Rectangle(350, 410, 650, 460, 5,lightgrew);//��������ɫ

    Fill_Rounded_Rectangle(350, 490, 485, 540, 5,0x435c);//��¼��ť//��185����50
    Draw_Rounded_Rectangle(515, 490, 650, 540, 5,1,0x0235);//ע�ᰴť//Բ�Ƿ������֣�x65��y+13
    

    PrintCC(355,245,"У԰�������ƽ̨",HEI,32,1,0);
    PrintCC(355,285,"���ڻ��пƼ���ѧУ԰����",HEI,16,1,0XC618);
    PrintCC(355,345,"�˺�",HEI,24,1,deepgrew);
    PrintCC(355,425,"����",HEI,24,1,deepgrew);
    PrintCC(390,503,"��¼",HEI,24,1,0xFFFF);
    PrintCC(555,503,"ע��",HEI,24,1,0x0235);
    PrintCC(750,50,"��������",HEI,16,1,white);
    PrintCC(900,50,"���ڲ�Ʒ",HEI,16,1,white);

}
