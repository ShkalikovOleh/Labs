#include "Task.h"

void add_task(long int number) {
	int sum1 = 0;
	for (int i = 5; i >= 3; i--) {
		int p = std::pow(10, i);
		int d = number / p;
		sum1 += d;
		number -= d * p;
	}
	int sum2 = 0;
	for (int i = 2; i >= 0; i--) {
		int p = std::pow(10, i);
		int d = number / p;
		sum2 += d;
		number -= d * p;
	}
	(sum1 == sum2) ? std::cout << "Good ticket" << std::endl : std::cout << "Bad ticket" << std::endl;
}