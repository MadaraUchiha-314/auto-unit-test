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
#include "simple-structs.h"


int main() {
    /*
    * The whole body of the program.
    */
    int var_0 = 3;
int var_1 = 4;
struct Complex var_2 = {.real=var_0,.img=var_1};assert(moduloSquareComplex(var_2) == 25);
int var_3 = 5;
int var_4 = 12;
struct Complex var_5 = {.real=var_3,.img=var_4};assert(moduloSquareComplex(var_5) == 169);

    /*
    * The good ol' return 0;
    */
    return 0;
}
