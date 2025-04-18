#ifndef __DRAW_SHAPE_H__
#define __DRAW_SHAPE_H__

void Draw_Rounded_Rectangle(int x1, int y1, int x2, int y2, 
                int radius, int width,unsigned int color);

void DrawArcWide(int xc, int yc, int radius, int width, 
    unsigned int color, float start_angle_deg, float end_angle_deg);

void Fill_Rounded_Rectangle(int x1, int y1, int x2, int y2, 
                            int radius, unsigned int color);



#endif