#include "MyClass.h"
#include <iostream>

using namespace std;

MyClass::MyClass(int a, int b)
: regVar(a), constVar(b)
{
 cout << regVar << endl;
 cout << constVar << endl;
}
