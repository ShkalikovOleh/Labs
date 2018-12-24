#include "Task.h"
#include <iostream>

void task1() {
	double a, b;
	std::cout << "Enter a ";
	std::cin >> a;
	std::cout << "Enter b ";
	std::cin >> b;
	//if (a != b)
	std::cout << "min " << ((a > b) ? b : a) << std::endl;
	/*else
		std::cout << "You must enter different number";*/
}