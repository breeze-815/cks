#include <all_func.h>

// typedef struct Button{
//     int commmunity; // 社区编号
//     int x1, y1, x2, y2; // 按钮坐标
//     int number;          // 楼栋编号
// } Button;

Button button [] = {
    {0, 0, 0, 0, 0, 0}, // 占位符
    //东区
    {1, 273, 364, 393, 414, 1}, // 1栋
    {1, 459, 364, 579, 414, 2}, // 2栋
    {1, 645, 364, 765, 414, 3}, // 3栋
    {1, 831, 364, 951, 414, 4}, // 4栋
    {1, 273, 464, 393, 514, 5}, // 5栋
    {1, 459, 464, 579, 514, 6}, // 6栋
    {1, 645, 464, 765, 514, 7}, // 7栋
    {1, 831, 464, 951, 514, 8}, // 8栋
    {1, 273, 564 ,393 ,614 ,9},  //9栋
    {1 ,459 ,564 ,579 ,614 ,10},//10栋
    {1 ,645 ,564 ,765 ,614 ,11},//11栋
    {1 ,831 ,564 ,951 ,614 ,12},//12栋
    {1 ,273 ,664 ,393 ,714 ,13},//13栋
    
    // ----------------------------------
    // 西区
    {2, 242, 364, 362, 414, 1}, // 1栋
    {2, 397, 364, 517, 414, 2}, // 2栋
    {2, 552, 364, 672, 414, 3}, // 3栋
    {2, 707, 364, 827, 414, 4}, // 4栋
    {2, 862, 364, 982, 414, 5}, // 5栋
    {2, 242, 464, 362, 514, 6}, // 6栋
    {2, 397, 464, 517, 514, 7}, // 7栋
    {2, 552, 464 ,672 ,514 ,8}, //8栋
    {2 ,707 ,464 ,827 ,514 ,9}, //9栋
    {2 ,862 ,464 ,982 ,514 ,10},//10栋
    {2 ,242 ,564 ,362 ,614 ,11},//11栋
    {2 ,397 ,564 ,517 ,614 ,12},//12栋
    {2 ,552 ,564 ,672 ,614 ,13},//13栋
    {2 ,707 ,564 ,827 ,614 ,14},//14栋
    {2 ,862 ,564 ,982 ,614 ,15},//15栋
    {2 ,242 ,664 ,362 ,714 ,16},//16栋
    {2 ,397 ,664 ,517 ,714 ,17}, //17栋

    // ----------------------------------
    // 南区
    {3, 273, 364, 393, 414, 1}, // 1栋
    {3, 459, 364, 579, 414, 2}, // 2栋
    {3, 645, 364, 765, 414, 3}, // 3栋

    // ----------------------------------
    // 紫菘
    {4, 242, 364, 362, 414, 1}, // 1栋
    {4, 397, 364, 517, 414, 2}, // 2栋
    {4, 552, 364, 672, 414, 3}, // 3栋
    {4, 707, 364, 827, 414, 4}, // 4栋
    {4, 862, 364, 982, 414, 5}, // 5栋
    {4, 242, 464, 362, 514, 6}, // 6栋
    {4, 397, 464 ,517 ,514 ,7}, // 7栋
    {4, 552 ,464 ,672 ,514 ,8}, // 8栋
    {4, 707 ,464 ,827 ,514 ,9}, // 9栋
    {4, 862 ,464 ,982 ,514 ,10},// 10栋
    {4, 242 ,564 ,362 ,614 ,11},// 11栋
    {4, 397 ,564 ,517 ,614 ,12},// 12栋
    {4, 552 ,564 ,672 ,614 ,13},// 13栋
    {4, 707 ,564 ,827 ,614 ,14},// 14栋
    {4, 862 ,564 ,982 ,614 ,15},// 15栋
    {4, 242 ,664 ,362 ,714 ,16},// 16栋
    {4, 397 ,664 ,517 ,714 ,17},// 17栋
    {4, 552 ,664 ,672 ,714 ,18},// 18栋

    // ----------------------------------
    // 韵苑
    {5, 232, 340, 332, 390, 1}, // 1栋
    {5, 364, 340, 464, 390, 2}, // 2栋
    {5, 496, 340, 596, 390, 3}, // 3栋
    {5, 628, 340, 728, 390, 4}, // 4栋
    {5, 760, 340, 860, 390, 5}, // 5栋
    {5, 892, 340 ,992 ,390 ,6}, //6栋
    {5 ,232 ,425 ,332 ,475 ,7}, //7栋
    {5 ,364 ,425 ,464 ,475 ,8}, //8栋
    {5 ,496 ,425 ,596 ,475 ,9}, //9栋
    {5 ,628 ,425 ,728 ,475 ,10}, //10栋
    {5 ,760 ,425 ,860 ,475 ,11}, //11栋
    {5 ,892 ,425 ,992 ,475 ,12}, //12栋
    {5 ,232 ,510 ,332 ,560 ,13}, //13栋
    {5 ,364 ,510 ,464 ,560 ,14}, //14栋
    {5 ,496 ,510 ,596 ,560 ,15}, //15栋
    {5 ,628 ,510 ,728 ,560 ,16}, //16栋
    {5 ,760 ,510 ,860 ,560 ,17}, //17栋
    {5, 892, 510, 992, 560, 18}, //18栋
    {5, 232, 595, 332, 645, 19}, //19栋
    {5, 364, 595, 464, 645, 20}, //20栋
    {5, 496, 595, 596, 645, 21}, //21栋
    {5, 628, 595, 728, 645, 22}, //22栋
    {5, 760, 595, 860, 645, 23}, //23栋
    {5, 892 ,595 ,992 ,645 ,24}, //24栋
    {5 ,232 ,680 ,332 ,730 ,25}, //25栋
    {5 ,364 ,680 ,464 ,730 ,26}, //26栋
    {5 ,496 ,680 ,596 ,730 ,27}, //27栋
};

void draw_button(int x)
{
    int i;
    int deta_x1 = (x == 5 ? 30 : 40), deta_x2 = (x == 5 ? 23 : 35), deta_y = 15;

    char buffer[20];
    PrintText(200, 310, "-----------------------------------", HEI, 32, 1, black); // 分隔线
    bar1(200, 320, 1024, 768, white); // 清除原有按钮
    
    for (i = 0; i < sizeof(button) / sizeof(button[0]); i++) {
        if (button[i].commmunity == x) {
            Draw_Rounded_Rectangle(button[i].x1, button[i].y1, button[i].x2, button[i].y2, 25, 1, deepblue);
            sprintf(buffer, "%d栋", button[i].number);
            if(button[i].number < 9) {
                PrintText(button[i].x1 + deta_x1, button[i].y1 + deta_y, buffer, HEI, 24, 1, deepblue);
            }
            else  {
                PrintText(button[i].x1 + deta_x2, button[i].y1 + deta_y, buffer, HEI, 24, 1, deepblue);
            }
        }
    }
}


// int press_button(int mx, int my, int cur_index, int cur_community) // cur_index: 当前按钮索引
// {
//     int i,new_index=-1;
//     int deta_x1=40,deta_x2=35,deta_y=15;
//     char buffer[20];

//     for ( i=0; i<sizeof(button)/sizeof(button[0]); i++)
//     {
//         // if (mouse_press(button[i].x1, button[i].y1, button[i].x2, button[i].y2) == 1 && 
//         // (button[i].commmunity * button[cur_index].commmunity == button[cur_index].commmunity *button[cur_index].commmunity) )
//         if (mx > button[i].x1 && mx < button[i].x2 && my > button[i].y1 && my < button[i].y2 && 
//             (button[i].commmunity == cur_community) && (button[i].number != button[cur_index].number)) // 判断鼠标是否在按钮范围内
//         {
            
//             new_index = i;
//             if(cur_index > 0)//消除原有高亮
//             {
//                 Fill_Rounded_Rectangle(button[cur_index].x1, button[cur_index].y1, button[cur_index].x2, button[cur_index].y2, 25, white);
//                 Draw_Rounded_Rectangle(button[cur_index].x1, button[cur_index].y1, button[cur_index].x2, button[cur_index].y2, 25, 1, deepblue);
//                 sprintf(buffer, "%d栋", button[i].number);
            
//                 if(button[cur_index].commmunity == 5)
//                 {
//                     deta_x1 = 30;
//                     deta_x2 = 23;
//                     deta_y = 15;
//                 }
//                 if(button[i].number < 9) {
//                     PrintText(button[i].x1 + deta_x1, button[i].y1 + deta_y, buffer, HEI, 24, 1, deepblue);
//                 }
//                 else  {
//                     PrintText(button[i].x1 + deta_x2, button[i].y1 + deta_y, buffer, HEI, 24, 1, deepblue);
//                 }
//             }   
//             //高亮新按钮
//             Fill_Rounded_Rectangle(button[i].x1, button[i].y1, button[i].x2, button[i].y2, 25, deepblue);
//             Draw_Rounded_Rectangle(button[i].x1, button[i].y1, button[i].x2, button[i].y2, 25, 1, white);
//             sprintf(buffer, "%d栋", button[i].number);
//             if(button[cur_index].commmunity == 5)
//             {
//                 deta_x1 = 30;
//                 deta_x2 = 23;
//                 deta_y = 15;
//             }
//             if(button[i].number < 9) {
//                 PrintText(button[i].x1 + deta_x1, button[i].y1 + deta_y, buffer, HEI, 24, 1, white);
//             }
//             else  {
//                 PrintText(button[i].x1 + deta_x2, button[i].y1 + deta_y, buffer, HEI, 24, 1, white);
//             }
//             sprintf(buffer, "选定%d栋", button[i].number);
//             PrintCC(200, 310, buffer, HEI, 32, 1, black); // 分隔线
//         }
//     }
//     return new_index;
// }
            
            

// int press_button(int mx, int my, int cur_index, int cur_community)
// {
//     int i, new_index = -1;
//     int deta_x1 = (cur_community == 5 ? 30 : 40), deta_x2 = (cur_community == 5 ? 23 : 35), deta_y = 15;
//     char buffer[20];
//     char test_buf[20];

//     for (i = 0; i < sizeof(button) / sizeof(button[0]); i++) {
//         if (mx > button[i].x1 && mx < button[i].x2 && my > button[i].y1 && my < button[i].y2 &&
//             (button[i].commmunity == cur_community) && (button[i].number != button[cur_index].number)) {
            
//             new_index = i;

//             // 消除原有高亮
//             if (cur_index >= 0) {
//                 Fill_Rounded_Rectangle(button[cur_index].x1, button[cur_index].y1, button[cur_index].x2, button[cur_index].y2, 25, white);
//                 Draw_Rounded_Rectangle(button[cur_index].x1, button[cur_index].y1, button[cur_index].x2, button[cur_index].y2, 25, 1, deepblue);
//                 sprintf(buffer, "%d栋", button[cur_index].number);
//                 if(button[i].number < 9) {
//                     PrintText(button[cur_index].x1 + deta_x1, button[cur_index].y1 + deta_y, buffer, HEI, 24, 1, deepblue);
//                 }
//                 else  {
//                     PrintText(button[cur_index].x1 + deta_x2, button[cur_index].y1 + deta_y, buffer, HEI, 24, 1, deepblue);
//                 }
//                 // PrintText(button[cur_index].x1 + deta_x2, button[cur_index].y1 + deta_y, buffer, HEI, 24, 1, deepblue);
//             }

//             // 高亮新按钮
//             Fill_Rounded_Rectangle(button[i].x1, button[i].y1, button[i].x2, button[i].y2, 25, deepblue);
//             Draw_Rounded_Rectangle(button[i].x1, button[i].y1, button[i].x2, button[i].y2, 25, 1, white);
//             sprintf(buffer, "%d栋", button[i].number);
//             deta_x1 = (button[i].commmunity == 5 ? 30 : 40), deta_x2 = (button[i].commmunity == 5 ? 23 : 35), deta_y = 15;
//             if(button[i].number < 9) {
//                 PrintText(button[i].x1 + deta_x1, button[i].y1 + deta_y, buffer, HEI, 24, 1, deepblue);
//             }
//             else  {
//                 PrintText(button[i].x1 + deta_x2, button[i].y1 + deta_y, buffer, HEI, 24, 1, deepblue);
//             }

//             bar1(200, 310, 700, 330, white); // 清除原有提示
//             sprintf(test_buf, "传出索引%d 对应%d %d", new_index,button[new_index].commmunity, button[new_index].number);
//             PrintText(200, 310, test_buf, HEI, 32, 1, black); // 分隔线
//         }
//     }
//     return new_index;
// }
            

int press_button(int mx, int my, int cur_index, int cur_community) {
    int i, new_index = -1;
    char buffer[20], test_buf[20];
    int deta_x;
    int is_cur_index_valid;
    // 条件 1: 检查 cur_index 有效性
    is_cur_index_valid = (cur_index >= 0 && cur_index < sizeof(button)/sizeof(button[0]));

    for (i = 0; i < sizeof(button)/sizeof(button[0]); i++) {
        // 条件 2: 检查鼠标点击范围、社区匹配、非自身按钮
        if (mx > button[i].x1 && mx < button[i].x2 && 
            my > button[i].y1 && my < button[i].y2 &&
            button[i].commmunity == cur_community && 
            (!is_cur_index_valid || button[i].number != button[cur_index].number)) 
        {
            new_index = i;

            // 消除旧高亮（仅当 cur_index 有效时）
            if (is_cur_index_valid) {
                // 恢复旧按钮颜色和文字
                Fill_Rounded_Rectangle(button[cur_index].x1, button[cur_index].y1, 
                                      button[cur_index].x2, button[cur_index].y2, 25, white);
                Draw_Rounded_Rectangle(button[cur_index].x1, button[cur_index].y1, 
                                      button[cur_index].x2, button[cur_index].y2, 25, 1, deepblue);
                // 计算文本偏移量（基于社区）
                deta_x = (button[cur_index].commmunity == 5) ? 23 : 35;
                if (button[cur_index].number < 9) {
                    deta_x = (button[cur_index].commmunity == 5) ? 30 : 40;
                }
                sprintf(buffer, "%d栋", button[cur_index].number);
                PrintText(button[cur_index].x1 + deta_x, button[cur_index].y1 + 15, 
                        buffer, HEI, 24, 1, deepblue);
            }

            // 设置新高亮
            Fill_Rounded_Rectangle(button[i].x1, button[i].y1, button[i].x2, button[i].y2, 25, deepblue);
            Draw_Rounded_Rectangle(button[i].x1, button[i].y1, button[i].x2, button[i].y2, 25, 1, white);
            // 计算文本偏移量（基于社区）
            deta_x = (button[i].commmunity == 5) ? 23 : 35;
            if (button[i].number < 9) {
                deta_x = (button[i].commmunity == 5) ? 30 : 40;
            }
            sprintf(buffer, "%d栋", button[i].number);
            PrintText(button[i].x1 + deta_x, button[i].y1 + 15, buffer, HEI, 24, 1, white);

            // 调试信息
            bar1(200, 310, 700, 340, white);
            sprintf(test_buf, "传出索引%d 对应%d %d", new_index, button[new_index].commmunity, button[new_index].number);
            PrintText(200, 310, test_buf, HEI, 32, 1, black);

            break; // 退出循环，避免多个按钮被处理
        }
    }
    return new_index;
}
    //         Fill_Rounded_Rectangle(40, 276, 160, 326, 25,deepblue);
    //         Draw_Rounded_Rectangle(40, 276, 160, 326, 25, 1,deepblue);
    //         PrintCC(75,291,"超市",HEI,24,1,white);
    //         Fill_Rounded_Rectangle(40, 439, 160, 489, 25,white);
    //         Draw_Rounded_Rectangle(40, 439, 160, 489, 25, 1,deepblue);
    //         PrintCC(75,454,"外卖",HEI,24,1,deepblue);
    //         Fill_Rounded_Rectangle(40, 602, 160, 652, 25,white);
    //         Draw_Rounded_Rectangle(40, 602, 160, 652, 25, 1,deepblue);
    //         PrintCC(75,617,"快递",HEI,24,1,deepblue);
    // }
  
