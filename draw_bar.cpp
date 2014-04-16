#include"all.h"
void draw_bar(int x,int y,int x1,int y1,int color)//此函数加上画线部分，突出立体感，cubic
{
	setcolor(color);
	setlinestyle(0,0,1);
	setfillstyle(1,color);
	bar(x,y,x1,y1);
	setcolor(WHITE);
	line(x+1,y+1,x1,y+1);
	line(x+1,y+1,x+1,y1-1);	
	line(x1,y1,x1,y+1);
	line(x1,y1,x+1,y1);
}