#include<iostream>
#include <graphics.h>		// ���� EasyX ��ͼ��ͷ�ļ�
#include <conio.h>
#include<cmath>
#define MAX 8
#define WIDTH 640
#define WIDTH1 550
#define HEIGHT 480
#pragma comment(lib,"Winmm.lib")
int i;
int num=20;
struct fengtiao
{
int x;
int y;
}fengtiao;
struct fadan
{
int x;
int y;
int v;
}fadan;
struct touzi
{
int x;
int y;
int v;
}touzi;
struct money//������Ľṹ�壻
{
int x;
int y;
}money[MAX];
struct Box//x
{
int x;
int y;
int score; 
int ver;
}box;
IMAGE img[2];
IMAGE img2[2];
IMAGE img3[2];
IMAGE img4;
IMAGE img5[2];
IMAGE img6;
IMAGE img7;
IMAGE img8[2];
void jiemian()
{   
	loadimage(&img7, "./����2.jpg", 720, 480);
    MOUSEMSG m;//���
    cleardevice();
    putimage(0,0,&img7);
    settextcolor(YELLOW);
    settextstyle(70,0,_T("����"));
	setbkmode(TRANSPARENT);//�������뱳��
    outtextxy(200,50,_T("�󸻺�"));
    settextcolor(YELLOW);
    setfillcolor(BLUE);
    fillrectangle(200, 200, 420, 250);
    settextstyle(40,0,_T("����"));
    setbkmode(TRANSPARENT);
    outtextxy(230,200,_T("��ʼ��Ϸ"));
    while (1)
    {
        m = GetMouseMsg();
        if (m.x >=200 && m.x <= 420&& m.y >= 200 && m.y <= 250)
        {
            setlinecolor(RED);
            rectangle(200, 200, 420, 250);
            if (m.uMsg == WM_LBUTTONDOWN /*&& m.uMsg == WM_LBUTTONUP*/)//��갴�²�����
            {
                 
                break;
            }
        }
        else
        {
            //��겻�ڿ���ھ͸���֮ǰ����ɫ��
            setlinecolor(BLACK);
            rectangle(200, 200, 420, 250);
        }
    }
 
 
 
}
void chushihua()//��ʼ��
{   //��ʼ��С��
	for(i=0;i<MAX;i++)
	{
	money[i].x=(rand()%WIDTH1);
	money[i].y=-rand()%200;
	}//�����Ϸ���������
	//��ʼ��������
      fadan.x=(rand()%WIDTH1);
	  fadan.y=-rand()%200;
	  //��ʼ��Ͷ��
       touzi.x=(rand()%WIDTH1);
	   touzi.y=-rand()%200;
	   //��ʼ������
	   fengtiao.x=(rand()%WIDTH1);
	   fengtiao.y=-rand()%200;
     	//��ʼ������
       box.x= WIDTH/2-50;
	   box.y=HEIGHT-20;;
	   box.score=50;
	   box.ver=0;
	   fadan.v=0;
	   touzi.v=0;
       loadimage(&img[0],"./Ӳ��1.png",40,40);//����ǮͼƬ
	   loadimage(&img[1],"./Ӳ��2.png",40,40);
	   loadimage(&img2[0],"./��1.png",33,40);
	   loadimage(&img2[1],"./��2.png",33,40);
	   loadimage(&img3[0],"./Ͷ��1.png",40,40);
	   loadimage(&img3[1],"./Ͷ��2.png",40,40);
	   loadimage(&img4,"./�Ʋ�.jpg",648,480);
	   loadimage(&img5[0],"./����1.png",40,40);
	   loadimage(&img5[1],"./����2.png",40,40);
	   loadimage(&img6, "./����.jpg", 720, 480);
	   loadimage(&img8[0], "./����1.png", 150, 30);
		loadimage(&img8[1], "./����2.png", 150, 30);
}
void tuxing()//����С�򣬲����С��Ĺ켣��  
{
cleardevice();
putimage(0, 0, &img6);

for(i=0;i<MAX;i++)
{

	putimage(money[i].x,money[i].y,&img[0],SRCAND);//���С���ͼƬ
	putimage(money[i].x,money[i].y,&img[1],SRCPAINT);//���С���ͼƬ
}
putimage(fadan.x,fadan.y,&img2[1],SRCAND);
putimage(fadan.x,fadan.y,&img2[0],SRCPAINT);
putimage(touzi.x,touzi.y,&img3[0],SRCAND);
putimage(touzi.x,touzi.y,&img3[1],SRCPAINT);
putimage(fengtiao.x,fengtiao.y,&img5[0],SRCAND);
putimage(fengtiao.x,fengtiao.y,&img5[1],SRCPAINT);

//��С��
putimage(box.x,box.y,&img8[0],SRCAND);
putimage(box.x,box.y,&img8[1],SRCPAINT);
setbkmode(TRANSPARENT);//�������뱳��
char  arr[20]=" ";
settextstyle(30, 0, _T("����"));
sprintf(arr,"�ʲ�:%d",box.score);
outtextxy(10,450,arr);//ʹ����������ʾ
}   
void yidong()//ʵ��С�˵��˶�
{
     BeginBatchDraw();//
        if(GetAsyncKeyState(VK_LEFT))//����
	{
		if(box.x>=0)//
		{
	    	box.x-=(40-fadan.v+touzi.v+box.ver/num);
			FlushBatchDraw();
		}

	}
        if(GetAsyncKeyState(VK_RIGHT))//����
		{   
			if(box.x+100<=WIDTH)
			{
				box.x+=(40-fadan.v+touzi.v+box.ver/num);
				FlushBatchDraw();//
			}
			
	}
        for(i=0;i<MAX;i++)
		{
			money[i].y+=(10+box.ver/num);
		}
			fadan.y+=(12+box.ver/num);//�������䣻
			touzi.y+=(12+box.ver/num);
			fengtiao.y+=(12+box.ver/num);
			FlushBatchDraw();
		EndBatchDraw();	
}
void panduan()
{      
         for(i=0;i<MAX;i++)
{
		if((money[i].x+20)>box.x&&(money[i].x+20)<box.x+150&&(money[i].y+40)>box.y&&(money[i].y+40)<(box.y+30))
	{
		box.ver+=1;
		box.score+=10;
		money[i].y=0;
		money[i].x=rand()%WIDTH1;
	}
		else if(money[i].y>480)
		{ box.ver+=1;
		box.score-=5;
		money[i].y=0;
		money[i].x=rand()%WIDTH1;
	}
		if((fadan.x+15)>box.x&&(fadan.x+15)<box.x+150&&(fadan.y+40)>box.y&&(fadan.y+40)<(box.y+30))//�жϷ���
	{
		if(fadan.v<40) 
		{
			fadan.v+=5;
			box.score-=20;
		}
		fadan.y=0;
		fadan.x=rand()%WIDTH1;
	
	}
		else if(fadan.y>480)
		{
        fadan.y=0;
		fadan.x=rand()%WIDTH1;
		}
			if((touzi.x+20)>box.x&&(touzi.x+20)<box.x+150&&(touzi.y+40)>box.y&&(touzi.y+40)<(box.y+30))//�ж�Ͷ��
	{
		box.score+=20;
		touzi.v+=5;
		touzi.y=0;
		touzi.x=rand()%WIDTH1;
	
	}
		else if(touzi.y>480)
		{
        touzi.y=0;
		touzi.x=rand()%WIDTH1;
		}
		if((fengtiao.x+18)>box.x&&(fengtiao.x+18)<box.x+150&&(fengtiao.y+40)>box.y&&(fengtiao.y+40)<(box.y+30))//�жϷ���
	{
	      box.score-=10000;
	    fengtiao.y=0;
		fengtiao.x=rand()%WIDTH1;
	}
		else if(fengtiao.y>480)
	{
		box.score+=0;
	    fengtiao.y=0;
		fengtiao.x=rand()%WIDTH1;
	}
}

}
int main()
{   
	initgraph(WIDTH,HEIGHT);
	mciSendString(_T("open ����.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
    jiemian();
//setbkcolor(LIGHTBLUE);//������ɫ
//cleardevice();
	chushihua();
	tuxing();
	while(1)
	{
		yidong();
		tuxing();
		Sleep(50);
		panduan();
		if(box.score<=0)
		{
           putimage(0,0,&img4);
		   Sleep(3000);
		   break;
		}
	}
	mciSendString(_T("close bkmusic"), NULL, 0, NULL);
_getch();			// �����������
closegraph();			// �ر�ͼ�ν���
return 0;
}