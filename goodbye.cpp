#include"all.h"
#include"public.h"
void goodbye()
{
	int x=200,y=-20;
	int x1=-40,x2=660;
	int i;     	
	InitGra(480);
	cleardevice();
	delay(150);
	setbkcolor(BLACK);
	settextstyle(1,0,6);
	/*Goodbye!从上往下运动后静止，getch后 退出*/
	for(i=0;i<20;i++)
	{
	   y+=10;
           x1+=12;
           x2-=15;
	   setcolor(YELLOW);  
  	   outtextxy(x,y,"Goodbye!");
           dis_hz(x2,300,"再见",2,30,BLUE);
           dis_hz(x1,300,"谢谢使用",2,30,BLUE);   
           delay(50);
  	   setfillstyle(1,BLACK);
	   bar(x,y,639,439);
           bar(x1,y,639,439);
         }
	outtextxy(x,y,"Goodbye!");
        dis_hz(x2,300,"再见",2,30,BLUE);
        dis_hz(x1,300,"谢谢使用！",2,30,BLUE);
	getch();
	closegraph();
}
