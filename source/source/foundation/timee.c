#include <all_func.h>

//获取当前时间
unsigned long get_tick_count()
{
    union REGS regs;
    regs.h.ah = 0x00;
    int86(0x1A, &regs, &regs);
    return ((unsigned long)regs.x.cx << 16) | regs.x.dx;
}