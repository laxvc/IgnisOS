#!/bin/bash
# Helper functions for IgnisOS
# This script contains utility functions used across various scripts.

# Function to print a message with a specific color
print_message() {
    local color="$1"
    shift
    local message="$@"
    
    case $color in
        "green") echo -e "\033[0;32m$message\033[0m" ;;  # Green
        "red")   echo -e "\033[0;31m$message\033[0m" ;;  # Red
        "yellow") echo -e "\033[0;33m$message\033[0m" ;;  # Yellow
        *) echo "$message" ;;  # Default to no color
    esac
}

# Function to check if a command exists
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Function to install a package if it's not already installed
install_package() {
    local package="$1"
    
    if command_exists "$package"; then
        print_message "green" "$package is already installed."
    else
        print_message "yellow" "Installing $package..."
        sudo apt-get install -y "$package"  # Adjust for your package manager
        if [ $? -eq 0 ]; then
            print_message "green" "$package installed successfully."
        else
            print_message "red" "Failed to install $package."
        fi
    fi
}

# Function to cleanup temporary files
cleanup_temp_files() {
    print_message "yellow" "Cleaning up temporary files..."
    rm -rf /tmp/ignisos_temp_*  # Adjust as necessary for your cleanup process
    print_message "green" "Cleanup completed."
}

# Export functions for use in other scripts
export -f print_message
export -f command_exists
export -f install_package
export -f cleanup_temp_files
