#include "io.h"

#include <stdio.h>

static int isValidPort(int port) { return port >= 0 && port < MAX_PORT; }

void io_write(int port, char value) {
  if (isValidPort(port)) {
    printf("I/O Write to port %d: %c\n", port, value);
  } else {
    fprintf(stderr, "Attempted to write to invalid I/O port: %d\n", port);
  }
}

char io_read(int port) {
  if (isValidPort(port)) {
    // This is a mock value for demonstration.
    // Actual reading logic will depend on hardware or emulation.
    return 'B';
  } else {
    fprintf(stderr, "Attempted to read from invalid I/O port: %d\n", port);
    return -1;  // Error sentinel value
  }
}
