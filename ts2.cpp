#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>



using namespace std;

struct telefon
{
    char fam[20];
    char name[20];
    char ini[20];
    char ylica[20];
    int dom;
    int namber;
};

telefon bd[*kolvo];

    void help();//основное меню
    void switch1();//переключатель
    void vvod();//список пользователей
    void list();
    void deletebd();
    void clsave();
    void openf();
    void screach ();

void help()
{
    cout<<endl<<endl<<"Телефонный справочник:"<<endl;
    cout<<"Ввод сведений о новых абонентах  - введите 1"<<endl;
    cout<<"Изменение содержимого записей справочника - введите 2"<<endl;
    cout<<"Удаление выбранных записей - введите 3"<<endl;
    cout<<"Поиск записей по фамилии и номеру телефона - введите 4"<<endl;
    cout<<"Показать список абонентов - введите 5"<<endl;
    cout<<"Выйти из системы - введите 6"<<endl;
}


void vvod(*kolvo)
{
    string answer;
    int p;
    int i;
    for (i=0; i<kolvo; i++)
    {
        printf("Введите фамилию>> %d%s" ,i,": ");
        fflush(stdin);
        cin>>(bd[i].fam);
        printf("Введите имя>> %d%s" ,i,": ");
        cin>>(bd[i].name);
        printf("Введите инициалы>> %d%s" ,i,": ");
        cin>>(bd[i].ini);
        printf("Введите улицу>> %d%s" ,i,": ");
        cin>>(bd[i].ylica);
        printf("Введите номер дома>> %d%s" ,i,": ");
        scanf("%d",&bd[i].dom);
        printf("Введите номер телефона>> %d%s", i, ": ");
        scanf("%d",&bd[i].namber);

m:      cout<<"\n\nПродолжить создание профилей? [yes/no]  ";
        cin>>answer;
        if((answer=="yes") || (answer=="y") || (answer=="Yes") || (answer=="Y") )
        {
        }
        else
            if((answer=="no") || (answer=="n") || (answer=="No") || (answer=="N") )
            {
                help();
                switch1 ();
            }
            else
            {
                cout<<"\nОшибка ввода. Повторите попытку";
                goto m;
            }
    }
    help();
    switch1 ();
}

void deletebd(*kolvo)
{
    int i;
    printf("Vvedite dannue kotorue nado udalit'- ");
    cin>>i;
	
     //for (int i=0; i<10; i++)
     //printf("%s %i %i %i\n", bd[i].fam, bd[i].name, bd[i].ini, bd[i].ylica, bd[i].dom, bd[i].namber);
   
    //    bd[i].fam=bd[d].fam;
    //    bd[i].name=bd[d].name;
    //    bd[i].ini=bd[d].ini;
    //    bd[i].ylica=bd[d].ylica;
    //    bd[i].dom=bd[d].dom;
    //    bd[i].namber=bd[d].namber;
    
	for (i; i<kolvo-2; i++)
		    {
	         bd[i] = bd[i+1];
		    }
     help();
    switch1 ();
}

void list(*kolvo)
{
for(int i=0; i<kolvo; i++)
    {
        cout<<"Фамилия:"<<bd[i].fam;
        cout<<endl;
        cout<<"Имя:"<<bd[i].name;
        cout<<endl;
        cout<<"Инициалы:"<<bd[i].ini;
        cout<<endl;
        cout<<"Улица:"<<bd[i].ylica;
        cout<<endl;
        cout<<"Дом:"<<bd[i].dom;
        cout<<endl;
        cout<<"Номер телефона:"<<bd[i].namber;
        cout<<endl;
        cout<<endl;
        cout<<endl;
    }
    help();
    switch1 ();
}

void switch1 (*kolvo)
{
    int x;
    cin>>x;
    switch(x)
    {
        case 0:   help();                            break;
        case 1:   vvod(*kolvo);                         break;
        case 4:   screach (*kolvo);                         break;
      //  case 2:   send();                            break;
        case 3:   deletebd(*kolvo);                            break;
        case 5:   list(*kolvo);                            break;
        //case 7:   cout<<"Открыть предидущую базу номеров?"; openf();  break;
        case 6:   cout<<"\nGood Bye!\n"; clsave(*kolvo); exit(0);            break;
        default:  cout<<"Ошибка ввода. Повторите выбор.\n";  switch1(); break;
    }
    cout<<"\n";
}

void clsave(*kolvo)
{
  ofstream F("result.txt");
   for(int i=0;i<kolvo;i++)
   {
       F<<bd[i].fam<<" ";
       F<<bd[i].name<<" ";
       F<<bd[i].ini<<" ";
       F<<bd[i].ylica<<" ";
       F<<bd[i].dom<<" ";
       F<<bd[i].namber<<" ";
   }
   F.close();
}
/**
void openf()
{
  char fname[25] ;
  cout<<"Введите имя базы номеров ";
  cin>>fname[25];
  ofstream F("result.txt");
   for(int i=0;i<10;i++)
   {
       F>>bd[i].fam>>" ";
       F>>bd[i].name>>" ";
       F>>bd[i].ini>>" ";
       F>>bd[i].ylica>>" ";
       F>>bd[i].dom>>" ";
       F>>bd[i].namber>>" ";
   }
   F.close();
   help();
   switch1 ();
}
**/

void screach (*kolvo)
{
  char famm[20];//слово для поиска
  cout<<"Введите фамилию : ";
  cin>>famm;
  cout<<"\n";
  //char fam[20];
  for(int i=0; i<kolvo; i++)
  {
    if(bd[i].fam==famm)
    {
          cout<<"Фамилия:"<<bd[i].fam;
          cout<<endl;
          cout<<"Имя:"<<bd[i].name;
          cout<<endl;
          cout<<"Инициалы:"<<bd[i].ini;
          cout<<endl;
          cout<<"Улица:"<<bd[i].ylica;
          cout<<endl;
          cout<<"Дом:"<<bd[i].dom;
          cout<<endl;
          cout<<"Номер телефона:"<<bd[i].namber;
          cout<<endl;
          cout<<endl;
          cout<<endl;

      help();
      switch1 ();
      }
      else
      {
        cout<<"Абонент не найден "<<endl;
        help();
        switch1 ();
      }
    }
}

int main()
{

    int kolvo;
    cout<<"Введите количество абонентов\n";
    cin>>kolvo;

    telefon bd [kolvo];

    help();
    switch1 (*kolvo, *bd);
    return 0;
}
