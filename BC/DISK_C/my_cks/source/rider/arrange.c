#include <all_func.h>

#define MAX_ORDERS 4
//test_demo
Acp_order acp_orders[4] = {
    //  id        pick  dest  comm  bldg  user_name    user_phone
    { "0001",    1,    40,    2,    2,   "����",       "18682353005" }, // 1�Ŷ�������Էʳ��ȡ�ͣ���һ�����Ͳͣ��û������������绰��18682353005
    { "0002",   10,    26,    4,    5,   "����",       "18682353006" }, // 2�Ŷ���������ʳ��ȡ�ͣ���ݿ5���Ͳͣ��û��������ģ��绰��18682353006
    { "0003",    5,    56,    3,    1,   "����",       "18682353007" }, // 3�Ŷ��������̹�ʳ��ȡ�ͣ���һ�����Ͳͣ��û��������壬�绰��18682353007
    { "0004",   19,    62,    1,    4,   "����",       "18682353008" } // 4�Ŷ�������԰����ȡ�ͣ����������Ͳͣ��û������������绰��18682353008  
};

int Manhattan_Distance(int x1, int y1, int x2, int y2) 
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int arrange(int start_idx, Acp_order acp_orders[], int n_orders)
{
    int temp_picked[4]; // ��ʱ���飬���ڴ洢��ǰ������ȡ��״̬
    int temp_delivered[4];  // ��ʱ���飬���ڴ洢��ǰ�������Ͳ�״̬
    int temp_remaining;
    int temp_current;
    int temp_step;
    int best_i;
    int best_type;    // 0 = ȡ��, 1 = �Ͳ�
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
    /*���� ��ѭ�� ����*/

    if(temp_remaining == 0) {
        PrintText(150, 200, "����������ж���", HEI, 24, 1, black);
        return -1; // ����-1��ʾû�п�ִ������
    }
    while (temp_remaining > 0) {
        /*���� ������Ŀ������� ����*/
        best_dist = 30000;
        best_i    = -1;
        best_type = -1;

        for (i = 0; i < n_orders; i++) {
            /* ȡ������ */
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
            /* �Ͳ����� */
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
        /*���� ���û���ҵ����񣬾����� ����*/\

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
            PrintText(50, 50, "�����쳣���޿�ִ������", HEI, 24, 1, black);
            break;
        }

        draw_arrange(temp_step, acp_orders, temp_current, best_i, best_type); 
        // �� arrange ���������λ�ø����߼�
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
    int rect_width = rect_x2 - rect_x1;  // ���ο��
    int rect_height = rect_y2 - rect_y1; // ���θ߶�

    int text_width = strlen(text) * font_size / 2; // �ı���ȹ��㣬ÿ���ַ����ԼΪ�����С��һ��
    int text_height = font_size;                  // �ı��߶ȵ��������С

    // ������е� x �� y ����
    *text_x = rect_x1 + (rect_width - text_width) / 2;
    *text_y = rect_y1 + (rect_height - text_height) / 2;
}


//jΪ�ڼ����ص㣬n_orderΪ������n_orderΪ��������start_indexΪ���,best_iΪ���ŵص㣬best_typeΪ���ŵص�����
//best_type=0Ϊȡ�ͣ�best_type=1Ϊ�Ͳ�
void draw_arrange(int j, Acp_order acp_orders[], int start_index, int best_i, int best_type) 
{
    int text_x,text_y;
    char buf[20];
    int distance_m;
    float distance_km;
    int time_min; // ������Сʱ��Ϊ1����
    int time_s;

    //Readbmp64k(0, 326, "bmp\\map4.bmp");
    Fill_Rounded_Rectangle(900, 266, 1020, 316, 5,deepblue);//�����
    Draw_Rounded_Rectangle(900, 266, 1020, 316, 5, 1, deepblue);//�����
    PrintCC(910, 276, "�����", HEI, 24, 1, white);
    if (best_type == 0)
    distance_m = dijkstra(&node[start_index], &node[acp_orders[best_i].pick_up_index],j);//�������·��
    else 
    distance_m = dijkstra(&node[start_index], &node[acp_orders[best_i].destination_index],j);//�������·��

    distance_km = distance_m / 1000.0; // ת��Ϊ����
    time_min = distance_m / 1000.0 * 60 / 20; // ����ƽ���ٶ�Ϊ20km/h������ʱ��
    if(time_min < 1) 
    time_s = time_min * 60; // ���ʱ��С��1���ӣ�ת��Ϊ��
    if(j==1) //��һ���ص�ʱ��ӡ���
    {
        
        Draw_Rounded_Rectangle(10, 160, 130, 210, 5, 1, deepblue);//���
        sprintf(buf, "%s",node[start_index].name);
        calculate_centered_text(10, 160, 130, 210, buf, 24, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 24, 1, black);//���
    }
    
    if (j <= 4)  //�ص��ڵ�һ��
    {
        //���ص��
        Draw_Rounded_Rectangle(10 + 221*j, 160, 130 + 221*j, 210, 5, 1, deepblue);//1��
        if(best_type == 0)
        sprintf(buf, "%s",node[acp_orders[best_i].pick_up_index].name);
        else
        sprintf(buf, "%s",node[acp_orders[best_i].destination_index].name);

        calculate_centered_text(10 + 221*j, 160, 130 + 221*j, 210, buf, 24, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 24, 1, black);//1��
        //����ͷ
        Line_Thick(221*j-91+3, 185, 10 + 221*j-3, 185, 3, black);//����
        Line_Thick(10+221*j-3, 185, 221*j-10-3, 165, 3, black);
        Line_Thick(10+221*j-3, 185, 221*j-10-3, 205, 3, black);//��ͷ
        //��ע����
        sprintf(buf, "%.2fkm", distance_km);
        calculate_centered_text(221*j-91+3, 185-16*2 , 10+221*j-3, 185 , buf, 16, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 16, 1, black);//����
        //��עʱ��
        if(time_min < 1)
        sprintf(buf, "%ds", time_s);
        else    
        sprintf(buf, "%dmin", time_min);
        calculate_centered_text(221*j-91+3, 185 , 10+221*j-3, 185+16*2 , buf, 16, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 16, 1, black);//ʱ��
    }
    else
    {
        //���ص��
        Draw_Rounded_Rectangle(220*j-990, 266, 220*j-870, 316, 5, 1, deepblue);//1��
        if(best_type == 0)
        sprintf(buf, "%s",node[acp_orders[best_i].pick_up_index].name);
        else
        sprintf(buf, "%s",node[acp_orders[best_i].destination_index].name);
        calculate_centered_text(220*j-990, 266, 220*j-870, 316, buf, 24, &text_x, &text_y);
        PrintText(text_x, text_y, buf, HEI, 24, 1, black);//1��
        //����ͷ
        Line_Thick(220*j-1090+3, 291, 220*j-990-3, 291, 3, black);//����
        Line_Thick(220*j-990-3, 291, 220*j-1010+3, 271, 3, black);
        Line_Thick(220*j-990-3, 291, 220*j-1010+3, 311, 3, black);//��ͷ
        //��ע����
        sprintf(buf, "%.2fkm", distance_km);
        calculate_centered_text(220*j-1090+3 ,291-16*2 ,220*j-990-3 ,291 , buf, 16,&text_x,&text_y);
        PrintText(text_x,text_y , buf , HEI ,16 ,1 ,black);//����
        //��עʱ��
        if(time_min < 1)
        sprintf(buf, "%ds", time_s);
        else    
        sprintf(buf, "%dmin", time_min);
        calculate_centered_text(220*j-1090+3 ,291 ,220*j-990-3 ,291+16*2 , buf ,24,&text_x,&text_y);
        PrintText(text_x, text_y, buf, HEI, 16, 1, black);//ʱ��
    }

}
