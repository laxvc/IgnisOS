#ifndef PROCESS_H
#define PROCESS_H

#include <stdint.h>

// Process states
typedef enum {
    PROCESS_NEW,
    PROCESS_READY,
    PROCESS_RUNNING,
    PROCESS_WAITING,
    PROCESS_TERMINATED
} ProcessState;

// Structure for process control block (PCB)
typedef struct {
    uint32_t pid;                // Process ID
    ProcessState state;         // Current state of the process
    uint32_t priority;          // Process priority
    uint32_t *stack_pointer;    // Pointer to the process stack
    uint32_t *base_pointer;     // Pointer to the base of the process stack
    uint32_t program_counter;   // Program counter for the process
    uint32_t total_time;        // Total time the process has been running
    uint32_t remaining_time;    // Remaining time for the process
} ProcessControlBlock;

// Function prototypes
void create_process(uint32_t priority, void (*entry_point)(void)); // Create a new process
void schedule_processes(void);                                     // Schedule processes based on priority
void switch_context(ProcessControlBlock *old, ProcessControlBlock *new); // Switch context between processes
void terminate_process(uint32_t pid);                             // Terminate a process by its PID
ProcessControlBlock* get_process_by_pid(uint32_t pid);          // Get a process by its PID

#endif // PROCESS_H
