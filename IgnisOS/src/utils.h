#ifndef UTILS_H
#define UTILS_H

#include <stddef.h> // For size_t

// Function prototypes
void* safe_malloc(size_t size);
char* string_duplicate(const char* str);
void log_message(const char* message);
int string_equals(const char* str1, const char* str2);
char* int_to_string(int value);
void free_string(char* str);

#endif // UTILS_H
