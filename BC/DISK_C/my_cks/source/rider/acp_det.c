#include "all_func.h"
#define MAX_COMBINED_ORDERS 20  

// void acp_order_detail(int page,int order_index,OrderList *OL,FoodList  *FL)
// {
//     /* ���б�������������ǰ�棬���ݾɱ����� */
//     int          i, cnt;
//     int          per_page;
//     int          start, end;
//     int          dist_m, y_offset;
//     double       dist_km, fee;
//     FoodOrder    combined[MAX_COMBINED_ORDERS];
//     char         buf[64];
//     FoodOrder   *o;

//     /*���� 1) �Ȱѳ��ж�����ʳ�ö����ϲ� ����*/
//     cnt = 0;
//     for (i = 0; i < OL->length && cnt < MAX_COMBINED_ORDERS; i++) {
//         combined[cnt].pick_up_location = OL->elem[i].pick_up_location;
//         combined[cnt].destination      = OL->elem[i].destination;
//         combined[cnt].total_amount     = OL->elem[i].total_amount;
//         strcpy(combined[cnt].user_name,  OL->elem[i].user_name);
//         strcpy(combined[cnt].order_time, OL->elem[i].order_time);
//         combined[cnt].station = 0;  /* ��ǣ����� */
//         cnt++;
//     }
//     for (i = 0; i < FL->length && cnt < MAX_COMBINED_ORDERS; i++) {
//         combined[cnt++] = FL->elem[i];
//     }

//     /*���� 2) ��λ����ҳ���ȫ�� index ����*/
//     per_page = 4;
//     start    = page * per_page;
//     end      = start + per_page;
//     if (start > cnt) start = cnt;
//     if (end   > cnt) end   = cnt;

//     /*���� 3) ȡ����������������� ����*/
//     o = NULL;
//     if (order_index >= start && order_index < end) {
//         o = &combined[order_index];
//     }
//     if (o == NULL) {
//         /* �������ڱ�ҳ��Χ�ڣ�ֱ�ӷ��� */
//         return;
//     }

//     /*���� 4) �������ر�����ͷ ����*/
//     mouse_off_arrow(&mouse);
//     bar1(0, 150, 1024, 768, white);

//     /*���� 5) ���ơ��������顱���� ����*/
//     PrintCC(512, 80, "��������", HEI, 28, 1, deepblue);

//     /*���� 6) ������ʾ��ϸ��Ϣ ����*/
//     y_offset = 150;

//     /* �û���Ϣ */
//     sprintf(buf, "�µ��ˣ�%s", o->user_name);
//     PrintText(200, y_offset, buf, HEI, 24, 1, 0x0000);
//     y_offset += 40;

//     /* ȡ�͵ص� */
//     sprintf(buf, "ȡ�͵㣺%s", node[o->pick_up_location].name);
//     PrintText(200, y_offset, buf, HEI, 24, 1, 0x0000);
//     y_offset += 40;

//     /* �ʹ�ص� */
//     sprintf(buf, "�ʹ�㣺%s", node[o->destination].name);
//     PrintText(200, y_offset, buf, HEI, 24, 1, 0x0000);
//     y_offset += 40;

//     /* �µ�ʱ�� */
//     sprintf(buf, "�µ�ʱ�䣺%s", o->order_time);
//     PrintText(200, y_offset, buf, HEI, 24, 1, 0x0000);
//     y_offset += 40;

//     /* ���㲢��ʾ���� */
//     dist_m  = dijkstra(&node[o->pick_up_location],
//                        &node[o->destination], 3);
//     dist_km = dist_m / 1000.0;
//     sprintf(buf, "���룺%.2f����", dist_km);
//     PrintText(200, y_offset, buf, HEI, 24, 1, 0x0000);
//     y_offset += 40;

//     /* ���㲢��ʾ���ͷ� */
//     fee = rider_deliver_price(dist_m, o->total_amount);
//     sprintf(buf, "���ͷѣ�%.2fԪ", fee);
//     PrintText(200, y_offset, buf, HEI, 24, 1, 0x0000);
//     y_offset += 60;

//     /*���� 7) ���ơ����ء���ť ����*/
//     Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1, deepblue);
//     PrintCC(75, 128, "����", HEI, 24, 1, deepblue);

//     /*���� 8) �ȴ��û���������ء� ����*/
//     while (1) {
//         mouse_show_arrow(&mouse);
//         if (mouse_press(40, 113, 160, 163) == 1) {
//             break;
//         }
//     }

//     /*���� 9) ���ؽӵ�ҳ�� ����*/
//     mouse_off_arrow(&mouse);
//     bar1(0, 150, 1024, 768, white);
//     draw_accept_order(page, OL, FL);
//     mouse_on_arrow(mouse);
// }

void accept_order_detail()
{

    
    int page = 0;// ��ʼҳ��
    int totalPage; // ��ҳ��
    int i;
    int cnt=0;
}
