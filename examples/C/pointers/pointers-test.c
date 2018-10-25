/*
 * This is a templace of a C-Program that will contain the automatically generated unit test code.
 * This will be iteratively imporoved when more and more complex things are implemented.
 */

/*
 * assert.h is included for assertions that we make while writing the unit tests.
 * stdlib.h is used for malloc.
 */
#include <assert.h>
#include <stdlib.h>
/*
 * Other header files that are required by the program
 */
#include "pointers.h"


int main() {
	/*
	 * The whole body of the program.
	 */

	/* TEST CASE START : # 0 */
	int var_0 = 5;
	int var_1 = 10;
	struct Person* var_2 = (struct Person*) malloc(sizeof(struct Person));
	*var_2 = (struct Person) {.age=var_0,.weight=var_1};
	int var_3 = getRank(var_2);
	assert(var_3 == 50);
	/* TEST CASE END : # 0 */

	/* TEST CASE START : # 1 */
	int var_4 = 5;
	int var_5 = 10;
	struct Person* var_6 = getPerson(var_4,var_5);
	assert(var_6->age == 5);
	assert(var_6->weight == 10);
	/* TEST CASE END : # 1 */

	/* TEST CASE START : # 2 */
	int* var_7 = (int*) malloc(sizeof(int));
	*var_7 = 10;
	int var_8 = modifyInt(var_7);
	assert(var_8 == 11);
	/* TEST CASE END : # 2 */

	/* TEST CASE START : # 3 */
	int* var_9 = (int*) malloc(sizeof(int));
	*var_9 = 10;
	int* var_10 = getInt(var_9);
	assert(*var_10 == 10);
	/* TEST CASE END : # 3 */

	/*
	 * The good ol' return 0;
	 */
	return 0;
}
