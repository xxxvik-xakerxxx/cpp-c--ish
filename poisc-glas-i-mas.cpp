#include <iostream>
#include <string.h>
using namespace std;
 
int main(){
    
 
    
    const char* glas = "aeiouауеоэяию";
    
    char array1[10][256]={""};//Массив для слов.
    int k=0,array1_cout=0;
 
    char predl[256];
 
    cout<<"Введите предложение"<<endl<<">>>";   
    cin.getline(predl, sizeof(predl));
    cout<<endl<<"Вы ввели: "<<predl<<endl;
        
 
    char * pch;
    const char* delim = " ";
    pch=strtok(predl,delim);
 
    while(pch!=NULL)
    {
        int mk = k;
        char newcharmas[256] = "";
        for (int i = 0; pch[i]; i++)
        {
            if(strchr(glas, pch[i]))
            {
                k++;
            }
        }
        if (mk!=k)
        {//Основные изменения в этой части кода.
            strcat(newcharmas,pch);
            for (int j=0;j<=strlen(newcharmas);j++)
            {
                array1[array1_cout][j]=newcharmas[j];
            }
            array1_cout++;
            
        }
        pch=strtok(NULL,delim);
    }
 
    cout<<endl<<"В данном предложении "<<k<<" гласных букв.";
    cout<<endl<<"Создан новый массив слов: "<<endl<<endl;
    int w=0;
    for (int q=0; q<=array1_cout;q++)
    {
        for (w=0;w<=256;w++)
        {
            if (array1[q][w]!=NULL)
            {
                cout<<array1[q][w];
            }
        }
        cout<<endl;
    }
 
    
   
 
 
}