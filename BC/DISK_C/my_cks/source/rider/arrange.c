#include <all_func.h>

#define MAX_ORDERS 4
//test_demo
Acp_order acp_orders[4] = {
    //  id        pick  dest  comm  bldg  user_name    user_phone
    { "0001",    1,    40,    2,    2,   "张三",       "18682353005" }, // 1号订单，韵苑食堂取餐，西一宿舍送餐，用户名：张三，电话：18682353005
    { "0002",   10,    26,    4,    5,   "李四",       "18682353006" }, // 2号订单，东三食堂取餐，紫菘5栋送餐，用户名：李四，电话：18682353006
    { "0003",    5,    56,    3,    1,   "王五",       "18682353007" }, // 3号订单，东教工食堂取餐，南一宿舍送餐，用户名：王五，电话：18682353007
    { "0004",   19,    62,    1,    4,   "赵六",       "18682353008" } // 4号订单，喻园超市取餐，东四宿舍送餐，用户名：赵六，电话：18682353008  
};

int Manhattan_Distance(int x1, int y1, int x2, int y2) 
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int arrange(int start_idx, Acp_order acp_orders[], int n_orders)
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
    char buf[64];
    int next_index;
    int next_pos;
    int next_type;

    for(i = 0; i < n_orders; i++) 
    {
        temp_picked[i] = route_state.picked[i];
        temp_delivered[i] = route_state.delivered[i];
    }
    temp_remaining = route_state.remaining;
    temp_current = route_state.current_pos;
    temp_step = 0;
    /*—— 主循环 ——*/

    if(temp_remaining == 0) {
        PrintText(150, 200, "您已完成所有订单", HEI, 24, 1, black);
        return -1; // 返回-1表示没有可执行任务
    }
    while (temp_remaining > 0) {
        /*—— 找最近的可做任务 ——*/
        best_dist = 30000;
        best_i    = -1;
        best_type = -1;

        for (i = 0; i < n_orders; i++) {
            /* 取餐任务 */
            if (!temp_picked[i]) {
                dist = Manhattan_Distance(
                    node[temp_current].x, node[temp_current].y,
                    node[acp_orders[i].pick_up_index].x,
                    node[acp_orders[i].pick_up_index].y
                );
                if (dist < best_dist && dist != 0) {
                    best_dist = dist;
                    best_i    = i;
                    best_type = 0;
                }
            }
            /* 送餐任务 */
            else if (!temp_delivered[i]) {
                dist = Manhattan_Distance(
                    node[temp_current].x, node[temp_current].y,
                    node[acp_orders[i].destination_index].x,
                    node[acp_orders[i].destination_index].y
                );
                if (dist < best_dist && dist != 0) {
                    best_dist = dist;
                    best_i    = i;
                    best_type = 1;
                }
            }
        }

       temp_step++;
        /*—— 如果没有找到任务，就跳出 ——*/\

        if(temp_step==1)
        {
            if(best_type == 0)
            {
                next_pos = acp_orders[best_i].pick_up_index;
                next_type = 0;
            }
            else
            {
                next_pos = acp_orders[best_i].destination_index;
                next_type = 1;
            }
            next_index = best_i;
            route_state.next_pos = next_pos;
            route_state.next_type = next_type;
        }
        if (best_i < 0) {
            PrintText(50, 50, "调度异常：无可执行任务", HEI, 24, 1, black);
            break;
        }

        draw_arrange(temp_step, acp_orders, temp_current, best_i, best_type); 
        // 在 arrange 函数中添加位置更新逻辑
        if (best_type == 0) {
            temp_current = acp_orders[best_i].pick_up_index;
            temp_picked[best_i] = 1;
        } else {
            temp_current = acp_orders[best_i].destination_index;
            temp_delivered[best_i] = 1;
        }
        temp_remaining--;
    }  
    return next_index; 
}


void calculate_centered_text(int rect_x1, int rect_y1, int rect_x2, int rect_y2, const char *text, int font_size, int *text_x, int *text_y)
{
    int rect_width = rect_x2 - rect_x1;  // 矩形宽度
    int rect_height = rect_y2 - rect_y1; // 矩形高度

    int text_width = strlen(text) * font_size / 2; // 文本宽度估算，每个字符宽度约为字体大小的一半
    int text_height = font_size;                  // 文本高度等于字体大小

    // 计算居中的 x 和 y 坐标
    *text_x = rect_x1 + (rect_width - text_width) / 2;
    *text_y = rect_y1 + (rect_height - text_height) / 2;
}


//j为第几个地点，n_order为订单，n_order为订单数，start_index为起点,best_i为最优地点，best_type为最优地点类型
//best_type=0为取餐，best_type=1为送餐
void draw_arrange(int j, Acp_order acp_orders[], int start_index, int best_i, int best_type) 
{
    int text_x,text_y;
    char buf[20];
    int distance_m;
    float distance_km;
    int time_min; // 假设最小时间为1分钟
    int time_s;

    //Readbmp64k(0, 326, "bmp\\map4.bmp");
    Fill_Rounded_Rectangle(900, 266, 1020, 316, 5,deepblue);//已完成
    Draw_Rounded_Rectangle(900, 266, 1020, 316, 5, 1, deepblue);//已完成
    PrintCC(910, 276, "已完成", HEI, 24, 1, white);
    if (best_type == 0)
    distance_m = dijkstra(&node[start_index], &node[acp_orders[best_i].pick_up_index],j);//计算最短路径
    else 
    distance_m = dijkstra(&node[start_index], &node[acp_orders[best_i].destination_index],j);//计算最短路径

    distance_km = distance_m / 1000.0; // 转换为公里
    time_min = distance_m / 1000.0 * 60 / 20; // 假设平均速度为20km/h，计算时间
    if(time_min < 1) 
    time_s = time_min * 60; // 如果时间小于1分钟，转换为秒
    if(j==1) //第一个地点时打印起点
    {
        
        Draw_Rounded_Rectangle(10, 160, 130, 210, 5, 1, deepblue);//起点
        sprintf(buf, "%s",node[start_index].name);
        calculate_centered_text(10, 160, 130, 210, buf, 24, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 24, 1, black);//起点
    }
    
    if (j <= 4)  //地点在第一排
    {
        //画地点框
        Draw_Rounded_Rectangle(10 + 221*j, 160, 130 + 221*j, 210, 5, 1, deepblue);//1号
        if(best_type == 0)
        sprintf(buf, "%s",node[acp_orders[best_i].pick_up_index].name);
        else
        sprintf(buf, "%s",node[acp_orders[best_i].destination_index].name);

        calculate_centered_text(10 + 221*j, 160, 130 + 221*j, 210, buf, 24, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 24, 1, black);//1号
        //画箭头
        Line_Thick(221*j-91+3, 185, 10 + 221*j-3, 185, 3, black);//连线
        Line_Thick(10+221*j-3, 185, 221*j-10-3, 165, 3, black);
        Line_Thick(10+221*j-3, 185, 221*j-10-3, 205, 3, black);//箭头
        //标注距离
        sprintf(buf, "%.2fkm", distance_km);
        calculate_centered_text(221*j-91+3, 185-16*2 , 10+221*j-3, 185 , buf, 16, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 16, 1, black);//距离
        //标注时间
        if(time_min < 1)
        sprintf(buf, "%ds", time_s);
        else    
        sprintf(buf, "%dmin", time_min);
        calculate_centered_text(221*j-91+3, 185 , 10+221*j-3, 185+16*2 , buf, 16, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 16, 1, black);//时间
    }
    else
    {
        //画地点框
        Draw_Rounded_Rectangle(220*j-990, 266, 220*j-870, 316, 5, 1, deepblue);//1号
        if(best_type == 0)
        sprintf(buf, "%s",node[acp_orders[best_i].pick_up_index].name);
        else
        sprintf(buf, "%s",node[acp_orders[best_i].destination_index].name);
        calculate_centered_text(220*j-990, 266, 220*j-870, 316, buf, 24, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 24, 1, black);//1号
        //画箭头
        Line_Thick(220*j-1090+3, 291, 220*j-990-3, 291, 3, black);//连线
        Line_Thick(220*j-990-3, 291, 220*j-1010+3, 271, 3, black);
        Line_Thick(220*j-990-3, 291, 220*j-1010+3, 311, 3, black);//箭头
        //标注距离
        sprintf(buf, "%.2fkm", distance_km);
        calculate_centered_text(220*j-1090+3 ,291-16*2 ,220*j-990-3 ,291 , buf, 16,&text_x,&text_y);
        PrintText(text_x,text_y , buf , HEI ,16 ,1 ,black);//距离
        //标注时间
        if(time_min < 1)
        sprintf(buf, "%ds", time_s);
        else    
        sprintf(buf, "%dmin", time_min);
        calculate_centered_text(220*j-1090+3 ,291 ,220*j-990-3 ,291+16*2 , buf ,24,&text_x,&text_y);
        PrintText(text_x, text_y, buf, HEI, 16, 1, black);//时间
    }

}
