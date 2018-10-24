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
#include "nested-structs.h"


int main() {
	/*
	 * The whole body of the program.
	 */

	/* TEST CASE START : # 0 */
	int var_0 = 1;
	int var_1 = 0;
	int var_2 = 0;
	int var_3 = 0;
	struct Distance var_4 = {.p2={.y=var_0,.x=var_1},.p1={.y=var_2,.x=var_3}};
	int var_5 = CalcDistanceSquare(var_4);
	assert(var_5 == 1);
	/* TEST CASE END : # 0 */

	/* TEST CASE START : # 1 */
	int var_6 = 5;
	int var_7 = 5;
	int var_8 = 0;
	int var_9 = 0;
	struct Distance var_10 = {.p2={.y=var_6,.x=var_7},.p1={.y=var_8,.x=var_9}};
	int var_11 = CalcDistanceSquare(var_10);
	assert(var_11 == 50);
	/* TEST CASE END : # 1 */

	/*
	 * The good ol' return 0;
	 */
	return 0;
}
