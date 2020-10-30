#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#define width 650
#define length 500
#define pi 3.1415926
int main()
{
	initgraph(width, length);
	double x[7], y[7], r[7];//7个小球的坐标半径
	x[0] = 250, y[0] = 250, r[0] =35;//中间小球的原始坐标半径
	double add,add1;//小球的移动速度
	add = 2;
	add1 = 1.25;
	double t = 2;//大圆与小圆半径之比
	double dis = 150;//初始大圆和小圆的距离
	double angle[6];
	angle[0] = pi / 12;
	x[1] = dis * sin(angle[0]) + x[0];
	y[1] = dis * cos(-angle[0]) + y[0];
	r[1] = t * r[0];
	for (int i = 1; i < 6; i++)//给大圆坐标和半径
	{
		angle[i] = angle[i - 1] + pi / 3;
		x[i + 1] = dis * sin(angle[i]) + x[0];
		y[i + 1] = dis * cos(-angle[i]) + y[0];
		r[i + 1] = t * r[0];
	}
	setbkcolor(RGB(144, 144, 144));
	cleardevice();
	setfillcolor(RGB(255, 0, 0));
	solidcircle(x[0], y[0], r[0]);
	setfillcolor(BLUE);
	for (int i = 1; i < 7; i++)
	{
		solidcircle(x[i], y[i], r[i]);
	}
	BeginBatchDraw();
	while (1)
	{
		cleardevice();
		x[0] += add;
		y[0] += add1;
		setfillcolor(RGB(255, 0, 0));
		solidcircle(x[0], y[0], r[0]);
		FlushBatchDraw();
		Sleep(20);
		if (x[0] > 500 || x[0]<250)
		{
			add = -add;
			add1 = -add1 ;
		}
	}
	_getch();
	return 0;
}