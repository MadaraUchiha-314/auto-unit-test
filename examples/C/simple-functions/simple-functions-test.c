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
#include "simple-functions.h"


int main() {
    /*
    * The whole body of the program.
    */
    int var_0 = 5;
assert(doubleInt(var_0) == 10);
int var_1 = 10;
assert(doubleInt(var_1) == 20);


    /*
    * The good ol' return 0;
    */
    return 0;
}