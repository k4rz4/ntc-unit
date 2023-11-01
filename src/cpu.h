#ifndef CPU_H
#define CPU_H

// Represents the state of a CPU with registers.
typedef struct {
  int registers[8];  // Assume 8 general-purpose registers for simplicity
                     // Other components can be added later as needed
} CPU;

/**
 * Initializes the CPU's state.
 *
 * @param cpu Pointer to the CPU structure.
 */
void cpu_init(CPU *cpu);

/**
 * Executes a given instruction.
 *
 * @param cpu Pointer to the CPU structure.
 * @param instruction The instruction to be executed.
 */
void cpu_execute_instruction(CPU *cpu, int instruction);

#endif
