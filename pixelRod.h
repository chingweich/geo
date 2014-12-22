#ifndef ROD_b
#define ROD_b
#include <string>
#include <vector>
#include "TCanvas.h"
#include "TLine.h"
#include "pixelMod.h"
#include "cmath"
class rod{
private:
  module* m[2][32];



public:
  rod();
  ~rod();
  TCanvas* drawRZ(TCanvas *c1);
  TCanvas* drawXY(TCanvas *c1);
  void rotate(double theta);
};
//---------------------------------------
rod::rod(float tem[2][32],float radiusR){
 
 if(radiusR<520){
    for(int j=0;j<2;j++){
       for(int i=0;i<32;i++){
       
       if (j==0)m[j][i]=new module(0,radiusR+3.022,tem[j][i],48,1.4,23.13);
       if (j==1)m[j][i]=new module(0,radiusR-3.022,tem[j][i],48,1.4,23.13);
       }
    }
  }
 if(radiusR>520){
    for(int j=0;j<2;j++){
       for(int i=0;i<32;i++){
       
       if (j==0)m[j][i]=new module(0,radiusR+3.022,tem[j][i],45.72,1,50);
       if (j==1)m[j][i]=new module(0,radiusR-3.022,tem[j][i],45.72,1,50);
       }
    }
  }

}
//----------------------------------------
TCanvas* rod::drawRZ(TCanvas *c1){

  for(int j=0;j<2;j++){ 
    for(int i=0;i<32;i++){
    c1=m[j][i]->drawRZ(c1);
    }
  }
  return c1;
}
//-----------------------------------------
TCanvas* rod::drawXY(TCanvas *c1){


    c1=m[0][0]->drawXY(c1);
    return c1;

   
}
//-----------------------------------------
void rod::rotate(double theta){
 
  for(int j=0;j<2;j++){ 
    for(int i=0;i<32;i++){
    m[j][i]->rotate(theta);
    }
  }

}

#endif
