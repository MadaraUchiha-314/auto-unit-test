# auto-unit-test
No writing unit tests again!

## Goals
- Generate unit tests from a given JSON file which contains the test.
- Generate the above JSON file automatically by parsing the code.
- Given the current state, execute the unit tests, take a snapshot and save it for later comparison.

## Generating and running a test
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
- [ ] C functions with takes struct argument
- [ ] C functions with takes nested struct argument
- [ ] C functions with returns nested struct value
- [ ] C functions with takes pointer arguments
- [ ] C functions with returns nested struct value

[Simple C function]: examples/c/simple-functions/simple-functions.h
