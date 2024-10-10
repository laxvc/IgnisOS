#!/bin/bash
# Build script for IgnisOS
# This script compiles the IgnisOS project and creates an executable.

# Define variables
SRC_DIR="src"
BIN_DIR="bin"
OBJ_DIR="obj"
CC="gcc"  # Change this if using a different compiler
CFLAGS="-Wall -g"  # Compiler flags

# Create bin and obj directories if they don't exist
mkdir -p "$BIN_DIR" "$OBJ_DIR"

# Compile source files to object files
for src_file in "$SRC_DIR"/*.c; do
    filename=$(basename "$src_file" .c)  # Get filename without extension
    echo "Compiling $src_file to $OBJ_DIR/$filename.o"
    $CC $CFLAGS -c "$src_file" -o "$OBJ_DIR/$filename.o"
done

# Link object files to create the executable
echo "Linking object files to create the IgnisOS executable"
$CC $CFLAGS "$OBJ_DIR"/*.o -o "$BIN_DIR/ignisos"

# Notify user of successful build
echo "Build completed successfully. Executable created at $BIN_DIR/ignisos"
