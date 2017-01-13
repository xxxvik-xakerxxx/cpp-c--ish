#include <iostream>
 
char* Rus(const char* text);
 
using namespace std;
 
int* bubble_sort(int s[],int n);
 
int main()
{
 setlocale(0,"Rus");
 int n;
 cout<<"Введите количество элементов массива:"<<endl;
 cin>>n;
 int *s=new int [n];
 int i;
  for (i=0; i<n; i++)
        {
          cout<<"Введите "<<i+1<<" из "<<n<<" элементов массива"<<endl;
          cin>> s[i];
        }
  cout<<"Ваш массив:"<<endl;
   for(i=0;i<n;i++)
       {
          cout << s[i]<<"  ";
       }
       bubble_sort(s,n);
 cout<<"\nОтсортированный массив"<<endl;
 for(int f=0;f<n;cout<<endl<<s[f],f++);
 delete []s;
 
return 0;
}
 
 int* bubble_sort(int s[], int n)
 {
   if (n % 2 ==0)
   {
   int i,swap,t,max, mid;
   for(i=0;i<n;i++)
       {
          max=s[i];
          mid=i;
          for(t=(i+1);t<n;t++)
             {
                 if (s[t]<max) {mid=t; max=s[t];};
             }
         swap=s[i];
         s[i]=s[mid];
         s[mid]=swap;
       }

     }
     else 
     {
      int i,swap,t,max, mid;
   for(i=0;i<n;i++)
       {
          max=s[i];
          mid=i;
          for(t=(i+1);t<n;t++)
             {
                 if (s[t]>max) {mid=t; max=s[t];};
             }
         swap=s[i];
         s[i]=s[mid];
         s[mid]=swap;
       }
     }
   return s;
 }