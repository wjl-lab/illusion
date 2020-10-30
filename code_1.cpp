#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#define width 800
#define length 600
#define pi 3.1415926
int main()
{
	initgraph(width, length);
	double x[7], y[7], r[7];
	x[0] = 200, y[0] = length / 3, r[0] = 40;
	double add,add1;
	add = 2;
	add1 = 3;
	setbkcolor(RGB(144, 144, 144));
	cleardevice();
	setfillcolor(RGB(255, 0, 0));
	solidcircle(x[0], y[0], r[0]);
	BeginBatchDraw();
	while (1)
	{
		cleardevice();
		x[0] += add1;
		y[0] += add;
		setfillcolor(RGB(255, 0, 0));
		solidcircle(x[0], y[0], r[0]);
		FlushBatchDraw();
		Sleep(10);
		if (x[0] > 600 || x[0]<200)
		{
			add = -add;
			add1 = -add1 ;
		}
	}
	_getch();
	return 0;
}