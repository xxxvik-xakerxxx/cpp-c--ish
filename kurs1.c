#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

string encode(long lSize, long * lKey, string fPath) //кодируем
{
    long i, j;
    string text, line, encstr;
    ifstream ifs(fPath.c_str());
    if(!ifs)
        cout<<"Error open file : "<<fPath.c_str()<<endl; // читаем файлик
    else
    {
        while(getline(ifs,line))
            text += line;
        ifs.close();
        cout<<"input string : "<<text.c_str()<<endl;
        for(i = 0; i < text.length(); i += lSize) //простой алгоритм кодирывания по ключу
        {
            line = "";
            for(j = 0; j < lSize; j++)
                line += text[i + j];
            for(j = 0; j < lSize; j++)
                encstr += line[lKey[j]];
        }
    }
    return encstr;
}

string decode(long lSize, long * lKey, string fPath) //декодируем
{
    long i, j;
    string text, line, decstr;
    ifstream ifs(fPath.c_str());
    if(!ifs)
        cout<<"Error open file : "<<fPath.c_str()<<endl; //читаем файл
    else
    {
        while(getline(ifs,line))
            text += line;
        ifs.close();
        cout<<"input string : "<<text.c_str()<<endl;
        decstr = text;
        for(i = 0; i < text.length(); i += lSize) // алгоритм  декодирывания
        {
            for(j = 0; j < lSize; j++)
                decstr[i + lKey[j]] = text[i + j];
        }
    }
    return decstr;
}

int main()
{ //переменные
    char chr;
    long lKey[5] = {0};
    long i, lSize= sizeof(lKey)/sizeof(lKey[0]);

    bool bMenu = true;
    string text;
    while(bMenu)
    {
        cout<<"***MENU***\n"; //меню
        cout<<"E - encode\n";
        cout<<"D - decode\n";
        cout<<(chr = getch())<<endl;
        switch(toupper(chr))
        {
        case 'E':
            cout<<"Enter key-block : \n"; //запрос ключа
            for(i = 0; i < lSize; i++)
            {
                cout<<"KEY["<<i + 1<<"] = ";
                cin>>lKey[i];
            }
            text = encode(lSize, lKey, "encode.txt"); //забираем текст из файла передаем в функцию
            cout<<"Encoded text : "<<text.c_str()<<endl;
            break;
        case 'D':
            cout<<"Enter key-block : \n"; //опють просим ключ
            for(i = 0; i < lSize; i++)
            {
                cout<<"KEY["<<i + 1<<"] = ";
                cin>>lKey[i];
            }
            text = decode(lSize, lKey, "decode.txt"); //бпрем данные из файла декодируем по ключу
            cout<<"Decoded text : "<<text.c_str()<<endl;
            break;
        default:
            cout<<"Unsupported key is pressed\n";
            break;
        }
        cout<<"Press Y for see MENU once again\n"; // просим выйти или продолжить
        cout<<"Any other key - EXIT\n";
        cout<<(chr = getch())<<endl;
        if(toupper(chr) != 'Y')
            bMenu = false;
        system("cls");
    }
    system("pause"); //задержка
    return 0;
}
