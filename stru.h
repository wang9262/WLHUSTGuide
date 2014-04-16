/*=======================================================================
此文件定义一些画图用的结构体
========================================================================*/
#include"all.h"
#include"hong.h"
typedef  struct 
{
	double x;  //小车的位置
	double y;
	double xspeed;   //小车的水平速度
	double yspeed;   //水车的垂直速度
	double angle;     //小车转过的角度
}CAR;

typedef struct  
{
    int x;          //按钮左上角
    int y;          
    int x1;        // 按钮右下角
    int y1;
    char *name;
    int state;     //按钮状态，决定画按钮的函数
}BUTTON;

typedef  struct   //点的结构体，为地图上的每一个节点。设置了x,y,和点号，这是为了方便初始化距离
{
   double x;
   double y;
   char *name;  //各节点的名称
   char *remarks[2];//备注
   int num;
  char *ename;
}POINT;
typedef struct
{
  double map_xspeed;
  double map_yspeed;
}MAP;
/***道路的结构体***/
typedef struct        
{
  float x;
  float y;  
  float len;              //道路的横向长度
}STREET;
typedef struct    
{ 
  float x,y;
  float sf;
}LITTLE;


/*===============for button===========*/
void dr_button(BUTTON *bt,int color,int dis,int flag);
void dr_LPbutton(BUTTON *bt);
/*===============for draw  car======*/
void draw_car(CAR *cp);
/*===============for map  and car control=========*/
void car_control(CAR *cp,double *carspeed);
void map_ctrl(MAP *mp,CAR *cp,double *carspeed,int *map_first,double *map_speed,POINT *point,STREET all_street[18],
                    LITTLE all_tree[10],LITTLE m[5],LITTLE wp[5],LITTLE sp[3],
					LITTLE gp[3],LITTLE dp[5],LITTLE lap[3],LITTLE bip[5],LITTLE hp[10],LITTLE bicycle[3]);
/*=================for   main_page choose==========*/
void jxbuild(POINT point[SPOTNUM],int star_fini_flag,int *point1);
void dorm(POINT point[SPOTNUM],int star_fini_flag,int *point1);
void canteen(POINT point[SPOTNUM],int star_fini_flag,int *point1);
void sch_door(POINT point[SPOTNUM],int star_fini_flag,int *point1);
void other(POINT point[SPOTNUM],int star_fini_flag,int *point1);
/*==================================for init  point and map===================================*/
    /**********************point,pay attention to data types*********************/
void init_point(POINT point[SPOTNUM]);
void init_point_info(POINT point[SPOTNUM], double p_distance[][SPOTNUM]);
    /******************map with11 14 parameter**************/
void init_map(STREET street[18],LITTLE tree[10],LITTLE mp[5],LITTLE wp[5],LITTLE building[3],LITTLE playground[3],
                                   LITTLE door[5],LITTLE lake[3],LITTLE bigbuilding[5],LITTLE house[10],LITTLE bicycle[3]);
void second_init_map(int *center_x, int *center_y,POINT *point,STREET street[18],LITTLE  tree[10],LITTLE mp[5],LITTLE wp[5],LITTLE building[3],LITTLE playground[3],
                                   LITTLE door[5],LITTLE lake[3],LITTLE bigbuilding[5],LITTLE house[10],LITTLE bicycle[3]);
/*==============================draw map with 11 parameter================================*/							
void draw_map(STREET all_street[18],LITTLE all_tree[10],LITTLE all_people_m[5],
                       LITTLE all_people_w[5],LITTLE all_ninebuilding[3],LITTLE all_playground[3],
				   LITTLE all_small_door[5],LITTLE all_lake[3],LITTLE all_bigbuilding[5],LITTLE all_house[10],LITTLE all_bicycle[3]);

/*==========================================for main_page with struct========================================*/
double rest_distance(CAR *cp,POINT finish_point);   
void shortestpath(double p[][SPOTNUM], int n, double d[], int path[SPOTNUM], int s);
void draw_line(POINT a,POINT b,int thicness,int color);
void draw_point(POINT a[SPOTNUM] , int start_point, int finish_point);
void drawroutine(int s, int f,  POINT *point, int *path);
  /****************judgement****************/
void change_route(CAR *cp, POINT *point, int *start_point, int *finish_point, int path[SPOTNUM],int *flag_road_error);
int judge_finish(CAR *cp, POINT finish_point);
int judge_error(CAR *cp, POINT *point);
void judge_pre_car(CAR *cp, POINT *point);
int judge_point1(int a, int b[]);   
  /****************input start and final*****************/
void search(POINT point[SPOTNUM],int *flag_click_beg,int *start,int *finish);//just equals to mouse_ctrl()
void input(POINT point[SPOTNUM],int star_fina_flag,int *point1);
/*========================================for main_page with no struct================================*/
void right_plus();
void warning(double *map_speed, double *speed);
void show_distance(double *distance); 
void mouse_click();
void guidance_end(int x, int y); 
void s_help();
void c_help();
void choose(int star_fini_flag,int *point1);
void main_page(int *choice);
void show_sta_fin(char *str,int star_fini_flag);
void remark(char *str[2]);
void mouse_ctrl(int *flag_click_beg,int *start,int *finish);
