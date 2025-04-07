#ifndef _LGFUNC_H_
#define _LGFUNC_H_

#define U_LIST_INIT_SIZE 10 //���Ա�洢�ռ�ĳ�ʼ������
#define U_LISTINCEREMENT 1  //���Ա�洢�ռ�ķ�������

typedef struct USER
{
	char name[12];//�˻� 
	char code[12];//����

	char type;//�û����� 1Ϊ�û���2Ϊ�̼ң�3Ϊ����
	char number[12];//�ֻ���
	char address;//��ַ 1��ݿ��2��Է��2��Է
	int pos;//�û����б���λ��

}USER;

typedef struct UserList
{
	struct USER* elem;    //�洢�ռ��ַ
	short length;  //��ǰ���ȣ���Ϊ short
	short listsize;  //��ǰ�洢�ռ���������Ϊ short
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

int Check_info(UserList UL, char name[12], char code[12]);

#endif