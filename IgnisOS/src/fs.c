#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fs.h"

// Structure to represent a file in the file system
typedef struct {
    char name[256];          // File name
    size_t size;            // File size in bytes
    char *data;             // Pointer to file data
} File;

// Array to hold files in the file system
File *file_system[100];    // Simple file system with a max of 100 files
int file_count = 0;        // Current number of files

// Function to create a new file
int create_file(const char *name) {
    if (file_count >= 100) {
        printf("Error: Maximum file limit reached.\n");
        return -1; // Error
    }

    File *new_file = (File *)malloc(sizeof(File));
    if (!new_file) {
        printf("Error: Memory allocation failed.\n");
        return -1; // Error
    }

    strncpy(new_file->name, name, sizeof(new_file->name));
    new_file->size = 0;
    new_file->data = NULL;
    file_system[file_count++] = new_file;
    printf("File '%s' created successfully.\n", name);
    return 0; // Success
}

// Function to write data to a file
int write_file(const char *name, const char *data, size_t size) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_system[i]->name, name) == 0) {
            file_system[i]->data = (char *)realloc(file_system[i]->data, size);
            if (!file_system[i]->data) {
                printf("Error: Memory allocation failed.\n");
                return -1; // Error
            }
            memcpy(file_system[i]->data, data, size);
            file_system[i]->size = size;
            printf("Data written to file '%s' successfully.\n", name);
            return 0; // Success
        }
    }
    printf("Error: File '%s' not found.\n", name);
    return -1; // Error
}

// Function to read data from a file
int read_file(const char *name) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_system[i]->name, name) == 0) {
            printf("Contents of file '%s':\n%s\n", name, file_system[i]->data);
            return 0; // Success
        }
    }
    printf("Error: File '%s' not found.\n", name);
    return -1; // Error
}

// Function to delete a file
int delete_file(const char *name) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_system[i]->name, name) == 0) {
            free(file_system[i]->data);
            free(file_system[i]);

            // Shift files in the array
            for (int j = i; j < file_count - 1; j++) {
                file_system[j] = file_system[j + 1];
            }
            file_count--;
            printf("File '%s' deleted successfully.\n", name);
            return 0; // Success
        }
    }
    printf("Error: File '%s' not found.\n", name);
    return -1; // Error
}

// Function to shut down the file system
void shutdown_file_system() {
    for (int i = 0; i < file_count; i++) {
        free(file_system[i]->data);
        free(file_system[i]);
    }
    file_count = 0; // Reset the file count
    printf("File system shut down successfully.\n");
}
