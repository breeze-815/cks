#ifndef __USER_DE_H__
#define __USER_DE_H__

#define D_LIST_INIT_SIZE 10 //线性表存储空间的初始分配量
#define D_LISTINCEREMENT 1  //线性表存储空间的分配增量

typedef struct Deliver
{
    int id; // 订单号
    int type; // 快递类型
    char name[10]; // 用户名
    char number[12];//手机号
    int community; //地址 1东区 2西区 3南区 4紫菘 5韵苑
	int building;//楼栋
    char time[20]; // 下单时间 
    char code[10]; //取件码
    int station; // 站点
    
} Deliver;

typedef struct DeliverList
{
	struct Deliver* elem;    //存储空间基址
	short length;  //当前长度，改为 short
	short listsize;  //当前存储空间容量，改为 short
}DeliverList;//订单线性表 

typedef struct Station{//站点
    char name[20];//名称
}Station;

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