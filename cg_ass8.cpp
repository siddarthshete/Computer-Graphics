/*
 Write C++ program to draw the following pattern. Use DDA Line and Bresenham Circle algorithms. 
 Apply the concept of Encapsulation
*/

#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class ddaline   
{
 float x1, x2, y1, y2;
 public:
 void drawline(float x1, float y1, float x2, float y2);
};
void ddaline::drawline(float x1, float y1, float x2, float y2)
{
 float len,dx,dy,x,y;
 int i;

 if(abs(x2-x1)>=abs(y2-y1))  
  len=abs(x2-x1);
 else
  len=abs(y2-y1);

 dx=((x2-x1)/len);
 dy=((y2-y1)/len);

 x= x1 + 0.5;
 y= y1 + 0.5;

 i=0;
 while(i<len)
 {
  putpixel(floor(x),floor(y),WHITE);
  x += dx;
  y += dy;
  i = i+1;
 }
}

class brecircle
{
 int Xc, Yc, Xi, Yi, R, Di, limit, d,d_;
 public:
 void mycircle(int, int, int);
 void mh();
 void md();
 void mv();

};
void brecircle :: mycircle(int Xc, int Yc, int R)
{
 limit= 0;
 Xi=0;
 Yi=R;
 Di=2*(1-R);
 while(Yi>=limit)
 {
 putpixel(Xc+Xi, Yc+Yi, WHITE);

 putpixel(Xc+Xi, Yc-Yi,WHITE);

 putpixel(Xc-Xi,Yc-Yi,WHITE);

 putpixel(Xc-Xi,Yc+Yi,WHITE);


 if(Di<0)
 {
  d=((2*Di) + (2*Yi) - 1);

  if(d<=0)
   mh();

  else
   md();
 }

 else if(Di>0)
 {
  d_=((2*Di) - (2*Xi) - 1);

  if(d_<=0)
   md();

  else
   mv();

 }

 else if(Di==0)
   md();
 }//end of while

}

void brecircle :: mh() //Select horizontal pixel
{
 Xi= Xi + 1;
 Di= Di + 2*Xi +1;
}

void brecircle :: mv() //Select vertical pixel
{
 Yi= Yi - 1;
 Di= Di - 2*Yi +1;
}

void brecircle :: md() //Select diagonal pixel
{
 Xi= Xi + 1;
 Yi= Yi-1;
 Di= Di + 2*Xi -2*Yi + 2;
}
//---------------------------------------------------------
int main()
{
 ddaline l;
 brecircle c;
 float x1,x2,y1,y2;
 int gd=DETECT,gm,ch;
 initgraph(&gd,&gm,NULL);
	
  l.drawline(212.3,350,388.3,350);
  l.drawline(212.3,350,300,200);
  l.drawline(300,200,388.3,350);
  c.mycircle(300,300,50);
  c.mycircle(300,300,100);
  getch();
  closegraph();
  return 0;
}


