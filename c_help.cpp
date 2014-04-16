#include "stru.h"
#include "all.h"
#include "public.h"
/*******此函数为选择模式下的帮助 choose help******/
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
	bt.name="返回";
	dr_button(&bt,CYAN,50,1);
	dis_hz(230,10,"使用帮助",1,50,YELLOW);
	dis_hz(20,50,"一、本导航系统适用于华科整个校区，其他地区有待推广。",0,20,WHITE);
	dis_hz(20,75,"二、选择起点，会弹出相应的选项，然后再点击进入选择，选择后",0,20,LIGHTRED);
	dis_hz(60,100,"下方会显示起点名称，终点也一样，然后点击开始，则开启导航",0,20,LIGHTRED);
	dis_hz(20,125,"三、在导航过程中，键盘上的上下左右键分别代表加速、减速、左",0,20,WHITE);
	dis_hz(60,145,"转、右转，空格代表急刹车。",0,20,WHITE);
	dis_hz(20,170,"四、在导航过程中，系统会自动检测小车的状态，并显示小车当前",0,20,WHITE);
	dis_hz(60,195,"位置、距终点距离等信息，并在超速时发出警报，走错路线时",0,20,WHITE);
	dis_hz(60,220,"系统会报错，并重新寻找最短线路！",0,20,WHITE);
	dis_hz(20,245,"五、若想结束导航，点击退出按钮，则会退出整个程序。点击帮助",0,20,WHITE);
	dis_hz(60,270,"则会弹出帮助界面。",0,20,WHITE);
	dis_hz(300,290,"制作人：张辰惺、王乐",0,20,YELLOW);
	dis_hz(230,320,"欢迎使用",1,50,YELLOW);
	while(1)
	{
		newmouse(&mousex,&mousey,&mousekey);
		if(mousex>499&&mousex<591&&mousey>319&&mousey<359&&mousekey==1)
		break;
	}
}