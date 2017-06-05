#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

//Функция для вычисления НОД - проверка взаимно простых
unsigned int gcd(unsigned int a, unsigned int b)
{
    while (a && b)
        if (a >= b)
           a = a % b;
        else
           b = b % a;
    return a | b;
}

//Функция Эйлера
int euler(int n)
{
    int ans;
    ans = n;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0)
        {
            while (n % i == 0) n = n/i;
            ans = ans - ans / i;
        }
    if (n > 1) ans = ans - ans / n;
    return ans;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    //x = a(mod m)
    int A, i, j, k, c, X;
    setlocale(LC_ALL, "Russian");

    //снимем нужные данные с клавиатуры
    cout << "Вы имеете систему уравнений вида:" << endl << "x = a[1] (mod m[1])" << endl <<
        "x = a[2] (mod m[2])" << endl << "..............." << endl << "x = a[k] (mod m[k])" << endl << "где i = 1, 2, ..., k." << endl;
    cout << "Программа создана для того, чтобы реализовывать Китайскую теорему об остатках," << endl << " т.е. находить число X по остаткам от деления на взаимно простые числа." << endl <<
        "Введите сначала число k - количество уравнений системы." << endl;
    cin >> k;
    if (cin.fail())
        do
        {
            cout << "---Error!---" << "Введите число!" << endl;
            cin.clear();
            cin.sync();
            cin >> k;
        }
        while (cin.fail());

    int *m = new int[k];
    int *a = new int[k];
    int *N = new int[k];
    int *M = new int[k];
    int *f = new int[k];
    memset (m, 0, sizeof(m));
    memset (a, 0, sizeof(a));
    memset (N, 0, sizeof(N));
    memset (M, 0, sizeof(M));
    memset (f, 0, sizeof(f));

    retry : ;//при ошибке возврат сюда
    for (int i=0; i<k; i++)//a[i] и m[i]
    {
        cout << "Введите числа m[" << i + 1 << "] и a[" << i + 1 << "] через пробел соответственно." << endl;
        cin >> m[i];
        if (cin.fail())
            do
            {
                cout << "---Error!---" << "Введите число!" << endl;
                cin.clear();
                cin.sync();
                cin >> m[i];
            }
            while (cin.fail());

        cin >> a[i];
        if (a[i] > m[i])
            do
            {
                cout << "a[i] должно быть меньше m[i]" << endl;
                cin.clear();
                cin.sync();
                cin >> a[i];
                if (cin.fail())
                    do
                    {
                        cout << "---Error!---" << "Введите число!" << endl;
                        cin.clear();
                        cin.sync();
                        cin >> a[i];
                    }
                    while (cin.fail());
            }
            while (a[i] > m[i]);
    }

    //проверим, взаимно ли просты элементы массива m
    for (int i=0; i < k; i++)
        for (int j=0; j < k; j++)
            if ((i != j) && (gcd(m[i], m[j]) != 1))
            {
                cout << "m[i] должны быть взаимно просты! Возврат к вводу m[i] и a[i]." << endl;
                goto retry;
            }

    //приступим, наконец к нахождению X
    A = 1;
    for (int i=0; i < k; i++)
        A = A * m[i];
    for (int i=0; i < k; i++)
        M[i] = A / m[i];

    for (int i=0; i < k; i++)
    {
        f[i] = euler(m[i]);
        //N[i] = exp(M[i] * log(f[i] - 1.0));
        c = N[i];
        for (int j=1; j <= f[i] - 1; j++)
            N[i] = N[i] * c;
        N[i] = N[i] % m[i];
    }

    //само значение X
    X = 0;
    for (int i=0; i < k; i++)
        X = X + a[i] * N[i] * M[i];

    cout << "Решение системы сравнений" << endl;
    for (int i=0; i < k; i++)
        cout << "X = " << a[i] << "(mod" << m[i] << ")" << endl;
    cout << "имеет вид:" << endl << "X = " << X << "(mod" << A << ")" << endl;

    delete[] m;
    delete[] a;
    delete[] N;
    delete[] M;
    delete[] f;
    system("pause");
    return 0;
}
