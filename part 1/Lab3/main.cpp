#include <iostream>
#include "Task.h"

using namespace std;

int main() {

	double x, y;

	cout << "Enter x ";
	cin >> x;

	cout << "Enter y ";
	cin >> y;

	if (task1_Check(x, y))
		cout << "Result is " << task1_Calculate(x, y) << endl;
	else
		cout << "Variable is incorrect" << endl;

	add_task(4);

	return 0;
}