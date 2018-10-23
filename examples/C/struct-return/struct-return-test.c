/*
 * This is a templace of a C-Program that will contain the automatically generated unit test code.
 * This will be iteratively imporoved when more and more complex things are implemented.
 */

/*
 * assert.h is included for assertions that we make while writing the unit tests.
 */
#include <assert.h>

/*
 * Other header files that are required by the program
 */
#include "struct-return.h"


int main() {
	/*
	 * The whole body of the program.
	 */
	int var_0 = 5;
	int var_1 = 10;
	struct Person var_2 = getPerson(var_0,var_1);
	assert(var_2.age == 5);
	assert(var_2.weight == 10);

	/*
	 * The good ol' return 0;
	 */
	return 0;
}
