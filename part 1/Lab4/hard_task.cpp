#include <cmath>
#include <iostream>

double** grad_horizontal(double** matrix, unsigned int m, unsigned int n);
double** grad_vertical(double** matrix, unsigned int m, unsigned int n);

double** grad_hard_task(double** matrix, unsigned int m, unsigned int n) {
	double** g_h = grad_horizontal(matrix, m, n);
	double** g_v = grad_vertical(matrix, m, n);

	double **s = new double*[m];
	for (int i = 0; i < m; i++)
		s[i] = new double[n];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			double h = g_h[i][j];
			double g = g_v[i][j];
			int temp = (int)std::sqrt(g*g + h * h); //int because color is discrete data
			if (temp > 255)
				s[i][j] = 255;
			else
				s[i][j] = temp;
		}
	}

	for (int i = 0; i < m; i++)
		delete[] g_h[i];
	delete[] g_h;
	for (int i = 0; i < m; i++)
		delete[] g_v[i];
	delete[] g_v;

	return s;
}

double** grad_horizontal(double** matrix, unsigned int m, unsigned int n) {
	double **g_h = new double*[m];
	for (int i = 0; i < m; i++)
		g_h[i] = new double[n];		

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			double sum = 0;
			if (i > 0 && j > 0 && i +1 > m && j + 1 < n) {
				sum += matrix[i - 1][j - 1];
				sum += 2 * matrix[i - 1][j];
				sum += matrix[i - 1][j + 1];
				sum -= matrix[i + 1][j - 1];
				sum -= 2 * matrix[i + 1][j];
				sum -= matrix[i + 1][j + 1];
			}
			else if (i > 0 && j > 0 && i + 1 < m) { //j+1 does not exist
				sum += matrix[i - 1][j - 1];
				sum += 2 * matrix[i - 1][j];
				sum -= matrix[i + 1][j - 1];
				sum -= 2 * matrix[i + 1][j];
			}
			else if (i > 0 && i + 1 < m && j + 1 < n) { //j-1 does not exist
				sum += 2 * matrix[i - 1][j];
				sum += matrix[i - 1][j + 1];
				sum -= 2 * matrix[i + 1][j];
				sum -= matrix[i + 1][j + 1];
			}
			else if (i > 0 && j > 0 && j + 1 < n) { //i+1 does not exist
				sum += matrix[i - 1][j - 1];
				sum += 2 * matrix[i - 1][j];
				sum += matrix[i - 1][j + 1];
			}
			else if (j > 0 && i + 1 < m && j + 1 < n) { //i-1 does not exist
				sum -= matrix[i + 1][j - 1];
				sum -= 2 * matrix[i + 1][j];
				sum -= matrix[i + 1][j + 1];
			}
			else if (i + 1 < m && j + 1 < n) { //i-1 and j-1 does not exist
				sum -= 2 * matrix[i + 1][j];
				sum -= matrix[i + 1][j + 1];
			}
			else if (j > 0 && i + 1 < m) { //i-1 and j+1 does not exist
				sum -= matrix[i + 1][j - 1];
				sum -= 2 * matrix[i + 1][j];
			}
			else if (i > 0 && j + 1 > m) { //i+1 and j-1 does not exist
				sum += 2 * matrix[i - 1][j];
				sum += matrix[i - 1][j + 1];
			}
			else if (i > 0 && j > 0) { //i+1 and j+1 does not exist
				sum += matrix[i - 1][j - 1];
				sum += 2 * matrix[i - 1][j];
			}
			else if (i + 1 < m) { ////i-1 , j-1, j+1 does not exist
				sum -= 2 * matrix[i + 1][j];
			}					
			else if (i > 0) { //i+1, j-1, j+1 does not exist
				sum += 2 * matrix[i - 1][j];				
			}
			//Another cases has 0 in prod			
			g_h[i][j] = sum;
		}
	}
	return g_h;
}

double** grad_vertical(double** matrix, unsigned int m, unsigned int n) {
	double **g_v = new double*[m];
	for (int i = 0; i < m; i++)
		g_v[i] = new double[n];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			double sum = 0;
			if (i > 0 && j > 0 && i + 1 < m && j + 1 < n) {
				sum += matrix[i - 1][j - 1];
				sum += 2 * matrix[i][j - 1];				
				sum += matrix[i + 1][j - 1];
				sum -= matrix[i - 1][j + 1];
				sum -= 2 * matrix[i][j + 1];
				sum -= matrix[i + 1][j + 1];
			}
			else if (i > 0 && j > 0 && i + 1 < m) { //j+1 does not exist
				sum += matrix[i - 1][j - 1];
				sum += 2 * matrix[i][j - 1];
				sum += matrix[i + 1][j - 1];
			}
			else if (i > 0 && i + 1 < m && j + 1 < n) { //j-1 does not exist
				sum -= matrix[i - 1][j + 1];
				sum -= 2 * matrix[i][j + 1];
				sum -= matrix[i + 1][j + 1];
			}
			else if (i > 0 && j > 0 && j + 1 < n) { //i+1 does not exist
				sum += matrix[i - 1][j - 1];
				sum += 2 * matrix[i][j - 1];
				sum -= matrix[i - 1][j + 1];
				sum -= 2 * matrix[i][j + 1];
			}
			else if (j > 0 && i + 1 < m && j + 1 < n) { //i-1 does not exist
				sum += 2 * matrix[i][j - 1];
				sum += matrix[i + 1][j - 1];
				sum -= 2 * matrix[i][j + 1];
				sum -= matrix[i + 1][j + 1];
			}
			else if (i + 1 < m && j + 1 < n) { //i-1 and j-1 does not exist
				sum -= 2 * matrix[i][j + 1];
				sum -= matrix[i + 1][j + 1];
			}
			else if (j > 0 && i + 1 < m) { //i-1 and j+1 does not exist
				sum += 2 * matrix[i][j - 1];
				sum += matrix[i + 1][j - 1];
			}
			else if (i > 0 && j + 1 < n) { //i+1 and j-1 does not exist
				sum -= matrix[i - 1][j + 1];
				sum -= 2 * matrix[i][j + 1];
			}
			else if (i > 0 && j > 0) { //i+1 and j+1 does not exist
				sum += matrix[i - 1][j - 1];
				sum += 2 * matrix[i][j - 1];
			}
			else if (j + 1 < n) { //i+1, i-1, j-1 does not exist
				sum -= 2 * matrix[i][j + 1];
			}
			else if (j > 0) { //i+1, i-1, j+1 does not exist
				sum += 2 * matrix[i][j - 1];
			}
			//Another cases has in prod 0			
			g_v[i][j] = 255;			
		}
	}
	return g_v;
}