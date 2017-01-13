


#include <iostream>
 using namespace std;
 

int main(int argc)

{
 
 int a [4][4];
   
 int i,n,j,m,k,x; // i-счётчик cтрок j-счётчик столбцов
 
  printf("Enter n, m ");
    
scanf("%i %i",&n, &m);
    
for (i=1;i<=n;i++)
    
{
        
for (j=1;j<=m;j++)
        
{
            
printf("\n a[%i,%i]= ",i,j);
  
          scanf("%f",&a[i][j]);
 
         }
 
   }
  
for( i=1; i <=n; i++);
   //cортировка массива

  {            
 
   for( j=1; m-1<=j ; j++ ) ;

    {     
     
 if ( a[j] > a[j+1] ); 
// внутренний цикл прохода
      {
     
 x=a[j+1];
  
    a[j+1]=a[j]; 
 
     a[j]=x;
     
 }
    
}
  
}
       

 
for(int j=1;j<=m;j++)

{

bool ext=true;

for(int i=1;i<=n;i++)

if(a[i][j]<0)

{

ext=false;

break;

}

if(ext)
cout<<"First column where all element >0 is "<<j+1;

}

for(i=1;i<=n;i++)            

{

for(j=1;j<=m;j++) 
printf("%f ",a[i][j]);

printf("\n");
}

return 0;
 

}