#include "Task.h"

void task3for(std::vector<int> data) {
	double prod = 0;
	for (int i = 0; i < data.size(); i++) {		
		if (data[i] % 3 == 0) {
			if (prod != 0)
				prod *= data[i];
			else
				prod = data[i];
		}
	}
	if (prod != 0)
		std::cout << prod << std::endl;
	else
		std::cout << "Data have not number like 3n" << std::endl;
}

void task3while(std::vector<int> data) {
	double prod = 0;
	int i = 0;
	while (i < data.size()) {		
		if (data[i] % 3 == 0) {
			if (prod != 0)
				prod *= data[i];
			else
				prod = data[i];
		}
		i++;
	}
	if (prod != 0)
		std::cout << prod << std::endl;
	else
		std::cout << "Data have not number like 3n" << std::endl;
}

//void task3for(std::vector<double> data) {
//	for (int i = 0; i < data.size() - 1; i++) {
//		for (int j = i + 1; j < data.size(); j++) {
//			double prod = data[i] * data[j];
//			if (prod / 3 - (int)(prod / 3) == 0) {
//				std::cout << prod << std::endl;
//				return;
//			}				
//		}
//	}
//	std::cout << "Data have not number like 3n" << std::endl;
//}