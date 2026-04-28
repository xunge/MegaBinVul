#include <stddef.h>

typedef struct _CS_WINKERNEL_MEMBLOCK {
    size_t size;
    char data[];
} CS_WINKERNEL_MEMBLOCK;

#define CS_WINKERNEL_POOL_TAG 'NSCS'
#define NonPagedPool 0
#define CAPSTONE_API
#define NT_ASSERT(x) ((void)0)

void* ExAllocatePoolWithTag(int PoolType, size_t NumberOfBytes, unsigned long Tag);