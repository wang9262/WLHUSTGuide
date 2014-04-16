#include"all.h"
#include"stru.h"
#include"public.h"
#include"hong.h"

void init_point(POINT point[SPOTNUM])    //下面是初始化节点参数，包括编号，参数，坐标,名称，英文首字母缩写
{
	//以下为学生公寓
	point[0].x=2000;point[0].y=140;point[0].name="韵苑公寓";point[0].remarks[0]="主要居住东校区";point[0].remarks[1]="学生";point[0].num=0;point[0].ename="YYGY";
	point[1].x=310;point[1].y=563;point[1].name="紫崧公寓";point[1].remarks[0]="主要居住西校区";point[1].remarks[1]="学生";point[1].num=1;point[1].ename="ZSGY";
	point[2].x=1177;point[2].y=563;point[2].name="沁苑公寓";point[2].remarks[0]="主要居住主校区";point[2].remarks[1]="学生";point[2].num=2;point[2].ename="QYGY";
	point[3].x=1540;point[3].y=20;point[3].name="博士公寓";point[3].remarks[0]="主要居住博士后";point[3].remarks[1]="靠近东九";point[3].num=3;point[3].ename="BSGY";
	point[4].x=807;point[4].y=742;point[4].name="研究生公寓";point[4].remarks[0]="主要居住研究生";point[4].remarks[1]="左侧为光谷体育馆";point[4].num=4;point[4].ename="YJSGY";
	//食堂
	point[5].x=1955;point[5].y=413;point[5].name="学一食堂";point[5].remarks[0]="清真食堂，附近";point[5].remarks[1]="有东十二";point[5].num=5;point[5].ename="XYST";
	point[6].x=2220;point[6].y=140;point[6].name="东园食堂";point[6].remarks[0]="学生食堂，一楼";point[6].remarks[1]="较贵";point[6].num=6;point[6].ename="DYST";
	point[7].x=1898;point[7].y=140;point[7].name="韵苑食堂";point[7].remarks[0]="学生食堂，晚上";point[7].remarks[1]="营业时间长";point[7].num=7;point[7].ename="YYST";
	point[8].x=1177;point[8].y=473;point[8].name="东四食堂";point[8].remarks[0]="沁苑附近，价格";point[8].remarks[1]="合理";point[8].num=8;point[8].ename="DSST";
	point[9].x=240;point[9].y=140;point[9].name="百景园";point[9].remarks[0]="食物品种多，价";point[9].remarks[1]="格较高";point[9].num=9;point[9].ename="BJY";
	//教学楼
	point[10].x=2088;point[10].y=289;point[10].name="东十二";point[10].remarks[0]="东校区学生的主";point[10].remarks[1]="要教学楼";point[10].num=10;point[10].ename="DSE";
	point[11].x=1650;point[11].y=140;point[11].name="东九楼";point[11].remarks[0]="前有小湖，附近";point[11].remarks[1]="是华科附中";point[11].num=11;point[11].ename="DJL";
	point[12].x=467;point[12].y=646;point[12].name="西五楼";point[12].remarks[0]="主要是物理课程";point[12].remarks[1]="教学楼";point[12].num=12;point[12].ename="XWL";
	point[13].x=707;point[13].y=742;point[13].name="南一楼";point[13].remarks[0]="正对南大门，里";point[13].remarks[1]="有各种办事处";point[13].num=13;point[13].ename="NYL";
	point[14].x=350;point[14].y=742;point[14].name="西十二";point[14].remarks[0]="全亚洲最大的教";point[14].remarks[1]="学楼";point[14].num=14;point[14].ename="XSE";
	 //校门
	point[15].x=1177;point[15].y=890;point[15].name="南四门";point[15].remarks[0]="内有光谷体育馆";point[15].remarks[1]="靠近南大门";point[15].num=15;point[15].ename="NSM";
	point[16].x=1955;point[16].y=890;point[16].name="东小门";point[16].remarks[0]="出门左拐为邮局";point[16].remarks[1]="靠近东大门";point[16].num=16;point[16].ename="DXM";
	point[17].x=707;point[17].y=890;point[17].name="南大门";point[17].remarks[0]="华科的正门，里";point[17].remarks[1]="有毛爷爷雕像";point[17].num=17;point[17].ename="NDM";
	point[18].x=467;point[18].y=890;point[18].name="南二门";point[18].remarks[0]="靠近光谷广场";point[18].remarks[1]="左边靠近南大门";point[18].num=18;point[18].ename="NEM";
	point[19].x=370;point[19].y=890;point[19].name="南三门";point[19].remarks[0]="里有西十二，正";point[19].remarks[1]="对湖北中医院";point[19].num=19;point[19].ename="NSHM";
	//其他
	point[20].x=1955;point[20].y=462;point[20].name="东图书馆";point[20].remarks[0]="内有自习室，藏";point[20].remarks[1]="书量较大";point[20].num=20;point[20].ename="DTSG";
	point[21].x=600;point[21].y=471;point[21].name="主图书馆";point[21].remarks[0]="藏书量大，附近";point[21].remarks[1]="有科技楼";point[21].num=21;point[21].ename="ZTSG";
	point[22].x=743;point[22].y=140;point[22].name="集贸市场";point[22].remarks[0]="各种生活必需品";point[22].remarks[1]="出售，价格便宜";point[22].num=22;point[22].ename="JMSC";
	point[23].x=600;point[23].y=558;point[23].name="校史馆";point[23].remarks[0]="为迎接六十年校";point[23].remarks[1]="庆而建";point[23].num=23;point[23].ename="XSG";
	point[24].x=1180;point[24].y=140;point[24].name="喻园小区";point[24].remarks[0]="主要是教师居住";point[24].remarks[1]="区，后有瑜伽山";point[24].num=24;point[24].ename="YYXQ";
	//过渡节点
	point[25].x=467;point[25].y=742;point[25].name="十字路口";point[25].remarks[0]="人流量较大，注";point[25].remarks[1]="意减速";point[25].num=25;point[25].ename=NULL;
	point[26].x=600;point[26].y=742;point[26].name="十字路口";point[26].remarks[0]="人流量较大，注";point[26].remarks[1]="意减速";point[26].num=26;point[26].ename=NULL;
	point[27].x=600;point[27].y=646;point[27].name="十字路口";point[27].remarks[0]="人流量较大，注";point[27].remarks[1]="意减速";point[27].num=27;point[27].ename=NULL;
	point[28].x=807;point[28].y=563;point[28].name="十字路口";point[28].remarks[0]="人流量较大，注";point[28].remarks[1]="意减速";point[28].num=28;point[28].ename=NULL;
	point[29].x=300;point[29].y=471;point[29].name="十字路口";point[29].remarks[0]="人流量较大，注";point[29].remarks[1]="意减速";point[29].num=29;point[29].ename=NULL;
	point[30].x=1955;point[30].y=289;point[30].name="十字路口";point[30].remarks[0]="人流量较大，注";point[30].remarks[1]="意减速";point[30].num=30;point[30].ename=NULL;
	point[31].x=2225;point[31].y=289;point[31].name="十字路口";point[31].remarks[0]="人流量较大，注";point[31].remarks[1]="意减速";point[31].num=31;point[31].ename=NULL;
	point[32].x=1540;point[32].y=140;point[32].name="十字路口";point[32].remarks[0]="人流量较大，注";point[32].remarks[1]="意减速";point[32].num=32;point[32].ename=NULL;
	point[33].x=600;point[33].y=140;point[33].name="十字路口";point[33].remarks[0]="人流量较大，注";point[33].remarks[1]="意减速";point[33].num=33;point[33].ename=NULL;
}
   /***init all point to make their distance MAX**/
void init_p(int num,double p[][SPOTNUM])          
{
	int i,j;
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			p[i][j]=MAX;
		}
	}
}
/*==================算出两个有确定标号的点，直接使p[a][b]=p[b][a]==============*/
     /******************this is to calculate the Adjacent point distance****************/
void init_distance(POINT a,POINT b,double p[][SPOTNUM])   
{
	p[a.num][b.num]=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	p[b.num][a.num]=p[a.num][b.num];
}

void  init_point_distance(double p_distance[][SPOTNUM], POINT *point)     
{
	init_p(SPOTNUM,p_distance);    //初始是使每个节点之间的距离为最大值
	init_distance(point[0],point[6],p_distance);
	init_distance(point[0],point[7],p_distance);
	init_distance(point[1],point[29],p_distance);
	init_distance(point[1],point[23],p_distance);
	init_distance(point[1],point[14],p_distance);
	init_distance(point[2],point[8],p_distance);
	init_distance(point[2],point[28],p_distance);
	init_distance(point[2],point[15],p_distance);
	init_distance(point[3],point[32],p_distance);
	init_distance(point[4],point[28],p_distance);
	init_distance(point[4],point[13],p_distance);
	init_distance(point[4],point[17],p_distance);
	init_distance(point[5],point[30],p_distance);
	init_distance(point[5],point[20],p_distance);
	init_distance(point[6],point[31],p_distance);
	init_distance(point[7],point[11],p_distance);
	init_distance(point[8],point[24],p_distance);
	init_distance(point[8],point[21],p_distance);
	init_distance(point[9],point[29],p_distance);
	init_distance(point[9],point[33],p_distance);
	init_distance(point[10],point[31],p_distance);
	init_distance(point[10],point[30],p_distance);
	init_distance(point[11],point[32],p_distance);
	init_distance(point[12],point[27],p_distance);
	init_distance(point[12],point[25],p_distance);
	init_distance(point[13],point[26],p_distance);
	init_distance(point[13],point[17],p_distance);
	init_distance(point[14],point[25],p_distance);
	init_distance(point[14],point[19],p_distance);
	init_distance(point[15],point[16],p_distance);
	init_distance(point[15],point[17],p_distance);
	init_distance(point[16],point[20],p_distance);
	init_distance(point[17],point[26],p_distance);
	init_distance(point[17],point[18],p_distance);
	init_distance(point[18],point[19],p_distance);
	init_distance(point[18],point[25],p_distance);
	init_distance(point[21],point[33],p_distance);
	init_distance(point[21],point[23],p_distance);
     init_distance(point[21],point[29],p_distance);
     init_distance(point[22],point[33],p_distance);
     init_distance(point[22],point[24],p_distance);
     init_distance(point[23],point[28],p_distance);
     init_distance(point[23],point[27],p_distance);
     init_distance(point[24],point[32],p_distance);
     init_distance(point[25],point[26],p_distance);
     init_distance(point[26],point[27],p_distance);
}

/*=====the function is used to init the information of point include the coordinate and the relatioship of all points=====*/
void init_point_info(POINT point[SPOTNUM], double p_distance[][SPOTNUM])
{
	init_point(point);
	init_point_distance(p_distance, point);
}
