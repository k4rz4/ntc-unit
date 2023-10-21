#include "cpu.h"
#include "io.h"
#include "memory.h"

int main() {
  CPU cpu;
  cpu_init(&cpu);

  // For simplicity, we'll just run a fixed number of cycles
  for (int cycle = 0; cycle < 100; cycle++) {
    // Here you could fetch an instruction from memory and then execute it
    // For now, let's keep it simple and execute a predefined set of
    // instructions:
    if (cycle % 10 == 0) {
      cpu_execute_instruction(&cpu, 1);  // Read from memory every 10 cycles
    }
    if (cycle % 20 == 0) {
      cpu_handle_interrupt(&cpu, 1);  // Timer interrupt every 20 cycles
    }
  }

  return 0;
}
