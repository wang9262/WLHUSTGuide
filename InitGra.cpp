#include "all.h"
void InitGra(int model)
{
	int GraphDriver,GraphMode;
	GraphDriver = VGA;
	switch(model)
	{
		
		case 350:
			          GraphMode =  VGAMED;//for cartoon,��ҳ����
			          break;   
		case 480:
			         GraphMode =  VGAHI;   
                        break;
          default:
                        break;			
	}
	initgraph(&GraphDriver,&GraphMode,"..\\all\\bgi");
	cleardevice();
}