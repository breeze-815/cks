#ifndef _LGFUNC_H_
#define _LGFUNC_H_

#define U_LIST_INIT_SIZE 10 //线性表存储空间的初始分配量
#define U_LISTINCEREMENT 1  //线性表存储空间的分配增量

typedef struct USER
{
	char name[12];//账户 
	char code[12];//密码

	int type;//用户类型 1为用户，2为商家，3为骑手
	char number[12];//手机号
	int address;//地址 1为紫菘，2为沁苑，3为韵苑

}USER;

typedef struct path
{
    int length;
    int node[20];
    int start;
    int end;
} path;

typedef struct ADMIN
{
	int esptic[9];//特殊项目票张数
	int normaltic[4];//普通票的总票

	int esptic_now[9];
	int normaltic_now[4];
}ADMIN;


typedef struct PROJECT
{
	int num;//编号
	char pname[30];//名称
	char open_close;//o为开放，c为不开放
	char type;//1刺激，2亲子，3娱乐，0特殊项目
	int play_time;//项目预设游玩时间
	int wait_people;//正在等待的游客人数
}PROJECT;





typedef struct UserList
{
	struct USER* elem;    //存储空间基值
	int length;  //当前长度
	int listsize;  //当前分配存储空间容量
}UserList;//用户线性表 


/*建立一个空表*/
void InitUList(UserList*UL);

/*在线性表UL的末尾插入新的元素e*/
void UListInsert(UserList*UL,struct USER e);

/*删除元素*/
void UListDelete(UserList*L,int i);


/*若线性表L存在，销毁线性表*/
void DestroyUList(UserList*UL);	

/*返回元素e在线性表中的位置*/
int Userposition(UserList UL,USER e);

//显示光标
void show_gb(int x,int y);
//得到显示信息
void input_mode(char *name,char *code,char *judge,int bar_x1,int bar_y1,int bar_x2,int bar_y2,int mode);
//保存用户信息
int save_user(USER temp);

void ReadAllUser(UserList *UL);

void UpdataUser(USER user);

#endif