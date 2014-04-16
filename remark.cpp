#include"all.h"
#include"public.h"
void remark(char *str[2])//show details of point
{
	draw_bar1(495,160,635,240,LIGHTGRAY);
	dis_hz(495,170,str[0],0,18,WHITE);
	dis_hz(495,190,str[1],0,18,WHITE);
}