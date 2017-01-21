#include <iostream>

 
using namespace std;
 
typedef struct People
{
    int happy_year;
    char name[12], city[18];
};
 
People* ReadStud(int &n)
{
    cout << "Введите кол-во сотрудников: ";
    cin >> n;
    People* A;
    A = new People[n];
    cout << "Введите данные об сотрудниках!" << endl;
    cout << "Имя - Место рождения - год рождения" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].name;
        cin >> A[i].city;
        cin >> A[i].happy_year;
    }
    return A;
}
 
void InfoStud(People* A, int n)
{
    int years;
    cout << "Введите год, по которму будем фильтровать - ";
    cin >> years;
    cout << "Имя - год рождения"<<"\n";
    for (int i = 0; i < n; i++)
    {
        if (A[i].happy_year == years) cout << A[i].name << " " << A[i].happy_year;
    }
}
int main()
{
   

    People *A;
    int n;
    A = ReadStud(n);
    InfoStud(A,n);
 
    delete[] A;
    return 0;
}