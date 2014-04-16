#include"all.h"
#include"stru.h"
#include"public.h"
#include"hong.h"
void main_page(int *choice)
{
	CAR cp1;
	MAP mp;
	mp.map_xspeed=0;mp.map_yspeed=0;
	cp1.angle=0;cp1.xspeed=0;cp1.yspeed=0;
	double  speed=0;
	double map_speed=0;
	int i=0;                        
	int flag_click_beg=0;    //the three flags are used to judge if the "Start","Finish","Begin" button is pressed
	double distance=0;                //此距离要根据选择路径的函数来实时反馈
	int start_point=-1, finish_point=-1;
	int  center_x;
	int  center_y;
	int flag_judge_finish=0;
	int flag_road_error=0;
	int map_first=0;  //to judge  car  whether it is out of bounds(150,100,400,250)  
	double p_distance[SPOTNUM][SPOTNUM];
	double d[SPOTNUM];
	int path[SPOTNUM];
	POINT point[SPOTNUM];
	STREET all_street[18];
   	LITTLE all_ninebuilding[3];
	LITTLE all_small_door[5];
	LITTLE all_tree[10];
	LITTLE all_mpeople[5];
	LITTLE all_wpeople[5];
	LITTLE all_lake[3];
	LITTLE all_playground[3];
	LITTLE all_bigbuilding[5];
	LITTLE all_house[10];
	LITTLE bicycle[3];
	init_map(all_street,all_tree,all_mpeople,all_wpeople,all_ninebuilding,all_playground,all_small_door,all_lake,all_bigbuilding,all_house,bicycle);
	init_point_info(point,p_distance);
	while(1)
	{
		flag_click_beg=0;
		flag_judge_finish=0;
		InitGra(350);
		setbkcolor(LIGHTGREEN);
		draw_map(all_street,all_tree,all_mpeople,all_wpeople,all_ninebuilding,all_playground,all_small_door,all_lake,all_bigbuilding,all_house,bicycle);
		right_plus();
		 while(!(1==flag_click_beg && start_point>=0 && finish_point>=0))
		{
			switch(*choice)
			{
				case 0:
					search(point,&flag_click_beg,&start_point,&finish_point); 
				     break;
				case 1:
					mouse_ctrl(&flag_click_beg,&start_point,&finish_point);
					break;
				default:
					break;
			}
			cleardevice();
			draw_map(all_street,all_tree,all_mpeople,all_wpeople,all_ninebuilding,all_playground,all_small_door,all_lake,all_bigbuilding,all_house,bicycle);
			mouse_click();
		}
		shortestpath(p_distance,SPOTNUM,d,path,start_point);
		distance=rest_distance(&cp1,point[finish_point]);
		center_x=340-point[start_point].x;
		center_y=170-point[start_point].y;
		second_init_map(&center_x, &center_y,point,all_street,all_tree,all_mpeople,all_wpeople,all_ninebuilding,all_playground,all_small_door,all_lake,all_bigbuilding,all_house,bicycle);
		cp1.x=point[start_point].x;
		cp1.y=point[start_point].y;
	     while(0==flag_judge_finish && 0==flag_road_error)
	    {
			while(0==flag_judge_finish && 0==flag_road_error)     //有没有完成一次导航的标志，如果完成就会跳出大循环
			{
				for(i=0;i<2;i++)
				{
					setactivepage(i);
				     cleardevice();
				     draw_map(all_street,all_tree,all_mpeople,all_wpeople,all_ninebuilding,all_playground,all_small_door,all_lake,all_bigbuilding,all_house,bicycle);
				     drawroutine(start_point, finish_point,point,path); 					//画出最短的路径
					 car_control(&cp1,&speed);
				     map_ctrl(&mp,&cp1,&speed,&map_first,&map_speed,point,all_street,all_tree,all_mpeople,all_wpeople,
					              all_ninebuilding,all_playground,all_small_door,all_lake,all_bigbuilding,all_house,bicycle);
					 distance=rest_distance(&cp1,point[finish_point]);
					 draw_car(&cp1);
				     mouse_click();
					 show_distance(&distance);
				/*======================判断小车所处位置=============================*/
				     judge_pre_car(&cp1,point);
				     change_route(&cp1, point, &start_point, &finish_point,path,&flag_road_error);
				     warning(&map_speed, &speed);
				     setvisualpage(i);
				     delay(15);
			     }
			    flag_judge_finish=judge_finish(&cp1,point[finish_point]);
		    }
	          if(1==flag_judge_finish)
		    {
			     distance=0;
				draw_bar1(494,57,636,78,LIGHTGRAY);
			     dis_hz(495,60,"到达目的地",0,20,YELLOW);
			     guidance_end(150,100);
			     cp1.angle=0;		
			     flag_click_beg=0;
			     speed=0;
			     map_speed=0; 			    //再次进入的时候，还是先判断车速
			     start_point=-1;
				finish_point=-1;
				map_first=0;
		     }
			if(1==flag_road_error)
		    {
				shortestpath(p_distance,SPOTNUM,d,path,start_point);
				draw_bar1(494,57,636,150,LIGHTGRAY);
			     dis_hz(495,60,"路线错误，正在",0,18,LIGHTRED);
				dis_hz(495,80,"为您重新查找……",0,18,LIGHTRED);
			     delay(1000);
			     draw_bar1(494,57,636,150,LIGHTGRAY);
			     flag_road_error=0;
		     }
	     }
	}
}