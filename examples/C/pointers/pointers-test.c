/*
 * This is a templace of a C-Program that will contain the automatically generated unit test code.
 * This will be iteratively imporoved when more and more complex things are implemented.
 */

/*
 * assert.h is included for assertions that we make while writing the unit tests.
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
	int var_0 = 5;
	int var_1 = 10;
	struct Person* var_2 = (struct Person*) malloc(sizeof(struct Person));
	*var_2 = (struct Person) {.age=var_0,.weight=var_1};
	int var_3 = getRank(var_2);
	assert(var_3 == 50);

	/*
	 * The good ol' return 0;
	 */
	return 0;
}
