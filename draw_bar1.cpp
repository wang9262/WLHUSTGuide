#include"all.h"
void draw_bar1(int x,int y,int x1,int y1,int color)//�˺�����Ϊ��ס�ϴγ��ֵĶ�����������
{
	setcolor(color);
	setlinestyle(0,0,1);
	setfillstyle(1,color);
	bar(x,y,x1,y1);
}