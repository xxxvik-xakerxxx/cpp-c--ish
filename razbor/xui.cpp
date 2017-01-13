
#include "time.h"
#include "iostream"
using namespace std;
 
void arr(int* arr_1,int n,  int* arr_2, int m)
{
    cout << "Equals elements in two array: " <<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (*(arr_1 + i) == *(arr_2 + j))
                cout << *(arr_1 + i) << " ";
        }
    }
    cout << endl;
}
 
int main()
{
    int n, m;
    srand(time(0));
    n = rand() % 100 + 10;
    m = rand() % 100 + 10;
    int* arr_1 = (int*)malloc(n*sizeof(int));
    int* arr_2 = (int*)malloc(m*sizeof(int));
    cout << "First array (size = " << n << " ): " << endl;
    for (int i = 0; i < n; i++)
    {
        *(arr_1+i) = rand() % 201 - 100;
        cout << *(arr_1 + i) << " ";
    }
    cout <<endl<<"Second array (size = " << n << " ): " << endl;
    for (int i = 0; i < n; i++)
    {
        *(arr_2 + i) = rand() % 201 - 100;
        cout << *(arr_2 + i) << " ";
    }
    cout << endl;
 
    arr(arr_1,n,arr_2,m);
 
    return 0;
}