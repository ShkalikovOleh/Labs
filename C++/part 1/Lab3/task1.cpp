#include "Task.h"
#include <cmath>

bool task1_Check(double x, double y) {
	if (x > 0) {
		if ((y >= 0) && (x > y) || (y < 0))
			return true;
		else
			return false;
	}
	else
		return false;
}

double task1_Calculate(double x, double y) {
	double x3 = x*x*x;
	double tx = x + x;	
	return (std::sqrt(1 / (x3 - y*y*y)) - (std::sqrt(tx) / (x3 - (y / tx))));	
}