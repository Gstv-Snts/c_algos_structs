CC = gcc
CCFLAGS = -Iinclude -Wall
RUN = build/src
TEST = build/tests
SOURCES := $(shell find src/ -name '*.c')
TESTS := $(shell find tests/ -name '*.c')


@make:
	@if [ ! -d build/ ]; then \
		echo "Creating build/"; \
		mkdir -p build/ && cd build/ && cmake .. && mv compile_commands.json ..; \
		echo "buid/ created"; \
	fi 

test:
	@make --no-print-directory
	@cd build/ && make
	@echo "############" 
	@echo ""
	@./$(TEST)
	@echo ""
	@echo ""
	@echo "############" 

cov:
	@make --no-print-directory
	@cd build/ && make
	@lcov --capture --directory . --output-file coverage.info
	@lcov --remove coverage.info '*/libs/*' '*/tests/*' --output-file coverage.info
	@genhtml coverage.info --output-directory out
	@cd out/ && google-chrome index.html

debug_test:
	@make --no-print-directory
	@echo "############" 
	@echo ""
	@gdb ./$(TEST)
	@echo ""
	@echo ""
	@echo "############" 

clean:
	@sudo rm -r build/ 
	@sudo rm -r compile_commands.json
	@sudo rm -r libs/

.PHONY: all clean
