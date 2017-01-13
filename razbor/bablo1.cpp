#include <iostream>
 #include <stdlib.h>
#include <time.h>
using namespace std;
 
int main ()
{
    int **mas, n, i,j;
    srand( time( NULL ) );
    cout<<"Введите количество строк и столбцов матрицы: "<< endl;
    cin>>n;
    mas=new int*[n];
 
    for(i=0; i<n; i++)
       mas[i]=new int[n];
 
    for(i=0; i<n; i++)
       for(j=0; j<n; j++)
           mas[i][j]=rand()%11-5;
  
    cout<<"исходная матрица"<<endl;
    for(i=0; i<n; i++)
        {
       for(j=0; j<n; j++)
       {
           cout.width(4);
          cout<<mas[i][j]<<" ";
       }
          cout<<endl;
        }
    int min;
    bool fl=true;
    for(i=0; i<n; i++)
    {
        if(mas[i][i]<0)
        {
            int max=mas[i][0];
            for(j=1; j<n; j++)
                if(max<mas[i][j])
                    max=mas[i][j];
            if(fl)
            {
                min=max;
                fl=false;
            }
            else
            {
                if(max<min)
                    min=max;
            }
        }
    }
    if(fl)
        cout<<"Искомый элемент не найден"<<endl;
    else
        cout<<"Искомый элемент равен: "<<min<<endl;     
                
    return 0; 
}