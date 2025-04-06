#ifndef _BUSI_DET_H
#define _BUSI_DET_H

void business_detail(int order_index);

void draw_b_order_info(Order currentOrder);
void draw_b_pagination_buttons();
void draw_b_order_items(Order currentOrder, int startIdx, int endIdx, int item_y);
void draw_b_total_amount(Order currentOrder, int item_y);
void draw_business_detail(OrderList *OL, int order_index, int page);

#endif