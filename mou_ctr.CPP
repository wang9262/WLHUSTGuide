#include"all.h"
#include"stru.h"
#include"public.h"
#include"hong.h"
void mouse_ctrl(int *flag_click_beg,int *start,int *finish)

{
	int star_fin_flag=-1;
	int mouse_x=320,mouse_y=175,mouse_click;
	int i;
	BUTTON bt[4];
	int flag=0;  //设定一个状态值，避免重复画，而产生闪动的效果
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
		/*鼠标移动到按钮上，高亮显示按钮*/
		/*鼠标由按钮外进入按钮里，由于状态值flag为了1，所以如果检测到鼠标移动按钮的位置上时，
		会画出高亮时画面，而flag值已对变为0，所以不会再去画这种高亮状态，避免产生闪动的效果*/
		if(mouse_x>bt[0].x&& mouse_x<bt[0].x1&&mouse_y>bt[0].y&&mouse_y<bt[0].y1&& flag==1)
		{
		   cursor(mouse_x,mouse_y);         //此处的具体含义是在此位置进行画鼠标用异或的方式覆盖掉，下面再调用一次cursor(mouse_x,mouse_y);在此位置画一个鼠标
		   bt[0].state=HIGHLIGHT;                //这个是一旦检测到鼠标进入到这个位置，就画一个鼠标，然后第二个是在外面把它异或掉，注意这个是在鼠标在外面就画了
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
			setlinestyle(0,0,3);//画X
			line(470,0,489,20);
			  line(470,20,489,0);
			flag=0;
			cursor(mouse_x,mouse_y);
		}
		  /*鼠标移出按钮，按钮回复常态,如果此时鼠标已经按下，则再点鼠标也没有任何反应*/
		  /*开始的时候，鼠标肯定是在按钮之外。即使flag为0，进入这种状态后，立即让flag变为1.如果鼠标还在按钮之外移动的话，
				 就只会在新的位置画出鼠标了，而不会再去画按钮，从而避免产生闪动的效果*/
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
				setlinestyle(0,0,3);//画X
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
			choose(star_fin_flag,start);
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
			choose(star_fin_flag,finish);
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
			c_help();
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