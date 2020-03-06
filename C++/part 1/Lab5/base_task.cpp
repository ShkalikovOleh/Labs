#include <fstream>

bool sum_base_task(const char* path) 
{
	std::ifstream input(path);	
	if (input) {
		int n = 255;
		char tc;
		int sum = 0;
		while (!input.eof()) {
			input.getline(&tc, n);
			const char* t = &tc;
			sum += atoi(t);
		}						
				
		std::ofstream output("test.out");
		if (output) {
			output << sum;
		}		
		else {
			input.close();
			return false;
		}
			
		return true;
	}
	else {
		input.close();
		return false;
	}		
}