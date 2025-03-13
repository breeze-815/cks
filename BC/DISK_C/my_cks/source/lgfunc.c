#include "all_func.h"



/**********************
����˵������¼��Ϣ�Ա�У�麯�� 
����˵�����û����Ա��û��������� 
����ֵ˵��:i���û������Ա��е�λ��   -2�� �������   -3���û������� 
**********************/
int Check_info(UserList UL,char name[10],char code[10])
{
	int i=0;
	for(i=0;i<UL.length;i++)
	{
		if(strcmp(UL.elem[i].name,name)==0)
		{
			if(strcmp(UL.elem[i].code,code)==0)
			{
				return i;
			}
			else
			{
				return -2;
			}
		}
	}
	return -3;
}

/**********************
����˵���������û���Ϣ���� 
����˵�����û��ṹ�� 
����ֵ˵��:0������ɹ�   -1�� ����ʧ�� 
**********************/
int save_user(USER users)
{
	UserList UL={0};
	FILE *fp=NULL;
	ReadAllUser(&UL);
	if((fp=fopen("userinfo.dat","rb+"))==NULL)		//�״�ʹ��ʱӦ�����ļ�
	{
		//prt_hz24(400,400,"�޷����ļ���",10,"HZK\\Hzk24h");
		delay(5000);
		exit(1);
	}
	if(Check_info(UL,users.name,users.code)==-3)			// ����û��Ƿ��Ѵ��� -3 �����û�������
	{
	    UListInsert(&UL,users);
	    fseek(fp,0,SEEK_SET);
	    rewind(fp);// �ƶ��ļ�ָ�뵽��ͷ
	    fwrite(&UL.length, sizeof(int), 1, fp);// 1. д���û�����
	    fwrite(&UL.listsize, sizeof(int), 1, fp);// 2. д���б��С
	    fwrite(UL.elem, sizeof(USER), UL.length, fp);// 3. д���û�����
	    fclose(fp);
		DestroyUList(&UL);
		delay(500);
		return 0;
	}
	else
	{
		DestroyUList(&UL);
		delay(500);		
		fclose(fp);
		return -1;
	}
}


/*******************
����˵������ȡ�ļ��е������û�
����˵�����û����Ա��ַ 
����ֵ���� 
*******************/
void ReadAllUser(UserList *UL)
{
	int length=0;//�������Ա��� 
	int listsize=U_LIST_INIT_SIZE;//���Ա��ʼ���� 
	FILE *fp=NULL;
	if((fp=fopen("userinfo.dat","rb+"))==NULL)			//����ļ����Ƿ�����
	{
		fp=fopen("userinfo.dat","wb");
		rewind(fp);
		fwrite(&length, sizeof(int), 1, fp);
		fwrite(&listsize, sizeof(int), 1, fp);
	}								
    else
    {
       fseek(fp,0,SEEK_SET);
	   fread(&length, sizeof(int), 1, fp);
	   fread(&listsize, sizeof(int), 1, fp);
	   UL->length = length;
	   UL->listsize = listsize;
	   if((UL->elem = (USER*)malloc(listsize* sizeof(USER)))==NULL)//�����û����Ա� 
	   {
		 CloseSVGA();
		 printf("No enough memory!\n");
		 getch();
		 exit(-1);
	   } 
	  fread(UL->elem, sizeof(USER),length, fp);//��ȡ�ļ��������û������Ա��� 
    }
	fclose(fp);
}


/*******************
����˵���������û���Ϣ 
����˵�����û��ṹ�� 
����ֵ���� 
*******************/

void UpdataUser(USER user)
{
	int usernum=0;//�û�λ�� 
	UserList UL={0};//�û����Ա� 
	FILE *fp=NULL;
	ReadAllUser(&UL);//��ȡ�����û������Ա� 
	if((fp=fopen("userinfo.dat","rb+"))==NULL)
	{
		//prt_hz24(400,400,"�޷����ļ���",10,"HZK\\Hzk24h");
		delay(5000);
		exit(1);
	}
	usernum=Userposition(UL,user);//�õ��û������Ա��е�λ�� 
	UL.elem[usernum]=user;//�������Ա����û���Ϣ 
	fseek(fp,0,SEEK_SET);
	fwrite(&UL.length, sizeof(int), 1, fp);
	fwrite(&UL.listsize, sizeof(int), 1, fp);
	fwrite(UL.elem, sizeof(USER), UL.length, fp);
	fclose(fp);
	DestroyUList(&UL);//�������Ա� 
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
	
}


/****************************
����˵�����������Ա�L
����˵�������Ա��ַ
����ֵ���� 
****************************/
void DestroyUList(UserList*UL)	
{
	free(UL->elem);
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
void input_mode(char *name,char *code,char *judge,int bar_x1,int bar_y1,int bar_x2,int bar_y2,int mode)
{
	int length;
	char showtemp[2]= "\0";//�洢�����ַ�,���������չʾ
	int i=0,k,temp;  // iΪ�ַ�����,tempΪ�Ӽ����϶�ȡ�����ַ���ACSII��
	int border; //���ĺ�����	    
	int x1,y1;
	x1=bar_x1+4;
	y1=bar_y1+5;//��������������ƫ����
	border=x1+4;//ÿ���ַ�ռ8������,ÿ����һ���ַ��������8������
	switch (mode)
	{
	case 1:
		if(name[0]=='\0') //����˺�Ϊ�գ�����ʾ�����
			bar1(bar_x1, bar_y1, bar_x2, bar_y2,0xFFFF);
		else
		{            //��궨λ���ı�ĩβ
			length=strlen(name);
			i=length;
			border+=8*i;
			cursor(border,y1);
		}
		break;
	case 2:
		if(code[0]=='\0') //�������Ϊ�գ�����ʾ�����
			bar1(bar_x1, bar_y1, bar_x2, bar_y2,0xFFFF);
		else
		{
		length=strlen(code);
		i=length;
		border+=8*i;
		cursor(border,y1);
		}
	case 3:
	if(judge[0]=='\0') //��������Ϊ�գ�����ʾ�����
		bar1(bar_x1, bar_y1, bar_x2, bar_y2,0xFFFF);
	else
	{
		length=strlen(judge);
		i=length;
		border+=8*i;
		cursor(border,y1);
	}
	default:
		break;
	}
	
	while(1) 
    {
		cursor(border,y1);
		//mouse_show_cursor(&mouse);
		if(mouse_location(455,255,845,295)==1 && mouse_location(455,335,845,375)==1 && mouse_location(455,415,845,455)==1)
			mouse_show_cursor(&mouse);
		else
			mouse_show_arrow(&mouse);
		if(bioskey(1)) //����м�������
		{
			temp=bioskey(0)&0x00ff; //��ȡ��������
			//mouse_show_arrow(&mouse); //��ʾ���
			if(temp!='\r'&&temp!='\n')	//������벻Ϊ�س�����������������������
			{
				if((('0'<=temp&&temp<='9')||('a'<=temp&&temp<='z')||('A'<=temp && temp<='Z'))&& i <10)//���Ϊ���ֻ���ĸ�����¼
				{
					hide_cursor(border,y1); //����ԭ���
					switch (mode)
					{
						case 1:
							name[i]=temp;//�ַ���������ַ��������ڱ����û���Ϣ
							break;	
						case 2:
							code[i]=temp;//�ַ���������ַ��������ڱ����û���Ϣ
							break;
						case 3:
							judge[i]=temp;//�ַ���������ַ��������ڱ����û���Ϣ
							break;
						default:
							break;
					}				
					*showtemp=temp;  //tempת��Ϊ�ַ���
					PrintText(border,y1-2,showtemp,HEI,16,1,0); //��ʾ�µ��ַ����ﵽ������ʵ�������ͬ��
					i++;	//�ַ���������
					switch (mode)
					{
						case 1:
							name[i]='\0';//����ַ�����β
							break;	
						case 2:
							code[i]='\0';//����ַ�����β
						case 3:
							judge[i]='\0';//����ַ�����β
							break;
						default:
							break;
					}			
					border+=8;	//������������8����
					draw_cursor(border,y1);
				}
				else if(temp=='\b'&&i>0)  //����Ƿ�Ϊ�˸������������ǰһ���ַ�
				{
					hide_cursor(border,y1);	//����ԭ���
					border-=8;	//�������8����
					i--;	//�ַ������Լ�
					switch (mode)
					{
						case 1:
							name[i]='\0';//���洢���ַ���0����
							break;	
						case 2:
							code[i]='\0';//���洢���ַ���0����
						case 3:
							judge[i]='\0';//���洢���ַ���0����
							break;
						default:
							break;
					}	
					bar1(border,y1,border+8, y1+16, 0xffff);	//���ԭ�ַ�
					draw_cursor(border,y1);
				}
				else if(temp=='\t')
				{
					if(mode==1)	//�����˺Ż�����ģʽ
					{
						hide_cursor(border,y1);//���ع��
						bar1(430,560,580,590,snow);
						input_mode(name,code,judge,bar_x1, bar_y1+80, bar_x2, bar_y2+80,mode+1); 
						break;
					}
					else if(mode==2)
					{
						hide_cursor(border,y1);//���ع��
						bar1(430,560,580,590,snow);
						input_mode(name,code,judge,bar_x1, bar_y1+80, bar_x2, bar_y2+80,mode+1); 
						break;
					}
					else if(mode == 3)
					{
						hide_cursor(border,y1);//���ع��
						bar1(430,560,580,590,snow);
						break;
					}
				}
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
		else if(mouse_press(455, 255, 845, 295)==1 && mode !=1)  //����˺���
		{
			hide_cursor(border,y1);//���ع��
			bar1(430,560,580,590,snow);
			input_mode(name,code,judge,bar_x1, bar_y1+80, bar_x2, bar_y2+80,1); 
			break;
		}
		else if(mouse_press(450, 330, 850, 380)==1 && mode !=2)
		{
			hide_cursor(border,y1);//���ع��
			bar1(430,560,580,590,snow);
			input_mode(name,code,judge,bar_x1, bar_y1+80, bar_x2, bar_y2+80,2); 
			break;
		}

		else if(mouse_press(450, 410, 850, 460)==1 && mode !=3)
		{
			hide_cursor(border,y1);//���ع��
			bar1(430,560,580,590,snow);
			input_mode(name,code,judge,bar_x1, bar_y1+80, bar_x2, bar_y2+80,3); 
			break;
		}
		else if (mouse_press(bar_x1,bar_y1,bar_x2,bar_y2)==2)  //�������
		{
			hide_cursor(border,y1);//���ع��
			break;
		}	
			
	// hide_cursor(border,y1);	//���ع��
	}
}	
