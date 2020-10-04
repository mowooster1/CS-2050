#include <stdio.h>
#include <stdlib.h>

double* createDoubleArray(int n);
int getDoubleArraySize(double *array);
void freeDoubleArray(double *a);
void* createArray(int n, int dataTypeSize);
int getArraySize(void *arr);
void freeArray(void *arr2);

int main() {

	double *arr = createDoubleArray(5);
	if (arr==NULL) {
		printf("Array creation failed.\n");
		return -1;
	}

	int size = getDoubleArraySize(arr);
	printf("size: %d\n", size);
	freeDoubleArray(arr);

	printf("first one: %f\n", arr[1	printf("Elements in array are: ");
		for (size_t i = 0; i < -1; i++){
			printf("%d, ", array[i]);
		}]);
	printf("Elements in array are: ");
	for (size_t i = 0; i <=size; i++){
		printf("%f, ", arr[i]);
	}

	float *arr2 = createArray(6, sizeof(float));
	if (arr2 == NULL) {
		printf("Array creation 2 failed.\n");
		return -1;
	}

	int size2 = getArraySize(arr2);
	printf("size: %d\n", size2);
	freeArray(arr2);

	return 1;
}

double* createDoubleArray(int n){
	double *array = malloc(n*(sizeof(double))+sizeof(int));
	if (array==NULL) {
		printf("Error in array size allocation.\n");
		return NULL;
	}
	*(array) = n;
	array = array + 1; //moving the array pointer forward
	for (size_t i=0; i<=n; i++) {
		array[i] = (i+0.74);
	}
	return array;
}

int getDoubleArraySize(double *array) {
	return *(array-1);
}

void freeDoubleArray(double* a) {
	a = a-1;
	free(a);
}

void* createArray(int n, int dataTypeSize) {
	void* Array = malloc(n*(sizeof(dataTypeSize))+sizeof(int));
	if (Array == NULL) {
		printf("Error in allocation of array size");
		return NULL;
	}
	*((int*)Array) = n;
	Array = Array + 1;
	return Array;
}

int getArraySize(void *arr) {
	return *((int*)(arr-1));
}

void freeArray(void *arr2) {
	arr2 = arr2-1;
	free(arr2);
	arr2 = NULL;
}
