#ifndef TASK_H
#define TASK_H

#include <stdint.h>

// Task states
typedef enum {
    TASK_READY,
    TASK_RUNNING,
    TASK_WAITING,
    TASK_TERMINATED
} TaskState;

// Structure for a task control block (TCB)
typedef struct {
    uint32_t tid;                  // Task ID
    TaskState state;               // Current state of the task
    uint32_t priority;             // Task priority
    uint32_t *stack_pointer;       // Pointer to the task stack
    uint32_t *base_pointer;        // Pointer to the base of the task stack
    uint32_t program_counter;      // Program counter for the task
    uint32_t total_time;           // Total time the task has been running
    uint32_t remaining_time;       // Remaining time for the task
    void (*entry_point)(void);     // Entry point of the task
} TaskControlBlock;

// Function prototypes
void create_task(uint32_t priority, void (*entry_point)(void)); // Create a new task
void schedule_tasks(void);                                       // Schedule tasks based on priority
void switch_task_context(TaskControlBlock *old, TaskControlBlock *new); // Switch context between tasks
void terminate_task(uint32_t tid);                              // Terminate a task by its TID
TaskControlBlock* get_task_by_tid(uint32_t tid);              // Get a task by its TID

#endif // TASK_H
