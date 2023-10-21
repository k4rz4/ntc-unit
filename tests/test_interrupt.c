#include <criterion/criterion.h>

#include "cpu.h"
#include "fff.h"
#include "interrupt.h"
#include "io.h"
FAKE_VOID_FUNC(handle_io_related_tasks)
FAKE_VOID_FUNC(handle_memory_related_tasks)
FAKE_VOID_FUNC(handle_timer_related_tasks)
FAKE_VOID_FUNC(handle_software_triggered_tasks)

TestSuite(interrupt_tests);

Test(interrupt_tests, test_handle_io_interrupt) {
  CPU cpu;
  RESET_FAKE(handle_io_related_tasks);

  handle_interrupt(&cpu, IO_INTERRUPT);

  cr_assert(handle_io_related_tasks_fake.call_count == 1,
            "handle_io_related_tasks was not called");
  cr_assert(handle_memory_related_tasks_fake.call_count == 0,
            "handle_memory_related_tasks should not have been called");
  cr_assert(handle_timer_related_tasks_fake.call_count == 0,
            "handle_timer_related_tasks should not have been called");
  cr_assert(handle_software_triggered_tasks_fake.call_count == 0,
            "handle_software_triggered_tasks should not have been called");
}

Test(interrupt_tests, test_handle_memory_interrupt) {
  CPU cpu;
  RESET_FAKE(handle_memory_related_tasks);

  handle_interrupt(&cpu, MEMORY_INTERRUPT);

  cr_assert(handle_memory_related_tasks_fake.call_count == 1,
            "handle_memory_related_tasks was not called");
}

// ...similar tests for TIMER_INTERRUPT, SOFTWARE_INTERRUPT...

Test(interrupt_tests, test_handle_unknown_interrupt) {
  CPU cpu;

  handle_interrupt(&cpu, 999);  // An unknown interrupt type

  // Here, you'd check that none of the specific handlers were called,
  // signifying a default behavior for unknown interrupts.
  cr_assert(handle_io_related_tasks_fake.call_count == 0,
            "handle_io_related_tasks should not have been called");
  cr_assert(handle_memory_related_tasks_fake.call_count == 0,
            "handle_memory_related_tasks should not have been called");
  cr_assert(handle_timer_related_tasks_fake.call_count == 0,
            "handle_timer_related_tasks should not have been called");
  cr_assert(handle_software_triggered_tasks_fake.call_count == 0,
            "handle_software_triggered_tasks should not have been called");
}
