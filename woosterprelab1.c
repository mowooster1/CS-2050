#include <stdio.h>
#include <stdlib.h>

/*	This function will accept an array of floats and a user-provided float(num).
It will return the sum of the largest number in the array smaller than num,
and the smallest number in the array that is greater than num.	*/

int find(float array[], int size, int key);

int readfile(FILE *fptr, float *arr);

int main()
{
	FILE *ptr;
	float a[5];
	ptr = fopen("testnumbers.txt", "r");

	if (ptr == NULL) {
		printf("Error, no file exists.");
		exit(1);
	}

	readfile(ptr, a);

	// attempting a search query that exists
	int y = find(a, 6, 9.7);
	//attempting a search query that does not exist
	int v = find(a, 6, 20);

	for (int i=0; i<(sizeof(a)-2); i++) {
		printf("\n%f\n", a[i]);
	}

	printf("Query result for key %f: %d\n", 9.7, y);
	printf("Query result for key %d: %d\n", 20, v);
}

int readfile(FILE *fptr, float *arr) {
	int x;
	fscanf(fptr, "%d", &x);

	//arr = malloc(x*sizeof(float));

	for (int i=0; i<x; i++) {
		fscanf(fptr, "%f", &arr[i]);
	}

	printf("Array is:");
	printf(" %f", arr[0]);

	for (size_t t=1; t<(sizeof(arr)-2); t++) {
		printf(",");
		printf(" %f", arr[t]);
	}

	fclose(fptr);

	return 0;
}

/* This function accepts an integer array, an integer giving the size of the array,
and a search query. It will loop through the array and return the location of the
key if found, and a -1 if not.
inputs: arr (array that will be searched), size (size of the array),
key (desired search query)
output: index of search query key if the array contains it, -1 if not.	*/

int find(float arr[], int size, int key)
{
	for (size_t i=0; i<size; i++) {
		if(arr[i] == key) {
			return i;
    }
  }
	return -1;
}
