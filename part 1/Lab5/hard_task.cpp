#include <unordered_map>
#include "Task.h"
#include <fstream>
#include <stack>

std::stack<int> GetBinary(int);

std::unordered_map<std::string, int> bigramm_hard_task(const char* path) {
	std::unordered_map<std::string, int> bigramm_map;
	std::ifstream file(path, std::ios::binary);
	if (file) {
		unsigned char data;								
		while (!file.eof()) {			
			file >> data;
			auto bits = GetBinary(data);
			int f = bits.top();
			int s = 0;
			bits.pop();
			while(!bits.empty()){
				s = bits.top();
				bits.pop();
				if (f == 0 && s == 0) {
					bigramm_map["00"]++;
				}
				else if (f == 0 && s == 1) {
					bigramm_map["01"]++;
				}
				else if (f == 1 && s == 0) {
					bigramm_map["10"]++;
				}														
				else if (f == 1 && s == 1) {
					bigramm_map["11"]++;
				}					
				f = s;
			}			
		}		
	}
	file.close();
	return bigramm_map;
}

std::stack<int> GetBinary(int data){
	std::stack<int> q = std::stack<int>();
	while (data >= 2) {
		int temp = data % 2;
		q.push(temp);
		data = data / 2;
	}
	q.push(data);
	while (q.size() < 8) {
		q.push(0);
	}
	return q;
}