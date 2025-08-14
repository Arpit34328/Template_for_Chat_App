# File Name:
# Author Name:
# Created:

# Compiler
CC =            # TODO: Set compiler name
CFLAGS =        # TODO: Add warning/debug/include directory flags

# Directories
SRC_DIR   =     # TODO: Source folder name
BUILD_DIR =     # TODO: Build folder name
BIN_DIR   =     # TODO: Binary folder name

# Output executable
TARGET    = $(BIN_DIR)/     # TODO: Name of final executable

# Source files
# Finds all C source files in the source directory
SRC_FILES := 
# Selects only the main source file from the list
MAIN_SRC  := 
# Lists all source files except the main source file
LIB_SRC   := 

# Object files
# Converts the main source file into its corresponding object file path
MAIN_OBJ  := 
# Converts all other source files into their corresponding object file paths
LIB_OBJ   := 

# Default target
all: $(TARGET)

# Linking step
$(TARGET): $(MAIN_OBJ) $(LIB_OBJ)
	# TODO: Create the bin dir
	# TODO: Link all object files into final executable

# Compilation step
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	# TODO: Create the build dir
	# TODO: Compile .c file into .o file

# Run the program
run: $(TARGET)
	# TODO: Add command to execute the program

# Clean build files
clean:
	# TODO: Remove build and bin directories

# Rebuild
rebuild: clean all

.PHONY: all clean rebuild run

