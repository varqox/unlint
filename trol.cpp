#include "unlint.h"
#include <iostream>

using namespace std;

int main()
{
	unlint a, b;
	cin >> a >> b;
	cout << "-----------\n" << a-b << endl;
	a-=b;
	cout << a << endl;
return 0;
}