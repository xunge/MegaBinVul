#include <stdlib.h>
#include <errno.h>
#include <stdint.h>

typedef void* LPCRITICAL_SECTION;
typedef void* PVOID;
typedef struct { uint8_t data[40]; } CRITICAL_SECTION;

static inline PVOID InterlockedCompareExchangePointer(PVOID* dest, PVOID exch, PVOID comp) {
    return __sync_val_compare_and_swap(dest, comp, exch);
}

#define InitializeCriticalSection(x) ((void)0)
#define DeleteCriticalSection(x) ((void)0)
#define EnterCriticalSection(x) ((void)0)

typedef struct {
    LPCRITICAL_SECTION lock;
} pthread_mutex_win_t;

#define pthread_mutex_t pthread_mutex_win_t