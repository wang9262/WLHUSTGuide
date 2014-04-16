#include  "all.h"
#include  "stru.h"
/*======================================================================
此函数为根据输入的起点和终点来计算两点之间的最短距离
======================================================================*/
void shortestpath(double p[][SPOTNUM], int n, double d[], int path[SPOTNUM], int s)         //此为了Dijkstra(迪杰斯特拉)算法的核心，只
//要调用此函数，就会算出从起点S到每个点的最短距离
//p数组表示相邻景点之间距离，若不相邻为最大值；n为景点数；d为最短距离；path为最短路径中上一景点编码；s为起点
{
	int i,j,k;
	int done[SPOTNUM];		//变量确定最短路径是否求出
	//初始化变量
	for(i=0; i<n; i++)
	{
		d[i] = MAX;	
		path[i] = -1;	//两点均不相邻
		done[i] = 0;	//最短路径均未求出
	}
	for(i =0; i<n; i++)
	{
		if(p[s][i] != MAX)		//与起点相邻的点
		{
			d[i] = p[s][i];	
			path[i] = s;//上一点编码即为起点
		}
	}
	done[s] = 1;	//起点到起点设置为以求出
	d[s] = 0;	//最短距离为0
	int min, t;
	for( i=1; i<n; i++)
	{
		min = MAX;
		for(j=0; j<n; j++)		//找出上一次求出的最短距离中最短的
		{
			if(!done[j])
			{
				if(d[j]<min)
				{
					min = d[j];
					t = j;
				}
			}
		}
		done[t] = 1;			//标记为已求
		for(k=0; k<n; k++)		//以当前点为基准，求出所有最短的距离
		{
				if(!done[k] && d[k]> min + p[t][k])	
				{
					 d[k] = min + p[t][k];
					 path[k] = t;
				}
		}
	}
}



/*=================画点的函数，参数是结构体=============================*/
void draw_point(POINT a[SPOTNUM] , int start_point, int finish_point)  
{
	setcolor(RED);
	setfillstyle(1,RED);
	bar(a[start_point].x-3, a[start_point].y-3, a[start_point].x+3, a[start_point].y+3);
	bar(a[finish_point].x-3, a[finish_point].y-3, a[finish_point].x+3, a[finish_point].y+3);
}

/*==============画线的函数，参数是结构体，可以定义厚度，颜色=================*/
void draw_line(POINT a,POINT b,int thicness,int color)    
{
	setcolor(color);
	setlinestyle(0,0,thicness);
	line(a.x,a.y,b.x,b.y);
}

/*=======================================================================
根据path[ ]里的节点来画路线，这是从终点向起点开始画的。
=======================================================================*/
void drawroutine(int s, int f,  POINT *point, int *path)
{
	int i;
	int j=f;            //先让j为终点
	while(path[j] != -1)   //直到找到起点
	{
		i=path[j];
		draw_line(point[j],point[i],3,RED);
		j=path[j];//将j赋为上一节点的编号
	}
	draw_point(point, f, s);
}


void change_route(CAR *cp, POINT *point, int *start_point, int *finish_point, int path[SPOTNUM],int *flag_road_error)
{
	int j;
	int i;
	int k=0;
	int allpoint[SPOTNUM];      //定义一个包含所有的节点的数组
	int route_point[SPOTNUM];
	int not_route[SPOTNUM];
	
	for(i=0; i<SPOTNUM; i++)   //先给数组赋初值
	{
		route_point[i]=-1;
		not_route[i]=-1;
		allpoint[i]=i;             //初始化存有所有节点的数组
	}
	
	
	j=*finish_point;
	while(path[j] != -1)   //把最短路径的节点都存到数组里去    
	{
		route_point[k]=path[j];
	     j=path[j];//把j赋为上一节点的编号
		k++;
	}
	for(j=0;j<SPOTNUM;j++)          
	{
		if(!(judge_point1(allpoint[j],route_point)))      //route_point[]从0 到SPOTNUM循环
		{
			not_route[j]=allpoint[j];     //j从0 到SPOTNUM循环，如果不是,则存入到not_route
		}
	}	
	for(j=0; j<SPOTNUM; j++)
	{
		if(not_route[j] != -1 && not_route[j] != *start_point && not_route[j] != *finish_point )              //把不是节点的POINT和小车的位置对比，如果为真，则退出
		{
			if(1==judge_error(cp, point+not_route[j]))
			{
				*flag_road_error=1;
				*start_point=j;
			}
		}
		
	}
		
}

