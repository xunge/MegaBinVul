#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define AcquireQuantumMemory(size, count) calloc(count, size)
#define ResizeQuantumMemory(ptr, size, count) realloc(ptr, (size)*(count))
#define MagickDLLCall
#define Quantum