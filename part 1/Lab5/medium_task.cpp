#include <cstdio>
#include <iostream>
#include <stack>

void to8(unsigned int data);

bool dump8_medium_task(const char* path) {
	FILE* file = std::fopen(path, "rb");
	if (!file)
		return false;		
	bool is_end = false;
	char data;
	std::cout << "Result:" << std::endl;
	data = fgetc(file);
	while (data != EOF)  {
		to8(data);		
		data = fgetc(file);
	}
	fclose(file);
	return true;
}

void to8(unsigned int data) {
	std::stack<int> q = std::stack<int>();
	while (data >= 8) {
		int temp = data % 8;
		q.push(temp);
		data = data / 8;
	}
	q.push(data);	
	while (!q.empty())
	{
		std::cout << q.top();
		q.pop();
	}
}

