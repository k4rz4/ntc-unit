CC = gcc
CFLAGS = -Wall -Wextra -pedantic
SRC_DIR = src
TEST_DIR = tests
OBJ_DIR = obj
BIN_DIR = bin

# Define source files and their corresponding object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# For tests, we remove the real implementation of the functions we're faking
TEST_OBJ_FILES = $(filter-out $(OBJ_DIR)/memory.o $(OBJ_DIR)/io.o,$(OBJ_FILES))

# Compile the application
all: $(BIN_DIR)/application

$(BIN_DIR)/application: $(OBJ_FILES) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Compile and run tests
test: $(OBJ_DIR)/tests
	./$^

$(OBJ_DIR)/tests: $(OBJ_FILES) $(wildcard $(TEST_DIR)/*.c)
	$(CC) $(CFLAGS) -I$(SRC_DIR) $^ -lcriterion -o $@

# Rule to compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create necessary directories
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)
