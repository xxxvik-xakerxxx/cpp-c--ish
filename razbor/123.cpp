  #include "stdafx.h"
#include<string.h>                                   //библиотека строковых функций
#include<conio.h>                                   //библиотека консольных функций
#include<stdlib.h>
#include <iostream>                            //библиотека функций ввода, вывода
using namespace std;
// область описания директив

#include "stdafx.h"

const int size = 80;

char *SkipSpace(char *pTmp);
char *SkipWord(char *pTmp);
char *CopyWord(char *from, char * to);

char *works(char *one, char *two, char *Result);


int lengthword(char *pTmp); // скорее всего не нужна!
int IsIn(char *p1, char *p2);
int comp(char *p1, char *p2);

int main() // главная функция
{
	char sfirst[size], sscnd[size], sresult[size];
	while(cout << "\nPlease input FIRST sentense:\n", cin.getline(sfirst,size)){ // ввод первой строки

		cout << "\nPlease input Second sentense:\n", cin.getline(sscnd,size); // ввод второй строки

		works(sfirst, sscnd, sresult); // получение результата

		cout << "\nThe first sentense\n" << sfirst << endl; // вывод первой исходной строки
		
		cout << "\nThe second sentense\n" << sscnd << endl; // вывод второй исходной строки
		
		cout << "\nThe RESULT sentense\n" << sresult << endl; // вывод результата
	}
	return 0;
{

char *SkipSpace(char *pTmp){
	for(;*pTmp == ' ' || *pTmp == '\t';pTmp++);
	return pTmp;
}
{
char *SkipWord(char *pTmp){
    for(;*pTmp != '\0' && *pTmp != ' ' && *pTmp != '\t';pTmp++);
    return pTmp;
}
{
int lengthword(char *pTmp){
    int n=0;
    for(;*pTmp != ' ' && *pTmp != '\t'; pTmp++, n++);
	return n;
}			 
{
char *works(char *one, char *two, char *Result){
  *Result='\0';
  while((one = SkipSpace(one)) && (*one != '\0' && *two !='\0')){
    if(IsIn(one, two))
      Result = CopyWord(one, Result);
    one = SkipWord(one);
  }
{
return  Result;

}
{
int IsIn(char *p1, char *p2){
  while((p2 = SkipSpace(p2)) && *p2 !='\0'){
    if(comp(p1, p2))
      return 1;
    p2 = SkipWord(p2);

  }
{

return 0;

}
{
         int comp(char *p1, char *p2){
         int Flag = 0;
          for(;*p1!= ' ' && *p1 != '\t' && (*p1 !='\0' || *p2 !='\0'); *p1++, *p2++)
         if(*p1 != *p2) {
           Flag = 1;
          break;
    }
{
      if (Flag)
        return 0;
       else 
       return 1;
}
{
             char *CopyWord(char *from, char *to){
	            char *temp;
	            for (temp = to; *temp; temp++);
	             while (* temp++ = * from++);
	             return to;

}
