#ifndef MOUSE_H
#define MOUSE_H

typedef struct {
    int x;
    int y;
    int key;
} MOUSE;


void mouse_init();
void MouseSpeed(int x, int y);
void MouseRange(int x1, int y1, int x2, int y2);
int MouseBut(MOUSE *mouse);
int MouseGet(MOUSE *mouse);
void MouseSet(int x, int y);
int mouse_press(int x1, int y1, int x2, int y2);

void mouse_on_arrow(MOUSE mouse);
void mouse_on_cursor(MOUSE mouse);
void mouse_on_hand(MOUSE mouse);

void mouse_show_cursor(MOUSE *mouse);
void mouse_show_arrow(MOUSE *mouse);
void mouse_show_hand(MOUSE *mouse);

void mouse_off_arrow(MOUSE *mouse);
void mouse_off_cursor(MOUSE *mouse);
void mouse_off_hand(MOUSE *mouse);

void Curinit();
void draw_mouse_arrow(int mx, int my);

void draw_cursor(int x, int y);
void hide_cursor(int x, int y);
void hide_cursor_grew(int x, int y);
void cursor(int x, int y);
void cursor_grew(int x, int y);
int mouse_location(int x1,int y1,int x2,int y2);
unsigned int Getpixel64k(int x, int y);
#endif // MOUSE_H