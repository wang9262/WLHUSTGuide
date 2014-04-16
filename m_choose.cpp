#include"all.h"
#include"stru.h"
#include"public.h"
void m_choose(int *choice)// choice to return for main_page 
{
	int i,dotx,doty,h,w,color,maxcolor;
     int mousex,mousey,mousekey;
	mousex=320;mousey=240;
	int flag=0;
     unsigned seed;
     char *s[2]={"选择模式","搜索模式"};
     char *ss[6]={"交","通","模","拟","导","航"};
     BUTTON bt[3];
	cleardevice();
     maxcolor=getmaxcolor();
     w=getmaxx()-20;
     h=getmaxy()-20;
	initmouse(0,639,0,479);
     srand(seed);
     for(i=0;i<500;++i)
	{
		dotx=i+random(w-1);
		doty=1+random(h-1);
		color=random(maxcolor);
		setcolor(color);
		//putpixel(dotx,doty,color);
		rectangle(dotx,doty,dotx+500,doty+3);
	}
	srand(seed);
	delay(5);
	setcolor(WHITE);
	setlinestyle(0,0,3);
	line(610,0,610,480);
	line(590,0,590,400);
	line(570,0,570,300);
	line(550,0,550,250);
	line(530,0,530,200);
	 for(i=0;i<2;i++)
	{
		 bt[i].x=440+20*i;
		 bt[i].x1=bt[i].x+160;
		 bt[i].y=280+70*i;
		 bt[i].y1=bt[i].y+40;
		 bt[i].name=s[i];
		 dr_button(&bt[i],WHITE,40,2);
	}
	for(i=0;i<6;i++)
	{
		dis_hz(30,30+50*i,ss[i],3,0,LIGHTMAGENTA);
	}
	cursor(mousex,mousey);
    while(1)
    {
	    newmouse(&mousex,&mousey,&mousekey);
	    if(mousex>bt[0].x&&mousex<bt[0].x1&&mousey>bt[0].y&&mousey<bt[0].y1&&flag==1)
	    {
			cursor(mousex,mousey);
			bt[0].state=HIGHLIGHT;
			dr_LPbutton(&bt[0]);
		     dis_hz(bt[0].x+3,bt[0].y+3,bt[0].name,2,40,CYAN);
			SOUND(100);
			delay(30);
			NOSOUND();
			flag=0;
			cursor(mousex,mousey);
		}
		if(mousex>bt[1].x&&mousex<bt[1].x1&&mousey>bt[1].y&&mousey<bt[1].y1&&flag==1)
	    {
		     cursor(mousex,mousey);
		     bt[1].state=HIGHLIGHT;
			dr_LPbutton(&bt[1]);
		    dis_hz(bt[1].x+3,bt[1].y+3,bt[1].name,2,40,CYAN);
		     SOUND(100);
			delay(30);
			NOSOUND();
		   flag=0;
		   cursor(mousex,mousey);
		}
		

		if(!(mousex>bt[0].x && mousex<bt[0].x1 && mousey>bt[0].y && mousey<bt[0].y1)
			&&!(mousex>bt[1].x && mousex<bt[1].x1 &&mousey>bt[1].y && mousey<bt[1].y1))
		{
			if(0==flag)
			{

				flag=1;
				bt[0].state= NORMALSTATE;
                    bt[1].state= NORMALSTATE;
				bt[2].state= NORMALSTATE;
				cursor(mousex,mousey);
                    dr_LPbutton(&bt[0]);
				dr_LPbutton(&bt[1]);
				dr_LPbutton(&bt[2]);
				dis_hz(bt[0].x+3,bt[0].y+3,bt[0].name,2,40,WHITE);
				dis_hz(bt[1].x+3,bt[1].y+3,bt[1].name,2,40,WHITE);
				dis_hz(bt[2].x+3,bt[2].y+3,bt[2].name,2,40,WHITE);
				cursor(mousex,mousey);
			}
	    }
	     if(1==mousekey &&mousex>bt[0].x && mousex<bt[0].x1 && mousey>bt[0].y && mousey<bt[0].y1)
		{
			*choice=1;//for search
			break;
		}
	     if(1==mousekey && mousex>bt[1].x && mousex<bt[1].x1 && mousey>bt[1].y && mousey<bt[1].y1)
	    {
			*choice=0;//for choose
			break;
		}
	}
}