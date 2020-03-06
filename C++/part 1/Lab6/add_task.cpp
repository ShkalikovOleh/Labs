#include <string>
#include <iostream>

void printPart_add_task(std::string string) {
	int pos = string.find_first_of('*');
	if (pos < string.size()) {
		std::string res = string.substr(0, pos);
		std::cout << res << std::endl;
	}
	else {
		std::cout << "String have not *" << std::endl;
	}	
}