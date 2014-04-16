#include"all.h"
void draw_bar1(int x,int y,int x1,int y1,int color)//此函数仅为遮住上次出现的东西而不画线
{
	setcolor(color);
	setlinestyle(0,0,1);
	setfillstyle(1,color);
	bar(x,y,x1,y1);
}