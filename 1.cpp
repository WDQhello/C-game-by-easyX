#include<iostream>
#include <graphics.h>		// 引用 EasyX 绘图库头文件
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
struct money//掉落物的结构体；
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
	loadimage(&img7, "./背景2.jpg", 720, 480);
    MOUSEMSG m;//鼠标
    cleardevice();
    putimage(0,0,&img7);
    settextcolor(YELLOW);
    settextstyle(70,0,_T("隶书"));
	setbkmode(TRANSPARENT);//分数融入背景
    outtextxy(200,50,_T("大富豪"));
    settextcolor(YELLOW);
    setfillcolor(BLUE);
    fillrectangle(200, 200, 420, 250);
    settextstyle(40,0,_T("黑体"));
    setbkmode(TRANSPARENT);
    outtextxy(230,200,_T("开始游戏"));
    while (1)
    {
        m = GetMouseMsg();
        if (m.x >=200 && m.x <= 420&& m.y >= 200 && m.y <= 250)
        {
            setlinecolor(RED);
            rectangle(200, 200, 420, 250);
            if (m.uMsg == WM_LBUTTONDOWN /*&& m.uMsg == WM_LBUTTONUP*/)//鼠标按下并弹起
            {
                 
                break;
            }
        }
        else
        {
            //鼠标不在框框内就覆盖之前的绿色框
            setlinecolor(BLACK);
            rectangle(200, 200, 420, 250);
        }
    }
 
 
 
}
void chushihua()//初始化
{   //初始化小球
	for(i=0;i<MAX;i++)
	{
	money[i].x=(rand()%WIDTH1);
	money[i].y=-rand()%200;
	}//从最上方掉下来；
	//初始化罚单；
      fadan.x=(rand()%WIDTH1);
	  fadan.y=-rand()%200;
	  //初始化投资
       touzi.x=(rand()%WIDTH1);
	   touzi.y=-rand()%200;
	   //初始化封条
	   fengtiao.x=(rand()%WIDTH1);
	   fengtiao.y=-rand()%200;
     	//初始化盒子
       box.x= WIDTH/2-50;
	   box.y=HEIGHT-20;;
	   box.score=50;
	   box.ver=0;
	   fadan.v=0;
	   touzi.v=0;
       loadimage(&img[0],"./硬币1.png",40,40);//载入钱图片
	   loadimage(&img[1],"./硬币2.png",40,40);
	   loadimage(&img2[0],"./罚1.png",33,40);
	   loadimage(&img2[1],"./罚2.png",33,40);
	   loadimage(&img3[0],"./投资1.png",40,40);
	   loadimage(&img3[1],"./投资2.png",40,40);
	   loadimage(&img4,"./破产.jpg",648,480);
	   loadimage(&img5[0],"./封条1.png",40,40);
	   loadimage(&img5[1],"./封条2.png",40,40);
	   loadimage(&img6, "./背景.jpg", 720, 480);
	   loadimage(&img8[0], "./手掌1.png", 150, 30);
		loadimage(&img8[1], "./手掌2.png", 150, 30);
}
void tuxing()//画出小球，并清除小球的轨迹。  
{
cleardevice();
putimage(0, 0, &img6);

for(i=0;i<MAX;i++)
{

	putimage(money[i].x,money[i].y,&img[0],SRCAND);//输出小球的图片
	putimage(money[i].x,money[i].y,&img[1],SRCPAINT);//输出小球的图片
}
putimage(fadan.x,fadan.y,&img2[1],SRCAND);
putimage(fadan.x,fadan.y,&img2[0],SRCPAINT);
putimage(touzi.x,touzi.y,&img3[0],SRCAND);
putimage(touzi.x,touzi.y,&img3[1],SRCPAINT);
putimage(fengtiao.x,fengtiao.y,&img5[0],SRCAND);
putimage(fengtiao.x,fengtiao.y,&img5[1],SRCPAINT);

//画小人
putimage(box.x,box.y,&img8[0],SRCAND);
putimage(box.x,box.y,&img8[1],SRCPAINT);
setbkmode(TRANSPARENT);//分数融入背景
char  arr[20]=" ";
settextstyle(30, 0, _T("隶书"));
sprintf(arr,"资产:%d",box.score);
outtextxy(10,450,arr);//使分数居中显示
}   
void yidong()//实现小人的运动
{
     BeginBatchDraw();//
        if(GetAsyncKeyState(VK_LEFT))//左移
	{
		if(box.x>=0)//
		{
	    	box.x-=(40-fadan.v+touzi.v+box.ver/num);
			FlushBatchDraw();
		}

	}
        if(GetAsyncKeyState(VK_RIGHT))//右移
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
			fadan.y+=(12+box.ver/num);//罚单下落；
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
		if((fadan.x+15)>box.x&&(fadan.x+15)<box.x+150&&(fadan.y+40)>box.y&&(fadan.y+40)<(box.y+30))//判断罚单
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
			if((touzi.x+20)>box.x&&(touzi.x+20)<box.x+150&&(touzi.y+40)>box.y&&(touzi.y+40)<(box.y+30))//判断投资
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
		if((fengtiao.x+18)>box.x&&(fengtiao.x+18)<box.x+150&&(fengtiao.y+40)>box.y&&(fengtiao.y+40)<(box.y+30))//判断封条
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
	mciSendString(_T("open 背景.mp3 alias bkmusic"), NULL, 0, NULL);
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);
    jiemian();
//setbkcolor(LIGHTBLUE);//背景颜色
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
_getch();			// 按任意键继续
closegraph();			// 关闭图形界面
return 0;
}