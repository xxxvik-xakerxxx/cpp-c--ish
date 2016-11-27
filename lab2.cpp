#include <iostream>
#include <math.h>

using  namespace  std;
int main ()
{
   float x, a, b, y, i;

  
   
   b=1.5;
   

    for (x=0.5; x<=3.1; x+=0.21){
	for (a=-0.1; a>=-1.4; a+=-0.1){
    if (x<b){
    i=a*x-pow(b,a);
    y=sin(fabs(i));
    
 }
   else{
    i=a*x-pow(b,a);
    y=cos(fabs(i));
    
}

cout<<y;}
}


    
    cin.get();
	return 0;
}
