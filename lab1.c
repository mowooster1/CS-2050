#include <stdio.h>
#include <stdlib.h>

float* readPackagesIntoArray(FILE *fp, int* totalNumofPackages);

void countPackages(float arr[], int size, int smallPackageSize, int largePackageSize, int* numofSmallPackages, int* numOfMediumPackages, int* numOfLargePackages);

int main()
{
	int size=0, numSmall=0, numLarge=0, numMed=0;
	int small=30, large=70;
	FILE *ptr;
	//open file with test data
	ptr = fopen("packages.txt", "r");

	//check that the test data file exists
	if (ptr == NULL) {
		printf("Error, no file exists.");
		exit(1);
	}

	//copy data from test file into an array of floats, then count the number of small, medium, and large packages within the array
	countPackages((readPackagesIntoArray(ptr, &size)), 14, small, large, &numSmall, &numMed, &numLarge);

	//print the number of each size of package within the given array
	printf("%d packages are small, %d packages are medium, %d packages are large.\n", numSmall, numMed, numLarge);

	return 0;
}

/*	This function accepts a file and an integer pointer as inputs. It is assumed that the first line of the file contains an integer
giving the size of the array, and that float values representing the size of each package follow on individual lines.
Inputs:
fp = the file to be read
totalNumofPackages = the integer pointer that will store the number of packages (presumed to be the first line of the file)
Returns:
a = a float array that contains the package weights from the file	*/

float* readPackagesIntoArray(FILE *fp, int* totalNumofPackages) {

	float *a;

	//reads the first line of the file and uses it to dynamically allocate an array with the appropriate amount of space
	fscanf(fp, "%d", totalNumofPackages);
		a = malloc(sizeof(int) + (*totalNumofPackages)*sizeof(float));

	//reads the remaining lines of the file and stores them in the created array
	for (int i=0; i<*totalNumofPackages; i++) {
		fscanf(fp, "%f", &a[i]);
	}

	fclose(fp);

	//returns the populated array
	return a;
}

/*	This function takes a float array of package weight, the array size, and the parameters defining the size of packages according to their weights. It then
counts the number of each size of package and stores that data in integer pointer parameters. It is assumed that small packages are less than or equal to the smallPackageSize
parameter, medium packages are greater than smallPackageSize but less than largePackageSize, and large packages are greater than or equal to largePackageSize.
Inputs:
arr: the float array of package weights
size: the size of the float array
smallPackageSize : the parameter defining the upper bounds for the weight of a small package
largePackageSize : the parameter defining the lower bounds for the weight of a large packages
Outputs:
numofSmallPackages : the number of counted small packages according to the given definitions
numOfMediumPackages : the number of counted medium packages according to the given definitions
numOfLargePackages : the number of counted large packages according to the given definitions */

void countPackages(float arr[], int size, int smallPackageSize, int largePackageSize, int* numofSmallPackages, int* numOfMediumPackages, int* numOfLargePackages) {

	//this for loop iterates through the given array in order to count each of the types of packages
	for (int o=0; o<size; o++) {
		//counting number of large packages
		if (arr[o] >= largePackageSize) {
			*numOfLargePackages = (*numOfLargePackages + 1);
		}
		//counting number of medium packages
		else if (arr[o] > smallPackageSize) {
			*numOfMediumPackages = (*numOfMediumPackages + 1);
		}
		//counting number of small packages
		else {
			*numofSmallPackages = (*numofSmallPackages + 1);
		}
	}
}
