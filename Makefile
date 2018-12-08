c-unit-tests:
	# Auto-Gnerating the unit tests
	python src/drivers/C/driver.py "$(test).json"

	# Making the bin folder for putting all executables
	mkdir -p "bin/$(test)"

	# This is for auto-indenting the code
	echo -e "G=gg\n:wq\n" | vim $(test).c

	# Compiling the code
	gcc -coverage "$(test).c" -o "bin/$(test)/output.out"
test-c-unit-tests:
	# Executing the generated binary
	./bin/$(test)/output.out
coverage-c-unit-tests:
	gcov "$(test).c"
all:
	make c-unit-tests test=examples/C/simple-functions/simple-functions-test
	make c-unit-tests test=examples/C/simple-structs/simple-structs-test
	make c-unit-tests test=examples/C/nested-structs/nested-structs-test
	make c-unit-tests test=examples/C/struct-return/struct-return-test
	make c-unit-tests test=examples/C/misc/misc-test
	make c-unit-tests test=examples/C/pointers/pointers-test
	make c-unit-tests test=examples/C/data-types/data-types-test
test-all:
	make test-c-unit-tests test=examples/C/simple-functions/simple-functions-test
	make test-c-unit-tests test=examples/C/simple-structs/simple-structs-test
	make test-c-unit-tests test=examples/C/nested-structs/nested-structs-test
	make test-c-unit-tests test=examples/C/struct-return/struct-return-test
	make test-c-unit-tests test=examples/C/misc/misc-test
	make test-c-unit-tests test=examples/C/pointers/pointers-test
	make test-c-unit-tests test=examples/C/data-types/data-types-test
cov-all:
	make coverage-c-unit-tests test=simple-functions-test
	make coverage-c-unit-tests test=simple-structs-test
	make coverage-c-unit-tests test=nested-structs-test
	make coverage-c-unit-tests test=struct-return-test
	make coverage-c-unit-tests test=misc-test
	make coverage-c-unit-tests test=pointers-test
	make coverage-c-unit-tests test=data-types-test
clean:
	find . -path './bin/**/*.out' -delete
	find . -path './examples/C/**/*.c' -delete
	find . -path './*.gcda' -delete
	find . -path './*.gcno' -delete
	find . -path './*.gcov' -delete
