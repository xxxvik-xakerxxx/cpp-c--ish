#include <iostream>
#include <iomanip>
using namespace std;
 
int main()
{
    int const n = 3, m = 4;
    bool flag = false;
    int mas[n][m];
 
    cout << "Enter the matrix:\n";;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cout << "Enter the matrix element[" << i+1 << "][" << j+1 << "]: ";
                cin >> mas[i][j];
        }
 
    cout << "\n\nYour matrix:\n";;
    for(int i = 0; i < n; i++)
    {
        cout << "\n\t";
        for(int j = 0; j < m; j++)
            cout <<  setw(3) << mas[i][j] << " ";
    }
 
    cout << "\n";
 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mas[i][j] < 0)
            {
                int sum = 0;  
                for(int k = 0; k < m; k++) 
                    sum += mas[i][k];
 
                cout << "\nAmount of line items [" << i + 1 << "] = " << sum;
            }
        }
    }
 
    cout << "\n\n";
 
    int stb, str, min, max;
    for(int i = 0; i < n; i++)
    {
       stb = 0;
       min = mas[i][0];
 
       for(int j = 0; j < m; j++)
       {
           if(mas[i][j] <= min)
           {
               min = mas[i][j];
               stb = j;
           }
       }
        
       str = 0;
       max = mas[0][stb];
 
       for (int k = 0; k < n; k++)
       {
           if(max <= mas[k][stb])
           {
               str = k;
               max = mas[k][stb];
 
               if(min == max)
               {
                    cout << "i = " << str << "  " << "j = " << stb << "  " <<
                    "Saddle point = " << mas[str][stb] << endl;
                    flag = true;
                }
           }
       }
    }
 
    if(flag = false)
        cout << "No saddle points!\n\n";
 
    cout << "\n\n";
    return 0;
}
