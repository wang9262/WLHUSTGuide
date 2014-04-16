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
void judge_pre_car(CAR *cp, POINT *point)   //判断当前小车的位置，要一个一个地地点去列举
{
	int i;
	for(i=0; i<SPOTNUM; i++,point++)
	{
		if((cp->x-point->x)*(cp->x-point->x)+(cp->y-point->y)*(cp->y-point->y)<=400)   //如果小车在节点的一定的距离以内，就会显示地点的名称
		{
			draw_bar1(494,57,636,150,LIGHTGRAY);
			dis_hz(495,60,"当前位置：",0,30,WHITE);
			dis_hz(495,90,point->name,0,20,YELLOW);//显示节点的名称
			dis_hz(495,110,point->remarks[0],0,18,WHITE);
			dis_hz(495,130,point->remarks[1],0,18,WHITE);
		}
	}
}
/*====this just to judge if car is at point location==========*/
int judge_error(CAR *cp, POINT *point)      //这也是一个判断小车当前的位置，与上面的函数不同的是只是判断一个
{
	if((cp->x-point->x)*(cp->x-point->x)+(cp->y-point->y)*(cp->y-point->y)<=400)  
	{
		return 1;
	}
	else 
		return 0;
}
/*========judge if a is in b[],this will be used in change routine========*/
int judge_point1(int a, int b[])           //判断a是否属于b[ ]
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

