#include "Task.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {	
	cout << "Base task" << endl << endl;

	int m, n;
	cout << "Enter a row count ";
	cin >> m;
	cout << "Enter a column count ";
	cin >> n;
	double **matrix1 = new double*[m];
	for (int i = 0; i < m; i++)		
		matrix1[i] = new double[n];

	cout << "Enter matrix" << endl;
	for (int i = 0; i < m; i++) {
		cout << i + 1 << " row" << endl;
		for (int j = 0; j < n; j++) {
			cin >> matrix1[i][j];
		}		
	}

	cout << "Min:" << min_base_task(matrix1, m, n) << endl;
	cout << "Prod:" << prod_base_task(matrix1, m, n) << endl;
	for (int i = 0; i < m; i++)
		delete[] matrix1[i];	
	delete[] matrix1;


	cout << endl << "Medium task" << endl << endl;

	int k;
	cout << "Enter n from n*n matrix size ";
	cin >> k;	
	double **matrix2 = new double*[k];
	for (int i = 0; i < k; i++)
		matrix2[i] = new double[k];

	cout << "Enter matrix" << endl;
	for (int i = 0; i < k; i++) {
		cout << i + 1 << " row" << endl;
		for (int j = 0; j < k; j++) {
			cin >> matrix2[i][j];
		}
	}

	cout << "Max:" <<max_medium_task(matrix2, k) << endl;
	cout << "Sum:" << sum_medium_task(matrix2, k) << endl;
	for (int i = 0; i < k; i++)
		delete[] matrix2[i];
	delete[] matrix2;


	cout << endl << "Hard task" << endl;	

	int s = 20;

	srand(time(NULL));
	double **matrix3 = new double*[s];
	for (int i = 0; i < s; i++)
		matrix3[i] = new double[s];
	for (int i = 0; i < s; i++) {		
		for (int j = 0; j < s; j++) {			
			matrix3[i][j] = rand() % 255 + 1;
		}
	}	
	
	cout << "Sobel" + s << endl;
	for (int i = 0; i < s; i++) {
		cout << "Row " << i + 1 << endl;
		for (int j = 0; j < s; j++) {
			cout << matrix3[i][j] << endl;
		}
	}
	cout << "Result" << endl;
	auto sobel = grad_hard_task(matrix3, s, s);
	for (int i = 0; i < s; i++) {
		cout << "Row " << i + 1 << endl;
		for (int j = 0; j < s; j++) {
			cout << sobel[i][j] << endl;
		}
	}
		
	for (int i = 0; i < s; i++)
		delete[] matrix3[i];	
	delete[] matrix3;
	for (int i = 0; i < s; i++)
		delete[] sobel[i];
	delete[] sobel;	

	return 0;
}