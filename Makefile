# Macros
CC = gcc
CFLAGS = -Wall -I./include
LDFLAGS = -L./lib -lmyutils

# Directories
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj
LIB_DIR = lib

# Library and executable
LIBRARY = $(LIB_DIR)/libmyutils.a
TARGET = $(BIN_DIR)/client_static

.PHONY: all clean

all:
	@$(MAKE) -C $(SRC_DIR) static
	@echo "Static build complete."

clean:
	@rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/client_static $(LIB_DIR)/libmyutils.a
	@echo "Cleaned."
