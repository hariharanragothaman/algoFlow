#include "../../../debug.h"

/*
 *
 * For the first time with C++11, C++ supports native multithreading.
 * This support consists of two parts: A well-defined memory model and a standardized threading interface.
 *
 *
 * Memory Model
 * The foundation of multithreading is a well-defined memory model.
 * This memory model has to deal with the following points:
 *
 * Atomic operations: Operations that can be performed without interruption.
 * Partial ordering of operations: Sequence of operations that must not be reordered.
 * Visible effects of operations: Guarantees when operations on shared variables are visible in other threads.
 *
 * The C++ memory model has a lot in common with its predecessor: the Java, memory model.
 * On the contrary, C++ permits the breaking of sequential consistency.
 * The sequential consistency is the default behavior of atomic operations.
 * The sequential consistency provides two guarantees.
 *
 * The instructions of a program are executed in source code order.
 * There is a global order of all operations on all threads.
 *
 */
