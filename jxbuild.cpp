#include"all.h"
#include"stru.h"
#include"public.h"
#include"hong.h"
void jxbuild(POINT point[SPOTNUM],int star_fini_flag,int *point1)
{
	int mouse_x=320,mouse_y=175,mouse_key=0;
	int i,flag=0;
	init_point(point);
     draw_bar(492,55,637,345,LIGHTGRAY);
	initmouse(492,637,55,159);
	cursor(mouse_x,mouse_y);
	while(1)
	{
		newmouse(&mouse_x,&mouse_y,&mouse_key);
		if(mouse_x>495&&mouse_x<635&&mouse_y>60&&mouse_y<78&&flag==1)
		{
			cursor(mouse_x,mouse_y);
			dis_hz(495,60,point[10].name,0,20,LIGHTRED);
			remark(point[10].remarks);
			flag=0;
			cursor(mouse_x,mouse_y);
		}
          if(mouse_x>495&&mouse_x<635&&mouse_y>80&&mouse_y<98&&flag==1)
		{
			cursor(mouse_x,mouse_y);
			remark(point[11].remarks);
			dis_hz(495,80,point[11].name,0,20,LIGHTRED);
			flag=0;
			cursor(mouse_x,mouse_y);
		}
		if(mouse_x>495&&mouse_x<635&&mouse_y>100&&mouse_y<118&&flag==1)
		{
			cursor(mouse_x,mouse_y);
			dis_hz(495,100,point[12].name,0,20,LIGHTRED);
			remark(point[12].remarks);
			flag=0;
			cursor(mouse_x,mouse_y);
		}
		if(mouse_x>495&&mouse_x<635&&mouse_y>120&&mouse_y<138&&flag==1)
		{
			cursor(mouse_x,mouse_y);
			remark(point[13].remarks);
			dis_hz(495,120,point[13].name,0,20,LIGHTRED);
			flag=0;
			cursor(mouse_x,mouse_y);
		}
		if(mouse_x>495&&mouse_x<635&&mouse_y>140&&mouse_y<158&&flag==1)
		{
			cursor(mouse_x,mouse_y);
			remark(point[14].remarks);
			dis_hz(495,140,point[14].name,0,20,LIGHTRED);
			flag=0;
			cursor(mouse_x,mouse_y);
		}
		if(!(mouse_x>495&&mouse_x<635&&mouse_y>60&&mouse_y<78)&&!(mouse_x>495&&mouse_x<635&&mouse_y>80&&mouse_y<98)&&
		!(mouse_x>495&&mouse_x<635&&mouse_y>100&&mouse_y<118)&&!(mouse_x>495&&mouse_x<635&&mouse_y>120&&mouse_y<138)&&
		!(mouse_x>495&&mouse_x<635&&mouse_y>140&&mouse_y<158)&&!(mouse_x>=495&&mouse_x<=635&&mouse_y>=160&&mouse_y<=240))
		{
			flag=1;
			for(i=0;i<5;i++)
			  dis_hz(495,60+20*i,point[i+10].name,0,20,WHITE);
			draw_bar1(495,160,634,240,LIGHTGRAY);
		}
		if(mouse_x>495&&mouse_x<635&&mouse_y>60&&mouse_y<78&&mouse_key==1)
		 {
			 cursor(mouse_x,mouse_y);
			 cursor(mouse_x,mouse_y);
			 cursor(mouse_x,mouse_y);
			 *point1=10;
			 remark(point[10].remarks);
               show_sta_fin(point[10].name,star_fini_flag);
			break;
		 }
		 if(mouse_x>495&&mouse_x<635&&mouse_y>80&&mouse_y<98&&mouse_key==1)
		 {
			 cursor(mouse_x,mouse_y);
			 cursor(mouse_x,mouse_y);
			 cursor(mouse_x,mouse_y);
			 *point1=11;
			 remark(point[11].remarks);
               show_sta_fin(point[11].name,star_fini_flag);
			break;
		 }
		 if(mouse_x>495&&mouse_x<635&&mouse_y>100&&mouse_y<118&&mouse_key==1)
		 {
			 cursor(mouse_x,mouse_y);
			 cursor(mouse_x,mouse_y);
			 cursor(mouse_x,mouse_y);
			 *point1=12;
			 remark(point[12].remarks);
               show_sta_fin(point[12].name,star_fini_flag);
			break;
		 }
		 if(mouse_x>495&&mouse_x<635&&mouse_y>120&&mouse_y<138&&mouse_key==1)
		 {
			 cursor(mouse_x,mouse_y);
			 cursor(mouse_x,mouse_y);
			 cursor(mouse_x,mouse_y);
			 *point1=13;
			 remark(point[13].remarks);
               show_sta_fin(point[13].name,star_fini_flag);
			break;
		 }
		 if(mouse_x>495&&mouse_x<635&&mouse_y>140&&mouse_y<158&&mouse_key==1)
		 {
			 cursor(mouse_x,mouse_y);
			 cursor(mouse_x,mouse_y);
			 cursor(mouse_x,mouse_y);
			 *point1=14;
			 remark(point[14].remarks);
               show_sta_fin(point[14].name,star_fini_flag);
			break;
		 }
	}
	
}