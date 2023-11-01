# Testing Suite for Embedded System Modules

## Overview

This testing suite is designed to validate and ensure the proper functionality of the embedded system modules including the CPU, memory management, I/O, and interrupt handling.

## Modules Under Test

1. **CPU**: Responsible for executing instructions and managing interrupts.
2. **Memory**: Manages memory allocation, deallocation, read, and write operations.
3. **I/O**: Manages reading from and writing to I/O ports.

## Testing Tools

- **Criterion**: A C testing framework which provides a main function and several macro functions to ease the creation and integration of new test cases.
- **fff (Fake Function Framework)**: Used for mocking dependencies in unit tests.

## Test Scenarios

1. **CPU Module**:
   - Initialization
   - Execute Memory Read Instruction
   - Execute I/O Write Instruction
   - Handling Interrupts

2. **Memory Module**:
   - Memory Allocation
   - Memory Deallocation
   - Memory Read and Write

3. **I/O Module**:
   - Mocked I/O Read
   - Mocked I/O Write


## Mocked Functions (Using fff)

- `memory_read()`: For mocking memory read operations.
- `memory_write()`: For mocking memory write operations.
- `io_read()`: For mocking I/O read operations.
- `io_write()`: For mocking I/O write operations.

## Test Implementation Steps

1. **Setting up Criterion**: 
   - Ensure Criterion is properly installed and accessible from the test files.
   - Set up a basic test harness with Criterion to allow for easy addition of new tests.

2. **Setting up fff**: 
   - Include the `fff.h` file in the test directory.
   - Use the `DEFINE_FFF_GLOBALS` macro to set up structures for fff.
   - Define mock functions using `FAKE_VOID_FUNC` or other related macros provided by fff.

3. **Implement Test Cases**:
   - For each module (CPU, Memory, I/O, Interrupts), implement test cases as described in the Test Scenarios section above.
   - Utilize mock functions where external interactions are expected.
   - Use Criterion's `cr_assert` or related functions to check expected outcomes.

4. **Compile and Run Tests**:
   - Update the `Makefile` to include the compilation and linkage of all test files, Criterion, and any necessary dependencies.
   - Compile and run the test suite, ensuring all tests pass.

5. **Iterate**:
   - As new features or changes are introduced to the system, update or add corresponding tests.
   - Ensure tests are always run after changes to catch any regressions.

