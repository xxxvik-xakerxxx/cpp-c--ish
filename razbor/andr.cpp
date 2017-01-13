#include <iostream>
#include <cstdlib>
using namespace std;

void addNumInSortArray(int A[], int N, int num, int n)
{
    // A - массив, упорядоченный по возрастанию
    // N - количество элементов в A
    // num - число, которое нужно добавить в A
    // n - количество num

    int k = 0;

    while (A[k] <= num && k < N) k++;

    for (int i = N+n-1; i > k; i--) A[i] = A[i-n];

    for (int i = k; i < k+n; i++) A[i] = num;
}
 
// Пример
int main()
{
    srand(time(NULL));
    int N = 10, num = rand() % 100, n = rand() % 10, *A = new int[N+n];
    

    for (int i = 0; i < N; i++)
     { A[i] = i*i;
       cout << A[i] << " ";
     }
    cout << endl << endl;

    addNumInSortArray(A, N, num, n);

    for (int i = 0; i < N+n; i++) cout << A[i] << " ";
    cout << endl << endl;

    delete [] A;
    
    return 0;
}