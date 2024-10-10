#include <stdio.h>
#include "system.h"  // Ensure you have the system management header

void test_system_initialization() {
    printf("Testing System Initialization...\n");

    // Call the system initialization function
    if (initialize_system() == 0) {
        printf("System initialized successfully.\n");
    } else {
        printf("System initialization failed!\n");
    }
}

void test_system_calls() {
    printf("Testing System Calls...\n");

    // Assume you have a function that performs a basic system call
    int result = system_call_example();  // Replace with your actual function
    if (result >= 0) {
        printf("System call executed successfully, returned: %d\n", result);
    } else {
        printf("System call failed!\n");
    }
}

int main() {
    test_system_initialization();
    test_system_calls();
    return 0;
}
