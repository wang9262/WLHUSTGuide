#include"all.h"
#include"stru.h"
#include"public.h"
#include"hong.h"
void search(POINT point[SPOTNUM],int *flag_click_beg,int *start,int *finish)
{   
	int star_fin_flag=-1;
	int mouse_x=320,mouse_y=175,mouse_click;
	int i;
	BUTTON bt[4];
	int flag=0;  //�趨һ��״ֵ̬�������ظ�����������������Ч��
     for(i=0;i<3;i++)
	{
		bt[i].x=493+50*i;
		bt[i].y=3;
		bt[i].x1=bt[i].x+43;
		bt[i].y1=bt[i].y+25;
	}
	bt[3].x=5;bt[3].y=325;bt[3].x1=45;
	bt[3].y1=345;
	initmouse(0,getmaxx(),0,getmaxy());
	cursor(mouse_x,mouse_y);
	while(1)
	{
		newmouse(&mouse_x, &mouse_y, &mouse_click);
		/*����ƶ�����ť�ϣ�������ʾ��ť*/
		/*����ɰ�ť����밴ť�����״ֵ̬flagΪ��1�����������⵽����ƶ���ť��λ����ʱ��
		�ử������ʱ���棬��flagֵ�ѶԱ�Ϊ0�����Բ�����ȥ�����ָ���״̬���������������Ч��*/

		if(mouse_x>bt[0].x&& mouse_x<bt[0].x1&&mouse_y>bt[0].y&&mouse_y<bt[0].y1&& flag==1)
		{
		   cursor(mouse_x,mouse_y);         //�˴��ľ��庬�����ڴ�λ�ý��л���������ķ�ʽ���ǵ��������ٵ���һ��cursor(mouse_x,mouse_y);�ڴ�λ�û�һ�����
		   bt[0].state=HIGHLIGHT;                //�����һ����⵽�����뵽���λ�ã��ͻ�һ����꣬Ȼ��ڶ��������������������ע������������������ͻ���
		   dr_LPbutton(&bt[0]);
		   flag=0;
		   cursor(mouse_x,mouse_y);
		}
		if(mouse_x>bt[1].x&& mouse_x<bt[1].x1&&mouse_y>bt[1].y&&mouse_y<bt[1].y1&& flag==1)
		{
		   cursor(mouse_x,mouse_y);
		   bt[1].state=HIGHLIGHT;
		   dr_LPbutton(&bt[1]);
		   flag=0;
		   cursor(mouse_x,mouse_y);
		}
		if(mouse_x>bt[2].x&& mouse_x<bt[2].x1&&mouse_y>bt[2].y&&mouse_y<bt[2].y1&& flag==1)
		{
		   cursor(mouse_x,mouse_y);
		   bt[2].state=HIGHLIGHT;
		   dr_LPbutton(&bt[2]);
		   flag=0;
		   cursor(mouse_x,mouse_y);
		}
		if(mouse_x>bt[3].x&& mouse_x<bt[3].x1&&mouse_y>bt[3].y&&mouse_y<bt[3].y1&& flag==1)
		{
		   cursor(mouse_x,mouse_y);
		   bt[3].state=HIGHLIGHT;
		   dr_LPbutton(&bt[3]);
		   flag=0;
		   cursor(mouse_x,mouse_y);
		}

		if(mouse_x>470&& mouse_x<490&&mouse_y>0&&mouse_y<30&& flag==1)
		{
			cursor(mouse_x,mouse_y);
			setfillstyle(1,WHITE);
			bar(470,0,489,20);
			setcolor(BLACK);
			setlinestyle(0,0,3);//��X
			line(470,0,489,20);
			line(470,20,489,0);
			flag=0;
			cursor(mouse_x,mouse_y);
		}
		  /*����Ƴ���ť����ť�ظ���̬,�����ʱ����Ѿ����£����ٵ����Ҳû���κη�Ӧ*/
		  /*��ʼ��ʱ�����϶����ڰ�ť֮�⡣��ʹflagΪ0����������״̬��������flag��Ϊ1.�����껹�ڰ�ť֮���ƶ��Ļ���
				 ��ֻ�����µ�λ�û�������ˣ���������ȥ����ť���Ӷ��������������Ч��*/
		if(!(mouse_x>bt[0].x && mouse_x<bt[0].x1 && mouse_y>bt[0].y && mouse_y<bt[0].y1)
			&&!(mouse_x>bt[1].x && mouse_x<bt[1].x1 &&mouse_y>bt[1].y && mouse_y<bt[1].y1)
			&&!(mouse_x>bt[2].x && mouse_x<bt[2].x1 && mouse_y>bt[2].y&& mouse_y<bt[2].y1)
		     &&!(mouse_x>bt[3].x && mouse_x<bt[3].x1 && mouse_y>bt[3].y&& mouse_y<bt[3].y1)
		     &&!(mouse_x>470&& mouse_x<490&&mouse_y>0&&mouse_y<30))
		{
			if(0==flag)
			{

				flag=1;
				bt[0].state= NORMALSTATE;
				bt[1].state= NORMALSTATE;
				bt[2].state= NORMALSTATE;
				bt[3].state= NORMALSTATE;
				cursor(mouse_x,mouse_y);
				dr_LPbutton(&bt[0]);
				dr_LPbutton(&bt[1]);
				dr_LPbutton(&bt[2]);
				dr_LPbutton(&bt[3]);
				setfillstyle(1,BROWN);
				bar(470,0,489,20);
				setcolor(YELLOW);
				setlinestyle(0,0,3);//��X
				line(470,0,489,20);
				line(470,20,489,0);
				cursor(mouse_x,mouse_y);
			}
		}

		if(1==mouse_click &&mouse_x>bt[0].x && mouse_x<bt[0].x1 && mouse_y>bt[0].y && mouse_y<bt[0].y1)
		{
			star_fin_flag=0;
			*flag_click_beg=0;
			cursor(mouse_x,mouse_y);
			bt[0].state=PRESS;
			dr_LPbutton(&bt[0]);
			cursor(mouse_x,mouse_y);
			cursor(mouse_x,mouse_y);
			input(point,star_fin_flag,start);
			break;
		}
		if(1==mouse_click &&mouse_x>bt[1].x && mouse_x<bt[1].x1 && mouse_y>bt[1].y && mouse_y<bt[1].y1)
		{
			star_fin_flag=1;
			*flag_click_beg=0;
			cursor(mouse_x,mouse_y);
			bt[1].state=PRESS;
			dr_LPbutton(&bt[1]);
			cursor(mouse_x,mouse_y);
			cursor(mouse_x,mouse_y);
			input(point,star_fin_flag,finish);
			break;
		}
		if(1==mouse_click &&mouse_x>bt[2].x && mouse_x<bt[2].x1 && mouse_y>bt[2].y && mouse_y<bt[2].y1)
		{
			*flag_click_beg=1;
			cursor(mouse_x,mouse_y);
			bt[2].state=PRESS;
			dr_LPbutton(&bt[2]);
			cursor(mouse_x,mouse_y);
			cursor(mouse_x,mouse_y);
			break;
		}
		if(1==mouse_click &&mouse_x>bt[3].x && mouse_x<bt[3].x1 && mouse_y>bt[3].y && mouse_y<bt[3].y1)
		{
			bt[3].state=PRESS;
			dr_LPbutton(&bt[3]);
			s_help();
			cleardevice();
			setbkcolor(LIGHTGREEN);
			break;
		}
		if( mouse_click==1&&mouse_x>470 && mouse_x<489 && mouse_y>0 && mouse_y<30)
		{
			cursor(mouse_x,mouse_y);
			closegraph();
			goodbye();
			exit(0);
		}
    }
}