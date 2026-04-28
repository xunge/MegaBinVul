#include <stddef.h>
#include <stdlib.h>
#include <sys/uio.h>

#define VIRTQUEUE_MAX_SIZE 1024

typedef unsigned long hwaddr;

extern void error_report(const char *fmt, ...);
extern void *cpu_physical_memory_map(hwaddr addr, hwaddr *len, int is_write);