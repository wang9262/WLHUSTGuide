#include"all.h"
#include"public.h"
#include"hong.h"
void guidance_end(int x, int y)        //导航结束画面  x,y为窗口的位置
{

   int first=1;
   int ch;
   int ch1=0;
   int flag_click_break=1;
   setcolor(GREEN);
   setlinestyle(0,0,1);
   setfillstyle(1,GREEN);
   setcolor(WHITE);
   rectangle(x,y,x+295,y+150);
   bar(x,y,x+295,y+150);
	
   setfillstyle(1,WHITE);   //画弹出窗口上方的边框
   bar(x,y,x+295,y+30);
   setcolor(WHITE);
   rectangle(x,y,x+295,y+30);
	
   dis_hz(x+2,y+3,"是否现在退出？",1,25,MAGENTA);
   dis_hz(x+8,y+45,"本次导航结束，谢谢使用！",1,25,YELLOW);
  
   setfillstyle(1,LIGHTGRAY);
   setlinestyle(0,0,1);
   
   bar(x+40,y+95,x+120,y+128);
   setcolor(WHITE);
   line(x+40,y+95,x+40,y+128);
   line(x+40,y+95,x+120,y+95);
   setcolor(BLUE);
   line(x+120,y+128,x+120,y+95);
   line(x+120,y+128,x+40,y+128);
   
   dis_hz(x+46,y+103,"退出",0,20,BLUE);
   settextstyle(1,0,1);
   outtextxy(x+86,y+100,"(\\Y)");
   
   
   bar(x+170,y+95,x+250,y+128);
   setcolor(WHITE);
   line(x+170,y+95,x+170,y+128);
   line(x+170,y+95,x+250,y+95);
   setcolor(BLUE);	
   line(x+250,y+128,x+250,y+95);
   line(x+250,y+128,x+170,y+128);  

   dis_hz(x+176,y+103,"取消",0,20,BLUE);
   settextstyle(1,0,1);
   outtextxy(x+216,y+100,"(\\N)");
      ch1=bioskey(0); 
   while(1==flag_click_break)
   {
      if(0==first)
      {
         ch=bioskey(0);
      }
      if(1==first)
      {
         ch=ch1;
         first=0;
      }
      switch(ch)
      {
         case  Y:
         {
            closegraph();
            goodbye();
            exit(0);
         }
         case N:
         flag_click_break=0;
         break;
         default:  
                    break;   
            }
         
      }
  
}


