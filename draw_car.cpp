#include"all.h"
#include"stru.h"
 /*================旋转函数，可以用来控制小车的旋转 this can draw a circle to explain=============*/
void shift(double angle1, int *body, int *win, int *head,  int *rear, int *L_h_light,int *L_r_light, int *R_h_light,  int *R_r_light,int x, int y)
{
	 int i,temp;
	 float a, b;
	 a=cos(angle1*PI/180);// cos law
	 b=-sin(angle1*PI/180);
	 for(i=0;i<10;i+=2)
	 {
		temp=body[i];
		body[i]=a*(body[i]-x)-b*(body[i+1]-y)+x;
		body[i+1]=b*(temp-x)+a*(body[i+1]-y)+y;
	 } 
	 for(i=0;i<10;i+=2)
	 {
		temp=win[i];
		win[i]=a*(win[i]-x)-b*(win[i+1]-y)+x;
		win[i+1]=b*(temp-x)+a*(win[i+1]-y)+y;
	 }
	 for(i=0;i<18;i+=2)
	 {
		temp=head[i];
		head[i]=a*(head[i]-x)-b*(head[i+1]-y)+x;
		head[i+1]=b*(temp-x)+a*(head[i+1]-y)+y;
	 }
	 for(i=0;i<18;i+=2)
	 {
		temp=rear[i];
		rear[i]=a*(rear[i]-x)-b*(rear[i+1]-y)+x;
		rear[i+1]=b*(temp-x)+a*(rear[i+1]-y)+y;
	 }
	 for(i=0;i<8;i+=2)
	 {   
		temp=L_h_light[i];
		L_h_light[i]=a*(L_h_light[i]-x)-b*(L_h_light[i+1]-y)+x;
		L_h_light[i+1]=b*(temp-x)+a*(L_h_light[i+1]-y)+y;
	 }
	 for(i=0;i<8;i+=2)
	 {   
		temp=R_h_light[i];
		R_h_light[i]=a*(R_h_light[i]-x)-b*(R_h_light[i+1]-y)+x;
		R_h_light[i+1]=b*(temp-x)+a*(R_h_light[i+1]-y)+y;
	 }
	 for(i=0;i<8;i+=2)
	 {   
		temp=L_r_light[i];
		L_r_light[i]=a*(L_r_light[i]-x)-b*(L_r_light[i+1]-y)+x;
		L_r_light[i+1]=b*(temp-x)+a*(L_r_light[i+1]-y)+y;
	 }
	 for(i=0;i<8;i+=2)
	 {   
		temp=R_r_light[i];
		R_r_light[i]=a*(R_r_light[i]-x)-b*(R_r_light[i+1]-y)+x;
		R_r_light[i+1]=b*(temp-x)+a*(R_r_light[i+1]-y)+y;
	 }
}
/*================此模块为画小车的模块，以小车中心为参照点,x y is center of car================*/
void draw_car(CAR *cp)
{
	int x=cp->x;
	int y=cp->y;//x,y为小车中心
	double angle1=cp->angle;
	float sf=0.8;
     int body[10]={x-20*sf,y+12*sf,x+20*sf,y+12*sf,x+20*sf,y-12*sf,x-20*sf,y-12*sf,x-20*sf,y+12*sf};
     int win[10]={x-12*sf,y+7*sf,x+12*sf,y+7*sf,x+12*sf,y-7*sf,x-12*sf,y-7*sf,x-12*sf,y+7*sf};
     int head[18]={x+20*sf,y+12*sf,x+23*sf,y+12*sf,x+23*sf,y+7*sf,x+28*sf,y+7*sf,x+28*sf,y-7*sf,x+23*sf,y-7*sf,x+23*sf,y-12*sf,x+20*sf,y-12*sf,x+20*sf,y+12*sf};
     int rear[18]={x-20*sf,y-12*sf,x-20*sf,y+12*sf,x-22*sf,y+12*sf,x-22*sf,y+9*sf,x-25*sf,y+9*sf,x-25*sf,y-9*sf,x-22*sf,y-9*sf,x-22*sf,y-12*sf,x-20*sf,y-12*sf};
     int L_h_light[8]={x+23*sf,y+12*sf,x+23*sf,y+7*sf,x+28*sf,y+7*sf,x+23*sf,y+12*sf};
     int R_h_light[8]={x+23*sf,y-12*sf,x+23*sf,y-7*sf,x+28*sf,y-7*sf,x+23*sf,y-12*sf};
     int L_r_light[8]={x-22*sf,y+12*sf,x-22*sf,y+9*sf,x-25*sf,y+9*sf,x-22*sf,y+12*sf};
     int R_r_light[8]={x-22*sf,y-12*sf,x-22*sf,y-9*sf,x-25*sf,y-9*sf,x-22*sf,y-12*sf};
		
	shift(angle1, body, win, head,  rear, L_h_light,L_r_light, R_h_light, R_r_light,x,y);
	setcolor(YELLOW);
	setlinestyle(0,0,1);
	setfillstyle(1,CYAN);
	fillpoly(5,body);
	
	setfillstyle(1,LIGHTGRAY);
	fillpoly(5,win);
	
	setfillstyle(1,LIGHTCYAN);
	fillpoly(9,head);
	
	setfillstyle(1,LIGHTCYAN);
	fillpoly(9,rear);
	
	setfillstyle(1,YELLOW);
	fillpoly(4,L_h_light);
	fillpoly(4,R_h_light);
	fillpoly(4,L_r_light);
	fillpoly(4,R_r_light);
	
	setcolor(YELLOW);
     setlinestyle(0,0,1);
	
	line(body[0],body[1],win[0],win[1]);
     line(body[2],body[3],win[2],win[3]);
	line(body[4],body[5],win[4],win[5]);
	line(body[6],body[7],win[6],win[7]);
	
	line((win[0]+win[2])/2,(win[1]+win[3])/2,(body[0]+body[2])/2,(body[1]+body[3])/2);
     line((win[4]+win[6])/2,(win[5]+win[7])/2,(body[4]+body[6])/2,(body[5]+body[7])/2);

}

