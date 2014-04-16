#include"all.h"
#include"stru.h"
#include"public.h"
#include"hong.h"
void input(POINT point[SPOTNUM],int star_fina_flag,int *point1)
{
	char info[7];
	int key;		
	int i=0,p=0,j,pp;	//i用于判断输入字母的个数,p用于判断是否有回车键,j is to judge enter
	char * s;			//j用于循环，pp用于判断是否搜索到相应的点,pp to judge input and point.ename,
	char * ss;          //ss用于接收输入的键 ,ss use to include input,s to include point.name
	settextstyle(0,0,2);
	settextjustify(0,2);
	dis_hz(495,60,"请输入起或终点",0,20,WHITE);
	draw_bar1(495,80,635,100,WHITE);
	while(1)
	{
		setcolor(LIGHTRED);
		key=bioskey(0);
		switch(key)
		{
			case A:
				outtextxy(495+i*16,82,"A");
				info[i]='A';
				i++;
				break;
			case B:
				outtextxy(496+i*16,82,"B");
				info[i]='B';
				i++;
				break;
			case C:
				outtextxy(496+i*16,82,"C");
				info[i]='C';
				i++;
				break;
			case D:
				outtextxy(496+i*16,82,"D");
				info[i]='D';
				i++;
				break;
			case E:
				outtextxy(496+i*16,82,"E");
				info[i]='E';
				i++;
				break;
			case F:
				outtextxy(496+i*16,82,"F");
				info[i]='F';
				i++;
				break;
			case G:
				outtextxy(496+i*16,82,"G");
				info[i]='G';
				i++;
				break;
			case H:
				outtextxy(496+i*16,82,"H");
				info[i]='H';
				i++;
				break;
			case I:
				outtextxy(496+i*16,82,"I");
				info[i]='I';
				i++;
				break;
			case J:
				outtextxy(496+i*16,82,"J");
				info[i]='J';
				i++;
				break;
			case K:
				outtextxy(496+i*16,82,"K");
				info[i]='K';
				i++;
				break;
			case L:
				outtextxy(496+i*16,82,"L");
				info[i]='L';
				i++;
				break;
			case M:
				outtextxy(496+i*16,82,"M");
				info[i]='M';
				i++;
				break;
			case N:
				outtextxy(496+i*16,82,"N");
				info[i]='N';
				i++;
				break;
			case O:
				outtextxy(496+i*16,82,"O");
				info[i]='O';
				i++;
				break;
			case P:
				outtextxy(496+i*16,82,"P");
				info[i]='P';
				i++;
				break;
			case Q:
				outtextxy(496+i*16,82,"Q");
				info[i]='Q';
				i++;
				break;
			case R:
				outtextxy(496+i*16,82,"R");
				info[i]='R';
				i++;
				break;
			case S:
				outtextxy(496+i*16,82,"S");
				info[i]='S';
				i++;
				break;
			case T:
				outtextxy(496+i*16,82,"T");
				info[i]='T';
				i++;
				break;
			case U:
				outtextxy(496+i*16,82,"U");
				info[i]='U';
				i++;
				break;
			case V:
				outtextxy(496+i*16,82,"V");
				info[i]='V';
				i++;
				break;
			case W:
				outtextxy(496+i*16,82,"W");
				info[i]='W';
				i++;
				break;
			case X:
				outtextxy(496+i*16,82,"X");
				info[i]='X';
				i++;
				break;
			case Y:
				outtextxy(496+i*16,82,"Y");
				info[i]='Y';
				i++;
				break;
			case Z:
				outtextxy(496+i*16,82,"Z");
				info[i]='Z';
				i++;
				break;
			case ENTER://确定
				p=1;
				break;
			case BACKSPACE: //删除
				if(i>0)
				{
					draw_bar1(480+i*16,82,496+i*16,100,WHITE);
					i--;
				}
				break;
			case ESC:
				closegraph();
			     goodbye();
                    exit(0);			
			     default:
				break;
		}
	     if(p==1)
	    {
		     info[i]='\0';
		     break;
	    }
	    if(i>=6)
	    {
			info[i]='\0';
		     break;
	    }
     }
	ss=info;
	for(j=0;j<25;j++)
	{
		s=point[j].ename;
		pp = strcmp(ss,s);
		if(pp==0)
		{
			*point1=point[j].num;
			remark(point[j].remarks);
			show_sta_fin(point[j].name,star_fina_flag);
			break;
		}
     }
	if(pp!=0)
	{
		i=0;
		p=0;
		draw_bar1(495,100,634,140,LIGHTGRAY);
		dis_hz(495,100,"无该地点，请重",0,20,LIGHTCYAN);
		dis_hz(495,120,"新输入………",0,20,LIGHTCYAN);
		delay(300);
		draw_bar1(495,100,634,330,LIGHTGRAY);	
		key=bioskey(0);
	}
}