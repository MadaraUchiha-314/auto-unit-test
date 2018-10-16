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
#include "nested-structs.h"


int main() {
	/*
	 * The whole body of the program.
	 */
	int var_0 = 1;
	int var_1 = 0;
	int var_2 = 0;
	int var_3 = 0;
	struct Distance var_4 = {.p2={.y=var_0,.x=var_1},.p1={.y=var_2,.x=var_3}};
	assert(CalcDistanceSquare(var_4) == 1);
	int var_5 = 5;
	int var_6 = 5;
	int var_7 = 0;
	int var_8 = 0;
	struct Distance var_9 = {.p2={.y=var_5,.x=var_6},.p1={.y=var_7,.x=var_8}};
	assert(CalcDistanceSquare(var_9) == 50);

	/*
	 * The good ol' return 0;
	 */
	return 0;
}
