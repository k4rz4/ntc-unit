#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>

typedef struct {
  char *data;   // Pointer to the block of memory
  size_t size;  // Size of the memory block
} Memory;

/**
 * Allocates a block of memory of the given size.
 *
 * @param size The size of the memory block to allocate.
 * @return A pointer to the allocated memory block, or NULL on failure.
 */
Memory *memory_alloc(size_t size);

/**
 * Frees a previously allocated block of memory.
 *
 * @param mem Pointer to the memory structure to be freed.
 */
void memory_free(Memory *mem);

/**
 * Writes a value to a specified address in memory.
 *
 * @param mem Pointer to the memory structure.
 * @param address The address within the memory block to write to.
 * @param value The value to write.
 */
void memory_write(Memory *mem, size_t address, char value);

/**
 * Reads a value from a specified address in memory.
 *
 * @param mem Pointer to the memory structure.
 * @param address The address within the memory block to read from.
 * @return The value read from the specified address, or -1 on error.
 */
char memory_read(Memory *mem, size_t address);

#endif
