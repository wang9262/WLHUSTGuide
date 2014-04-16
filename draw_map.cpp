#include  "all.h"
#include  "stru.h"
void street1(STREET *str1)//横向街道，Horizontal street
{
	int i;
	int x=str1->x,y=str1->y,len=str1->len;
	int street[]={x,y,x+len,y,x+len,y+40,x,y+40,x,y};
	setcolor(LIGHTGRAY);
     setlinestyle(0,0,1);
     setfillstyle(1,LIGHTGRAY);
	fillpoly(5,street);
	setcolor(YELLOW);
	line(x,y+20,x+len,y+20);
	setcolor(WHITE);
	setlinestyle(1,0,1);
	for(i=0;i<2;i++)
		line(x,y+10+20*i,x+len,y+10+20*i);
}
void street2(STREET *str2)//竖直街道,Vertical street
{
	int i;
	int x=str2->x,y=str2->y,len=str2->len;
	int street[]={x,y,x+40,y,x+40,y-len,x,y-len,x,y};
	setcolor(LIGHTGRAY);
	setlinestyle(0,0,1);
	setfillstyle(1,LIGHTGRAY);
	fillpoly(5,street);
	setlinestyle(0,0,1);
	setcolor(YELLOW);
	line(x+20,y,x+20,y-len);
	setcolor(WHITE);
	setlinestyle(1,0,1);
	for(i=0;i<2;i++)
		line(x+10+20*i,y,x+10+20*i,y-len);
}
void street3(STREET *str3,int angle)//任意角度横向街道,，angle为与斜向与水平线的角度，len为横向长度,右下角(x,y), right bottom(x,y) northeast
{
	int i;
	double a=0.0;
	a=tan(angle*PI/180.0);
	int x=str3->x,y=str3->y,len=str3->len;
	int street_point[]={x,y,x+46,y,x+46+len,y-len*a,x+len,y-len*a,x,y};

	setcolor(LIGHTGRAY);
	setlinestyle(0,0,1);
	setfillstyle(1,LIGHTGRAY);
	fillpoly(5,street_point);
	setlinestyle(0,0,1);
	setcolor(YELLOW);
	line(x+23,y,x+23+len,y-len*a);
	setlinestyle(1,0,1);
	setcolor(WHITE);
     for(i=0;i<2;i++)
		line(x+12+23*i,y,x+12+len+23*i,y-len*a);
}
void street4(STREET *str4,int angle)//任意角度横向街道,，angle为斜向与水平的角度，len为横向长度,左下角（x,y） left bottom ,northwest
{
	int i;
	double b=0.0;
	b=tan(angle*PI/180.0);
	int x=str4->x,y=str4->y,len=str4->len;
	int street_point[]={x,y,x-46,y,x-46-len,y-len*b,x-len,y-len*b,x,y};

	setcolor(LIGHTGRAY);
	setlinestyle(0,0,1);
	setfillstyle(1,LIGHTGRAY);
	fillpoly(5,street_point);
	setlinestyle(0,0,1);
	setcolor(YELLOW);
	line(x-23,y,x-23-len,y-len*b);
	setlinestyle(1,0,1);
	setcolor(WHITE);
	for(i=0;i<2;i++)
		line(x-12-23*i,y,x-12-len-23*i,y-len*b);
}
void compass()                            //为画指南针的函数
{
     int n[]={60,10,45,40,55,40,55,90,65,90,65,40,75,40,60,10};
	setcolor(LIGHTBLUE);
     setlinestyle(0,0,1);
	setfillstyle(1,LIGHTBLUE);
	fillpoly(8,n);
	ellipse(60,50,0,360,40,40);
	setcolor(RED);
	settextstyle(0,0,2);
	outtextxy(53,25,"N");
}   
/* 画东九，西十二，东十二函数，可以根据需要调节大小----sf*/
void ninebuilding(LITTLE *sp)
{
	int i;
	int x=sp->x,y=sp->y;
     double sf=sp->sf;
	int ninebuilding1[40];
	ninebuilding1[0]=x;ninebuilding1[1]=y;ninebuilding1[2]=x+43*sf;ninebuilding1[3]=y+0*sf;ninebuilding1[4]=x+35*sf;ninebuilding1[5]=y+6*sf;ninebuilding1[6]=x+24*sf;
	ninebuilding1[7]=y+6*sf;ninebuilding1[8]=x-13*sf;ninebuilding1[9]=y+36*sf;ninebuilding1[10]=x+1*sf;ninebuilding1[11]=y+36*sf;ninebuilding1[12]=x-8*sf;
	ninebuilding1[13]=y+42*sf;ninebuilding1[14]=x-55*sf;ninebuilding1[15]=y+42*sf;ninebuilding1[16]=x-48*sf;ninebuilding1[17]=y+36*sf;ninebuilding1[18]=x-27*sf;
	ninebuilding1[19]=y+36*sf;ninebuilding1[20]=x-20*sf;ninebuilding1[21]=y+30*sf;ninebuilding1[22]=x-40*sf;ninebuilding1[23]=y+30*sf;ninebuilding1[24]=x-32*sf;
	ninebuilding1[25]=y+24*sf;ninebuilding1[26]=x-12*sf;ninebuilding1[27]=y+24*sf;ninebuilding1[28]=x-4*sf;ninebuilding1[29]=y+18*sf;ninebuilding1[30]=x-24*sf;
	ninebuilding1[31]=y+18*sf;ninebuilding1[32]=x-16*sf;ninebuilding1[33]=y+12*sf;ninebuilding1[34]=x+3*sf;ninebuilding1[35]=y+12*sf;ninebuilding1[36]=x+11*sf;
	ninebuilding1[37]=y+6*sf;ninebuilding1[38]=x-8*sf;ninebuilding1[39]=y+6*sf;
	
	setcolor(BLUE);
	setlinestyle(0,0,2);
	drawpoly(20,ninebuilding1);
	setfillstyle(1,8);
	fillpoly(20,ninebuilding1);
	
	int ninebuilding2[8];
	ninebuilding2[0]=x-55*sf;ninebuilding2[1]=y+42*sf;ninebuilding2[2]=x-8*sf;ninebuilding2[3]=y+42*sf;
	ninebuilding2[4]=x-8*sf;ninebuilding2[5]=y+59*sf;ninebuilding2[6]=x-55*sf;ninebuilding2[7]=y+59*sf;
	
	setcolor(BLUE);
	setlinestyle(0,0,2);
	drawpoly(4,ninebuilding2);
	setfillstyle(1,WHITE);
	fillpoly(4,ninebuilding2);
	
	int ninebuilding3[8];
	ninebuilding3[0]=x-8*sf;ninebuilding3[1]=y+42*sf;ninebuilding3[2]=x+1*sf;ninebuilding3[3]=y+36*sf;
	ninebuilding3[4]=x+1*sf;ninebuilding3[5]=y+52*sf;ninebuilding3[6]=x-8*sf;ninebuilding3[7]=y+59*sf;
	
	setcolor(BLUE);
	setlinestyle(0,0,2);
	drawpoly(4,ninebuilding3);
	setfillstyle(1,8);
	fillpoly(4,ninebuilding3);
	
	
	int ninebuilding4[8];
	ninebuilding4[0]=x+35*sf;ninebuilding4[1]=y+6*sf;ninebuilding4[2]=x+43*sf;ninebuilding4[3]=y+0*sf;
	ninebuilding4[4]=x+43*sf;ninebuilding4[5]=y+17*sf;ninebuilding4[6]=x+35*sf;ninebuilding4[7]=y+23*sf;
	
	setcolor(BLUE);
	setlinestyle(0,0,2);
	drawpoly(4,ninebuilding4);
	setfillstyle(1,8);
	fillpoly(4,ninebuilding4);
	
	int ninebuilding5[10];
	ninebuilding5[0]=x-13*sf;ninebuilding5[1]=y+36*sf;ninebuilding5[2]=x+24*sf;ninebuilding5[3]=y+6*sf;
	ninebuilding5[4]=x+24*sf;ninebuilding5[5]=y+23*sf;ninebuilding5[6]=x+1*sf;ninebuilding5[7]=y+42*sf;
	ninebuilding5[8]=x+1*sf;ninebuilding5[9]=y+36*sf;

	setcolor(BLUE);
	setlinestyle(0,0,2);
	drawpoly(5,ninebuilding5);
	setfillstyle(1,WHITE);
	fillpoly(5,ninebuilding5);

	setcolor(BLUE);
	line(x-8*sf,y+6*sf,x-8*sf,y+12*sf);
	line(x-24*sf,y+18*sf,x-24*sf,y+24*sf);
	line(x-40*sf,y+30*sf,x-40*sf,y+36*sf);
	line(x+24*sf,y+23*sf,x+35*sf,y+23*sf);
	setcolor(8);
	line(x-1*sf,y+31*sf,x-1*sf,y+35*sf);
     line(x+8*sf,y+23*sf,x+8*sf,y+33*sf);
     line(x+18*sf,y+14*sf,x+18*sf,y+25*sf);
	line(x+30*sf,y+10*sf,x+30*sf,y+21*sf);
	for(i=0;i<6;i++)
	{
		setcolor(8);
		line(x-47*sf,y+44*sf,x-47*sf,y+57*sf);

		x+=6*sf;
	}	
}

/* 画树函数，可以根据需要调节大小----sf*/
void tree(LITTLE *ptp)
{
	int x=ptp->x,y=ptp->y;
	double sf=ptp->sf;
	int tree1[18];
	int tree[34];
	tree1[0]=x;tree1[1]=y;
	tree1[2]=x+3*sf;tree1[3]=y+20*sf;tree1[4]=x+9*sf;tree1[5]=y+20*sf;tree1[6]=x+13*sf;tree1[7]=y+0*sf;tree1[8]=x+10*sf;tree1[9]=y+3*sf;
	tree1[10]=x+8*sf;tree1[11]=y-1*sf;tree1[12]=x+7*sf;tree1[13]=y+3*sf;tree1[14]=x+4*sf;tree1[15]=y-1*sf;tree1[16]=x+4*sf;tree1[17]=y+3*sf;
	setcolor(YELLOW);
	setlinestyle(0,0,1);
	drawpoly(9,tree1);
	setfillstyle(1,BROWN);
	fillpoly(9,tree1);
	
	tree[0]=x;tree[1]=y;tree[2]=x+4*sf;tree[3]=y+3*sf;tree[4]=x+4*sf;tree[5]=y-1*sf;tree[6]=x+7*sf;tree[7]=y+3*sf;
	tree[8]=x+8*sf;tree[9]=y-1*sf;tree[10]=x+10*sf;tree[11]=y+3*sf;tree[12]=x+13*sf;tree[13]=y+0*sf;tree[14]=x+10*sf;tree[15]=y+13*sf;
	tree[16]=x+17*sf;tree[17]=y+12*sf;tree[18]=x+20*sf;tree[19]=y-3*sf;tree[20]=x+15*sf;tree[21]=y-20*sf;tree[22]=x+8*sf;tree[23]=y-22*sf;
	tree[24]=x-2*sf;tree[25]=y-20*sf;tree[26]=x-6*sf;tree[27]=y-9*sf;tree[28]=x-7*sf;tree[29]=y+2*sf;tree[30]=x-3*sf;tree[31]=y+10*sf;
	tree[32]=x+2*sf;tree[33]=y+12*sf;
     setcolor(YELLOW);
	setlinestyle(0,0,1);
	drawpoly(17,tree);
	setfillstyle(1,GREEN);
	fillpoly(17,tree);
}
/*画女人函数，可以缩放*/
void people_w(LITTLE *wppp)
{
	int i;
	int x=wppp->x,y=wppp->y;
     double sf=wppp->sf;
     setcolor(BLUE);
     setlinestyle(0,0,2);
     ellipse(x,y,0,360,9*sf,9*sf);
     int people_w[20];
     people_w[0]=x-2*sf;people_w[1]=y+9*sf;people_w[2]=x+2*sf;people_w[3]=y+9*sf;
     people_w[4]=x+5*sf;people_w[5]=y+15*sf;people_w[6]=x+10*sf;people_w[7]=y+20*sf;	
     people_w[8]=x+8*sf;people_w[9]=y+22*sf;people_w[10]=x+10*sf;people_w[11]=y+26*sf;	
     people_w[12]=x-9*sf;people_w[13]=y+26*sf;people_w[14]=x-7*sf;people_w[15]=y+22*sf;	
     people_w[16]=x-9*sf;people_w[17]=y+20*sf;people_w[18]=x-5*sf;people_w[19]=y+16*sf;
     int people_w1[6];
     people_w1[0]=x+7*sf;people_w1[1]=y+5*sf;people_w1[2]=x+9*sf;people_w1[3]=y+13*sf;
     people_w1[4]=x+6*sf;people_w1[5]=y+13*sf;
     int people_w2[6];
     people_w2[0]=x+8*sf;people_w2[1]=y+3*sf;people_w2[2]=x+15*sf;people_w2[3]=y+9*sf;
     people_w2[4]=x+12*sf;people_w2[5]=y+12*sf;	

     setcolor(BLUE); 
     setlinestyle(0,0,1);
     drawpoly(10,people_w);
     drawpoly(3,people_w1);
     drawpoly(3,people_w2);

     line(x-7*sf,y-5*sf,x+4*sf,y+0*sf);
     line(x+4*sf,y+0*sf,x+7*sf,y+6*sf);
 
     setfillstyle(1,BLUE);
     floodfill(x+0*sf,y-5*sf,BLUE);
  
     setfillstyle(1,LIGHTMAGENTA);
     fillpoly(10,people_w);
 
     setfillstyle(1,BLUE);
     fillpoly(3,people_w1);
     fillpoly(3,people_w2);
 
     line(x-5*sf,y+16*sf,x-1*sf,y+12*sf);
     line(x-7*sf,y+22*sf,x+1*sf,y+14*sf);
     line(x+5*sf,y+15*sf,x+8*sf,y+22*sf);
     for(i=0;i<2;i++)
    { 
		setfillstyle(1,YELLOW);
	     bar(x-7*sf,y+26*sf,x-1*sf,y+28*sf);
	     rectangle(x-7*sf,y+26*sf,x-1*sf,y+28*sf);
	     x+=9*sf;
    }	
}
/*画男人函数，可以缩放*/
void people_m(LITTLE *mppp)
{
	int i;
     int x=mppp->x,y=mppp->y;
     double sf=mppp->sf;
     setcolor(BLUE);
     setlinestyle(0,0,2);
     ellipse(x,y,0,360,9*sf,9*sf);
     int people_m[24];
     people_m[0]=x-2*sf;people_m[1]=y+9*sf;people_m[2]=x+2*sf;people_m[3]=y+9*sf;
     people_m[4]=x+6*sf;people_m[5]=y+13*sf;people_m[6]=x+6*sf;people_m[7]=y+15*sf;	
     people_m[8]=x+10*sf;people_m[9]=y+19*sf;people_m[10]=x+8*sf;people_m[11]=y+21*sf;	
     people_m[12]=x+6*sf;people_m[13]=y+19*sf;people_m[14]=x-5*sf;people_m[15]=y+19*sf;	
     people_m[16]=x-7*sf;people_m[17]=y+21*sf;people_m[18]=x-9*sf;people_m[19]=y+19*sf;
     people_m[20]=x-6*sf;people_m[21]=y+16*sf;people_m[22]=x-6*sf;people_m[23]=y+13*sf;
 
     setcolor(BLUE); 
     setlinestyle(0,0,1);
     drawpoly(12,people_m);	
     setfillstyle(1,GREEN);
     fillpoly(12,people_m);
 
	line(x-7*sf,y-5*sf,x+4*sf,y+0*sf);
     line(x+4*sf,y+0*sf,x+6*sf,y+7*sf);

     setfillstyle(1,GREEN);
     fillpoly(12,people_m);
 
     setcolor(BLUE);
     line(x-2*sf,y+12*sf,x-6*sf,y+16*sf);
     line(x+1*sf,y+13*sf,x-5*sf,y+19*sf);
	line(x+6*sf,y+15*sf,x+6*sf,y+19*sf);
 
     setfillstyle(1,BLUE);
     floodfill(x+0*sf,y-5*sf,BLUE);
 
     for(i=0;i<2;i++)
    { 
	     setfillstyle(1,YELLOW);
	     bar(x-5*sf,y+19*sf,x-1*sf,y+26*sf);
          rectangle(x-5*sf,y+19*sf,x-1*sf,y+26*sf);
	     x+=6*sf;
     }	
}

/*画小校门函数*/
void small_door(LITTLE  *dp)
{
	int i;
	int x=dp->x,y=dp->y;
	int temp_x=x;
	double sf=dp->sf;
	int small_door1[8];
	small_door1[0]=x;small_door1[1]=y;small_door1[2]=x+28*sf;small_door1[3]=y+0*sf;
	small_door1[4]=x+32*sf;small_door1[5]=y+4*sf;small_door1[6]=x-4*sf;small_door1[7]=y+4*sf;
	int small_door2[8];
	small_door2[0]=x-8*sf;small_door2[1]=y+7*sf;small_door2[2]=x+37*sf;small_door2[3]=y+7*sf;
	small_door2[4]=x+41*sf;small_door2[5]=y+11*sf;small_door2[6]=x-12*sf;small_door2[7]=y+11*sf;
	
	setcolor(BLUE);
	setlinestyle(0,0,2);
	drawpoly(4,small_door1);
	drawpoly(4,small_door2);
	setfillstyle(1,RED);
	fillpoly(4,small_door2);
	fillpoly(4,small_door1);
	
	setfillstyle(1,BROWN);
	bar(x+0*sf,y+4*sf,x+28*sf,y+7*sf);
	rectangle(x+0*sf,y+4*sf,x+28*sf,y+7*sf);
	
	for (i=0;i<2;i++)
	{
		setcolor(BLUE);
		setfillstyle(1,BROWN);
	     bar(x-6*sf,y+11*sf,x-3*sf,y+25*sf);
	     rectangle(x-6*sf,y+11*sf,x-3*sf,y+25*sf);
		x+=5*sf;
	}
	for (i=0;i<2;i++)
	{
		setcolor(BLUE);
		setfillstyle(1,BROWN);
	     bar(temp_x+27*sf,y+11*sf,temp_x+30*sf,y+25*sf);
	     rectangle(temp_x+27*sf,y+11*sf,temp_x+30*sf,y+25*sf);
		temp_x+=5*sf;
	}
}
/*画操场*/
void playground(LITTLE  *gp)
{
	int i,j;
	int x=gp->x,y=gp->y;
	int temp_x1=x;
	double sf=gp->sf;
     	    setcolor(BLUE);
              setlinestyle(0,0,1);
	         setfillstyle(1,LIGHTRED);
	         bar(x-20*sf,y-20*sf,x+20*sf,y+56*sf);
	         rectangle(x-20*sf,y-20*sf,x+20*sf,y+56*sf);
	for(i=0;i<6;i++)
	{
         ellipse(x,y,0,180,(20-i*2)*sf,(20-i*2)*sf);
	}
	setfillstyle(1,BLUE);
	floodfill(x-19*sf,y-19*sf,BLUE);
	floodfill(x+19*sf,y-19*sf,BLUE);
	for(i=0;i<6;i++)
	{
          ellipse(x+0*sf,y+36*sf,180,360,(20-i*2)*sf,(20-i*2)*sf);
	}
	floodfill(x-19*sf,y+55*sf,BLUE);
	floodfill(x+19*sf,y+55*sf,BLUE);
	for(i=0;i<2;i++)
	{
		for(j=0;j<6;j++)
		{
			line(x-20*sf,y+0*sf,x-20*sf,y+36*sf);
			x+=2*sf;
		}
		x+=18*sf;
	}
	setfillstyle(1,GREEN);
	bar(temp_x1-10*sf,y+0*sf,temp_x1+10*sf,y+36*sf);
	rectangle(temp_x1-10*sf,y+0*sf,temp_x1+10*sf,y+36*sf);
	ellipse(temp_x1+0*sf,y+18*sf,0,360,2*sf,2*sf);
	line(temp_x1-10*sf,y+18*sf,temp_x1+10*sf,y+18*sf);
	for(i=0;i<2;i++)
	{
		bar(temp_x1-5*sf,y+0*sf,temp_x1+5*sf,y+4*sf);
	     rectangle(temp_x1-5*sf,y+0*sf,temp_x1+5*sf,y+4*sf);
	     y+=32*sf;
	}
}
/*画湖*/
void lake(LITTLE *lap)
{
	int x=lap->x,y=lap->y;
     double sf=lap->sf;
	int lake[10];
	lake[0]=x;lake[1]=y;lake[2]=x+13*sf;lake[3]=y+3*sf;lake[4]=x+22*sf;lake[5]=y+35*sf;
	lake[6]=x-4*sf;lake[7]=y+37*sf;lake[8]=x-9*sf;lake[9]=y+23*sf;
	
	setcolor(BLUE);
	setlinestyle(0,0,2);
	drawpoly(5,lake);
	setfillstyle(1,LIGHTBLUE);
	fillpoly(5,lake);
}
/*画南一，，，图书馆等*/	
void bigbuilding(LITTLE *bip)
{
	int x=bip->x,y=bip->y;
     double sf=bip->sf;
     int front[]={x-40*sf,y,x+40*sf,y,x+40*sf,y-20*sf,x-40*sf,y-20*sf,x-40*sf,y};
     int up[]={x-40*sf,y-20*sf,x+40*sf,y-20*sf,x+55*sf,y-35*sf,x-25*sf,y-35*sf,x-40*sf,y-20*sf};
     int side[]={x+40*sf,y,x+55*sf,y-15*sf,x+55*sf,y-35*sf,x+40*sf,y-20*sf,x+40*sf,y};
     setcolor(LIGHTGRAY);
     setlinestyle(0,0,0);
     setfillstyle(1,8);
     fillpoly(5,front);
     setfillstyle(1,WHITE);
     fillpoly(5,up);
     setfillstyle(1,BROWN);
	fillpoly(5,side);

     setcolor(WHITE);
     line(x-20*sf,y,x-20*sf,y-20*sf);line(x,y,x,y-20*sf);line(x+20*sf,y,x+20*sf,y-20*sf);
     line(x-37*sf,y-15*sf,x-23*sf,y-15*sf);line(x-37*sf,y-10*sf,x-23*sf,y-10*sf);line(x-37*sf,y-5*sf,x-23*sf,y-5*sf);
     line(x-17*sf,y-15*sf,x-3*sf,y-15*sf);line(x-17*sf,y-10*sf,x-3*sf,y-10*sf);line(x-17*sf,y-5*sf,x-3*sf,y-5*sf);
     line(x+17*sf,y-15*sf,x+3*sf,y-15*sf);line(x+17*sf,y-10*sf,x+3*sf,y-10*sf);line(x+17*sf,y-5*sf,x+3*sf,y-5*sf);
     line(x+37*sf,y-15*sf,x+23*sf,y-15*sf);line(x+37*sf,y-10*sf,x+23*sf,y-10*sf);line(x+37*sf,y-5*sf,x+23*sf,y-5*sf);

     setfillstyle(1,DARKGRAY);
     setcolor(YELLOW);
     setlinestyle(0,0,0);
     settextstyle(1,0,3);
}
/*画房屋的函数*/
void house(LITTLE *hp)
{
	int x=hp->x,y=hp->y;
     double sf=hp->sf;
  
     int w1[]={x-40*sf,y-90*sf,x-20*sf,y-80*sf,x-20*sf,y-90*sf,x-40*sf,y-100*sf,x-40*sf,y-90*sf};
     int w2[]={x-20*sf,y-80*sf,x+20*sf,y-80*sf,x+20*sf,y-102*sf,x,y-110*sf,x-20*sf,y-90*sf,x-20*sf,y-80*sf};
     int w3[]={x-40*sf,y-100*sf,x-20*sf,y-90*sf,x,y-110*sf,x-22*sf,y-115*sf,x-40*sf,y-100*sf};
     int door[]={x-10*sf,y-80*sf,x-10*sf,y-95*sf,x+8*sf,y-95*sf,x+8*sf,y-80*sf,x-10*sf,y-80*sf};

     setcolor(LIGHTGRAY);
     setlinestyle(0,0,1);
 
     setfillstyle(1,RED);
     fillpoly(5,w1);
     setfillstyle(1,BROWN);
     fillpoly(6,w2);
     setfillstyle(8,BROWN);
     fillpoly(5,w3);
     setfillstyle(1,WHITE);
     fillpoly(5,door);
} 

/* 画自行车函数，可以根据需要调节大小----sf*/
void bicycle(LITTLE *pbp)
{
     int x=pbp->x,y=pbp->y;
     double sf=pbp->sf;

     int bicycle[16];
     bicycle[0]=x;bicycle[1]=y;bicycle[2]=x+0.4*sf;bicycle[3]=y+1*sf;
     bicycle[4]=x+6*sf;bicycle[5]=y+1*sf;bicycle[6]=x+2*sf;bicycle[7]=y+5*sf;
     bicycle[8]=x-2*sf;bicycle[9]=y+5*sf;bicycle[10]=x+0.4*sf;bicycle[11]=y+1*sf;
     bicycle[12]=x+2*sf;bicycle[13]=y+5*sf;bicycle[14]=x;bicycle[15]=y;

     int people[24];
     people[0]=x;people[1]=y;people[2]=x+3*sf;people[3]=y-3*sf;
     people[4]=x+4*sf;people[5]=y-2*sf; people[6]=x+6.75*sf;people[7]=y-0.5*sf;
     people[8]=x+6.55*sf;people[9]=y-0.25*sf;people[10]=x+3.57*sf;people[11]=y-1.5*sf;
     people[12]=x+1*sf;people[13]=y+0.2*sf;people[14]=x+4*sf;people[15]=y+1*sf;
     people[16]=x+2*sf;people[17]=y+5*sf;people[18]=x+3*sf;people[19]=y+1.4*sf;
     people[20]=x+0.5*sf;people[21]=y+1*sf;people[22]=x;people[23]=y;

     setcolor(LIGHTRED);
     setlinestyle(0,0,3);
     line(x+5.75*sf,y,x+7*sf,y+5*sf);
     line(x+5.75*sf,y,x+6.75*sf,y-0.5*sf);
     drawpoly(8,bicycle);
     setcolor(BLUE);
     setfillstyle(1,BLUE);
     fillpoly(12,people);

     setlinestyle(0,0,3);
     line(x+2*sf,y+5*sf,x+3*sf,y+4.8*sf);

     setcolor(BLUE);
     ellipse(x+4.2*sf,y-3.6*sf,0,360,1*sf,1*sf);
     setcolor(LIGHTBLUE);
     setlinestyle(0,0,3);
	ellipse(x-2*sf,y+5*sf,0,360,3*sf,3*sf);//轮子
     ellipse(x+7*sf,y+5*sf,0,360,3*sf,3*sf);
}
/*====================================================================================
the function is used to draw the whole map
======================================================================================*/
void draw_map(STREET all_street[18],LITTLE all_tree[10],LITTLE all_people_m[5],
                       LITTLE all_people_w[5],LITTLE all_ninebuilding[3],LITTLE all_playground[3],
				   LITTLE all_small_door[5],LITTLE all_lake[3],LITTLE all_bigbuilding[5],LITTLE all_house[10],LITTLE all_bicycle[3])
{
	int i;
	for(i=0;i<7;i++)
	     street1(&all_street[i]);
	for(i=7;i<15;i++)
	     street2(&all_street[i]);
	
     street4(&all_street[15],80);
	street4(&all_street[16],65);
	street3(&all_street[17],65);
	for(i=0;i<3;i++)
	{
		ninebuilding(&all_ninebuilding[i]);
		playground(&all_playground[i]);
	     bicycle(&all_bicycle[i]);
		lake(&all_lake[i]);
	}
     for(i=0;i<10;i++)
	{
	     tree(&all_tree[i]);
		house(&all_house[i]);
	}
     for(i=0;i<5;i++)
	{
		people_m(&all_people_m[i]);
		people_w(&all_people_w[i]);
		small_door(&all_small_door[i]);
		bigbuilding(&all_bigbuilding[i]);
	}
     compass();
} 
