#include <stdint.h>

typedef struct IM3Runtime_ *IM3Runtime;

typedef struct {
    void* buf;
    uint32_t buf_len;
} __wasi_iovec_t;

#define m3ApiOffsetToPtr(offset) ((void*)((uint8_t*)_mem + (uintptr_t)(offset)))
#define m3ApiCheckMem(ptr, size) 
#define m3ApiSuccess() return _mem