
//#define Open_Header

char move;
int bx,by,level;
float ys;
float xs;
int x;
float cx;
float cs;
int bgcol=5;
int bcol=14;
int ppcol;//player Paddle
int cpcol;//Comp. Paddle
int ocol;//selection box col

#include<t_vii.h>



void main()
{

ppcol=1;
cpcol=4;
ocol=15;
startup();

int gd=EGA,gm=EGAHI;
initgraph(&gd,&gm,"C:\\TC\\bgi");
if(graphresult()!=grOk)
{
	cout<<"Can't Initialize Graph!!";
	exit(0);
}
reset();

settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
MainMenu();
CheckLevel(level,cs,xs,ys);
set(bx,cx,cs,level);
plate(x,1);
plate(cx,2);
setcolor(ocol);
setbkcolor(bgcol);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,2) ;
outtextxy(getmaxx()/2-60,getmaxy()/2-10,"TABLE TENNIS");
setcolor(WHITE);
getch();
cleardevice();

CheckLevel(level,cs,xs,ys);
plate(x,cx,1);
clearball();
plate(x,1);
plate(cx,2);
ball(bx,by);
set(bx,cx,cs,level);
delay(100);

for(;;)
	{
	//sound(random(500)+200);
	if(kbhit())
	{
	move=getch();
		if(move==27)
		{
			nosound();
			reset();
			CheckLevel(level,cs,xs,ys);
			ball(bx,by);
			check(bx,by,xs,ys,x,cx,cs,level);
			set(bx,cx,cs,level);
			MainMenu();
			cleardevice();
			x=getmaxx()/2;
			set(bx,cx,cs,level);
			CheckLevel(level,cs,xs,ys);
			setcolor(ocol);
			setbkcolor(bgcol);
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,2) ;
			outtextxy(getmaxx()/2-60,getmaxy()/2-10,"TABLE TENNIS");
			setcolor(WHITE);
			getch();
			cleardevice();
		}
		if(move=='a'||move=='A'||move==75)
		{
			plate(x,cx,1);
			clearball();
			if(x-79>0)
				x-=70;
			bx+=xs;
			by+=ys;
			ball(bx,by);
			check(bx,by,xs,ys,x,cx,cs,level);
			set(bx,cx,cs,level);
		}
		if(move=='D'||move=='d'||move==77)
		{
			plate(x,cx,1);
			clearball();
			if(x+79<getmaxx())
				x+=70;
			bx+=xs;
			by+=ys;
			ball(bx,by);
			check(bx,by,xs,ys,x,cx,cs,level);
			set(bx,cx,cs,level);
		}
	}

	else if(!kbhit())
	{
	clearball();
	bx+=xs;
	by+=ys;
	ball(bx,by);
	check(bx,by,xs,ys,x,cx,cs,level);
	set(bx,cx,cs,level);
	delay(10);
	}
	}
}
