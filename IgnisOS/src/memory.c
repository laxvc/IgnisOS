#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

#define MEMORY_POOL_SIZE 1024 * 1024 // 1 MB memory pool

static char memory_pool[MEMORY_POOL_SIZE]; // Static memory pool
static size_t used_memory = 0;             // Track used memory

// Function to initialize memory management
void init_memory() {
    used_memory = 0;
    printf("Memory management initialized. Memory pool size: %d bytes\n", MEMORY_POOL_SIZE);
}

// Function to allocate memory
void* allocate_memory(size_t size) {
    if (used_memory + size > MEMORY_POOL_SIZE) {
        printf("Memory allocation failed: Not enough memory.\n");
        return NULL; // Not enough memory
    }
    
    void* ptr = &memory_pool[used_memory]; // Allocate memory from the pool
    used_memory += size;                   // Update used memory
    return ptr;                            // Return pointer to allocated memory
}

// Function to deallocate memory (in this simple example, it doesn't free memory)
void deallocate_memory(void* ptr) {
    // In a simple memory pool, we won't actually free memory
    // This function can be expanded to manage free blocks if needed
    printf("Deallocate memory at address: %p\n", ptr);
}

// Function to shutdown memory management
void shutdown_memory() {
    printf("Memory management shutdown.\n");
    // Add any necessary cleanup code for memory management here
}
