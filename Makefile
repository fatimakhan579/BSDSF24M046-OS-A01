# Macros
CC = gcc
CFLAGS = -Wall -I./include

# Directories
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj

# Phony targets (not real files)
.PHONY: all clean

# Default target - goes into src/ and runs its Makefile
all:
	@$(MAKE) -C $(SRC_DIR)
	@echo "Build complete."

clean:
	@rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/client
	@echo "Cleaned."
