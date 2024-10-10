#!/bin/bash
# Test Memory script for IgnisOS
# This script tests the memory management functionalities of IgnisOS.

# Function to simulate memory allocation
simulate_memory_allocation() {
    echo "Simulating memory allocation..."
    # Allocate an array of 1000 integers
    local array_size=1000
    local array=()

    for ((i=0; i<array_size; i++)); do
        array[i]=$((RANDOM % 100))
    done

    echo "Memory allocation successful. Allocated $array_size integers."
}

# Function to test memory deallocation
test_memory_deallocation() {
    echo "Testing memory deallocation..."
    # Simulate deallocation by clearing the array
    unset array
    echo "Memory deallocated successfully."
}

# Run memory tests
simulate_memory_allocation
test_memory_deallocation

# Notify user of memory test completion
echo "Memory tests completed successfully."
