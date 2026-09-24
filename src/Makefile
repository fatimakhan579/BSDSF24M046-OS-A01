# Macros
CC = gcc
CFLAGS = -Wall -I../include
OBJ_DIR = ../obj
BIN_DIR = ../bin
LIB_DIR = ../lib

# Object files for library
LIB_OBJECTS = $(OBJ_DIR)/mystrfunctions.o $(OBJ_DIR)/myfilefunctions.o

# Object file for main
MAIN_OBJ = $(OBJ_DIR)/main.o

# Targets
LIBRARY = $(LIB_DIR)/libmyutils.a
TARGET = $(BIN_DIR)/client_static

.PHONY: static clean

# Build static library then link executable
static: $(TARGET)

# Link main.o against static library
$(TARGET): $(MAIN_OBJ) $(LIBRARY)
	@$(CC) $(MAIN_OBJ) -L$(LIB_DIR) -lmyutils -o $@
	@echo "Linked static executable: $@"

# Build static library from object files
$(LIBRARY): $(LIB_OBJECTS)
	@ar rcs $@ $^
	@echo "Created static library: $@"

# Compile rules
$(OBJ_DIR)/mystrfunctions.o: mystrfunctions.c ../include/mystrfunctions.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $@"

$(OBJ_DIR)/myfilefunctions.o: myfilefunctions.c ../include/myfilefunctions.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $@"

$(OBJ_DIR)/main.o: main.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $@"

.PHONY: clean
clean:
	@rm -f $(OBJ_DIR)/*.o $(TARGET) $(LIBRARY)
	@echo "Cleaned."
