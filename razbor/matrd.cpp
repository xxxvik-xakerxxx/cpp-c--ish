#include <stdio.h>
#include <stdlib.h>
#define SIZE_ARRAY 10       
#define MAX_INTEGER 10      
int myarray[SIZE_ARRAY][SIZE_ARRAY];
int main()
{

	int NeedString=0; 
	int max = 0;      
	printf("Array:\n");
				
	for (int i = 0; i < SIZE_ARRAY; i++)
	 {
		for (int ii = 0; ii < SIZE_ARRAY; ii++)
		 {
			 myarray[i][ii] = rand()%MAX_INTEGER;
			 printf("%3d ", myarray[i][ii]);
		 }
		 printf("\n");
	 }
	printf("Vvedite nomer stroki: ");
	scanf("%d", &NeedString);
	while (NeedString <= 0 || NeedString > SIZE_ARRAY) 
	{ 
		printf("Vvedite v diapazone ot 1 do %d:  ", SIZE_ARRAY);	
		scanf("%d", &NeedString);
printf("\n"); 																											               
	} NeedString--;
															 
	 for (int i = 0; i < SIZE_ARRAY; i++)  
	 {
	   if (myarray[NeedString][i] > max) max = myarray[NeedString][i];
	 }
	 printf("Max element v stroke %d\n", max); 
	 printf("Sdvig %d strok na %d element vpravo\n", NeedString+1, max);
	 for (int i = 0; i < max; i++) 
	 {
		 int save = myarray[NeedString][SIZE_ARRAY-1];
		 printf("%d: ", i+1);

		 for (int ii = SIZE_ARRAY-1; ii > 0; ii--)
		 {
			 myarray[NeedString][ii] = myarray[NeedString][ii-1];
		 }
		 myarray[NeedString][0] = save;
		 for (int i = 0; i < SIZE_ARRAY; i++) printf("%3d ", myarray[NeedString][i]);
		 printf("\n");
	 }
																		 
	 scanf("%d", &NeedString);
 	return 0;
}
