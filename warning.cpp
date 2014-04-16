#include"all.h"
#include"public.h"
void SOUND(unsigned frequency)
{
	union                /* ������-�������������ַ���ɵ����� */
	{                                         
		unsigned divisor;
		unsigned char c[2];
	} tone;

	tone.divisor=119328L/frequency;             /* �����Ƶ�ʶ�Ӧ�Ķ�ʱ������ֵ */
	outportb(0x43,0xb6);                              /* ֪ͨ��ʱ�������µļ��� */
	outportb(0x42,tone.c[0]);                       /* �������ֽ����͵���ʱ�� */
	outportb(0x42,tone.c[1]);                        /* �������ֽں��͵���ʱ�� */
	outportb(0x61,inportb(0x61) | 3 );           /* ʹ��ʱ�������ȵ������Ч */
}

void NOSOUND(void)
{
	outportb(0x61,(inportb(0x61) & 0xfc)); /* ʹ��ʱ�������ȵ������Ч */
}
void speed_warning(double *map_speed)
{
	if((*map_speed) <15 && (*map_speed>-15) && *map_speed != 0)
	{
		draw_bar1(510,280,634,300,LIGHTGRAY);
		dis_hz(510,280,"������ʻ",0,30,GREEN);
	}
	
	else if((*map_speed)>=15  || (*map_speed)<=-15)
	{
		draw_bar1(495,280,634,300,LIGHTGRAY);
		dis_hz(495,280,"�ѳ��٣������",0,20,GREEN);
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

