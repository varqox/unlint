#include "unlint.h"
#include <iostream>

using namespace std;

int main()
{
	unlint a, b;
    cin >> a >> b;
    if(a<b) cout << a << "<" << b  << endl;
    if(a>b) cout << a << ">" << b  << endl;
    if(a==b) cout << a << "==" << b  << endl;
    if(a!=b) cout << a << "!=" << b  << endl;
    if(a<=b) cout << a << "<=" << b  << endl;
    if(a>=b) cout << a << ">=" << b  << endl;
return 0;
}