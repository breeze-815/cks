#include "all_func.h"

#define H 15
#define W 12

clock_t last_toggle;
volatile int cursor_visible = 1;   // 光标可见状态

int cursor_x = 100, cursor_y = 100; // 光标初始位置（根据需求修改）
unsigned int cursor_bk[16][2];      // 光标背景存储（假设16x2光标）
MOUSE mouse = {0, 0, 0};            // 定义一个鼠标结构变量
unsigned int mouse_bk[20][20];      // 存放被鼠标覆盖的区域

int mouse_shape_arrow[H][W] = 		// 鼠标形状二维数组
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
    {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0},  // 顶部短横线
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},  // 中间垂直线（宽度1像素）
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0}   // 底部短横线
};

int mouse_shape_hand[H][W] = {
    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},  // 指尖水平线
    {0, 0, 0, 1, 2, 2, 2, 2, 1, 0, 0, 0},
    {0, 0, 1, 2, 2, 2, 2, 2, 2, 1, 0, 0},
    {0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0},
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0},  // 指尖与手掌连接处
    {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1},  // 手掌上部略向右延伸（模拟拇指部分）
    {0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0},  // 手掌整体收敛
    {0, 0, 1, 2, 2, 2, 2, 2, 2, 1, 0, 0},
    {0, 0, 0, 1, 2, 2, 2, 2, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 2, 2, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 下面留透明区域
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

/***鼠标复位***/
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

/***鼠标初始化***/
void mouse_init()
{
    MouseInit();                  // 鼠标复位，检测是否安装鼠标
    MouseRange(0, 0, 1012, 752);  // 鼠标范围设置
    MouseGet(&mouse);             // 得到鼠标状态
    MouseSpeed(6, 4);
    mouse_on_hand(mouse);        // 显示鼠标
}


/********************************
    功能说明：设置鼠标计数与像素比,值越大鼠标移动速度越慢 
    参数说明：int   vx,    鼠标横向的；int   vy    鼠标纵向的
********************************/
void MouseSpeed(int x, int y)
{
    union REGS regs;
    regs.x.ax = 0x0f;
    regs.x.cx = x;
    regs.x.dx = y;
    int86(0x33, &regs, &regs);
}


/***鼠标范围设置***/
void MouseRange(int x1, int y1, int x2, int y2)
{
    union REGS mouse;
    /*设置横坐标范围*/
    mouse.x.ax = 7;
    mouse.x.cx = x1;
    mouse.x.dx = x2;
    int86(0x33, &mouse, &mouse);
    /*设置纵坐标范围*/
    mouse.x.ax = 8;
    mouse.x.cx = y1;
    mouse.x.dx = y2;
    int86(0x33, &mouse, &mouse);
}

/***得到鼠标按键状态(不传递鼠标坐标)***/
int MouseBut(MOUSE *mouse)
{
    union REGS regs;
    regs.x.ax = 3;
    int86(0x33, &regs, &regs);
    mouse->key = regs.x.bx;
    return mouse->key;
}

/***得到鼠标位置，按键状态***/
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

/***设置鼠标显示位置***/
void MouseSet(int x, int y)
{
    union REGS regs;
    regs.x.ax = 4;
    regs.x.cx = x;
    regs.x.dx = y;
    int86(0x33, &regs, &regs);      // 设置鼠标当前坐标    
    mouse_on_cursor(mouse);          // 画鼠标    
}
/***得到某一点的颜色值***/
unsigned int Getpixel64k(int x, int y)
{
    unsigned int far* const video_buffer = (unsigned int far *)0xa0000000L;
    unsigned char page;                                                  //要切换的页面号
    unsigned long int page_dev;                                           //对应显存地址偏移量                       
    if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))           //判断点是否在屏幕范围内，不在就退出 
    {
        printf("out of range");
    }
    page_dev = ((unsigned long int)y << 10) + x;                              //计算显存地址偏移量和对应的页面号，做换页操作
    page = page_dev >> 15;    //32k个点一换页，除以32k的替代算法
    Selectpage(page);
    return video_buffer[page_dev];     //返回颜色
}

/***判断鼠标左键是否在指定区域内按下***/
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

//判断鼠标是否停留在某个区域
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
            mouse_bk[i][j] = Getpixel64k(j + mouse.x, i + mouse.y);  // 存储鼠标覆盖区
            /***画鼠标***/
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
            mouse_bk[i][j] = Getpixel64k(j + mouse.x, i + mouse.y);  // 存储鼠标覆盖区
            /***画鼠标***/
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
            mouse_bk[i][j] = Getpixel64k(j + mouse.x, i + mouse.y);  // 存储鼠标覆盖区
            /***画鼠标***/
            if (mouse_shape_hand[i][j] == 1)
                Putpixel64k(mouse.x + j, mouse.y + i, 0);
            else if (mouse_shape_hand[i][j] == 2)
                Putpixel64k(mouse.x + j, mouse.y + i, 0xffff);
        }
    }
}

/***鼠标每次移动重新显示***/
void mouse_show_cursor(MOUSE *mouse)
{  
	int i, j;       // 循环变量
	int color;      // 鼠标某点颜色
	int x, y;
	x = mouse->x;   // 鼠标原位置坐标
	y = mouse->y;         
	MouseGet(mouse);    // 得到新鼠标状态
	if (mouse->x != x || mouse->y != y)  // 鼠标移动就重新画鼠标
	{
		for (i = 0; i < H; i++)           	
		{
			for (j = 0; j < W; j++)
			{
				if (mouse_shape_cursor[i][j] == 0)
					continue;
				Putpixel64k(x + j, y + i, mouse_bk[i][j]);   // 画出原鼠标覆盖区
			}
		}
		mouse_on_cursor(*mouse);  // 在新位置显示鼠标
	}	}
	
void mouse_show_arrow(MOUSE *mouse)
{  
	int i, j;       // 循环变量
	int color;      // 鼠标某点颜色
	int x, y;
	x = mouse->x;   // 鼠标原位置坐标
	y = mouse->y;         
	MouseGet(mouse);    // 得到新鼠标状态
	if (mouse->x != x || mouse->y != y)  // 鼠标移动就重新画鼠标
	{
		for (i = 0; i < H; i++)           	
		{
			for (j = 0; j < W; j++)
			{
				if (mouse_shape_arrow[i][j] == 0)
					continue;
				Putpixel64k(x + j, y + i, mouse_bk[i][j]);   // 画出原鼠标覆盖区
			}
		}
		mouse_on_arrow(*mouse);  // 在新位置显示鼠标
	}
}

void mouse_show_hand(MOUSE *mouse)
{  
	int i, j;       // 循环变量
	int color;      // 鼠标某点颜色
	int x, y;
	x = mouse->x;   // 鼠标原位置坐标
	y = mouse->y;         
	MouseGet(mouse);    // 得到新鼠标状态
	if (mouse->x != x || mouse->y != y)  // 鼠标移动就重新画鼠标
	{
		for (i = 0; i < H; i++)           	
		{
			for (j = 0; j < W; j++)
			{
				if (mouse_shape_hand[i][j] == 0)
					continue;
				Putpixel64k(x + j, y + i, mouse_bk[i][j]);   // 画出原鼠标覆盖区
			}
		}
		mouse_on_hand(*mouse);  // 在新位置显示鼠标
	}
}

/***鼠标隐藏***/
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
			Putpixel64k(x + j, y + i, mouse_bk[i][j]);   // 画出原鼠标覆盖区
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
			Putpixel64k(x + j, y + i, mouse_bk[i][j]);   // 画出原鼠标覆盖区
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
			Putpixel64k(x + j, y + i, mouse_bk[i][j]);   // 画出原鼠标覆盖区
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

// 绘制光标
void draw_cursor(int x, int y)
{
	Line1(x, y, x, y + 28, 0);
}

// 隐藏光标
void hide_cursor(int x, int y)
{
	Line1(x, y, x, y + 28, 0xffff);
}

//隐藏光标（灰色）
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

// 鼠标滚轮
int mouse_scroll(int *scroll_position, int min_scroll, int max_scroll)
{
    static int last_y = -1;
    MOUSE mouse;
    MouseGet(&mouse);

    if (mouse.key & 1) // 如果按下鼠标左键
    {
        if (last_y != -1) // 检测到拖动
        {
            int delta = mouse.y - last_y; // 计算垂直位移
            *scroll_position += delta; // 更新滚动位置
            if (*scroll_position < min_scroll)
                *scroll_position = min_scroll;
            if (*scroll_position > max_scroll)
                *scroll_position = max_scroll;
        }
        last_y = mouse.y; // 更新上一次 Y 坐标
    }
    else
    {
        last_y = -1; // 鼠标左键抬起，重置
    }

    return *scroll_position;
}
