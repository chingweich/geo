#ifndef LAYER_b
#define LAYER_b
#include <string>
#include <vector>
#include "TCanvas.h"
#include "TLine.h"
#include "pixelMod.h"
#include "pixelRod.h"
#include "cmath"
class layers{
private:
  rod* l[6][2][38];

public:
  layers();
  ~layers();
  TCanvas* drawRZ(int i);
  TCanvas* drawXY(int i);
  TCanvas* drawRZbase(int i,TCanvas* c1);
  TCanvas* drawXYbase(int i,TCanvas* c1);
  TCanvas* drawAllRZ( );
  TCanvas* drawAllXY( );
};
//-------------------------------------------
layers::layers(){
float tem1[2][32]={{43.948,-43.997,129.688,-129.733,213.275,-213.316,294.764,-294.802,374.207,-374.241,451.656,-451.686,527.16,-527.187,600.769,-600.793,672.53,-672.551,742.49,-742.507,810.693,-810.707,877.184,-877.196,942.006,-942.014,1005.2,-1005.21,1066.81,-1066.81,1126.87,-1126.87},{0.552775,83.9258,-83.9716,166.332,-166.374,246.669,-246.708,324.99,-325.025,401.344,-401.376,475.782,-475.81,548.351,-548.375,619.098,-619.119,688.069,-688.087,755.308,-755.323,820.859,-820.872,884.765,-884.775,947.067,-947.074,1007.8,-1007.81,1067.02,-1067.02}};
float tem2[2][32]=
  {
{44.6175,-44.6669,133.007,-133.052,220.507,-220.549,307.129,-307.166,392.879,-392.913,477.768,-477.798,561.803,-561.829,644.994,-645.016,727.349,-727.367,808.876,-808.89,889.583,-889.594,969.479,-969.486,1048.57,-1048.58,1126.87,-1126.87},
{0.12807,87.1535,-87.2001,173.608,-173.65,259.193,-259.232,343.918,-343.953,427.792,-427.823,510.822,-510.849,593.018,-593.041,674.388,-674.407,754.939,-754.955,834.681,-834.694,913.622,-913.631,991.769,-991.774,1069.13,-1069.13}
  };
float tem3[2][32]=
  {
{14.9273,-74.3793,104.029,-163.075,192.521,-251.164,280.407,-338.65,367.693,-425.538,454.381,-511.831,540.475,-597.533,625.981,-682.65,710.902,-767.184,795.242,-851.139,879.005,-934.521,962.194,-1017.33,1044.81,-1099.58,1126.87},
{-29.4117,58.8094,-117.353,146.548,-204.692,233.687,-291.434,320.229,-377.582,406.18,-463.141,491.542,-548.114,576.32,-632.506,660.518,-716.321,744.14,-799.562,827.19,-882.233,909.672,-964.339,991.589,-1045.88,1072.95,-1126.87}
  };
float tem4[2][32]=
  {
{54.4923,-144.936,253.079,-342.824,450.132,-539.184,645.663,-734.027,839.685,-927.367,1032.21,-1119.21,},
{-45.0683,152.792,-242.189,349.081,-437.787,543.853,-631.875,737.122,-824.464,928.899,-1015.57,1119.19,}
  };
float tem5[2][32]=
  {
{54.4923,-144.936,253.079,-342.824,450.132,-539.184,645.663,-734.027,839.685,-927.367,1032.21,-1119.21},
{-45.0683,152.792,-242.189,349.081,-437.787,543.853,-631.875,737.122,-824.464,928.899,-1015.57,1119.19}
  };
float tem6[2][32]=
  {
{54.4923,-144.936,253.079,-342.824,450.132,-539.184,645.663,-734.027,839.685,-927.367,1032.21,-1119.21},
{-45.0683,152.792,-242.189,349.081,-437.787,543.853,-631.875,737.122,-824.464,928.899,-1015.57,1119.19}
  };
float radius[6][2]={
{218,236.426},{345.368,365.776},{496,516.404},{674,694.002},{875.901,895.903},{1068,1088}
  };
int rodNum[6]={8,12,17,24,31,38};
  for (int i=0;i<6;i++){
  double theta=(3.14159265358979323846)/(rodNum[i]);
    for (int j=0;j<2;j++){
      for (int k=0;k<76;k++){
      if(k>rodNum[i])break;
      if(i==0)l[i][j][k]=new rod(tem1,radius[i][j]);
      if(i==1)l[i][j][k]=new rod(tem2,radius[i][j]);
      if(i==2)l[i][j][k]=new rod(tem3,radius[i][j]);
      if(i==3)l[i][j][k]=new rod(tem4,radius[i][j]);
      if(i==4)l[i][j][k]=new rod(tem5,radius[i][j]);
      if(i==5)l[i][j][k]=new rod(tem6,radius[i][j]);
      l[i][j][k]->rotate(theta*k*2);
      if (j==1) l[i][j][k]->rotate(theta);
      }
    }
  }
}
//-------------------------------------------------------
TCanvas*  layers::drawRZ(int i){
TCanvas *c1 = new TCanvas("c1","Examples",10,10,700,500);
int axisXMax=1200,axisXMin=-1200,axisYMax=1200,axisYMin=-1200;
c1->Range(axisXMin,axisYMin,axisXMax,axisYMax);
TLine *beamPath =new TLine(axisXMin,0,axisXMax,0);
beamPath-> SetLineColor(3);
beamPath->Draw();

c1=drawRZbase(i,c1);
return c1;

}
//-------------------------------------------------------
TCanvas*  layers::drawXY(int i){
TCanvas *c1 = new TCanvas("c1","Examples",10,10,700,700);
int axisXMax=1200,axisXMin=-1200,axisYMax=1200,axisYMin=-1200;
c1->Range(axisXMin,axisYMin,axisXMax,axisYMax);
TLine *beamPath =new TLine(axisXMin,0,axisXMax,0);
beamPath-> SetLineColor(3);
beamPath->Draw();

c1=drawXYbase(i,c1);
return c1;

}
//---------------------------------------------------------
TCanvas*  layers::drawRZbase(int i,TCanvas* c1){
int rodNum[6]={8,12,17,24,31,38};
  
double theta=(3.14159265358979323846)/(rodNum[i]);

int axisXMax=1200,axisXMin=-1200,axisYMax=1200,axisYMin=-1200;

c1=l[i-1][0][0]->drawRZ(c1);
l[i-1][1][0]->rotate(-theta);
c1=l[i-1][1][0]->drawRZ(c1);
l[i-1][1][0]->rotate(theta);
TGaxis *axis1 = new TGaxis(axisXMin+(axisXMax-axisXMin)/20,axisYMin+(axisYMax-axisYMin)/20,axisXMax-(axisXMax-axisXMin)/20,axisYMin+(axisYMax-axisYMin)/20,axisXMin+(axisXMax-axisXMin)/20,axisXMax-(axisXMax-axisXMin)/20,510,"");
   axis1->SetName("Z[mm]");
   axis1->Draw();
TGaxis *axis2 = new TGaxis(axisXMin+(axisXMax-axisXMin)/10,axisYMin+(axisYMax-axisYMin)/20,axisXMin+(axisXMax-axisXMin)/10,axisYMax-(axisYMax-axisYMin)/20,axisYMin+(axisYMax-axisYMin)/20,axisYMax-(axisYMax-axisYMin)/20,510,"");
   axis2->SetName("r[mm]");
   axis2->Draw();
return c1;

}
//-------------------------------------------------------
TCanvas*  layers::drawXYbase(int i,TCanvas*  c1){

int axisXMax=1200,axisXMin=-1200,axisYMax=1200,axisYMin=-1200;
int rodNum[6]={8,12,17,24,31,38};
 
 
  
      for (int k=0;k<76;k++){
      if(k>rodNum[i-1])break;
       c1=l[i-1][0][k]->drawXY(c1);
       c1=l[i-1][1][k]->drawXY(c1);
      }
    
  


TGaxis *axis1 = new TGaxis(axisXMin+(axisXMax-axisXMin)/20,axisYMin+(axisYMax-axisYMin)/20,axisXMax-(axisXMax-axisXMin)/20,axisYMin+(axisYMax-axisYMin)/20,axisXMin+(axisXMax-axisXMin)/20,axisXMax-(axisXMax-axisXMin)/20,510,"");
   axis1->SetName("Z[mm]");
   axis1->Draw();
TGaxis *axis2 = new TGaxis(axisXMin+(axisXMax-axisXMin)/10,axisYMin+(axisYMax-axisYMin)/20,axisXMin+(axisXMax-axisXMin)/10,axisYMax-(axisYMax-axisYMin)/20,axisYMin+(axisYMax-axisYMin)/20,axisYMax-(axisYMax-axisYMin)/20,510,"");
   axis2->SetName("r[mm]");
   axis2->Draw();
return c1;

}
//---------------------------------------------------------

TCanvas* layers::drawAllRZ( ){
     for (int k=1;k<7;k++){
    
      if (k==1)TCanvas* a=drawRZ(k);
      a=drawRZbase(k,a);
      }
     return a;
}
//-----------------------------------
TCanvas* layers::drawAllXY( ){
     for (int k=1;k<7;k++){
    
      if (k==1)TCanvas* a=drawXY(k);
      a=drawXYbase(k,a);
      }
     return a;
}
//-----------------------------------
#endif
