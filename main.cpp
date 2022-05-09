

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>
#include <iostream>

using namespace std;
int currentX,currentY;
int yfor0,yfor1, l,m,a;
void draw0(int bin[10])
{delay(100);
//****NRZ-L encoding
    line(currentX,yfor0+27,(currentX+50), yfor0+27);
     outtextxy(currentX+20,yfor0-90,"0");
    line(currentX,100, currentX,739);


//****manchastre encoding
line(currentX,yfor1+160,currentX+25, yfor1+160);
line(currentX+25,370, currentX+25,470);
line(currentX+25,yfor1+260,currentX+50, yfor1+260);
//****differetial manchaster encoding
  line(currentX,370, currentX,470);
 line(currentX+25,530, currentX+25,670);

if(l==1)
{
 line(currentX,yfor1+320,currentX+25, yfor1+320);
 line(currentX+25,yfor1+460,currentX+50, yfor1+460);

a=2;
  }
  else if(l==2 ) {

  line(currentX+25,yfor1+320,currentX+50, yfor1+320);
  line(currentX,yfor1+460,currentX+25, yfor1+460);
  m=l;


  }
  currentX+=50;

}
void draw1(int bin[10])
{delay(100);
//****NRZ-L
  outtextxy(currentX+20,yfor1-40,"1");
 line(currentX,yfor1-20,currentX+50, yfor1-20);
 line(currentX,100, currentX,739);
//****manchaster encoding
 line(currentX,yfor1+260,currentX+25, yfor1+260);
  line(currentX,370, currentX,470);
 line(currentX+25,370, currentX+25,470);
 line(currentX+25,yfor1+160,currentX+50, yfor1+160);

//**** differential manchaster encoding
 line(currentX,460, currentX,460);
 line(currentX+25,530, currentX+25,670);
 //for(i=0;i<8;i++)
 {
if(a==1 )
{
 line(currentX,yfor1+320,currentX+25, yfor1+320);
  line(currentX+25,yfor1+460,currentX+50, yfor1+460);
l=1;
a++;
 }
else  if(a==2 )
 {

line(currentX,yfor1+460,currentX+25, yfor1+460);
line(currentX+25,yfor1+320,currentX+50, yfor1+320);
l++;

a--;

 }

}

    currentX+=50;

}
int main()
{
    int i;
    int gd = DETECT, gm;
    //initgraph(&gd, &gm, "");
    int bin[8],n;
    initwindow(580, 780);


    outtextxy(275,0,"LINE CODING GRAPH");
    yfor0=getmaxy()/3;
    yfor1=yfor0-50;
    currentX=100;
    currentY=yfor0;
//*******string part****//
    outtextxy(110,150,"NRZ-L");
    outtextxy(110,340,"manchaster encoding");
    outtextxy(110,490,"differential manchaster encoding");
//****NRZ unipolar voltage axis
    outtextxy(80,180,"+A");
    outtextxy(83,235,"0");
    outtextxy(83,283,"-A");

//****manchaster encoding voltage axis
    outtextxy(80,357,"+A");
    outtextxy(83,425,"0");
    outtextxy(83,457,"-A");

//****differential manchaster encoding voltage axis
    outtextxy(80,527,"+A");
    outtextxy(83,600,"0");
    outtextxy(83,660,"-A");

//*******axis
   line(100,239, 600,239);
    line(100,00, 100,739);
    line(100,425, 600,425);
    line(100,600, 600,600);
a=1;
l=1;
cout<<"Enter number :";
cin>>n;
cout<<"your number is "<<n<<"+50" <<"="<<n+50;
n=n+50;
    for(i=0;n>0;i++)
    {
     bin[i]=n%2;
     n=n/2;
    }
    for(i=7;i>=0;i--)
    {
    if(bin[i]==1)
    {


    draw1(bin);
    }
    else
    {


    draw0(bin);
    }

    }
    getch();

     getch();


	closegraph();
}
using namespace std;
int main()
{
    int gd = DETECT, gm;
    int t = 0,enco[4];
	double arry[20];
    double x, y;
	int n=0;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    for(x = 0; x < getmaxx(); x+=3){
       y = 8*cos(2*3.14*50*x);
       y = getmaxy()/3 - y;
       delay(1);
       t+=1;
    }
    x= 0;
 	for(n = 0;n<5 ;n++){
 	   y = 8 * cos(3.14* n);
 	   printf("\t%f" ,y);
 	   arry[n] = floor(y);
 	   y = 2*getmaxy()/3 - y;
       x+=20;
	}
	printf("\n");
	int y_for0 = getmaxy()/2;
	int y_for1 = y_for0-100;
	int current_x = 100;
	int prv_y;
	if(arry[0])
		prv_y = y_for0;
	else
		prv_y = y_for1;

    setcolor(255);
	outtextxy(100, y_for1-50, "Manchester encoding");
	for(n = 0;n<5 ;n++){
		printf("\t %.2f",arry[n]);
		if(arry[n]==7){
			enco[0]=1;
			enco[1]=1;
			enco[2]=1;
			enco[3]=1;
		}else if(arry[n]==6){
			enco[0]=1;
			enco[1]=1;
			enco[2]=1;
			enco[3]=0;
		}else if(arry[n]==5){
			enco[0]=1;
			enco[1]=1 ;
			enco[2]=0;
			enco[3]=1;
		}else if(arry[n]==4){
			enco[0]=1;
			enco[1]=1;
			enco[2]=0;
			enco[3]=0;
		}else if(arry[n]==3){
			enco[0]=1;
			enco[1]=0;
			enco[2]=1;
			enco[3]=1;
		}else if(arry[n]==2){
			enco[0]=1;
			enco[1]=0;
			enco[2]=1;
			enco[3]=0;
		}else if(arry[n]==1){
			enco[0]=1;
			enco[1]=0;
			enco[2]=0;
			enco[3]=1;
		}else if(arry[n]==0){
			enco[0]=1;
			enco[1]=0;
			enco[2]=0;
			enco[3]=0;
		}else if(arry[n]==-1){
			enco[0]=0;
			enco[1]=1;
			enco[2]=1;
			enco[3]=1;
		}else if(arry[n]==-2){
			enco[0]=0;
			enco[1]=1;
			enco[2]=1;
			enco[3]=0;
		}else if(arry[n]==-3){
			enco[0]=0;
			enco[1]=1;
			enco[2]=0;
			enco[3]=1;
		}else if(arry[n]==-4){
			enco[0]=0;
			enco[1]=1;
			enco[2]=0;
			enco[3]=0;
		}else if(arry[n]==-5){
			enco[0]=0;
			enco[1]=0;
			enco[2]=1;
			enco[3]=1;
		}else if(arry[n]==-6){
			enco[0]=0;
			enco[1]=0;
			enco[2]=1;
			enco[3]=0;
		}else if(arry[n]==-7){
			enco[0]=0;
			enco[1]=0;
			enco[2]=0;
			enco[3]=1;
		}else if(arry[n]==-8){
			enco[0]=0;
			enco[1]=0;
			enco[2]=0;
			enco[3]=0;
		}

		for (int j=0;j<4;j++){
			if(enco[j]){
				line(current_x,prv_y,current_x,y_for0);
				line(current_x,y_for0,current_x+25,y_for0);
				line(current_x+25,y_for0,current_x+25,y_for1);
				line(current_x+25,y_for1,current_x+50,y_for1);
				current_x = current_x+50;
				prv_y=y_for1;
			}else{
				line(current_x,prv_y,current_x,y_for1);
				line(current_x,y_for1,current_x+25,y_for1);
				line(current_x+25,y_for1,current_x+25,y_for0);
				line(current_x+25,y_for0,current_x+50,y_for0);
				current_x+=50;
				prv_y = y_for0;
			}
		}
	}
	setcolor(15);
	line(50,y_for0-50,current_x+50,y_for0-50);

	getch();
    closegraph();
    return 0;
}
