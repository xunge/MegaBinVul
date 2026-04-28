#include <stdint.h>

typedef uintptr_t txSize;
typedef uint64_t txNumber;
typedef struct txMachine txMachine;
#define XS_NOT_ENOUGH_MEMORY_EXIT 1
void fxAbort(txMachine* the, int exitCode);