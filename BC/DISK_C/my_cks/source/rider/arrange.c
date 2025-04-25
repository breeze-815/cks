#include <all_func.h>
#define ORDERS_PER_PAGE   4

#define ORDER_SUPERMARKET 0
#define ORDER_FOOD        1
#define ORDER_DELIVER     2

void arrange(int start_idx, AcceptedOrder cur_orders[], int n_orders)
{
    int temp_picked[4]; // 临时数组，用于存储当前订单的取餐状态
    int temp_delivered[4];  // 临时数组，用于存储当前订单的送餐状态
    int temp_remaining;
    int temp_current;
    int temp_step;
    int best_i;
    int best_type;    // 0 = 取餐, 1 = 送餐
    int dist;
    int best_dist;
    int i;
    char buf[100];
    int next_index;
    int next_pos;
    int next_type;
    char debuf[10];
    int step=0;
    for(i = 0; i < n_orders; i++)  //拷贝数据状态
    {
        temp_picked[i] = route_state.picked[i];
        temp_delivered[i] = route_state.delivered[i];
    }
    temp_remaining = route_state.remaining;
    temp_current = route_state.current_pos;
    temp_step = 0;
    /*—— 主循环 ——*/

    if(temp_remaining == 0) {
        bar1(0,150,1024,326,white);
        PrintText(400, 250, "当前暂无任务", HEI, 36, 1, Red);
        return -1; // 返回-1表示没有可执行任务
    }
    while (temp_remaining > 0) 
    {
        /*—— 找最近的可做任务 ——*/
        best_dist = 20000;
        best_i    = -1;
        best_type = -1;

        for (i = 0; i < n_orders; i++) 
        {
            /* 取餐任务 */
            int pu_idx, dst_idx;

            if (!temp_picked[i]) {
                // 取餐
                if (cur_orders[i].type == ORDER_SUPERMARKET) {
                    pu_idx = cur_orders[i].data.order.pick_up_location;
                } else if (cur_orders[i].type == ORDER_FOOD) {
                    pu_idx = cur_orders[i].data.food.station;
                } else {
                    pu_idx = cur_orders[i].data.deliver.station;
                }

                dist = Manhattan_Distance(
                    node[temp_current].x, node[temp_current].y,
                    node[pu_idx].x,        node[pu_idx].y
                );
                if (dist < best_dist ) {
                    best_dist = dist;
                    best_i    = i;
                    best_type = 0;
                }
            }
            else if (!temp_delivered[i]) {
                // 送餐
                if (cur_orders[i].type == ORDER_SUPERMARKET) {
                    dst_idx = cur_orders[i].data.order.destination;
                } else if (cur_orders[i].type == ORDER_FOOD) {
                    dst_idx = cur_orders[i].data.food.destination;
                } else {
                    dst_idx = cur_orders[i].data.deliver.index;
                }

                dist = Manhattan_Distance(
                    node[temp_current].x, node[temp_current].y,
                    node[dst_idx].x,      node[dst_idx].y
                );
                if (dist < best_dist ) 
                {
                    best_dist = dist;
                    best_i    = i;
                    best_type = 1;
                }
            }   
        }
        if (best_i < 0)
            break;
        if(best_type == 0)
        {
            if (cur_orders[best_i].type == ORDER_SUPERMARKET) {
                next_pos = cur_orders[best_i].data.order.pick_up_location;
            } else if (cur_orders[best_i].type == ORDER_FOOD) {
                next_pos = cur_orders[best_i].data.food.station;
            } else {
                next_pos = cur_orders[best_i].data.deliver.station;
            }
            next_type = 0;
        }
        else
        {
            if (cur_orders[best_i].type == ORDER_SUPERMARKET) {
                next_pos = cur_orders[best_i].data.order.destination;
            } else if (cur_orders[best_i].type == ORDER_FOOD) {
                next_pos = cur_orders[best_i].data.food.destination;
            } else {
                next_pos = cur_orders[best_i].data.deliver.index;
            }
            next_type = 1;
        }        
        // 存入序列
        route_state.seq_pos[step]  = next_pos;
        route_state.seq_type[step] = best_type;
        route_state.seq_order[step] = best_i;
        // 标记已完成
        if (best_type == 0) 
            temp_picked[best_i] = 1;
        else               
            temp_delivered[best_i] = 1;
        temp_current = next_pos;
        temp_remaining--;
        step++;
    }
    route_state.seq_len = step;
}

//step是步数，cur_orders[]为当前接单的结构体，start_index为起点，best_i为下一个点的订单数，best_
void draw_arrange(int step, struct AcceptedOrder cur_orders[], int start_index, int end_index) 
{
    int text_x,text_y;
    char buf[100];
    int distance_m;
    float distance_km;
    float time_min; // 假设最小时间为1分钟
    int time_m;
    int time_s;
    
    //绘制已完成按钮
    Fill_Rounded_Rectangle(900, 266, 1020, 316, 5,deepblue);//已完成
    Draw_Rounded_Rectangle(900, 266, 1020, 316, 5, 1, deepblue);//已完成
    PrintCC(910, 276, "已完成", HEI, 24, 1, white);

    //计算两点间距离和时间
    distance_m = dijkstra(&node[start_index], &node[end_index], 3);
    distance_km = distance_m / 1000.0; // 转换为公里
    time_min = distance_m / 1000.0 * 60 / 20; // 假设平均速度为20km/h，计算时间

    if(step==1) //第一个地点时打印起点
    {
        Draw_Rounded_Rectangle(10, 160, 130, 210, 5, 1, deepblue);
        sprintf(buf, "%s",node[start_index].name);
        calculate_centered_text(10, 160, 130, 210, buf, 24, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 24, 1, black);
    }
    
    if (step <= 4)  //地点在第一排
    {
        //画地点框
        Draw_Rounded_Rectangle(10 + 221*step, 160, 130 + 221*step, 210, 5, 1, deepblue);//1号
        sprintf(buf, "%s",node[end_index].name);
        calculate_centered_text(10 + 221*step, 160, 130 + 221*step, 210, buf, 24, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 24, 1, black);//1号
        //画箭头
        Line_Thick(221*step-91+3, 185, 10 + 221*step-3, 185, 3, black);//连线
        Line_Thick(10+221*step-3, 185, 221*step-10-3, 165, 3, black);
        Line_Thick(10+221*step-3, 185, 221*step-10-3, 205, 3, black);//箭头
        //标注距离
        sprintf(buf, "%.2fkm", distance_km);
        calculate_centered_text(221*step-91+3, 185-16*2 , 10+221*step-3, 185 , buf, 16, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 16, 1, black);//距离
        //标注时间
        if(time_min < 1.0) 
        {
            time_s = (int)(time_min * 60.0 + 0.5);  // 四舍五入
            sprintf(buf, "%ds", time_s);
        }
        else 
        {
            time_m = (int)(time_min + 0.5);
            sprintf(buf, "%dmin", time_m);
        }
        calculate_centered_text(221*step-91+3, 185 , 10+221*step-3, 185+16*2 , buf, 16, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 16, 1, black);//时间
    }
    else
    {
        //画地点框
        Draw_Rounded_Rectangle(220*step-990, 266, 220*step-870, 316, 5, 1, deepblue);//1号
        sprintf(buf, "%s",node[end_index].name);
        calculate_centered_text(220*step-990, 266, 220*step-870, 316, buf, 24, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 24, 1, black);//1号
        //画箭头
        Line_Thick(220*step-1090+3, 291, 220*step-990-3, 291, 3, black);//连线
        Line_Thick(220*step-990-3, 291, 220*step-1010+3, 271, 3, black);
        Line_Thick(220*step-990-3, 291, 220*step-1010+3, 311, 3, black);//箭头
        //标注距离
        sprintf(buf, "%.2fkm", distance_km);
        calculate_centered_text(220*step-1090+3 ,291-16*2 ,220*step-990-3 ,291 , buf, 16,&text_x,&text_y);
        PrintText(text_x,text_y , buf , HEI ,16 ,1 ,black);//距离
        //标注时间
        if(time_min < 1.0) 
        {
            time_s = (int)(time_min * 60.0 + 0.5);  // 四舍五入
            sprintf(buf, "%ds", time_s);
        }
        else 
        {
            time_m = (int)(time_min + 0.5);
            sprintf(buf, "%dmin", time_m);
        }
        calculate_centered_text(220*step-1090+3 ,291 ,220*step-990-3 ,291+16*2 , buf ,24,&text_x,&text_y);
        PrintText(text_x, text_y, buf, HEI, 16, 1, black);//时间
    }
}



void calculate_centered_text(int rect_x1, int rect_y1, int rect_x2, int rect_y2, const char *text, int font_size, int *text_x, int *text_y)
{
    int rect_width = rect_x2 - rect_x1;  
    int rect_height = rect_y2 - rect_y1;

    int text_width = strlen(text) * font_size / 2; 
    int text_height = font_size;                  

    
    *text_x = rect_x1 + (rect_width - text_width) / 2;
    *text_y = rect_y1 + (rect_height - text_height) / 2;
}

int Manhattan_Distance(int x1, int y1, int x2, int y2) 
{
    return abs(x1 - x2) + abs(y1 - y2);
}
