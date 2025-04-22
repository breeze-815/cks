#include "all_func.h"

/**********************
功能说明：登录信息对比校验函数 
参数说明：用户线性表，用户名，密码 
返回值说明:i：用户在线性表中的位置  -2:密码错误 -3：用户不存在 
**********************/
int Check_info(UserList UL, char name[12], char code[12]) {
    int i = 0;
    for (i = 0; i < UL.length; i++)
	{
        if (strcmp(UL.elem[i].name, name) == 0) 
		{
            if (strcmp(UL.elem[i].code, code) == 0) 
			{
                return i; // 用户名和密码都匹配，返回用户位置
            }
			else 
			{
                return -2; // 用户名匹配但密码不匹配，返回密码错误，用户已存在
            }
        }
    }
    return -3; // 用户不存在
}

/**********************
功能说明：保存用户信息函数 
参数说明：用户结构体 
返回值说明:0：保存成功   -1： 保存失败 -2：用户已存在
**********************/
int save_user(USER users) {
    int i = 0;
    UserList UL = {0};
	int user_pos;
	FILE *fp = NULL;

	ReadAllUser(&UL);

	user_pos = Check_info(UL, users.name, users.code);// 获取用户位置
    
    if ((fp = fopen("data\\userinfo.dat", "rb+")) == NULL) {
        fp = fopen("data\\userinfo.dat", "wb");
        if (fp == NULL) {
            printf("无法打开文件！\n");
            return -1;
        }
    }

    if (user_pos == -3) // 用户不存在
	{ 
        UListInsert(&UL, users); // 插入新用户
    } 
	else if(user_pos != -3) // 用户存在
	{ 
        UL.elem[user_pos] = users;// 更新用户信息
    }

    // 重新写入列表数据
    rewind(fp);
    fwrite(&UL.length, sizeof(int), 1, fp);
    fwrite(&UL.listsize, sizeof(int), 1, fp);
    
    // 逐个写入用户数据
    for (i = 0; i < UL.length; i++) {
        fwrite(&UL.elem[i], sizeof(USER), 1, fp);
    }

    fclose(fp);
    DestroyUList(&UL);

	if(user_pos != -3)//用户已存在
	{ 
		return -2;
	}
	else
	{
		return 0;//用户不存在
	}
}



/*******************
功能说明：获取文件中的所有用户
参数说明：用户线性表地址 
返回值：无 
*******************/
void ReadAllUser(UserList *UL) {
    int i = 0;
    short length = 0; // 改为 short
    short listsize = U_LIST_INIT_SIZE; // 改为 short
    FILE *fp = NULL;

    if ((fp = fopen("data\\userinfo.dat", "rb")) == NULL) {
        fp = fopen("data\\userinfo.dat", "wb");
        if (fp == NULL) {
            printf("无法创建文件！\n");
            return;
        }
        fwrite(&length, sizeof(short), 1, fp); // 改为 short
        fwrite(&listsize, sizeof(short), 1, fp); // 改为 short
        fclose(fp);
        return;
    }

    fread(&length, sizeof(short), 1, fp); // 改为 short
    fread(&listsize, sizeof(short), 1, fp); // 改为 short

    UL->length = length;
    UL->listsize = listsize;
    UL->elem = (USER *)malloc(listsize * sizeof(USER));

    if (UL->elem == NULL) {
        printf("No enough memory!\n");
        fclose(fp);
        exit(-1);
    }

    // 逐个读取用户数据
    for (i = 0; i < length; i++) {
        fread(&UL->elem[i], sizeof(USER), 1, fp);
    }

    fclose(fp);
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
	
};
/****************************
功能说明：销毁线性表L
参数说明：线性表地址
返回值：无 
****************************/
void DestroyUList(UserList*UL)	
{
	free(UL->elem);
	UL->elem=NULL;
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


//输入模式
void input_mode(char *name,char *code,char *judge,int bar_x1,int bar_y1,int bar_x2,int bar_y2,int mode,int state)
{
	int length;//用于记录输入的字符个数，便于光标移动至末尾
	char showtemp[2]= "\0";//存储输入字符,用于输入框展示
	int i=0,k,temp;  // i为字符个数,temp为从键盘上读取输入字符的ACSII码
	
	char name_temp[12]="\0";
	char code_temp[12]="\0";
	char judge_temp[12]="\0";

	int border; //光标的横坐标	    
	int x1,y1;
	x1=bar_x1+4;
	y1=bar_y1+5;//光标相较于输入框的偏移量
	border=x1+4;//每个字符占8个像素,每输入一个字符光标右移8个像素
	switch (mode)
	{
	case 1://账号输入
		if(name_temp[0]=='\0') //如果账号为空，则显示输入框
			bar1(bar_x1, bar_y1, bar_x2, bar_y2,lightgrew);
		else
		{            //光标定位至文本末尾
			length=strlen(name_temp);
			i=length;
			border+=12*i;
			cursor_grew(border,y1);
		}
		break;
	case 2://密码输入
		if(code_temp[0]=='\0') //如果密码为空，则显示输入框
			bar1(bar_x1, bar_y1, bar_x2, bar_y2,lightgrew);
		else
		{
			length=strlen(code_temp);
			i=length;
			border+=12*i;
			cursor_grew(border,y1);
		}
	case 3://确认密码输入
	if(judge_temp[0]=='\0') //如果输入框为空，则显示输入框
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
		if(bioskey(1)) //如果有键盘输入
		{
			temp=bioskey(0)&0x00ff; //获取键盘输入
			if(temp!='\r'&&temp!='\n')	//检测输入不为回车键，则继续，否则输入结束
			{
				if((('0'<=temp&&temp<='9')||('a'<=temp&&temp<='z')||('A'<=temp && temp<='Z'))&& i <12)//检测为数字或字母，则记录
				{
					hide_cursor_grew(border,y1); //隐藏原光标
					switch (mode)
					{
						case 1:
							name[i]=temp;//字符送入给定字符串，用于保存用户信息
							name_temp[i]=temp;
							break;	
						case 2:
							code[i]=temp;//字符送入给定字符串，用于保存用户信息
							code_temp[i]=temp;
							break;
						case 3:
							judge[i]=temp;//字符送入给定字符串，用于保存用户信息
							judge_temp[i]=temp;
							break;
						default:
							break;
					}				
					*showtemp=temp;  //temp转化为字符串
					PrintText(border,y1+2,showtemp,HEI,24,1,0); //显示新的字符串达到画面与实际输入的同步
					i++;	//字符个数自增
					switch (mode)
					{
						case 1:
							name[i]='\0';//标记字符串结尾
							name_temp[i]='\0';//标记字符串结尾
							break;	
						case 2:
							code[i]='\0';//标记字符串结尾
							code_temp[i]='\0';//标记字符串结尾
							break;
						case 3:
							judge[i]='\0';//标记字符串结尾
							judge_temp[i]='\0';//标记字符串结尾
							break;
						default:
							break;
					}			
					border+=12;	//光标横坐标右移12像素
					draw_cursor(border,y1);
				}
				else if(temp=='\b'&&i>0)  //检测是否为退格键，是则消除前一个字符
				{
					hide_cursor_grew(border,y1);	//隐藏原光标
					border-=12;	//光标左移12像素
					i--;	//字符个数自减
					switch (mode)
					{
						case 1:
							name[i]='\0';//将存储的字符用0覆盖
							name_temp[i]='\0';//将存储的字符用0覆盖
							break;	
						case 2:
							code[i]='\0';//将存储的字符用0覆盖
							code_temp[i]='\0';//将存储的字符用0覆盖
							break;
						case 3:
							judge[i]='\0';//将存储的字符用0覆盖
							judge_temp[i]='\0';//将存储的字符用0覆盖
							break;
						default:
							break;
					}	
					bar1(border,y1,border+12, y1+26, lightgrew);	//清空原字符
					draw_cursor(border,y1);
				}
				// else if(temp=='\t')
				// {
				// 	if(mode==1)	//输入账号或密码模式
				// 	{
				// 		hide_cursor(border,y1);//隐藏光标
				// 		bar1(430,560,580,590,snow);
				// 		input_mode(name,code,judge,bar_x1, bar_y1+80, bar_x2, bar_y2+80,mode+1); 
				// 		break;
				// 	}
				// 	else if(mode==2)
				// 	{
				// 		hide_cursor(border,y1);//隐藏光标
				// 		bar1(430,560,580,590,snow);
				// 		input_mode(name,code,judge,bar_x1, bar_y1+80, bar_x2, bar_y2+80,mode+1); 
				// 		break;
				// 	}
				// 	else if(mode == 3)
				// 	{
				// 		hide_cursor(border,y1);//隐藏光标
				// 		bar1(430,560,580,590,snow);
				// 		break;
				// 	}
				// }
				else if(i>=10)
				{
					mouse_off_arrow(&mouse);
					mouse_show_arrow(&mouse);
					PrintCC(570,575,"输入超过长度限制",HEI,24,1,0XF800);
					delay(500);
					bar1(570,575,800,600,snow);
				}
			}
			else
			{
				
				break;
			}
		}
		else if(mouse_press(450, 250, 700, 300)==1 && mode !=1 && state==0)  //点击注册时账号栏
		{
			hide_cursor_grew(border,y1);//隐藏光标
			bar1(455,255,695,295,lightgrew);
			input_mode(name,code,judge,455,255,695,295,1,0); 
			break;
		}
		else if(mouse_press(450, 330, 700, 380)==1 && mode !=2 && state==0)//点击注册时密码栏
		{
			hide_cursor_grew(border,y1);//隐藏光标
			bar1(455,335,695,375,snow);
			input_mode(name,code,judge,455,335,695,375,2,0); 
			break;
		}
		else if(mouse_press(450, 410, 700, 460)==1 && mode !=3 && state==0)//点击注册时确认密码栏
		{
			hide_cursor_grew(border,y1);//隐藏光标
			bar1(455,415,695,455,snow);
			input_mode(name,code,judge,455,415,695,455,3,0); 
			break;
		}
		else if(mouse_press(350, 330, 650, 380)==1 && mode !=1 && state==1)//点击登录时账号框 
		{
			hide_cursor_grew(border,y1);//隐藏光标
			bar1(355, 335, 645, 375,lightgrew);
			input_mode(name,code,judge, 355, 335, 645, 375,1,1);
			break;
		}
        else if(mouse_press(350, 410, 650, 460)==1 && mode !=2 && state==1)//点击登录时密码框 
		{	
			hide_cursor_grew(border,y1);//隐藏光标
			bar1(355, 415, 645, 455,lightgrew);
			input_mode(name,code,judge, 355, 415, 645, 455,2,1);
			break;
		}
		else if (mouse_press(bar_x1,bar_y1,bar_x2,bar_y2)==2)  //点击框外
		{
			hide_cursor_grew(border,y1);//隐藏光标
			break;
		}	
	}
}	
