#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;
double func(double a, double x);

int main(int argc, char* argv[]) {	
	assert(argc == 3);

	double a, x;
	try {		
		x = atof(argv[1]);
		a = atof(argv[2]);
		cout << "Result: " << func(a, x) << endl;
	}
	catch (...) {
		cout << "Incorrect argument" << endl;
	}
	system("pause");
	return 0;
}

//18 task from lab1
double func(double a, double x) {
	double p1, p2, p2_1, p2_2;
	const char* e1 = "Incorrect part 1";
	const char* e2 = "Incorrect part 2";
	const char* e2_1 = "a-x < 0 and (2x-a)^3 > 0";
	const char* e2_2 = "a-x > 0 and (2x-a)^3 < 0";
	const char* e2_3 = "(2x - a) ^ 3 = 0";
	try {
		try {
			if ((a - 2) == 0)
				throw e1;
			p1 = (x*x*x + x + 3) / (a - 2);
		}
		catch(...)
		{
			throw e1;
		}
		try {
			p2_1 = pow((a - x), 5);
			p2_2 = pow((2 * x - a), 3);
			if (p2_1 < 0 && p2_2 > 0)
				throw e2_1;
			if (p2_1 > 0 && p2_2 < 0)
				throw e2_2;
			if (p2_2 == 0)
				throw e2_3;
			p2 = sqrt(p2_1 / p2_2);
		}
		catch (const char* er)
		{
			cout << er << endl;
			throw e2;
		}
	}
	catch (const char* er) {
		cout << er << endl;
		throw;
	}
	return p1 + p2;
}