double min_base_task(double** matrix, unsigned int m, unsigned int n) {
	double min = **matrix;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {			
			if (min > *(*(matrix + i) + j))
				min = *(*(matrix + i) + j);
		}
	}
	return min;
}

double prod_base_task(double** matrix, unsigned int m, unsigned int n) {
	double prod = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
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