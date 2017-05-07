.PHONY: all clean

all:
	@mkdir -p build
	@cd build; \
	cmake ..;\
	make;
	@echo " "
	@echo " "
	@echo "|_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_|  Executing program  |_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_|"
	@echo " "
	@cd build; \
	time ./jawe --input ../tests/semantics/assignments.js --dump-ast
	@echo " "
	@echo "|_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_|"
	@echo " "

clean:
	./build.sh --remove

