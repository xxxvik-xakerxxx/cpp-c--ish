# include <iostream>
using  namespace  std;
int main()
{
        int n,m,i,k,d,l;
        int **mas;
        float rab;
        cout<<"Vveditе kilkist' strok (n) i stolbcov (m)"<<endl;
        cin>>n>>m;
//створюємо динамічний масив
        mas=new int*[n];      //створюємо масив покажчиків
        for(i=0;i<n;i++)
           mas[i]=new int[m]; //створюємо динамічні строки
        cout<<"Vveditе elementi massiva"<<endl;
//заповнюємо масив з клавіатури
        for(i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mas[i][j];
// Виведення на екран вихіного масиву 
cout<<"vihidna matrica"<<"\n";
        for(i=0;i<n;i++,cout<<endl)
        for(int j=0;j<m;j++)
            cout<<mas[i][j]<<"\t";
            cout<<"\n";
            int maxval[m];
        //знаходимо максимальні елементи стовпців
                    for (int j=0; j<m; ++j)
                {
        maxval[j]=mas[0][j];
        for (i = 1; i<n; ++i)
            if (mas[i][j]>maxval[j])
                maxval[j]=mas[i][j];
                            }
                            // сортування по зменшенню
for (l=1; l<m; l++)
for (d=0;d<l;d++)
          if(maxval[d]<maxval[d+1])
	{
	    rab=maxval[d];
	      maxval[d]=maxval[d+1];
          maxval[d+1]=rab;
          }
// виведення на екран відсортованого масиву
 cout<<"vidsortovaniy masiv"<<"\n";
 for (k=0; k<m; ++k)
cout<<maxval[k]<<" ";
return 0;
}
