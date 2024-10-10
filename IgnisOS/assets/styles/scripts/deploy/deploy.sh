#!/bin/bash
# Deploy script for IgnisOS
# This script sets up the IgnisOS environment for deployment.

# Define variables
SRC_DIR="src"
BIN_DIR="bin"
DEPLOY_DIR="deploy"  # Change this to your desired deployment directory
BACKUP_DIR="backup"

# Create backup of existing deployment (if exists)
if [ -d "$DEPLOY_DIR" ]; then
    echo "Backing up existing deployment to $BACKUP_DIR"
    mkdir -p "$BACKUP_DIR"
    cp -r "$DEPLOY_DIR/"* "$BACKUP_DIR/"
fi

# Create the deployment directory if it doesn't exist
mkdir -p "$DEPLOY_DIR"

# Copy binaries and configuration files to the deployment directory
echo "Deploying IgnisOS files to $DEPLOY_DIR"
cp "$BIN_DIR/ignisos" "$DEPLOY_DIR/"
cp -r "config/" "$DEPLOY_DIR/"

# Notify user of successful deployment
echo "Deployment completed successfully. IgnisOS is ready in $DEPLOY_DIR."
