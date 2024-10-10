#include <stdio.h>
#include <stdlib.h>
#include "process.h"

#define MAX_PROCESSES 10 // Maximum number of processes

// Structure to represent a process
typedef struct {
    int pid;            // Process ID
    const char *name;   // Process name
    int is_running;     // Running status
} Process;

static Process process_table[MAX_PROCESSES]; // Process table
static int process_count = 0;                  // Current process count

// Function to initialize process management
void init_process_management() {
    process_count = 0;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        process_table[i].is_running = 0; // Mark all processes as not running
    }
    printf("Process management initialized.\n");
}

// Function to create a new process
int create_process(const char *name) {
    if (process_count >= MAX_PROCESSES) {
        printf("Process creation failed: Maximum process limit reached.\n");
        return -1; // Failure
    }
    
    int pid = process_count; // Simple PID assignment
    process_table[pid].pid = pid;
    process_table[pid].name = name;
    process_table[pid].is_running = 1;
    process_count++;
    
    printf("Process created: [PID: %d, Name: %s]\n", pid, name);
    return pid; // Return the new process ID
}

// Function to terminate a process
void terminate_process(int pid) {
    if (pid < 0 || pid >= process_count || !process_table[pid].is_running) {
        printf("Termination failed: Invalid PID %d.\n", pid);
        return; // Invalid process ID
    }
    
    process_table[pid].is_running = 0; // Mark process as not running
    printf("Process terminated: [PID: %d, Name: %s]\n", pid, process_table[pid].name);
}

// Function to list all processes
void list_processes() {
    printf("Current Processes:\n");
    for (int i = 0; i < process_count; i++) {
        if (process_table[i].is_running) {
            printf("[PID: %d, Name: %s]\n", process_table[i].pid, process_table[i].name);
        }
    }
}

// Function to shutdown process management
void shutdown_process_management() {
    printf("Process management shutdown.\n");
    // Add any necessary cleanup code for process management here
}
