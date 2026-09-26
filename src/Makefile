# Macros
CC = gcc
CFLAGS = -Wall -I../include
OBJ_DIR = ../obj
BIN_DIR = ../bin
LIB_DIR = ../lib

# Object files
LIB_OBJECTS = $(OBJ_DIR)/mystrfunctions.o $(OBJ_DIR)/myfilefunctions.o
MAIN_OBJ = $(OBJ_DIR)/main.o

# Targets
STATIC_LIB = $(LIB_DIR)/libmyutils.a
DYNAMIC_LIB = $(LIB_DIR)/libmyutils.so
STATIC_TARGET = $(BIN_DIR)/client_static
DYNAMIC_TARGET = $(BIN_DIR)/client_dynamic

.PHONY: static dynamic clean

# Static build
static: $(STATIC_TARGET)

$(STATIC_TARGET): $(MAIN_OBJ) $(STATIC_LIB)
	@$(CC) $(MAIN_OBJ) -L$(LIB_DIR) -lmyutils -o $@
	@echo "Linked static executable: $@"

$(STATIC_LIB): $(LIB_OBJECTS)
	@ar rcs $@ $^
	@echo "Created static library: $@"

# Dynamic build
dynamic: $(DYNAMIC_TARGET)

$(DYNAMIC_TARGET): $(MAIN_OBJ) $(DYNAMIC_LIB)
	@$(CC) $(MAIN_OBJ) -L$(LIB_DIR) -lmyutils -o $@
	@echo "Linked dynamic executable: $@"

$(DYNAMIC_LIB): $(LIB_OBJECTS)
	@$(CC) --shared -o $@ $^
	@echo "Created dynamic library: $@"

# Compile rules - fPIC needed for dynamic library
$(OBJ_DIR)/mystrfunctions.o: mystrfunctions.c ../include/mystrfunctions.h
	@$(CC) $(CFLAGS) -fPIC -c $< -o $@
	@echo "Compiled: $@"

$(OBJ_DIR)/myfilefunctions.o: myfilefunctions.c ../include/myfilefunctions.h
	@$(CC) $(CFLAGS) -fPIC -c $< -o $@
	@echo "Compiled: $@"

$(OBJ_DIR)/main.o: main.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $@"

.PHONY: clean
clean:
	@rm -f $(OBJ_DIR)/*.o $(STATIC_TARGET) $(DYNAMIC_TARGET)
	@rm -f $(STATIC_LIB) $(DYNAMIC_LIB)
	@echo "Cleaned."
