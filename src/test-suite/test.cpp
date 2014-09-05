#include "test.h"
#include "main.h"
#include "usefull.h"
#include "gen.h"
#include "../base_unlint.h"

#include <cstdio>
#include <cstdlib>

using std::string;

bool test(const string& in, const string& out) {
	FilePutContents(tmp_dir.sname() + "/test.in", in);
	system(("Calc -w < " << tmp_dir.sname() << "/test.in > " << tmp_dir.sname() << "/test.out").c_str());
	return (out + "\n") == FileGetContents(tmp_dir.sname() << "/test.out");
}

int run(const string& in, const string& out) {
	if (!test(in, out)) {
		static int test = 0;
		if (test == 0)
			system("mkdir -p wrongs");
		string k;
		system(("mv " << tmp_dir.sname() << "/test.in wrongs/" << (k = ToString(++test)) << ".in; mv " << tmp_dir.sname() << "/test.out wrongs/" << k << ".out").c_str());
		return 1;
	}
	return 0;
}

bool incrementation_test(int max_num_length) {
	string a = generator::genNum(max_num_length);
	unlint::base_unlint x(a);
	++x;
	if (0 != run(a + "+1", x.str()))
		return false;
	x = a;
	x++;
	if (0 != run(a + "+1", x.str()))
		return false;
	return true;
}

bool decrementation_test(int max_num_length) {
	string a = generator::genNum(max_num_length);
	unlint::base_unlint x(a);
	--x;
	if (0 != run(a + "-1", x.str()))
		return false;
	x = a;
	x--;
	if (0 != run(a + "-1", x.str()))
		return false;
	return true;
}

bool addition_test(int max_num_length) {
	string a = generator::genNum(max_num_length), b = generator::genNum(max_num_length);
	unlint::base_unlint x = unlint::base_unlint(a) + unlint::base_unlint(b);
	if (0 != run(a << "+" << b, x.str()))
		return false;
	return true;
}

bool subtraction_test(int max_num_length) {
	string a = generator::genNum(max_num_length), b = generator::genNum(max_num_length);
	if (a.size() < b.size() || (a.size() == b.size() && a < b))
		swap(a, b);
	unlint::base_unlint x = unlint::base_unlint(a) - unlint::base_unlint(b);
	if (0 != run(a << "-" << b, x.str()))
		return false;
	return true;
}
