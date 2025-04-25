#include "all_func.h"

#define H 15
#define W 12

clock_t last_toggle;
volatile int cursor_visible = 1;   // ���ɼ�״̬

int cursor_x = 100, cursor_y = 100; // ����ʼλ�ã����������޸ģ�
unsigned int cursor_bk[16][2];      // ��걳���洢������16x2��꣩
MOUSE mouse = {0, 0, 0};            // ����һ�����ṹ����
unsigned int mouse_bk[20][20];      // ��ű���긲�ǵ�����

int mouse_shape_arrow[H][W] = 		// �����״��ά����
{     
    
		{1,1,0,0,0,0,0,0,0,0,0,0},
		{1,2,1,0,0,0,0,0,0,0,0,0},
		{1,2,2,1,0,0,0,0,0,0,0,0},
		{1,2,2,2,1,0,0,0,0,0,0,0},
		{1,2,2,2,2,1,0,0,0,0,0,0},
		{1,2,2,2,2,2,1,0,0,0,0,0},
		{1,2,2,2,2,2,2,1,0,0,0,0},
		{1,2,2,2,2,2,2,2,1,0,0,0},
		{1,2,2,2,2,2,2,2,2,1,0,0},
		{1,2,2,2,2,2,2,2,2,2,1,0},
		{1,2,2,2,2,2,2,1,1,1,1,1},
		{1,2,2,1,2,2,2,1,0,0,0,0},
		{1,2,1,0,1,2,2,2,1,0,0,0},	
		{1,1,0,0,0,1,2,2,2,1,0,0},	
		{1,0,0,0,0,0,1,1,1,1,0,0}	
};

int mouse_shape_cursor[H][W] = {
    {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},  // �����̺���
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},  // �м䴹ֱ�ߣ����1���أ�
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0}   // �ײ��̺���
};

int mouse_shape_hand[H][W] = {
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},  // ָ��ˮƽ��
    {0, 0, 0, 1, 2, 2, 2, 2, 1, 0, 0, 0},
    {0, 0, 1, 2, 2, 2, 2, 2, 2, 1, 0, 0},
    {0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0},
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0},  // ָ�����������Ӵ�
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1},  // �����ϲ����������죨ģ��Ĵָ���֣�
    {0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0},  // ������������
    {0, 0, 1, 2, 2, 2, 2, 2, 2, 1, 0, 0},
    {0, 0, 0, 1, 2, 2, 2, 2, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 2, 2, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // ������͸������
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

/***��긴λ***/
void MouseInit()
{
    union REGS regs;
    regs.x.ax=0;
    int86(0x33,&regs,&regs);
    if(regs.x.ax==0)
    {
        printf("mouse error");
        delay(5000);
        exit(1);
    }
}

/***����ʼ��***/
void mouse_init()
{
    MouseInit();                  // ��긴λ������Ƿ�װ���
    MouseRange(0, 0, 1012, 752);  // ��귶Χ����
    MouseGet(&mouse);             // �õ����״̬
    MouseSpeed(6, 4);
    mouse_on_hand(mouse);        // ��ʾ���
}


/********************************
    ����˵�������������������ر�,ֵԽ������ƶ��ٶ�Խ�� 
    ����˵����int   vx,    ������ģ�int   vy    ��������
********************************/
void MouseSpeed(int x, int y)
{
    union REGS regs;
    regs.x.ax = 0x0f;
    regs.x.cx = x;
    regs.x.dx = y;
    int86(0x33, &regs, &regs);
}


/***��귶Χ����***/
void MouseRange(int x1, int y1, int x2, int y2)
{
    union REGS mouse;
    /*���ú����귶Χ*/
    mouse.x.ax = 7;
    mouse.x.cx = x1;
    mouse.x.dx = x2;
    int86(0x33, &mouse, &mouse);
    /*���������귶Χ*/
    mouse.x.ax = 8;
    mouse.x.cx = y1;
    mouse.x.dx = y2;
    int86(0x33, &mouse, &mouse);
}

/***�õ���갴��״̬(�������������)***/
int MouseBut(MOUSE *mouse)
{
    union REGS regs;
    regs.x.ax = 3;
    int86(0x33, &regs, &regs);
    mouse->key = regs.x.bx;
    return mouse->key;
}

/***�õ����λ�ã�����״̬***/
int MouseGet(MOUSE *mouse)
{
    union REGS regs;
    regs.x.ax = 3;
    int86(0x33, &regs, &regs);
    mouse->x = regs.x.cx;
    mouse->y = regs.x.dx;
    mouse->key = regs.x.bx;
    return mouse->key;
}

/***���������ʾλ��***/
void MouseSet(int x, int y)
{
    union REGS regs;
    regs.x.ax = 4;
    regs.x.cx = x;
    regs.x.dx = y;
    int86(0x33, &regs, &regs);      // ������굱ǰ����    
    mouse_on_cursor(mouse);          // �����    
}
/***�õ�ĳһ�����ɫֵ***/
unsigned int Getpixel64k(int x, int y)
{
    unsigned int far* const video_buffer = (unsigned int far *)0xa0000000L;
    unsigned char page;                                                  //Ҫ�л���ҳ���
    unsigned long int page_dev;                                           //��Ӧ�Դ��ַƫ����                       
    if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))           //�жϵ��Ƿ�����Ļ��Χ�ڣ����ھ��˳� 
    {
        printf("out of range");
    }
    page_dev = ((unsigned long int)y << 10) + x;                              //�����Դ��ַƫ�����Ͷ�Ӧ��ҳ��ţ�����ҳ����
    page = page_dev >> 15;    //32k����һ��ҳ������32k������㷨
    Selectpage(page);
    return video_buffer[page_dev];     //������ɫ
}

/***�ж��������Ƿ���ָ�������ڰ���***/
int mouse_press(int x1, int y1, int x2, int y2)
{
    MOUSE mouse = {0, 0, 0};
    MouseGet(&mouse);
    if ((mouse.x >= x1) && (mouse.x <= x2) && (mouse.y >= y1) && (mouse.y <= y2) && ((mouse.key & 1) == 1))
    {
        return 1;
    }
    else if (((mouse.x <= x1) || (mouse.x >= x2) || ((mouse.x >= x1) && (mouse.x <= x2) && (mouse.y >= y1)) || ((mouse.x <= x1) && (mouse.x <= x2) && (mouse.y >= y2))) && ((mouse.key & 1) == 1))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

//�ж�����Ƿ�ͣ����ĳ������
int mouse_location(int x1,int y1,int x2,int y2)
{
	MOUSE mouse = {0, 0, 0};
	MouseGet(&mouse);
	if ((mouse.x >= x1) && (mouse.x <= x2) && (mouse.y >= y1) && (mouse.y <= y2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void mouse_on_arrow(MOUSE mouse)
{
    int i, j;
    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            mouse_bk[i][j] = Getpixel64k(j + mouse.x, i + mouse.y);  // �洢��긲����
            /***�����***/
            if (mouse_shape_arrow[i][j] == 1)
                Putpixel64k(mouse.x + j, mouse.y + i, 0);
            else if (mouse_shape_arrow[i][j] == 2)
                Putpixel64k(mouse.x + j, mouse.y + i, 0xffff);
        }
    }
}

void mouse_on_cursor(MOUSE mouse)
{
    int i, j;
    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            mouse_bk[i][j] = Getpixel64k(j + mouse.x, i + mouse.y);  // �洢��긲����
            /***�����***/
            if (mouse_shape_cursor[i][j] == 1)
                Putpixel64k(mouse.x + j, mouse.y + i, 0);
            else if (mouse_shape_cursor[i][j] == 2)
                Putpixel64k(mouse.x + j, mouse.y + i, 0xffff);
        }
    }
}

void mouse_on_hand(MOUSE mouse)
{
    int i, j;
    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            mouse_bk[i][j] = Getpixel64k(j + mouse.x, i + mouse.y);  // �洢��긲����
            /***�����***/
            if (mouse_shape_hand[i][j] == 1)
                Putpixel64k(mouse.x + j, mouse.y + i, 0);
            else if (mouse_shape_hand[i][j] == 2)
                Putpixel64k(mouse.x + j, mouse.y + i, 0xffff);
        }
    }
}

/***���ÿ���ƶ�������ʾ***/
void mouse_show_cursor(MOUSE *mouse)
{  
	int i, j;       // ѭ������
	int color;      // ���ĳ����ɫ
	int x, y;
	x = mouse->x;   // ���ԭλ������
	y = mouse->y;         
	MouseGet(mouse);    // �õ������״̬
	if (mouse->x != x || mouse->y != y)  // ����ƶ������»����
	{
		for (i = 0; i < H; i++)           	
		{
			for (j = 0; j < W; j++)
			{
				if (mouse_shape_cursor[i][j] == 0)
					continue;
				Putpixel64k(x + j, y + i, mouse_bk[i][j]);   // ����ԭ��긲����
			}
		}
		mouse_on_cursor(*mouse);  // ����λ����ʾ���
	}	}
	
void mouse_show_arrow(MOUSE *mouse)
{  
	int i, j;       // ѭ������
	int color;      // ���ĳ����ɫ
	int x, y;
	x = mouse->x;   // ���ԭλ������
	y = mouse->y;         
	MouseGet(mouse);    // �õ������״̬
	if (mouse->x != x || mouse->y != y)  // ����ƶ������»����
	{
		for (i = 0; i < H; i++)           	
		{
			for (j = 0; j < W; j++)
			{
				if (mouse_shape_arrow[i][j] == 0)
					continue;
				Putpixel64k(x + j, y + i, mouse_bk[i][j]);   // ����ԭ��긲����
			}
		}
		mouse_on_arrow(*mouse);  // ����λ����ʾ���
	}
}

void mouse_show_hand(MOUSE *mouse)
{  
	int i, j;       // ѭ������
	int color;      // ���ĳ����ɫ
	int x, y;
	x = mouse->x;   // ���ԭλ������
	y = mouse->y;         
	MouseGet(mouse);    // �õ������״̬
	if (mouse->x != x || mouse->y != y)  // ����ƶ������»����
	{
		for (i = 0; i < H; i++)           	
		{
			for (j = 0; j < W; j++)
			{
				if (mouse_shape_hand[i][j] == 0)
					continue;
				Putpixel64k(x + j, y + i, mouse_bk[i][j]);   // ����ԭ��긲����
			}
		}
		mouse_on_hand(*mouse);  // ����λ����ʾ���
	}
}

/***�������***/
void mouse_off_arrow(MOUSE *mouse)
{
	int i, j;
	int x, y;
	x = mouse->x;
	y = mouse->y;
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			if (mouse_shape_arrow[i][j] == 0)
				continue;
			Putpixel64k(x + j, y + i, mouse_bk[i][j]);   // ����ԭ��긲����
		}
	}
}

void mouse_off_cursor(MOUSE *mouse)
{
	int i, j;
	int x, y;
	x = mouse->x;
	y = mouse->y;
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			if (mouse_shape_cursor[i][j] == 0)
				continue;
			Putpixel64k(x + j, y + i, mouse_bk[i][j]);   // ����ԭ��긲����
		}
	}
}

void mouse_off_hand(MOUSE *mouse)
{
	int i, j;
	int x, y;
	x = mouse->x;
	y = mouse->y;
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			if (mouse_shape_hand[i][j] == 0)
				continue;
			Putpixel64k(x + j, y + i, mouse_bk[i][j]);   // ����ԭ��긲����
		}
	}
}

void draw_mouse_arrow(int mx, int my)
{
	int i, j;
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			if (mouse_shape_arrow[i][j] == 1)
				Putpixel64k(mx + j, my + i, 0);
			else if (mouse_shape_arrow[i][j] == 2)
				Putpixel64k(mx + j, my + i, 0xffff);
		}
	}
}

// ���ƹ��
void draw_cursor(int x, int y)
{
	Line1(x, y, x, y + 28, 0);
}

// ���ع��
void hide_cursor(int x, int y)
{
	Line1(x, y, x, y + 28, 0xffff);
}

//���ع�꣨��ɫ��
void hide_cursor_grew(int x, int y)
{
	Line1(x, y, x, y + 28, lightgrew);
}

void cursor(int x, int y)
{
	static int i=0;
	i++;
	i%=30000;
	if(i<=15000)
	{
		draw_cursor(x, y);
	}
	else
	{
		hide_cursor(x, y);
	}
}
void cursor_grew(int x, int y)
{
    static int j=0;
    j++;
    j%=30000;
    if(j<=15000)
    {
        draw_cursor(x, y);
    }
    else
    {
        hide_cursor_grew(x, y);
    }
}

// ������
int mouse_scroll(int *scroll_position, int min_scroll, int max_scroll)
{
    static int last_y = -1;
    MOUSE mouse;
    MouseGet(&mouse);

    if (mouse.key & 1) // �������������
    {
        if (last_y != -1) // ��⵽�϶�
        {
            int delta = mouse.y - last_y; // ���㴹ֱλ��
            *scroll_position += delta; // ���¹���λ��
            if (*scroll_position < min_scroll)
                *scroll_position = min_scroll;
            if (*scroll_position > max_scroll)
                *scroll_position = max_scroll;
        }
        last_y = mouse.y; // ������һ�� Y ����
    }
    else
    {
        last_y = -1; // ������̧������
    }

    return *scroll_position;
}
