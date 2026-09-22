# Macros
CC = gcc
CFLAGS = -Wall -I../include
OBJ_DIR = ../obj
BIN_DIR = ../bin

# All object files needed
OBJECTS = $(OBJ_DIR)/mystrfunctions.o $(OBJ_DIR)/myfilefunctions.o $(OBJ_DIR)/main.o

# Final executable
TARGET = $(BIN_DIR)/client

# Link all objects into executable
# $^ means all dependencies, $@ means the target
$(TARGET): $(OBJECTS)
	@$(CC) $^ -o $@
	@echo "Linked: $@"

# Compile each .c into .o
# $< means first dependency (the .c file), $@ means the .o output
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
	@rm -f $(OBJ_DIR)/*.o $(TARGET)
	@echo "Cleaned src."
