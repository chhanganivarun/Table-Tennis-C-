
#ifdef Open_Header
#error You requested to open header file
#endif


#ifndef __cplusplus
#error Must use C++ for type t_vii.
#endif

#ifndef T_VII_H
#define T_VII_H

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<complex.h>
#include<graphics.h>
#include<ctype.h>
#include<dos.h>
#include<iomanip.h>
#include<time.h>

void rect(int x,int y,int col)
{
	setfillstyle(1,bgcol);
	rectangle(x+56,y+5,x+156,y+20);
	floodfill(x+100,y+10,WHITE);
	setfillstyle(1,WHITE);

	setfillstyle(1,col);
	rectangle(x+56,y+5,x+156,y+20);
	floodfill(x+100,y+10,WHITE);
	setfillstyle(1,WHITE);

}
void set(int,int &,int &,int &);
void CheckLevel(int & ,float & , float & ,float & );
void MainMenu();
void MainMenuset();
void OptSet(int *a);
int Options();
void opt(int oy,int col=bgcol);
int scorep=0,scorec=0;
int tri=0;
time_t bi,bf,i;

void plate(int ,int );
void ball(int ,int );

void startup()
{
	fstream fio;
	fio.open("TT.DBF",ios::in|ios::out|ios::ate|ios::nocreate);
	if(!fio)
	{
		fio.open("TT.DBF",ios::in|ios::out|ios::ate);
		fio<<bgcol<<'\n'<<bcol<<'\n'<<ppcol<<'\n'<<cpcol<<'\n'<<ocol;
	}
	else
	{
		fio.seekg(0);
		char ch;
//		cout<<bgcol<<"\n"<<bcol<<"\n"<<ppcol<<"\n"<<cpcol<<"\n"<<ocol<<"\n";
		fio>>bgcol;
		fio.get(ch);
		fio>>bcol;
		fio.get(ch);
		fio>>ppcol;
		fio.get(ch);
		fio>>cpcol;
		fio.get(ch);
		fio>>ocol;
//		cout<<bgcol<<"\n"<<ch<<"\n"<<bcol<<"\n"<<ch<<"\n"<<ppcol<<"\n"<<ch<<"\n"<<cpcol<<"\n"<<ch<<"\n"<<ocol;
//		getch();
	}
	fio.close();
}
void endup()
{
closegraph();
exit(0);
}
void reset()
{
	setbkcolor(bgcol);
	tri=0;
	level=1;
	scorep=0;
	scorec=0;
	bx=getmaxx()/2 ;
	by=getmaxy()-120 ;
	cx=getmaxx()/2;
	x=getmaxx()/2;
}
void plate(int x,int type)
{

if(type==1)
	{
	setfillstyle(1,ppcol);
	rectangle(x-50,getmaxy()-75,x+50,getmaxy()-90);
	floodfill(x,getmaxy()-80,WHITE);
	setfillstyle(1,WHITE);
	}
if(type==2)
	{
	setfillstyle(1,cpcol);
	rectangle(x-50,75,x+50,90);
	floodfill(x,80,WHITE);
	setfillstyle(1,WHITE);
	}
}
void plate(int x1,int x2,int rem)
{
	setfillstyle(1,bgcol);
	setcolor(bgcol);
	floodfill(x1,getmaxy()-80,WHITE);
	floodfill(x2,80,WHITE);
	rectangle(x1-50,getmaxy()-75,x1+50,getmaxy()-90);
	rectangle(x2-50,75,x2+50,90);
	setcolor(WHITE);
	setfillstyle(1,WHITE);
	if(rem);
}
void WinCrackers()
{
	setbkcolor(bgcol);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	while(!kbhit())
	{
		int f1x=random(360),f1y=random(120);
		int f2x=random(360),f2y=random(120);
		for(int m=0;m<=50;m++)
		{
			setcolor(ocol);
			settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
			outtextxy(getmaxx()/2-100,getmaxy()/2-20,"CONGRATULATIONS");
			outtextxy(getmaxx()/2-50,getmaxy()/2,"YOU WON");
			outtextxy((getmaxx()/2)-80,getmaxy()/2+20,"THE GAME ! ! !");
			setcolor(random(15));
			circle(f1x+120,f1y+120,m);
			setcolor(random(15));
			circle(f2x+120,f2y+120,m-10);
			delay(10);
			setcolor(bgcol);
			circle(f1x+120,f1y+120,m);
			circle(f2x+120,f2y+120,m-10);
			setcolor(WHITE);
		}
	}
}
void ball(int bx,int  by)
{
setfillstyle(1,bcol);
circle(bx,by,10);
floodfill(bx,by,WHITE);
setfillstyle(1,WHITE);
}
void clearball()
{
	setfillstyle(1,bgcol);
	floodfill(bx,by,WHITE);
	setcolor(bgcol);
	circle(bx,by,10);
	setcolor(WHITE);
	setfillstyle(1,WHITE);

}
void set(int bx,float &cx,float &cs,int &level)
{
	char li[100],ll[100];

	setcolor(ocol);
	sprintf(li,"Score :  %d (You) : %d (Computer)",scorep,scorec);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	sprintf(ll,"LEVEL : %d",level);
	outtextxy((getmaxx()/2)-53,50,ll);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy((getmaxx()/2)-200,getmaxy()-50,li);

	line(1,1,1,getmaxy());
	line(1,1,getmaxx(),1);
	line(getmaxx(),1,getmaxx(),getmaxy());
	line(1,getmaxy(),getmaxx(),getmaxy());

	if(cx>bx)
	{
		plate(x,cx,1);
		cx-=abs(cs);
		plate(x,1);
		plate(cx,2);
	}
	else if(cx<bx)
	{
		plate(x,cx,1);
		cx+=abs(cs);
		plate(x,1);
		plate(cx,2);
	}
}
void check(int &bx,int &by,float &xs,float &ys,int &x,float &cx,float &cs,int &level)
{
	if((bx>=x-60&&bx<=x+60)&&(by>getmaxy()-110&&by<getmaxy()-90))
	{
		ys=-ys;
		clearball();
		by=getmaxy()-112;
	}
	if(bx-10<=0)
	{clearball();xs=-xs;bx=11;}
	if(bx+10>=getmaxx())
	{clearball();xs=-xs;bx=getmaxx()-11;}
if(by-10<=0)
{
	scorep++;
	if(scorep>=3)
	{
	setbkcolor(bgcol);
	set(bx,cx,cs,level);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	setcolor(ocol);
	outtextxy(getmaxx()/2-50,getmaxy()/2,"YOU WIN");
	setcolor(WHITE);
	tri=0;
	level++;
	if(level>=6)
	{
	cleardevice();
	WinCrackers();
	reset();
	CheckLevel(level,cs,xs,ys);
	plate(x,1);
	plate(cx,2);
	ball(bx,by);
	//check(bx,by,xs,ys,x,cx,cs,level);
	tri=0;
	set(bx,cx,cs,level);
	getch();
	MainMenu();
	cleardevice();
	CheckLevel(level,cs,xs,ys);
	set(bx,cx,cs,level);
	x=getmaxx()/2;
	plate(x,1);
	plate(cx,2);
	CheckLevel(level,cs,xs,ys);
	setbkcolor(bgcol);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2) ;
	setcolor(ocol);
	outtextxy(getmaxx()/2-60,getmaxy()/2-10,"TABLE TENNIS");
	setcolor(WHITE);
	getch();
	cleardevice();

	}
	getch();
	scorep=0;
	scorec=0;
	CheckLevel(level,cs,xs,ys);
	}
	cleardevice();
	bx=getmaxx()/2;
	by=120;
	x=getmaxx()/2;
	cx=getmaxx()/2;
	plate(x,1);
	plate(cx,2);
	ball(bx,by);
	set(bx,cx,cs,level);
	setbkcolor(bgcol);
	setcolor(ocol);
	outtextxy(getmaxx()/2-50,getmaxy()/2,"READY???");
	setcolor(WHITE);
	getch();
	cleardevice();
	CheckLevel(level,cs,xs,ys);

}
if((bx>=cx-60&&bx<=cx+60)&&(by<=110&&by>=90))
	{
	ys=-ys;
	clearball();
	by=112;
	}
if(by+10>=getmaxy())
{
	scorec++;
	if(scorec>=3)
	{
	set(bx,cx,cs,level);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	setbkcolor(bgcol);
	setcolor(ocol);
	outtextxy(getmaxx()/2-50,getmaxy()/2,"YOU LOSE");
	setcolor(WHITE);
	if(tri<2)
	getch();
	CheckLevel(level,cs,xs,ys);
	scorec=0;
	scorep=0;
	tri++;
	if(tri>=3)
	{
	if(level>1)
	{level--;
	setcolor(ocol);
	outtextxy(getmaxx()/2-120,getmaxy()/2+20,"YOU FAILED TO CLEAR LEVEL");
	outtextxy(getmaxx()/2-40,getmaxy()/2-20,"LEVEL--;");
	setcolor(WHITE);
	getch();
	tri=0;
	cleardevice();
	}

	else
	{
	setbkcolor(bgcol);
	setcolor(ocol);
	outtextxy(getmaxx()/2-50,getmaxy()/2-20,"GAME OVER");
	setcolor(WHITE);
	getch();
	reset();
	MainMenu();
	}
	}
	}
	cleardevice();
	bx=getmaxx()/2;
	by=getmaxy()-120;
	x=getmaxx()/2;
	cx=getmaxx()/2;
	plate(x,1);
	plate(cx,2);
	ball(bx,by);
	set(bx,cx,cs,level);
	setcolor(ocol);
	outtextxy(getmaxx()/2-50,getmaxy()/2,"READY???");
	setcolor(WHITE);
	CheckLevel(level,cs,xs,ys);
	getch();
	cleardevice();
}
//cout<<xs<<endl<<ys;
}
void getlevel(int &level)
{
	cleardevice();
	gotoxy(25,20);
	cout<<"START FROM LEVEL(1 to 5):";
	char ch;
	ch=getche();
	level=ch-48;
	level%=5;
	if(level<0)
	level=-level;
	if(level==0)
	level=5;
}
void CheckLevel(int &level,float &cs, float &xs,float &ys)
{
int ss;
srand((unsigned)time(&i));
if(level==1)
ss=2;
else
ss=(level+1);

ys=(ss+level/2.5+1.2*sqrt(abs(2*scorep*scorep-scorec*scorep-tri*scorep)));
xs=(ss+level/2+sqrt(abs(2*scorep*scorep-scorec*scorep-tri*scorep)));
xs=(rand()%2)?-xs:xs;
cs=abs(xs);
cs-=0.4+(rand()%10000)/100000;

}
void MainMenu()
{
	char move;
	int oy=130;
	btm:
	cleardevice();
	MainMenuset();
	opt(oy,ocol);
	for(;;)
	{
		move=getch();
		if(move=='w'||move=='W'||move=='a'||move=='A'||move==72||move==75)
		{
			opt(oy,bgcol);
			if(oy>130)
			{
				oy-=30;
				MainMenuset();
				opt(oy,ocol);
			}
			else
			{
				oy=250;
				MainMenuset();
				opt(oy,ocol);
			}
		}
		else if(move=='s'||move=='S'||move=='D'||move=='d'||move==80||move==77)
		{
			opt(oy,bgcol);
			if(oy<250)
			{
				oy+=30;
				MainMenuset();
				opt(oy,ocol);
			}
			else
			{
				oy=130;
				MainMenuset();
				opt(oy,ocol);
			}
		}
		else if(move==13)
		{
			if(oy==250)
			{
				nosound();
				endup();
			}
			else if(oy==190)
			{
				cleardevice();
				gotoxy(1,1);
				cout    <<"THIS IS TABLE TENNIS v.7 completely made and designed by VARUN CHHANGANI\n"
					<<"ANY CORRELATION WITH ANY OTHER GAME NOT DESIGNED BY SOFTECH INC. IS FULLY \nCOINCIDENTIAL";
				gotoxy(1,20);
				cout	<<"press any key to continue";
				getch();
				setcolor(WHITE);
				goto btm;
			}
			else if(oy==220)
			{
				cleardevice();
				gotoxy(1,1);
				cout    <<"WELCOME TO TABLE TENNIS\n"
					<<"THIS GAME IS QUITE EASY,YOUR MAIN OBJECTIVE IS TO AVOID THE  BALL FALL BELOW THE LOWER PLATE THAT IS CONTROLLED BY YOU.\n"
					<<"YOU CAN CONTROL THE PLATE BY USING \'A\' OR Left Arrow Key (TO MOVE LEFT) AND \'D\' OR Right Arrow Key (TO MOVE RIGHT)\n"
					<<"ALSO TRY THAT THE BALL FALLS IN COMPUTER'S COURT (i.e. BELOW COMPUTER'S PLATE)\n"
					<<"THE GAME HAS  5 LEVELS AS THE LEVEL INCREASES THE SPEED OF BALL AND  COMPUTER'S PLATE INCREASES\n"
					<<"BY THE COURSE OF GAME IN ANY LEVEL YOU LOSE MORE THAN THREE TIMES YOU WOULD BE \nDOWNGRADED TO LOWER LEVEL\n"
					<<"LETS SEE HOW MUCH YOU WIN!!!\n"
					<<"HAPPY GAMING! ENJOY THE GAME!\n";
				gotoxy(1,20);
				cout	<<"press any key to continue";
				getch();
				setcolor(WHITE);

				goto btm;
			}
			else if(oy==130)
			{
					cleardevice();
					getlevel(level);
					goto start;
			}
			else if(oy==160)
			{
					cleardevice();
					Options();
					goto btm;
			}
		}
	}
	start:
	cleardevice();
}
int Options()
{
	int a[5];
	a[0]=bgcol;
	a[1]=bcol;
	a[2]=ppcol;
	a[3]=cpcol;
	a[4]=ocol;
	char move;
	int oy=100;
	for(;;)
	{
		OptSet(a);
		opt(oy,ocol);

		move=getch();
		if(move=='w'||move=='W'||move==72)
		{
			opt(oy,bgcol);

			if(oy>100)
			{
				oy-=30;
				OptSet(a);
				opt(oy,ocol);
			}
			else
			{
				oy=280;
				OptSet(a);
				opt(oy,ocol);
			}
		}

		else if(move=='a'||move=='A'||move==75)
		{
			if(oy<=220&&a[((oy-100)/30)]==15)
				cleardevice();

			if(oy==100)
			{
				a[0]+=8;
				a[0]=(--a[0])%8;
				if(a[0]==a[4]||a[0]==0)
					a[0]--;
				a[0]+=8;
				a[0]%=8;
				if(a[0]==a[4]||a[0]==0)
					a[0]--;
				a[0]+=8;
				a[0]%=8;
			}
			else if(oy==130)
			{
				a[1]+=16;
				a[1]=(a[1]-1)%16;
				if(a[1]==15)
					a[1]--;
				a[1]+=16;
				a[1]%=16;
			}
			else if(oy==160)
				a[2]=(a[2]-1+16)%16;
			else if(oy==190)
				a[3]=(a[3]-1+16)%16;
			else if(oy==220)
			{
				a[4]=(--a[4]+16)%16;
				if(a[4]==a[0])
					a[4]--;
				a[4]+=16;
				a[4]%=16;
			}

			;
		}
		else if(move=='d'||move=='D'||move==77)
		{

			if(oy<=220&&a[((oy-100)/30)]==15)
				cleardevice();

			if(oy==100)
			{
				a[0]=(++a[0])%8;
				if(a[0]==a[4]||a[0]==0)
					a[0]++;
				a[0]=a[0]%8;
				if(a[0]==a[4]||a[0]==0)
					a[0]++;
				//a[0]+=8;
				a[0]%=8;
			}
			else if(oy==130)
			{
				//a[1]+=16;
				a[1]=(a[1]+1)%16;
				if(a[1]==15)
					a[1]++;
				//a[1]+=16;
				a[1]%=16;
			}
			else if(oy==160)
				a[2]=(a[2]+1)%16;
			else if(oy==190)
				a[3]=(a[3]+1)%16;
			else if(oy==220)
			{
				//e+=16;
				a[4]=(++a[4])%16;
				if(a[0]==a[4])
					a[4]++;
				//e+=16;
				a[4]%=16;
			}

		}
		else if(move=='s'||move=='S'||move==80)
		{
			opt(oy,bgcol);
			if(oy<280)
			{
				oy+=30;
				OptSet(a);
				opt(oy,ocol);
			}
			else
			{
				oy=100;
				OptSet(a);
				opt(oy,ocol);
			}
		}

		else if(move==13)
		{
			if(oy==280)
			{
				bgcol=a[0];
				bcol=a[1];
				ppcol=a[2];
				cpcol=a[3];
				ocol=a[4];
				remove("TT.DBF");
				startup();
				return 0;
			}
			else if(oy==250)
			{
				a[0]=5;
				a[1]=14;
				a[2]=1;
				a[3]=4;
				a[4]=15;
			}

		}


	}
}
void OptSet(int *a)
{

setbkcolor(bgcol);
setcolor(ocol);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,4);
outtextxy((getmaxx()/2)-50,40,"Options");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
char ll[100];
sprintf(ll," %c               %c",17,16);
outtextxy(10,100,"Background Colour:");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(getmaxx()/2-65,110,ll);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
outtextxy(10,130,"Ball Colour:");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(getmaxx()/2-65,140,ll);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
outtextxy(10,160,"Player Paddle Colour:");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(getmaxx()/2-65,170,ll);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
outtextxy(10,190,"Comp. Paddle Colour:");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(getmaxx()/2-65,200,ll);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
outtextxy(10,220,"Fonts Colour:");
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(getmaxx()/2-65,230,ll);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
outtextxy((getmaxx()/2)-60,250,"Reset Defaults");
outtextxy((getmaxx()/2)-15,280,"BACK");

setcolor(WHITE);

rect(225,100,a[0]);
rect(225,130,a[1]);
rect(225,160,a[2]);
rect(225,190,a[3]);
rect(225,220,a[4]);

 ;
}
void MainMenuset()
{
setcolor(ocol);
setbkcolor(bgcol);
settextstyle(GOTHIC_FONT,HORIZ_DIR,4);
outtextxy((getmaxx()/2)-130,40,"TABLE TENNIS");
settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
outtextxy((getmaxx()/2)-20,130,"PLAY");
outtextxy((getmaxx()/2)-30,160,"OPTIONS");
outtextxy((getmaxx()/2)-30,190,"CREDITS");
outtextxy((getmaxx()/2)-60,220,"INSTRUCTIONS");
outtextxy((getmaxx()/2)-20,250,"EXIT");
setcolor(WHITE);
}
void opt (int oy,int col)
{
setcolor(col);
rectangle(getmaxx()/2-70,oy,getmaxx()/2+85,oy+25);
setcolor(WHITE);
}
#endif