c-unit-tests:
	# Auto-Gnerating the unit tests
	python src/drivers/C/driver.py "$(test).json"

	# Making the bin folder for putting all executables
	mkdir -p "bin/$(test)"

	# This is for auto-indenting the code
	echo -e "G=gg\n:wq\n" | vim $(test).c

	# Compiling the code
	gcc "$(test).c" -o "bin/$(test)/output.out"
test-c-unit-tests:
	# Executing the generated binary
	./bin/$(test)/output.out
all:
	# make c-unit-tests test=examples/C/simple-functions/simple-functions-test
	# make c-unit-tests test=examples/C/simple-structs/simple-structs-test
	# make c-unit-tests test=examples/C/nested-structs/nested-structs-test
	# make c-unit-tests test=examples/C/struct-return/struct-return-test
	# make c-unit-tests test=examples/C/misc/misc-test
	make c-unit-tests test=examples/C/pointers/pointers-test
test-all:
	make test-c-unit-tests test=examples/C/simple-functions/simple-functions-test
	make test-c-unit-tests test=examples/C/simple-structs/simple-structs-test
	make test-c-unit-tests test=examples/C/nested-structs/nested-structs-test
	make test-c-unit-tests test=examples/C/struct-return/struct-return-test
	make test-c-unit-tests test=examples/C/misc/misc-test
	make test-c-unit-tests test=examples/C/pointers/pointers-test

clean:
	find . -path './bin/**/*.out' -delete
	find . -path './examples/C/**/*.c' -delete
