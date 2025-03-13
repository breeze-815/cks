#ifndef _LGFUNC_H_
#define _LGFUNC_H_

#define U_LIST_INIT_SIZE 10 //���Ա�洢�ռ�ĳ�ʼ������
#define U_LISTINCEREMENT 1  //���Ա�洢�ռ�ķ�������

typedef struct USER
{
	char name[12];//�˻� 
	char code[12];//����

	int type;//�û����� 1Ϊ�û���2Ϊ�̼ң�3Ϊ����
	char number[12];//�ֻ���
	int address;//��ַ 1Ϊ��ݿ��2Ϊ��Է��3Ϊ��Է

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
void input_mode(char *name,char *code,char *judge,int bar_x1,int bar_y1,int bar_x2,int bar_y2,int mode);
//�����û���Ϣ
int save_user(USER temp);

void ReadAllUser(UserList *UL);

void UpdataUser(USER user);

#endif