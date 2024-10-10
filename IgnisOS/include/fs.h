#ifndef FS_H
#define FS_H

#include <stdint.h>

#define MAX_FILENAME_LENGTH 255
#define BLOCK_SIZE 4096 // Size of each block in bytes
#define MAX_FILES 1024  // Maximum number of files in the file system

// File types
typedef enum {
    FILE_TYPE_REGULAR,
    FILE_TYPE_DIRECTORY,
    FILE_TYPE_SYMLINK
} FileType;

// File control block structure
typedef struct {
    char name[MAX_FILENAME_LENGTH]; // Name of the file
    FileType type;                  // Type of the file
    uint32_t size;                  // Size of the file in bytes
    uint32_t blocks;                // Number of blocks allocated to the file
    uint32_t block_start;           // Starting block number
    uint32_t permissions;           // File permissions (read, write, execute)
    uint32_t created_at;            // Creation timestamp
    uint32_t modified_at;           // Last modified timestamp
} FileControlBlock;

// File system structure
typedef struct {
    FileControlBlock files[MAX_FILES]; // Array of file control blocks
    uint32_t total_files;                // Total number of files in the file system
} FileSystem;

// Function prototypes
void initialize_file_system(FileSystem *fs);
int create_file(FileSystem *fs, const char *filename, FileType type, uint32_t permissions);
int delete_file(FileSystem *fs, const char *filename);
int read_file(FileSystem *fs, const char *filename, uint8_t *buffer, uint32_t size);
int write_file(FileSystem *fs, const char *filename, const uint8_t *data, uint32_t size);
FileControlBlock* get_file_info(FileSystem *fs, const char *filename);

#endif // FS_H
