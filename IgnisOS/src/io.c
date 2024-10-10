#include <stdio.h>
#include <stdlib.h>
#include "io.h"

// Function to initialize I/O operations
void init_io() {
    printf("Initializing I/O subsystem...\n");
    // Add any necessary setup code for the I/O subsystem here
}

// Function to write a character to the console
void write_char(char c) {
    putchar(c);
}

// Function to write a string to the console
void write_string(const char *str) {
    printf("%s", str);
}

// Function to read a character from the console
char read_char() {
    char c = getchar();
    return c;
}

// Function to read a string from the console
void read_string(char *buffer, size_t size) {
    fgets(buffer, size, stdin);
}

// Function to shut down I/O operations
void shutdown_io() {
    printf("Shutting down I/O subsystem...\n");
    // Add any necessary cleanup code for the I/O subsystem here
}
