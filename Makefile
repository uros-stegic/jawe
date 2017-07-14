TEST_EXAMPLE	= ../tests/syntax/functions.js
JAWE_FLAGS		= --print

.PHONY: all clean run

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
	time ./jawe --input-file $(TEST_EXAMPLE) $(JAWE_FLAGS)
	@echo " "
	@echo "|_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_|"
	@echo " "

clean:
	./build.sh --remove

run:
	@echo " "
	@echo " "
	@echo "|_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_|  Executing program  |_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_|"
	@echo " "
	@cd build; \
	time ./jawe --input-file $(TEST_EXAMPLE) $(JAWE_FLAGS)
	@echo " "
	@echo "|_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_/^\_|"
	@echo " "
