/*======================================================
�������Ĺ�����ͨ�����̿���С�����˶���
====================================================*/
#include"all.h"
#include"stru.h"
#include"public.h"
#include"hong.h"
void car_control(CAR *cp,double *carspeed)
{
	cp->xspeed=-(*carspeed * cos(cp->angle*PI/180));
	cp->yspeed=-(*carspeed * sin(cp->angle*PI/180));	
		
	if(((cp->x)>150) && cp->x<400 && cp->y>100 && cp->y<250)   
	{
		(cp->x)-=(cp->xspeed);
		(cp->y)+=(cp->yspeed);
	}
	if(cp->angle>=360)   //���ת����360�ȣ�����360��ȥ����Ƕ�
	{
		cp->angle=(cp->angle)-360;
	}
	if(cp->angle<=-360)
	{
		cp->angle+=360;    
	}
	if(bioskey(1))  //�а���ʱ��Ĳ���
	{
		if((cp->x)>150 && cp->x<400 && cp->y>100 && cp->y<250)
		{
			int key=bioskey(0);
			switch(key)
			{
				case UP :       			//��ס���ϵļ�ͷʱ��С�����ݶȼ�1
							if(cp->angle<=180)
							{
								if(*carspeed<15)
									*carspeed+=5;
								if(*carspeed==15)
									*carspeed=15;
							}
							if(cp->angle>180)
							{
								if(*carspeed>-15)
								     *carspeed-=5;
								if(*carspeed==-15)
									*carspeed=-15;
							}
							break;
																				
				case DOWN :     //�������µļ�ͷʱ��С���������ٶȼ�1
													
					if(cp->angle<=180)
					{
						if(*carspeed>-15)
							*carspeed-=5;
						if(*carspeed==-15)
						     *carspeed=-15;
					}
					if(cp->angle>180)
					{
						if(*carspeed<15)
							*carspeed+=5;
						if(*carspeed==15)
							*carspeed=15;
					}
					break;
				case  LEFT :             //С����ʱ��ת��
					cp->angle += 15;
					break;
											
				case   RIGHT :             //С����ʱ��ת��
											
					cp->angle -= 15;
					break;
											
				case	P :             //��ͣ
					while(P!=bioskey(0));
					break;
				case SPACE : //��ɲ��
					*carspeed=0;       
					*carspeed=0;
					break;
				case	ESC :
					closegraph();
					goodbye();
					exit(0);
					break;
				default :
					break;
			}
		}
	}
}


void map_ctrl(MAP *mp,CAR *cp,double *carspeed,int *map_first,double *map_speed,POINT *point,STREET all_street[18],LITTLE all_tree[10],LITTLE m[5],LITTLE wp[5],LITTLE sp[3],
                    LITTLE gp[3],LITTLE dp[5],LITTLE lap[3],LITTLE bip[5],LITTLE hp[10],LITTLE bicycle[3])
{
	int i;
	static int temp_speed;
	if((cp->x>=400 || cp->y<=100 || cp->y>=250 || cp->x<=150))
	{
		if(0==*map_first)      // this is to judge whether car is out of bounds
		{
			temp_speed=(*carspeed);    //��Խ���ʱ�򣬰ѳ����ٶȴ��ݸ���ͼ
			(*map_speed)=temp_speed;
			*map_first=1;
			*carspeed=0;
		}
	}
	if(cp->angle>=360)               //���ת����360�ȣ�����360��ȥ����Ƕ�
	{
		cp->angle=cp->angle-360;
	}
	if(cp->angle<=-360)
	{
		cp->angle+=360;
	}

	mp->map_xspeed=*map_speed *cos((cp->angle)*PI/180);     //С���ĽǶȼ�Ϊ��ͼ�ĽǶ�
	mp->map_yspeed=*map_speed *sin((cp->angle)*PI/180);

	  if((cp->x>=400 || cp->y<=100 || cp->y>=250 || cp->x<=150))
	{
		for(i=0; i<18; i++,all_street++)
		{
			all_street->x-=mp->map_xspeed;
			all_street->y+=mp->map_yspeed;
		}
		for(i=0;i<SPOTNUM;i++,point++)
		{
			point->x-=mp->map_xspeed;
			point->y+=mp->map_yspeed;
		}
		for(i=0; i<10; i++,all_tree++)
		{
			all_tree->x-=mp->map_xspeed;
			all_tree->y+=mp->map_yspeed;
		}
		for(i=0; i<5; i++,m++)
		{
		     m->x-=mp->map_xspeed;
			m->y+=mp->map_yspeed;
		}
		for(i=0; i<5; i++,wp++)
		{
		   wp->x-=mp->map_xspeed;
			wp->y+=mp->map_yspeed;
		}
		for(i=0; i<3; i++,sp++)
		{
		   sp->x-=mp->map_xspeed;
			sp->y+=mp->map_yspeed;
		}
		for(i=0; i<5; i++,dp++)
		{
		   dp->x-=mp->map_xspeed;
			dp->y+=mp->map_yspeed;
		}
		for(i=0; i<3; i++,gp++)
		{
		   gp->x-=mp->map_xspeed;
			gp->y+=mp->map_yspeed;
		}
		for(i=0;i<3;i++,lap++)
		{
			lap->x-=mp->map_xspeed;
               lap->y+=mp->map_yspeed;
		}
		for(i=0;i<5;i++,bip++)
		{
			bip->x-=mp->map_xspeed;
               bip->y+=mp->map_yspeed;
		}
		for(i=0;i<10;i++,hp++)
		{
			hp->x-=mp->map_xspeed;
               hp->y+=mp->map_yspeed;
		}
		for(i=0;i<3;i++,bicycle++)
		{
			bicycle->x-=mp->map_xspeed;
               bicycle->y+=mp->map_yspeed;
		}
	}

	if(bioskey(1))
	{
		int ch=bioskey(0);
		if((cp->x>=400 || cp->y<=100 || cp->y>=250 || cp->x<=150))
		{
			switch(ch)
			{
				case    LEFT :             //С����ʱ��ת��

							cp->angle += 15;
							break;

				case   RIGHT :             //С����ʱ��ת��

							cp->angle -= 15;
							break;
				case	UP:
									if(cp->angle<=180)         //������һ���Ƕȣ���Ϊ����С���ܹ��г�ͷ����β�ĸ���
										{
										if(*map_speed<15)
											*map_speed+=5;
										if(15==*map_speed)
											*map_speed=15;
										}
									if(cp->angle>180)
										{
											if(*map_speed>-15)
											*map_speed-=5;
											if(-15==*map_speed)
											*map_speed=-15;
										}
									break;
				case	DOWN:
									if(cp->angle<=180)
										{
										if(*map_speed>-15)
											*map_speed-=5;
										if(-15==*map_speed)
											*map_speed=-15;
										}
										if(cp->angle>180)
										{
											if(*map_speed<15)
											*map_speed+=5;
										if(15==*map_speed)
											*map_speed=15;
										}

									break;
				case	P:             //��ͣ
									while(P!=bioskey(0));
									break;
				case SPACE : //��ɲ��
									*map_speed=0;
									break;
				case ESC :
								 closegraph();
								 goodbye();
								 exit(0);
								 break;

				default :
								break;
			}
			}
		}


}