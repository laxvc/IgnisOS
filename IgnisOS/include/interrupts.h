#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>

// Interrupt numbers
#define IRQ_TIMER       0
#define IRQ_KEYBOARD    1
#define IRQ_SERIAL      2
#define IRQ_DISK        3
#define IRQ_NETWORK     4

// Interrupt handler type
typedef void (*InterruptHandler)(void);

// Structure for interrupt descriptor table (IDT) entry
typedef struct {
    uint16_t offset_low;    // Lower 16 bits of the handler function address
    uint16_t selector;      // Kernel segment selector
    uint8_t zero;           // Unused, set to zero
    uint8_t type_attr;      // Type and attributes (interrupt gate)
    uint16_t offset_high;   // Higher 16 bits of the handler function address
} __attribute__((packed)) IDTEntry;

// Function prototypes
void initialize_interrupts(void);
void register_interrupt_handler(uint8_t interrupt_number, InterruptHandler handler);
void interrupt_handler(void); // Common interrupt handler
void enable_interrupts(void);
void disable_interrupts(void);

#endif // INTERRUPTS_H
