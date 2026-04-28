#include <stdint.h>
#include <sys/uio.h>

typedef struct IM3Runtime* IM3Runtime;

typedef struct {
    uint32_t buf;
    uint32_t buf_len;
} wasi_iovec_t;

void* m3ApiOffsetToPtr(uint32_t offset);
uint32_t m3ApiReadMem32(const void* ptr);
void m3ApiCheckMem(const void* ptr, uint32_t len);
void m3ApiSuccess(void);