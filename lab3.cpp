// lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"

#define SIZE 5

void matrix_sort(int col, int row, int matrix[][SIZE])
{
	int temp = 0;
	for (int k = 0; k < col; k++)
	{
		for (int i = 1; i < row; i++)
		{
			for (int j = i; j > 0 && matrix[j - 1][k] < matrix[j][k]; j--)
			{
				temp = matrix[j - 1][k];
				matrix[j - 1][k] = matrix[j][k];
				matrix[j][k] = temp;
			}
		}
	}
}

double function_calc(int array[], int size, int col)
{
	int counter = 0;
	int mas = 1;

	for (int j = 0; j < size && j < col; j++)
	{
		counter++;
		mas = mas * array[j];
	}
	return pow(mas, 1 / (double)counter);
}

void enter_matrix(int **iMatrix)
{
	int i, j, element = 0;

	printf("Please enter matrix elements:\n");

	for (i = 0; i < SIZE*SIZE; i++)
	{
		scanf_s("%d", &element);
		*(iMatrix+i) = element;
		printf("\n");
	}
	printf("\n");
}

void main(void)
{
	const int row = SIZE, col = SIZE;
	int i, j, element;
	int matrix[SIZE][SIZE];
    double geomean = 0, Fij = 0;

	enter_matrix(matrix);
	
	//printf("Please enter matrix elements:\n");

	/*for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			/*matrix[i][j] = (int)rand() % 10;
			printf("%2d", matrix[i][j]);

			scanf_s("%d", &element);
			matrix[i][j] = element;
		}
		printf("\n");
	}
	printf("\n");*/

	printf("Entered matrix:\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}

	matrix_sort(col, row, matrix);

	printf("Sorted matrix:\n");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}


	for (i = 1; i < col; i++)
	{
		geomean = function_calc(matrix[i], row, i);
		Fij += geomean;
		printf("Geometric mean for row #%d under main diagonal = %f\n", i+1,  geomean);
	}
	printf("\nF(fi(aij)) = %f", Fij);

	_getch();
}


