c-unit-tests:
	python src/drivers/C/driver.py "$(test).json"
	mkdir -p "bin/$(test)"
	gcc "$(test).c" -o "bin/$(test)/output.out"
test-c-unit-tests:
	./bin/$(test)/output.out
clean:
	find . -path './bin/**/*.out' -delete
	find . -path './examples/C/**/*.c' -delete
