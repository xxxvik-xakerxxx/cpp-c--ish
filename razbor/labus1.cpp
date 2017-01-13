#include <iostream>
using namespace std;
const int n=4, m=4;
int main()
{ int a[n], b[m], c[n+m];
  int i, j, k, l;
//--------------- ввод двух отсортированных массивов
  cout << "Vvedite 2 otsortirovanih massiva" << endl;
  for (i=0; i<n; i++) 
  cin >> a[i];
  for (j=0; j<m; j++)  
  cin >> b[j];
//------------------- слияние массивов a и b в массив с
  for (i=0, j=0, k=0; i<n && j<m; k++)  
  if (a[i]<b[j]) c[k]=a[i++];  
  else c[k]=b[j++];  
  if (i==n)    
  for (l=k; l<n+m; l++) 
  c[l]=b[j++];  
  else 
  for (l=k; l<n+m; l++) 
  c[l]=a[i++];
//-------------- вывод полученного массива с
  cout << "Rezult — massiv c" << endl;
  for (i=0; i<n+m; i++) 
  cout << c[i] << "\n";
return 0;
}