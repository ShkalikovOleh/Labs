#include "Task.h"
#include <iostream>

using namespace std;

int main() {
	cout << "Base task" << endl << endl;	
	if (!sum_base_task("test.in"))
		cout << "Error in base task" << endl;
	else
		cout << "Base task complete" << endl;

	cout << endl << "Medium task"  << endl << endl;
	if (!dump8_medium_task("binary.txt"))
		cout << "Error in medium task" << endl;

	cout << endl << "Hard task" << endl << endl;
	const char* p = "E:/Repositories/Labs/x64/Debug/Lab7.exe";	
	
	auto map = bigramm_hard_task(p);
	for (auto it = map.begin(); it != map.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}
	return 0;
}