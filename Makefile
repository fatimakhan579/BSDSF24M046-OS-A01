# Macros
CC = gcc
CFLAGS = -Wall -I./include

# Directories
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj
LIB_DIR = lib
MAN_DIR = man/man3

# Install paths
INSTALL_BIN = /usr/local/bin
INSTALL_MAN = /usr/local/share/man/man3

# Targets
STATIC_LIB = $(LIB_DIR)/libmyutils.a
DYNAMIC_LIB = $(LIB_DIR)/libmyutils.so
STATIC_TARGET = $(BIN_DIR)/client_static
DYNAMIC_TARGET = $(BIN_DIR)/client_dynamic

.PHONY: all static dynamic clean install uninstall

all: static dynamic

static:
	@$(MAKE) -C $(SRC_DIR) static
	@echo "Static build complete."

dynamic:
	@$(MAKE) -C $(SRC_DIR) dynamic
	@echo "Dynamic build complete."

install: all
	@echo "Installing executable..."
	@cp $(DYNAMIC_TARGET) $(INSTALL_BIN)/client
	@chmod 755 $(INSTALL_BIN)/client
	@echo "Installing man pages..."
	@cp $(MAN_DIR)/*.3 $(INSTALL_MAN)/
	@mandb
	@echo "Installation complete."

uninstall:
	@rm -f $(INSTALL_BIN)/client
	@rm -f $(INSTALL_MAN)/mystrlen.3
	@rm -f $(INSTALL_MAN)/mystrcpy.3
	@rm -f $(INSTALL_MAN)/mystrncpy.3
	@rm -f $(INSTALL_MAN)/mystrcat.3
	@rm -f $(INSTALL_MAN)/wordCount.3
	@rm -f $(INSTALL_MAN)/mygrep.3
	@echo "Uninstall complete."

clean:
	@rm -f $(OBJ_DIR)/*.o $(STATIC_LIB) $(DYNAMIC_LIB)
	@rm -f $(BIN_DIR)/client_static $(BIN_DIR)/client_dynamic
	@echo "Cleaned."
