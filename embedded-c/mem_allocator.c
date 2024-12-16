#include <stdlib.h>

typedef struct {
    void *base;
    size_t block_size;
    size_t num_blocks;
    size_t free_blocks;
    char *bitmap;
} MemoryAllocator;

MemoryAllocator *create_allocator(void *base, size_t block_size, size_t num_blocks) {
    MemoryAllocator *allocator = malloc(sizeof(MemoryAllocator));
    allocator->base = base;
    allocator->block_size = block_size;
    allocator->num_blocks = num_blocks;
    allocator->free_blocks = num_blocks;
    allocator->bitmap = calloc(num_blocks, sizeof(char));
    return allocator;
}

void *allocate_memory(MemoryAllocator *allocator) {
    for (size_t i = 0; i < allocator->num_blocks; i++) {
        if (allocator->bitmap[i] == 0) {
            allocator->bitmap[i] = 1;
            allocator->free_blocks--;
            return (char *)allocator->base + i * allocator->block_size;
        }
    }
    return NULL; // Out of memory
}

void free_memory(MemoryAllocator *allocator, void *ptr) {
    size_t index = (char *)ptr - (char *)allocator->base) / allocator->block_size;
    allocator->bitmap[index] = 0;
    allocator->free_blocks++;
}

void destroy_allocator(MemoryAllocator *allocator) {
    free(allocator->bitmap);
    free(allocator);
}