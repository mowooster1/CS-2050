#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int ID, jobType;
	float salary;
} Employee;

Employee* readEmployeeInfo(FILE *fp);
int getSize(FILE *fp);
void freeArray(Employee *array);
Employee* getEmployeebyID(Employee*, int);
void setID(Employee *p, int id);
int getID(Employee *p);
void setSalary(Employee *p, float salary);
void getAvgSalary(Employee *p);
float getSalary(Employee *e);

int main() {
	FILE *ptr = fopen("sample.txt", "r");
	if (ptr==NULL) {
		printf("No such file exists.\n");
		return -1;
	}

	Employee *arr = readEmployeeInfo(ptr);
	getAvgSalary(arr);


	freeArray(arr);

	return 1;
}

Employee* readEmployeeInfo(FILE *fp) {

	int x = getSize(fp);

	Employee* array = malloc(x*sizeof(Employee));
	if (array == NULL) {
		printf("Error in allocating space for array");
		return NULL;
	}

	for (int i=0; i<x; i++) {
		fscanf(fp, "%d,%d,%f", &array[i].ID, &array[i].jobType, &array[i].salary);
	}

	fclose(fp);
	return array;
}

int getSize(FILE *fp) {
	int x;
	fscanf(fp, "%d", &x);
	return x;
}

void freeArray(Employee *array) {
	free(array);
	array = NULL;
}

int getID(Employee *p) {
	return p->ID;
}

Employee* getEmployeebyID(Employee* emp, int ID) {

	for (size_t x=0; x<3; x++) {
		if (getID(&emp[x]) == ID) {
			return &emp[x];
		}
	}
	printf("No employee found by that ID.\n");
	return NULL;
}

void setID(Employee *p, int id) {
	p->ID=id;
}

float getSalary(Employee *e){
    return e->salary;
}

void setSalary(Employee *p, float salary) {
	p->salary=salary;
}

void getAvgSalary(Employee *p){
    float sum=0;
    for(size_t i=0;i<3;i++){
        sum+=getSalary(&p[i]);
    }
    float average = sum/3;
    printf("These employees have an above-average salary:\n");
    for(size_t i=0;i<3;i++){
        if(getSalary(&p[i])>average)
            printf("%d\n",getID(&p[i]));
    }

}
