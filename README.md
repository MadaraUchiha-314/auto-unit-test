# auto-unit-test
No writing unit tests again!

## Goals
- Generate unit tests from a given JSON file which contains the test.
- Generate the above JSON file automatically by parsing the code.
- Given the current state, execute the unit tests, take a snapshot and save it for later comparison.

## Generating and running a test
- To generate a unit-test for all suites
```shell
make all
```
- To run all unit tests generated.
```shell
make test-all
```
- To generate a unit-test for a suite, say `examples/C/simple-functions/simple-functions-test.json`
```shell
make c-unit-tests test=examples/C/simple-functions/simple-functions-test
```
- To run a unit test.
```shell
make test-c-unit-tests test=examples/C/simple-functions/simple-functions-test
```


## Current State.
- [x] Simple C function working. [Simple C function]
- [x] C functions which takes struct argument. [Simple Struct function]
- [x] C functions which takes nested struct argument. [Nested Struct function]
- [x] C functions which returns nested struct value. [Struct Return function]
- [x] C functions which takes pointer arguments. [Pointer Function]
- [ ] C functions which return pointer arguments
- [ ] C functions which modify pointer arguments
- [ ] C functions which takes arrays (through pointer)

[Simple C function]: examples/C/simple-functions/simple-functions.h
[Simple Struct function]: examples/C/simple-structs/simple-structs.h
[Nested Struct function]: examples/C/nested-structs/nested-structs.h
[Struct Return function]: examples/C/struct-return/struct-return.h
[Pointer Function]: examples/C/pointers/pointers.h
