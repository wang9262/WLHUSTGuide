#include"all.h"
union REGS regs;

/****����꣬�˴�����Ϊ��ʵ������ʵ�Ļ�������ȫ���������****/   
void cursor(int x, int y)
{
	setwritemode(XOR_PUT);
	setlinestyle(0,0,1);
	setcolor(BLACK);
	
     line(x,y,x+11,y+11);
     line(x+10,y+11,x+8,y+11);
     line(x+7,y+11,x+10,y+19);
     line(x+9,y+20,x+8,y+20);
     line(x+7,y+19,x+4,y+12);
     line(x+3,y+13,x+1,y+15);
     line(x,y+16,x,y+1);
	setcolor(WHITE);
	
    line(x+1,y+2,x+1,y+14);
    line(x+2,y+3,x+2,y+13);
    line(x+3,y+4,x+3,y+12);
    line(x+4,y+5,x+4,y+11);
    line(x+5,y+6,x+5,y+13);
    line(x+6,y+7,x+6,y+15);
    line(x+7,y+8,x+7,y+10);
    line(x+7,y+14,x+7,y+17);
    line(x+8,y+9,x+8,y+10);
    line(x+8,y+16,x+8,y+19);
    line(x+9,y+10,x+9,y+10);
    line(x+9,y+18,x+9,y+19);
	
	setwritemode(COPY_PUT);
}


/*****��ʼ�����*****/ 
/*����7��8�Ź���ȷ�����λ�õļ���λ��*/ 
int initmouse(int xmi, int xma, int ymi, int yma)	
{
	int retcode;
	regs.x.ax=0;
	int86(51,&regs,&regs);
	retcode=regs.x.ax;
	if(0==retcode)
	{
		return 0;
	}
	regs.x.ax = 7;                                                                                
	regs.x.cx = xmi;                                                                              
	regs.x.dx = xma;                                                                              
	int86(51, &regs, &regs);                                                                      
	regs.x.ax = 8;                                                                                
	regs.x.cx = ymi;                                                                              
	regs.x.dx = yma;                                                                              
	int86(51, &regs, &regs);                                                                      
	return retcode;                
}

/***����ϵͳ�жϵõ��ȼ�λ�ú����״̬***/ 
int readmouse(int *mx, int *my,int *mbutt)           //������������������Ǹı������ú���ʱ�����mosex,mosey,mousekeyֵ
{
	int xx0 = *mx;                                                                                
	int yy0 = *my;                                                                                
	int but0 = 0;                                                                                 
	int mb;                                                                                       
	int xnew;                                                                                     
	int ynew;                                                                                     
	do                                 //������λ�û򰴼�״̬û�иı䣬�Ͳ���ı䶨���ֵ���������ں����ﶨ���mosex,mosey,mousekeyֵ
	{                                                                                             
		regs.x.ax = 3;                                                                            
		int86(51, &regs, &regs);                                                                  
		xnew = regs.x.cx;                                                                         
		ynew = regs.x.dx;                                                                         
		*mbutt = regs.x.bx;                                                                       
	}while (xnew==xx0&&ynew==yy0&&*mbutt==but0);                                                  
		*mx = xnew; /*���º���ȼ�λ��*/                                                                              
		*my = ynew;                                                                               
		return 0;                                                      
}

/****newmouse���������ڵõ������ȼ�������겢��ԭ�����������*****/    //�����İ����޹�                                                                                              
void newmouse(int *mx, int*my, int*mbutt)      //���µ�λ�û���꣬���һ����readmouse�����ı�mosex,mosey,mousekeyֵ	                         
{                                                                                                 
		int xx0 = *mx;                                                                                
		int yy0 = *my;                                                                                
		 
		int xm;                                                                                       
		int ym;                                                                                       
		readmouse(&xm, &ym, mbutt); /*����readmouse�����õ��µ��ȼ�λ�ú���갴ť״̬*/                                                                       
          if(xm!=xx0||ym!=yy0)
		{			
			cursor(xx0, yy0);	/*��ԭ�������ķ�ʽ��ԭ������긲��*/                                                   
			cursor(xm, ym);
		}			/*���µ�λ�û����*/	                                                        
		*mx = xm;                                                                                     
		*my = ym;                                                                                     
} 