#include <iostream>
int main(){
	    int arr1[] = {1,2,3,4,5},len1 = sizeof(arr1)/sizeof(*arr1);
		    int arr2[] = {5,6,7,8,3,10},len2 = sizeof(arr2)/sizeof(*arr2);
			int **arr4;
			    for (int i=0; i < len1 ; i++){
					        for (int j=0; j < len2; j++)
							{
								            if (arr1[i] == arr2[j])
												arr1[i]=arr4[i][j];
												std::cout << arr1[i] << ' ';
				}
				}
                for (int i=0; i<len1; i++)
					for(int j=0; j<len1; j++)
					std::cout<< arr4[i][j]; 
				    return 0;
}
