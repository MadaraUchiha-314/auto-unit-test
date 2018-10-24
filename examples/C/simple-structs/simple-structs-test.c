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
#include "simple-structs.h"


int main() {
	/*
	 * The whole body of the program.
	 */
	int var_0 = 3;
	int var_1 = 4;
	struct Complex var_2 = {.real=var_0,.img=var_1};
	int var_3 = moduloSquareComplex(var_2);
	assert(var_3 == 25);
	int var_4 = 5;
	int var_5 = 12;
	struct Complex var_6 = {.real=var_4,.img=var_5};
	int var_7 = moduloSquareComplex(var_6);
	assert(var_7 == 169);

	/*
	 * The good ol' return 0;
	 */
	return 0;
}
