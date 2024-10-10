#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdint.h>

// System constants
#define SYSTEM_HEAP_SIZE  (1024 * 1024) // 1 MB heap size
#define MAX_INTERRUPTS    256            // Maximum number of interrupts

// Structure for an interrupt descriptor
typedef struct {
    uint32_t interrupt_number; // Interrupt number
    void (*handler)(void);      // Pointer to the interrupt handler function
} InterruptDescriptor;

// Function prototypes
void initialize_system(void);                     // Initialize the system
void register_interrupt(uint32_t interrupt_number, void (*handler)(void)); // Register an interrupt handler
void handle_interrupt(uint32_t interrupt_number); // Handle an interrupt
void system_shutdown(void);                        // Shutdown the system
void system_reboot(void);                          // Reboot the system

#endif // SYSTEM_H
