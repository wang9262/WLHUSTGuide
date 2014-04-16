#include"all.h"
#include"stru.h"
#include"public.h"
#include"hong.h"
/*=========This function is used to judge if the car has got to the finish_point===========*/
int judge_finish(CAR *cp, POINT finish_point) 
{
	if((cp->x-finish_point.x)*(cp->x-finish_point.x)+(cp->y-finish_point.y)*(cp->y-finish_point.y)<=400)
		return 1; 
	else 
		return 0;
}
/*=======judge present car location============*/
void judge_pre_car(CAR *cp, POINT *point)   //�жϵ�ǰС����λ�ã�Ҫһ��һ���صص�ȥ�о�
{
	int i;
	for(i=0; i<SPOTNUM; i++,point++)
	{
		if((cp->x-point->x)*(cp->x-point->x)+(cp->y-point->y)*(cp->y-point->y)<=400)   //���С���ڽڵ��һ���ľ������ڣ��ͻ���ʾ�ص������
		{
			draw_bar1(494,57,636,150,LIGHTGRAY);
			dis_hz(495,60,"��ǰλ�ã�",0,30,WHITE);
			dis_hz(495,90,point->name,0,20,YELLOW);//��ʾ�ڵ������
			dis_hz(495,110,point->remarks[0],0,18,WHITE);
			dis_hz(495,130,point->remarks[1],0,18,WHITE);
		}
	}
}
/*====this just to judge if car is at point location==========*/
int judge_error(CAR *cp, POINT *point)      //��Ҳ��һ���ж�С����ǰ��λ�ã�������ĺ�����ͬ����ֻ���ж�һ��
{
	if((cp->x-point->x)*(cp->x-point->x)+(cp->y-point->y)*(cp->y-point->y)<=400)  
	{
		return 1;
	}
	else 
		return 0;
}
/*========judge if a is in b[],this will be used in change routine========*/
int judge_point1(int a, int b[])           //�ж�a�Ƿ�����b[ ]
{
	int i;
	for(i=0; i<SPOTNUM; i++)
	{
		if(a == b[i])
		{
			return 1;
		}
	}
	return 0;
}

