

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>
#include<iostream>
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
