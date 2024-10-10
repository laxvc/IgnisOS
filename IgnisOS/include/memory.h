#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

// Memory management constants
#define MEMORY_POOL_SIZE  (1024 * 1024) // 1 MB memory pool
#define PAGE_SIZE         4096            // 4 KB page size
#define MAX_PAGES         (MEMORY_POOL_SIZE / PAGE_SIZE) // Max pages in the pool

// Structure for a memory page
typedef struct {
    uint32_t address;   // Starting address of the page
    uint32_t is_free;   // Flag indicating if the page is free (1) or allocated (0)
} MemoryPage;

// Structure for the memory pool
typedef struct {
    MemoryPage pages[MAX_PAGES]; // Array of memory pages
    uint32_t free_page_count;     // Count of free pages
} MemoryPool;

// Function prototypes
void initialize_memory(void);                     // Initialize memory management
void* allocate_memory(uint32_t size);             // Allocate memory of a given size
void deallocate_memory(void* ptr);                 // Deallocate previously allocated memory
void* request_page(void);                          // Request a memory page
void release_page(void* ptr);                      // Release a memory page

#endif // MEMORY_H
