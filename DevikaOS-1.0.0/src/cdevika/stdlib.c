
#include "include/types.h"
#include "include/stdlib.h"
 
#define HEAP_SIZE 1024 // Define the size of the heap

// Structure to represent memory blocks
typedef struct block {
    uint16 size;            // Size of the memory block
    struct block *next;     // Pointer to the next block in the linked list
    int free;               // Flag indicating whether the block is free (1) or not (0)
} block;

// max memory size is 1000
static char memory[MAX_MEMORY_SIZE]; // Static array to simulate memory
static int next_free_index = 0; // Index to keep track of the next available memory location

static char heap[HEAP_SIZE]; // The heap memory

// Define the initial block at the start of the heap
static block *freeList = (block*)heap;

// Initialize the heap
void init_heap() {
    freeList->size = HEAP_SIZE - sizeof(block); // Set size of the initial block
    freeList->next = NULL;
    freeList->free = 1;
}

// Function to allocate memory
void *malloc(uint32 size) {
    block *curr, *prev;
    void *result;

    // If size is 0, return NULL
    if (size == 0) return NULL;

    // If freeList is not initialized, initialize it
    if (!freeList) {
        init_heap();
    }

    // Search for a free block of appropriate size
    curr = freeList;
    while (curr) {
        if (curr->free && curr->size >= size) {
            // If a free block of appropriate size is found, allocate memory from it
            curr->free = 0;
            result = (void*)(curr + 1);
            return result;
        }
        prev = curr;
        curr = curr->next;
    }

    // If no free block is found, return NULL
    return NULL;
}

void *memoryAllocate(int noOfBytes) {
    if (next_free_index + noOfBytes > MAX_MEMORY_SIZE) {
        // Memory allocation failed, return NULL
        return 0; // null
    }

    void *ptr = &memory[next_free_index]; // Pointer to the next available memory location
    next_free_index += noOfBytes; // Update the next available index
    return ptr;
}

// Function to deallocate memory
void free(void *ptr) {
    // Calculate the starting address of the block
    block *blk = (block*)ptr - 1;

    // Set the free flag to 1 since this block is now free
    blk->free = 1;
}