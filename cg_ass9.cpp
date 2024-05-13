#include<iostream>
#include<graphics.h>
using namespace std;
   
    void boundaryFill(int x, int y,int fill_col,int boundary_col)
    {
     int current_col=getpixel(x,y);
     if(current_col !=boundary_col && current_col != fill_col)
     {
       putpixel(x,y,fill_col);
       boundaryFill(x+1,y, fill_col, boundary_col);
       boundaryFill(x,y+1, fill_col, boundary_col);
       boundaryFill(x-1,y, fill_col, boundary_col);
       boundaryFill(x,y-1, fill_col, boundary_col);
      }
     }
     
     void floodFill(int x,int y, int fill_col, int old_col)
     {
      if(getpixel(x,y)==old_col)
      {
        putpixel(x, y, fill_col);
        floodFill(x+1,y,fill_col,old_col);
        floodFill(x-1,y,fill_col, old_col);
        floodFill(x,y+1,fill_col,old_col);
        floodFill(x, y-1,fill_col,old_col);
       }
      }
  int main(){
             int gd,gm;
             int DETECT;
             int ch;
             cout<<"Enter your choice:"<<endl;
             cout<<"1. for boundary fill\n 2. for flood fill"<<endl;
             cin>>ch;
             
      switch(ch)
                {
                  case 1:
                  initgraph(&gd,&gm, NULL);
                  line(250,250,250,350);
                  line(250,250,400,250);
                  line(400,250,400,350);
                  line(250,350,400,350);
                  boundaryFill(300,300,RED,WHITE);
                  break;
                  
                  case 2:
                  initgraph(&gd,&gm,NULL);
                  line(250,250,250,350);
                  line(250,250,400,250);
                  line(400,250,400,350);
                  line(250,350,400,350);
                  floodFill(300,300,BLUE,BLACK);
                  break;
                 
                 }
                  delay(100000);
                  closegraph();
                  return 0;
                  
                }
                                                                                                                                                     
       


