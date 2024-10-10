#include <stdio.h>
#include "process.h"  // Ensure you have the process management header

void test_process_creation() {
    printf("Testing Process Creation...\n");

    // Assume create_process is a function defined in process.h
    int process_id = create_process("TestProcess");
    if (process_id < 0) {
        printf("Process creation failed!\n");
        return;
    }

    printf("Process created successfully with ID: %d\n", process_id);
    
    // Additional checks and process handling can go here

    printf("Process creation test completed successfully.\n");
}

int main() {
    test_process_creation();
    return 0;
}
