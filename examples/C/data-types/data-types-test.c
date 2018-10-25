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
#include "data-types.h"


int main() {
	/*
	 * The whole body of the program.
	 */

	/* TEST CASE START : # 0 */
	int var_0 = 5;
	char var_1 = 'a';
	double var_2 = 10.5;
	double var_3 = 20.5;
	int var_4 = testMultipleDataTypes(var_0,var_1,var_2,var_3);
	assert(var_4 == 5);
	/* TEST CASE END : # 0 */

	/* TEST CASE START : # 1 */
	char var_5 = 'a';
	char var_6 = testCharReturnType(var_5);
	assert(var_6 == 'a');
	/* TEST CASE END : # 1 */

	/* TEST CASE START : # 2 */
	double var_7 = 10.5;
	double var_8 = testDoubleReturnType(var_7);
	assert(var_8 == 10.5);
	/* TEST CASE END : # 2 */

	/*
	 * The good ol' return 0;
	 */
	return 0;
}
