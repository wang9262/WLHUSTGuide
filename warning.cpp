#include"all.h"
#include"public.h"
void SOUND(unsigned frequency)
{
	union                /* 定义由-个整数和两个字符组成的联合 */
	{                                         
		unsigned divisor;
		unsigned char c[2];
	} tone;

	tone.divisor=119328L/frequency;             /* 计算该频率对应的定时器计数值 */
	outportb(0x43,0xb6);                              /* 通知定时器采用新的计数 */
	outportb(0x42,tone.c[0]);                       /* 计数低字节先送到定时器 */
	outportb(0x42,tone.c[1]);                        /* 计数高字节后送到定时器 */
	outportb(0x61,inportb(0x61) | 3 );           /* 使定时器到喇叭的输出有效 */
}

void NOSOUND(void)
{
	outportb(0x61,(inportb(0x61) & 0xfc)); /* 使定时器到喇叭的输出无效 */
}
void speed_warning(double *map_speed)
{
	if((*map_speed) <15 && (*map_speed>-15) && *map_speed != 0)
	{
		draw_bar1(510,280,634,300,LIGHTGRAY);
		dis_hz(510,280,"正常行驶",0,30,GREEN);
	}
	
	else if((*map_speed)>=15  || (*map_speed)<=-15)
	{
		draw_bar1(495,280,634,300,LIGHTGRAY);
		dis_hz(495,280,"已超速，请减速",0,20,GREEN);
	}
	
}

void warning_beep(double *beep_speed)
{
  
   unsigned   freq; 
   if((*beep_speed)>=15 || (*beep_speed)<=-15)
   {
		for(freq=80;freq<230;freq+=30)
		{ 
			SOUND(freq); 
			delay(20); 
			NOSOUND(); 
		} 
		for(   ;   freq> 80;     freq   -=30) 
		{ 
			SOUND(freq); 
			delay(20); 
			NOSOUND(); 
		} 
	}
}

/*the function is used to remind you if the car or the map  have run with high speed */
void warning(double *map_speed, double *speed)
{
	speed_warning(speed);
	speed_warning(map_speed);
	warning_beep(speed);
	warning_beep(map_speed);
}

