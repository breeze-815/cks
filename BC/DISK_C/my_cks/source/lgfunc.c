#include "all_func.h"



/**********************
功能说明：登录信息对比校验函数 
参数说明：用户线性表，用户名，密码 
返回值说明:i：用户在线性表中的位置   -2： 密码错误   -3：用户不存在 
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
功能说明：保存用户信息函数 
参数说明：用户结构体 
返回值说明:0：保存成功   -1： 保存失败 
**********************/
int save_user(USER users)
{
	UserList UL={0};
	FILE *fp=NULL;
	ReadAllUser(&UL);
	if((fp=fopen("userinfo.dat","rb+"))==NULL)		//首次使用时应创建文件
	{
		//prt_hz24(400,400,"无法打开文件！",10,"HZK\\Hzk24h");
		delay(5000);
		exit(1);
	}
	if(Check_info(UL,users.name,users.code)==-3)			//用户不存在 
	{
	    UListInsert(&UL,users);
	    fseek(fp,0,SEEK_SET);
	    rewind(fp);
	    fwrite(&UL.length, sizeof(int), 1, fp);
	    fwrite(&UL.listsize, sizeof(int), 1, fp);
	    fwrite(UL.elem, sizeof(USER), UL.length, fp);
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
功能说明：获取文件中的所有用户
参数说明：用户线性表地址 
返回值：无 
*******************/
void ReadAllUser(UserList *UL)
{
	int length=0;//接收线性表长度 
	int listsize=U_LIST_INIT_SIZE;//线性表初始长度 
	FILE *fp=NULL;
	if((fp=fopen("userinfo.dat","rb+"))==NULL)			//检测文件打开是否正常
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
	   if((UL->elem = (USER*)malloc(listsize* sizeof(USER)))==NULL)//构建用户线性表 
	   {
		 CloseSVGA();
		 printf("No enough memory!\n");
		 getch();
		 exit(-1);
	   } 
	  fread(UL->elem, sizeof(USER),length, fp);//读取文件的所有用户到线性表中 
    }
	fclose(fp);
}


/*******************
功能说明：更新用户信息 
参数说明：用户结构体 
返回值：无 
*******************/

void UpdataUser(USER user)
{
	int usernum=0;//用户位置 
	UserList UL={0};//用户线性表 
	FILE *fp=NULL;
	ReadAllUser(&UL);//获取所有用户到线性表 
	if((fp=fopen("userinfo.dat","rb+"))==NULL)
	{
		//prt_hz24(400,400,"无法打开文件！",10,"HZK\\Hzk24h");
		delay(5000);
		exit(1);
	}
	usernum=Userposition(UL,user);//得到用户在线性表中的位置 
	UL.elem[usernum]=user;//更新线性表中用户信息 
	fseek(fp,0,SEEK_SET);
	fwrite(&UL.length, sizeof(int), 1, fp);
	fwrite(&UL.listsize, sizeof(int), 1, fp);
	fwrite(UL.elem, sizeof(USER), UL.length, fp);
	fclose(fp);
	DestroyUList(&UL);//销毁线性表 
}

/****************************
功能说明：建立一个线性表 
参数说明：线性表地址
返回值：  无  
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
功能说明：在线性表L末尾插入元素 
参数说明：线性表地址，要插入的元素
返回值：  无  
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
功能说明：在线性表L中删除第i个元素，并用e返回其值
参数说明：线性表地址，要删除的元素位置，接收删除元素的存储空间地址
返回值：无 
****************************/
void UListDelete(UserList*L,int i)
{
	USER*p=NULL;
	USER*q=NULL;
	if((i<0)||(i>=L->length)) //i的位置不合法 
	{
		CloseSVGA();
		printf("ListDelete Wrong!");
		getch();
		exit(1);
	}
	p=L->elem+i;  //p为被删除元素位置
	//*e=*p;  //把被删除元素的值赋给e
	q=L->elem+L->length-1;  //表尾元素的位置
	for(p++;p<=q;p++)  //被删除元素之后的元素左移
		*(p-1)=*p;
	L->length--;  //表长减一
	
}


/****************************
功能说明：销毁线性表L
参数说明：线性表地址
返回值：无 
****************************/
void DestroyUList(UserList*UL)	
{
	free(UL->elem);
	UL->listsize=0;
	UL->length=0;
}


/****************************
功能说明：得到元素E在线性表中的位置
参数说明：线性表，元素e 
返回值：  无 
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




/***信息输入时所做的相同操作***/
void Get_account(int x1,int y1,char *name,char *judge)
{
	int length;
	char showtemp[2]= "\0";//存储输入字符,用于输入框展示
	int i=0,k,temp;  // i为字符个数,temp为从键盘上读取输入字符的ACSII码
	int border=x1+4; //光标的横坐标	    
	x1=x1+4;
	y1=y1+5;//光标相较于输入框的偏移量
	//每个字符占8个像素,每输入一个字符光标右移8个像素
	if(name[0]=='\0') //如果输入框为空，则显示输入框
		bar1(455, 255, 845, 295,0xFFFF);
	else
	{
		length=strlen(name);
		i=length;
		border+=8*i;
		cursor(border,y1);
		//光标定位至文本末尾
	}
	while(1) 
    {
		mouse_off(&mouse);
	    cursor(border,y1);//光标闪烁 
		mouse_show(&mouse);
		if(bioskey(1)) //如果有键盘输入
		{
			temp=bioskey(0)&0x00ff; //获取键盘输入
			mouse_show(&mouse); //显示鼠标
			if(temp!='\r'&&temp!='\n')	//检测输入不为回车键，则继续，否则输入结束
			{
				if((('0'<=temp&&temp<='9')||('a'<=temp&&temp<='z')||('A'<=temp && temp<='Z'))&& i <10)//检测为数字或字母，则记录
				{
					hide_cursor(border,y1); //隐藏原光标
					name[i]=temp;			//字符送入给定字符串，用于保存用户信息			
					*showtemp=temp;  //temp转化为字符串
					PrintText(border,y1-2,showtemp,HEI,16,1,0); //显示新的字符串达到画面与实际输入的同步
					i++;	//字符个数自增
					name[i]='\0';		//标记字符串结尾
					border+=8;	//光标横坐标右移8像素
					cursor(border,y1);	//显示新光标
				}
				else if(temp=='\b'&&i>0)  //检测是否为退格键，是则消除前一个字符
				{
					hide_cursor(border,y1);	//隐藏原光标
					border-=8;	//光标左移8像素
					i--;	//字符个数自减
					name[i]='\0';	//将存储的字符用0覆盖
					bar1(border,y1,border+8, y1+16, 0xffff);	//清空原字符
					cursor(border,y1);	//显示新光标
				}
				else if(temp=='\t')
				{
					Get_code(455,340,users.code,judge);
				}
				else if(i>=10)
				{
					mouse_off(&mouse);
					mouse_show(&mouse);
					PrintCC(1,1,"输入账号超出长度限制",HEI,24,1,0xF800);
				}
			}
			else
			{
				break;
			}
		}
		else if (mouse_press(450, 250, 850, 300)!=1) {
			break;
		}
		hide_cursor(border,y1);	//隐藏光标
	}
}


void Get_code(int x1,int y1,char *name,char *judge)
{
	int length;
	char showtemp[2]= "\0";//存储输入字符,用于输入框展示
	int i=0,k,temp;  // i为字符个数,temp为从键盘上读取输入字符的ACSII码
	int border=x1+4; //光标的横坐标	    
	x1=x1+4;
	y1=y1+5;//光标相较于输入框的偏移量
	//每个字符占8个像素,每输入一个字符光标右移8个像素
	if(name[0]=='\0') //如果输入框为空，则显示输入框
		bar1(455, 335, 845, 375,0xffff);
	else
	{
		length=strlen(name);
		i=length;
		border+=8*i;
		cursor(border,y1);
		//光标定位至文本末尾
	}
	while(1) 
    {
		mouse_off(&mouse);
	    cursor(border,y1);//光标闪烁 
		mouse_show(&mouse);
		if(bioskey(1)) //如果有键盘输入
		{
			temp=bioskey(0)&0x00ff; //获取键盘输入
			mouse_show(&mouse); //显示鼠标
			if(temp!='\r'&&temp!='\n')	//检测输入不为回车键，则继续，否则输入结束
			{
				if((('0'<=temp&&temp<='9')||('a'<=temp&&temp<='z')||('A'<=temp && temp<='Z'))&& i <10)//检测为数字或字母，则记录
				{
					hide_cursor(border,y1); //隐藏原光标
					name[i]=temp;			//字符送入给定字符串，用于保存用户信息			
					*showtemp=temp;  //temp转化为字符串
					PrintText(border,y1-2,showtemp,HEI,16,1,0); //显示新的字符串达到画面与实际输入的同步
					delay(100);
					bar1(border,y1,border+8, y1+16, 0xffff);
					Circlefill(border+4,y1+8,2,0);
					i++;	//字符个数自增
					name[i]='\0';		//标记字符串结尾
					border+=8;	//光标横坐标右移8像素
					cursor(border,y1);	//显示新光标
				}
				else if(temp=='\b'&&i>0)  //检测是否为退格键，是则消除前一个字符
				{
					hide_cursor(border,y1);	//隐藏原光标
					border-=8;	//光标左移8像素
					i--;	//字符个数自减
					name[i]='\0';	//将存储的字符用0覆盖
					bar1(border,y1,border+8, y1+16, 0xffff);	//清空原字符
					cursor(border,y1);	//显示新光标
				}
				else if(temp=='\t')
				{
					Check_code(455,420,judge);
				}
				else if(i>=10)
				{
					mouse_off(&mouse);
					mouse_show(&mouse);
					PrintCC(1,1,"输入密码超出长度限制",HEI,24,1,0xF800);
				}
			}
			else
			{
				break;
			}
		}
		else if (mouse_press(450, 250, 850, 300)!=1) {
			break;
		}
		hide_cursor(border,y1);	//隐藏光标
	}
}

void Check_code(int x1,int y1,char *judge)
{
	int length;
	char showtemp[2]= "\0";//存储输入字符,用于输入框展示
	int i=0,k,temp;  // i为字符个数,temp为从键盘上读取输入字符的ACSII码
	int border=x1+4; //光标的横坐标	    
	x1=x1+4;
	y1=y1+5;//光标相较于输入框的偏移量
	//每个字符占8个像素,每输入一个字符光标右移8个像素
	if(judge[0]=='\0') //如果输入框为空，则显示输入框
		bar1(455, 415, 845, 455,0xffff);
	else
	{
		length=strlen(judge);
		i=length;
		border+=8*i;
		cursor(border,y1);
		//光标定位至文本末尾
	}
	while(1) 
    {
		mouse_off(&mouse);
	    cursor(border,y1);//光标闪烁 
		mouse_show(&mouse);
		if(bioskey(1)) //如果有键盘输入
		{
			temp=bioskey(0)&0x00ff; //获取键盘输入
			mouse_show(&mouse); //显示鼠标
			if(temp!='\r'&&temp!='\n')	//检测输入不为回车键，则继续，否则输入结束
			{
				if((('0'<=temp&&temp<='9')||('a'<=temp&&temp<='z')||('A'<=temp && temp<='Z'))&& i <10)//检测为数字或字母，则记录
				{
					hide_cursor(border,y1); //隐藏原光标
					judge[i]=temp;			//字符送入给定字符串，用于保存用户信息			
					*showtemp=temp;  //temp转化为字符串
					PrintText(border,y1-2,showtemp,HEI,16,1,0); //显示新的字符串达到画面与实际输入的同步
					delay(100);
					bar1(border,y1,border+8, y1+16, 0xffff);
					Circlefill(border+4,y1+8,2,0);
					i++;	//字符个数自增
					judge[i]='\0';		//标记字符串结尾
					border+=8;	//光标横坐标右移8像素
					cursor(border,y1);	//显示新光标
				}
				else if(temp=='\b'&&i>0)  //检测是否为退格键，是则消除前一个字符
				{
					hide_cursor(border,y1);	//隐藏原光标
					border-=8;	//光标左移8像素
					i--;	//字符个数自减
					judge[i]='\0';	//将存储的字符用0覆盖
					bar1(border,y1,border+8, y1+16, 0xffff);	//清空原字符
					cursor(border,y1);	//显示新光标
				}
				else if(i>=10)
				{
					mouse_off(&mouse);
					mouse_show(&mouse);
					PrintCC(1,1,"输入密码超出长度限制",HEI,24,1,0xF800);
				}
			}
			else
			{
				break;
			}
		}
		else if (mouse_press(450, 250, 850, 300)!=1) {
			break;
		}
		hide_cursor(border,y1);	//隐藏光标
	}
}
