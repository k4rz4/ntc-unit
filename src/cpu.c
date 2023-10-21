#include "cpu.h"

#include <stddef.h>
#include <stdio.h>

#include "io.h"
#include "memory.h"

void cpu_init(CPU *cpu) {
  if (!cpu) {
    fprintf(stderr, "CPU pointer is NULL. Initialization failed.\n");
    return;
  }

  for (int i = 0; i < 8; i++) {
    cpu->registers[i] = 0;
  }
}

void cpu_execute_instruction(CPU *cpu, int instruction) {
  if (!cpu) {
    fprintf(stderr, "CPU pointer is NULL. Cannot execute instruction.\n");
    return;
  }

  switch (instruction) {
    case 1:
      // Read from memory
      memory_read(NULL, 0);  // TODO: The NULL should probably be replaced with
                             // a valid Memory pointer
      break;
    case 2:
      // Write to I/O
      io_write(0, cpu->registers[0]);
      break;
    case 3:
      // Simple ADD instruction
      cpu->registers[2] = cpu->registers[0] + cpu->registers[1];
      break;
    // ... other instructions
    default:
      fprintf(stderr, "Invalid instruction: %d\n", instruction);
      break;
  }
}

void cpu_handle_interrupt(CPU *cpu, int interrupt_type) {
  if (!cpu) {
    fprintf(stderr, "CPU pointer is NULL. Cannot handle interrupt.\n");
    return;
  }

  switch (interrupt_type) {
    case 1:  // Timer Interrupt
      printf("Timer Interrupt Occurred!\n");
      break;
    // ... other interrupt types
    default:
      fprintf(stderr, "Unknown interrupt type: %d\n", interrupt_type);
      break;
  }
}
