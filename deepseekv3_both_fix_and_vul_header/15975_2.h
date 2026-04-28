#include <stddef.h>
#include <stdlib.h>

struct kref {
    int count;
};

struct dvb_device {
    struct kref ref;
    void *fops;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define kfree free