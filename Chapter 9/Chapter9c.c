/*The files "mata.txt" and "matb.txt" contain integer matrices of size 10 x 10.
Write a program that calculates the sum of the matrices in a new matrix.
The resulting sum matrix shall be saved to the file "sum.usr".

The matrix elements are separated by spaces and newlines. For example:

1 2 3 4 5 6 7 8 9 10
11 12 13 14 15 16 17 18 19 20
... ... ...
... ... ...
91 92 93 94 95 96 97 98 99 100

The sum matrix must be saved in the same format. At the end, the program
prints a message indicating successful completion.

Example output:
The sum of the matrices has been calculated into the file sum.usr.*/

#include <stdio.h>

int main()
{
	int sumArray[10] [10];
	int tempArray[10] [10];
	FILE* mata;
	FILE* matb;
	FILE* sum;

	if ( (mata = fopen("mata.txt", "r")) != NULL && (matb = fopen("matb.txt", "r")) != NULL && (sum = fopen("sum.usr", "w"))  != NULL )
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j< 10; j++)
			{
				fscanf(mata, "%d ", &sumArray[i] [j]);
				fscanf(matb, "%d ", &tempArray[i] [j]);
				sumArray [i] [j] += tempArray [i] [j];
				if (j != 9)
				{
					fprintf(sum, "%d ", sumArray[i] [j]);
				}
				else
				{
					fprintf(sum, "%d\n", sumArray[i] [j]);
				}
			}
		}
		fclose(mata);
		fclose(matb);
		fclose(sum);
	}
	else
	{
		fclose(mata);
		fclose(matb);
		return 1;
	}
	printf("The sum of the matrices has been calculated into the file sum.usr.\n");
	return 0;
}
