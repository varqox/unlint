#include "unlint.h"
#include <iostream>

using namespace std;

int main()
{
	unlint a, c, b;
    cin >> a >> b;
    for(int i=0; i<1000; ++i)
    	a=a-b;
    cout << a << endl;
return 0;
}