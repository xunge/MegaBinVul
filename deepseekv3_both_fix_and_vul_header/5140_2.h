#include <stdlib.h>
#include <stddef.h>

struct kref {
    int count;
};

struct ipmi_user {
    struct kref refcount;
    void *release_barrier;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

void cleanup_srcu_struct(void *);
void kfree(void *);