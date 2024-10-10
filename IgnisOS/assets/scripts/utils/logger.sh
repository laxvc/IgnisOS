#!/bin/bash
# Logger script for IgnisOS
# This script provides logging functions for the IgnisOS project.

# Log file path
LOG_FILE="ignisos.log"

# Function to log messages with a timestamp
log_message() {
    local log_level="$1"
    shift
    local message="$@"
    
    # Get current timestamp
    local timestamp=$(date +"%Y-%m-%d %H:%M:%S")
    
    # Append log message to the log file
    echo "[$timestamp] [$log_level] $message" >> "$LOG_FILE"
    
    # Print the log message to the console (optional)
    case $log_level in
        "INFO") echo -e "\033[0;32m$message\033[0m" ;;  # Green for info
        "WARNING") echo -e "\033[0;33m$message\033[0m" ;;  # Yellow for warning
        "ERROR") echo -e "\033[0;31m$message\033[0m" ;;  # Red for error
        *) echo "$message" ;;  # Default
    esac
}

# Function to log info messages
log_info() {
    log_message "INFO" "$@"
}

# Function to log warning messages
log_warning() {
    log_message "WARNING" "$@"
}

# Function to log error messages
log_error() {
    log_message "ERROR" "$@"
}

# Function to display log file contents
display_logs() {
    echo "Contents of the log file ($LOG_FILE):"
    cat "$LOG_FILE"
}

# Export functions for use in other scripts
export -f log_info
export -f log_warning
export -f log_error
export -f display_logs
