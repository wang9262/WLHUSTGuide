#include"all.h"
#include"stru.h"
#include"public.h"
#include"hong.h"
void choose(int star_fini_flag,int *point1)
{
	POINT point[SPOTNUM];
	int mousex=600,mousey=345,mousekey=0;
	int flag=0;
	int i;
	char *s[5]={"学生公寓","食堂","教学楼","校门","其他"};//dorm,canteen,jxbuild,sch_door,other
	initmouse(492,637,55,345);
	cursor(mousex,mousey);
	while(1)
	{
		newmouse(&mousex,&mousey,&mousekey);	
		if(mousex>495&&mousex<635&&mousey>60&&mousey<87&&flag==1)
		{
			cursor(mousex,mousey);
			dis_hz(495,60,s[0],1,27,LIGHTRED);
			flag=0;
			cursor(mousex,mousey);
		}
		if(mousex>495&&mousex<635&&mousey>90&&mousey<117&&flag==1)
		{
			cursor(mousex,mousey);
			dis_hz(495,90,s[1],1,27,LIGHTRED);
			flag=0;
			cursor(mousex,mousey);
		}
		if(mousex>495&&mousex<635&&mousey>120&&mousey<147&&flag==1)
		{
			cursor(mousex,mousey);
			dis_hz(495,120,s[2],1,27,LIGHTRED);
			flag=0;
			cursor(mousex,mousey);
		}
		if(mousex>495&&mousex<635&&mousey>150&&mousey<177&&flag==1)
		{
			cursor(mousex,mousey);
			dis_hz(495,150,s[3],1,27,LIGHTRED);
			flag=0;
			cursor(mousex,mousey);
		}
		if(mousex>495&&mousex<635&&mousey>180&&mousey<207&&flag==1)
		{
			cursor(mousex,mousey);
			dis_hz(495,180,s[4],1,27,LIGHTRED);
			flag=0;
			cursor(mousex,mousey);
		}
		if(!(mousex>495&&mousex<635&&mousey>60&&mousey<87)&&!(mousex>495&&mousex<635&&mousey>90&&mousey<117)&&
			!(mousex>495&&mousex<635&&mousey>120&&mousey<147)&&!(mousex>495&&mousex<635&&mousey>150&&mousey<177)&&
		!(mousex>495&&mousex<635&&mousey>180&&mousey<207))
		{
			flag=1;
			for(i=0;i<5;i++)
			{
			  dis_hz(495,60+30*i,s[i],1,27,WHITE);
			}
		}
		if(mousex>495&&mousex<635&&mousey>60&&mousey<87&&mousekey==1)
		{
			delay(200);
			dorm(point,star_fini_flag,point1);
			break;
		}
		if(mousex>495&&mousex<635&&mousey>90&&mousey<117&&mousekey==1)
		{
			delay(200);
			canteen(point,star_fini_flag,point1);
			break;
		}
		if(mousex>495&&mousex<635&&mousey>120&&mousey<147&&mousekey==1)
		{
			delay(200);
			jxbuild(point,star_fini_flag,point1);
			break;
		}
		if(mousex>495&&mousex<635&&mousey>150&&mousey<177&&mousekey==1)
		{
			delay(200);
			sch_door(point,star_fini_flag,point1);
			break;
		}
		if(mousex>495&&mousex<635&&mousey>180&&mousey<207&&mousekey==1)
		{
			delay(200);
			other(point,star_fini_flag,point1);
			break;
		}
	}
}