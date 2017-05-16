#include <iostream>

using namespace std;
struct list
{
  list *prev;
  int num, id;
  list *next;
};
void Show(list *begin)
{
  list *temp=begin;
  cout<<"\n";
  while(temp)
  {
    cout << temp->num<<"\t";
    temp=temp->next;
  }
  cout<<"\n";
}

int main()
{
  list *begin = NULL;
  list *end = NULL;
  int num, menu;
  int id=0;
  cout<<"KolVoEl \n";
  cin>>id;
  bool m=true;
  do{
    cout<<"1.Add \n";
    cout<<"2.DelEl \n";
    cout<<"3.AddKel \n";
    cout<<"4.Exit \n";
    cin>>menu;
    switch(menu){
      case 1:
      cout<<"Vod el: ";
      for (int i=0; i<id; i++)
      {
        if(begin==NULL)
        {
          begin = new list;
          cin>>begin->num;
          begin->id=i;
          end = begin;
          end->next = NULL;
        }
        else{
          end->next = new list;
          end = end->next;
          end->next = NULL;
          cin>> end->num;
          end->id=i;
        }
      }
      Show(begin);
      break;
      case 2:
      {
        int idd;
        cout<<"Vvedite nomer elementa: ";
        cin>>idd;
        list *temp=begin;
        cout<<"Ua tut1";
        while(temp)
        {
          cout<<"Ua tut2";
          if (temp->id==idd)
          {
            cout<<"Ua tut3";
            begin=begin->next;
            for(int i=0; i<id; i++)
            {
              cout<<"Ua tut4";
              begin->id=i;
              end = begin;
              end->next = NULL;
            }

          }temp=temp->next;
        }

      }
      Show(begin);
      break;
      case 4:
      {
        m=false;
      }
    }
  }while (m==true);

  return 0;
}
