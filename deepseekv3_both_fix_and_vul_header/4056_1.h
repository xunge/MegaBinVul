#include <stddef.h>
#include <stdlib.h>

struct kref {
    int refcount;
};

struct list_head {
    struct list_head *next, *prev;
};

struct nfc_llcp_local {
    struct kref ref;
    struct list_head list;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

void list_del(struct list_head *entry);
void local_cleanup(struct nfc_llcp_local *local);