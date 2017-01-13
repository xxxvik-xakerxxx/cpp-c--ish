#include <iostream>
using namespace std;
 
struct Stud 
{
    char Name[35]; 
    char Family[35];
    char Otch[100]; 
    char Predm[100]; 
    int Kol[1]; 
    void Show(); 
    void Input(); 
};
 
void Stud::Input() 
{    
    
            cout<<"\n\n";
                        
            cout<<"Фамилия\t\t";
            cin.getline(Family,35); 
 
 
            cout<<"Имя \t\t";
            cin.getline(Name,35); 
            
 
            cout<<"Очество \t";
            
            cin.getline(Otch,100); 

            cout<<"Предмет \t";
            
            cin.getline(Predm,100); 
 
            
                cout<<"Число перездач\t\t";
                cin>>Kol[0]; 
                cin.ignore();
            
                
        cout<<"======================\n";
}
 
void Stud::Show() //Функция показывает данные структуры на экране
{    
    cout<<Name<<"\t"<<Family<<"\t"<<Otch<<"\t"<<Predm<<"\t"<<Kol<<"\n";
    
}
 
 
 
int main()
{
    
       
    int N;
    cout << "Введите число элементов структуры: " << "\n";
    cin>>N;
    cin.ignore();
    Stud  Stud[N];
 
    for (int i=0;i<N;i++) Stud[i].Input();
    cout<<"Структура:"<<"\n"; 
    for (int i=0;i<N;i++) Stud[i].Show();
    
	for (int i=0;i<N-1;i++)
	{
		for (int j=1;j<N;j++)
		{
			if (Stud[i].Kol[0]>Stud[j].Kol[0]) swap(Stud[i],Stud[j]);
		}
	}
    cout<<"Отсортированая структура "<<"\n";
	for (int i=0;i<N;i++) Stud[i].Show();
 
   return 0;
    }
