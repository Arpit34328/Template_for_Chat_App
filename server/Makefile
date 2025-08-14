# File Name:
# Author Name:
# Created:

# Compiler and Archiver
CC =            # TODO: Set compiler name (e.g., gcc)
AR =            # TODO: Set archiver command (e.g., ar)
CFLAGS =        # TODO: Add warning/debug/include directory flags

# Directories
SRC_DIR   =     # TODO: Source folder name
BUILD_DIR =     # TODO: Build folder name
BIN_DIR   =     # TODO: Binary folder name
LIB_DIR   =     # TODO: Library folder name

# Output executable and library
TARGET     = $(BIN_DIR)/     # TODO: Name of final executable
LIB_NAME   =                 # TODO: Name of static library file (e.g., libserver.a)
LIB_TARGET = $(LIB_DIR)/$(LIB_NAME)

# Source files
# Finds all C source files in the source directory
SRC_FILES :=   # TODO: Use find to match all .c files in SRC_DIR
# Selects only the main source file from the list
MAIN_SRC  :=   # TODO: Filter to get only main.c
# Lists all source files except the main source file
LIB_SRC   :=   # TODO: Filter-out the main.c from SRC_FILES

# Object files
# Converts the main source file into its corresponding object file path
MAIN_OBJ  :=   # TODO: Convert main.c path to build/main.o path
# Converts all other source files into their corresponding object file paths
LIB_OBJ   :=   # TODO: Convert other .c file paths to .o file paths in build dir

# Default target
all: $(TARGET)

# Link main with static library
$(TARGET): $(MAIN_OBJ) $(LIB_TARGET)
	# TODO: Create the bin dir
	# TODO: Link main object with static library

# Build static library
$(LIB_TARGET): $(LIB_OBJ)
	# TODO: Create the lib dir
	# TODO: Archive object files into static library

# Compile all .c to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	# TODO: Create necessary build subdirectories
	# TODO: Compile .c file into .o file

# Run the program
run: $(TARGET)
	# TODO: Add command to execute the program

# Clean build and output files
clean:
	# TODO: Remove build, bin, and lib directories

# Rebuild
rebuild: clean all

.PHONY: all clean rebuild run

