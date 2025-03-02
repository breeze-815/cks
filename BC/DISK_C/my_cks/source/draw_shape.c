#include <all_func.h>
#define PI 3.14159265358979323846

/*
	函数功能：在 (xc, yc) 为圆心，radius 为圆弧半径，
	绘制颜色为 color、宽度为 width 的圆弧，
	弧线起始角和结束角分别由 start_angle_deg 和 end_angle_deg 指定（单位：度）。
	如果 start_angle_deg > end_angle_deg，则认为弧线跨越 0° 边界。
 */
void Draw_Rounded_Rectangle(int x1, int y1, int x2, int y2, int radius, int width,unsigned int color)
{
	/* 画矩形 */
	
	Line3(x1 + radius, y1, x2 - radius, y1, width, color);
	Line3(x2, y1 + radius, x2, y2 - radius, width, color);
	Line3(x1 + radius, y2, x2 - radius, y2, width, color);
	Line3(x1, y1 + radius, x1, y2 - radius, width, color);
	/* 画圆弧 */
	DrawArcWide(x1 + radius, y1 + radius, radius, width, color, 180, 270);
	DrawArcWide(x2 - radius, y1 + radius, radius, width, color, 270, 360);
	DrawArcWide(x2 - radius, y2 - radius, radius, width, color, 0, 90);
	DrawArcWide(x1 + radius, y2 - radius, radius, width, color, 90, 180);
}

void DrawArcWide(int xc, int yc, int radius, int width, unsigned int color, float start_angle_deg, float end_angle_deg)
 {
	 int x, y, d;
	 double start_angle, end_angle, angle;
	 int px, py;
	 
	 /* 将角度从度转换为弧度 */
	 start_angle = start_angle_deg * PI / 180.0;
	 end_angle   = end_angle_deg   * PI / 180.0;
	 
	 /* 半径和宽度必须为正，否则退出 */
	 if (radius <= 0 || width <= 0)
	 {
		 return;
	 }
	 
	 y = radius;
	 d = 3 - (radius << 1);  // 等价于 d = 3 - 2 * radius
	 
	 for (x = 0; x <= y; x++)
	 {
		 /* 对 Bresenham 算法生成的8个对称点，
			计算每个点相对于圆心的极角，只有当角度在指定区间内时才绘制 */
		 
		 /* 点1： (xc + x, yc + y) */
		 px = xc + x;
		 py = yc + y;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* 点2： (xc + x, yc - y) */
		 px = xc + x;
		 py = yc - y;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* 点3： (xc - x, yc - y) */
		 px = xc - x;
		 py = yc - y;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* 点4： (xc - x, yc + y) */
		 px = xc - x;
		 py = yc + y;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* 点5： (xc + y, yc + x) */
		 px = xc + y;
		 py = yc + x;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* 点6： (xc + y, yc - x) */
		 px = xc + y;
		 py = yc - x;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* 点7： (xc - y, yc - x) */
		 px = xc - y;
		 py = yc - x;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* 点8： (xc - y, yc + x) */
		 px = xc - y;
		 py = yc + x;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* 根据 Bresenham 决策变量更新 x、y 和 d */
		 if (d < 0)
		 {
			 d += x * 4 + 6;
		 }
		 else
		 {
			 d += (x - y) * 4 + 10;
			 y--;
		 }
	 }
 }

void Fill_Rounded_Rectangle(int x1, int y1, int x2, int y2, int radius, unsigned int color)
{
    int width = x2 - x1;
    int height = y2 - y1;
    int cx, dx;
    int y;

    // 检查基本参数：若矩形无效或圆角为 0，则直接填充普通矩形
    if (width <= 0 || height <= 0)
        return;
    if (radius <= 0) {
        Bar(x1, y1, x2, y2, color);
        return;
    }
    
    // 限制圆角半径不能超过矩形宽度或高度的一半
    if (radius > width / 2) radius = width / 2;
    if (radius > height / 2) radius = height / 2;
    
    // 1. 填充中央区域：覆盖除左右两侧圆角部分之外的区域
    bar1(x1 + radius, y1, x2 - radius, y2, color);
    
    // 2. 填充左右两侧矩形区域：上、下均不包含圆角部分
    bar1(x1, y1 + radius, x1 + radius, y2 - radius, color);   // 左侧
    bar1(x2 - radius, y1 + radius, x2, y2 - radius, color);     // 右侧
    
    // 3. 填充四个角的圆形区域（扫描线法填充四分之一圆）
    
    // 3.1 填充左上角：圆心位于 (x1+radius, y1+radius)
    cx = x1 + radius;
    for (y = 0; y < radius; y++) {
        // 计算在当前 y 偏移下（距圆心垂直距离 y），水平方向最大偏移 dx 满足：dx^2 + y^2 <= radius^2
        dx = (int)(sqrt((double)radius * radius - (double)y * y) + 0.5);
        // 填充从 (cx - dx, y1 + radius - y - 1) 到 (cx, y1 + radius - y) 的水平线
        bar1(cx - dx, y1 + radius - y - 1, cx, y1 + radius - y, color);
    }
    
    // 3.2 填充右上角：圆心位于 (x2 - radius, y1+radius)
    cx = x2 - radius;
    for (y = 0; y < radius; y++) {
        dx = (int)(sqrt((double)radius * radius - (double)y * y) + 0.5);
        // 填充从 (cx, y1 + radius - y - 1) 到 (cx + dx, y1 + radius - y)
        bar1(cx, y1 + radius - y - 1, cx + dx, y1 + radius - y, color);
    }
    
    // 3.3 填充右下角：圆心位于 (x2 - radius, y2 - radius)
    cx = x2 - radius;
    for (y = 0; y < radius; y++) {
        dx = (int)(sqrt((double)radius * radius - (double)y * y) + 0.5);
        // 填充从 (cx, y2 - radius + y) 到 (cx + dx, y2 - radius + y + 1)
        bar1(cx, y2 - radius + y, cx + dx, y2 - radius + y + 1, color);
    }
    
    // 3.4 填充左下角：圆心位于 (x1 + radius, y2 - radius)
    cx = x1 + radius;
    for (y = 0; y < radius; y++) {
        dx = (int)(sqrt((double)radius * radius - (double)y * y) + 0.5);
        // 填充从 (cx - dx, y2 - radius + y) 到 (cx, y2 - radius + y + 1)
        bar1(cx - dx, y2 - radius + y, cx, y2 - radius + y + 1, color);
    }
}