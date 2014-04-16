#include"all.h"
#include"stru.h"
#include"public.h"
#include"hong.h"
void init_all_street(STREET street[18])
{
	int i;
	int a[18]={218,1938,300,303,448,333,340,447,577,687,790,1159,1519,1935,2205,393,687,727},
	     b[18]={120,269,451,543,626,722,870,870,722,870,729,870,120,911,309,870,870,870},
		c[18]={2014,270,858,858,130,457,1600,244,602,148,179,750,100,601,191,130,65,65};
     for (i=0;i<18;i++)
     {
		street[i].x=a[i];
		street[i].y=b[i];
		street[i].len=c[i];
	}	
}
void init_all_tree(LITTLE tree[10])//树的位置
{
	int a[10]={100,546,254,270,379,1091,1090,636,911,1248},//,1113,87,2131,106,1853,1864,129,996,774,450},
		 b[10]={10,192,493,579,773,819,604,192,77,191};//189,110,196,172,475,730,230,198,196,190};
	int i;
	 for(i=0;i<10;i++)
	 {
		tree[i].x=a[i];
		 tree[i].y=b[i];
		 tree[i].sf=2;
	 }
}
void init_all_people_m(LITTLE mp[5])//画男人的位置
{
	int a[5]={87,356,604,760,733},//829,860,314,218,1559},
		b[5]={264,943,920,401,511},//80,622,74,196,942},
		c[5]={2,1,2,1,2};//1,2,1,2,1};
	 int i;
	 for(i=0;i<5;i++)
	{
		mp[i].x=a[i];
		mp[i].y=b[i];
		mp[i].sf=c[i];
	}
}
void init_all_people_w(LITTLE mp[5])//画女人的位置
{
	int a[5]={210,427,863,985,993},//882,802,371,152,1703},
		b[5]={627,72,190,389,513},//568,901,74,1200,834},
		c[5]={2,1,2,1,2};//,1,2,1,2,1};
	 int i;
	 for(i=0;i<5;i++)
	{
		mp[i].x=a[i];
		mp[i].y=b[i];
		mp[i].sf=c[i];
	}
}
void  init_all_building(LITTLE ninebuilding[3])//画东十二，西十二，东九
{
	int a[3]={229,1539,2100},
		b[3]={714,173,305};
	int i;
	for(i=0;i<3;i++)
	{
		ninebuilding[i].x=a[i];
		ninebuilding[i].y=b[i];
		ninebuilding[i].sf=2;
	}
}
void  init_all_door(LITTLE small_door[5])//画所有校门
{
	int a[5]={340,447,687,1157,1935};
	int i;
	for(i=0;i<6;i++)
	{
		small_door[i].x=a[i];
		small_door[i].y=870;
		small_door[i].sf=2;
	}
}
void init_all_playground(LITTLE gp[3])//画操场
{
	int a[3]={365,1333,1839},
		b[3]={227,700,277};
	int i;
	for(i=0;i<3;i++)
		{ 
			gp[i].x=a[i];
			gp[i].y=b[i];
			gp[i].sf=2;
	}
}
void init_all_lake(LITTLE lap[3])//湖。。。。。。。。。。。。。
{
	int a[3]={515,843,1665},
		b[3]={755,736,190};
	int  i;
	for(i=0;i<3;i++)
	{
		lap[i].x=a[i];
		lap[i].y=b[i];
		lap[i].sf=3;
	}
}
void init_all_bigbuilding(LITTLE bip[5])//南一，，，，，
{
	int a[5]={694,444,444,2167,2100},
		b[5]={665,542,430,86,630};
	int i;
	for (i=0;i<5;i++)
	{
			bip[i].x=a[i];
			bip[i].y=b[i];
			bip[i].sf=2;
		}
}
void init_all_house(LITTLE hp[10])//房子
{
	int a[10]={220,722,1159,1515,1940,1835,2100,1273,1280,180},
		b[10]={250,250,250,190,250,250,660,672,729,700};
	int i;
	for (i=0;i<10;i++)
	{
			hp[i].x=a[i];
			hp[i].y=b[i];
			hp[i].sf=2;
		}
}
void init_all_bicycle(LITTLE plp[3])
{
	int a[3]={298,298,659},
		b[3]={173,452,121};
	int i;
	for(i=0;i<3;i++)
	{
			plp[i].x=a[i];
			plp[i].y=b[i];
		     plp[i].sf=2;
	}
}
void init_map(STREET street[18],LITTLE tree[10],LITTLE mp[5],LITTLE wp[5],LITTLE building[3],LITTLE playground[3],
                                   LITTLE door[5],LITTLE lake[3],LITTLE bigbuilding[5],LITTLE house[10],LITTLE bicycle[3])
{
	init_all_street(street);
	init_all_tree(tree);
	init_all_people_m(mp);
	init_all_people_w(wp);
	init_all_building(building);
	init_all_playground(playground);
	init_all_door(door);
	init_all_lake(lake);
	init_all_bigbuilding(bigbuilding);
	init_all_house(house);
	init_all_bicycle(bicycle);
}
void second_init_map(int *center_x, int *center_y,POINT *point,STREET street[18],LITTLE  tree[10],LITTLE mp[5],LITTLE wp[5],LITTLE building[3],LITTLE playground[3],
                                   LITTLE door[5],LITTLE lake[3],LITTLE bigbuilding[5],LITTLE house[10],LITTLE bicycle[3])	
{
	     int i;
		for(i=0;i<SPOTNUM;i++,point++)     //使节点击跟着起点一起动
		{
			point->x+=*center_x;
			point->y+=*center_y;
		}
		for(i=0; i<3; i++,lake++,building++,playground++,bicycle++)
		{
			lake->x+=*center_x;
			lake->y+=*center_y;
			building->x+=*center_x;
			building->y+=*center_y;
			playground->x+=*center_x;
			playground->y+=*center_y;
			bicycle->x+=*center_x;
			bicycle->y+=*center_y;
		}
		for(i=0; i<18; i++,street++)
		{
		     street->x+= *center_x;
			street->y+= *center_y;
		}
		for(i=0; i<10; i++,tree++)
		{
			tree->x+=*center_x;
			tree->y+=*center_y;
		}
    
		for(i=0; i<5; i++,mp++,wp++,door++,bigbuilding++)
		{
			mp->x+=*center_x;
			mp->y+=*center_y;
			wp->x=*center_x;
			wp->y=*center_y;
			door->x+=*center_x;
			door->y+=*center_y;
			bigbuilding->x+=*center_x;
			bigbuilding->y+=*center_y;
		}
		for(i=0; i<10; i++,house++)
		{
			house->x+=*center_x;
			house->y+=*center_y;
		}
}





