#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

extern void add_task1(int b, int data);

extern void add_task2(int b, std::vector<int> data);


int main() {	
	double x;
	double y;
	double r;	

	std::cout << "Main task" << std::endl;
	std::cout << "Enter r: ";
	std::cin >> r;	
	std::cout << "Enter x: ";
	std::cin >> x;
	std::cout << "Enter y: ";
	std::cin >> y;

	

	if (std::sqrt(x*x + y*y) == std::sqrt(2)*r / 2)
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "False";
	}	
	std::cout << std::endl;

	
	//add_task 1
	std::cout << std::endl;
	std::cout << "Add task 1" << std::endl;
	add_task1(2, 31);
	add_task1(8, 31);
	add_task1(16, 31);
	add_task1(16,1000);
	std::cout << std::endl;

	//add_task 2
	std::cout << std::endl;
	std::cout << "Add task 2" << std::endl;
	std::vector<int> ar1 = { 1,1,0,0,1 };
	std::vector<int> ar2 = { 0,1,0,0,0 };
	add_task2(2, ar1);
	add_task2(2, ar2);
	std::cout << std::endl;

	return 0;
}

//print hex
void add_task1(int b, int data) {
	std::stack<int> q = std::stack<int>();
	
	while (data > b) {
		int temp = data % b;
		q.push(temp);
		data = data / b;
	}
	std::cout << data;
	
	while (!q.empty())
	{
		auto temp = q.top();
		if ((temp > 9) && (temp < 16)) {
			switch (temp)
			{			
			case 10:
				std::cout << "A";
				break;
			case 11:
				std::cout << "B";
				break;
			case 12:
				std::cout << "C";
				break;
			case 13:
				std::cout << "D";
				break;
			case 14:
				std::cout << "E";
				break;
			case 15:
				std::cout << "F";
				break;
			default:
				break;
			}
		}
		else
		{
			std::cout << temp;
		}
		q.pop();
	}
	std::cout << std::endl;
}

//print number in b system
void add_task2(int b, std::vector<int> data)
{
	int sum = 0;
	for (int i = 0; i < data.size(); i++) {
		sum += data[i] * pow(b, data.size() - i - 1);
	}	
	std::cout << sum << std::endl;
}