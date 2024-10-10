#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

// Function to allocate memory and check for success
void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed for size: %zu\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Function to duplicate a string
char* string_duplicate(const char* str) {
    size_t len = strlen(str);
    char* new_str = (char*)safe_malloc(len + 1); // +1 for null terminator
    strcpy(new_str, str);
    return new_str;
}

// Function to log messages
void log_message(const char* message) {
    printf("[LOG] %s\n", message);
}

// Function to compare two strings for equality
int string_equals(const char* str1, const char* str2) {
    return strcmp(str1, str2) == 0;
}

// Function to convert an integer to a string
char* int_to_string(int value) {
    char* buffer = (char*)safe_malloc(12); // Enough space for int
    sprintf(buffer, "%d", value);
    return buffer;
}

// Function to clean up memory for a string
void free_string(char* str) {
    free(str);
}
