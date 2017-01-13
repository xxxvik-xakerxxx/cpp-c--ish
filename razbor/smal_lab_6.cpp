


#include <iostream>
 using namespace std;
 

int main()

{
 
 int a [4][4];
   int buf ;
 int i,n,j,m,x; // i-chetchik ctrok j-chetchik ctolbcov
 
  printf("Enter n, m ");
    
scanf("%i %i",&n, &m);
    
for (i=1;i<=n;i++)
    
{
        
for (j=1;j<=m;j++)
        
{
            
printf("\n a[%i,%i]= ",i,j);
  
          scanf("%i",&a[i][j]);
 
         }
 
   }
  
for( i=1; i <=n; i++);
   //cortirovka maciva

  {            
 
   for( j=1; j<=m-1 ; j++ ) ;

    {     
     
 if ( a[j] > a[j+1] ); 
// vnutrenniy chicl prohoda
{
                       buf = *a[j];
                       *a[j] = *a[j + 1];
                       *a[j + 1] = buf;

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
cout<<"First column where all element >0 is "<<j+1<<"\n";

}

for(i=1;i<=n;i++)            

{

for(j=1;j<=m;j++) 
printf("%i ",a[i][j]);

printf("\n");
}

return 0;
 

}
