#include <criterion/criterion.h>
#include "cpu.h"
#include "memory.h"
#include "io.h"
#include "fff.h"

DEFINE_FFF_GLOBALS
FAKE_VOID_FUNC(memory_read)
FAKE_VOID_FUNC(io_write, int)

void setup_integration(void)
{
    // Setup common to all integration tests
    RESET_FAKE(memory_read);
    RESET_FAKE(io_write);
}

Test(integration_tests, test_cpu_memory_interaction, .init = setup_integration)
{
    CPU cpu;
    cpu_init(&cpu);
    cpu_execute_instruction(&cpu, 1); // Assuming this instructs a memory read
    cr_assert(memory_read_fake.call_count == 1, "Expected CPU to instruct a memory read.");
}
