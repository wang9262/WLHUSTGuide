#include "stru.h"
#include "all.h"
#include "public.h"
/*******�˺���Ϊѡ��ģʽ�µİ��� choose help******/
void c_help()
{
     BUTTON bt;
	int mousex=320,mousey=150,mousekey;
	cleardevice();
	cursor(mousex,mousey);
	setbkcolor(LIGHTBLUE);
	setcolor(YELLOW);
	line(0,37,getmaxx(),37);
	line(0,39,getmaxx(),39);
	line(0,8,639,8);
	line(0,5,639,5);
	line(0,315,639,315);
	line(0,317,639,317);
	bt.x=500,bt.y=320;
	bt.x1=bt.x+90,bt.y1=bt.y+28;
	bt.name="����";
	dr_button(&bt,CYAN,50,1);
	dis_hz(230,10,"ʹ�ð���",1,50,YELLOW);
	dis_hz(20,50,"һ��������ϵͳ�����ڻ�������У�������������д��ƹ㡣",0,20,WHITE);
	dis_hz(20,75,"����ѡ����㣬�ᵯ����Ӧ��ѡ�Ȼ���ٵ������ѡ��ѡ���",0,20,LIGHTRED);
	dis_hz(60,100,"�·�����ʾ������ƣ��յ�Ҳһ����Ȼ������ʼ����������",0,20,LIGHTRED);
	dis_hz(20,125,"�����ڵ��������У������ϵ��������Ҽ��ֱ������١����١���",0,20,WHITE);
	dis_hz(60,145,"ת����ת���ո����ɲ����",0,20,WHITE);
	dis_hz(20,170,"�ġ��ڵ��������У�ϵͳ���Զ����С����״̬������ʾС����ǰ",0,20,WHITE);
	dis_hz(60,195,"λ�á����յ�������Ϣ�����ڳ���ʱ�����������ߴ�·��ʱ",0,20,WHITE);
	dis_hz(60,220,"ϵͳ�ᱨ��������Ѱ�������·��",0,20,WHITE);
	dis_hz(20,245,"�塢�����������������˳���ť������˳��������򡣵������",0,20,WHITE);
	dis_hz(60,270,"��ᵯ���������档",0,20,WHITE);
	dis_hz(300,290,"�����ˣ��ų��ʡ�����",0,20,YELLOW);
	dis_hz(230,320,"��ӭʹ��",1,50,YELLOW);
	while(1)
	{
		newmouse(&mousex,&mousey,&mousekey);
		if(mousex>499&&mousex<591&&mousey>319&&mousey<359&&mousekey==1)
		break;
	}
}