#include <iostream>
#include <iomanip>
#include <math.h>
#include <time.h>
#define SZ  10
using namespace std;
double GetValue(double matr[][SZ], int row, int col)
{
    double sum   = 0.;
    int    count = -1;
    if(SZ < 2)
        return 0;
    for(int i = row - 1; i <= row + 1; i++)
    {
        if(i >= 0 && i <= SZ - 1)
            for(int j = col - 1; j <= col + 1; j++)
                if(j >= 0 && j <= SZ - 1)
                {
                    sum += matr[i][j];
                    count++;
                }
    }
    return (sum - matr[row][col]) / count;
}
int main()
{
    srand((unsigned)time(NULL));
    double source[SZ][SZ];
    double target[SZ][SZ];
    double sum_elem = 0.;
    int    i, j;
    cout << "Source:\n";
    for(i = 0; i < SZ; i++)
    {
        for(j = 0; j < SZ; j++)
        {
            source[i][j] = rand() % 50 - 24;
            cout << setw(8) << setprecision(4) << source[i][j];
        }
        cout << endl;
    }
    // Построить результат сглаживания заданной вещественной матрицы размером 10 на 10.
    cout << "\nTarget:\n";
    for(i = 0; i < SZ; i++)
    {
        for(j = 0; j < SZ; j++)
        {
            target[i][j] = GetValue(source, i, j);
            cout << setw(8) << target[i][j];
        }
        cout << endl;
    }
    cout << "\nPress any key to quit...\n";
    cin.get();
    return 0;
}