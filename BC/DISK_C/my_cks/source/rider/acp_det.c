#include "all_func.h"
#define MAX_COMBINED_ORDERS 20  

// void acp_order_detail(int page,int order_index,OrderList *OL,FoodList  *FL)
// {
//     /* 所有变量声明放在最前面，兼容旧编译器 */
//     int          i, cnt;
//     int          per_page;
//     int          start, end;
//     int          dist_m, y_offset;
//     double       dist_km, fee;
//     FoodOrder    combined[MAX_COMBINED_ORDERS];
//     char         buf[64];
//     FoodOrder   *o;

//     /*—— 1) 先把超市订单和食堂订单合并 ——*/
//     cnt = 0;
//     for (i = 0; i < OL->length && cnt < MAX_COMBINED_ORDERS; i++) {
//         combined[cnt].pick_up_location = OL->elem[i].pick_up_location;
//         combined[cnt].destination      = OL->elem[i].destination;
//         combined[cnt].total_amount     = OL->elem[i].total_amount;
//         strcpy(combined[cnt].user_name,  OL->elem[i].user_name);
//         strcpy(combined[cnt].order_time, OL->elem[i].order_time);
//         combined[cnt].station = 0;  /* 标记：超市 */
//         cnt++;
//     }
//     for (i = 0; i < FL->length && cnt < MAX_COMBINED_ORDERS; i++) {
//         combined[cnt++] = FL->elem[i];
//     }

//     /*—— 2) 定位到本页里的全局 index ——*/
//     per_page = 4;
//     start    = page * per_page;
//     end      = start + per_page;
//     if (start > cnt) start = cnt;
//     if (end   > cnt) end   = cnt;

//     /*—— 3) 取出被点击的那条订单 ——*/
//     o = NULL;
//     if (order_index >= start && order_index < end) {
//         o = &combined[order_index];
//     }
//     if (o == NULL) {
//         /* 索引不在本页范围内，直接返回 */
//         return;
//     }

//     /*—— 4) 清屏并关闭鼠标箭头 ——*/
//     mouse_off_arrow(&mouse);
//     bar1(0, 150, 1024, 768, white);

//     /*—— 5) 绘制“订单详情”标题 ——*/
//     PrintCC(512, 80, "订单详情", HEI, 28, 1, deepblue);

//     /*—— 6) 逐行显示详细信息 ——*/
//     y_offset = 150;

//     /* 用户信息 */
//     sprintf(buf, "下单人：%s", o->user_name);
//     PrintText(200, y_offset, buf, HEI, 24, 1, 0x0000);
//     y_offset += 40;

//     /* 取餐地点 */
//     sprintf(buf, "取餐点：%s", node[o->pick_up_location].name);
//     PrintText(200, y_offset, buf, HEI, 24, 1, 0x0000);
//     y_offset += 40;

//     /* 送达地点 */
//     sprintf(buf, "送达点：%s", node[o->destination].name);
//     PrintText(200, y_offset, buf, HEI, 24, 1, 0x0000);
//     y_offset += 40;

//     /* 下单时间 */
//     sprintf(buf, "下单时间：%s", o->order_time);
//     PrintText(200, y_offset, buf, HEI, 24, 1, 0x0000);
//     y_offset += 40;

//     /* 计算并显示距离 */
//     dist_m  = dijkstra(&node[o->pick_up_location],
//                        &node[o->destination], 3);
//     dist_km = dist_m / 1000.0;
//     sprintf(buf, "距离：%.2f公里", dist_km);
//     PrintText(200, y_offset, buf, HEI, 24, 1, 0x0000);
//     y_offset += 40;

//     /* 计算并显示配送费 */
//     fee = rider_deliver_price(dist_m, o->total_amount);
//     sprintf(buf, "配送费：%.2f元", fee);
//     PrintText(200, y_offset, buf, HEI, 24, 1, 0x0000);
//     y_offset += 60;

//     /*—— 7) 绘制“返回”按钮 ——*/
//     Draw_Rounded_Rectangle(40, 113, 160, 163, 25, 1, deepblue);
//     PrintCC(75, 128, "返回", HEI, 24, 1, deepblue);

//     /*—— 8) 等待用户点击“返回” ——*/
//     while (1) {
//         mouse_show_arrow(&mouse);
//         if (mouse_press(40, 113, 160, 163) == 1) {
//             break;
//         }
//     }

//     /*—— 9) 返回接单页面 ——*/
//     mouse_off_arrow(&mouse);
//     bar1(0, 150, 1024, 768, white);
//     draw_accept_order(page, OL, FL);
//     mouse_on_arrow(mouse);
// }

void accept_order_detail()
{

    
    int page = 0;// 初始页码
    int totalPage; // 总页数
    int i;
    int cnt=0;
}
