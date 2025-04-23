#include "all_func.h"

/**********************
����˵������¼��Ϣ�Ա�У�麯�� 
����˵�����û����Ա��û��������� 
����ֵ˵��:i���û������Ա��е�λ��  -2:������� -3���û������� 
**********************/
int Check_info(UserList UL, char name[12], char code[12]) {
    int i = 0;
    for (i = 0; i < UL.length; i++)
	{
        if (strcmp(UL.elem[i].name, name) == 0) 
		{
            if (strcmp(UL.elem[i].code, code) == 0) 
			{
                return i; // �û��������붼ƥ�䣬�����û�λ��
            }
			else 
			{
                return -2; // �û���ƥ�䵫���벻ƥ�䣬������������û��Ѵ���
            }
        }
    }
    return -3; // �û�������
}

/**********************
����˵���������û���Ϣ���� 
����˵�����û��ṹ�� 
����ֵ˵��:0������ɹ�   -1�� ����ʧ�� -2���û��Ѵ���
**********************/
int save_user(USER users) {
    int i = 0;
    UserList UL = {0};
	int user_pos;
	FILE *fp = NULL;

	ReadAllUser(&UL);

	user_pos = Check_info(UL, users.name, users.code);// ��ȡ�û�λ��
    
    if ((fp = fopen("data\\userinfo.dat", "rb+")) == NULL) {
        fp = fopen("data\\userinfo.dat", "wb");
        if (fp == NULL) {
            printf("�޷����ļ���\n");
            return -1;
        }
    }

    if (user_pos == -3) // �û�������
	{ 
        UListInsert(&UL, users); // �������û�
    } 
	else if(user_pos != -3) // �û�����
	{ 
        UL.elem[user_pos] = users;// �����û���Ϣ
    }

    // ����д���б�����
    rewind(fp);
    fwrite(&UL.length, sizeof(int), 1, fp);
    fwrite(&UL.listsize, sizeof(int), 1, fp);
    
    // ���д���û�����
    for (i = 0; i < UL.length; i++) {
        fwrite(&UL.elem[i], sizeof(USER), 1, fp);
    }

    fclose(fp);
    DestroyUList(&UL);

	if(user_pos != -3)//�û��Ѵ���
	{ 
		return -2;
	}
	else
	{
		return 0;//�û�������
	}
}



/*******************
����˵������ȡ�ļ��е������û�
����˵�����û����Ա��ַ 
����ֵ���� 
*******************/
void ReadAllUser(UserList *UL) {
    int i = 0;
    short length = 0; // ��Ϊ short
    short listsize = U_LIST_INIT_SIZE; // ��Ϊ short
    FILE *fp = NULL;

    if ((fp = fopen("data\\userinfo.dat", "rb")) == NULL) {
        fp = fopen("data\\userinfo.dat", "wb");
        if (fp == NULL) {
            printf("�޷������ļ���\n");
            return;
        }
        fwrite(&length, sizeof(short), 1, fp); // ��Ϊ short
        fwrite(&listsize, sizeof(short), 1, fp); // ��Ϊ short
        fclose(fp);
        return;
    }

    fread(&length, sizeof(short), 1, fp); // ��Ϊ short
    fread(&listsize, sizeof(short), 1, fp); // ��Ϊ short

    UL->length = length;
    UL->listsize = listsize;
    UL->elem = (USER *)malloc(listsize * sizeof(USER));

    if (UL->elem == NULL) {
        printf("No enough memory!\n");
        fclose(fp);
        exit(-1);
    }

    // �����ȡ�û�����
    for (i = 0; i < length; i++) {
        fread(&UL->elem[i], sizeof(USER), 1, fp);
    }

    fclose(fp);
}

/****************************
����˵��������һ�����Ա� 
����˵�������Ա��ַ
����ֵ��  ��  
****************************/
void InitUList(UserList*UL)  
{
	if((UL->elem=(USER*)malloc(U_LIST_INIT_SIZE*sizeof(USER)))==NULL)
	{
		CloseSVGA();
		printf("No enough memory!\n");
		exit(-1);
	}
	UL->length=0;
	UL->listsize=U_LIST_INIT_SIZE;
}


/****************************
����˵���������Ա�Lĩβ����Ԫ�� 
����˵�������Ա��ַ��Ҫ�����Ԫ��
����ֵ��  ��  
****************************/
void UListInsert(UserList*UL,USER e) 
{
	USER*newbase=NULL;
	if(UL->length>=UL->listsize)
	{
		if((newbase=(USER*)realloc(UL->elem,(UL->listsize+U_LISTINCEREMENT)*sizeof(USER)))==NULL)
	    {
		CloseSVGA();
		printf("No enough memory!\n");
		exit(-1);
	    }
		UL->elem=newbase;
		UL->listsize+=U_LISTINCEREMENT;
	}
	*(UL->elem+(UL->length))=e;
	UL->length++;
}



/****************************
����˵���������Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
����˵�������Ա��ַ��Ҫɾ����Ԫ��λ�ã�����ɾ��Ԫ�صĴ洢�ռ��ַ
����ֵ���� 
****************************/
void UListDelete(UserList*L,int i)
{
	USER*p=NULL;
	USER*q=NULL;
	if((i<0)||(i>=L->length)) //i��λ�ò��Ϸ� 
	{
		CloseSVGA();
		printf("ListDelete Wrong!");
		getch();
		exit(1);
	}
	p=L->elem+i;  //pΪ��ɾ��Ԫ��λ��
	//*e=*p;  //�ѱ�ɾ��Ԫ�ص�ֵ����e
	q=L->elem+L->length-1;  //��βԪ�ص�λ��
	for(p++;p<=q;p++)  //��ɾ��Ԫ��֮���Ԫ������
		*(p-1)=*p;
	L->length--;  //����һ
	
};
/****************************
����˵�����������Ա�L
����˵�������Ա��ַ
����ֵ���� 
****************************/
void DestroyUList(UserList*UL)	
{
	free(UL->elem);
	UL->elem=NULL;
	UL->listsize=0;
	UL->length=0;
}


/****************************
����˵�����õ�Ԫ��E�����Ա��е�λ��
����˵�������Ա�Ԫ��e 
����ֵ��  �� 
****************************/
int Userposition(UserList UL,USER e)
{
	int i=-1;
	for(i=0;i<UL.length;i++)
	{
		if(strcmp(e.name,UL.elem[i].name)==0)
		{
			return i;
		}	
	}
	return -1;
}


//����ģʽ
void input_mode(char *name,char *code,char *judge,int bar_x1,int bar_y1,int bar_x2,int bar_y2,int mode,int state)
{
	int length;//���ڼ�¼������ַ����������ڹ���ƶ���ĩβ
	char showtemp[2]= "\0";//�洢�����ַ�,���������չʾ
	int i=0,k,temp;  // iΪ�ַ�����,tempΪ�Ӽ����϶�ȡ�����ַ���ACSII��
	
	char name_temp[12]="\0";
	char code_temp[12]="\0";
	char judge_temp[12]="\0";

	int border; //���ĺ�����	    
	int x1,y1;
	x1=bar_x1+4;
	y1=bar_y1+5;//��������������ƫ����
	border=x1+4;//ÿ���ַ�ռ8������,ÿ����һ���ַ��������8������
	switch (mode)
	{
	case 1://�˺�����
		if(name_temp[0]=='\0') //����˺�Ϊ�գ�����ʾ�����
			bar1(bar_x1, bar_y1, bar_x2, bar_y2,lightgrew);
		else
		{            //��궨λ���ı�ĩβ
			length=strlen(name_temp);
			i=length;
			border+=12*i;
			cursor_grew(border,y1);
		}
		break;
	case 2://��������
		if(code_temp[0]=='\0') //�������Ϊ�գ�����ʾ�����
			bar1(bar_x1, bar_y1, bar_x2, bar_y2,lightgrew);
		else
		{
			length=strlen(code_temp);
			i=length;
			border+=12*i;
			cursor_grew(border,y1);
		}
	case 3://ȷ����������
	if(judge_temp[0]=='\0') //��������Ϊ�գ�����ʾ�����
		bar1(bar_x1, bar_y1, bar_x2, bar_y2,lightgrew);
	else
	{
		length=strlen(judge_temp);
		i=length;
		border+=12*i;
		cursor_grew(border,y1);
	}
	default:
		break;
	}
	
	while(1) 
    {
		cursor_grew(border,y1);
		//mouse_show_cursor(&mouse);
		if(mouse_location(455,255,845,295)==1 && mouse_location(455,335,845,375)==1 && mouse_location(455,415,845,455)==1)
			mouse_show_cursor(&mouse);
		else
			mouse_show_arrow(&mouse);
		if(bioskey(1)) //����м�������
		{
			temp=bioskey(0)&0x00ff; //��ȡ��������
			if(temp!='\r'&&temp!='\n')	//������벻Ϊ�س�����������������������
			{
				if((('0'<=temp&&temp<='9')||('a'<=temp&&temp<='z')||('A'<=temp && temp<='Z'))&& i <12)//���Ϊ���ֻ���ĸ�����¼
				{
					hide_cursor_grew(border,y1); //����ԭ���
					switch (mode)
					{
						case 1:
							name[i]=temp;//�ַ���������ַ��������ڱ����û���Ϣ
							name_temp[i]=temp;
							break;	
						case 2:
							code[i]=temp;//�ַ���������ַ��������ڱ����û���Ϣ
							code_temp[i]=temp;
							break;
						case 3:
							judge[i]=temp;//�ַ���������ַ��������ڱ����û���Ϣ
							judge_temp[i]=temp;
							break;
						default:
							break;
					}				
					*showtemp=temp;  //tempת��Ϊ�ַ���
					PrintText(border,y1+2,showtemp,HEI,24,1,0); //��ʾ�µ��ַ����ﵽ������ʵ�������ͬ��
					i++;	//�ַ���������
					switch (mode)
					{
						case 1:
							name[i]='\0';//����ַ�����β
							name_temp[i]='\0';//����ַ�����β
							break;	
						case 2:
							code[i]='\0';//����ַ�����β
							code_temp[i]='\0';//����ַ�����β
							break;
						case 3:
							judge[i]='\0';//����ַ�����β
							judge_temp[i]='\0';//����ַ�����β
							break;
						default:
							break;
					}			
					border+=12;	//������������12����
					draw_cursor(border,y1);
				}
				else if(temp=='\b'&&i>0)  //����Ƿ�Ϊ�˸������������ǰһ���ַ�
				{
					hide_cursor_grew(border,y1);	//����ԭ���
					border-=12;	//�������12����
					i--;	//�ַ������Լ�
					switch (mode)
					{
						case 1:
							name[i]='\0';//���洢���ַ���0����
							name_temp[i]='\0';//���洢���ַ���0����
							break;	
						case 2:
							code[i]='\0';//���洢���ַ���0����
							code_temp[i]='\0';//���洢���ַ���0����
							break;
						case 3:
							judge[i]='\0';//���洢���ַ���0����
							judge_temp[i]='\0';//���洢���ַ���0����
							break;
						default:
							break;
					}	
					bar1(border,y1,border+12, y1+26, lightgrew);	//���ԭ�ַ�
					draw_cursor(border,y1);
				}
				// else if(temp=='\t')
				// {
				// 	if(mode==1)	//�����˺Ż�����ģʽ
				// 	{
				// 		hide_cursor(border,y1);//���ع��
				// 		bar1(430,560,580,590,snow);
				// 		input_mode(name,code,judge,bar_x1, bar_y1+80, bar_x2, bar_y2+80,mode+1); 
				// 		break;
				// 	}
				// 	else if(mode==2)
				// 	{
				// 		hide_cursor(border,y1);//���ع��
				// 		bar1(430,560,580,590,snow);
				// 		input_mode(name,code,judge,bar_x1, bar_y1+80, bar_x2, bar_y2+80,mode+1); 
				// 		break;
				// 	}
				// 	else if(mode == 3)
				// 	{
				// 		hide_cursor(border,y1);//���ع��
				// 		bar1(430,560,580,590,snow);
				// 		break;
				// 	}
				// }
				else if(i>=10)
				{
					mouse_off_arrow(&mouse);
					mouse_show_arrow(&mouse);
					PrintCC(570,575,"���볬����������",HEI,24,1,0XF800);
					delay(500);
					bar1(570,575,800,600,snow);
				}
			}
			else
			{
				
				break;
			}
		}
		else if(mouse_press(450, 250, 700, 300)==1 && mode !=1 && state==0)  //���ע��ʱ�˺���
		{
			hide_cursor_grew(border,y1);//���ع��
			bar1(455,255,695,295,lightgrew);
			input_mode(name,code,judge,455,255,695,295,1,0); 
			break;
		}
		else if(mouse_press(450, 330, 700, 380)==1 && mode !=2 && state==0)//���ע��ʱ������
		{
			hide_cursor_grew(border,y1);//���ع��
			bar1(455,335,695,375,snow);
			input_mode(name,code,judge,455,335,695,375,2,0); 
			break;
		}
		else if(mouse_press(450, 410, 700, 460)==1 && mode !=3 && state==0)//���ע��ʱȷ��������
		{
			hide_cursor_grew(border,y1);//���ع��
			bar1(455,415,695,455,snow);
			input_mode(name,code,judge,455,415,695,455,3,0); 
			break;
		}
		else if(mouse_press(350, 330, 650, 380)==1 && mode !=1 && state==1)//�����¼ʱ�˺ſ� 
		{
			hide_cursor_grew(border,y1);//���ع��
			bar1(355, 335, 645, 375,lightgrew);
			input_mode(name,code,judge, 355, 335, 645, 375,1,1);
			break;
		}
        else if(mouse_press(350, 410, 650, 460)==1 && mode !=2 && state==1)//�����¼ʱ����� 
		{	
			hide_cursor_grew(border,y1);//���ع��
			bar1(355, 415, 645, 455,lightgrew);
			input_mode(name,code,judge, 355, 415, 645, 455,2,1);
			break;
		}
		else if (mouse_press(bar_x1,bar_y1,bar_x2,bar_y2)==2)  //�������
		{
			hide_cursor_grew(border,y1);//���ع��
			break;
		}	
	}
}	
