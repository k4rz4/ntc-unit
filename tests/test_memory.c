#include <criterion/criterion.h>
#include <stdint.h>

#include "fff.h"
#include "memory.h"

// Define fake functions if any are needed here for memory. For instance, if we
// needed to fake malloc:
FAKE_VALUE_FUNC(void *, malloc, size_t)

FAKE_VOID_FUNC(free, void *)

TestSuite(memory_tests);

Test(memory_tests, test_memory_allocation) {
  size_t size = 1024;

  // Fake the malloc call to return a valid pointer
  malloc_fake.return_val = (void *)0x12345678;  // some mock address

  Memory *mem = (Memory *)memory_alloc(sizeof(Memory));
  mem->data = (char *)memory_alloc(size);

  cr_assert_eq((uintptr_t)mem, 0x12345678,
               "Expected mock address not returned");
  cr_assert_eq((uintptr_t)mem->data, 0x12345678,
               "Expected mock address not returned for data");

  // Reset fakes
  RESET_FAKE(malloc);
  RESET_FAKE(free);
}

Test(memory_tests, test_memory_write_read) {
  size_t size = 1024;
  Memory mem;
  char buffer[1024];
  mem.data = buffer;
  mem.size = size;

  char testData = 'A';
  memory_write(&mem, 500, testData);
  char readData = memory_read(&mem, 500);
  cr_assert_eq(testData, readData, "Memory write-read failed");
}

Test(memory_tests, test_out_of_bounds_read) {
  size_t size = 1024;
  Memory mem;
  char buffer[1024];
  mem.data = buffer;
  mem.size = size;

  char readData = memory_read(&mem, 5000);
  cr_assert_eq(readData, -1, "Out of bounds read should return -1");
}

// Edge case: Large memory allocation
Test(memory_tests, test_large_memory_allocation) {
  size_t size = SIZE_MAX;

  // Fake the malloc call to return NULL (to mimic failed allocation)
  malloc_fake.return_val = NULL;

  Memory *mem = (Memory *)memory_alloc(size);

  cr_assert_null(mem, "Expected NULL due to large memory allocation");

  // Reset fakes
  RESET_FAKE(malloc);
}

// ... Additional tests ...
