#include "interrupt.h"

#include <stdio.h>

// Declare mock functions (these are faked in tests)
void handle_io_related_tasks(void);
void handle_memory_related_tasks(void);
void handle_timer_related_tasks(void);
void handle_software_triggered_tasks(void);

void handle_interrupt(CPU *cpu, InterruptType interrupt_type) {
  (void)cpu;  // If the CPU is not used, consider removing it from the function
              // signature.

  switch (interrupt_type) {
    case IO_INTERRUPT:
      // Add actual logic to handle the I/O interrupt
      printf("Handling I/O Interrupt\n");
      break;
    case MEMORY_INTERRUPT:
      // Add actual logic to handle the Memory interrupt
      printf("Handling Memory Interrupt\n");
      break;
    case TIMER_INTERRUPT:
      // Add actual logic to handle the Timer interrupt
      printf("Handling Timer Interrupt\n");
      break;
    case SOFTWARE_INTERRUPT:
      // Add actual logic to handle the Software interrupt
      printf("Handling Software Interrupt\n");
      break;
    default:
      fprintf(stderr, "Unknown interrupt type: %d\n", interrupt_type);
      break;
  }
}
