#include"all.h"
#include"stru.h"
#include"public.h"
double rest_distance(CAR *cp,POINT finish_point)             //ʵʱ���С����λ�ã�����ʣ�����ļ���
{
	double rest_dis;
	rest_dis=sqrt((finish_point.x-cp->x)*(finish_point.x-cp->x)+(finish_point.y-cp->y)*(finish_point.y-cp->y));
	return rest_dis;
}
void show_distance(double *distance)                           //��ʾ��ǰ�ľ���
{
	int dec,sign;
     char  *str;
	char *str1={"M"};
	str=ecvt(*distance,5,&dec,&sign); 	//�ú������ڰѸ�����ת��Ϊ�ַ���
	dis_hz(495,150,"��Ŀ�ĵؾ��룺",0,20,LIGHTGREEN);
	setcolor(LIGHTBLUE);
	settextstyle(1,0,1);
	outtextxy(495,170,str);
	outtextxy(560,170,str1);
	setcolor(LIGHTRED);
	switch(dec)
	{
	     case 1:
			outtextxy(505,170,".");
		     break;
		case 2:
		     outtextxy(515.5,170,".");
               break;
		case 3:
	          outtextxy(528,170,".");
		     break;
		case 4:
		     outtextxy(539,170,".");
               break;
     }
}