#include "unlint.h"
#include <iostream>

using namespace std;

int main()
{
	unlint a, c, b;
    cin >> a >> b;
#ifdef _1
    cout << --a;
#elif _2
    cout << a--;
#elif _3
    cout << ++a;
#elif _4
    cout << a++;
#elif _5
	cout << -a;
#elif _6
	cout << +a;
#elif _7
	cout << a+b;
#elif _8
	cout << (a+=b);
#elif _9
	cout << a-b;
#elif _10
	cout << (a-=b);
#elif _11
	cout << a*b;
#elif _12
	cout << (a*=b);
#elif _13
	cout << a/b;
#elif _14
	cout << (a/=b);
#elif _15
	cout << a%b;
#elif _16
	cout << (a%=b);
#elif _17
	cout << nwd(a,b);
#elif _18
	cout << pow(a,b);
#elif _19
	cout << a.pow(b);
#elif _20
	cout << factorial(a);
#elif _21
	cout << a.factorial();
#endif
    cout << endl;
return 0;
}