#ifndef _LGFUNC_H_
#define _LGFUNC_H_

#define U_LIST_INIT_SIZE 10 //���Ա�洢�ռ�ĳ�ʼ������
#define U_LISTINCEREMENT 1  //���Ա�洢�ռ�ķ�������

typedef struct USER
{
	char name[12];//�˻� 
	char code[12];//����

	int espbook[9];//ԤԼ������Ŀ,0δԤԼ��1ԤԼ
	int espneed[4];//��ߡ���˵�����ϡ�ĸӤ
	int booktime[2];//����ԤԼ��ʱ��
	int needtime[2];//���������ʱ��

	int daytic1;//����Ʊ
	char t1[40];
	int daytic2;//��ͯ����Ʊ
	char t2[40];
	int monthtic;//��Ʊ
	char t3[40];
	int yeartic;//��Ʊ
	char t4[40];

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
	int esptic[9];//������ĿƱ����
	int normaltic[4];//��ͨƱ����Ʊ

	int esptic_now[9];
	int normaltic_now[4];
}ADMIN;


typedef struct PROJECT
{
	int num;//���
	char pname[30];//����
	char open_close;//oΪ���ţ�cΪ������
	char type;//1�̼���2���ӣ�3���֣�0������Ŀ
	int play_time;//��ĿԤ������ʱ��
	int wait_people;//���ڵȴ����ο�����
}PROJECT;





/*******************************************************************/
typedef struct UserList
{
	struct USER* elem;    //�洢�ռ��ֵ
	int length;  //��ǰ����
	int listsize;  //��ǰ����洢�ռ�����
}UserList;//�û����Ա� 


/*����һ���ձ�*/
void InitUList(UserList*UL);

/*�����Ա�UL��ĩβ�����µ�Ԫ��e*/
void UListInsert(UserList*UL,struct USER e);

/*ɾ��Ԫ��*/
void UListDelete(UserList*L,int i);


/*�����Ա�L���ڣ��������Ա�*/
void DestroyUList(UserList*UL);	

/*����Ԫ��e�����Ա��е�λ��*/
int Userposition(UserList UL,USER e);

//��ʾ���
void show_gb(int x,int y);
//�õ���ʾ��Ϣ
void Get_account(int x1,int y1,char *name,char *judge);
//�õ�����
void Get_code(int x1,int y1,char *name,char *judge);
//�������
void Check_code(int x1,int y1,char *judge);
//�����û���Ϣ
int save_user(USER temp);

void ReadAllUser(UserList *UL);

void UpdataUser(USER user);


#endif