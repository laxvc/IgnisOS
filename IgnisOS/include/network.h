#ifndef NETWORK_H
#define NETWORK_H

#include <stdint.h>

// Networking constants
#define MAX_CONNECTIONS   1024          // Maximum number of concurrent connections
#define BUFFER_SIZE       4096          // Buffer size for network packets

// Enumeration for protocol types
typedef enum {
    PROTOCOL_TCP,
    PROTOCOL_UDP,
    PROTOCOL_ICMP
} ProtocolType;

// Structure for a network address
typedef struct {
    uint32_t ip;           // IPv4 address
    uint16_t port;         // Port number
} NetworkAddress;

// Structure for a network packet
typedef struct {
    ProtocolType protocol; // Protocol type (TCP, UDP, ICMP)
    NetworkAddress src;    // Source address
    NetworkAddress dest;   // Destination address
    uint8_t data[BUFFER_SIZE]; // Packet data
    uint32_t length;       // Length of the packet data
} NetworkPacket;

// Function prototypes
void initialize_network(void);                       // Initialize network stack
void send_packet(NetworkPacket *packet);             // Send a network packet
void receive_packet(NetworkPacket *packet);          // Receive a network packet
void handle_network_interrupt(void);                 // Handle network interrupts
void set_ip_address(uint32_t ip);                    // Set the system's IP address
uint32_t get_ip_address(void);                        // Get the system's IP address

#endif // NETWORK_H
