#include "gen.h"
#include "main.h"
#include "test.h"
#include "usefull.h"

#include <csignal>
#include <cstdio>
#include <cstring>
#include <iostream>

#define eprintf(args...) fprintf(stderr,args)

TemporaryDirectory tmp_dir("test.XXXXXX");

enum TestTypes {
	NONE = 0,
	INCREMENTATION = 1 << 0,
	DECREMENTION = 1 << 1,
	ADDITION = 1 << 2,
	SUBTRACTION = 1 << 3,
	MULTIPLICATION = 1 << 4,
	DIVISION = 1 << 5,
	MODULO = 1 << 6,
	ASSIGN_ADDITION = 1 << 7,
	ASSIGN_SUBTRACTION = 1 << 8,
	ASSIGN_MULTIPLICATION = 1 << 9,
	ASSIGN_DIVISION = 1 << 10,
	ASSIGN_MODULO = 1 << 11,
	GCD = 1 << 12, // Greatest common divisor
	POWER = 1 << 13,
	FACTORIAL = 1 << 14,
	ALL = (1 << 15) - 1
};

int main(int argc, char **argv) {
	if (argc < 4) {
		eprintf("Usage: test <options> <number of tests> <max numbers length>\n\nOptions:\n    all - test all\n    ++ - test ++ operator\n    -- - test -- operator\n    + - test + operator\n    - - test - operator\n    * - test * operator\n    / - test / operator\n    %% - test %% operator\n    += - test += operator\n    -= - test -= operator\n    *= - test *= operator\n    /= - test /= operator\n    %%= - test %%= operator\n    gcd - test gcd (Greatest common divisor)\n    pow - test pow\n    factorial - test factorial\n");
		return 1;
	}
	int number_of_tests, max_num_length;
	if (1 != sscanf(argv[--argc], "%i", &max_num_length)) {
		eprintf("Failed to get the max numbers length\n");
		return 1;
	}  else if (max_num_length < 1) {
		eprintf("Max numbers length cannot be less than 1\n");
		return 1;
	}
	if (1 != sscanf(argv[--argc], "%i", &number_of_tests)) {
		eprintf("Failed to get the number of tests\n");
		return 1;
	} else if (number_of_tests < 0) {
		eprintf("Number of tests cannot be negative\n");
		return 1;
	}
	TestTypes tests = NONE;
	for (int i = 1; i < argc; ++i) {
		if(0 == strcmp(argv[i], "all"))
			tests = static_cast<TestTypes>(tests | ALL);
		else if (0 == strcmp(argv[i], "++"))
			tests = static_cast<TestTypes>(tests | INCREMENTATION);
		else if (0 == strcmp(argv[i], "--"))
			tests = static_cast<TestTypes>(tests | DECREMENTION);
		else if (0 == strcmp(argv[i], "+"))
			tests = static_cast<TestTypes>(tests | ADDITION);
		else if (0 == strcmp(argv[i], "-"))
			tests = static_cast<TestTypes>(tests | SUBTRACTION);
		else if (0 == strcmp(argv[i], "*"))
			tests = static_cast<TestTypes>(tests | MULTIPLICATION);
		else if (0 == strcmp(argv[i], "/"))
			tests = static_cast<TestTypes>(tests | DIVISION);
		else if (0 == strcmp(argv[i], "%"))
			tests = static_cast<TestTypes>(tests | MODULO);
		else if (0 == strcmp(argv[i], "+="))
			tests = static_cast<TestTypes>(tests | ASSIGN_ADDITION);
		else if (0 == strcmp(argv[i], "-="))
			tests = static_cast<TestTypes>(tests | ASSIGN_SUBTRACTION);
		else if (0 == strcmp(argv[i], "*="))
			tests = static_cast<TestTypes>(tests | ASSIGN_MULTIPLICATION);
		else if (0 == strcmp(argv[i], "/="))
			tests = static_cast<TestTypes>(tests | ASSIGN_DIVISION);
		else if (0 == strcmp(argv[i], "%="))
			tests = static_cast<TestTypes>(tests | ASSIGN_MODULO);
		else if (0 == strcmp(argv[i], "gcd"))
			tests = static_cast<TestTypes>(tests | GCD);
		else if (0 == strcmp(argv[i], "pow"))
			tests = static_cast<TestTypes>(tests | POWER);
		else if (0 == strcmp(argv[i], "factorial"))
			tests = static_cast<TestTypes>(tests | FACTORIAL);
		else {
			eprintf("Unsupported option: '%s'\n", argv[i]);
		}
	}
	// signal control
	signal(SIGHUP, exit);
	signal(SIGINT, exit);
	signal(SIGQUIT, exit);
	signal(SIGILL, exit);
	signal(SIGTRAP, exit);
	signal(SIGABRT, exit);
	signal(SIGIOT, exit);
	signal(SIGBUS, exit);
	signal(SIGFPE, exit);
	signal(SIGKILL, exit); // We won't block SIGKILL
	signal(SIGUSR1, exit);
	signal(SIGSEGV, exit);
	signal(SIGUSR2, exit);
	signal(SIGPIPE, exit);
	signal(SIGALRM, exit);
	signal(SIGTERM, exit);
	signal(SIGSTKFLT, exit);
	signal(_NSIG, exit);
	if (tests & INCREMENTATION) {
		printf("Testing ++\n");
		for (int i = 1; i <= number_of_tests; ++i)
			printf("Test %i: %s\n", i, incrementation_test(max_num_length) ? "\033[1;32mOK\033[0m" : "\033[1;31mWrong\033[0m");
	}
	if (tests & DECREMENTION) {
		printf("Testing --\n");
		for (int i = 1; i <= number_of_tests; ++i)
			printf("Test %i: %s\n", i, decrementation_test(max_num_length) ? "\033[1;32mOK\033[0m" : "\033[1;31mWrong\033[0m");
	}
	if (tests & ADDITION) {
		printf("Testing +\n");
		for (int i = 1; i <= number_of_tests; ++i)
			printf("Test %i: %s\n", i, addition_test(max_num_length) ? "\033[1;32mOK\033[0m" : "\033[1;31mWrong\033[0m");
	}
	if (tests & SUBTRACTION) {
		printf("Testing -\n");
		for (int i = 1; i <= number_of_tests; ++i)
			printf("Test %i: %s\n", i, subtraction_test(max_num_length) ? "\033[1;32mOK\033[0m" : "\033[1;31mWrong\033[0m");
	}
	return 0;
}
