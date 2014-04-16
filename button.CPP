#include  "all.h"
#include  "stru.h"
#include  "public.h"
#include  "hong.h"
/*画正常状态下按钮的函数*/
void dr_button(BUTTON *bt,int color,int dis,int flag)
{
	setlinestyle(0,0,1);  
	rectangle(bt->x,bt->y,bt->x1,bt->y1);
	setfillstyle(1,LIGHTGRAY);   
	bar(bt->x+1,bt->y+1,bt->x1-1,bt->y1-1); 
	dis_hz(bt->x+3,bt->y+3,bt->name,flag,dis,color);
}
/*高亮状态和按下状态*/
void dr_LPbutton(BUTTON *bt)
{
	setlinestyle(0,0,1); 
	if(PRESS==bt->state)   
	{
		setcolor(CYAN);
		line(bt->x,bt->y,bt->x1,bt->y);
		line(bt->x,bt->y,bt->x,bt->y1);
		setcolor(WHITE);
		line(bt->x,bt->y1,bt->x1,bt->y1);
		line(bt->x1,bt->y1,bt->x1,bt->y);
	}
	else if(HIGHLIGHT== bt->state)  
	{
		setcolor(WHITE);
		line(bt->x,bt->y,bt->x1,bt->y);
		line(bt->x,bt->y,bt->x,bt->y1);
		setcolor(CYAN);
		line(bt->x,bt->y1,bt->x1,bt->y1);
		line(bt->x1,bt->y1,bt->x1,bt->y);
		
	}
	else if(NORMALSTATE==bt->state)
	{
		setcolor(DARKGRAY);                 
		line(bt->x,bt->y,bt->x,bt->y1);
          line(bt->x,bt->y,bt->x1,bt->y);
          line(bt->x1,bt->y,bt->x1,bt->y1);
          line(bt->x,bt->y1,bt->x1,bt->y1);
		
	}
}

