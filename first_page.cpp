#include"all.h"
#include"stru.h"
#include"public.h"
void first_page()
{
	int i,x4,y4,x5,y5,x6,y6,x7,y7,
	temp_x1,temp_y1,
	temp_x3,temp_y3;
	int pag[32];
	int pag1[32];
	temp_x1=105,temp_y1=235,
	temp_x3=100,temp_y3=300;
     void  *buffer;
     unsigned int size;
     CAR cp;
     InitGra(480);
     cp.x=temp_x3;cp.y=temp_y3,cp.angle=0;
     draw_car(&cp);
	size=imagesize(temp_x3-30,temp_y3-60,temp_x3+30,temp_y3+60);
     buffer=malloc(size);
     getimage(temp_x3-30,temp_y3-40,temp_x3+30,temp_y3+40,buffer);
     setcolor(YELLOW);//»­½ø¶ÈÌõ
     setlinestyle(0,0,3);
     rectangle(100,230,480,250);
     for(i=0;i<370;i++)
    {
		setcolor(YELLOW);
	     line(temp_x1,temp_y1,temp_x1,temp_y1+10);
	     outtextxy(100,210,"loading...");
	     putimage((temp_x3-30)+i,temp_y3-40,buffer,COPY_PUT);
	     delay(4);
	     temp_x1+=1;
    }
	outtextxy(490,235,"100%");
	free(buffer);
	getch();
}
	