#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

typedef struct {
			int rowSize, colSize;
	    double row[ROW], col[COL];
		} arrayADT;

arrayADT** createGeneral2DArray (int rows, int cols);
int getColSize(arrayADT*);
int getRowSize(arrayADT*);

int main() {

	arrayADT* array = (arrayADT*)createGeneral2DArray(ROW, COL);

	printf("\nNumber of rows: %d\n", ROW);

	for (int i=0; i<ROW; i++) {
			printf("\nIn row %d: \n", i);
			printf("Number of Columns: %d\n", COL);
			for(int j=0; j<COL; j++) {
					printf("Array[%d][%d] = %d\n", i, j, *(((int *)array+i)+j));
			}
	}


	return 1;
}

arrayADT** createGeneral2DArray (int rows, int cols) {

	arrayADT** array;
	array = (arrayADT**)malloc(sizeof(int)+rows*sizeof(arrayADT));

	if (array == NULL) {
		printf("Error in allocating space for array");
		return NULL;
	}
	*((int*)array) = rows;
	(int*)array++;

	for(size_t i=0; i<rows; i++) {
		*(array+i) = (arrayADT*)malloc(cols*sizeof(arrayADT)+sizeof(int));
		if(*(array+i)==NULL) {
			printf("Error in allocating space for array");
			return NULL;
		}
	}

	for (size_t t=0; t<rows; t++) {
		*((int*)array) = cols;
		(int*)array++;
	}

	for (int l=0; l<ROW; l++) {
			printf("\nIn row %d: \n", l);
			printf("Number of Columns: %d\n", COL);
			for(int j=0; j<COL; j++) {
					printf("Array[%d][%d] = %d\n", l, j, *(((int *)array+l)+j));
			}

	return (arrayADT**)array;
}
/*
int getColSize(arrayADT*) {

}
int getRowSize(arrayADT*);
*/
