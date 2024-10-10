#include <stdio.h>
#include <stdlib.h>
#include "task.h"

#define MAX_TASKS 10 // Maximum number of tasks

// Structure to represent a task
typedef struct {
    int task_id;            // Task ID
    const char *name;       // Task name
    int is_running;         // Running status
    void (*task_function)(); // Pointer to the task function
} Task;

static Task task_table[MAX_TASKS]; // Task table
static int task_count = 0;          // Current task count

// Function to initialize task management
void init_task_management() {
    task_count = 0;
    for (int i = 0; i < MAX_TASKS; i++) {
        task_table[i].is_running = 0; // Mark all tasks as not running
    }
    printf("Task management initialized.\n");
}

// Function to create a new task
int create_task(const char *name, void (*task_function)()) {
    if (task_count >= MAX_TASKS) {
        printf("Task creation failed: Maximum task limit reached.\n");
        return -1; // Failure
    }

    int task_id = task_count; // Simple Task ID assignment
    task_table[task_id].task_id = task_id;
    task_table[task_id].name = name;
    task_table[task_id].is_running = 1;
    task_table[task_id].task_function = task_function;
    task_count++;

    printf("Task created: [ID: %d, Name: %s]\n", task_id, name);
    return task_id; // Return the new task ID
}

// Function to run a task
void run_task(int task_id) {
    if (task_id < 0 || task_id >= task_count || !task_table[task_id].is_running) {
        printf("Failed to run task: Invalid Task ID %d.\n", task_id);
        return; // Invalid task ID
    }

    printf("Running task: [ID: %d, Name: %s]\n", task_id, task_table[task_id].name);
    task_table[task_id].task_function(); // Call the task function
}

// Function to terminate a task
void terminate_task(int task_id) {
    if (task_id < 0 || task_id >= task_count || !task_table[task_id].is_running) {
        printf("Termination failed: Invalid Task ID %d.\n", task_id);
        return; // Invalid task ID
    }

    task_table[task_id].is_running = 0; // Mark task as not running
    printf("Task terminated: [ID: %d, Name: %s]\n", task_id, task_table[task_id].name);
}

// Function to list all tasks
void list_tasks() {
    printf("Current Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        if (task_table[i].is_running) {
            printf("[ID: %d, Name: %s]\n", task_table[i].task_id, task_table[i].name);
        }
    }
}

// Function to shutdown task management
void shutdown_task_management() {
    printf("Task management shutdown.\n");
    // Add any necessary cleanup code for task management here
}
