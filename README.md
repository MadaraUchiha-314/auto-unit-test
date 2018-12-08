# auto-unit-test [![CircleCI](https://circleci.com/gh/MadaraUchiha-314/auto-unit-test/tree/master.svg?style=svg)](https://circleci.com/gh/MadaraUchiha-314/auto-unit-test/tree/master) [![codecov](https://codecov.io/gh/MadaraUchiha-314/auto-unit-test/branch/master/graph/badge.svg)](https://codecov.io/gh/MadaraUchiha-314/auto-unit-test)

No writing unit tests again!

## Goals
- Generate unit tests from a given JSON file which contains the test.
    - This project is currently at this stage.
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

|Functionality|Status|Library Code|Auto Generated Unit Test|
|--- |--- |--- |--- |
|Simple C function working.|✅|[Simple C function]|[Simple C function Unit Test]|
|C functions which takes struct argument.|✅|[Simple Struct function]|[Simple Struct function Unit Test]|
|C functions which takes nested struct argument.|✅|[Nested Struct function]|[Nested Struct function Unit Test]|
|C functions which returns nested struct value.|✅|[Struct Return function]|[Struct Return function Unit Test]|
|C functions which takes pointer arguments.|✅|[Pointer Function]|[Pointer Function Unit Test]|
|C functions which returns pointer.|✅|[Pointer Function]|[Pointer Function Unit Test]|
|Support for all primitive data-types.|✅|[Data Type Function]|[Data Type Unit Test]|
|C functions which takes arrays (through pointer)||||
|Monitoring side-effects and global changes|||||

[Simple C function]: examples/C/simple-functions/simple-functions.h
[Simple C function Unit Test]: examples/C/simple-functions/simple-functions-test.c

[Simple Struct function]: examples/C/simple-structs/simple-structs.h
[Simple Struct function Unit Test]: examples/C/simple-structs/simple-structs-test.c

[Nested Struct function]: examples/C/nested-structs/nested-structs.h
[Nested Struct function Unit Test]: examples/C/nested-structs/nested-structs-test.c

[Struct Return function]: examples/C/struct-return/struct-return.h
[Struct Return function Unit Test]: examples/C/struct-return/struct-return-test.c

[Pointer Function]: examples/C/pointers/pointers.h
[Pointer Function Unit Test]: examples/C/pointers/pointers-test.c

[Data Type Function]: examples/C/data-types/data-types.h
[Data Type Unit Test]: examples/C/data-types/data-types-test.c
