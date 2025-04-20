#ifndef __ARRANGE_H__
#define __ARRANGE_H__
int Manhattan_Distance(int x1, int y1, int x2, int y2);
int arrange(int start_idx, Acp_order acp_orders[], int n_orders) ;
void calculate_centered_text(int rect_x1, int rect_y1, int rect_x2, int rect_y2, const char *text, int font_size, int *text_x, int *text_y) ;
void draw_arrange(int j, Acp_order acp_orders[], int start_index, int best_i, int best_type);

#endif