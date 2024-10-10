#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

// System constants
#define KERNEL_STACK_SIZE  1024 * 1024 // 1 MB kernel stack size
#define MAX_PROCESSES      256           // Maximum number of processes
#define MAX_OPEN_FILES     1024          // Maximum number of open files
#define MAX_DEVICES        32            // Maximum number of devices

// Process states
typedef enum {
    PROCESS_READY,
    PROCESS_RUNNING,
    PROCESS_BLOCKED,
    PROCESS_TERMINATED
} ProcessState;

// Structure for process control block (PCB)
typedef struct {
    uint32_t pid;                  // Process ID
    ProcessState state;           // Current state of the process
    uint32_t priority;            // Process priority
    uint32_t *stack;              // Pointer to the process stack
    uint32_t *entry_point;        // Entry point of the process
} ProcessControlBlock;

// Function prototypes
void kernel_main(void);                     // Main function for the kernel
void process_scheduler(void);               // Scheduler function to manage processes
void initialize_system(void);               // System initialization function
void handle_interrupts(void);               // Interrupt handling function
void panic(const char *message);            // Panic function for error handling

#endif // MAIN_H
