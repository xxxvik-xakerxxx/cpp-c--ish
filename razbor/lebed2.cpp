
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#define N 10

using namespace std;

void matr_random(int m[][N]) {
    int i, j;
    srand(time(0));
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            m[i][j] = rand() % 20 - 10;
}
int matr_chrs(int m[][N], int numRow) {
    int i;
    int chrs = 0;
    for (i = 0; i < N; i++) {
        if ((m[numRow][i] < 0) && (m[numRow][i] % 2 == 0))
            chrs += m[numRow][i];
    }
    return chrs;
}
int matr_find_zero(int m[][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            if (! m[j][i])
                return i;
    }
    return -1;
}
void matr_swap_rows(int m[][N], int row1, int row2) {
    int i;
    int tmp;
    for (i = 0; i < N; i++) {
        tmp = m[row1][i];
        m[row1][i] = m[row2][i];
        m[row2][i] = tmp;
    }
}
void matr_sort_chrs(int m[][N]) {
    int i;
    int sorted;
    do {
        sorted = 1;
        for (i = 0; i < N - 1; i++) {
            if (matr_chrs(m, i) > matr_chrs(m, i + 1)) {
                matr_swap_rows(m, i, i + 1);
                sorted = 0;
                break;
            }
        }
    } while (! sorted);
}
void matr_print(int m[][N], int print_chrs = 0) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            std::cout << std::setw(3) << m[i][j] << ' ';
        if (print_chrs)
            std::cout << " | " << matr_chrs(m, i) << ' ';
        std::cout << std::endl;
    }
}
int main(int argc)
{
    
    ofstream fout;
    ifstream fvhod;
    int m[N][N];
    int colNum;
    matr_random(m);
    std::cout << "input matrix:" << std::endl;
    matr_print(m);
    colNum = matr_find_zero(m);
    if (colNum >= 0)
        std::cout << "First column with zero is: " << colNum + 1 << std::endl;
    else
        std::cout << "Column with zero not found" << std::endl;
    matr_sort_chrs(m);
    std::cout << std::endl << "output matrix:" << std::endl;
    matr_print(m, 1);

    // ждем пока не нажмут <ENTER>
    getchar();
    return 0;
}