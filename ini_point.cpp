#include"all.h"
#include"stru.h"
#include"public.h"
#include"hong.h"

void init_point(POINT point[SPOTNUM])    //�����ǳ�ʼ���ڵ������������ţ�����������,���ƣ�Ӣ������ĸ��д
{
	//����Ϊѧ����Ԣ
	point[0].x=2000;point[0].y=140;point[0].name="��Է��Ԣ";point[0].remarks[0]="��Ҫ��ס��У��";point[0].remarks[1]="ѧ��";point[0].num=0;point[0].ename="YYGY";
	point[1].x=310;point[1].y=563;point[1].name="���¹�Ԣ";point[1].remarks[0]="��Ҫ��ס��У��";point[1].remarks[1]="ѧ��";point[1].num=1;point[1].ename="ZSGY";
	point[2].x=1177;point[2].y=563;point[2].name="��Է��Ԣ";point[2].remarks[0]="��Ҫ��ס��У��";point[2].remarks[1]="ѧ��";point[2].num=2;point[2].ename="QYGY";
	point[3].x=1540;point[3].y=20;point[3].name="��ʿ��Ԣ";point[3].remarks[0]="��Ҫ��ס��ʿ��";point[3].remarks[1]="��������";point[3].num=3;point[3].ename="BSGY";
	point[4].x=807;point[4].y=742;point[4].name="�о�����Ԣ";point[4].remarks[0]="��Ҫ��ס�о���";point[4].remarks[1]="���Ϊ���������";point[4].num=4;point[4].ename="YJSGY";
	//ʳ��
	point[5].x=1955;point[5].y=413;point[5].name="ѧһʳ��";point[5].remarks[0]="����ʳ�ã�����";point[5].remarks[1]="�ж�ʮ��";point[5].num=5;point[5].ename="XYST";
	point[6].x=2220;point[6].y=140;point[6].name="��԰ʳ��";point[6].remarks[0]="ѧ��ʳ�ã�һ¥";point[6].remarks[1]="�Ϲ�";point[6].num=6;point[6].ename="DYST";
	point[7].x=1898;point[7].y=140;point[7].name="��Էʳ��";point[7].remarks[0]="ѧ��ʳ�ã�����";point[7].remarks[1]="Ӫҵʱ�䳤";point[7].num=7;point[7].ename="YYST";
	point[8].x=1177;point[8].y=473;point[8].name="����ʳ��";point[8].remarks[0]="��Է�������۸�";point[8].remarks[1]="����";point[8].num=8;point[8].ename="DSST";
	point[9].x=240;point[9].y=140;point[9].name="�پ�԰";point[9].remarks[0]="ʳ��Ʒ�ֶ࣬��";point[9].remarks[1]="��ϸ�";point[9].num=9;point[9].ename="BJY";
	//��ѧ¥
	point[10].x=2088;point[10].y=289;point[10].name="��ʮ��";point[10].remarks[0]="��У��ѧ������";point[10].remarks[1]="Ҫ��ѧ¥";point[10].num=10;point[10].ename="DSE";
	point[11].x=1650;point[11].y=140;point[11].name="����¥";point[11].remarks[0]="ǰ��С��������";point[11].remarks[1]="�ǻ��Ƹ���";point[11].num=11;point[11].ename="DJL";
	point[12].x=467;point[12].y=646;point[12].name="����¥";point[12].remarks[0]="��Ҫ������γ�";point[12].remarks[1]="��ѧ¥";point[12].num=12;point[12].ename="XWL";
	point[13].x=707;point[13].y=742;point[13].name="��һ¥";point[13].remarks[0]="�����ϴ��ţ���";point[13].remarks[1]="�и��ְ��´�";point[13].num=13;point[13].ename="NYL";
	point[14].x=350;point[14].y=742;point[14].name="��ʮ��";point[14].remarks[0]="ȫ�������Ľ�";point[14].remarks[1]="ѧ¥";point[14].num=14;point[14].ename="XSE";
	 //У��
	point[15].x=1177;point[15].y=890;point[15].name="������";point[15].remarks[0]="���й��������";point[15].remarks[1]="�����ϴ���";point[15].num=15;point[15].ename="NSM";
	point[16].x=1955;point[16].y=890;point[16].name="��С��";point[16].remarks[0]="�������Ϊ�ʾ�";point[16].remarks[1]="����������";point[16].num=16;point[16].ename="DXM";
	point[17].x=707;point[17].y=890;point[17].name="�ϴ���";point[17].remarks[0]="���Ƶ����ţ���";point[17].remarks[1]="��ëүү����";point[17].num=17;point[17].ename="NDM";
	point[18].x=467;point[18].y=890;point[18].name="�϶���";point[18].remarks[0]="������ȹ㳡";point[18].remarks[1]="��߿����ϴ���";point[18].num=18;point[18].ename="NEM";
	point[19].x=370;point[19].y=890;point[19].name="������";point[19].remarks[0]="������ʮ������";point[19].remarks[1]="�Ժ�����ҽԺ";point[19].num=19;point[19].ename="NSHM";
	//����
	point[20].x=1955;point[20].y=462;point[20].name="��ͼ���";point[20].remarks[0]="������ϰ�ң���";point[20].remarks[1]="�����ϴ�";point[20].num=20;point[20].ename="DTSG";
	point[21].x=600;point[21].y=471;point[21].name="��ͼ���";point[21].remarks[0]="�������󣬸���";point[21].remarks[1]="�пƼ�¥";point[21].num=21;point[21].ename="ZTSG";
	point[22].x=743;point[22].y=140;point[22].name="��ó�г�";point[22].remarks[0]="�����������Ʒ";point[22].remarks[1]="���ۣ��۸����";point[22].num=22;point[22].ename="JMSC";
	point[23].x=600;point[23].y=558;point[23].name="Уʷ��";point[23].remarks[0]="Ϊӭ����ʮ��У";point[23].remarks[1]="�����";point[23].num=23;point[23].ename="XSG";
	point[24].x=1180;point[24].y=140;point[24].name="��԰С��";point[24].remarks[0]="��Ҫ�ǽ�ʦ��ס";point[24].remarks[1]="���������٤ɽ";point[24].num=24;point[24].ename="YYXQ";
	//���ɽڵ�
	point[25].x=467;point[25].y=742;point[25].name="ʮ��·��";point[25].remarks[0]="�������ϴ�ע";point[25].remarks[1]="�����";point[25].num=25;point[25].ename=NULL;
	point[26].x=600;point[26].y=742;point[26].name="ʮ��·��";point[26].remarks[0]="�������ϴ�ע";point[26].remarks[1]="�����";point[26].num=26;point[26].ename=NULL;
	point[27].x=600;point[27].y=646;point[27].name="ʮ��·��";point[27].remarks[0]="�������ϴ�ע";point[27].remarks[1]="�����";point[27].num=27;point[27].ename=NULL;
	point[28].x=807;point[28].y=563;point[28].name="ʮ��·��";point[28].remarks[0]="�������ϴ�ע";point[28].remarks[1]="�����";point[28].num=28;point[28].ename=NULL;
	point[29].x=300;point[29].y=471;point[29].name="ʮ��·��";point[29].remarks[0]="�������ϴ�ע";point[29].remarks[1]="�����";point[29].num=29;point[29].ename=NULL;
	point[30].x=1955;point[30].y=289;point[30].name="ʮ��·��";point[30].remarks[0]="�������ϴ�ע";point[30].remarks[1]="�����";point[30].num=30;point[30].ename=NULL;
	point[31].x=2225;point[31].y=289;point[31].name="ʮ��·��";point[31].remarks[0]="�������ϴ�ע";point[31].remarks[1]="�����";point[31].num=31;point[31].ename=NULL;
	point[32].x=1540;point[32].y=140;point[32].name="ʮ��·��";point[32].remarks[0]="�������ϴ�ע";point[32].remarks[1]="�����";point[32].num=32;point[32].ename=NULL;
	point[33].x=600;point[33].y=140;point[33].name="ʮ��·��";point[33].remarks[0]="�������ϴ�ע";point[33].remarks[1]="�����";point[33].num=33;point[33].ename=NULL;
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
/*==================���������ȷ����ŵĵ㣬ֱ��ʹp[a][b]=p[b][a]==============*/
     /******************this is to calculate the Adjacent point distance****************/
void init_distance(POINT a,POINT b,double p[][SPOTNUM])   
{
	p[a.num][b.num]=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	p[b.num][a.num]=p[a.num][b.num];
}

void  init_point_distance(double p_distance[][SPOTNUM], POINT *point)     
{
	init_p(SPOTNUM,p_distance);    //��ʼ��ʹÿ���ڵ�֮��ľ���Ϊ���ֵ
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
