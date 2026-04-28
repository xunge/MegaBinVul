#include <stdlib.h>

typedef void* HANDLE;

typedef struct _CRITICAL_SECTION {
    void* DebugInfo;
    long LockCount;
    long RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long SpinCount;
} CRITICAL_SECTION;

typedef struct MonoInternalThread {
    CRITICAL_SECTION *synch_cs;
    void *name;
} MonoInternalThread;

#define MONO_ARCH_SAVE_REGS
#define THREAD_DEBUG(x) x
#define g_message(...)
#define g_free(ptr) free(ptr)