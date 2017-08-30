/*
      date:  Febuary 15, 2014
      name:  John Green
  homework:  04
     class:  CSE 1320-004
*/

#include <stdio.h>

void find_values(int[][5], int, int*, int*);
void mean_var(int[][5], int, int, double*, double*);

int main(void)
{
	int matrix_1[][5] = {{55, 8, 12, 6, -1},{-10, 4, 7, 5, -6},
		{-20, 0, 15, 4, -2}};
	int matrix_2[][5] = {{1, 6, -2, 5, 14},{0, 4, 3, -5, 12},
		{2, 4, 5, -6, 12},{4, 7, 15, 4, 16},{3, 9, 4, 0, 17}};
	int maxSum = 0, colIndex = 0;
	double mean = 0.0, var = 0.0;
	
	find_values(matrix_1, sizeof(matrix_1)/sizeof(matrix_1[0]), 
		&colIndex, &maxSum);
		
	mean_var(matrix_1, sizeof(matrix_1)/sizeof(matrix_1[0]),
		colIndex, &mean, &var);
		
	printf("For the first array, the column with index %d has the maximum sum of %d\n", colIndex, maxSum);
	printf("It has a mean of %.3f and a variance of %.3f\n\n", mean, var);
	
	find_values(matrix_2, sizeof(matrix_2)/sizeof(matrix_2[0]), 
		&colIndex, &maxSum);	
	
	mean_var(matrix_2, sizeof(matrix_2)/sizeof(matrix_2[0]),
		colIndex, &mean, &var);
		
	printf("For the second array, the column with index %d has the maximum sum of %d\n", colIndex, maxSum);
	printf("It has a mean of %.3f and a variance of %.3f\n", mean, var);
	
	return 0;
}

void find_values(int matrix[][5], int rows, int* colIndex, int* maxSum)
{
	int x,y,sum;
	
	for(x = 0; x < 5; x++)
	{
		sum = 0;
		for(y = 0; y < rows; y++)
		{
			sum += matrix[y][x];
		}
		if(!x)
		{
			*maxSum = sum;
			*colIndex = x;
			continue;
		}
		if(sum > *maxSum)
		{
			*maxSum = sum;
			*colIndex = x;
		}	
	}
}

void mean_var(int matrix[][5], int rows, int colIndex, double* mean, double* var)
{
	double sum = 0.0, varsum = 0.0;
	int x;
	
	for(x = 0; x < rows; x++)
	{
		sum += matrix[x][colIndex];
	}
	
	*mean = sum/rows;
	
	for(x = 0; x < rows; x++)
	{
		varsum += (matrix[x][colIndex] - *mean)*(matrix[x][colIndex] - *mean);
	}
	
	*var = (varsum/(rows-1));	
}
