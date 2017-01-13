#include <iostream> 
using namespace std ;
int sliv(int A[], int B[],int i,int n)
{
  int C[n+n],k,j;
do{
    while (A[i]<B[j]&&i<n)
    {
      C[k++]=A[i];
      i++;
    }
    while (A[i]>B[j]&&j<n)
    {
      C[k++]=B[j];
      j++;
    }
    while (A[i]==B[i]&&i<n&&j<n)
    {
      C[k++]=A[i++];
      C[k++]=B[j++];
          }
        if(i==n)
          while (j<n)
            C[k++]=B[j++];
          if(j==n)
            while (i<n)
              C[k++]=A[i++];

  }
  while (k<n+n);
  for(i=0; i<n; i++)
    cout<<C[i]<<' ';

}

int main()
{
  const int n=5;
  int A[n];
  int B[n]; 
  int C[n+n];
  int i, j, k;
  cout<<"el 1 mas";
  for (i=0; i<n; i++)
    cin>>A[i];
  cout<<"el 2 mas";
  for (i=0; i<n; i++)
    cin>>B[i];
  i=0,j=0,k=0;

  sliv(A,B,i,n);
  cout<<"result";
  
  return 0;

}