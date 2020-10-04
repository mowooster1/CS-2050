#include <stdio.h>
#include <stdlib.h>

int* createArray(int n);
int getSumOfMaximumAndMinimum(int* array);
void storeSumOfSquares(int * array, int size);
int getSumOfSquares (int * array);
void freeArray(int* array);

/* This function will call several functions to create an integer array, calculate the sum of the squares of the numbers, the sum of the max and min value, and store both of
the calculations in the first two memory locations. */
int main(void)
{
	int arraySize = 10;

	int* intarray = NULL;

	//checking to make sure the array was allocated correctly
 	intarray = createArray(arraySize);
	if (intarray==NULL) {
		printf("There was an error in array creation.\n");
	}
	else {
		printf("Elements in array are: ");
		for (size_t i = 2; i < (arraySize+1); i++) {
			printf("%d, ", intarray[i]);
			}
		printf("%d\n", intarray[arraySize+1]);
	}

	storeSumOfSquares(intarray, arraySize);

	printf("Sum of maximum and minimum value is %d, and the sum of squares value of all elements is %d\n", getSumOfMaximumAndMinimum(intarray), getSumOfSquares(intarray));

	freeArray(intarray);

	return 0;
}

/* This function creates an array and populates it, storing the sum of the maxixmum and minimum values in the second memory location, and the sum of the squares of the
values in the first memory location. The size of the array is allocated according the integer the function receives, in addition to the space for the two values stored
at the beginning.
input:
int n: this value represents the size of the desired array
output:
int* a: this pointer is used to store an array of ints that is returned to the user. */
int* createArray(int n) {

	//allocates memory and checks for an error
	int* a = malloc((n+2)*sizeof(int));
	if (a == NULL) {
		printf("There was an error in malloc creation.");
		return NULL;
	}
	//populates the array
	else {
		a[0] = 0;
		a[1] = 0;
		for (int i=2; i<=(n+1); i++) {
			a[i] = (i-1);
		}
	}
	return a;
}

/* This function will receive an integer array and return the sum of the max and min values in the array.
input:
int* array: this is the user-provided array that will be analyzed.
output:
sum: this variable stores the sum of the max and min values in the array.
array[1]: the function stores the sum in the second memory location in the array and returns it. */
int getSumOfMaximumAndMinimum(int * array) {

	int min=array[2], max=array[2];
	for (size_t i=2; i<=11; i++) {
		if (array[i] < min) {
			min = array[i];
		}
		if (array[i] > max) {
			max = array[i];
		}
		else {
			continue;
		}
	}
	int sum = max + min;
	array[1] = sum;
	return array[1];
}
/* This function will receive an integer array and its size, then store the sum of the squares of all the elements in the first memory location in the array.
inputs:
int* array: this is the user-provided array that will be analyzed.
int size: this is the size of the array.
output:
the function is void, but it will store the squaresum in the first memory location in the array. */
void storeSumOfSquares(int * array, int size) {

	int squaresum = 0;
	for(size_t i=2; i<=(size+1); i++) {
		squaresum += (array[i]*array[i]);
	}
	array[0] = squaresum;
}
/* This function will receive an integer array and return the sum of the squares of its elements, which is assumed to be stored in the first memory location.
inputs:
int* array: this is the user-provided array that will be analyzed.
output:
array[0]: this is the sqaure of the sums stored in the first memory location. */
int getSumOfSquares (int * array)
{
	return array[0];
}
/*This function receives the integer array and frees the memory that has been allocated.
input:
int* array: this is the user-provided array that will be freed.
output:
The function is void.*/
void freeArray(int* array) {
	free(array);
}
