#include"all.h"
#include"stru.h"
#include"public.h"
void right_plus()
{
	BUTTON  bt[4];
	int i;
	char *s[6]={"起点","终点","开始","交通模拟导航系统","信息栏","帮助"};
	/*整个右边的界面*/
	setcolor(LIGHTCYAN);   
	setfillstyle(1,LIGHTCYAN);
	bar(490,0,getmaxx(),getmaxy());
	line(490,0,490,getmaxy());
	
	setcolor(LIGHTBLUE);                            
	setfillstyle(1,LIGHTBLUE);
	bar(120,0,489,30);
	dis_hz(130,3,s[3],1,30,YELLOW);
	setfillstyle(1,BROWN);
	bar(470,0,489,20);
	setcolor(YELLOW);
	setlinestyle(0,0,3);//画X
	line(470,0,489,20);
	line(470,20,489,0);
     setcolor(DARKGRAY);
	for(i=0;i<3;i++)
	{
		bt[i].x=493+50*i;
		bt[i].y=3;
		bt[i].x1=bt[i].x+43;
		bt[i].y1=bt[i].y+25;
		bt[i].name=s[i];
		dr_button(&bt[i],YELLOW,20,0);
	}
	bt[3].x=5;bt[3].y=325;bt[3].x1=45;
	bt[3].y1=345;bt[3].name=s[5];
	draw_bar1(5,325,45,345,DARKGRAY);
	dr_button(&bt[3],YELLOW,20,0);
	dis_hz(520,35,s[4],0,30,BLUE);
	draw_bar(492,55,637,345,LIGHTGRAY);
  }
