double sum_medium_task(double** matrix, unsigned int n) {
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - i - 1; j < n; j++) {
			sum += matrix[i][j];
		}
	}
	return sum;
}

double max_medium_task(double** matrix, unsigned int n) {
	double max = matrix[0][n-1];
	for (int i = 0; i < n; i++)
	{
		for (int j = n - i - 1; j < n; j++) {
			if (max < matrix[i][j])
				max = matrix[i][j];
		}
	}
	return max;
}