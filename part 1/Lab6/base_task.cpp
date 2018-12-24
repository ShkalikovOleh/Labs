#include <string>
#include <vector>
#include <array>

bool base_task(std::string string1, std::string string2) {
	return (string1 == string2) && (string1.size() == string2.size());
}

double lab4min_base_task(std::vector<std::vector<double>> matrix)
{
	double min = matrix[0][0];
	for (auto it = matrix.cbegin(); it != matrix.cend(); it++) {
		for (auto jt = (*it).cbegin(); jt != (*it).cend(); jt++) {
			if (min > *jt)				
				min = *jt;
		}
	}
	return min;
};

double lab4prod_base_task(std::vector<std::vector<double>> matrix)
{
	double prod = 0;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			double t = matrix[i][j];
			if (t > 0) {
				if (prod != 0)
					prod *= t;
				else
					prod = t;
			}
		}
	}
	return prod;
}

template<int m, int n>
double alt_lab4min_base_task(std::array<std::array<double, n>, m> matrix) {
	double min = matrix[0][0];
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (min > matrix[i][j])
				min = matrix[i][j];
		}
	}
	return min;
}

template<int m, int n>
double alt_lab4prod_base_task(std::array<std::array<double, n>, m> matrix) {
	double prod = 0;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			double t = matrix[i][j];
			if (t > 0) {
				if (prod != 0)
					prod *= t;
				else
					prod = t;
			}
		}
	}
	return prod;
}