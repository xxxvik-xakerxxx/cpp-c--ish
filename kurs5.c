#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>

using  namespace std;

char *shifr(char *key, char *text)
{


    srand((unsigned)time(NULL));


    char txt[5][9] = {0};
    char txtend[33] = {0};
    int n = 0;
    int m = 0;
    int d = 0;

    cout << "Введите кол-во строк:" << endl;
    cin >> n;

    cout << "Введите ключ:" << endl;
    cin >> key;

    m = 0;



    for(int i = 0; i < strlen(key); i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(m != strlen(text))
            {
                txt[j][i] = text[m];
                m++;
            }
            else
            {
                txt[j][i] ='0';

            }

        }
    }



    cout << "Tекст:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < strlen(key); j++)
        {
            cout << txt[i][j];
        }
        cout << endl;
    }



    for(int j = 0; j < strlen(key); j++)
    {
        for(int i = j; i < strlen(key); i++)
        {
            if(key[i] < key[j])
            {
                char tmp = key[j];
                key[j] = key[i];
                key[i] = tmp;

                for(int k = 0; k < n; k++)
                {
                    char tmp2 = txt[k][i];
                    txt[k][i] = txt[k][j];
                    txt[k][j] = tmp2;
                }
            }
        }
    }



    cout << endl << "Зашифрованный текст:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < strlen(key); j++)
        {
            cout << txt[i][j];
        }
        cout << endl;
    }

    int z = 0;



    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < strlen(key); j++)
        {
            txtend[z] = txt[i][j];
            z++;
        }
    }


    return txtend;
};

char *deshifr(char *key, char *text)
{

    char txt[5][9] = {0};
    int sortkey[9] = {0};
    char txtend[33] = {0};
    int schet = 0;
    int n = 0;


    cout << "Введите кол-во строк:" << endl;
    cin >> n;

    cout << "Введите ключ:" << endl;
    cin >> key;



    for(int schet = 0; schet < strlen(key); schet++)
    {
        sortkey[schet] += schet;
    }



    for(int j = 0; j < strlen(key); j++)
    {
        for(int i = j; i < strlen(key); i++)
        {
            if(key[i] < key[j])
            {
                char tmp = key[j];
                key[j] = key[i];
                key[i] = tmp;

                char tmp2 = sortkey[i];
                sortkey[i] = sortkey[j];
                sortkey[j] = tmp2;
            }
        }
    }


    int m = 0;



    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < strlen(key); j++)
        {
            if(m != strlen(text))
            {
                txt[i][j] = text[m];
                m++;
            }
        }
    }

    cout << "Зашифрованный текст:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < strlen(key); j++)
        {
            cout << txt[i][j];
        }
        cout << endl;
    }

    for(int j = 0; j < strlen(key); j++)
    {
        for(int i = j; i < strlen(key); i++)
        {
            if(sortkey[i] < sortkey[j])
            {
                char tmp = sortkey[j];
                sortkey[j] = sortkey[i];
                sortkey[i] = tmp;

                for(int k = 0; k < n; k++)
                {
                    char tmp2 = txt[k][i];
                    txt[k][i] = txt[k][j];
                    txt[k][j] = tmp2;
                }
            }
        }
    }

    cout << endl << "Расшифрованный текст:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < strlen(key); j++)
        {
            cout << txt[i][j];
        }
        cout << endl;
    }

    int z = 0;


    for(int i = 0; i < strlen(key); i++)
    {
        for(int j = 0; j < n; j++)
        {
            txtend[z] = txt[j][i];
            z++;
        }
    }


    return txtend;
};

int main()
{
    FILE *f1, *f2;
    char *m;
    char _key[9];
    char buff[33] = {0};

    setlocale(LC_ALL, "Russian");
    cout << "1 Шифрование текста" << endl;
    cout << "2 Расшифрование текста" << endl;
    cout << "--------------------------------" << endl;

    switch (getchar())
    {
        case '1':
            {

                char _txt[33] = {0};
                f1 = fopen("D://text.txt", "r");
                do{
                    fgets(_txt, sizeof(_txt), f1);
                    m = shifr(_key, _txt);
                    strcat(buff, m);
                    strcat(buff, "\n");
                }while(!feof(f1));
                fclose(f1);

                f2 = fopen("D://text2.txt", "w");
                fprintf(f2, "%s", buff);
                fclose(f1);
                fclose(f2);
                system("pause");
                break;
            }

        break;

        case '2':
            {
                char _txt2[33] = {0};
                f1 = fopen("D://text2.txt", "r");
                do{
                    fgets(_txt2, sizeof(_txt2), f1);
                    m = deshifr(_key, _txt2);
                    strcat(buff, m);
                    strcat(buff, "\n");
                }while(!feof(f1));
                fclose(f1);

                f2 = fopen("D://text3.txt", "w");
                fprintf(f2, "%s", buff);
                fclose(f1);
                fclose(f2);
                system("pause");
                break;

            }


        break;
    }

}
