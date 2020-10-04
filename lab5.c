#include <stdio.h>
#include <stdlib.h>

double** create2DArray(int, int);
int getRowSize(double**);
int getColSize(double**, int);
void printTable(double** );
void freeTable(double**);

int main() {

	double** array = create2DArray(4, 4);
	printTable(array);
	freeTable(array);

	return 1;
}
/* In this function, a 2D doubles array is created such that the number of rows is stored before
the array of row pointers as a floating point, and the number of columns is stored before
each row as a floating point.
Inputs:
int numRows - this is the desired number of rows
int numCols - this is the desired number of columns
Outputs:
double** array - this is the created 2D array. */

double** create2DArray(int numRows, int numCols) {
	double ** array;
	array = (double**)malloc(numRows*sizeof(double)+sizeof(float));

	if (array == NULL) {
		printf("Array size allocation failed.\n");
		return NULL;
	}

	*((float*)array) = numRows;
	 (float*)array++;

	for (size_t y=0; y<numRows; y++) {
		*(array+y) = (double*)malloc(numCols*sizeof(double)+sizeof(float));
		if( *(array+y) == NULL) {
			printf("Array size allocation failed.\n");
			return NULL;
		}
	}

	for (size_t i=0; i<numRows; i++) {
		*((float*)array) = numCols;
		(float*)array++;
	}
	for (size_t g=0; g<numRows; g++) {
		(float*)array--;
	}

	return (double**)array;
}

/*This function receives a 2D doubles array and returns the number of rows, assumed to be stored before the row pointers.
Inputs:
double** table - this is the 2D doubles array to be analyzed.
Ouputs:
int rowSize - this is the number of rows in the array. */

int getRowSize(double** table) {
	int rowSize = *((float*)table);
	return rowSize;
}

/*This function receives a 2D doubles array and returns the number of columns in the selected row, or returns -1 if that
row does not exist.
Inputs:
double** table - this is the 2D doubles array to be analyzed.
int rowNo - this is the selected row.
Outputs:
int colSize - this is the number of columns in the selected array. */

int getColSize(double **table, int rowNo) {

	int x = getRowSize((double**)table);
	if (rowNo >= x) {
		printf("Selected row is out of bounds.");
		return -1;
	}
	int colSize = *((float*)table+rowNo);
	return colSize;
}

/*This function receives a 2D double array and prints the values in row-wise order.
Inputs:
double** table - this is the given 2D doubles array.
Outputs:
there are not any returned outputs. */

void printTable(double** table) {

	int x = getRowSize((double**)table);
	int y = getColSize((double**)table, 2);

	printf("Number of rows in 2D Array: %d\n", x);

	for (int i=0; i<x; i++) {
		printf("Row %d Number of columns: %d\n", i, y);
		for (int j=0; j<y; j++) {
			printf("Array[%d,%d] = %f\n", i, j, *((double*)(table+i)+j));
		}
	}

}

/*This function receives a 2D double array and frees the memory allocated.
Inputs:
double** table - this is the 2D double array to be freed.
Outputs:
this function does not return any outputs. */

void freeTable(double** table) {

float rowSize = getRowSize(table);
*table = (double*)((float*)table);

for (size_t i=0; i<rowSize; i++) {
	free(table+i);
}

free(table);

}
