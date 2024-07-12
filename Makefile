CC = g++
CCFLAGS = -Iinclude -std=c++20 -Wall
RUN = build/src
TEST = build/tests
SOURCES := $(shell find src/ -name '*.cpp')
TESTS := $(shell find tests/ -name '*.cpp')


@$(BUILD_DIR):
	@if [ ! -d build/ ]; then \
		echo "Creating build/"; \
		mkdir -p build/; \
		echo "buid/ created"; \
	fi 
	@if [ ! -f compile_commands.json ]; then \
		echo "Creating compile_commands.json"; \
		echo '[{"directory": "$(shell pwd)","command": "clang++ -I./include","file": ""},]' > compile_commands.json; \
		echo "compile_commands.json created."; \
	fi 

run:
	@make --no-print-directory
	@$(CC)  $(CCFLAGS) cmd/main.cpp $(SOURCES) -o $(RUN)
	@echo "############" 
	@echo ""
	@./$(RUN)
	@echo ""
	@echo ""
	@echo "############" 

test:
	@make --no-print-directory
	@$(CC) $(CCFLAGS) $(TESTS) $(SOURCES) -o $(TEST)
	@echo "############" 
	@echo ""
	@./$(TEST)
	@echo ""
	@echo ""
	@echo "############" 

debug_test:
	@make --no-print-directory
	@$(CC) -Wall $(TEST_DIR)*.cpp \
		$(ALGOS_DIR)*.cpp \
		$(STRUCTS_DIR)*.cpp \
		-o $(TEST)
	@echo "############" 
	@echo ""
	@gdb ./$(TEST)
	@echo ""
	@echo ""
	@echo "############" 

debug_run:
	@make --no-print-directory
	@$(CC) -Wall \
		$(SRC_DIR)*.cpp \
		$(ALGOS_DIR)*.cpp \
		-o $(RUN)
	@echo "############" 
	@echo ""
	@gdb ./$(RUN)
	@echo ""
	@echo ""
	@echo "############" 

clean:
	sudo rm -r build/
	sudo rm -r compile_commands.json

.PHONY: all clean
