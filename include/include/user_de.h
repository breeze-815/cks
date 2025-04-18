#ifndef __USER_DE_H__
#define __USER_DE_H__

#define D_LIST_INIT_SIZE 10 //���Ա�洢�ռ�ĳ�ʼ������
#define D_LISTINCEREMENT 1  //���Ա�洢�ռ�ķ�������

typedef struct Deliver
{
    int id; // ������
    int type; // �������
    char name[10]; // �������
    char code[10]; // ��ݵ���
    int station; // վ��
} Deliver;

typedef struct DeliverList
{
	struct Deliver* elem;    //�洢�ռ��ַ
	short length;  //��ǰ���ȣ���Ϊ short
	short listsize;  //��ǰ�洢�ռ���������Ϊ short
}DeliverList;//�������Ա� 

void user_deliver();
void draw_user_deliver();
void press_station(int x);

void deliver_input(char *deliver_code,int bar_x1,int bar_y1,int bar_x2,int bar_y2);

int Deliver_pos(DeliverList DL,Deliver delivers);
void DListInsert(DeliverList*DL,Deliver delivers);
int save_Deliver(Deliver delivers);
void DestroyDList(DeliverList*DL);
void ReadAllDeliver(DeliverList *DL);

#endif