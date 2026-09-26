# Macros
CC = gcc
CFLAGS = -Wall -I./include

# Directories
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj
LIB_DIR = lib

# Targets
STATIC_LIB = $(LIB_DIR)/libmyutils.a
DYNAMIC_LIB = $(LIB_DIR)/libmyutils.so
STATIC_TARGET = $(BIN_DIR)/client_static
DYNAMIC_TARGET = $(BIN_DIR)/client_dynamic

.PHONY: all static dynamic clean

all: static dynamic

static:
	@$(MAKE) -C $(SRC_DIR) static
	@echo "Static build complete."

dynamic:
	@$(MAKE) -C $(SRC_DIR) dynamic
	@echo "Dynamic build complete."

clean:
	@rm -f $(OBJ_DIR)/*.o $(STATIC_LIB) $(DYNAMIC_LIB)
	@rm -f $(BIN_DIR)/client_static $(BIN_DIR)/client_dynamic
	@echo "Cleaned."
