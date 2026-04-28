#include <stddef.h>

struct vm_area_struct {
    void *vm_private_data;
    unsigned long vm_start;
    unsigned long vm_end;
};

struct videobuf_mapping {
    int count;
};

extern void dprintk(int level, const char *format, ...);