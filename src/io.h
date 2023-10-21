#ifndef IO_H
#define IO_H

#define MAX_PORT 100

/**
 * Writes a value to a specified I/O port.
 *
 * @param port The I/O port to write to.
 * @param value The value to write.
 */
void io_write(int port, char value);

/**
 * Reads a value from a specified I/O port.
 *
 * @param port The I/O port to read from.
 * @return The value read from the port, or -1 on error.
 */
char io_read(int port);

#endif
