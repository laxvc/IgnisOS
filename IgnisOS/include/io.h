#ifndef IO_H
#define IO_H

#include <stdint.h>

// I/O port macros
#define PORT_KEYBOARD 0x60
#define PORT_DISK     0x1F0
#define PORT_SERIAL   0x3F8

// Function prototypes for I/O operations
void outb(uint16_t port, uint8_t value);  // Write a byte to an I/O port
uint8_t inb(uint16_t port);                // Read a byte from an I/O port

void outw(uint16_t port, uint16_t value);  // Write a word to an I/O port
uint16_t inw(uint16_t port);                // Read a word from an I/O port

void outl(uint16_t port, uint32_t value);  // Write a double word to an I/O port
uint32_t inl(uint16_t port);                // Read a double word from an I/O port

// Function prototypes for keyboard I/O
void keyboard_init(void);                    // Initialize keyboard
void keyboard_handler(void);                 // Handle keyboard input

// Function prototypes for disk I/O
void disk_init(void);                        // Initialize disk
void disk_read(uint32_t sector, void* buffer); // Read from disk
void disk_write(uint32_t sector, const void* buffer); // Write to disk

// Function prototypes for serial I/O
void serial_init(void);                      // Initialize serial port
void serial_write(const char* str);          // Write a string to the serial port

#endif // IO_H
