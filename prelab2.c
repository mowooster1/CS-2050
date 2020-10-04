#include <stdio.h>
#include <stdlib.h>

double* createDoubleArray(int minIndex, int maxIndex);

void freeDoubleArray (double* array[], int startingIndex);

void readDataIntoArray(FILE *fp, int min, int max, double* testarray);

double AverageRainfall(double arr[], int start, int end);

int main()
{
	FILE *fptr;

	fptr = fopen("raintest.txt", "r");
	if (fptr == NULL) {
		printf("There was an error in file creation.\n");
		exit(1);
	}

	double* rainfall = NULL;

	rainfall = createDoubleArray(1920, 1930);
	if (rainfall==NULL) {
		printf("There was an error in array creation.\n");
	}

	else {
		readDataIntoArray(fptr, 1920, 1930, rainfall);
		if (rainfall == NULL) {
			printf("There was an error in filling the array.\n");
		}
		else {
			printf("Elements in array:\n");
			for (size_t i = 1920; i < 1930; i++) {
			printf("%.2f\n", rainfall[i]);
			}
		}
	}

	printf("Average rainfall in 1922: %.2lf\n", rainfall[1922]);
	printf("Average rainfall between 1923 and 1925: %lf\n", AverageRainfall(rainfall, 1923, 1925));

	freeDoubleArray(&rainfall, 1920);

	return 0;
}

double* createDoubleArray(int minIndex, int maxIndex) {

	double* a = malloc(sizeof(int) + (20)*sizeof(double));
	if (a == NULL) {
		printf("There was an error in malloc creation.");
		return NULL;
	}
	return a;
}

void freeDoubleArray (double* array[], int startingIndex) {
	free(*array);
}

void readDataIntoArray(FILE *fp, int min, int max, double* testarray) {

	for (int i=min; i<max; i++) {
		fscanf(fp, "%lf", &testarray[i]);
	}

	fclose(fp);
}

double AverageRainfall(double arr[], int start, int end) {

	double sum;
	for (int i=start; i<=end; i++) {
		sum += arr[i];
	}
	sum = sum/((end-start)+1);
	return sum;
}
