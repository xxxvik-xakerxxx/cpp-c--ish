#include <iostream>
#include "error.h"
using namespace std;
int Readint()
{
    unsigned int a;
    cin >> a;
    if (!cin)
    {
        cin.clear();
        while (cin.peek() !='\n')
            cin.ignore();
        cin.ignore();
    }
    return a;
}
