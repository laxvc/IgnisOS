#ifndef DEVICE_H
#define DEVICE_H

#include <stdint.h>

// Device types
#define DEVICE_TYPE_STORAGE   0x01
#define DEVICE_TYPE_NETWORK   0x02
#define DEVICE_TYPE_INPUT     0x03
#define DEVICE_TYPE_OUTPUT    0x04

// Device status
#define DEVICE_STATUS_OK      0x00
#define DEVICE_STATUS_ERROR   0x01

// Structure for device information
typedef struct {
    uint32_t id;                // Unique identifier for the device
    char name[256];             // Device name
    uint8_t type;               // Device type (e.g., storage, network)
    uint8_t status;             // Device status
    uint64_t capacity;          // Device capacity in bytes (if applicable)
} Device;

// Function prototypes
void initialize_device(Device *device);
void read_device(Device *device, uint8_t *buffer, uint32_t size);
void write_device(Device *device, const uint8_t *buffer, uint32_t size);
void reset_device(Device *device);
uint8_t get_device_status(Device *device);

#endif // DEVICE_H
