#include <iostream>
#include <iomanip>
#include <fstream>

void summ (int ( &mass ) [ 4 ] [ 4 ] )
 {
 int sum ( 0 ) ;
 for (int i = 0 ; i <4 ; i++)
 for (int j = i + 1 ; j <4 ; j++)
sum+=mass [ i ] [ j ] ;
 std::cout << " summ = " << sum << std::endl;
if(sum %2 !=00)
{
for (int i = 0 ; i < 4 ; i++) 
mass [ i ] [ i ] = 0 ;
}

}

int main()
{
int mass [4] [4];
 for ( int i = 0 ; i <4 ; i++)
 for ( int j = 0 ; j <4; j++) { 

std::cout << " Enter mas ["<< i <<"] [ "<< j <<"] = " ;
std::cin >> mass [ i ] [ j ] ;
 } 
summ ( mass ) ; 
for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            std::cout << std::setw(3) << mass[i][j] << " " ;
        std::cout << std::endl;
}
 

return 0;
}