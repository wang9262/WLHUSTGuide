#include  "all.h"
void dis_hz (int x, int y,char *s,int flag,int part,int color)
{
	FILE *hzk_p;                                       //���庺�ֿ��ļ�ָ��
	unsigned char quma,weima;                 //���庺�ֵ������λ��
	unsigned long offset;                          //���庺�����ֿ��е�ƫ����
	unsigned char mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};  //�������飬������ʾ���ֵ����е�����
	int i,j,pos;
	
	switch (flag)    //��ͬ��flag��Ӧ��ͬ�ĺ��ֿ⣬ʵ���˺��ֵĴ�С�ɸ�����Ҫ�ı�
	{
		case 0 :
			      {
				     char mat[32];   //16*16�ĺ�����Ҫ32���ֽڵ��������洢
					int y0=y;
					 hzk_p = fopen("..\\all\\hzk\\hzk16","rb");            //ʹ�����·��
					 if(hzk_p==NULL) 
					 {
						outtextxy(10,10,"Can't open hzk16 file!Press any key to quit...");
						 getch();
						 exit(1);
						 
					}
					while(*s!=NULL)
					{
						//while (x<620 && (*s!=NULL))
						//{
							y=y0;
							quma=s[0]-0xa0;                      //�������
							weima=s[1]-0xa0;                     //���λ��
							offset=(94*(quma-1)+(weima-1))*32L;   //���Ҫ��ʾ�ĺ������ֿ��ļ��е�ƫ��
							fseek(hzk_p,offset,SEEK_SET);         //�ض�λ�ļ�ָ��
							fread (mat,32,1,hzk_p);            //�����ú��ֵľ����������,1ΪҪ����Ĵ���
							
							for(i=0;i<16;i++)             
							{
								pos=2*i;       //16*16��������ÿһ���������ֽ�
								for(j=0;j<16;j++)    //һ��һ�е�ɨ�裬��λ��Ϊ��1�ĵ���ʾ����
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)   //j%8ֻ����0��7֮��ѭ����j/8��0��1֮��ѭ��
									{
										putpixel(x+j,y,color);										
									}
									
								}
								y++;
				
								
							}
							/*====================================================
								������һ��������ʾ��
							====================================================*/
							x+=part;        //��x һ��ƫ����part
							s+=2;           //�������ŵ������룬2���ֽڣ�����Ҫ��2
							
						//}
						//x=20;y0+=30; //һ�к�����ʾ��󣬸�yһ��ƫ����
                         }
						
					break;	
						
				 }
		
		
		case 1 :
		          {
					char mat[72];   //24*24����Ҫ72���ֽ����洢
				     int y0=y;
					hzk_p = fopen("..\\all\\hzk\\hzk24f","rb");
					if (hzk_p==NULL)
					{
						outtextxy(10,10,"Can't open hzk24 file!Press any key to quit...");
						getch();
						exit(1);
						
					}
					while(*s!=NULL)
					{
						//while(x<620 && (*s!=NULL))
						//{
							y=y0;
							quma=s[0]-0xa0;                      //�������
							weima=s[1]-0xa0;                     //���λ��
							offset=(94*(quma-1)+(weima-1))*72L;
							fseek(hzk_p,offset,SEEK_SET);         
							fread (mat,72,1,hzk_p); 
							for (i=0;i<24;i++)
							{
								pos=3*i;   //������ÿһ���������ֽ�
								for (j=0;j<24;j++)   // ÿһ����24λ
								{
									if ((mask[j%8]&mat[pos+j/8])!=NULL)
										putpixel(x+j,y,color);
									
								}
								y++;
								
							}
							x+=part;
							s+=2;
						//}
						//x=35;y0=y0+40;
					}		
						break;
				}
				
		case 2 :
			      {
				     char mat[128];   //32*32�ĺ�����Ҫ128���ֽڵ��������洢
					int y0=y;
					 hzk_p = fopen("..\\all\\hzk\\hzk32k","rb");
					 if(hzk_p==NULL)
					 {
						outtextxy(10,10,"Can't open hzk32 file!Press any key to quit...");
						 getch();
						 exit(1);
						 
					}
					while(*s!=NULL)
					{
						//while (x<620 && (*s!=NULL))
						//{
							y=y0;
							quma=s[0]-0xa0;                      //�������
							weima=s[1]-0xa0;                     //���λ��
							offset=(94*(quma-1)+(weima-1))*128L;  
							fseek(hzk_p,offset,SEEK_SET);       
							fread (mat,128,1,hzk_p);            
							for(i=0;i<32;i++)             
							{
								pos=4*i;       //32*32��������ÿһ���������ֽ�
								for(j=0;j<32;j++)   
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)   
									{
										putpixel(x+j,y,color);
										
									}
									
								}
								y++;
				
								
							}
								//������һ��������ʾ��
							x+=part;    //��x һ��ƫ����part
							s+=2;          //�������ŵ������룬2���ֽڣ�����Ҫ��2
							
						//}
						//x=50;y0=y0+60;   //һ�к�����ʾ��󣬸�yһ��ƫ����
					}
						break;	
						
				 }
				 
		
		case 3:
		          {
					char mat[288];   //48*48�ĺ�����Ҫ288���ֽڵ��������洢
					int y0=y;
					 hzk_p = fopen("..\\all\\hzk\\hzk48k","rb");
					 if(hzk_p==NULL)
					 {
						outtextxy(10,10,"Can't open hzk48 file!Press any key to quit...");
						 getch();
						 exit(1);
						 
					}
					while(*s!=NULL)
					{
						//while (x<620 && (*s!=NULL))
						//{
							y=y0;
							quma=s[0]-0xa0;                      //�������
							weima=s[1]-0xa0;                     //���λ��
							offset=(94*(quma-1)+(weima-1))*288L;   //���Ҫ��ʾ�ĺ������ֿ��ļ��е�ƫ��
							fseek(hzk_p,offset,SEEK_SET);         //�ض�λ�ļ�ָ��
							fread (mat,288,1,hzk_p);            //�����ú��ֵľ����������,1ΪҪ���������
							
							for(i=0;i<48;i++)             
							{
								pos=6*i;       
								for(j=0;j<48;j++)    //һ��һ�е�ɨ�裬��λ��Ϊ��1�ĵ���ʾ����
								{
									if((mask[j%8]&mat[pos+j/8])!=NULL)   //j%8ֻ����0��8֮��ѭ����j/8��0��1֮��ѭ��
									{
										putpixel(x+j,y,color);
										
									}
									
								}
								y++;
							}
								//������һ��������ʾ��
							x+=part;    //��x һ��ƫ����part
							s+=2;          //�������ŵ������룬2���ֽڣ�����Ҫ��2
							
						//}
						//x=70;y0+=90;   //һ�к�����ʾ��󣬸�yһ��ƫ����
					}
						break;	
					
				}
				
		default: 
			      break;
		
	}
	fclose(hzk_p);
}