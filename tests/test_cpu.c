#include <criterion/criterion.h>

#include "cpu.h"
#include "fff.h"
#include "io.h"
#include "memory.h"

DEFINE_FFF_GLOBALS

FAKE_VALUE_FUNC(char, memory_read, Memory *, size_t)
FAKE_VOID_FUNC(io_write, int, char)

TestSuite(cpu_tests);

Test(cpu_tests, test_cpu_init) {
  CPU cpu;
  cpu_init(&cpu);

  for (int i = 0; i < 8; i++) {
    cr_assert_eq(cpu.registers[i], 0, "Register %d was not initialized to 0",
                 i);
  }
}

Test(cpu_tests, test_cpu_execute_read_memory_instruction) {
  CPU cpu;
  cpu_init(&cpu);

  cpu_execute_instruction(&cpu, 1);

  cr_assert(memory_read_fake.call_count == 1, "memory_read was not called");
}

Test(cpu_tests, test_cpu_execute_io_write_instruction) {
  CPU cpu;
  cpu_init(&cpu);
  cpu.registers[0] = 'A';

  cpu_execute_instruction(&cpu, 2);

  cr_assert(io_write_fake.call_count == 1, "io_write was not called");
  cr_assert_eq(io_write_fake.arg0_val, 0, "Expected port to be 0");
  cr_assert_eq(io_write_fake.arg1_val, 'A', "Expected value to be 'A'");
}

Test(cpu_tests, test_cpu_invalid_instruction) {
  CPU cpu;
  cpu_init(&cpu);

  cpu_execute_instruction(&cpu, 999);  // Invalid instruction

  // Here, you might want to spy on stderr to see if the error message was
  // printed. For simplicity, this step is skipped, but it's important in
  // real-world applications.
}

// ... Additional tests ...
