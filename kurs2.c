#include <iostream>

using namespace std;

const int FIRST_SYMBOL = ' '; // первый символ
const int SYMBOL_NUMBER = 95; // для простоты кодируем только английский алфавит

void GammaCoding( char *input, char *gamma, char *result )
{
  for( char *i=input, *j=gamma; *i; i++, j++ )
  {
    if(!(*j)) j=gamma;
    int Ti = *i - FIRST_SYMBOL;
    int Gi = *j - FIRST_SYMBOL;
    *(result++) = FIRST_SYMBOL+(Ti+Gi)%SYMBOL_NUMBER;
  }
  *result = '\0';
}

void GammaDecoding( char *input, char *gamma, char *result )
{
  for( char *i=input, *j=gamma; *i; i++, j++ )
  {
    if(!(*j)) j=gamma;
    int Ci = *i - FIRST_SYMBOL;
    int Gi = *j - FIRST_SYMBOL;
    *(result++) = FIRST_SYMBOL+(Ci-Gi+SYMBOL_NUMBER)%SYMBOL_NUMBER;
  }
  *result = '\0';
}

int main()
{

    char str1[256], gamma[256], rez[256];

    cout << "Введите исходное сообщение: ";
    cin >> str1;
    cout << "Введите гамму: ";
    cin >> gamma;

    GammaCoding( str1, gamma, rez );
    cout << "Зашифрованное сообщение: ";
    cout << rez << endl;

    cout << "Введите зашифрованное сообщение: ";
    cin >> rez;

    GammaDecoding( rez, gamma, str1 );
    cout << "Исходное сообщение: ";
    cout << str1 << endl;


    return 0;
}
