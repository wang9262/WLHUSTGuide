/*=======================for  hanzi=============*/
void dis_hz (int x, int y,char *s,int flag,int part,int color);
/*=======================for mouse===========*/

int initmouse(int xmi, int xma, int ymi, int yma);
void cursor(int x, int y);
void newmouse(int *mx, int*my, int*mbutt);  
/*===============for bar==========*/
void draw_bar(int x,int y,int x1,int y1,int color);  //cubic
void draw_bar1(int x,int y,int x1,int y1,int color);
/*=================for sound===============*/
void SOUND(unsigned frequency);
void NOSOUND();
/*=================for  interface========*/
void first_page();
void goodbye();
void m_page();
void m_choose(int *choice);//input or choose
void InitGra(int model);