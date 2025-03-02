#include <all_func.h>
#define PI 3.14159265358979323846

/*
	�������ܣ��� (xc, yc) ΪԲ�ģ�radius ΪԲ���뾶��
	������ɫΪ color�����Ϊ width ��Բ����
	������ʼ�Ǻͽ����Ƿֱ��� start_angle_deg �� end_angle_deg ָ������λ���ȣ���
	��� start_angle_deg > end_angle_deg������Ϊ���߿�Խ 0�� �߽硣
 */
void Draw_Rounded_Rectangle(int x1, int y1, int x2, int y2, int radius, int width,unsigned int color)
{
	/* ������ */
	
	Line3(x1 + radius, y1, x2 - radius, y1, width, color);
	Line3(x2, y1 + radius, x2, y2 - radius, width, color);
	Line3(x1 + radius, y2, x2 - radius, y2, width, color);
	Line3(x1, y1 + radius, x1, y2 - radius, width, color);
	/* ��Բ�� */
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
	 
	 /* ���ǶȴӶ�ת��Ϊ���� */
	 start_angle = start_angle_deg * PI / 180.0;
	 end_angle   = end_angle_deg   * PI / 180.0;
	 
	 /* �뾶�Ϳ�ȱ���Ϊ���������˳� */
	 if (radius <= 0 || width <= 0)
	 {
		 return;
	 }
	 
	 y = radius;
	 d = 3 - (radius << 1);  // �ȼ��� d = 3 - 2 * radius
	 
	 for (x = 0; x <= y; x++)
	 {
		 /* �� Bresenham �㷨���ɵ�8���ԳƵ㣬
			����ÿ���������Բ�ĵļ��ǣ�ֻ�е��Ƕ���ָ��������ʱ�Ż��� */
		 
		 /* ��1�� (xc + x, yc + y) */
		 px = xc + x;
		 py = yc + y;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* ��2�� (xc + x, yc - y) */
		 px = xc + x;
		 py = yc - y;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* ��3�� (xc - x, yc - y) */
		 px = xc - x;
		 py = yc - y;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* ��4�� (xc - x, yc + y) */
		 px = xc - x;
		 py = yc + y;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* ��5�� (xc + y, yc + x) */
		 px = xc + y;
		 py = yc + x;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* ��6�� (xc + y, yc - x) */
		 px = xc + y;
		 py = yc - x;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* ��7�� (xc - y, yc - x) */
		 px = xc - y;
		 py = yc - x;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* ��8�� (xc - y, yc + x) */
		 px = xc - y;
		 py = yc + x;
		 angle = atan2((double)(py - yc), (double)(px - xc));
		 if (angle < 0) angle += 2 * PI;
		 if ((start_angle <= end_angle && angle >= start_angle && angle <= end_angle) ||
			 (start_angle > end_angle && (angle >= start_angle || angle <= end_angle)))
			 Circlefill(px, py, width, color);
		 
		 /* ���� Bresenham ���߱������� x��y �� d */
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

    // ��������������������Ч��Բ��Ϊ 0����ֱ�������ͨ����
    if (width <= 0 || height <= 0)
        return;
    if (radius <= 0) {
        Bar(x1, y1, x2, y2, color);
        return;
    }
    
    // ����Բ�ǰ뾶���ܳ������ο�Ȼ�߶ȵ�һ��
    if (radius > width / 2) radius = width / 2;
    if (radius > height / 2) radius = height / 2;
    
    // 1. ����������򣺸��ǳ���������Բ�ǲ���֮�������
    bar1(x1 + radius, y1, x2 - radius, y2, color);
    
    // 2. �������������������ϡ��¾�������Բ�ǲ���
    bar1(x1, y1 + radius, x1 + radius, y2 - radius, color);   // ���
    bar1(x2 - radius, y1 + radius, x2, y2 - radius, color);     // �Ҳ�
    
    // 3. ����ĸ��ǵ�Բ������ɨ���߷�����ķ�֮һԲ��
    
    // 3.1 ������Ͻǣ�Բ��λ�� (x1+radius, y1+radius)
    cx = x1 + radius;
    for (y = 0; y < radius; y++) {
        // �����ڵ�ǰ y ƫ���£���Բ�Ĵ�ֱ���� y����ˮƽ�������ƫ�� dx ���㣺dx^2 + y^2 <= radius^2
        dx = (int)(sqrt((double)radius * radius - (double)y * y) + 0.5);
        // ���� (cx - dx, y1 + radius - y - 1) �� (cx, y1 + radius - y) ��ˮƽ��
        bar1(cx - dx, y1 + radius - y - 1, cx, y1 + radius - y, color);
    }
    
    // 3.2 ������Ͻǣ�Բ��λ�� (x2 - radius, y1+radius)
    cx = x2 - radius;
    for (y = 0; y < radius; y++) {
        dx = (int)(sqrt((double)radius * radius - (double)y * y) + 0.5);
        // ���� (cx, y1 + radius - y - 1) �� (cx + dx, y1 + radius - y)
        bar1(cx, y1 + radius - y - 1, cx + dx, y1 + radius - y, color);
    }
    
    // 3.3 ������½ǣ�Բ��λ�� (x2 - radius, y2 - radius)
    cx = x2 - radius;
    for (y = 0; y < radius; y++) {
        dx = (int)(sqrt((double)radius * radius - (double)y * y) + 0.5);
        // ���� (cx, y2 - radius + y) �� (cx + dx, y2 - radius + y + 1)
        bar1(cx, y2 - radius + y, cx + dx, y2 - radius + y + 1, color);
    }
    
    // 3.4 ������½ǣ�Բ��λ�� (x1 + radius, y2 - radius)
    cx = x1 + radius;
    for (y = 0; y < radius; y++) {
        dx = (int)(sqrt((double)radius * radius - (double)y * y) + 0.5);
        // ���� (cx - dx, y2 - radius + y) �� (cx, y2 - radius + y + 1)
        bar1(cx - dx, y2 - radius + y, cx, y2 - radius + y + 1, color);
    }
}