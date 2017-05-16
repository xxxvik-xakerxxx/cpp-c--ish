#include<iostream>
using namespace std;
struct node
{
  int  elem;
  node *sled;
};
 class Spisok {
   private:
     node *phead, *Res;
   public:
     Spisok() {phead=new(node);Res=NULL;}
     ~Spisok() {delete phead;}
     void POSTROENIE ();
     void VYVOD ();
     node *POISK (int);
     void YDALE ();
     void DOBAV();
     void OCHISTKA();
 };

int main ()
{
  Spisok A;
  int   el;
  node *Res_Zn;

  A.POSTROENIE ();
  A.VYVOD ();
  cout<<"\nВведите элемент звена, после которого ";
  cout<<"осуществляется удаление:\n";
  cin>>el;
  Res_Zn=A.POISK (el);
  if  (Res_Zn!=NULL && (*Res_Zn).sled!=NULL)
    {A.YDALE (); A.VYVOD ();}
  else  cout<<"Звена с заданным элементом в списке нет!";
  cout<<"\nВведите элемент звена, на место которого ";
  cout<<"осуществляется добавление:\n";
  cin>>el;
  Res_Zn=A.POISK (el);
  if  (Res_Zn!=NULL && (*Res_Zn).sled!=NULL)
    {A.DOBAV (); A.VYVOD ();}
  else  cout<<"Звена с заданным элементом в списке нет!";
  A. OCHISTKA();
}

void Spisok::POSTROENIE ()

{
  node *t;
  int  el;

  t = phead; (*t).sled = NULL;
  cout<<"Вводите элементы звеньев списка: \n";
  cin>>el;
  while  (el!=0)
  {
    (*t).sled = new (node);
    t = (*t).sled; (*t).elem = el; (*t).sled = NULL;
    cin>>el;
  }
}

void Spisok::VYVOD ()

{
  node *t;

  t = phead; t = (*t).sled;
  cout<<"Список: ";
  while  (t!=NULL)
  {
         cout<<(*t).elem <<" ";
    t = (*t).sled;
  }
}

 node *Spisok::POISK (int el)

{
  node *t;

  Res = NULL; t = phead; t = (*t).sled;
  while  (t!=NULL && Res==NULL)
    if  ((*t).elem==el)  Res = t;
    else  t = (*t).sled;
  return Res;
}

void Spisok::YDALE ()

{
  node *q;
  q = (*Res).sled;
  if  (q!=NULL)
  {

    (*Res).sled = (*(*Res).sled).sled; delete q;
  }
  else
    cout<<"Звено с заданным элементом - последнее!\n";
}

void Spisok::DOBAV ()

{
  node *q;
  int  el;
  q = Res;
  cout<<"Вводите добавляемый элемент : ";
  cin>>el;
    (*q).elem = el;

}

void Spisok::OCHISTKA ()

{
  node *q,*q1;

  q = phead;
  q1 = (*q).sled;
  while (q1!=NULL);
  { q = q1; q1 = (*q1).sled; delete q;}
}
