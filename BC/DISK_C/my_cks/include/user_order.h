#ifndef __USER_ORDER_H__
#define __USER_ORDER_H__

#define O_LIST_INIT_SIZE 10 //ÏßĞÔ±í´æ´¢¿Õ¼äµÄ³õÊ¼·ÖÅäÁ¿
#define O_LISTINCEREMENT 1  //ÏßĞÔ±í´æ´¢¿Õ¼äµÄ·ÖÅäÔöÁ¿

typedef struct Order{
    int id;//¶©µ¥ºÅ
    int address;//ÓÃ»§µØÖ·
    char user_name[12];//ÓÃ»§Ãû
    char user_phone[12];//ÓÃ»§ÊÖ»úºÅ
    char order_time[20];//ÏÂµ¥Ê±¼ä
    CartItem item[20];//¹ºÎï³µÄÚÎïÆ·ĞÅÏ¢
    int itemCount;//¹ºÎï³µÄÚÎïÆ·ÖÖÀàÊıÁ¿
    float total_amount;//×Ü¼Û
} Order;//¶©µ¥ĞÅÏ¢

typedef struct OrderList
{
	struct Order* elem;    //´æ´¢¿Õ¼ä»ùÖ·
	short length;  //µ±Ç°³¤¶È£¬¸ÄÎª short
	short listsize;  //µ±Ç°´æ´¢¿Õ¼äÈİÁ¿£¬¸ÄÎª short
}OrderList;//¶©µ¥ÏßĞÔ±í 

void user_order();

void draw_page_header(USER *currentUser, int order_id, char *current_time);
void draw_pagination_buttons();
void draw_order_items(int startIdx, int endIdx, int item_y);
void draw_total_amount(int item_y);
void store_order_data(char *current_time, USER *currentUser, float total_amount);
void draw_user_order(int page);
<<<<<<< HEAD
void draw_info();

void draw_user_order(int page);


=======
>>>>>>> parent of 36a1d1b (æ›´æ”¹è¾“å…¥æ¡†)
char* get_current_time();

void InitOList(OrderList*OL);
void ReadAllOrder(OrderList *OL);
void DestroyOList(OrderList*OL);
int Order_pos(OrderList OL,Order orders);
void OListInsert(OrderList*OL,struct Order e);
int save_order(Order orders);

#endif