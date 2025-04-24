#ifndef __USER_DE_H__
#define __USER_DE_H__

#define D_LIST_INIT_SIZE 10 //���Ա�洢�ռ�ĳ�ʼ������
#define D_LISTINCEREMENT 1  //���Ա�洢�ռ�ķ�������

typedef struct Deliver
{
    int id; // ������
    int type; // �������
    char name[10]; // �û���
    char number[12];//�ֻ���
    int community; //��ַ 1���� 2���� 3���� 4��ݿ 5��Է
	int building;//¥����
    int destination;//�ʹ��ַ
    char time[20]; // �µ�ʱ�� 
    char code[10]; //ȡ����
    int company; // ��ݹ�˾
    int station; // վ��
    int index;
    int total_cnt;
    int acp_count;
    int hst_count;
} Deliver;

typedef struct DeliverList
{
	struct Deliver* elem;    //�洢�ռ��ַ
	short length;  //��ǰ���ȣ���Ϊ short
	short listsize;  //��ǰ�洢�ռ���������Ϊ short
}DeliverList;//�������Ա� 

typedef struct Company{//��ݹ�˾
    char name[20];//����
}Company;

typedef struct Station{//վ��
    char name[20];//����
}Station;

void user_deliver();
void draw_user_deliver();
int choose_company(int x, int y, int* last_index);
int choose_station(int x, int y, int* last_index_station);

void deliver_input(char *deliver_code,int bar_x1,int bar_y1,int bar_x2,int bar_y2);

int Deliver_pos(DeliverList DL,Deliver delivers);
void DListInsert(DeliverList*DL,Deliver delivers);
int save_Deliver(Deliver delivers);
void DestroyDList(DeliverList*DL);
void ReadAllDeliver(DeliverList *DL);

#endif