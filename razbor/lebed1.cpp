#include <iostream>
#include <iomanip> 
#include <ctime> 
using namespace std; 
//блок подключения функций
void uswap(int*, int*); 
int** create(size_t); 
void destroy(int**, size_t); 
void random(int**, size_t); 
void print(int**, size_t); 
void mx_swap(int**, size_t, size_t, size_t); 
long long dd_sum(int**, size_t); 
int main() //корневая функция
{ 
    system("chcp 1251 > nul"); 
    srand(static_cast<unsigned>(time(NULL))); 
    cout << " Введіть розмір квадратної матриці: "; 
    size_t size; 
    cin >> size; 
    int** matrix = NULL; 
    if (matrix = create(size)) { 
        random(matrix, size); 
        cout << "\n Вихідна матриця:\n\n"; 
        print(matrix, size); 
        cout << " Сума глав діагоналі: " << dd_sum(matrix, size) << endl; 
        mx_swap(matrix, size, 0, size - 1); 
        cout << "\n Матриця після обміну:\n\n"; 
        print(matrix, size); 
        destroy(matrix, size); 
        matrix = NULL; 
    } 
    cin.sync(); 
    cin.get(); 
} 
long long dd_sum(int** mx, size_t sz)//тут сумма диагонали 
{ 
    long long sum = 0; 
    for (int n = 0; n <= sz-1; ++n) 
        sum += mx[n][n]; 
    return sum; 
} 
void random(int** mx, size_t sz) //рандомное забитие матрици
{ 
    for (size_t r = 0; r < sz; ++r) 
        for (size_t c = 0; c < sz; ++c) 
            mx[r][c] = 1 + rand() % 30; 
    } 
void uswap(int& a, int& b) //свап для перестановки элементов
{ 
    int tmp = a; a = b; b = tmp; 
} 
void mx_swap(int** mx, size_t sz, size_t ca, size_t cb) //свап для матрици
{ 
    for (size_t r = 0; r < sz; ++r) 
        uswap(mx[r][ca], mx[r][cb]); 
} 
void print(int** mx, size_t sz) //вывод матрици
{ 
    for (size_t r = 0; r < sz; ++r, cout << endl) 
        for (size_t c = 0; c < sz; ++c) 
            cout << setw(3) << mx[r][c]; 
    cout << endl; 
} 
void destroy(int** mx, size_t sz) //очистка
{ 
    if (mx && sz) { 
        for (size_t r = 0; r < sz; ++r) delete[] mx[r]; 
        delete[] mx; 
    } 
} 
int** create(size_t sz)//создание матрици
 { 
    int** ptr = NULL; 
    if (ptr = new (nothrow) int*[sz]) { 
        for (size_t r = 0; r < sz; ++r) { 
            if (ptr[r] = new (nothrow) int[sz]); 
            else { 
                for (size_t c = 0; c < r; ++c) delete[] ptr[c]; 
                delete[] ptr; 
                ptr = NULL; 
                break; 
            } 
        } 
    } 
    return ptr; 
}