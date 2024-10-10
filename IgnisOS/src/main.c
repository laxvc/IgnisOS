#include <stdio.h>
#include "init.h"    // Include your initialization header
#include "io.h"      // Include I/O functions
#include "interrupts.h" // Include interrupt handling

// Main function: Entry point for the operating system
int main() {
    // Initialize the operating system components
    init_io();             // Initialize I/O subsystem
    init_interrupts();     // Initialize interrupt handling

    printf("Welcome to IgnisOS!\n");

    // Main loop of the operating system
    while (1) {
        // Placeholder for the main OS operations
        printf("IgnisOS is running...\n");

        // Add any additional processing or task management here

        // Simulate a basic delay for demonstration
        for (volatile long i = 0; i < 10000000; i++); // Simple delay
    }

    // Cleanup and shutdown (not reachable in this example)
    shutdown_io();         // Shut down I/O subsystem
    shutdown_interrupts(); // Shut down interrupt handling

    return 0;
}
