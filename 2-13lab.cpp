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
            a[i][j] = rand() % 10 -4; // Каждый элемент случайному числу от 0 до
            cout << a[i][j] << "\t"; // Вывести элементы на консольку
        }
        cout << endl; // Двумерный массив. Строка кончилась, переводим строку и на консоли
    }
    int min;
     min=a[0][0];
     for(int i=0; i<n; i++)
     {
       for (int j=0; j<n; j++)
       {
         if (a[i][j]<min) min=a[i][j];

       }
     }
     cout << "Min element: ";
     cout << min << "\n";
     if (min%2==0)
     {
       cout << "Element " << min << " paren. \nSortirowka";
       int j=2;
       for(int i=0; i<n; i++)
       {
         for(int z=0; z<n-i; z++)
         {
           if (a[z][j]>a[z+1][j])
           {
             for(int k=0; k<n; k++)
             {
               int buf=a[z][k];
               a[z][k]=a[z+1][k];
               a[z+1][k]=buf;
             }
           }
         }
       }
       cout <<"Otsort matr \n";
       for (int i=0; i<n; i++)
       {
         for (int j=0; j<n; j++)
         {
           cout << a [i][j]<<"\t";
         }
       }
     }


     else
     {
       cout << "Element " << min << "  ne paren. \nProgramm stop.";
     }
    // Удаление массива
    for (int i = 0; i < n; i++)
    {
        delete[]a[i]; // Удаляем каждый элемент
    }
    delete [] a; // А потом массив
    return 0;
}
