# auto-unit-test [![CircleCI](https://circleci.com/gh/MadaraUchiha-314/auto-unit-test/tree/master.svg?style=svg)](https://circleci.com/gh/MadaraUchiha-314/auto-unit-test/tree/master)
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

<table>
<tr>
    <th>Functionality</th>
    <th>Status</th>
    <th>Library Code</th>
    <th>Auto Generated Unit Test</th>
</tr>
<tr>
    <td>Simple C function working.</td>
    <td>✅</td>
    <td>[Simple C function]</td>
    <td>[Simple C function Unit Test]</td>
</tr>
<tr>
    <td>C functions which takes struct argument.</td>
    <td>✅</td>
    <td>[Simple Struct function]</td>
    <td>[Simple Struct function Unit Test]</td>
</tr>
<tr>
    <td>C functions which takes nested struct argument.</td>
    <td>✅</td>
    <td>[Nested Struct function]</td>
    <td>[Nested Struct function Unit Test]</td>
</tr>
<tr>
    <td>C functions which returns nested struct value.</td>
    <td>✅</td>
    <td>[Struct Return function]</td>
    <td>[Struct Return function Unit Test]</td>
</tr>
<tr>
    <td> C functions which takes pointer arguments.</td>
    <td>✅</td>
    <td>[Pointer Function]</td>
    <td>[Pointer Function Unit Test]</td>
</tr>
<tr>
    <td> C functions which returns pointer.</td>
    <td>✅</td>
    <td>[Pointer Function]</td>
    <td>[Pointer Function Unit Test]</td>
</tr>
<tr>
    <td>C functions which takes arrays (through pointer)</td>
    <td></td>
    <td></td>
    <td></td>
</tr>
</table>


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
