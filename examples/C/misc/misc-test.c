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
#include "misc.h"


int main() {
	/*
	 * The whole body of the program.
	 */

	/* TEST CASE START : # 0 */
	int var_0 = 20;
	int var_1 = 10;
	struct Point var_2 = {.y=var_0,.x=var_1};
	int var_3 = 5;
	struct Point var_4 = scalarMultiplication(var_2,var_3);
	assert(var_4.y == 100);
	assert(var_4.x == 50);
	/* TEST CASE END : # 0 */

	/*
	 * The good ol' return 0;
	 */
	return 0;
}
