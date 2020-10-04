#include <stdio.h>
#include <stdlib.h>

void* createArray(int, int);
int getArraySize(void*);
void storeMaximum(int*);
float getMaximum(int*);
void freeArray(void*);


int main(void) {

	int arraySize = 10; //size of the array

	int* testArray = (int*)createArray(arraySize, sizeof(int));
	if (testArray == NULL) {
		printf("Array creation failed.\n");
		return -1;
	}

	else {
		for (size_t i=0; i<arraySize; i++) {
			testArray[i] = (int)i;
		}

		storeMaximum(testArray);

		printf("Elements in array are:");
		for(size_t j=0; j<(arraySize-1); j++) {
			printf(" %d,", testArray[j]);
		}
		printf(" %d\n", testArray[arraySize-1]);

		printf("Array size is %d, and the maximum of all elements is %.2f.\n", getArraySize(testArray), getMaximum(testArray));

		freeArray((void*)testArray);
	}
	return 0;
}

/* This function will create an array with space for the user-provided values, as well as two
hidden values stored at the beginning of the memory: first will be the size of the array, the
second will be the maximum of all Elements in the array.
inputs:
int n: this is the number of elements in the array.
int elemSize: this is the size of the data type the user wishes to input.
outputs:
Array: this is the array that the function will return (with the specifications described above.) */

void* createArray(int n, int elemSize) {
	int* Array = (int*)malloc(n*(sizeof(elemSize)) + sizeof(int) + sizeof(float));
	if (Array == NULL) {
		printf("Error in allocation of array size");
		return NULL;
	}
	*(Array) = n; //storing the size of the array
	Array ++; //incrementing to the next element, which will be the maximum of all elements
	*((float*)Array) = 0; //setting maximum to zero for now
	Array = (int*)((float*)Array + 1); //incrementing to the first user input
	return (void*)Array;
}

/*This function receives the user-created array (of any type), and returns the size of the array. This
value is stored in the first element of the array.
inputs:
void *array: this is the user-created array of any type.
outputs:
size: this is the size of the array. */

int getArraySize(void *array) {
	return *((int*)((float*)array - 1)-1);
}

/* This function will receive an integer array, find the maximum of all the elements, then store this value
as a floating-point number in the second memory location in the array.
input:
int *array: this is the user-provided integer array.
output:
int *array: this is the user-provided integer array with the maximum stored. */

void storeMaximum(int* array) {

	float max= *(array);
	int x = getArraySize(array); //getting the size of the array

	for (size_t i=1; i<=x; i++) {
		if (*(array+i) > max) {
			max = *(array+i);
		}
	}
	*((float*)array-1) = (float)max; //storing the max value
	array = array + 1;
}

/*This function receives the user-created array (of any type), and returns the max value in the array. This
value is stored in the second element of the array.
inputs:
void *array: this is the user-created array of any type.
outputs:
max: this is the max value in the array. */

float getMaximum(int *array) {
	return *((float*)array-1);
}

/*This function receives an array of any type, then frees all of the memories that have been allocated.
inputs:
void* array: this is the user-created array.
outputs:
there are no created outputs. */

void freeArray(void *array) {
	array = (void*)((int*)((float*)array-1)-1);
	free(array);
	array = NULL;
}
