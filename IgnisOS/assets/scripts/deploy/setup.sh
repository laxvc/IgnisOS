#!/bin/bash
# Setup script for IgnisOS
# This script installs necessary dependencies and sets up the environment.

# Update package list
echo "Updating package list..."
sudo apt update

# Install required packages (modify as needed)
echo "Installing required packages..."
sudo apt install -y build-essential gcc gdb make

# Create necessary directories if they don't exist
echo "Creating necessary directories..."
mkdir -p bin obj src include lib

# Notify user of successful setup
echo "Setup completed successfully. Your development environment is ready."
