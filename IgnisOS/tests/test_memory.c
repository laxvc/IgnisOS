#include <stdio.h>
#include <stdlib.h>

void test_memory_allocation() {
    int *array;
    size_t size = 10;

    // Allocate memory for an array of integers
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Initialize and print the array
    for (size_t i = 0; i < size; i++) {
        array[i] = i * 10;  // Assign values
        printf("array[%zu] = %d\n", i, array[i]);
    }

    // Free the allocated memory
    free(array);
    printf("Memory successfully freed.\
