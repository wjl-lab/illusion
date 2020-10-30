#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#define width 1000
#define length 1000
#define pi 3.1415926
void original();

int main()
{
	initgraph(width, length);
	double x[7], y[7], r[7];//7个小球的坐标半径
	x[0] = 250, y[0] = 200, r[0] = 35;//中间小球的原始坐标半径
	double add, add1;//小球的移动速度
	add = 7.5;
	add1 = 6;
	double t = 2.5;//大圆与小圆半径之比
	double change = 0.006;
	double change1 = 0.35;
	double dis = 175;//初始大圆和小圆的距离
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
		setfillcolor(BLUE);
		//solidcircle(x[1], y[1], r[1]);
		x[1] = dis * sin(angle[0]) + x[0];
		y[1] = dis * cos(-angle[0]) + y[0];
		r[1] = t * r[0];
		solidcircle(x[1], y[1], r[1]);
		for (int i = 1; i < 6; i++)//给大圆坐标和半径
		{
			angle[i] = angle[i - 1] + pi / 3;
			x[i + 1] = dis * sin(angle[i]) + x[0];
			y[i + 1] = dis * cos(-angle[i]) + y[0];
			r[i + 1] = t * r[0];
			solidcircle(x[i + 1], y[i + 1], r[i + 1]);
			t = t - change;
			dis = dis - change1;
		}
		if (_kbhit())
		{
			original();
		}
		FlushBatchDraw();
		Sleep(15);
		if (x[0] > 750 || x[0] < 250)
		{
			add = -add;
			add1 = -add1;
			change1 = -1 * change1;
			change = -1 * change;
		}
	}
	_getch();
	closegraph();
	return 0;
}
//原始圆
void original()
{
	char input = _getch();
	if (input == ' ')
	{
		cleardevice();
		int x = 250, y = 200, r = 35;
		double add, add1;
		add = 3;
		add1 = 2;
		while (1)
		{
			cleardevice();
			x += add;
			y += add1;
			setfillcolor(RGB(255, 0, 0));
			solidcircle(x, y, r);
			FlushBatchDraw();
			Sleep(10);
			if (x > 750 || x < 250)
			{
				add = -add;
				add1 = -add1;
			}
			if (_kbhit())
			{
				input = _getch();
				if (input == ' ')
				{
					break;
				}
			}
		}
	}
}