#include "all_func.h"

int welcome() {

    int i;//ѭ������

    char name[12]="\0";//�û���
	char code[12]="\0";//����
    char judge[12]="\0";//�����жϵ�����
    int result=-5;//�жϵ�½���,-5��ʾδ��¼,-2��ʾ�������-3��ʾ�û������ڣ�>=0��ʾ��¼�ɹ��������û�λ��

    int state=0;//�ж��Ƿ��ڵ�¼ע�����

    UserList UL={0};
	ReadAllUser(&UL);

	mouse_off_arrow(&mouse);
	
	draw_basic();

	mouse_on_arrow(mouse);

	while(1){
		mouse_show_arrow(&mouse);
        
        if(state==0)//�ڵ�¼ע�����
        {
            if(mouse_press(515, 490, 650, 540)==1)//���ע��
            {
                DestroyUList(&UL);//�������Ա�
                user_register();//����ע��ҳ��
                //return����⿪ʼ
    
                ReadAllUser(&UL);//���¶�ȡ�û���Ϣ
                mouse_off_arrow(&mouse);
                draw_basic();
                mouse_on_arrow(mouse);
            }
            else if(mouse_press(750,50,850,100)==1)
            {
                draw_about_us();//��������
                state=1;
            }
            else if(mouse_press(900,50,950,100)==1)
            {
                draw_about_product();//���ڲ�Ʒ
                state=1;
            }
            else if(mouse_press(350, 330, 650, 380)==1)//����˺ſ� 
            {
                input_mode(name,code,judge, 355, 335, 645, 375,1,1);//�����˺�
            }
            else if(mouse_press(350, 410, 650, 460)==1)//�������� 
            {
                input_mode(name,code,judge, 355, 415, 645, 455,2,1);//��������
            }
            else if(mouse_press(350, 490, 485, 540)==1)//�����¼
            {
                result=Check_info(UL,name,code);//�ж��˺������Ƿ���ȷ
                
                if(result >= 0)
                {
                    int user_type = UL.elem[result].type; // ��ȡ�û�����
                    users.pos=result  ;//��¼�û�λ��

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
                    
                    // ������������
                    for (i = 0; i < sizeof(name); i++) name[i] = '\0';
                    for (i = 0; i < sizeof(code); i++) code[i] = '\0';
                    for (i = 0; i < sizeof(judge); i++) judge[i] = '\0';
                }
                if(result ==-2)//����������� 
                {
                    PrintCC(430,550,"�������",HEI,24,1,lightred);
                    delay(500);
                    bar1(430,550,580,580,white);
                }
                if(result ==-3)//�û������� 
                {
                    PrintCC(430,550,"�û�������",HEI,24,1,lightred);
                    delay(500);
                    bar1(430,550,580,580,white);
                } 
            delay(15);
            }

        }

        if(state==1)
        {
            if(mouse_press(750,50,850,100)==1)
            {
                draw_about_us();//��������
                state=1;
            }
            else if(mouse_press(900,50,950,100)==1)
            {
                draw_about_product();//���ڲ�Ʒ
                state=1;
            }
            else if(mouse_press(700, 225,720,245)==1)
            {
                mouse_off_arrow(&mouse);
                draw_basic();//���ص�¼����
                mouse_on_arrow(mouse);
                state=0;
            }
        }
    }
}


void draw_basic()
{
    Readbmp64k(0, 0, "bmp\\city.bmp");

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


void draw_about_us() 
{
	Fill_Rounded_Rectangle(250, 200, 750, 580, 30, white); // ������

    Line_Thick(700, 225, 720, 245, 1, black);//"x"
    Line_Thick(700, 245, 720, 225, 1, black);//

    PrintText(270, 225, "��ϵ����", HEI, 32, 1, 0x0000); // ���⣨��ɫ��

    PrintText(270, 300, "��ϵͳ�ɻ��пƼ���ѧ�˹��������Զ���", HEI, 24, 1, 0x0000);
    PrintText(270, 330, "ѧԺ����2402��Ĳ���������Ӻ���ɡ�", HEI, 24, 1, 0x0000);
    PrintText(270, 360, "�������Ҫ����������ֶ˱�д��·��", HEI, 24, 1, 0x0000);
    PrintText(270, 390, "�滮���������Ӻ���Ҫ��������û���", HEI, 24, 1, 0x0000);
    PrintText(270, 420, "�̼���Ϣ�洢������չʾ����", HEI, 24, 1, 0x0000);
    PrintText(270, 450, "�������⣬����ϵ��", HEI, 24, 1, 0x0000);
    PrintText(270, 480, "�����  2960473693", HEI, 24, 1, 0x0000);
    PrintText(270, 510, "���Ӻ�  2496100220", HEI, 24, 1, 0x0000);
}
void draw_about_product() 
{
    Fill_Rounded_Rectangle(250, 200, 750, 580, 30, white); // ������

    Line_Thick(700, 225, 720, 245, 1, black);//"X"
    Line_Thick(700, 245, 720, 225, 1, black);//

    PrintText(270, 225, "��Ʒ����", HEI, 32, 1, 0x0000); // ���⣨��ɫ��

    PrintText(270, 300, "��ϵͳģ����У԰���������ͳ��й�����", HEI, 24, 1, 0x0000);
    PrintText(270, 330, "�ͼ���ݴ�ȡ���������̣������û�ע��", HEI, 24, 1, 0x0000);
    PrintText(270, 360, "������̼ҹ�������������������", HEI, 24, 1, 0x0000);
    PrintText(270, 390, "�ȹ��ܡ�ͨ�����������ѡȡ��ϵͳ���", HEI, 24, 1, 0x0000);
    PrintText(270, 420, "��ϵͳ��ΪУ԰�ڵ�ѧ������ʦ��ʳ�ü�", HEI, 24, 1, 0x0000);
    PrintText(270, 450, "�����̼ҡ��������ֵ��ṩһ�廯������", HEI, 24, 1, 0x0000);
    PrintText(270, 480, "���������ͷ��񡣽������·���Ż�����", HEI, 24, 1, 0x0000);
    PrintText(270, 510, "��ϵͳ�ܹ��������Ч�ʣ��������ͳɱ�", HEI, 24, 1, 0x0000);
    PrintText(270, 540, "���϶����ļ�ʱ�ʹ", HEI, 24, 1, 0x0000);
}

