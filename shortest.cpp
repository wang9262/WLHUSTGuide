#include  "all.h"
#include  "stru.h"
/*======================================================================
�˺���Ϊ��������������յ�����������֮�����̾���
======================================================================*/
void shortestpath(double p[][SPOTNUM], int n, double d[], int path[SPOTNUM], int s)         //��Ϊ��Dijkstra(�Ͻ�˹����)�㷨�ĺ��ģ�ֻ
//Ҫ���ô˺������ͻ���������S��ÿ�������̾���
//p�����ʾ���ھ���֮����룬��������Ϊ���ֵ��nΪ��������dΪ��̾��룻pathΪ���·������һ������룻sΪ���
{
	int i,j,k;
	int done[SPOTNUM];		//����ȷ�����·���Ƿ����
	//��ʼ������
	for(i=0; i<n; i++)
	{
		d[i] = MAX;	
		path[i] = -1;	//�����������
		done[i] = 0;	//���·����δ���
	}
	for(i =0; i<n; i++)
	{
		if(p[s][i] != MAX)		//��������ڵĵ�
		{
			d[i] = p[s][i];	
			path[i] = s;//��һ����뼴Ϊ���
		}
	}
	done[s] = 1;	//��㵽�������Ϊ�����
	d[s] = 0;	//��̾���Ϊ0
	int min, t;
	for( i=1; i<n; i++)
	{
		min = MAX;
		for(j=0; j<n; j++)		//�ҳ���һ���������̾�������̵�
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
		done[t] = 1;			//���Ϊ����
		for(k=0; k<n; k++)		//�Ե�ǰ��Ϊ��׼�����������̵ľ���
		{
				if(!done[k] && d[k]> min + p[t][k])	
				{
					 d[k] = min + p[t][k];
					 path[k] = t;
				}
		}
	}
}



/*=================����ĺ����������ǽṹ��=============================*/
void draw_point(POINT a[SPOTNUM] , int start_point, int finish_point)  
{
	setcolor(RED);
	setfillstyle(1,RED);
	bar(a[start_point].x-3, a[start_point].y-3, a[start_point].x+3, a[start_point].y+3);
	bar(a[finish_point].x-3, a[finish_point].y-3, a[finish_point].x+3, a[finish_point].y+3);
}

/*==============���ߵĺ����������ǽṹ�壬���Զ����ȣ���ɫ=================*/
void draw_line(POINT a,POINT b,int thicness,int color)    
{
	setcolor(color);
	setlinestyle(0,0,thicness);
	line(a.x,a.y,b.x,b.y);
}

/*=======================================================================
����path[ ]��Ľڵ�����·�ߣ����Ǵ��յ�����㿪ʼ���ġ�
=======================================================================*/
void drawroutine(int s, int f,  POINT *point, int *path)
{
	int i;
	int j=f;            //����jΪ�յ�
	while(path[j] != -1)   //ֱ���ҵ����
	{
		i=path[j];
		draw_line(point[j],point[i],3,RED);
		j=path[j];//��j��Ϊ��һ�ڵ�ı��
	}
	draw_point(point, f, s);
}


void change_route(CAR *cp, POINT *point, int *start_point, int *finish_point, int path[SPOTNUM],int *flag_road_error)
{
	int j;
	int i;
	int k=0;
	int allpoint[SPOTNUM];      //����һ���������еĽڵ������
	int route_point[SPOTNUM];
	int not_route[SPOTNUM];
	
	for(i=0; i<SPOTNUM; i++)   //�ȸ����鸳��ֵ
	{
		route_point[i]=-1;
		not_route[i]=-1;
		allpoint[i]=i;             //��ʼ���������нڵ������
	}
	
	
	j=*finish_point;
	while(path[j] != -1)   //�����·���Ľڵ㶼�浽������ȥ    
	{
		route_point[k]=path[j];
	     j=path[j];//��j��Ϊ��һ�ڵ�ı��
		k++;
	}
	for(j=0;j<SPOTNUM;j++)          
	{
		if(!(judge_point1(allpoint[j],route_point)))      //route_point[]��0 ��SPOTNUMѭ��
		{
			not_route[j]=allpoint[j];     //j��0 ��SPOTNUMѭ�����������,����뵽not_route
		}
	}	
	for(j=0; j<SPOTNUM; j++)
	{
		if(not_route[j] != -1 && not_route[j] != *start_point && not_route[j] != *finish_point )              //�Ѳ��ǽڵ��POINT��С����λ�öԱȣ����Ϊ�棬���˳�
		{
			if(1==judge_error(cp, point+not_route[j]))
			{
				*flag_road_error=1;
				*start_point=j;
			}
		}
		
	}
		
}

