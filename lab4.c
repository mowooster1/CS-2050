#include <stdio.h>
#include <stdlib.h>

typedef struct {
	    int recipeID, eggQuantity;
			float flourWeight;
		} Recipe;

Recipe* readRecipeFile(FILE*);
int getSize(Recipe*);

void setRecipeID(Recipe*,int);
void setRecipeEggQuantity(Recipe*,int);
void setRecipeFlourWeight(Recipe*,float);
int getRecipeID(Recipe*);
int getRecipeEggQuantity(Recipe*);
float getRecipeFlourWeight(Recipe*);

Recipe* getRecipeByID(Recipe*,int);
int countRecipe(Recipe*,float,float);
void freeRecipeArray(Recipe*);

int main() {
	FILE *ptr = fopen("recipes.csv", "r");
	if (ptr==NULL) {
		printf("No such file exists.\n");
		return -1;
	}

	Recipe* array = (Recipe*)readRecipeFile(ptr);
	Recipe* chosen = getRecipeByID(array, 20);
	printf("here is the recipe id of 20: %d\n", getRecipeID(chosen));
	printf("here is the egg quantity of 20: %d\n", getRecipeEggQuantity(chosen));
	printf("here is the flour weight of 20: %f\n", getRecipeFlourWeight(chosen));
	printf("here is the size of the array: %d\n", getSize(array));
	setRecipeID(chosen, 34);
	setRecipeEggQuantity(chosen, 50);
	setRecipeFlourWeight(chosen, 50.1);
	printf("here is the new recipe id of 20: %d\n", getRecipeID(chosen));
	printf("here is the new egg quantity of 20: %d\n", getRecipeEggQuantity(chosen));
	printf("here is the new flour weight of 20: %f\n", getRecipeFlourWeight(chosen));
	printf("Here is the number of recipes with flour weight above %f and below %f: %d\n", 0.0, 500.0, countRecipe(array, 0.0, 500.0));


	freeRecipeArray(array);
	array = NULL;

	return 1;
}
/*This function receies a file pointer, assumed to be pointed to a csv file. It creates
an array of "Recipe" structs with the size of the array hidden in front.
inputs:
FILE* ptr - this is the file pointer pointing to a csv list of recipes
outputs:
Recipe* recipeList - this is the array of recipe structs with the size hidden in front. */

Recipe* readRecipeFile(FILE* ptr) {

	int x;
	fscanf(ptr, "%d,,", &x); //reading in the size

	Recipe* array = (Recipe*)malloc(x*sizeof(Recipe)+sizeof(int)); //allocating space for the array
	if (array == NULL) {
		printf("Error in allocating space for array");
		return NULL;
	}

	*((int*)(array)) = x; //setting the size as the first memory location
	array = (Recipe*)((int*)array + 1); //moving to the first recipe spot

	for (int i=0; i<x; i++) {
		fscanf(ptr, "%d,%d,%f", &array[i].recipeID, &array[i].eggQuantity, &array[i].flourWeight);
	}

	fclose(ptr);
	return (Recipe*)array;
}

/* This function receives an array of Recipe structs and return the size of the array, assumed
to be hidden as an int in front of the array.
inputs:
Recipe* array - this is the array of Recipe structs.
outputs:
int size - this is the size of the array. */

int getSize(Recipe* array) {
	int *size;
	size = ((int*)array-1);
	return *size;
}

/* This function receives a pointer to an individual recipe struct, sets its id as the second
parameter.
inputs:
Recipe * selected - this is the pointer to the seleceted recipe struct
int id - this is the desired id
outputs:
this function returns no output. */

void setRecipeID(Recipe* selected,int id) {
	selected->recipeID=id;
}

/* This function receives a pointer to an individual recipe struct, sets its egg quantity as the second
parameter.
inputs:
Recipe * selected - this is the pointer to the seleceted recipe struct
int eggs - this is the desired number of eggs
outputs:
this function returns no output. */

void setRecipeEggQuantity(Recipe* selected,int eggs) {
	selected->eggQuantity=eggs;
}

/* This function receives a pointer to an individual recipe struct, sets its flour weight as the second
parameter.
inputs:
Recipe * selected - this is the pointer to the seleceted recipe struct
float flour - this is the desired flour weight
outputs:
this function returns no output. */

void setRecipeFlourWeight(Recipe* selected,float flour) {
	selected->flourWeight=flour;
}

/*This function receives a pointer to an individual recipe struct, returns its id.
inputs:
Recipe* selected - this is the pointer to the desired recipe.
outputs:
selected->recipeID - this is the id number of the selected recipe. */

int getRecipeID(Recipe* selected){
	return selected->recipeID;
}

/*This function receives a pointer to an individual recipe struct, returns its egg quantity.
inputs:
Recipe* selected - this is the pointer to the desired recipe.
outputs:
selected->eggQuantity - this is the egg quantity of the selected recipe. */

int getRecipeEggQuantity(Recipe* selected) {
	return selected->eggQuantity;
}

/*This function receives a pointer to an individual recipe struct, returns its flour weight.
inputs:
Recipe* selected - this is the pointer to the desired recipe.
outputs:
selected->flourWeight - this is the flour weight of the selected recipe. */

float getRecipeFlourWeight(Recipe* selected) {
	return selected->flourWeight;
}

/* This function receives the struct array and an integer. It searches the first recipe which has
an ID that is equal to the second input value, then returns the pointer to that recipe struct or
NULL if data does not exist.
inputs:
Recipe* selected - this is the struct array of recipes to be searched
int id - this is the desired recipe id
outputs:
&selected[i] - this is the desired recipe id. */

Recipe* getRecipeByID(Recipe* selected,int id) {

		int x = getSize(selected);

		for (size_t i=0; i<x; i++) {
			if (getRecipeID(&selected[i]) == id) {
				return &selected[i];
			}
		}
		printf("No recipe found by that ID.\n");
		return NULL;
}

/* This function receives the struct array, and two floats as inputs. It counts the number of recipes
which has flour weight that is larger than the first float, and smaller than the second float, and
returns this counted number as an integer.
inputs:
Recipe* array - this is the struct array of recipes
float small - this is the number that all the counted recipes need to be larger than
float big - this is the number that all the counted recipes need to be smaller than
outputs:
int count - this is the number of recipes that satisfy the requirements. */

int countRecipe(Recipe* array, float small, float big) {

	int x = getSize(array), count=0;

	for (size_t i=0; i<x; i++) { //counting the recipes that meet the requirements
		if ((getRecipeFlourWeight(&array[i]) > small) && (getRecipeFlourWeight(&array[i]) < big)) {
			count += 1;
		}
	}
	return count;
}

/*This function receives the struct array, and frees all the previously allocated memories.
inputs:
Recipe* array - this is the struct array to be freed.
outputs:
this function creates no outputs. */

void freeRecipeArray(Recipe* array) {
	array = (Recipe*)((int*)array -1); //incrementing back to the hidden array size
	free(array);
	array = NULL;
}
