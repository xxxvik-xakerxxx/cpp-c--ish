#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void add (int *[], int&);
void copy (int*, int*, const int);
int find (int *[], const int);
inline void get_number (int&, int&);
int menu();
void out (int *[], const int);
void rand_in (int *[], const int);
void remove (int *[], int&);
void sort(int*, int*, const int);
void sort_key (int *[], const int);
void sort_number (int *[], const int);


int main()
{
    setlocale(0, "");
    int nSize = 10;
    int *pKey, *pNumber;
    srand(unsigned(time(0)));

    pKey = new int[nSize];
    pNumber = new int[nSize];
    int *masP[] = {pKey, pNumber};

    rand_in(masP, nSize);
    out(masP, nSize);

    bool bLabelOut = true;
    while (bLabelOut)
    {
        switch (menu())
        {
            case 1:
                {
                    int n = find(masP, nSize);
                    if ( n > -1)
                        cout<<"Введенный номер в списке на "<<n+1<<" месте\n";
                    else cout<<"Такого номера в списке нет\n";
                }
                break;
            case 2: add (masP, nSize);
                break;
            case 3: remove (masP, nSize);
                break;
            case 4: out (masP, nSize);
                break;
            case 5: sort_key (masP, nSize);
                break;
            case 6: sort_number (masP, nSize);
                break;
            case 7: bLabelOut = false;
                break;
        default: cout<<"Некорректный ввод\n";
            break;
        }
    }

    cout<<"\n";
    delete[] pKey, pNumber;
    return 0;
}
//----------------------------Добавление номера
void add (int *p[], int& s)     // Для удобства в функции введены локальные указатели для работы с номерами телефонов.
{                               // В начале функции им присваивается значение из массива указателей.
    int *k = p[0];              // По завершении функции эти указатели записываются в массив.
    int *n = p[1];
    int *k_add = new int[++s];
    int *n_add = new int[s];    //Создадим новые массивы для кодов и номеров на 1 больше старых
    copy(k, k_add, s-1);        // Скопируем старые массивы в новые
    copy(n, n_add, s-1);
    int key, number;
    get_number(key, number);
    *(k_add+s-1) = key;         // Добавим новый номер телефона
    *(n_add+s-1) = number;

    p[0] = k_add;               // Запишем в массив указателей указатели на новые массивы.
    p[1] = n_add;
}
//-------------------------------------Копирование массива. (Нужно в функциях добавления и удаления)
void copy (int *a, int *b, const int s)
{
    for (int i = 0; i < s; i++)
        *(b+i) = *(a+i);
}
//------------------------------------Поиск по номеру телефона
int find (int *p[], const int s)
{
    int *k = p[0];
    int *n = p[1];
    int key, number;
    get_number(key, number);
    for (int i = 0; i < s; i++)
        if ( *(k+i) == key )
            if ( *(n+i) == number )
                return i;
    return -1;
}
//------------------------------------ Ввод номера телефона(Служебная функция)
void get_number (int& key, int& number)
{
    cout<<"Введите код города : ";
    cin>>key;
    cout<<"Введите номер телефона : ";
    cin>>number;
    cout<<"\n";
}
//------------------------------------ Меню для пользователя
int menu()
{
    int c;
    cout<<"Выберите действие :\n1 - поиск по номеру\n2 - добавить номер\n3 - удалить номер\n"
        <<"4 - вывести список номеров\n5 - сортировка по коду города\n6 - сортировка по номеру\n7 - выход\n";
    cin>>c;
    if ( 1 == c ) return 1;
    if ( 2 == c ) return 2;
    if ( 3 == c ) return 3;
    if ( 4 == c ) return 4;
    if ( 5 == c ) return 5;
    if ( 6 == c ) return 6;
    if ( 7 == c ) return 7;
    else return 0;
}
//-------------------------------------Вывод списка телефонов
void out (int *p[], const int s)
{
    cout<<"Код Телефон\n";
    for (int i = 0; i < s; i++)
    {
        cout.fill('0');
        cout.width(3);
        cout<<p[0][i]<<" ";
        cout.width(7);
        cout<<p[1][i]<<"\n";
    }
}
//-------------------------------------Случайное заполнение начального списка
void rand_in (int *p[], const int s)
{
    int *k = p[0];
    int *n = p[1];
    for (int i = 0; i < s; i++)
    {
        *(k+i) = rand()%301 + rand()%50;
        *(n+i) = (rand()%10000)*123;
    }
    p[0] = k;
    p[1] = n;
}
//------------------------------------- Удаление номера из списка
void remove (int *p[], int& s)
{
    int *k = p[0];          // Функция аналогична функции добавления номера
    int *n = p[1];
    int n_r = find (p, s);
    if ( n_r > -1 )
    {
        int *k_new = new int[--s];
        int *n_new = new int[s];
        int i;
        for ( i = 0; i < n_r; i++)
        {

            *(k_new+i) = *(k+i);
            *(n_new+i) = *(n+i);
        }
        for (i; i < s; i++)
        {
            *(k_new+i) = *(k+i+1);
            *(n_new+i) = *(n+i+1);
        }

        p[0] = k_new;
        p[1] = n_new;
    }
    else
        cout<<"Такого номера нет\n";

}
//------------------------------------- Сортировка вставками по неубыванию. Нужна для реализации сортировок по коду и номеру.
void sort(int *a, int *b, const int s)
{
    for (int i = 1; i < s; i++)
    {
        int ins = *(a+i);
        int temp = *(b+i);
        int j = i - 1;
        while (j >= 0 && ins < *(a+j))
        {
            *(a+j+1) = *(a+j);
            *(b+j+1) = *(b+j);
            j--;
        }
        *(a+j+1) = ins;
        *(b+j+1) = temp;
    }
}
//------------------------------------ Сортировка по коду города
void sort_key (int *p[], const int s)
{
    int *k = p[0];
    int *n = p[1];

    sort (k, n, s);

    p[0] = k;
    p[1] = n;
}
//------------------------------------- Сортировка по номеру телефона
void sort_number (int *p[], const int s)
{
    int *k = p[0];
    int *n = p[1];

    sort (n, k, s);

    p[0] = k;
    p[1] = n;
}
