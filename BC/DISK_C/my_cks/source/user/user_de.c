#include "all_func.h"

Deliver delivers={0};//�洢��Ϣ�Ŀ�ݽṹ��
Station stations[8]={
    {"˳����"},
    {"�ϴ���"},
    {"��ͨ���"},
    {"��ͨ���"},
    {"�������"},
    {"�������"},
    {"Բͨ���"},
    {"�������"}
};

void user_deliver(){
    UserList UL = {0};
    DeliverList DL = {0};
    USER currentUser;
    int last_index=-1;//��¼�ϴ�ѡ��ķ����ṩ��
    int state=0; //�ж��Ƿ���Ҫ������Ϣ

    int cur_index = -1;
    int cur_community=0;
    int returned_index;

    ReadAllUser(&UL); // ��ȡ�û��б�
    ReadAllDeliver(&DL); // ��ȡ�����б�

    currentUser=UL.elem[users.pos];// ��ȡ��ǰ�û���Ϣ

    delivers.id=DL.length+1;// ������
    strcpy(delivers.name, currentUser.name);// �û���
    strcpy(delivers.number, currentUser.number);// �û��ֻ���
    delivers.community=currentUser.community;// �û���ַ
    delivers.building=currentUser.building;// �û�¥��

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

        //
        if(state==0){
            if(mouse_press(440, 35, 660, 85)==1)
            {
                deliver_input(delivers.code, 445, 40, 655, 80); // ����ȡ����
            }
            else if(mouse_press(730, 35, 850, 85)==1)//����ȡ���밴ť
            {
                save_Deliver(delivers);
                PrintCC(750, 120, "����ɹ�", HEI, 24, 1, lightred);
                delay(500);
                bar1(750, 120, 1024, 160, white);
            }
            else if(mouse_press(800, 700, 1000, 750)==1)//������ɶ�����ť
            {
                if (delivers.station == 0) // δѡ������ṩ��
                { 
                    PrintCC(750, 120, "��ѡ������ṩ��", HEI, 24, 1, lightred);
                    delay(500);
                    bar1(750, 120, 1024, 160, white);
                }
                else if(strlen(delivers.code)==0){//δ����ȡ����
                    PrintCC(750, 120, "������ȡ����", HEI, 24, 1, lightred);
                    delay(500);
                    bar1(750, 120, 1024, 160, white);
                }
                else if (currentUser.community == '\0' || strlen(currentUser.number) == 0)// �ж��û���Ϣ�Ƿ�����
                {
                    mouse_off_arrow(&mouse);
                    draw_info();
                    mouse_on_arrow(mouse);
                    state = 1;
                }
                else//������ȷ,������Ϣ
                {
                    strcpy(delivers.time, get_current_time()); // ����ʱ��
                    save_Deliver(delivers);
                    de_order();//���붩��ҳ��
                }

            }
            else if(mouse_press(250,50, 750+185, 325+50)==1)//ѡ������ṩ��
            {
                int index;
                MouseGet(&mouse);
                mouse_off_arrow(&mouse);
                
                index=choose_station(mouse.x, mouse.y, &last_index);

                if(index!=-1)
                {
                    delivers.station=index;//��¼ѡ��ķ����ṩ��
                    save_Deliver(delivers);
                }

                mouse_on_arrow(mouse);
            }
        }
        
        // �����û���Ϣ
        if(state==1)
        {
            if(mouse_press(430, 105, 650, 155)==1)
            {
                number_input(currentUser.number, 435, 110, 645, 150); // �����ֻ���
            }
            else if(mouse_press(710, 105, 830, 155)==1)
            {
                if(strlen(currentUser.number)==11)
                {
                    save_user(currentUser);
                    PrintCC(800,50,"����ɹ�",HEI,24,1,lightred);
                    delay(500);
                    bar1(800,50,950,100,white);
                }
                else
                {
                    PrintCC(800,50,"���Ȳ��Ϸ�",HEI,24,1,lightred);
                    delay(500);
                    bar1(800,50,950,100,white);
                }
            }
            else if(mouse_press(440, 180, 560, 230)==1)
            {
                cur_index = -1;
                press1(4);//��ť״̬�л�
                draw_button(1);
                cur_community=1; 
            
            }
            else if(mouse_press(620, 180, 740, 230)==1)
            {
                cur_index = -1;
                press1(5);//����
                draw_button(2);
                cur_community=2;
            }
            else if(mouse_press(800, 180, 920, 230)==1)
            {
                cur_index = -1;
                press1(6);//����
                draw_button(3);
                cur_community=3;
        
            }
            else if(mouse_press(530, 255, 650, 305)==1)
            {
                cur_index = -1;
                press1(7);//��ݿ
                draw_button(4);
                cur_community=4;
            }
            else if(mouse_press(750, 255, 870, 305)==1)
            {
                cur_index = -1;
                press1(8);//��Է
                draw_button(5);
                cur_community=5;
            }
            else if (mouse_press(200, 310, 1024, 768) == 1) { 
                MouseGet(&mouse);
                mouse_off_arrow(&mouse);
                returned_index = press_button(mouse.x, mouse.y, cur_index, cur_community);//��ȡ��ť���

                currentUser.community = button[returned_index].commmunity;//��ȡ�������

                currentUser.building = button[returned_index].number;//��ȡ¥�ű��

                cur_index = returned_index;//���µ�ǰ��ť���

                save_user(currentUser);//�����û���Ϣ

                mouse_on_arrow(mouse);

                delay(200);
            }

            if(mouse_press(950, 50, 975,75)==1)
            {
                state = 0;
                mouse_off_arrow(&mouse);
                draw_user_deliver();
                mouse_on_arrow(mouse);
            }
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


int choose_station(int x, int y, int* last_index) {
    int i, j;
    int index = -1;
    int station_count = 8;

    for (i = 0; i < 3; i++) {           // ��
        for (j = 0; j < 3; j++) {       // ��
            int x1 = 250 + 250 * j;
            int y1 = 175 + 75 * i;
            int x2 = x1 + 185;
            int y2 = y1 + 50;
            
            index = i * 3 + j;
            if (index >= station_count) break; // ��������������˳�

            

            if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {

                // �ָ���һ����ť
                if (*last_index != -1 && *last_index != index) {
                    int pre_row = *last_index / 3;
                    int pre_col = *last_index % 3;
                    int pre_x1 = 250 + 250 * pre_col;
                    int pre_y1 = 175 + 75 * pre_row;
                    int pre_x2 = pre_x1 + 185;
                    int pre_y2 = pre_y1 + 50;

                    Fill_Rounded_Rectangle(pre_x1, pre_y1, pre_x2, pre_y2, 5, white);
                    Draw_Rounded_Rectangle(pre_x1, pre_y1, pre_x2, pre_y2, 5, 1, deepblue);
                    PrintCC(pre_x1 + 40, pre_y1 + 13, stations[*last_index].name, HEI, 24, 1, deepblue);
                }

                // ��ǰ��ť����
                Fill_Rounded_Rectangle(x1, y1, x2, y2, 5, deepblue);
                Draw_Rounded_Rectangle(x1, y1, x2, y2, 5, 1, deepblue);
                PrintCC(x1 + 40, y1 + 13, stations[index].name, HEI, 24, 1, white);

                *last_index = index;
                return index + 1; // ���ؿ�ݹ�˾��ţ�1~8��
            }
        }
    }
    return -1; // δѡ���κΰ�ť
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
    DL->elem=NULL;
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