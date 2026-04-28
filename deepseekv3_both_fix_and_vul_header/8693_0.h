#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned long hwaddr;

struct iovec {
    void *iov_base;
    size_t iov_len;
};

void error_report(const char *fmt, ...);
void *cpu_physical_memory_map(hwaddr addr, hwaddr *len, bool is_write);