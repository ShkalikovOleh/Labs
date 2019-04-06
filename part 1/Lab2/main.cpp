#include <iostream>
#include <vector>
#include "Task.h"

int main() {

	std::cout << "Task 1" << std::endl;
	task1();	
	std::cout << std::endl;

	std::cout << "Task2" << std::endl;
	task2();	
	std::cout << std::endl;

	//alt_task2();
	//std::cout << std::endl;

	std::vector<int> correct = { 5, 8, 4, 9, 3 };
	std::vector<int> incorrect = { 5, 8, 4, 2, 7 };	

	std::cout << "Task3 for correct" << std::endl;
	task3for(correct);
	std::cout << std::endl;

	std::cout << "Task3 for incorrect" << std::endl;
	task3for(incorrect);
	std::cout << std::endl;

	std::cout << "Task3 while correct" << std::endl;
	task3while(correct);
	std::cout << std::endl;

	std::cout << "Task3 while incorrect" << std::endl;
	task3while(incorrect);
	std::cout << std::endl;	

	long int correct_number = 600006;
	long int incorrect_number = 350801;

	std::cout << "Task Add correct" << std::endl;
	add_task(correct_number);
	std::cout << std::endl;

	std::cout << "Task Add incorrect" << std::endl;
	add_task(incorrect_number);

	return 0;
 }