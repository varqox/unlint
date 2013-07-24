#include "../unlint.hpp"
#include <iostream>

using namespace std;

int main()
{
	unlint a, c, b;
    cin >> a >> b;
    cout << (a/=b) << endl;
return 0;
}