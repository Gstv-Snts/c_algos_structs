CC = gcc
RUN = build/main
TEST = build/test
SRC_DIR = src/
ALGOS_DIR = src/algos/
STRUCTS_DIR = src/structs/
BUILD_DIR = build/
TEST_DIR = tests/

@$(BUILD_DIR):
	@if [ ! -d $(BUILD_DIR) ]; then \
		echo "Creating $(BUILD_DIR)."; \
		mkdir -p build/; \
		echo "$(BUILD_DIR) created."; \
	fi 

run:
	@make --no-print-directory
	@$(CC) -Wall \
		$(SRC_DIR)*.c \
		$(ALGOS_DIR)*.c \
		-o $(RUN)
	@echo "############" 
	@echo ""
	@./$(RUN)
	@echo ""
	@echo ""
	@echo "############" 

test:
	@make --no-print-directory
	@$(CC) -Wall $(TEST_DIR)*.c \
		$(ALGOS_DIR)*.c \
		-o $(TEST)
	@echo "############" 
	@echo ""
	@./$(TEST)
	@echo ""
	@echo ""
	@echo "############" 

debug_test:
	@make --no-print-directory
	@$(CC) -Wall $(TEST_DIR)*.c \
		$(ALGOS_DIR)*.c \
		$(STRUCTS_DIR)*.c \
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
		$(SRC_DIR)*.c \
		$(ALGOS_DIR)*.c \
		-o $(RUN)
	@echo "############" 
	@echo ""
	@gdb ./$(RUN)
	@echo ""
	@echo ""
	@echo "############" 

clean:
	rm -r $(BUILD_DIR)

.PHONY: all clean
