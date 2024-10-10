#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

// Utility macros
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

// Function prototypes
void delay(uint32_t milliseconds);          // Delay for a specified number of milliseconds
uint32_t random(uint32_t min, uint32_t max); // Generate a random number between min and max
void reverse_string(char *str);              // Reverse a string in place
void copy_memory(void *dest, const void *src, uint32_t n); // Copy memory from src to dest
void set_memory(void *ptr, uint8_t value, uint32_t n); // Set memory to a specific value

#endif // UTILS_H
