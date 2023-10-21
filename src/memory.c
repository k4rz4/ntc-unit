#include "memory.h"

#include <stdio.h>
#include <stdlib.h>

Memory *memory_alloc(size_t size) {
  Memory *memBlock = (Memory *)malloc(sizeof(Memory));
  if (!memBlock) {
    fprintf(stderr, "Failed to allocate memory for Memory struct.\n");
    return NULL;
  }

  memBlock->data = (char *)malloc(size);
  if (!memBlock->data) {
    fprintf(stderr, "Failed to allocate memory of size: %zu\n", size);
    free(memBlock);  // Important: Don't leak the previously allocated Memory
                     // structure.
    return NULL;
  }

  memBlock->size = size;
  return memBlock;
}

void memory_free(Memory *mem) {
  if (mem) {
    free(mem->data);  // Free the data block first
    free(mem);        // Then free the Memory structure itself
  }
}

void memory_write(Memory *mem, size_t address, char value) {
  if (mem == NULL) {
    fprintf(stderr,
            "Memory pointer is NULL. Cannot perform write operation.\n");
    return;
  }

  if (address < mem->size) {
    mem->data[address] = value;
  } else {
    fprintf(stderr, "Attempted to write to out-of-bounds memory address: %zu\n",
            address);
  }
}

#ifndef TEST_MEMORY_READ
char memory_read(Memory *mem, size_t address) {
  if (mem == NULL) {
    fprintf(stderr, "Memory pointer is NULL. Cannot perform read operation.\n");
    return -1;  // Error sentinel value
  }

  if (address < mem->size) {
    return mem->data[address];
  } else {
    fprintf(stderr,
            "Attempted to read from out-of-bounds memory address: %zu\n",
            address);
    return -1;  // Error sentinel value
  }
#endif
}
