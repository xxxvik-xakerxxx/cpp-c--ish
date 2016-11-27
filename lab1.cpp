#include <iostream>
#include <math.h>
#include <iomanip> 
using namespace std;
int main()
{
	
	float  c, d, i, f;         //задаем перемменые

	const double x=0.25, y=1.31, a=3.5, b=0.9;            //значения за условием (константы)
    

    c=(a*pow (x, 3))*(b*pow (y,2))*(a*b); //находим число c для sin
    d=(3*sin(c)-sin(c*3))/4;              // sin куб числа с
    i=(a*pow (x, 3))*(b*pow (y,2))*a;     //выражение под корнем
    f=pow (i,2);                          //квадрат
    c=pow(f, 1./3);                       //корень кубический
    i=d/c;                                //первая часть выражения

    c=(a*pow (x, 3))*(b*pow (y,2))*(a*b); //находим число c для tg
    d=tan (c);                            //вычисляем tg
    
    f=i*c;                                //решаем итоговое уравнение

    cout << setprecision(3) << f;         //вывод с точностью до 5 числа строки


    cout<<"\n";
    cin.get();
    return 0;
}
