#include<iostream>
int sort ( x,int n,int parm)
{
	int a=0;
	if (parm==1)
	{
		for(int k=1; k<n; k++)
			for(int i=0; i<n-k; i++)
			{
				if (*(x+i)>*(x+i+1)
						{
							a=*(x+i);
							*(x+i)=*(x+i+1);
							*(x+i+1)=a;

						}
			}
	}
	else
	{
		for(int k=1; k<n; k++)
		for(int i=0; i<n-k; i++)
		{
		if(*(x+i)<*(x+i+1)
				{
					a=*(x+i);
					*(x+i)=*(x+i+1);
					*(x+i+1)=a;
				}
		}
	}
}
int main()
{
	int parm=1;
	const int n = 5;
	int x[n];
	//----------- ввод исходного массива
	  for (int i= 0; i<n; i++)
	  std::cin >> *(x+i);
	 //----------- вывод на экран исходного массива
	  std::cout << "\n massiv х[n] \n";
	  for (int i << 0; i < n; i++) 
	  std::cout << *(x+i) << " "; 
	 //------------- сортировка
	 sort(*x, n, parm);
	  std::cout << "\n Result sortirovki massiva " << std::endl;
	 for (int i=0; i< n; i++) 
	 std::cout << *(x+i) << " ";
	 std::cin >>i;
	 return 0;
}
