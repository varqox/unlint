#include "../unlint.hpp"
#include <iostream>
#include "../../stream/allinone.cpp"

using namespace std;

int main()
{
	unlint a, c, b;
    cin >> a >> b;
    cout << (a*=b) << endl;
return 0;
}