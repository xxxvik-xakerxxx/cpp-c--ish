#include <iostream>
#include<stdio.h>
#include <string.h>
#include <math.h>

int j, k, r, q, i;
float m, n;
char s[] = {"Както так "}, buf[16];
void Mymain(char *s)
{
    n = strlen(s);//длинна строки
    m = sqrt(n);//длинна ширины массива
    q =i*m;
    //считываем  символы и записываем их в матрицу
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
        {
            buf[q + j] = s[k];
            k++;
        }
    //шифруем
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
        {
            s[k] = buf[q + i];
            k++;
        }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c", s[k] = buf[q + i]);
        }
    }
}
int main()
{
    printf("%s\n", s);
    Mymain(s);
}
