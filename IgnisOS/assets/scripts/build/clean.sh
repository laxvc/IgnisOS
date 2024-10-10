#!/bin/bash
# Clean script for IgnisOS
# This script removes compiled object files and the executable.

# Define directories
BIN_DIR="bin"
OBJ_DIR="obj"

# Remove object files
if [ -d "$OBJ_DIR" ]; then
    echo "Removing object files from $OBJ_DIR"
    rm -rf "$OBJ_DIR"/*
else
    echo "No object files to clean in $OBJ_DIR"
fi

# Remove the executable
if [ -f "$BIN_DIR/ignisos" ]; then
    echo "Removing executable from $BIN_DIR"
    rm -f "$BIN_DIR/ignisos"
else
    echo "No executable found to clean in $BIN_DIR"
fi

# Notify user of successful clean
echo "Clean completed successfully."
