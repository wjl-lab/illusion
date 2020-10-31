#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
/********** 定义全局变量 **********/
#define WIDTH 1000
#define LENGTH 800
#define PI 3.1415926
/********** 绘制中间的圆 **********/
void originCircle(double x, double y, double r)
{
	setfillcolor(RGB(255, 0, 0));
	solidcircle(x, y, r);
}
/********** 绘制旁边的一个小圆 **********/
void surroundCircle(double x, double y, double r)
{
	setfillcolor(BLUE);
	solidcircle(x, y, r);
}
/********** 插入滑稽图片后一起移动 **********/
void funnyMove(double x, double y, double r)
{
	IMAGE img; // 插入图片
	loadimage(&img, _T("D:\\图片2.png"), 2 * r, 2 * r, true);
	putimage(x - r, y - r, &img);
}
int main(void)
{
	initgraph(WIDTH, LENGTH);
	int drawMode = 1;
	double x[7], y[7], r[7];//7个小圆的坐标半径
	x[0] = 250, y[0] = 240, r[0] = 35;//中间小圆的原始坐标半径
	double speedX = 3.0, speedY = 2.4;//小圆的移动速度
	double ratio = 2.25;//大圆与小圆半径之比
	double radius_change = 0.0018;//半径比例的变化率
	double dis_change = 0.10;//距离的变化率
	double dis = 163;//初始大圆和小圆的距离 
	double angle[6];
	angle[0] = PI / 12;//一个大圆数据
	x[1] = dis * sin(angle[0]) + x[0];
	y[1] = dis * cos(-angle[0]) + y[0];
	r[1] = ratio * r[0];
	for (int i = 1; i < 6; i++)//给定其它大圆数据
	{
		angle[i] = angle[i - 1] + PI / 3;
		x[i + 1] = dis * sin(angle[i]) + x[0];
		y[i + 1] = dis * cos(-angle[i]) + y[0];
		r[i + 1] = ratio * r[0];
	}
	setbkcolor(RGB(0, 0, 0));
	cleardevice();
	originCircle(x[0], y[0], r[0]);//绘制小圆
	for (int i = 1; i < 7; i++)//批量绘制大圆
		surroundCircle(x[i], y[i], r[i]);
	BeginBatchDraw();
	while (1)
	{
		cleardevice();
		if (_kbhit())
		{
			char input = _getch(); // 获得用户按键
			if (input == ' ') // 空格键
			{
				cleardevice(); // 清屏
				drawMode = drawMode + 1; // 进行下一种绘图模式
				if (drawMode > 3) // 如果大于4，重新回到第1种绘图模式
					drawMode -= 3;
			}
		}
		if (drawMode == 1)//绘制七个圆一起移动
		{
			x[0] += speedX;
			y[0] += speedY;
			originCircle(x[0], y[0], r[0]);//绘制小圆
			x[1] = dis * sin(angle[0]) + x[0];
			y[1] = dis * cos(-angle[0]) + y[0];
			r[1] = ratio * r[0];
			surroundCircle(x[1], y[1], r[1]);
			for (int i = 1; i < 6; i++)//给定其他大圆坐标和半径
			{
				angle[i] = angle[i - 1] + PI / 3;
				x[i + 1] = dis * sin(angle[i]) + x[0];
				y[i + 1] = dis * cos(-angle[i]) + y[0];
				r[i + 1] = ratio * r[0];
				surroundCircle(x[i + 1], y[i + 1], r[i + 1]);
				ratio = ratio - radius_change;
				dis = dis - dis_change;
			}
			FlushBatchDraw();
			Sleep(10);
			if (x[0] > 800 || x[0] < 250)
			{
				speedX = -speedX;//小球速度反向
				speedY = -speedY;
				dis_change = -1 * dis_change;
				radius_change = -1 * radius_change;
			}
		}
		if (drawMode == 2)//绘制中间小圆移动
		{
			x[0] += speedX;
			y[0] += speedY;
			originCircle(x[0], y[0], r[0]);//绘制小圆
			x[1] = dis * sin(angle[0]) + x[0];
			y[1] = dis * cos(-angle[0]) + y[0];
			r[1] = ratio * r[0];
			for (int i = 1; i < 6; i++)//给定其他大圆坐标和半径
			{
				angle[i] = angle[i - 1] + PI / 3;
				x[i + 1] = dis * sin(angle[i]) + x[0];
				y[i + 1] = dis * cos(-angle[i]) + y[0];
				r[i + 1] = ratio * r[0];
				ratio = ratio - radius_change;
				dis = dis - dis_change;
			}
			FlushBatchDraw();
			Sleep(10);
			if (x[0] > 750 || x[0] < 250)
			{
				speedX = -speedX;//小球速度反向
				speedY = -speedY;
				dis_change = -1 * dis_change;
				radius_change = -1 * radius_change;
			}
		}
		if (drawMode == 3)
		{
			x[0] += speedX;
			y[0] += speedY;
			funnyMove(x[0], y[0], r[0]);
			x[1] = dis * sin(angle[0]) + x[0];
			y[1] = dis * cos(-angle[0]) + y[0];
			r[1] = ratio * r[0];
			funnyMove(x[1], y[1], r[1]);
			for (int i = 1; i < 6; i++)//给定其他大圆坐标和半径
			{
				angle[i] = angle[i - 1] + PI / 3;
				x[i + 1] = dis * sin(angle[i]) + x[0];
				y[i + 1] = dis * cos(-angle[i]) + y[0];
				r[i + 1] = ratio * r[0];
				funnyMove(x[i + 1], y[i + 1], r[i + 1]);
				ratio = ratio - radius_change;
				dis = dis - dis_change;
			}
			FlushBatchDraw();
			Sleep(5);
			if (x[0] > 750 || x[0] < 250)
			{
				speedX = -speedX;//小球速度反向
				speedY = -speedY;
				dis_change = -1 * dis_change;
				radius_change = -1 * radius_change;
			}
		}
	}
	_getch();
	closegraph();
	return 0;
}