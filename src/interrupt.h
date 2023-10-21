#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "cpu.h"

// Enumerated type for interrupt types
typedef enum {
  IO_INTERRUPT = 1,
  MEMORY_INTERRUPT,
  TIMER_INTERRUPT,
  SOFTWARE_INTERRUPT
} InterruptType;

/**
 * Handles an interrupt based on its type.
 *
 * @param cpu Pointer to the CPU structure.
 * @param interrupt_type The type of the interrupt.
 */
void handle_interrupt(CPU *cpu, InterruptType interrupt_type);

#endif
