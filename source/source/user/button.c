#include <all_func.h>

Button button [] = {
    {0, 0, 0, 0, 0, 0}, // 梩弇睫
    //陲⑹
    {1, 273, 364, 393, 414, 1}, // 1集
    {1, 459, 364, 579, 414, 2}, // 2集
    {1, 645, 364, 765, 414, 3}, // 3集
    {1, 831, 364, 951, 414, 4}, // 4集
    {1, 273, 464, 393, 514, 5}, // 5集
    {1, 459, 464, 579, 514, 6}, // 6集
    {1, 645, 464, 765, 514, 7}, // 7集
    {1, 831, 464, 951, 514, 8}, // 8集
    {1, 273, 564 ,393 ,614 ,9},  //9集
    {1 ,459 ,564 ,579 ,614 ,10},//10集
    {1 ,645 ,564 ,765 ,614 ,11},//11集
    {1 ,831 ,564 ,951 ,614 ,12},//12集
    {1 ,273 ,664 ,393 ,714 ,13},//13集
    
    // ----------------------------------
    // 昹⑹
    {2, 242, 364, 362, 414, 1}, // 1集
    {2, 397, 364, 517, 414, 2}, // 2集
    {2, 552, 364, 672, 414, 3}, // 3集
    {2, 707, 364, 827, 414, 4}, // 4集
    {2, 862, 364, 982, 414, 5}, // 5集
    {2, 242, 464, 362, 514, 6}, // 6集
    {2, 397, 464, 517, 514, 7}, // 7集
    {2, 552, 464 ,672 ,514 ,8}, //8集
    {2 ,707 ,464 ,827 ,514 ,9}, //9集
    {2 ,862 ,464 ,982 ,514 ,10},//10集
    {2 ,242 ,564 ,362 ,614 ,11},//11集
    {2 ,397 ,564 ,517 ,614 ,12},//12集
    {2 ,552 ,564 ,672 ,614 ,13},//13集
    {2 ,707 ,564 ,827 ,614 ,14},//14集
    {2 ,862 ,564 ,982 ,614 ,15},//15集
    {2 ,242 ,664 ,362 ,714 ,16},//16集
    {2 ,397 ,664 ,517 ,714 ,17}, //17集

    // ----------------------------------
    // 鰍⑹
    {3, 273, 364, 393, 414, 1}, // 1集
    {3, 459, 364, 579, 414, 2}, // 2集
    {3, 645, 364, 765, 414, 3}, // 3集

    // ----------------------------------
    // 豜暆
    {4, 242, 364, 362, 414, 1}, // 1集
    {4, 397, 364, 517, 414, 2}, // 2集
    {4, 552, 364, 672, 414, 3}, // 3集
    {4, 707, 364, 827, 414, 4}, // 4集
    {4, 862, 364, 982, 414, 5}, // 5集
    {4, 242, 464, 362, 514, 6}, // 6集
    {4, 397, 464 ,517 ,514 ,7}, // 7集
    {4, 552 ,464 ,672 ,514 ,8}, // 8集
    {4, 707 ,464 ,827 ,514 ,9}, // 9集
    {4, 862 ,464 ,982 ,514 ,10},// 10集
    {4, 242 ,564 ,362 ,614 ,11},// 11集
    {4, 397 ,564 ,517 ,614 ,12},// 12集
    {4, 552 ,564 ,672 ,614 ,13},// 13集
    {4, 707 ,564 ,827 ,614 ,14},// 14集
    {4, 862 ,564 ,982 ,614 ,15},// 15集
    {4, 242 ,664 ,362 ,714 ,16},// 16集
    {4, 397 ,664 ,517 ,714 ,17},// 17集
    {4, 552 ,664 ,672 ,714 ,18},// 18集

    // ----------------------------------
    // 婘埸
    {5, 232, 340, 332, 390, 1}, // 1集
    {5, 364, 340, 464, 390, 2}, // 2集
    {5, 496, 340, 596, 390, 3}, // 3集
    {5, 628, 340, 728, 390, 4}, // 4集
    {5, 760, 340, 860, 390, 5}, // 5集
    {5, 892, 340 ,992 ,390 ,6}, //6集
    {5 ,232 ,425 ,332 ,475 ,7}, //7集
    {5 ,364 ,425 ,464 ,475 ,8}, //8集
    {5 ,496 ,425 ,596 ,475 ,9}, //9集
    {5 ,628 ,425 ,728 ,475 ,10}, //10集
    {5 ,760 ,425 ,860 ,475 ,11}, //11集
    {5 ,892 ,425 ,992 ,475 ,12}, //12集
    {5 ,232 ,510 ,332 ,560 ,13}, //13集
    {5 ,364 ,510 ,464 ,560 ,14}, //14集
    {5 ,496 ,510 ,596 ,560 ,15}, //15集
    {5 ,628 ,510 ,728 ,560 ,16}, //16集
    {5 ,760 ,510 ,860 ,560 ,17}, //17集
    {5, 892, 510, 992, 560, 18}, //18集
    {5, 232, 595, 332, 645, 19}, //19集
    {5, 364, 595, 464, 645, 20}, //20集
    {5, 496, 595, 596, 645, 21}, //21集
    {5, 628, 595, 728, 645, 22}, //22集
    {5, 760, 595, 860, 645, 23}, //23集
    {5, 892 ,595 ,992 ,645 ,24}, //24集
    {5 ,232 ,680 ,332 ,730 ,25}, //25集
    {5 ,364 ,680 ,464 ,730 ,26}, //26集
    {5 ,496 ,680 ,596 ,730 ,27}, //27集
};

void draw_button(int x)
{
    int i;
    int deta_x1 = (x == 5 ? 30 : 40), deta_x2 = (x == 5 ? 23 : 35), deta_y = 15;

    char buffer[20];
    PrintText(200, 310, "-----------------------------------", HEI, 32, 1, black); // 煦路盄
    bar1(200, 320, 1024, 768, white); // ь壺埻衄偌聽
    
    for (i = 0; i < sizeof(button) / sizeof(button[0]); i++) {
        if (button[i].commmunity == x) {
            Draw_Rounded_Rectangle(button[i].x1, button[i].y1, button[i].x2, button[i].y2, 25, 1, deepblue);
            sprintf(buffer, "%d集", button[i].number);
            if(button[i].number < 9) {
                PrintText(button[i].x1 + deta_x1, button[i].y1 + deta_y, buffer, HEI, 24, 1, deepblue);
            }
            else  {
                PrintText(button[i].x1 + deta_x2, button[i].y1 + deta_y, buffer, HEI, 24, 1, deepblue);
            }
        }
    }
}


int press_button(int mx, int my, int cur_index, int cur_community) {
    int i, new_index = -1;
    char buffer[20], test_buf[20];
    int deta_x;
    int is_cur_index_valid;
    // 沭璃 1: 潰脤 cur_index 衄虴俶
    is_cur_index_valid = (cur_index >= 0 && cur_index < sizeof(button)/sizeof(button[0]));

    for (i = 0; i < sizeof(button)/sizeof(button[0]); i++) {
        // 沭璃 2: 潰脤扷梓萸僻毓峓﹜扦⑹ぁ饜﹜準赻旯偌聽
        if (mx > button[i].x1 && mx < button[i].x2 && 
            my > button[i].y1 && my < button[i].y2 &&
            button[i].commmunity == cur_community && 
            (!is_cur_index_valid || button[i].number != button[cur_index].number)) 
        {
            new_index = i;

            // 秏壺導詢謠ㄗ躺絞 cur_index 衄虴奀ㄘ
            if (is_cur_index_valid) {
                // 閥葩導偌聽晇伎睿恅趼
                Fill_Rounded_Rectangle(button[cur_index].x1, button[cur_index].y1, 
                                      button[cur_index].x2, button[cur_index].y2, 25, white);
                Draw_Rounded_Rectangle(button[cur_index].x1, button[cur_index].y1, 
                                      button[cur_index].x2, button[cur_index].y2, 25, 1, deepblue);
                // 數呾恅掛ぇ痄講ㄗ價衾扦⑹ㄘ
                deta_x = (button[cur_index].commmunity == 5) ? 23 : 35;
                if (button[cur_index].number < 9) {
                    deta_x = (button[cur_index].commmunity == 5) ? 30 : 40;
                }
                sprintf(buffer, "%d集", button[cur_index].number);
                PrintText(button[cur_index].x1 + deta_x, button[cur_index].y1 + 15, 
                        buffer, HEI, 24, 1, deepblue);
            }

            // 扢离陔詢謠
            Fill_Rounded_Rectangle(button[i].x1, button[i].y1, button[i].x2, button[i].y2, 25, deepblue);
            Draw_Rounded_Rectangle(button[i].x1, button[i].y1, button[i].x2, button[i].y2, 25, 1, white);
            // 數呾恅掛ぇ痄講ㄗ價衾扦⑹ㄘ
            deta_x = (button[i].commmunity == 5) ? 23 : 35;
            if (button[i].number < 9) {
                deta_x = (button[i].commmunity == 5) ? 30 : 40;
            }
            sprintf(buffer, "%d集", button[i].number);
            PrintText(button[i].x1 + deta_x, button[i].y1 + 15, buffer, HEI, 24, 1, white);

            // 覃彸陓洘
            bar1(200, 310, 700, 340, white);
            sprintf(test_buf, "換堤坰竘%d 勤茼%d %d", new_index, button[new_index].commmunity, button[new_index].number);
            PrintText(200, 310, test_buf, HEI, 32, 1, black);

            break; // 豖堤悜遠ㄛ旌轎嗣跺偌聽掩揭燴
        }
    }
    return new_index;
}
 