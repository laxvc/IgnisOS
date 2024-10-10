#!/bin/bash

# Build script for IgnisOS

# Set the directories
SRC_DIR="src"
OBJ_DIR="obj"
BIN_DIR="bin"

# Create object and binary directories if they don't exist
mkdir -p $OBJ_DIR
mkdir -p $BIN_DIR

# Compile each source file into an object file
for src_file in $SRC_DIR/*.c; do
    # Get the filename without the directory
    filename=$(basename "$src_file" .c)
    gcc -c "$src_file" -o "$OBJ_DIR/$filename.o" -Iinclude -Wall -Wextra -g
done

# Link the object files to create the final executable
gcc $OBJ_DIR/*.o -o "$BIN_DIR/ignisos"

echo "Build complete. Executable is located in the $BIN_DIR directory."
