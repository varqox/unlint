#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <fstream>

using namespace std;

template<typename type>
type abs(type a)
{
	if(a<0) return -a;
return a;
}

int rd()
{
return abs(rand());
}

string to_string(int a)
{
	stack<char> st;
	while(a>0)
	{
		st.push('0'+a%10);
		a/=10;
	}
	string w;
	while(!st.empty())
	{
		w+=st.top();
		st.pop();
	}
	if(w.empty()) w="0";
return w;
}

int main()
{
	srand(time(NULL));
	int t;
	cin >> t;
	fstream test;
	{int ___e=system("g++ cont.cpp -s -O3 -D_21 -o cont && mkdir -p tests/21/ && rm -f tests/21/*");}
	for(int q=1; q<=t; ++q)
	{
		string in, in1, out, spr, test_name;
		test_name="tests/21/"+to_string(q);
		for(int i=rd()%4; i>=0; --i)
		{
			in+=static_cast<char>(rd()%10+'0');
		}
		for(int i=rd()%4; i>=0; --i)
		{
			in1+=static_cast<char>(rd()%10+'0');
		}
		test.open((test_name+".in").c_str(), ios_base::out);
		test << (rd()%2 ? "-":"") << in << " " << (rd()%2 ? "-":"") << in1 << endl;
		test.close();
		int ___e=system(("./cont < "+test_name+".in > "+test_name+".out").c_str());
		cout << q << ": generated!\n";
	}
return 0;
}