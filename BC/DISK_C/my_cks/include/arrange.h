#ifndef __ARRANGE_H__
#define __ARRANGE_H__

typedef struct AcceptedOrder{
    int type; // 0:超市, 1:食品, 2:快递
    union {
        Order order;
        FoodOrder food;
        Deliver deliver;
    } data;
    float deliver_price;
} AcceptedOrder;//已接取的订单
int arrange(int start_idx, struct AcceptedOrder acp_orders[], int n_orders);
void draw_arrange(int j, struct AcceptedOrder acp_orders[], int start_index, int best_i, int best_type);
void calculate_centered_text(int rect_x1, int rect_y1, int rect_x2, int rect_y2, const char *text, int font_size, int *text_x, int *text_y);
int Manhattan_Distance(int x1, int y1, int x2, int y2);

#endif