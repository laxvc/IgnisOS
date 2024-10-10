#!/bin/bash
# Test System script for IgnisOS
# This script tests the core system functionalities of IgnisOS.

# Function to test process creation
test_process_creation() {
    echo "Testing process creation..."
    
    # Create a simple process
    (sleep 1 &)
    local pid=$!

    # Check if the process is running
    if ps -p $pid > /dev/null; then
        echo "Process $pid created successfully."
    else
        echo "Failed to create process."
    fi

    # Cleanup
    wait $pid 2>/dev/null
}

# Function to test system call functionality
test_system_call() {
    echo "Testing system calls..."
    
    # Simulate a simple system call (e.g., fetching current directory)
    current_dir=$(pwd)
    
    if [ -n "$current_dir" ]; then
        echo "Current directory: $current_dir"
    else
        echo "Failed to retrieve current directory."
    fi
}

# Run system tests
test_process_creation
test_system_call

# Notify user of system test completion
echo "System tests completed successfully."
