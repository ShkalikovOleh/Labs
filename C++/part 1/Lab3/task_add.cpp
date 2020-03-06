#include "Task.h"
#include <stack>
#include <iostream>

std::stack<int> p1, p2, p3;

extern void move(int n, std::stack<int>&from, std::stack<int> &to, std::stack<int> &indep);

void print() {
	auto tp1 = p1;
	auto tp2 = p2;
	auto tp3 = p3;
	std::cout << "Piramid 1" << std::endl;
	while(!tp1.empty()){
		std::cout << tp1.top() << std::endl;
		tp1.pop();
	}
	std::cout << std::endl;
	std::cout << "Piramid 2" << std::endl;
	while(!tp1.empty()){
		std::cout << tp2.top() << std::endl;
		tp2.pop();
	}
	std::cout << std::endl;
	std::cout << "Piramid 3" << std::endl;
	while(!tp3.empty()){
		std::cout << tp3.top() << std::endl;
		tp3.pop();
	}
}

void add_task(int n) {	
	for (int i = n; i > 0; i--) {
		p1.push(i);
	}
	std::cout << std::endl << "Start" << std::endl;
	print();
	move(n, p1, p3, p2);
	std::cout << std::endl << "End" << std::endl;
	print();
}

void move(int n, std::stack<int> &from, std::stack<int> &to, std::stack<int> &indep) {	
	if (n >= 1) {		
		move(n - 1, from, indep, to);
		if (to.empty() || (!to.empty() && to.top() > from.top())) {
			to.push(from.top());
			from.pop();
		}			
		move(n - 1, indep, to, from);		
	}	
}
