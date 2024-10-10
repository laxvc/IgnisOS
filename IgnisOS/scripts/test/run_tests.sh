#!/bin/bash
# Run Tests script for IgnisOS
# This script executes the test scripts for IgnisOS.

# Define test directories
TEST_DIR="tests"
TEST_MEMORY="test_memory.sh"
TEST_SYSTEM="test_system.sh"

# Function to run a test
run_test() {
    local test_script=$1
    if [ -f "$TEST_DIR/$test_script" ]; then
        echo "Running $test_script..."
        bash "$TEST_DIR/$test_script"
        if [ $? -eq 0 ]; then
            echo "$test_script completed successfully."
        else
            echo "$test_script failed."
        fi
    else
        echo "$test_script not found in $TEST_DIR."
    fi
}

# Run the memory test
run_test "$TEST_MEMORY"

# Run the system test
run_test "$TEST_SYSTEM"

# Notify user of test completion
echo "All tests completed."
