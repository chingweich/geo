
#ifndef MODULE_b
#define MODULE_b


#include <string>
#include <vector>
#include "TCanvas.h"
#include "TLine.h"
#include "cmath"
class module {
private:
 double posX;
 double posY;
 double posZ;
 double length;
 double width;
 double height;
public:
 module();
 ~module();
 TCanvas* drawRZ(TCanvas *c1);
 TCanvas* drawXY(TCanvas *c1);
 double printX();
 void rotate(double theta);
};
//-------------------------------------------------------
module::module(double x,double y, double z, double dx ,double dy ,double dz){
posX=x;
posY=y;
posZ=z;
length=dx;
height=dy;
width=dz;
}
//--------------------------------------------------------
TCanvas* module::drawRZ(TCanvas *c1){
//TCanvas *c1 = new TCanvas("c1","Examples",10,10,700,500);
//c1->Range(-100,-100,100,100);
if (posZ==0) return c1;
TLine *moduleLine =new TLine(posZ-width,posY,posZ+width,posY);
//cout<<posZ-width<<"to"<<posZ+width<<endl;
moduleLine->Draw("same");
return c1;
}
//---------------------------------------------------------
TCanvas* module::drawXY(TCanvas *c1){
//TCanvas *c1 = new TCanvas("c1","Examples",10,10,700,500);
//c1->Range(-100,-100,100,100);
if (posZ==0) return c1;
double theta=atan(posY/posX);
double dx=abs(length*sin(theta));
if (theta>0)dx=-dx;
double dy=length*cos(theta);
TLine *moduleLine =new TLine(posX-dx,posY-dy,posX+dx,posY+dy);
moduleLine->Draw("same");
return c1;
}
//--------------------------------
double module::printX(){
return posX;

}
//--------------------------------
void module::rotate(double theta){
double x=posX;
double y=posY;
posX=cos(theta)*x-sin(theta)*y;
posY=cos(theta)*y+sin(theta)*x;

}

#endif
