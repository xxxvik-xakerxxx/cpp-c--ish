#include <iostream>
#include <ctime>
#include <math.h> // в ней функция time

using namespace std;

int main()
{
    srand(time(NULL)); // Инициализируем генератор случайных чисел.
    int n = 0;
    cout << "Vedite cislo n dla masiva \n";
    cin >> n; // Считываем с клавиатуры n
    int **a = new int* [n]; // Создаем массив указателей
    for (int i = 0; i < n; i++)
    {
        a[i] = new int [n]; // Создаем элементы
    }
    // А дальше работа как с обычным массивом.
    cout << "Vasha matrica \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = rand() % 10; // Каждый элемент случайному числу от 0 до
            cout << a[i][j] << " "; // Вывести элементы на консольку
        }
        cout << endl; // Двумерный массив. Строка кончилась, переводим строку и на консоли
    }
    //сортировка на главной диагонали
int tmp;
bool flag; //Переменная для проверки и выхода из цыкла
do //Цыкл сортировки
 {
  flag = true;
  for (int i=0; i<n-1; i++)
  {
    if (a[i][i]<a[i+1][i+1])
    {
      flag = false;
      tmp = a[i][i];
      a[i][i] = a[i+1][i+1];
      a[i+1][i+1] = tmp;
    }
  }
 }
 while (!flag);
 cout << endl;
 //Вывод матрицы
 cout << "Otsort mas \n";
 for (int i=0; i<n; i++)
 {
   for (int j=0; j<n; j++)
   {
     cout <<a[i][j] << " ";
   }
   cout <<endl;
 }
 //поис макс и мин элемента и смена местами
int min, max;
 min=a[0][0];
 max=a[0][0];
 for(int i=0; i<n; i++)
 {
   for (int j=0; j<n; j++)
   {
     if (a[i][j]<min) min=a[i][j];
     {
       if (a[i][j]>max) max=a[i][j];
     }
   }
 }
int pp;
pp=min;
min=max;
max=pp;

//Вывод матрицы
cout << "Kon mas \n";
for (int i=0; i<n; i++)
{
  for (int j=0; j<n; j++)
  {
    cout <<a[i][j] << " ";
  }
  cout <<endl;
}
    // Удаление массива
    for (int i = 0; i < n; i++)
    {
        delete[]a[i]; // Удаляем каждый элемент
    }
    delete [] a; // А потом массив
    return 0;
}
