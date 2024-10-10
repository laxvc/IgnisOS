# IgnisOS Installation Guide

## Overview
This guide will walk you through the steps to install IgnisOS on your machine. Before you begin, ensure that your system meets the following requirements.

## System Requirements
- **Processor**: 64-bit processor (Intel or AMD)
- **RAM**: Minimum 2 GB (4 GB recommended)
- **Storage**: Minimum 10 GB of free disk space
- **Bootable USB Drive**: At least 4 GB

## Prerequisites
- A computer with a compatible BIOS/UEFI firmware.
- A working internet connection to download IgnisOS.
- A tool to create bootable USB drives (e.g., Rufus, Etcher).

## Installation Steps

### Step 1: Download IgnisOS
1. Visit the [IgnisOS GitHub Releases Page](https://github.com/laxvc/IgnisOS/releases).
2. Download the latest version of the IgnisOS ISO file.

### Step 2: Create a Bootable USB Drive
1. Insert your USB drive into the computer.
2. Open your USB creation tool (e.g., Rufus, Etcher).
3. Select the IgnisOS ISO file you downloaded.
4. Choose your USB drive from the device list.
5. Start the process to create a bootable USB drive.

### Step 3: Boot from the USB Drive
1. Restart your computer.
2. Access the BIOS/UEFI settings (usually by pressing F2, F12, ESC, or DEL during startup).
3. Set the boot order to prioritize the USB drive.
4. Save and exit the BIOS/UEFI settings.

### Step 4: Install IgnisOS
1. After booting from the USB drive, you will see the IgnisOS installer menu.
2. Select "Install IgnisOS" from the menu.
3. Follow the on-screen instructions to choose your language, time zone, and keyboard layout.
4. Select the installation type (e.g., erase disk and install IgnisOS or install alongside another OS).
5. Partition your disk if necessary (use the guided option for simplicity).
6. Proceed with the installation. This may take several minutes.
7. Once the installation is complete, remove the USB drive and reboot your computer.

### Step 5: First Boot
1. After rebooting, you should see the IgnisOS boot menu.
2. Select the IgnisOS option to boot into your new operating system.

## Post-Installation
- After installation, consider updating your system to ensure all packages are up to date:
  ```bash
  sudo apt update && sudo apt upgrade
