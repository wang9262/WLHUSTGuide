#include"all.h"
#include"public.h"
void show_sta_fin(char *str,int star_fini_flag)//show start(0) and finish(1) 
{
	draw_bar1(495,260,636,345,LIGHTGRAY);
	switch(star_fini_flag)
	{
		case 0:
	     dis_hz(495,260,"��㣺",0,20,WHITE);
	     dis_hz(555,260,str,0,20,LIGHTCYAN);
		dis_hz(495,280,"��ѡ����㣬����",0,18,LIGHTRED);
		dis_hz(495,300,"����˳�",0,18,LIGHTRED);
		break;
		case 1:
	     dis_hz(495,260,"�յ㣺",0,20,WHITE);
	     dis_hz(555,260,str,0,20,LIGHTCYAN);
		dis_hz(495,280,"��ѡ���յ㣬����",0,18,LIGHTRED);
		dis_hz(495,300,"����˳�",0,18,LIGHTRED);
		break;
	}
	getch();
	setcolor(LIGHTGRAY);
	bar(492,55,637,345);
	setcolor(WHITE);
	line(493,56,637,56);
	line(493,56,493,344);	
	line(637,345,637,56);
	line(637,345,493,345);
}